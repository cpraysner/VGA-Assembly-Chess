.equ ADDR_VGA, 0x08000000
.equ ADDR_CHAR, 0x09000000
.equ SP_INITIAL_ADDRESS, 0x03FFFFFC
.equ PS2_DATA_ADDRESS, 0xFF200100
.data

PawnWhite:   .word 0x12, 0x22, 0x32,0x42,0x52,0x62,0x72,0x82, 0
PawnBlack:   .word 0x17,0x27, 0x37,0x47,0x57,0x67,0x77,0x87, 0
RookBlack:   .word 0x18,0x88, 0
RookWhite:   .word 0x11,0x81,0
KnightBlack: .word 0x28,0x78,0
KnightWhite: .word 0x21, 0x71,0
BishopBlack: .word 0x38, 0x68,0
BishopWhite: .word 0x31, 0x61,0
QueenWhite:  .word 0x41,0
QueenBlack:  .word 0x48,0
KingWhite:   .word 0x51,0
KingBlack:   .word 0x58,0
legalMoves:  .space 60 

.section .exceptions, "ax"
 isr:	
	 subi sp, sp, 44
	 stwio r6, 0(sp)
	 stwio r7, 4(sp)
	 stwio r8, 8(sp)
	 stwio r9, 12(sp)
	 stwio r10, 16(sp)
	 stwio r11, 20(sp)
	 stwio r12, 24(sp)
	 stwio r13, 28(sp)
	 stwio r14, 32(sp)
	 stwio r15, 36(sp)
	 stwio r19, 40(sp)

	 rdctl r6, ipending
     andi  r7, r6, 0x80           # is bit RIP 1?
     beq   r7, r0, done
	
 mouse_info:
	
	 movia r7, PS2_DATA_ADDRESS
	 ldwio r11, 0(r7)      #load first byte
	 andi r11, r11, 0xFFFF
	 andi r12, r11, 0x8000
	 beq r12, r0, done
	 andi r12, r11, 0xFF
	 movi r13, 0x5A
	 beq r12, r13, Enter_Key
	 movi r13, 0xE0
	 bne r12,r13, Enter_Break
	 ldwio r13, 0(r7)	 #load second byte
	 andi r13, r13, 0xFFFF
	 andi r11, r13, 0x8000
	 beq r11, r0, done
	 andi r13, r13, 0xFF
	 
Arrow_Keys:
	movi r2, 0x75
	beq r13, r2, Up_Key
	movi r2, 0x6B
	beq r13, r2, Left_Key
	movi r2, 0x72
	beq r2, r13, Down_Key
	movi r2, 0x74
	beq r2, r13, Right_Key
	br Arrow_Break
	
Up_Key:
	movi r3, 0x1
	beq r17, r3, done
	subi r17, r17, 1
	br Arrow_Break
	
Down_Key:
	movi r3, 0x8
	beq r17, r3, done
	addi r17, r17, 1
	br Arrow_Break
	
	
Left_Key:
	movi r3, 0x1
	beq r16, r3, done
	subi r16, r16, 1
	br Arrow_Break
Right_Key:
	movi r3, 0x8
	beq r16, r3, done
	addi r16, r16, 1
	br Arrow_Break
	
	


Enter_Key:
	movi r18, 0x1

Enter_Break:
ldwio r6, 0(r7)
ldwio r6, 0(r7)
br done
	
Arrow_Break:
ldwio r6, 0(r7)
ldwio r6, 0(r7)
ldwio r6, 0(r7)


 done:	
	 ldwio r6, 0(sp)
	 ldwio r7, 4(sp)
	 ldwio r8, 8(sp)
	 ldwio r9, 12(sp)
	 ldwio r10,16(sp)
	 ldwio r11,20(sp)
	 ldwio r12, 24(sp)
	 ldwio r13, 28(sp)
	 ldwio r14, 32(sp)
	 ldwio r15, 36(sp)
	 ldwio r19, 40(sp)
	 addi sp, sp, 44
	
	 addi ea, ea, -4
	 eret



.text

.global main
main:
	#mouse set up
	movia r13, PS2_DATA_ADDRESS
	movui r14, 0b1				#enable interrupts
	stwio r14, 4(r13)         
	movui r14, 0b10000000     #unmask IRQ seven
	wrctl ienable, r14
	movui r14, 0b1				#enable interrupts in the processor
	wrctl ctl0, r14
	#movi  r14, 0xFA
	#stwio r14, 0(r13)	#enable streaming mode
	
Loop:
	movi r16, 0x1
	movi r17, 0x1
	

	subi sp, sp, 4
	stw ra, 0(sp)
	call draw_everything
	ldw ra, 0(sp)
	addi sp, sp, 4

	mov r5, r16
	mov r4, r17
	subi sp, sp, 4
	stw ra, 0(sp)
	call arrow_input
	ldw ra, 0(sp)
	addi sp, sp, 4




White_Arrow:
mov r18, r0
mov r20, r16
mov r19, r17
Poll_until_white_select:
	
	bne r20, r16, Arrow_In
	bne r19, r17, Arrow_In
	bne r18, r0, Check_mouse_click_white
	br Poll_until_white_select
	
Arrow_In:
	mov r5, r16
	mov r4, r17
	subi sp, sp, 4
	stw ra, 0(sp)
	call draw_everything
	ldw ra, 0(sp)
	addi sp, sp, 4
	mov r5, r16
	mov r4, r17
	subi sp, sp, 4
	stw ra, 0(sp)
	call arrow_input
	ldw ra, 0(sp)
	addi sp, sp, 4
	beq r18, r0, White_Arrow
	
Check_mouse_click_white:
	mov r18, r0
	mov r12, r16
	slli r12,r12,4
	or r12,r12,r17
	
	movia r10, PawnWhite
	Loop_Pawn_White:
	ldw r11, 0(r10)
	beq r11, r0, Pre_Loop_Rook_White
	beq r11, r12, white_pawn_moves
	addi r10,r10,2
	br Loop_Pawn_White	
	
	Pre_Loop_Rook_White:
	movia r10, RookWhite
	Loop_Rook_White:
	ldw r11, 0(r10)
	beq r11, r0, Pre_Loop_Knight_White
	beq r11, r12, white_rook_moves
	addi r10,r10,2
	br Loop_Rook_White
	
	Pre_Loop_Knight_White:
	movia r10, KnightWhite
	Loop_Knight_White:
	ldw r11, 0(r10)
	beq r11, r0, Pre_Loop_Bishop_White
	beq r11, r12, white_knight_moves
	addi r10,r10,2
	br Loop_Knight_White
	
	Pre_Loop_Bishop_White:
	movia r10, BishopWhite
	Loop_Bishop_White:
	ldw r11, 0(r10)
	beq r11, r0, Pre_Loop_Queen_White
	beq r11, r12, white_bishop_moves
	addi r10,r10,2
	br Loop_Bishop_White
	
	Pre_Loop_Queen_White:
	movia r10, QueenWhite
	Loop_Queen_White:
	ldw r11, 0(r10)
	beq r11, r0, Pre_Loop_King_White
	beq r11, r12, white_queen_moves
	addi r10,r10,2
	br Loop_Queen_White
	
	Pre_Loop_King_White:
	movia r10, KingWhite
	Loop_King_White:
	ldw r11, 0(r10)
	beq r11, r0, White_Arrow
	beq r11, r12, white_king_moves
	addi r10,r10,2
	br Loop_King_White
	
	
	
white_pawn_moves:
	addi sp, sp, -8
	stw r10, 4(sp)
	stw ra, 0(sp)
	mov r4, r16
	mov r5, r17
	movia r6, PawnWhite
	movia r7, PawnBlack
	addi sp, sp, -40
	movia r2, RookWhite
	stw r2, 0(sp)
	movia r2, RookBlack
	stw r2, 4(sp)
	movia r2, KnightWhite
	stw r2, 8(sp)
	movia r2, KnightBlack
	stw r2, 12(sp)
	movia r2, BishopWhite
	stw r2, 16(sp)
	movia r2, BishopBlack
	stw r2, 20(sp)
	movia r2, QueenWhite
	stw r2, 24(sp)
	movia r2, QueenBlack
	stw r2, 28(sp)
	movia r2, KingWhite
	stw r2, 32(sp)
	movia r2, KingBlack
	stw r2, 36(sp)
	call pawn_legal_white
	addi sp, sp, 40
	ldwio ra, 0(sp)
	ldw r10, 4(sp)
	addi sp, sp,8
	mov r22, r2
	br White_Arrow1
white_rook_moves:
	addi sp, sp, -8
	stw ra, 0(sp)
	stw r10, 4(sp)
	mov r4, r10
	ori r5, r4, 0xF
	srli r4,r4, 4
	movia r6, PawnWhite
	movia r7, PawnBlack
	addi sp, sp, -44
	movia r2, RookWhite
	stw r2, 0(sp)
	movia r2, RookBlack
	stw r2, 4(sp)
	movia r2, KnightWhite
	stw r2, 8(sp)
	movia r2, KnightBlack
	stw r2, 12(sp)
	movia r2, BishopWhite
	stw r2, 16(sp)
	movia r2, BishopBlack
	stw r2, 20(sp)
	movia r2, QueenWhite
	stw r2, 24(sp)
	movia r2, QueenBlack
	stw r2, 28(sp)
	movia r2, KingWhite
	stw r2, 32(sp)
	movia r2, KingBlack
	stw r2, 36(sp)
	movia r2, legalMoves
	stw r2, 40(sp)
	call legal_rook_moves_white
	addi sp, sp, 44
	ldwio ra, 0(sp)
	ldw r10, 4(sp)
	addi sp, sp,8
	mov r22, r2
	br White_Arrow1
white_knight_moves:
	addi sp, sp, -8
	stw ra, 0(sp)
	stw r10, 4(sp)
	mov r4, r10
	ori r5, r4, 0xF
	srli r4,r4, 4
	movia r6, PawnWhite
	movia r7, PawnBlack
	addi sp, sp, -44
	movia r2, RookWhite
	stw r2, 0(sp)
	movia r2, RookBlack
	stw r2, 4(sp)
	movia r2, KnightWhite
	stw r2, 8(sp)
	movia r2, KnightBlack
	stw r2, 12(sp)
	movia r2, BishopWhite
	stw r2, 16(sp)
	movia r2, BishopBlack
	stw r2, 20(sp)
	movia r2, QueenWhite
	stw r2, 24(sp)
	movia r2, QueenBlack
	stw r2, 28(sp)
	movia r2, KingWhite
	stw r2, 32(sp)
	movia r2, KingBlack
	stw r2, 36(sp)
	movia r2, legalMoves
	stw r2, 40(sp)
	call legal_knight_moves_white
	addi sp, sp, 44
	ldwio ra, 0(sp)
	ldw r10, 4(sp)
	addi sp, sp,8
	mov r22, r2	
	br White_Arrow1
white_queen_moves:
	addi sp, sp, -8
	stw ra, 0(sp)
	stw r10, 4(sp)
	mov r4, r10
	ori r5, r4, 0xF
	srli r4,r4, 4
	movia r6, PawnWhite
	movia r7, PawnBlack
	addi sp, sp, -44
	movia r2, RookWhite
	stw r2, 0(sp)
	movia r2, RookBlack
	stw r2, 4(sp)
	movia r2, KnightWhite
	stw r2, 8(sp)
	movia r2, KnightBlack
	stw r2, 12(sp)
	movia r2, BishopWhite
	stw r2, 16(sp)
	movia r2, BishopBlack
	stw r2, 20(sp)
	movia r2, QueenWhite
	stw r2, 24(sp)
	movia r2, QueenBlack
	stw r2, 28(sp)
	movia r2, KingWhite
	stw r2, 32(sp)
	movia r2, KingBlack
	stw r2, 36(sp)
	movia r2, legalMoves
	stw r2, 40(sp)
	call legal_queen_moves_white
	addi sp, sp, 44
	ldwio ra, 0(sp)
	ldw r10, 4(sp)
	addi sp, sp,8
	mov r22, r2
	br White_Arrow1
white_bishop_moves:
	addi sp, sp, -8
	stw ra, 0(sp)
	stw r10, 4(sp)
	mov r4, r10
	ori r5, r4, 0xF
	srli r4,r4, 4
	movia r6, PawnWhite
	movia r7, PawnBlack
	addi sp, sp, -44
	movia r2, RookWhite
	stw r2, 0(sp)
	movia r2, RookBlack
	stw r2, 4(sp)
	movia r2, KnightWhite
	stw r2, 8(sp)
	movia r2, KnightBlack
	stw r2, 12(sp)
	movia r2, BishopWhite
	stw r2, 16(sp)
	movia r2, BishopBlack
	stw r2, 20(sp)
	movia r2, QueenWhite
	stw r2, 24(sp)
	movia r2, QueenBlack
	stw r2, 28(sp)
	movia r2, KingWhite
	stw r2, 32(sp)
	movia r2, KingBlack
	stw r2, 36(sp)
	movia r2, legalMoves
	stw r2, 40(sp)
	call legal_bishop_moves_white
	addi sp, sp, 44
	ldwio ra, 0(sp)
	ldw r10, 4(sp)
	addi sp, sp,8
	mov r22, r2
	br White_Arrow1
white_king_moves:
	addi sp, sp, -8
	stw ra, 0(sp)
	stw r10, 4(sp)
	mov r4, r10
	ori r5, r4, 0xF
	srli r4,r4, 4
	movia r6, PawnWhite
	movia r7, PawnBlack
	addi sp, sp, -44
	movia r2, RookWhite
	stw r2, 0(sp)
	movia r2, RookBlack
	stw r2, 4(sp)
	movia r2, KnightWhite
	stw r2, 8(sp)
	movia r2, KnightBlack
	stw r2, 12(sp)
	movia r2, BishopWhite
	stw r2, 16(sp)
	movia r2, BishopBlack
	stw r2, 20(sp)
	movia r2, QueenWhite
	stw r2, 24(sp)
	movia r2, QueenBlack
	stw r2, 28(sp)
	movia r2, KingWhite
	stw r2, 32(sp)
	movia r2, KingBlack
	stw r2, 36(sp)
	movia r2, legalMoves
	stw r2, 40(sp)
	call king_legal_white
	addi sp, sp, 44
	ldwio ra, 0(sp)
	ldw r10, 4(sp)
	addi sp, sp,8
	mov r22, r2
	br White_Arrow1


White_Arrow1:
mov r18, r0
mov r20, r16
mov r19, r17
Poll_until_white_move:
	
	bne r20, r16, Arrow_In1
	bne r19, r17, Arrow_In1
	bne r18, r0, Make_move_white
	br Poll_until_white_move
	

Arrow_In1:
	mov r5, r16
	mov r4, r17
	subi sp, sp, 8
	stw r10, 4(sp)
	stw ra, 0(sp)
	call draw_everything
	ldw ra, 0(sp)
	addi sp, sp, 4
	mov r5, r16
	mov r4, r17
	subi sp, sp, 4
	stw ra, 0(sp)
	call arrow_input
	ldw ra, 0(sp)
	ldw r10, 4(sp)
	addi sp, sp, 8
	beq r18, r0, White_Arrow1
Make_move_white:
	mov r18, r0
	mov r14, r20
	slli r14,r14,4
	or r14,r14,r19
	movia r22, legalMoves
Check_legal_white:
	ldw r13, 0(r22)
	beq r13, r0, White_Arrow1
	addi r22, r22, 0x4
	bne r13, r14, Check_legal_white
	
	
	movia r13, PawnBlack
Loop_Take_Pawn_Black:
	ldw r11, 0(r13)
	beq r11, r0, Pre_Loop_Take_Rook_Black
	beq r11, r14, Take_Black_Piece
	addi r13,r13,2
	br Loop_Take_Pawn_Black

Pre_Loop_Take_Rook_Black:
	movia r13, RookBlack

Loop_Take_Rook_Black:
	ldw r11, 0(r13)
	beq r11, r0, Pre_Loop_Take_Bishop_Black
	beq r11, r14, Take_Black_Piece
	addi r13,r13,2
	br Loop_Take_Rook_Black

	Pre_Loop_Take_Bishop_Black:
	movia r13, BishopBlack

Loop_Take_Bishop_Black:
	ldw r11, 0(r13)
	beq r11, r0, Pre_Loop_Take_Knight_Black
	beq r11, r14, Take_Black_Piece
	addi r13,r13,2
	br Loop_Take_Bishop_Black
	
Pre_Loop_Take_Knight_Black:
	movia r13, KnightBlack

Loop_Take_Knight_Black:
	ldw r11, 0(r13)
	beq r11, r0, Take_Queen_Black
	beq r11, r14, Take_Black_Piece
	addi r13,r13,2
	br Loop_Take_Knight_Black

	

Take_Queen_Black:
	movia r13, RookBlack
	ldw r11, 0(r13)
	beq r11, r14, Take_Black_Piece
	addi r13,r13,2
	br Move_White_Piece
	
	
	
	

Take_Black_Piece:
	movi r11, 0xFF
	stw r11, 0(r13)
	br Move_White_Piece
	
Move_White_Piece:
	stw r14, 0(r10)
	subi sp, sp, 4
	stw ra, 0(sp)
	call draw_everything
	ldw ra, 0(sp)
	addi sp, sp, 4	
	
	movi r16, 0x1
	movi r17, 0x8
	mov r18, r0
	mov r5, r16
	mov r4, r17
	subi sp, sp, 4
	stw ra, 0(sp)
	call arrow_input
	ldw ra, 0(sp)
	addi sp, sp, 4
Black_Arrow:
mov r20, r16
mov r19, r17
Poll_until_black_select:
	
	bne r20, r16, Arrow_In2
	bne r19, r17, Arrow_In2
	bne r18, r0, Check_mouse_click_black
	br Poll_until_black_select
	
	# subi sp, sp, 4
	# stw ra, 0(sp)
	# call draw_everything
	# ldw ra, 0(sp)
	# addi sp, sp, 4
Arrow_In2:
	mov r5, r16
	mov r4, r17
	subi sp, sp, 4
	stw ra, 0(sp)
	call draw_everything
	ldw ra, 0(sp)
	addi sp, sp, 4
	mov r5, r16
	mov r4, r17
	subi sp, sp, 4
	stw ra, 0(sp)
	call arrow_input
	ldw ra, 0(sp)
	addi sp, sp, 4
	beq r18, r0, Black_Arrow
	
Check_mouse_click_black:
	mov r18, r0
	mov r12, r16
	slli r12,r12,4
	or r12,r12,r17
	
	movia r10, PawnBlack
	Loop_Pawn_Black:
	ldw r11, 0(r10)
	beq r11, r0, Pre_Loop_Rook_Black
	beq r11, r12, black_pawn_moves
	addi r10,r10,2
	br Loop_Pawn_Black	
	
	Pre_Loop_Rook_Black:
	movia r10, RookBlack
	Loop_Rook_Black:
	ldw r11, 0(r10)
	beq r11, r0, Pre_Loop_Knight_Black
	beq r11, r12, black_rook_moves
	addi r10,r10,2
	br Loop_Rook_Black
	
	Pre_Loop_Knight_Black:
	movia r10, KnightBlack
	Loop_Knight_Black:
	ldw r11, 0(r10)
	beq r11, r0, Pre_Loop_Bishop_Black
	beq r11, r12, black_knight_moves
	addi r10,r10,2
	br Loop_Knight_Black
	
	Pre_Loop_Bishop_Black:
	movia r10, BishopBlack
	Loop_Bishop_Black:
	ldw r11, 0(r10)
	beq r11, r0, Pre_Loop_Queen_Black
	beq r11, r12, black_bishop_moves
	addi r10,r10,2
	br Loop_Bishop_Black
	
	Pre_Loop_Queen_Black:
	movia r10, QueenBlack
	Loop_Queen_Black:
	ldw r11, 0(r10)
	beq r11, r0, Pre_Loop_King_Black
	beq r11, r12, black_queen_moves
	addi r10,r10,2
	br Loop_Queen_Black
	
	Pre_Loop_King_Black:
	movia r10, KingBlack
	Loop_King_Black:
	ldw r11, 0(r10)
	beq r11, r0, Black_Arrow
	beq r11, r12, black_king_moves
	addi r10,r10,2
	br Loop_King_Black
	
	
	
black_pawn_moves:
	addi sp, sp, -8
	stw r10, 4(sp)
	stw ra, 0(sp)
	mov r4, r10
	ori r5, r4, 0xF
	srli r4,r4, 4
	movia r6, PawnWhite
	movia r7, PawnBlack
	addi sp, sp, -40
	movia r2, RookWhite
	stw r2, 0(sp)
	movia r2, RookBlack
	stw r2, 4(sp)
	movia r2, KnightWhite
	stw r2, 8(sp)
	movia r2, KnightBlack
	stw r2, 12(sp)
	movia r2, BishopWhite
	stw r2, 16(sp)
	movia r2, BishopBlack
	stw r2, 20(sp)
	movia r2, QueenWhite
	stw r2, 24(sp)
	movia r2, QueenBlack
	stw r2, 28(sp)
	movia r2, KingWhite
	stw r2, 32(sp)
	movia r2, KingBlack
	stw r2, 36(sp)
	call pawn_legal_black
	addi sp, sp, 40
	ldwio ra, 0(sp)
	ldw r10, 4(sp)
	addi sp, sp,8
	mov r22, r2
	br Black_Arrow1
black_rook_moves:
	addi sp, sp, -8
	stw ra, 0(sp)
	stw r10, 4(sp)
	mov r4, r10
	ori r5, r4, 0xF
	srli r4,r4, 4
	movia r6, PawnWhite
	movia r7, PawnBlack
	addi sp, sp, -40
	movia r2, RookWhite
	stw r2, 0(sp)
	movia r2, RookBlack
	stw r2, 4(sp)
	movia r2, KnightWhite
	stw r2, 8(sp)
	movia r2, KnightBlack
	stw r2, 12(sp)
	movia r2, BishopWhite
	stw r2, 16(sp)
	movia r2, BishopBlack
	stw r2, 20(sp)
	movia r2, QueenWhite
	stw r2, 24(sp)
	movia r2, QueenBlack
	stw r2, 28(sp)
	movia r2, KingWhite
	stw r2, 32(sp)
	movia r2, KingBlack
	stw r2, 36(sp)
	call legal_rook_moves_black
	addi sp, sp, 40
	ldwio ra, 0(sp)
	ldw r10, 4(sp)
	addi sp, sp,8
	mov r22, r2
	br Black_Arrow1
	black_knight_moves:
	addi sp, sp, -8
	stw ra, 0(sp)
	stw r10, 4(sp)
	mov r4, r10
	ori r5, r4, 0xF
	srli r4,r4, 4
	movia r6, PawnWhite
	movia r7, PawnBlack
	addi sp, sp, -40
	movia r2, RookWhite
	stw r2, 0(sp)
	movia r2, RookBlack
	stw r2, 4(sp)
	movia r2, KnightWhite
	stw r2, 8(sp)
	movia r2, KnightBlack
	stw r2, 12(sp)
	movia r2, BishopWhite
	stw r2, 16(sp)
	movia r2, BishopBlack
	stw r2, 20(sp)
	movia r2, QueenWhite
	stw r2, 24(sp)
	movia r2, QueenBlack
	stw r2, 28(sp)
	movia r2, KingWhite
	stw r2, 32(sp)
	movia r2, KingBlack
	stw r2, 36(sp)
	call legal_knight_moves_black
	addi sp, sp, 40
	ldwio ra, 0(sp)
	ldw r10, 4(sp)
	addi sp, sp,8	
	mov r22, r2
	br Black_Arrow1
 black_queen_moves:
	addi sp, sp, -8
	stw ra, 0(sp)
	stw r10, 4(sp)
	mov r4, r10
	ori r5, r4, 0xF
	srli r4,r4, 4
	movia r6, PawnWhite
	movia r7, PawnBlack
	addi sp, sp, -40
	movia r2, RookWhite
	stw r2, 0(sp)
	movia r2, RookBlack
	stw r2, 4(sp)
	movia r2, KnightWhite
	stw r2, 8(sp)
	movia r2, KnightBlack
	stw r2, 12(sp)
	movia r2, BishopWhite
	stw r2, 16(sp)
	movia r2, BishopBlack
	stw r2, 20(sp)
	movia r2, QueenWhite
	stw r2, 24(sp)
	movia r2, QueenBlack
	stw r2, 28(sp)
	movia r2, KingWhite
	stw r2, 32(sp)
	movia r2, KingBlack
	stw r2, 36(sp)
	call legal_queen_moves_black
	addi sp, sp, 40
	ldwio ra, 0(sp)
	ldw r10, 4(sp)
	addi sp, sp,8
	mov r22, r2
	br Black_Arrow1
black_bishop_moves:
	addi sp, sp, -8
	stw ra, 0(sp)
	stw r10, 4(sp)
	mov r4, r10
	ori r5, r4, 0xF
	srli r4,r4, 4
	movia r6, PawnWhite
	movia r7, PawnBlack
	addi sp, sp, -40
	movia r2, RookWhite
	stw r2, 0(sp)
	movia r2, RookBlack
	stw r2, 4(sp)
	movia r2, KnightWhite
	stw r2, 8(sp)
	movia r2, KnightBlack
	stw r2, 12(sp)
	movia r2, BishopWhite
	stw r2, 16(sp)
	movia r2, BishopBlack
	stw r2, 20(sp)
	movia r2, QueenWhite
	stw r2, 24(sp)
	movia r2, QueenBlack
	stw r2, 28(sp)
	movia r2, KingWhite
	stw r2, 32(sp)
	movia r2, KingBlack
	stw r2, 36(sp)
	call legal_bishop_moves_black
	addi sp, sp, 40
	ldwio ra, 0(sp)
	ldw r10, 4(sp)
	addi sp, sp,8
	mov r22, r2
	br Black_Arrow1
black_king_moves:
		addi sp, sp, -8
	stw ra, 0(sp)
	stw r10, 4(sp)
	mov r4, r10
	ori r5, r4, 0xF
	srli r4,r4, 4
	movia r6, PawnWhite
	movia r7, PawnBlack
	addi sp, sp, -40
	movia r2, RookWhite
	stw r2, 0(sp)
	movia r2, RookBlack
	stw r2, 4(sp)
	movia r2, KnightWhite
	stw r2, 8(sp)
	movia r2, KnightBlack
	stw r2, 12(sp)
	movia r2, BishopWhite
	stw r2, 16(sp)
	movia r2, BishopBlack
	stw r2, 20(sp)
	movia r2, QueenWhite
	stw r2, 24(sp)
	movia r2, QueenBlack
	stw r2, 28(sp)
	movia r2, KingWhite
	stw r2, 32(sp)
	movia r2, KingBlack
	stw r2, 36(sp)
	call king_legal_black
	addi sp, sp, 40
	ldwio ra, 0(sp)
	ldw r10, 4(sp)
	addi sp, sp,8
	mov r22, r2

Black_Arrow1:
mov r18, r0
mov r20, r16
mov r19, r17
Poll_until_black_move:
	
	bne r20, r16, Arrow_In3
	bne r19, r17, Arrow_In3
	bne r18, r0, Make_move_black
	br Poll_until_black_move
	

Arrow_In3:
	mov r5, r16
	mov r4, r17
	subi sp, sp, 8
	stw r10, 4(sp)
	stw ra, 0(sp)
	call draw_everything
	ldw ra, 0(sp)
	addi sp, sp, 4
	mov r5, r16
	mov r4, r17
	subi sp, sp, 4
	stw ra, 0(sp)
	call arrow_input
	ldw ra, 0(sp)
	ldw r10, 4(sp)
	addi sp, sp, 8
	beq r18, r0, Black_Arrow1
Make_move_black:
	mov r14, r20
	slli r14,r14,4
	or r14,r14,r19
	movia r22, legalMoves
Check_legal_black:
	ldw r13, 0(r22)
	beq r13, r0, Black_Arrow1
	addi r22,r22, 0x4
	bne r13, r14, Check_legal_black
	
	
	movia r13, PawnWhite
Loop_Take_Pawn_White:
	ldw r11, 0(r13)
	beq r11, r0, Pre_Loop_Take_Rook_White
	beq r11, r14, Take_White_Piece
	addi r13,r13,2
	br Loop_Take_Pawn_White

Pre_Loop_Take_Rook_White:
	movia r13, RookWhite

Loop_Take_Rook_White:
	ldw r11, 0(r13)
	beq r11, r0, Pre_Loop_Take_Bishop_White
	beq r11, r14, Take_White_Piece
	addi r13,r13,2
	br Loop_Take_Rook_White

	Pre_Loop_Take_Bishop_White:
	movia r13, BishopWhite

Loop_Take_Bishop_White:
	ldw r11, 0(r13)
	beq r11, r0, Pre_Loop_Take_Knight_White
	beq r11, r14, Take_White_Piece
	addi r13,r13,2
	br Loop_Take_Bishop_White
	
Pre_Loop_Take_Knight_White:
	movia r13, KnightWhite

Loop_Take_Knight_White:
	ldw r11, 0(r13)
	beq r11, r0, Take_Queen_White
	beq r11, r14, Take_White_Piece
	addi r13,r13,2
	br Loop_Take_Knight_White

	

Take_Queen_White:
	movia r13, RookWhite
	ldw r11, 0(r13)
	beq r11, r14, Take_White_Piece
	addi r13,r13,2
	br Move_Black_Piece
	
	
	
	

Take_White_Piece:
	movi r11, 0xFF
	stw r11, 0(r13)
	br Move_Black_Piece
	
Move_Black_Piece:
	stw r14, 0(r10)
	subi sp, sp, 4
	stw ra, 0(sp)
	call draw_everything
	ldw ra, 0(sp)
	addi sp, sp, 4	
	br Loop
	
	draw_everything:
	subi sp, sp, 4
	stwio ra, 0(sp)
	call draw_chessboard	
	ldwio ra, 0(sp)
	addi sp, sp,4
	
	movia r10, PawnWhite
	ldw r11, 0(r10)
	
	draw_pawns_white:
	
	movi r12, 0xFF
	beq	r12, r11, Skip_Pawn_White
	andi r4, r11, 0xF
	andi r5, r11, 0xF0
	srli r5, r5, 4
	
	subi sp, sp, 12
	stwio r11, 8(sp)
	stwio r10, 4(sp)
	stwio ra, 0(sp)
	call draw_pawn_white
	ldwio r11, 8(sp)
	ldwio r10, 4(sp)
	ldwio ra, 0(sp)
	addi sp, sp,12
Skip_Pawn_White:
	addi r10,r10,2
	ldw r11, 0(r10)
	bne r11, r0, draw_pawns_white
	
	movia r10, PawnBlack
	ldw r11, 0(r10)
	draw_pawns_black:
	movi r12, 0xFF
	beq	r12, r11, Skip_Pawn_Black
	andi r4, r11, 0xF
	andi r5, r11, 0xF0
	srli r5, r5, 4
	
	subi sp, sp, 12
	stwio r11, 8(sp)
	stwio r10, 4(sp)
	stwio ra, 0(sp)
	
	call draw_pawn_black
	
	ldwio r11, 8(sp)
	ldwio r10, 4(sp)
	ldwio ra, 0(sp)
	addi sp, sp,12
Skip_Pawn_Black:
	addi r10,r10, 2
	ldw r11, 0(r10)
	bne r11, r0, draw_pawns_black
	
	
	movia r10, RookBlack
	ldw r11, 0(r10)
	
	draw_rooks_black:
	movi r12, 0xFF
	beq	r12, r11, Skip_Rook_Black
	andi r4, r11, 0xF
	andi r5, r11, 0xF0
	srli r5, r5, 4
	
	subi sp, sp, 12
	stwio r11, 8(sp)
	stwio r10, 4(sp)
	stwio ra, 0(sp)
	call draw_rook_black
	ldwio r11, 8(sp)
	ldwio r10, 4(sp)
	ldwio ra, 0(sp)
	addi sp, sp,12
Skip_Rook_Black:
	addi r10,r10,2
	ldw r11, 0(r10)
	bne r11, r0, draw_rooks_black
	
	movia r10, RookWhite
	ldw r11, 0(r10)
	
	draw_rooks_white:
	movi r12, 0xFF
	beq	r12, r11, Skip_Rook_White
	andi r4, r11, 0xF
	andi r5, r11, 0xF0
	srli r5, r5, 4
	
	subi sp, sp, 12
	stwio r11, 8(sp)
	stwio r10, 4(sp)
	stwio ra, 0(sp)
	call draw_rook_white
	ldwio r11, 8(sp)
	ldwio r10, 4(sp)
	ldwio ra, 0(sp)
	addi sp, sp,12
Skip_Rook_White:
	addi r10,r10,2
	ldw r11, 0(r10)
	bne r11, r0, draw_rooks_white
	
	movia r10, KnightBlack
	ldw r11, 0(r10)
	
	draw_knights_black:
	movi r12, 0xFF
	beq	r12, r11, Skip_Knight_Black
	andi r4, r11, 0xF
	andi r5, r11, 0xF0
	srli r5, r5, 4
	
	subi sp, sp, 12
	stwio r11, 8(sp)
	stwio r10, 4(sp)
	stwio ra, 0(sp)
	call draw_knight_black
	ldwio r11, 8(sp)
	ldwio r10, 4(sp)
	ldwio ra, 0(sp)
	addi sp, sp,12
Skip_Knight_Black:
	addi r10,r10,2
	ldw r11, 0(r10)
	bne r11, r0, draw_knights_black
	
	movia r10, KnightWhite
	ldw r11, 0(r10)
	
	draw_knights_white:
	movi r12, 0xFF
	beq	r12, r11, Skip_Knight_White
	andi r4, r11, 0xF
	andi r5, r11, 0xF0
	srli r5, r5, 4
	
	subi sp, sp, 12
	stwio r11, 8(sp)
	stwio r10, 4(sp)
	stwio ra, 0(sp)
	call draw_knight_white
	ldwio r11, 8(sp)
	ldwio r10, 4(sp)
	ldwio ra, 0(sp)
	addi sp, sp,12
Skip_Knight_White:
	addi r10,r10,2
	ldw r11, 0(r10)
	bne r11, r0, draw_knights_white
	
	movia r10, BishopBlack
	ldw r11, 0(r10)
	
	draw_bishops_black:
	movi r12, 0xFF
	beq	r12, r11, Skip_Bishop_Black
	andi r4, r11, 0xF
	andi r5, r11, 0xF0
	srli r5, r5, 4
	
	subi sp, sp, 12
	stwio r11, 8(sp)
	stwio r10, 4(sp)
	stwio ra, 0(sp)
	call draw_bishop_black
	ldwio r11, 8(sp)
	ldwio r10, 4(sp)
	ldwio ra, 0(sp)
	addi sp, sp,12
Skip_Bishop_Black:
	addi r10,r10,2
	ldw r11, 0(r10)
	bne r11, r0, draw_bishops_black
	
	movia r10, BishopWhite
	ldw r11, 0(r10)
	
	draw_bishops_white:
	movi r12, 0xFF
	beq	r12, r11, Skip_Bishop_White
	andi r4, r11, 0xF
	andi r5, r11, 0xF0
	srli r5, r5, 4
	
	subi sp, sp, 12
	stwio r11, 8(sp)
	stwio r10, 4(sp)
	stwio ra, 0(sp)
	call draw_bishop_white
	ldwio r11, 8(sp)
	ldwio r10, 4(sp)
	ldwio ra, 0(sp)
	addi sp, sp,12
Skip_Bishop_White:
	addi r10,r10,2
	ldw r11, 0(r10)
	bne r11, r0, draw_bishops_white
	
	movia r10, QueenBlack
	ldw r11, 0(r10)
	
	draw_queens_black:
	movi r12, 0xFF
	beq	r12, r11, Skip_Queen_Black
	andi r4, r11, 0xF
	andi r5, r11, 0xF0
	srli r5, r5, 4
	
	subi sp, sp, 12
	stwio r11, 8(sp)
	stwio r10, 4(sp)
	stwio ra, 0(sp)
	call draw_queen_black
	ldwio r11, 8(sp)
	ldwio r10, 4(sp)
	ldwio ra, 0(sp)
	addi sp, sp,12
Skip_Queen_Black:
	addi r10,r10,2
	ldw r11, 0(r10)
	bne r11, r0, draw_queens_black
	
	
	movia r10, QueenWhite
	ldw r11, 0(r10)
	
	draw_queens_white:
	movi r12, 0xFF
	beq	r12, r11, Skip_Queen_White
	andi r4, r11, 0xF
	andi r5, r11, 0xF0
	srli r5, r5, 4
	
	subi sp, sp, 12
	stwio r11, 8(sp)
	stwio r10, 4(sp)
	stwio ra, 0(sp)
	call draw_queen_white
	ldwio r11, 8(sp)
	ldwio r10, 4(sp)
	ldwio ra, 0(sp)
	addi sp, sp,12
Skip_Queen_White:
	addi r10,r10,2
	ldw r11, 0(r10)
	bne r11, r0, draw_queens_white
	
	
	movia r10, KingBlack
	ldw r11, 0(r10)
	
	draw_kings_black:
	andi r4, r11, 0xF
	andi r5, r11, 0xF0
	srli r5, r5, 4
	
	subi sp, sp, 12
	stwio r11, 8(sp)
	stwio r10, 4(sp)
	stwio ra, 0(sp)
	call draw_king_black
	ldwio r11, 8(sp)
	ldwio r10, 4(sp)
	ldwio ra, 0(sp)
	addi sp, sp,12
	addi r10,r10,2
	ldw r11, 0(r10)
	bne r11, r0, draw_kings_black
	
	movia r10, KingWhite
	ldw r11, 0(r10)
	
	draw_kings_white:
	
	andi r4, r11, 0xF
	andi r5, r11, 0xF0
	srli r5, r5, 4
	
	subi sp, sp, 12
	stwio r11, 8(sp)
	stwio r10, 4(sp)
	stwio ra, 0(sp)
	call draw_king_white
	ldwio r11, 8(sp)
	ldwio r10, 4(sp)
	ldwio ra, 0(sp)
	addi sp, sp,12
	addi r10,r10,2
	ldw r11, 0(r10)
	bne r11, r0, draw_kings_white
	ret


