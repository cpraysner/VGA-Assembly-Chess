typedef int bool;
#define true 1
#define false 0
#include "eligible_move_header.h"

void legal_queen_moves_black(int x, int y, int* pawnWhite, int* pawnBlack, int* rookWhite, int* rookBlack, int* knightWhite, int*knightBlack, int*bishopWhite, int* bishopBlack, int* queenWhite, int* queenBlack, int* kingWhite, int* kingBlack, int* array_legal){

legal_bishop_moves_black(x,y,pawnWhite,pawnBlack,rookWhite,rookBlack,kingWhite, knightBlack,bishopWhite,bishopBlack, queenWhite, queenBlack, kingWhite, kingBlack, array_legal);
legal_rook_moves_black(x,y,pawnWhite,pawnBlack,rookWhite,rookBlack,kingWhite, knightBlack,bishopWhite,bishopBlack, queenWhite, queenBlack, kingWhite, kingBlack, array_legal);




}