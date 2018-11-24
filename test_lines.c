

void write_pixel(int x, int y, short colour) {
  volatile short *vga_addr=(volatile short*)(0x08000000 + (y<<10) + (x<<1));
  *vga_addr=colour;
}

void write_char(int x, int y, char c) {
  // VGA character buffer
  volatile char * character_buffer = (char *) (0x09000000 + (y<<7) + x);
  *character_buffer = c;
}

/* set entire screen to write (not clearing character buffer) */

void clear_screen() {
  int x, y;
  for (x = 0; x < 320; x++) {
    for (y = 0; y < 240; y++) {
	  write_pixel(x,y,0);
	}
  }
}



void draw_light_square(int x_start, int y_start){
   int x, y;
   for(x = x_start; x < (x_start + 30); x++){
	for(y = y_start; y < (y_start+30); y++){
		write_pixel(x,y,0xC618);
	}
   }
}


void draw_dark_square(int x_start, int y_start){
   int x, y;
   for(x = x_start; x < (x_start + 30); x++){
	for(y = y_start; y < (y_start+30); y++){
		write_pixel(x,y,0x7BEF);
	}
   }
}


void draw_row_of_squares_odd(int y_start){
    

   draw_light_square(40,y_start);
   draw_dark_square(70,y_start);
   draw_light_square(100,y_start);
   draw_dark_square(130,y_start);
   draw_light_square(160,y_start);
   draw_dark_square(190,y_start);
   draw_light_square(220,y_start);
   draw_dark_square(250,y_start);


}

void draw_row_of_squares_even(int y_start){
    
   draw_dark_square(40,y_start);
   draw_light_square(70,y_start);
   draw_dark_square(100,y_start);
   draw_light_square(130,y_start);
   draw_dark_square(160,y_start);
   draw_light_square(190,y_start);
   draw_dark_square(220,y_start);
  draw_light_square(250,y_start);
   


}





void clear_char_buffer(){
int x,y;
char c;
for(x=0;x<320;x++){
    for(y=0;y<240;y++){
volatile char * character_buffer = (char *) (0x09000000 + (y<<7) + x);
*character_buffer = 0x00;
}
}


}


void draw_rook_black(int y_start, int x_start){
int x,y;
x_start = 40 + (x_start*30) - 30;
y_start = (y_start*30)-30;

for(x=x_start+2;x<(x_start+28);x++){
	for(y=y_start+19;y<(y_start+27);y++){
	write_pixel(x,y,0X0000);	
}
}

for(x=x_start+8;x<(x_start+22);x++){
	for(y=y_start+10;y<(y_start+19);y++){
	write_pixel(x,y,0X0000);	
}
}

for(x=x_start+2;x<(x_start+28);x++){
	for(y=y_start+5;y<(y_start+10);y++){
	write_pixel(x,y,0X0000);	
}
}

for(x=x_start+2;x<(x_start+7);x++){
	for(y=y_start+2;y<(y_start+5);y++){
	write_pixel(x,y,0X0000);	
}
}

for(x=x_start+12;x<(x_start+18);x++){
	for(y=y_start+2;y<(y_start+5);y++){
	write_pixel(x,y,0X0000);	
}
}

for(x=x_start+23;x<(x_start+28);x++){
	for(y=y_start+2;y<(y_start+5);y++){
	write_pixel(x,y,0X0000);	
}
}

}

void draw_bishop_white(int y_start, int x_start){
int x,y;
x_start = 40 + (x_start*30) - 30;
y_start = (y_start*30)-30;


write_pixel(x_start+5,y_start+26,0X0000);
write_pixel(x_start+5,y_start+27, 0X0000);


write_pixel(x_start+6,y_start+25, 0X0000);
write_pixel(x_start+6,y_start+26, 0XFFFF);
write_pixel(x_start+6,y_start+27,0X0000);


write_pixel(x_start+7,y_start+24,0X0000);
write_pixel(x_start+7,y_start+25,0XFFFF);
write_pixel(x_start+7,y_start+26,0XFFFF);
write_pixel(x_start+7,y_start+27,0X0000);


write_pixel(x_start+8,y_start+23, 0X0000);
write_pixel(x_start+8,y_start+24,0XFFFF);
write_pixel(x_start+8,y_start+25,0XFFFF);
write_pixel(x_start+8,y_start+26, 0XFFFF);
write_pixel(x_start+8,y_start+27, 0X0000);

write_pixel(x_start+9,y_start+8, 0X0000);
write_pixel(x_start+9,y_start+9, 0X0000);
write_pixel(x_start+9,y_start+10, 0X0000);

write_pixel(x_start+9,y_start+23,0X0000 );
write_pixel(x_start+9,y_start+24, 0XFFFF);
write_pixel(x_start+9,y_start+25, 0XFFFF);
write_pixel(x_start+9,y_start+26,0XFFFF );
write_pixel(x_start+9,y_start+27, 0X0000);


write_pixel(x_start+10,y_start+8, 0X0000);
write_pixel(x_start+10,y_start+9, 0XFFFF);
write_pixel(x_start+10,y_start+10, 0XFFFF);
write_pixel(x_start+10,y_start+11, 0X0000);
write_pixel(x_start+10,y_start+20, 0X0000);
write_pixel(x_start+10,y_start+21, 0X0000);
write_pixel(x_start+10,y_start+22, 0X0000);
write_pixel(x_start+10,y_start+23, 0X0000);
write_pixel(x_start+10,y_start+24, 0XFFFF);
write_pixel(x_start+10,y_start+25, 0XFFFF);
write_pixel(x_start+10,y_start+26, 0XFFFF);
write_pixel(x_start+10,y_start+27, 0X0000);


write_pixel(x_start+11,y_start+4, 0X0000);
write_pixel(x_start+11,y_start+5,0X0000 );
write_pixel(x_start+11,y_start+6, 0X0000);
write_pixel(x_start+11,y_start+7, 0X0000);
write_pixel(x_start+11,y_start+8, 0X0000);
write_pixel(x_start+11,y_start+9, 0XFFFF);
write_pixel(x_start+11,y_start+10, 0XFFFF);
write_pixel(x_start+11,y_start+11, 0X0000);
write_pixel(x_start+11,y_start+19, 0X0000);
write_pixel(x_start+11,y_start+20, 0XFFFF);
write_pixel(x_start+11,y_start+21, 0XFFFF);
write_pixel(x_start+11,y_start+22, 0XFFFF);
write_pixel(x_start+11,y_start+23, 0X0000);
write_pixel(x_start+11,y_start+24, 0XFFFF);
write_pixel(x_start+11,y_start+25, 0XFFFF);
write_pixel(x_start+11,y_start+26, 0XFFFF);
write_pixel(x_start+11,y_start+27, 0X0000);


write_pixel(x_start+12,y_start+3, 0X0000);
write_pixel(x_start+12,y_start+4, 0XFFFF);
write_pixel(x_start+12,y_start+5, 0XFFFF);
write_pixel(x_start+12,y_start+6, 0XFFFF);
write_pixel(x_start+12,y_start+7, 0XFFFF);
write_pixel(x_start+12,y_start+8, 0X0000);
write_pixel(x_start+12,y_start+9, 0XFFFF);
write_pixel(x_start+12,y_start+10, 0XFFFF);
write_pixel(x_start+12,y_start+11, 0X0000);
write_pixel(x_start+12,y_start+12, 0X0000);
write_pixel(x_start+12,y_start+13, 0X0000);
write_pixel(x_start+12,y_start+14, 0X0000);
write_pixel(x_start+12,y_start+15, 0X0000);
write_pixel(x_start+12,y_start+16, 0X0000);
write_pixel(x_start+12,y_start+17, 0X0000);
write_pixel(x_start+12,y_start+18, 0X0000);
write_pixel(x_start+12,y_start+19, 0XFFFF);
write_pixel(x_start+12,y_start+20, 0XFFFF);
write_pixel(x_start+12,y_start+21, 0XFFFF);
write_pixel(x_start+12,y_start+22, 0XFFFF);
write_pixel(x_start+12,y_start+23, 0X0000);
write_pixel(x_start+12,y_start+24, 0XFFFF);
write_pixel(x_start+12,y_start+25, 0XFFFF);
write_pixel(x_start+12,y_start+26, 0XFFFF);
write_pixel(x_start+12,y_start+27, 0X0000);

write_pixel(x_start+13,y_start+0,0X0000 );
write_pixel(x_start+13,y_start+1, 0X0000);
write_pixel(x_start+13,y_start+2, 0X0000);
write_pixel(x_start+13,y_start+3, 0XFFFF);
write_pixel(x_start+13,y_start+4, 0XFFFF);
write_pixel(x_start+13,y_start+5, 0XFFFF);
write_pixel(x_start+13,y_start+6, 0XFFFF);
write_pixel(x_start+13,y_start+7, 0XFFFF);
write_pixel(x_start+13,y_start+8, 0X0000);
write_pixel(x_start+13,y_start+9, 0XFFFF);
write_pixel(x_start+13,y_start+10, 0XFFFF);
write_pixel(x_start+13,y_start+11, 0X0000);
write_pixel(x_start+13,y_start+12, 0XFFFF);
write_pixel(x_start+13,y_start+13, 0XFFFF);
write_pixel(x_start+13,y_start+14, 0XFFFF);
write_pixel(x_start+13,y_start+15, 0XFFFF);
write_pixel(x_start+13,y_start+16, 0XFFFF);
write_pixel(x_start+13,y_start+17, 0XFFFF);
write_pixel(x_start+13,y_start+18, 0XFFFF);
write_pixel(x_start+13,y_start+19, 0XFFFF);
write_pixel(x_start+13,y_start+20, 0XFFFF);
write_pixel(x_start+13,y_start+21, 0XFFFF);
write_pixel(x_start+13,y_start+22, 0XFFFF);
write_pixel(x_start+13,y_start+23, 0X0000);
write_pixel(x_start+13,y_start+24, 0XFFFF);
write_pixel(x_start+13,y_start+25, 0XFFFF);
write_pixel(x_start+13,y_start+26, 0XFFFF);
write_pixel(x_start+13,y_start+27, 0X0000);



write_pixel(x_start+14,y_start+0, 0X0000);
write_pixel(x_start+14,y_start+1, 0XFFFF);
write_pixel(x_start+14,y_start+2, 0XFFFF);
write_pixel(x_start+14,y_start+3, 0XFFFF);
write_pixel(x_start+14,y_start+4, 0XFFFF);
write_pixel(x_start+14,y_start+5, 0XFFFF);
write_pixel(x_start+14,y_start+6, 0XFFFF);
write_pixel(x_start+14,y_start+7, 0XFFFF);
write_pixel(x_start+14,y_start+8, 0X0000);
write_pixel(x_start+14,y_start+9, 0XFFFF);
write_pixel(x_start+14,y_start+10, 0XFFFF);
write_pixel(x_start+14,y_start+11, 0X0000);
write_pixel(x_start+14,y_start+12, 0XFFFF);
write_pixel(x_start+14,y_start+13, 0XFFFF);
write_pixel(x_start+14,y_start+14, 0XFFFF);
write_pixel(x_start+14,y_start+15, 0XFFFF);
write_pixel(x_start+14,y_start+16, 0XFFFF);
write_pixel(x_start+14,y_start+17, 0XFFFF);
write_pixel(x_start+14,y_start+18, 0XFFFF);
write_pixel(x_start+14,y_start+19, 0XFFFF);
write_pixel(x_start+14,y_start+20, 0XFFFF);
write_pixel(x_start+14,y_start+21, 0XFFFF);
write_pixel(x_start+14,y_start+22, 0XFFFF);
write_pixel(x_start+14,y_start+23, 0X0000);
write_pixel(x_start+14,y_start+24, 0XFFFF);
write_pixel(x_start+14,y_start+25, 0XFFFF);
write_pixel(x_start+14,y_start+26, 0XFFFF);
write_pixel(x_start+14,y_start+27, 0X0000);

write_pixel(x_start+15,y_start+0, 0X0000);
write_pixel(x_start+15,y_start+1, 0XFFFF);
write_pixel(x_start+15,y_start+2, 0XFFFF);
write_pixel(x_start+15,y_start+3, 0XFFFF);
write_pixel(x_start+15,y_start+4, 0XFFFF);
write_pixel(x_start+15,y_start+5, 0XFFFF);
write_pixel(x_start+15,y_start+6, 0XFFFF);
write_pixel(x_start+15,y_start+7, 0XFFFF);
write_pixel(x_start+15,y_start+8, 0X0000);
write_pixel(x_start+15,y_start+9, 0XFFFF);
write_pixel(x_start+15,y_start+10, 0XFFFF);
write_pixel(x_start+15,y_start+11, 0X0000);
write_pixel(x_start+15,y_start+12, 0XFFFF);
write_pixel(x_start+15,y_start+13, 0XFFFF);
write_pixel(x_start+15,y_start+14, 0XFFFF);
write_pixel(x_start+15,y_start+15, 0XFFFF);
write_pixel(x_start+15,y_start+16, 0XFFFF);
write_pixel(x_start+15,y_start+17, 0XFFFF);
write_pixel(x_start+15,y_start+18, 0XFFFF);
write_pixel(x_start+15,y_start+19, 0XFFFF);
write_pixel(x_start+15,y_start+20, 0XFFFF);
write_pixel(x_start+15,y_start+21, 0XFFFF);
write_pixel(x_start+15,y_start+22, 0XFFFF);
write_pixel(x_start+15,y_start+23, 0X0000);
write_pixel(x_start+15,y_start+24, 0XFFFF);
write_pixel(x_start+15,y_start+25, 0XFFFF);
write_pixel(x_start+15,y_start+26, 0XFFFF);
write_pixel(x_start+15,y_start+27, 0X0000);

write_pixel(x_start+16,y_start+0, 0X0000);
write_pixel(x_start+16,y_start+1, 0X0000);
write_pixel(x_start+16,y_start+2, 0X0000);
write_pixel(x_start+16,y_start+3, 0XFFFF);
write_pixel(x_start+16,y_start+4, 0XFFFF);
write_pixel(x_start+16,y_start+5, 0XFFFF);
write_pixel(x_start+16,y_start+6, 0XFFFF);
write_pixel(x_start+16,y_start+7, 0XFFFF);
write_pixel(x_start+16,y_start+8, 0X0000);
write_pixel(x_start+16,y_start+9, 0XFFFF);
write_pixel(x_start+16,y_start+10, 0XFFFF);
write_pixel(x_start+16,y_start+11, 0X0000);
write_pixel(x_start+16,y_start+12, 0XFFFF);
write_pixel(x_start+16,y_start+13, 0XFFFF);
write_pixel(x_start+16,y_start+14, 0XFFFF);
write_pixel(x_start+16,y_start+15, 0XFFFF);
write_pixel(x_start+16,y_start+16, 0XFFFF);
write_pixel(x_start+16,y_start+17, 0XFFFF);
write_pixel(x_start+16,y_start+18, 0XFFFF);
write_pixel(x_start+16,y_start+19, 0XFFFF);
write_pixel(x_start+16,y_start+20, 0XFFFF);
write_pixel(x_start+16,y_start+21, 0XFFFF);
write_pixel(x_start+16,y_start+22, 0XFFFF);
write_pixel(x_start+16,y_start+23, 0X0000);
write_pixel(x_start+16,y_start+24, 0XFFFF);
write_pixel(x_start+16,y_start+25, 0XFFFF);
write_pixel(x_start+16,y_start+26, 0XFFFF);
write_pixel(x_start+16,y_start+27, 0X0000);


write_pixel(x_start+17,y_start+3,0X0000 );
write_pixel(x_start+17,y_start+4, 0XFFFF);
write_pixel(x_start+17,y_start+5, 0XFFFF);
write_pixel(x_start+17,y_start+6, 0XFFFF);
write_pixel(x_start+17,y_start+7, 0XFFFF);
write_pixel(x_start+17,y_start+8, 0X0000);
write_pixel(x_start+17,y_start+9, 0XFFFF);
write_pixel(x_start+17,y_start+10, 0XFFFF);
write_pixel(x_start+17,y_start+11, 0X0000);
write_pixel(x_start+17,y_start+12, 0X0000);
write_pixel(x_start+17,y_start+13, 0X0000);
write_pixel(x_start+17,y_start+14, 0X0000);
write_pixel(x_start+17,y_start+15, 0X0000);
write_pixel(x_start+17,y_start+16, 0X0000);
write_pixel(x_start+17,y_start+17, 0X0000);
write_pixel(x_start+17,y_start+18, 0X0000);
write_pixel(x_start+17,y_start+19, 0XFFFF);
write_pixel(x_start+17,y_start+20, 0XFFFF);
write_pixel(x_start+17,y_start+21, 0XFFFF);
write_pixel(x_start+17,y_start+22, 0XFFFF);
write_pixel(x_start+17,y_start+23, 0X0000);
write_pixel(x_start+17,y_start+24, 0XFFFF);
write_pixel(x_start+17,y_start+25, 0XFFFF);
write_pixel(x_start+17,y_start+26, 0XFFFF);
write_pixel(x_start+17,y_start+27, 0X0000);

write_pixel(x_start+18,y_start+4, 0X0000);
write_pixel(x_start+18,y_start+5, 0X0000);
write_pixel(x_start+18,y_start+6, 0X0000);
write_pixel(x_start+18,y_start+7, 0X0000);
write_pixel(x_start+18,y_start+8, 0X0000);
write_pixel(x_start+18,y_start+9, 0XFFFF);
write_pixel(x_start+18,y_start+10, 0XFFFF);
write_pixel(x_start+18,y_start+11, 0X0000);
write_pixel(x_start+18,y_start+19, 0X0000);
write_pixel(x_start+18,y_start+20, 0XFFFF);
write_pixel(x_start+18,y_start+21, 0XFFFF);
write_pixel(x_start+18,y_start+22, 0XFFFF);
write_pixel(x_start+18,y_start+23, 0X0000);
write_pixel(x_start+18,y_start+24, 0XFFFF);
write_pixel(x_start+18,y_start+25, 0XFFFF);
write_pixel(x_start+18,y_start+26, 0XFFFF);
write_pixel(x_start+18,y_start+27, 0X0000);


write_pixel(x_start+19,y_start+8, 0X0000);
write_pixel(x_start+19,y_start+9, 0XFFFF);
write_pixel(x_start+19,y_start+10, 0XFFFF);
write_pixel(x_start+19,y_start+11, 0X0000);
write_pixel(x_start+19,y_start+20, 0X0000);
write_pixel(x_start+19,y_start+21, 0X0000);
write_pixel(x_start+19,y_start+22, 0X0000);
write_pixel(x_start+19,y_start+23, 0X0000);
write_pixel(x_start+19,y_start+24, 0XFFFF);
write_pixel(x_start+19,y_start+25, 0XFFFF);
write_pixel(x_start+19,y_start+26, 0XFFFF);
write_pixel(x_start+19,y_start+27, 0X0000);


write_pixel(x_start+20,y_start+8, 0X0000);
write_pixel(x_start+20,y_start+9, 0X0000);
write_pixel(x_start+20,y_start+10, 0X0000);
write_pixel(x_start+20,y_start+23, 0X0000);
write_pixel(x_start+20,y_start+24, 0XFFFF);
write_pixel(x_start+20,y_start+25, 0XFFFF);
write_pixel(x_start+20,y_start+26, 0XFFFF);
write_pixel(x_start+20,y_start+27, 0X0000);

write_pixel(x_start+21,y_start+23, 0X0000);
write_pixel(x_start+21,y_start+24, 0XFFFF);
write_pixel(x_start+21,y_start+25, 0XFFFF);
write_pixel(x_start+21,y_start+26, 0XFFFF);
write_pixel(x_start+21,y_start+27, 0X0000);

write_pixel(x_start+22,y_start+24, 0X0000);
write_pixel(x_start+22,y_start+25, 0XFFFF);
write_pixel(x_start+22,y_start+26, 0XFFFF);
write_pixel(x_start+22,y_start+27, 0X0000);

write_pixel(x_start+23,y_start+25, 0X0000);
write_pixel(x_start+23,y_start+26, 0XFFFF);
write_pixel(x_start+23,y_start+27, 0X0000);

write_pixel(x_start+24,y_start+26, 0X0000);
write_pixel(x_start+24,y_start+27, 0X0000);



}

void draw_bishop_black(int y_start, int x_start){
int x,y;
x_start = 40 + (x_start*30) - 30;
y_start = (y_start*30)-30;


write_pixel(x_start+5,y_start+26,0X0000);
write_pixel(x_start+5,y_start+27, 0X0000);


write_pixel(x_start+6,y_start+25, 0X0000);
write_pixel(x_start+6,y_start+26, 0X0000);
write_pixel(x_start+6,y_start+27,0X0000);


write_pixel(x_start+7,y_start+24,0X0000);
write_pixel(x_start+7,y_start+25,0X0000);
write_pixel(x_start+7,y_start+26,0X0000);
write_pixel(x_start+7,y_start+27,0X0000);


write_pixel(x_start+8,y_start+23, 0X0000);
write_pixel(x_start+8,y_start+24,0X0000);
write_pixel(x_start+8,y_start+25,0X0000);
write_pixel(x_start+8,y_start+26, 0X0000);
write_pixel(x_start+8,y_start+27, 0X0000);

write_pixel(x_start+9,y_start+8, 0X0000);
write_pixel(x_start+9,y_start+9, 0X0000);
write_pixel(x_start+9,y_start+10, 0X0000);

write_pixel(x_start+9,y_start+23,0X0000 );
write_pixel(x_start+9,y_start+24, 0X0000);
write_pixel(x_start+9,y_start+25, 0X0000);
write_pixel(x_start+9,y_start+26,0X0000 );
write_pixel(x_start+9,y_start+27, 0X0000);


write_pixel(x_start+10,y_start+8, 0X0000);
write_pixel(x_start+10,y_start+9, 0X0000);
write_pixel(x_start+10,y_start+10, 0X0000);
write_pixel(x_start+10,y_start+11, 0X0000);
write_pixel(x_start+10,y_start+20, 0X0000);
write_pixel(x_start+10,y_start+21, 0X0000);
write_pixel(x_start+10,y_start+22, 0X0000);
write_pixel(x_start+10,y_start+23, 0X0000);
write_pixel(x_start+10,y_start+24, 0X0000);
write_pixel(x_start+10,y_start+25, 0X0000);
write_pixel(x_start+10,y_start+26, 0X0000);
write_pixel(x_start+10,y_start+27, 0X0000);


write_pixel(x_start+11,y_start+4, 0X0000);
write_pixel(x_start+11,y_start+5,0X0000 );
write_pixel(x_start+11,y_start+6, 0X0000);
write_pixel(x_start+11,y_start+7, 0X0000);
write_pixel(x_start+11,y_start+8, 0X0000);
write_pixel(x_start+11,y_start+9, 0X0000);
write_pixel(x_start+11,y_start+10, 0X0000);
write_pixel(x_start+11,y_start+11, 0X0000);
write_pixel(x_start+11,y_start+19, 0X0000);
write_pixel(x_start+11,y_start+20, 0X0000);
write_pixel(x_start+11,y_start+21, 0X0000);
write_pixel(x_start+11,y_start+22, 0X0000);
write_pixel(x_start+11,y_start+23, 0X0000);
write_pixel(x_start+11,y_start+24, 0X0000);
write_pixel(x_start+11,y_start+25, 0X0000);
write_pixel(x_start+11,y_start+26, 0X0000);
write_pixel(x_start+11,y_start+27, 0X0000);


write_pixel(x_start+12,y_start+3, 0X0000);
write_pixel(x_start+12,y_start+4, 0X0000);
write_pixel(x_start+12,y_start+5, 0X0000);
write_pixel(x_start+12,y_start+6, 0X0000);
write_pixel(x_start+12,y_start+7, 0X0000);
write_pixel(x_start+12,y_start+8, 0X0000);
write_pixel(x_start+12,y_start+9, 0X0000);
write_pixel(x_start+12,y_start+10, 0X0000);
write_pixel(x_start+12,y_start+11, 0X0000);
write_pixel(x_start+12,y_start+12, 0X0000);
write_pixel(x_start+12,y_start+13, 0X0000);
write_pixel(x_start+12,y_start+14, 0X0000);
write_pixel(x_start+12,y_start+15, 0X0000);
write_pixel(x_start+12,y_start+16, 0X0000);
write_pixel(x_start+12,y_start+17, 0X0000);
write_pixel(x_start+12,y_start+18, 0X0000);
write_pixel(x_start+12,y_start+19, 0X0000);
write_pixel(x_start+12,y_start+20, 0X0000);
write_pixel(x_start+12,y_start+21, 0X0000);
write_pixel(x_start+12,y_start+22, 0X0000);
write_pixel(x_start+12,y_start+23, 0X0000);
write_pixel(x_start+12,y_start+24, 0X0000);
write_pixel(x_start+12,y_start+25, 0X0000);
write_pixel(x_start+12,y_start+26, 0X0000);
write_pixel(x_start+12,y_start+27, 0X0000);

write_pixel(x_start+13,y_start+0,0X0000 );
write_pixel(x_start+13,y_start+1, 0X0000);
write_pixel(x_start+13,y_start+2, 0X0000);
write_pixel(x_start+13,y_start+3, 0X0000);
write_pixel(x_start+13,y_start+4, 0X0000);
write_pixel(x_start+13,y_start+5, 0X0000);
write_pixel(x_start+13,y_start+6, 0X0000);
write_pixel(x_start+13,y_start+7, 0X0000);
write_pixel(x_start+13,y_start+8, 0X0000);
write_pixel(x_start+13,y_start+9, 0X0000);
write_pixel(x_start+13,y_start+10, 0X0000);
write_pixel(x_start+13,y_start+11, 0X0000);
write_pixel(x_start+13,y_start+12, 0X0000);
write_pixel(x_start+13,y_start+13, 0X0000);
write_pixel(x_start+13,y_start+14, 0X0000);
write_pixel(x_start+13,y_start+15, 0X0000);
write_pixel(x_start+13,y_start+16, 0X0000);
write_pixel(x_start+13,y_start+17, 0X0000);
write_pixel(x_start+13,y_start+18, 0X0000);
write_pixel(x_start+13,y_start+19, 0X0000);
write_pixel(x_start+13,y_start+20, 0X0000);
write_pixel(x_start+13,y_start+21, 0X0000);
write_pixel(x_start+13,y_start+22, 0X0000);
write_pixel(x_start+13,y_start+23, 0X0000);
write_pixel(x_start+13,y_start+24, 0X0000);
write_pixel(x_start+13,y_start+25, 0X0000);
write_pixel(x_start+13,y_start+26, 0X0000);
write_pixel(x_start+13,y_start+27, 0X0000);



write_pixel(x_start+14,y_start+0, 0X0000);
write_pixel(x_start+14,y_start+1, 0X0000);
write_pixel(x_start+14,y_start+2, 0X0000);
write_pixel(x_start+14,y_start+3, 0X0000);
write_pixel(x_start+14,y_start+4, 0X0000);
write_pixel(x_start+14,y_start+5, 0X0000);
write_pixel(x_start+14,y_start+6, 0X0000);
write_pixel(x_start+14,y_start+7, 0X0000);
write_pixel(x_start+14,y_start+8, 0X0000);
write_pixel(x_start+14,y_start+9, 0X0000);
write_pixel(x_start+14,y_start+10, 0X0000);
write_pixel(x_start+14,y_start+11, 0X0000);
write_pixel(x_start+14,y_start+12, 0X0000);
write_pixel(x_start+14,y_start+13, 0X0000);
write_pixel(x_start+14,y_start+14, 0X0000);
write_pixel(x_start+14,y_start+15, 0X0000);
write_pixel(x_start+14,y_start+16, 0X0000);
write_pixel(x_start+14,y_start+17, 0X0000);
write_pixel(x_start+14,y_start+18, 0X0000);
write_pixel(x_start+14,y_start+19, 0X0000);
write_pixel(x_start+14,y_start+20, 0X0000);
write_pixel(x_start+14,y_start+21, 0X0000);
write_pixel(x_start+14,y_start+22, 0X0000);
write_pixel(x_start+14,y_start+23, 0X0000);
write_pixel(x_start+14,y_start+24, 0X0000);
write_pixel(x_start+14,y_start+25, 0X0000);
write_pixel(x_start+14,y_start+26, 0X0000);
write_pixel(x_start+14,y_start+27, 0X0000);

write_pixel(x_start+15,y_start+0, 0X0000);
write_pixel(x_start+15,y_start+1, 0X0000);
write_pixel(x_start+15,y_start+2, 0X0000);
write_pixel(x_start+15,y_start+3, 0X0000);
write_pixel(x_start+15,y_start+4, 0X0000);
write_pixel(x_start+15,y_start+5, 0X0000);
write_pixel(x_start+15,y_start+6, 0X0000);
write_pixel(x_start+15,y_start+7, 0X0000);
write_pixel(x_start+15,y_start+8, 0X0000);
write_pixel(x_start+15,y_start+9, 0X0000);
write_pixel(x_start+15,y_start+10, 0X0000);
write_pixel(x_start+15,y_start+11, 0X0000);
write_pixel(x_start+15,y_start+12, 0X0000);
write_pixel(x_start+15,y_start+13, 0X0000);
write_pixel(x_start+15,y_start+14, 0X0000);
write_pixel(x_start+15,y_start+15, 0X0000);
write_pixel(x_start+15,y_start+16, 0X0000);
write_pixel(x_start+15,y_start+17, 0X0000);
write_pixel(x_start+15,y_start+18, 0X0000);
write_pixel(x_start+15,y_start+19, 0X0000);
write_pixel(x_start+15,y_start+20, 0X0000);
write_pixel(x_start+15,y_start+21, 0X0000);
write_pixel(x_start+15,y_start+22, 0X0000);
write_pixel(x_start+15,y_start+23, 0X0000);
write_pixel(x_start+15,y_start+24, 0X0000);
write_pixel(x_start+15,y_start+25, 0X0000);
write_pixel(x_start+15,y_start+26, 0X0000);
write_pixel(x_start+15,y_start+27, 0X0000);

write_pixel(x_start+16,y_start+0, 0X0000);
write_pixel(x_start+16,y_start+1, 0X0000);
write_pixel(x_start+16,y_start+2, 0X0000);
write_pixel(x_start+16,y_start+3, 0X0000);
write_pixel(x_start+16,y_start+4, 0X0000);
write_pixel(x_start+16,y_start+5, 0X0000);
write_pixel(x_start+16,y_start+6, 0X0000);
write_pixel(x_start+16,y_start+7, 0X0000);
write_pixel(x_start+16,y_start+8, 0X0000);
write_pixel(x_start+16,y_start+9, 0X0000);
write_pixel(x_start+16,y_start+10, 0X0000);
write_pixel(x_start+16,y_start+11, 0X0000);
write_pixel(x_start+16,y_start+12, 0X0000);
write_pixel(x_start+16,y_start+13, 0X0000);
write_pixel(x_start+16,y_start+14, 0X0000);
write_pixel(x_start+16,y_start+15, 0X0000);
write_pixel(x_start+16,y_start+16, 0X0000);
write_pixel(x_start+16,y_start+17, 0X0000);
write_pixel(x_start+16,y_start+18, 0X0000);
write_pixel(x_start+16,y_start+19, 0X0000);
write_pixel(x_start+16,y_start+20, 0X0000);
write_pixel(x_start+16,y_start+21, 0X0000);
write_pixel(x_start+16,y_start+22, 0X0000);
write_pixel(x_start+16,y_start+23, 0X0000);
write_pixel(x_start+16,y_start+24, 0X0000);
write_pixel(x_start+16,y_start+25, 0X0000);
write_pixel(x_start+16,y_start+26, 0X0000);
write_pixel(x_start+16,y_start+27, 0X0000);


write_pixel(x_start+17,y_start+3,0X0000 );
write_pixel(x_start+17,y_start+4, 0X0000);
write_pixel(x_start+17,y_start+5, 0X0000);
write_pixel(x_start+17,y_start+6, 0X0000);
write_pixel(x_start+17,y_start+7, 0X0000);
write_pixel(x_start+17,y_start+8, 0X0000);
write_pixel(x_start+17,y_start+9, 0X0000);
write_pixel(x_start+17,y_start+10, 0X0000);
write_pixel(x_start+17,y_start+11, 0X0000);
write_pixel(x_start+17,y_start+12, 0X0000);
write_pixel(x_start+17,y_start+13, 0X0000);
write_pixel(x_start+17,y_start+14, 0X0000);
write_pixel(x_start+17,y_start+15, 0X0000);
write_pixel(x_start+17,y_start+16, 0X0000);
write_pixel(x_start+17,y_start+17, 0X0000);
write_pixel(x_start+17,y_start+18, 0X0000);
write_pixel(x_start+17,y_start+19, 0X0000);
write_pixel(x_start+17,y_start+20, 0X0000);
write_pixel(x_start+17,y_start+21, 0X0000);
write_pixel(x_start+17,y_start+22, 0X0000);
write_pixel(x_start+17,y_start+23, 0X0000);
write_pixel(x_start+17,y_start+24, 0X0000);
write_pixel(x_start+17,y_start+25, 0X0000);
write_pixel(x_start+17,y_start+26, 0X0000);
write_pixel(x_start+17,y_start+27, 0X0000);

write_pixel(x_start+18,y_start+4, 0X0000);
write_pixel(x_start+18,y_start+5, 0X0000);
write_pixel(x_start+18,y_start+6, 0X0000);
write_pixel(x_start+18,y_start+7, 0X0000);
write_pixel(x_start+18,y_start+8, 0X0000);
write_pixel(x_start+18,y_start+9, 0X0000);
write_pixel(x_start+18,y_start+10, 0X0000);
write_pixel(x_start+18,y_start+11, 0X0000);
write_pixel(x_start+18,y_start+19, 0X0000);
write_pixel(x_start+18,y_start+20, 0X0000);
write_pixel(x_start+18,y_start+21, 0X0000);
write_pixel(x_start+18,y_start+22, 0X0000);
write_pixel(x_start+18,y_start+23, 0X0000);
write_pixel(x_start+18,y_start+24, 0X0000);
write_pixel(x_start+18,y_start+25, 0X0000);
write_pixel(x_start+18,y_start+26, 0X0000);
write_pixel(x_start+18,y_start+27, 0X0000);


write_pixel(x_start+19,y_start+8, 0X0000);
write_pixel(x_start+19,y_start+9, 0X0000);
write_pixel(x_start+19,y_start+10, 0X0000);
write_pixel(x_start+19,y_start+11, 0X0000);
write_pixel(x_start+19,y_start+20, 0X0000);
write_pixel(x_start+19,y_start+21, 0X0000);
write_pixel(x_start+19,y_start+22, 0X0000);
write_pixel(x_start+19,y_start+23, 0X0000);
write_pixel(x_start+19,y_start+24, 0X0000);
write_pixel(x_start+19,y_start+25, 0X0000);
write_pixel(x_start+19,y_start+26, 0X0000);
write_pixel(x_start+19,y_start+27, 0X0000);


write_pixel(x_start+20,y_start+8, 0X0000);
write_pixel(x_start+20,y_start+9, 0X0000);
write_pixel(x_start+20,y_start+10, 0X0000);
write_pixel(x_start+20,y_start+23, 0X0000);
write_pixel(x_start+20,y_start+24, 0X0000);
write_pixel(x_start+20,y_start+25, 0X0000);
write_pixel(x_start+20,y_start+26, 0X0000);
write_pixel(x_start+20,y_start+27, 0X0000);

write_pixel(x_start+21,y_start+23, 0X0000);
write_pixel(x_start+21,y_start+24, 0X0000);
write_pixel(x_start+21,y_start+25, 0X0000);
write_pixel(x_start+21,y_start+26, 0X0000);
write_pixel(x_start+21,y_start+27, 0X0000);

write_pixel(x_start+22,y_start+24, 0X0000);
write_pixel(x_start+22,y_start+25, 0X0000);
write_pixel(x_start+22,y_start+26, 0X0000);
write_pixel(x_start+22,y_start+27, 0X0000);

write_pixel(x_start+23,y_start+25, 0X0000);
write_pixel(x_start+23,y_start+26, 0X0000);
write_pixel(x_start+23,y_start+27, 0X0000);

write_pixel(x_start+24,y_start+26, 0X0000);
write_pixel(x_start+24,y_start+27, 0X0000);



}

void draw_rook_white(int y_start, int x_start){
int x,y;
x_start = 40 + (x_start*30) - 30;
y_start = (y_start*30)-30;

for(x=x_start+2;x<(x_start+28);x++){
	for(y=y_start+19;y<(y_start+27);y++){
	write_pixel(x,y,0XFFFF);	
}
}

for(x=x_start+8;x<(x_start+22);x++){
	for(y=y_start+10;y<(y_start+19);y++){
	write_pixel(x,y,0XFFFF);	
}
}

for(x=x_start+2;x<(x_start+28);x++){
	for(y=y_start+5;y<(y_start+10);y++){
	write_pixel(x,y,0XFFFF);	
}
}

for(x=x_start+2;x<(x_start+7);x++){
	for(y=y_start+2;y<(y_start+5);y++){
	write_pixel(x,y,0XFFFF);	
}
}

for(x=x_start+12;x<(x_start+18);x++){
	for(y=y_start+2;y<(y_start+5);y++){
	write_pixel(x,y,0XFFFF);	
}
}

for(x=x_start+23;x<(x_start+28);x++){
	for(y=y_start+2;y<(y_start+5);y++){
	write_pixel(x,y,0XFFFF);	
}
}

}

void draw_knight_white(int y_start, int x_start){
int x,y;
x_start = 40 + (x_start*30) - 30;
y_start = (y_start*30)-30;


write_pixel(x_start+5,y_start+8,0X0000);
write_pixel(x_start+5,y_start+9, 0X0000);
write_pixel(x_start+5,y_start+10, 0X0000 );

write_pixel(x_start+6,y_start+7, 0X0000);
write_pixel(x_start+6,y_start+8, 0X0000);
write_pixel(x_start+6,y_start+9, 0XFFFF);
write_pixel(x_start+6,y_start+10, 0XFFFF);
write_pixel(x_start+6,y_start+11, 0X0000);
write_pixel(x_start+6,y_start+22, 0X0000);
write_pixel(x_start+6,y_start+23, 0X0000);
write_pixel(x_start+6,y_start+24, 0X0000);


write_pixel(x_start+7,y_start+6, 0X0000);
write_pixel(x_start+7,y_start+7, 0X0000);
write_pixel(x_start+7,y_start+8, 0XFFFF);
write_pixel(x_start+7,y_start+9, 0XFFFF);
write_pixel(x_start+7,y_start+10, 0XFFFF);
write_pixel(x_start+7,y_start+11, 0X0000);
write_pixel(x_start+7,y_start+22, 0X0000);
write_pixel(x_start+7,y_start+23, 0XFFFF);
write_pixel(x_start+7,y_start+24, 0X0000);

write_pixel(x_start+8,y_start+6, 0X0000);
write_pixel(x_start+8,y_start+7, 0XFFFF);
write_pixel(x_start+8,y_start+8, 0XFFFF);
write_pixel(x_start+8,y_start+9, 0XFFFF);
write_pixel(x_start+8,y_start+10, 0XFFFF);
write_pixel(x_start+8,y_start+11, 0X0000);
write_pixel(x_start+8,y_start+21,0X0000 );
write_pixel(x_start+8,y_start+22, 0X0000);
write_pixel(x_start+8,y_start+23,0XFFFF );
write_pixel(x_start+8,y_start+24, 0X0000);


write_pixel(x_start+9,y_start+3, 0X0000);
write_pixel(x_start+9,y_start+4, 0X0000);
write_pixel(x_start+9,y_start+5, 0X0000);
write_pixel(x_start+9,y_start+6, 0XFFFF);
write_pixel(x_start+9,y_start+7, 0XFFFF);
write_pixel(x_start+9,y_start+8, 0XFFFF);
write_pixel(x_start+9,y_start+9, 0XFFFF);
write_pixel(x_start+9,y_start+10, 0XFFFF);
write_pixel(x_start+9,y_start+11, 0X0000);
write_pixel(x_start+9,y_start+21, 0X0000);
write_pixel(x_start+9,y_start+22, 0XFFFF);
write_pixel(x_start+9,y_start+23, 0XFFFF);
write_pixel(x_start+9,y_start+24, 0X0000);


write_pixel(x_start+10,y_start+3, 0X0000);
write_pixel(x_start+10,y_start+4, 0X0000);
write_pixel(x_start+10,y_start+5, 0X0000);
write_pixel(x_start+10,y_start+6, 0XFFFF);
write_pixel(x_start+10,y_start+7, 0XFFFF);
write_pixel(x_start+10,y_start+8, 0XFFFF);
write_pixel(x_start+10,y_start+9, 0XFFFF);
write_pixel(x_start+10,y_start+10, 0XFFFF);
write_pixel(x_start+10,y_start+11, 0X0000);
write_pixel(x_start+10,y_start+16, 0X0000);
write_pixel(x_start+10,y_start+17, 0X0000);
write_pixel(x_start+10,y_start+18, 0X0000);
write_pixel(x_start+10,y_start+19, 0X0000);
write_pixel(x_start+10,y_start+20, 0X0000);
write_pixel(x_start+10,y_start+21, 0X0000);
write_pixel(x_start+10,y_start+22, 0XFFFF);
write_pixel(x_start+10,y_start+23, 0XFFFF);
write_pixel(x_start+10,y_start+24, 0X0000);


write_pixel(x_start+11,y_start+3, 0X0000);
write_pixel(x_start+11,y_start+4, 0X0000);
write_pixel(x_start+11,y_start+5, 0X0000);
write_pixel(x_start+11,y_start+6, 0XFFFF);
write_pixel(x_start+11,y_start+7, 0XFFFF);
write_pixel(x_start+11,y_start+8, 0XFFFF);
write_pixel(x_start+11,y_start+9, 0XFFFF);
write_pixel(x_start+11,y_start+10, 0XFFFF);
write_pixel(x_start+11,y_start+11, 0X0000);
write_pixel(x_start+11,y_start+15, 0X0000);
write_pixel(x_start+11,y_start+16, 0X0000);
write_pixel(x_start+11,y_start+17, 0XFFFF);
write_pixel(x_start+11,y_start+18, 0XFFFF);
write_pixel(x_start+11,y_start+19, 0XFFFF);
write_pixel(x_start+11,y_start+20, 0XFFFF);
write_pixel(x_start+11,y_start+21, 0X0000);
write_pixel(x_start+11,y_start+22, 0XFFFF);
write_pixel(x_start+11,y_start+23, 0XFFFF);
write_pixel(x_start+11,y_start+24, 0X0000);

write_pixel(x_start+12,y_start+3, 0X0000);
write_pixel(x_start+12,y_start+4, 0X0000);
write_pixel(x_start+12,y_start+5, 0X0000);
write_pixel(x_start+12,y_start+6, 0XFFFF);
write_pixel(x_start+12,y_start+7, 0X0000);
write_pixel(x_start+12,y_start+8, 0XFFFF);
write_pixel(x_start+12,y_start+9, 0XFFFF);
write_pixel(x_start+12,y_start+10, 0XFFFF);
write_pixel(x_start+12,y_start+11, 0X0000);
write_pixel(x_start+12,y_start+12, 0X0000);
write_pixel(x_start+12,y_start+13, 0X0000);
write_pixel(x_start+12,y_start+14, 0X0000);
write_pixel(x_start+12,y_start+15, 0X0000);
write_pixel(x_start+12,y_start+16, 0XFFFF);
write_pixel(x_start+12,y_start+17, 0XFFFF);
write_pixel(x_start+12,y_start+18, 0XFFFF);
write_pixel(x_start+12,y_start+19, 0XFFFF);
write_pixel(x_start+12,y_start+20, 0XFFFF);
write_pixel(x_start+12,y_start+21, 0X0000);
write_pixel(x_start+12,y_start+22, 0XFFFF);
write_pixel(x_start+12,y_start+23, 0XFFFF);
write_pixel(x_start+12,y_start+24, 0X0000);


write_pixel(x_start+13,y_start+3, 0X0000);
write_pixel(x_start+13,y_start+4, 0X0000);
write_pixel(x_start+13,y_start+5, 0X0000);
write_pixel(x_start+13,y_start+6, 0XFFFF);
write_pixel(x_start+13,y_start+7, 0XFFFF);
write_pixel(x_start+13,y_start+8, 0XFFFF);
write_pixel(x_start+13,y_start+9, 0XFFFF);
write_pixel(x_start+13,y_start+10, 0XFFFF);
write_pixel(x_start+13,y_start+11, 0XFFFF);
write_pixel(x_start+13,y_start+12, 0XFFFF);
write_pixel(x_start+13,y_start+13, 0XFFFF);
write_pixel(x_start+13,y_start+14, 0XFFFF);
write_pixel(x_start+13,y_start+15, 0XFFFF);
write_pixel(x_start+13,y_start+16, 0XFFFF);
write_pixel(x_start+13,y_start+17, 0XFFFF);
write_pixel(x_start+13,y_start+18, 0XFFFF);
write_pixel(x_start+13,y_start+19, 0XFFFF);
write_pixel(x_start+13,y_start+20, 0XFFFF);
write_pixel(x_start+13,y_start+21, 0X0000);
write_pixel(x_start+13,y_start+22, 0XFFFF);
write_pixel(x_start+13,y_start+23, 0XFFFF);
write_pixel(x_start+13,y_start+24, 0X0000);

write_pixel(x_start+14,y_start+2, 0X0000);
write_pixel(x_start+14,y_start+3, 0X0000);
write_pixel(x_start+14,y_start+4, 0X0000);
write_pixel(x_start+14,y_start+5, 0X0000);
write_pixel(x_start+14,y_start+6, 0XFFFF);
write_pixel(x_start+14,y_start+7, 0XFFFF);
write_pixel(x_start+14,y_start+8, 0XFFFF);
write_pixel(x_start+14,y_start+9, 0XFFFF);
write_pixel(x_start+14,y_start+10, 0XFFFF);
write_pixel(x_start+14,y_start+11, 0XFFFF);
write_pixel(x_start+14,y_start+12, 0XFFFF);
write_pixel(x_start+14,y_start+13, 0XFFFF);
write_pixel(x_start+14,y_start+14, 0XFFFF);
write_pixel(x_start+14,y_start+15, 0XFFFF);
write_pixel(x_start+14,y_start+16, 0XFFFF);
write_pixel(x_start+14,y_start+17, 0XFFFF);
write_pixel(x_start+14,y_start+18, 0XFFFF);
write_pixel(x_start+14,y_start+19, 0XFFFF);
write_pixel(x_start+14,y_start+20, 0XFFFF);
write_pixel(x_start+14,y_start+21, 0X0000);
write_pixel(x_start+14,y_start+22, 0XFFFF);
write_pixel(x_start+14,y_start+23, 0XFFFF);
write_pixel(x_start+14,y_start+24, 0X0000);

write_pixel(x_start+15,y_start+3, 0X0000);
write_pixel(x_start+15,y_start+4, 0XFFFF);
write_pixel(x_start+15,y_start+5, 0XFFFF);
write_pixel(x_start+15,y_start+6, 0XFFFF);
write_pixel(x_start+15,y_start+7, 0XFFFF);
write_pixel(x_start+15,y_start+8, 0XFFFF);
write_pixel(x_start+15,y_start+9, 0XFFFF);
write_pixel(x_start+15,y_start+10, 0XFFFF);
write_pixel(x_start+15,y_start+11, 0XFFFF);
write_pixel(x_start+15,y_start+12, 0XFFFF);
write_pixel(x_start+15,y_start+13, 0XFFFF);
write_pixel(x_start+15,y_start+14, 0XFFFF);
write_pixel(x_start+15,y_start+15, 0XFFFF);
write_pixel(x_start+15,y_start+16, 0XFFFF);
write_pixel(x_start+15,y_start+17, 0XFFFF);
write_pixel(x_start+15,y_start+18, 0XFFFF);
write_pixel(x_start+15,y_start+19, 0XFFFF);
write_pixel(x_start+15,y_start+20, 0XFFFF);
write_pixel(x_start+15,y_start+21, 0X0000);
write_pixel(x_start+15,y_start+22, 0XFFFF);
write_pixel(x_start+15,y_start+23, 0XFFFF);
write_pixel(x_start+15,y_start+24, 0X0000);


write_pixel(x_start+16,y_start+3,0X0000 );
write_pixel(x_start+16,y_start+4, 0X0000);
write_pixel(x_start+16,y_start+5, 0X0000);
write_pixel(x_start+16,y_start+6, 0XFFFF);
write_pixel(x_start+16,y_start+7, 0XFFFF);
write_pixel(x_start+16,y_start+8, 0XFFFF);
write_pixel(x_start+16,y_start+9, 0XFFFF);
write_pixel(x_start+16,y_start+10, 0XFFFF);
write_pixel(x_start+16,y_start+11, 0XFFFF);
write_pixel(x_start+16,y_start+12, 0XFFFF);
write_pixel(x_start+16,y_start+13, 0XFFFF);
write_pixel(x_start+16,y_start+14, 0XFFFF);
write_pixel(x_start+16,y_start+15, 0XFFFF);
write_pixel(x_start+16,y_start+16, 0XFFFF);
write_pixel(x_start+16,y_start+17, 0XFFFF);
write_pixel(x_start+16,y_start+18, 0XFFFF);
write_pixel(x_start+16,y_start+19, 0XFFFF);
write_pixel(x_start+16,y_start+20, 0XFFFF);
write_pixel(x_start+16,y_start+21, 0X0000);
write_pixel(x_start+16,y_start+22, 0XFFFF);
write_pixel(x_start+16,y_start+23, 0XFFFF);
write_pixel(x_start+16,y_start+24, 0X0000);


write_pixel(x_start+17,y_start+4,0X0000 );
write_pixel(x_start+17,y_start+5, 0X0000);
write_pixel(x_start+17,y_start+6, 0XFFFF);
write_pixel(x_start+17,y_start+7, 0XFFFF);
write_pixel(x_start+17,y_start+8, 0XFFFF);
write_pixel(x_start+17,y_start+9, 0XFFFF);
write_pixel(x_start+17,y_start+10, 0XFFFF);
write_pixel(x_start+17,y_start+11, 0XFFFF);
write_pixel(x_start+17,y_start+12, 0XFFFF);
write_pixel(x_start+17,y_start+13, 0XFFFF);
write_pixel(x_start+17,y_start+14, 0XFFFF);
write_pixel(x_start+17,y_start+15, 0XFFFF);
write_pixel(x_start+17,y_start+16, 0XFFFF);
write_pixel(x_start+17,y_start+17, 0XFFFF);
write_pixel(x_start+17,y_start+18, 0XFFFF);
write_pixel(x_start+17,y_start+19, 0XFFFF);
write_pixel(x_start+17,y_start+20, 0XFFFF);
write_pixel(x_start+17,y_start+21, 0X0000);
write_pixel(x_start+17,y_start+22, 0XFFFF);
write_pixel(x_start+17,y_start+23, 0XFFFF);
write_pixel(x_start+17,y_start+24, 0X0000);


write_pixel(x_start+18,y_start+4,0X0000 );
write_pixel(x_start+18,y_start+5, 0X0000);
write_pixel(x_start+18,y_start+6, 0X0000);
write_pixel(x_start+18,y_start+7, 0XFFFF);
write_pixel(x_start+18,y_start+8, 0XFFFF);
write_pixel(x_start+18,y_start+9, 0XFFFF);
write_pixel(x_start+18,y_start+10, 0XFFFF);
write_pixel(x_start+18,y_start+11, 0XFFFF);
write_pixel(x_start+18,y_start+12, 0XFFFF);
write_pixel(x_start+18,y_start+13, 0XFFFF);
write_pixel(x_start+18,y_start+14, 0XFFFF);
write_pixel(x_start+18,y_start+15, 0X0000);
write_pixel(x_start+18,y_start+16, 0X0000);
write_pixel(x_start+18,y_start+17, 0X0000);
write_pixel(x_start+18,y_start+18, 0X0000);
write_pixel(x_start+18,y_start+19, 0X0000);
write_pixel(x_start+18,y_start+20, 0X0000);
write_pixel(x_start+18,y_start+21, 0X0000);
write_pixel(x_start+18,y_start+22, 0XFFFF);
write_pixel(x_start+18,y_start+23, 0XFFFF);
write_pixel(x_start+18,y_start+24, 0X0000);

write_pixel(x_start+19,y_start+5, 0X0000);
write_pixel(x_start+19,y_start+6, 0X0000);
write_pixel(x_start+19,y_start+7, 0X0000);
write_pixel(x_start+19,y_start+8, 0X0000);
write_pixel(x_start+19,y_start+9, 0XFFFF);
write_pixel(x_start+19,y_start+10, 0XFFFF);
write_pixel(x_start+19,y_start+11, 0XFFFF);
write_pixel(x_start+19,y_start+12, 0XFFFF);
write_pixel(x_start+19,y_start+13, 0XFFFF);
write_pixel(x_start+19,y_start+14, 0X0000);
write_pixel(x_start+19,y_start+15, 0X0000);
write_pixel(x_start+19,y_start+16, 0X0000);
write_pixel(x_start+19,y_start+17, 0X0000);
write_pixel(x_start+19,y_start+18, 0X0000);
write_pixel(x_start+19,y_start+19, 0X0000);
write_pixel(x_start+19,y_start+20, 0X0000);
write_pixel(x_start+19,y_start+21, 0X0000);
write_pixel(x_start+19,y_start+22, 0XFFFF);
write_pixel(x_start+19,y_start+23, 0XFFFF);
write_pixel(x_start+19,y_start+24, 0X0000);

write_pixel(x_start+20,y_start+6, 0X0000);
write_pixel(x_start+20,y_start+7, 0X0000);
write_pixel(x_start+20,y_start+8, 0X0000);
write_pixel(x_start+20,y_start+9, 0XFFFF);
write_pixel(x_start+20,y_start+10, 0XFFFF);
write_pixel(x_start+20,y_start+11, 0XFFFF);
write_pixel(x_start+20,y_start+12, 0XFFFF);
write_pixel(x_start+20,y_start+13, 0X0000);
write_pixel(x_start+20,y_start+14, 0X0000);
write_pixel(x_start+20,y_start+15, 0X0000);
write_pixel(x_start+20,y_start+16, 0X0000);
write_pixel(x_start+20,y_start+20, 0X0000);
write_pixel(x_start+20,y_start+21, 0X0000);
write_pixel(x_start+20,y_start+22, 0XFFFF);
write_pixel(x_start+20,y_start+23, 0XFFFF);
write_pixel(x_start+20,y_start+24, 0X0000);


write_pixel(x_start+21,y_start+7, 0X0000);
write_pixel(x_start+21,y_start+8, 0X0000);
write_pixel(x_start+21,y_start+9, 0X0000);
write_pixel(x_start+21,y_start+10, 0X0000);
write_pixel(x_start+21,y_start+11, 0X0000);
write_pixel(x_start+21,y_start+12, 0X0000);
write_pixel(x_start+21,y_start+13, 0X0000);
write_pixel(x_start+21,y_start+14, 0X0000);
write_pixel(x_start+21,y_start+15, 0X0000);
write_pixel(x_start+21,y_start+16, 0X0000);
write_pixel(x_start+21,y_start+21, 0X0000);
write_pixel(x_start+21,y_start+22, 0XFFFF);
write_pixel(x_start+21,y_start+23, 0XFFFF);
write_pixel(x_start+21,y_start+24, 0X0000);


write_pixel(x_start+22,y_start+8, 0X0000);
write_pixel(x_start+22,y_start+9, 0X0000);
write_pixel(x_start+22,y_start+10, 0X0000);
write_pixel(x_start+22,y_start+11, 0X0000);
write_pixel(x_start+22,y_start+12, 0X0000);
write_pixel(x_start+22,y_start+13, 0X0000);
write_pixel(x_start+22,y_start+14, 0X0000);
write_pixel(x_start+22,y_start+21, 0X0000);
write_pixel(x_start+22,y_start+22, 0X0000);
write_pixel(x_start+22,y_start+23, 0XFFFF);
write_pixel(x_start+22,y_start+24, 0X0000);

write_pixel(x_start+23,y_start+22, 0X0000);
write_pixel(x_start+23,y_start+23, 0XFFFF);
write_pixel(x_start+23,y_start+24, 0X0000);


write_pixel(x_start+24,y_start+22,0X0000 );
write_pixel(x_start+24,y_start+23, 0X0000);
write_pixel(x_start+24,y_start+24, 0X0000);


}

void draw_knight_black(int y_start, int x_start){
int x,y;
x_start = 40 + (x_start*30) - 30;
y_start = (y_start*30)-30;


write_pixel(x_start+5,y_start+8,0X0000);
write_pixel(x_start+5,y_start+9, 0X0000);
write_pixel(x_start+5,y_start+10, 0X0000 );

write_pixel(x_start+6,y_start+7, 0X0000);
write_pixel(x_start+6,y_start+8, 0X0000);
write_pixel(x_start+6,y_start+9, 0X0000);
write_pixel(x_start+6,y_start+10, 0X0000);
write_pixel(x_start+6,y_start+11, 0X0000);
write_pixel(x_start+6,y_start+22, 0X0000);
write_pixel(x_start+6,y_start+23, 0X0000);
write_pixel(x_start+6,y_start+24, 0X0000);


write_pixel(x_start+7,y_start+6, 0X0000);
write_pixel(x_start+7,y_start+7, 0X0000);
write_pixel(x_start+7,y_start+8, 0X0000);
write_pixel(x_start+7,y_start+9, 0X0000);
write_pixel(x_start+7,y_start+10, 0X0000);
write_pixel(x_start+7,y_start+11, 0X0000);
write_pixel(x_start+7,y_start+22, 0X0000);
write_pixel(x_start+7,y_start+23, 0X0000);
write_pixel(x_start+7,y_start+24, 0X0000);

write_pixel(x_start+8,y_start+6, 0X0000);
write_pixel(x_start+8,y_start+7, 0X0000);
write_pixel(x_start+8,y_start+8, 0X0000);
write_pixel(x_start+8,y_start+9, 0X0000);
write_pixel(x_start+8,y_start+10, 0X0000);
write_pixel(x_start+8,y_start+11, 0X0000);
write_pixel(x_start+8,y_start+21,0X0000 );
write_pixel(x_start+8,y_start+22, 0X0000);
write_pixel(x_start+8,y_start+23,0X0000 );
write_pixel(x_start+8,y_start+24, 0X0000);


write_pixel(x_start+9,y_start+3, 0X0000);
write_pixel(x_start+9,y_start+4, 0X0000);
write_pixel(x_start+9,y_start+5, 0X0000);
write_pixel(x_start+9,y_start+6, 0X0000);
write_pixel(x_start+9,y_start+7, 0X0000);
write_pixel(x_start+9,y_start+8, 0X0000);
write_pixel(x_start+9,y_start+9, 0X0000);
write_pixel(x_start+9,y_start+10, 0X0000);
write_pixel(x_start+9,y_start+11, 0X0000);
write_pixel(x_start+9,y_start+21, 0X0000);
write_pixel(x_start+9,y_start+22, 0X0000);
write_pixel(x_start+9,y_start+23, 0X0000);
write_pixel(x_start+9,y_start+24, 0X0000);


write_pixel(x_start+10,y_start+3, 0X0000);
write_pixel(x_start+10,y_start+4, 0X0000);
write_pixel(x_start+10,y_start+5, 0X0000);
write_pixel(x_start+10,y_start+6, 0X0000);
write_pixel(x_start+10,y_start+7, 0X0000);
write_pixel(x_start+10,y_start+8, 0X0000);
write_pixel(x_start+10,y_start+9, 0X0000);
write_pixel(x_start+10,y_start+10, 0X0000);
write_pixel(x_start+10,y_start+11, 0X0000);
write_pixel(x_start+10,y_start+16, 0X0000);
write_pixel(x_start+10,y_start+17, 0X0000);
write_pixel(x_start+10,y_start+18, 0X0000);
write_pixel(x_start+10,y_start+19, 0X0000);
write_pixel(x_start+10,y_start+20, 0X0000);
write_pixel(x_start+10,y_start+21, 0X0000);
write_pixel(x_start+10,y_start+22, 0X0000);
write_pixel(x_start+10,y_start+23, 0X0000);
write_pixel(x_start+10,y_start+24, 0X0000);


write_pixel(x_start+11,y_start+3, 0X0000);
write_pixel(x_start+11,y_start+4, 0X0000);
write_pixel(x_start+11,y_start+5, 0X0000);
write_pixel(x_start+11,y_start+6, 0X0000);
write_pixel(x_start+11,y_start+7, 0X0000);
write_pixel(x_start+11,y_start+8, 0X0000);
write_pixel(x_start+11,y_start+9, 0X0000);
write_pixel(x_start+11,y_start+10, 0X0000);
write_pixel(x_start+11,y_start+11, 0X0000);
write_pixel(x_start+11,y_start+15, 0X0000);
write_pixel(x_start+11,y_start+16, 0X0000);
write_pixel(x_start+11,y_start+17, 0X0000);
write_pixel(x_start+11,y_start+18, 0X0000);
write_pixel(x_start+11,y_start+19, 0X0000);
write_pixel(x_start+11,y_start+20, 0X0000);
write_pixel(x_start+11,y_start+21, 0X0000);
write_pixel(x_start+11,y_start+22, 0X0000);
write_pixel(x_start+11,y_start+23, 0X0000);
write_pixel(x_start+11,y_start+24, 0X0000);

write_pixel(x_start+12,y_start+3, 0X0000);
write_pixel(x_start+12,y_start+4, 0X0000);
write_pixel(x_start+12,y_start+5, 0X0000);
write_pixel(x_start+12,y_start+6, 0X0000);
write_pixel(x_start+12,y_start+7, 0XFFFF); 
write_pixel(x_start+12,y_start+8, 0X0000);
write_pixel(x_start+12,y_start+9, 0X0000);
write_pixel(x_start+12,y_start+10, 0X0000);
write_pixel(x_start+12,y_start+11, 0X0000);
write_pixel(x_start+12,y_start+12, 0X0000);
write_pixel(x_start+12,y_start+13, 0X0000);
write_pixel(x_start+12,y_start+14, 0X0000);
write_pixel(x_start+12,y_start+15, 0X0000);
write_pixel(x_start+12,y_start+16, 0X0000);
write_pixel(x_start+12,y_start+17, 0X0000);
write_pixel(x_start+12,y_start+18, 0X0000);
write_pixel(x_start+12,y_start+19, 0X0000);
write_pixel(x_start+12,y_start+20, 0X0000);
write_pixel(x_start+12,y_start+21, 0X0000);
write_pixel(x_start+12,y_start+22, 0X0000);
write_pixel(x_start+12,y_start+23, 0X0000);
write_pixel(x_start+12,y_start+24, 0X0000);


write_pixel(x_start+13,y_start+3, 0X0000);
write_pixel(x_start+13,y_start+4, 0X0000);
write_pixel(x_start+13,y_start+5, 0X0000);
write_pixel(x_start+13,y_start+6, 0X0000);
write_pixel(x_start+13,y_start+7, 0X0000);
write_pixel(x_start+13,y_start+8, 0X0000);
write_pixel(x_start+13,y_start+9, 0X0000);
write_pixel(x_start+13,y_start+10, 0X0000);
write_pixel(x_start+13,y_start+11, 0X0000);
write_pixel(x_start+13,y_start+12, 0X0000);
write_pixel(x_start+13,y_start+13, 0X0000);
write_pixel(x_start+13,y_start+14, 0X0000);
write_pixel(x_start+13,y_start+15, 0X0000);
write_pixel(x_start+13,y_start+16, 0X0000);
write_pixel(x_start+13,y_start+17, 0X0000);
write_pixel(x_start+13,y_start+18, 0X0000);
write_pixel(x_start+13,y_start+19, 0X0000);
write_pixel(x_start+13,y_start+20, 0X0000);
write_pixel(x_start+13,y_start+21, 0X0000);
write_pixel(x_start+13,y_start+22, 0X0000);
write_pixel(x_start+13,y_start+23, 0X0000);
write_pixel(x_start+13,y_start+24, 0X0000);

write_pixel(x_start+14,y_start+2, 0X0000);
write_pixel(x_start+14,y_start+3, 0X0000);
write_pixel(x_start+14,y_start+4, 0X0000);
write_pixel(x_start+14,y_start+5, 0X0000);
write_pixel(x_start+14,y_start+6, 0X0000);
write_pixel(x_start+14,y_start+7, 0X0000);
write_pixel(x_start+14,y_start+8, 0X0000);
write_pixel(x_start+14,y_start+9, 0X0000);
write_pixel(x_start+14,y_start+10, 0X0000);
write_pixel(x_start+14,y_start+11, 0X0000);
write_pixel(x_start+14,y_start+12, 0X0000);
write_pixel(x_start+14,y_start+13, 0X0000);
write_pixel(x_start+14,y_start+14, 0X0000);
write_pixel(x_start+14,y_start+15, 0X0000);
write_pixel(x_start+14,y_start+16, 0X0000);
write_pixel(x_start+14,y_start+17, 0X0000);
write_pixel(x_start+14,y_start+18, 0X0000);
write_pixel(x_start+14,y_start+19, 0X0000);
write_pixel(x_start+14,y_start+20, 0X0000);
write_pixel(x_start+14,y_start+21, 0X0000);
write_pixel(x_start+14,y_start+22, 0X0000);
write_pixel(x_start+14,y_start+23, 0X0000);
write_pixel(x_start+14,y_start+24, 0X0000);

write_pixel(x_start+15,y_start+3, 0X0000);
write_pixel(x_start+15,y_start+4, 0X0000);
write_pixel(x_start+15,y_start+5, 0X0000);
write_pixel(x_start+15,y_start+6, 0X0000);
write_pixel(x_start+15,y_start+7, 0X0000);
write_pixel(x_start+15,y_start+8, 0X0000);
write_pixel(x_start+15,y_start+9, 0X0000);
write_pixel(x_start+15,y_start+10, 0X0000);
write_pixel(x_start+15,y_start+11, 0X0000);
write_pixel(x_start+15,y_start+12, 0X0000);
write_pixel(x_start+15,y_start+13, 0X0000);
write_pixel(x_start+15,y_start+14, 0X0000);
write_pixel(x_start+15,y_start+15, 0X0000);
write_pixel(x_start+15,y_start+16, 0X0000);
write_pixel(x_start+15,y_start+17, 0X0000);
write_pixel(x_start+15,y_start+18, 0X0000);
write_pixel(x_start+15,y_start+19, 0X0000);
write_pixel(x_start+15,y_start+20, 0X0000);
write_pixel(x_start+15,y_start+21, 0X0000);
write_pixel(x_start+15,y_start+22, 0X0000);
write_pixel(x_start+15,y_start+23, 0X0000);
write_pixel(x_start+15,y_start+24, 0X0000);


write_pixel(x_start+16,y_start+3,0X0000 );
write_pixel(x_start+16,y_start+4, 0X0000);
write_pixel(x_start+16,y_start+5, 0X0000);
write_pixel(x_start+16,y_start+6, 0X0000);
write_pixel(x_start+16,y_start+7, 0X0000);
write_pixel(x_start+16,y_start+8, 0X0000);
write_pixel(x_start+16,y_start+9, 0X0000);
write_pixel(x_start+16,y_start+10, 0X0000);
write_pixel(x_start+16,y_start+11, 0X0000);
write_pixel(x_start+16,y_start+12, 0X0000);
write_pixel(x_start+16,y_start+13, 0X0000);
write_pixel(x_start+16,y_start+14, 0X0000);
write_pixel(x_start+16,y_start+15, 0X0000);
write_pixel(x_start+16,y_start+16, 0X0000);
write_pixel(x_start+16,y_start+17, 0X0000);
write_pixel(x_start+16,y_start+18, 0X0000);
write_pixel(x_start+16,y_start+19, 0X0000);
write_pixel(x_start+16,y_start+20, 0X0000);
write_pixel(x_start+16,y_start+21, 0X0000);
write_pixel(x_start+16,y_start+22, 0X0000);
write_pixel(x_start+16,y_start+23, 0X0000);
write_pixel(x_start+16,y_start+24, 0X0000);


write_pixel(x_start+17,y_start+4,0X0000 );
write_pixel(x_start+17,y_start+5, 0X0000);
write_pixel(x_start+17,y_start+6, 0X0000);
write_pixel(x_start+17,y_start+7, 0X0000);
write_pixel(x_start+17,y_start+8, 0X0000);
write_pixel(x_start+17,y_start+9, 0X0000);
write_pixel(x_start+17,y_start+10, 0X0000);
write_pixel(x_start+17,y_start+11, 0X0000);
write_pixel(x_start+17,y_start+12, 0X0000);
write_pixel(x_start+17,y_start+13, 0X0000);
write_pixel(x_start+17,y_start+14, 0X0000);
write_pixel(x_start+17,y_start+15, 0X0000);
write_pixel(x_start+17,y_start+16, 0X0000);
write_pixel(x_start+17,y_start+17, 0X0000);
write_pixel(x_start+17,y_start+18, 0X0000);
write_pixel(x_start+17,y_start+19, 0X0000);
write_pixel(x_start+17,y_start+20, 0X0000);
write_pixel(x_start+17,y_start+21, 0X0000);
write_pixel(x_start+17,y_start+22, 0X0000);
write_pixel(x_start+17,y_start+23, 0X0000);
write_pixel(x_start+17,y_start+24, 0X0000);


write_pixel(x_start+18,y_start+4,0X0000 );
write_pixel(x_start+18,y_start+5, 0X0000);
write_pixel(x_start+18,y_start+6, 0X0000);
write_pixel(x_start+18,y_start+7, 0X0000);
write_pixel(x_start+18,y_start+8, 0X0000);
write_pixel(x_start+18,y_start+9, 0X0000);
write_pixel(x_start+18,y_start+10, 0X0000);
write_pixel(x_start+18,y_start+11, 0X0000);
write_pixel(x_start+18,y_start+12, 0X0000);
write_pixel(x_start+18,y_start+13, 0X0000);
write_pixel(x_start+18,y_start+14, 0X0000);
write_pixel(x_start+18,y_start+15, 0X0000);
write_pixel(x_start+18,y_start+16, 0X0000);
write_pixel(x_start+18,y_start+17, 0X0000);
write_pixel(x_start+18,y_start+18, 0X0000);
write_pixel(x_start+18,y_start+19, 0X0000);
write_pixel(x_start+18,y_start+20, 0X0000);
write_pixel(x_start+18,y_start+21, 0X0000);
write_pixel(x_start+18,y_start+22, 0X0000);
write_pixel(x_start+18,y_start+23, 0X0000);
write_pixel(x_start+18,y_start+24, 0X0000);

write_pixel(x_start+19,y_start+5, 0X0000);
write_pixel(x_start+19,y_start+6, 0X0000);
write_pixel(x_start+19,y_start+7, 0X0000);
write_pixel(x_start+19,y_start+8, 0X0000);
write_pixel(x_start+19,y_start+9, 0X0000);
write_pixel(x_start+19,y_start+10, 0X0000);
write_pixel(x_start+19,y_start+11, 0X0000);
write_pixel(x_start+19,y_start+12, 0X0000);
write_pixel(x_start+19,y_start+13, 0X0000);
write_pixel(x_start+19,y_start+14, 0X0000);
write_pixel(x_start+19,y_start+15, 0X0000);
write_pixel(x_start+19,y_start+16, 0X0000);
write_pixel(x_start+19,y_start+17, 0X0000);
write_pixel(x_start+19,y_start+18, 0X0000);
write_pixel(x_start+19,y_start+19, 0X0000);
write_pixel(x_start+19,y_start+20, 0X0000);
write_pixel(x_start+19,y_start+21, 0X0000);
write_pixel(x_start+19,y_start+22, 0X0000);
write_pixel(x_start+19,y_start+23, 0X0000);
write_pixel(x_start+19,y_start+24, 0X0000);

write_pixel(x_start+20,y_start+6, 0X0000);
write_pixel(x_start+20,y_start+7, 0X0000);
write_pixel(x_start+20,y_start+8, 0X0000);
write_pixel(x_start+20,y_start+9, 0X0000);
write_pixel(x_start+20,y_start+10, 0X0000);
write_pixel(x_start+20,y_start+11, 0X0000);
write_pixel(x_start+20,y_start+12, 0X0000);
write_pixel(x_start+20,y_start+13, 0X0000);
write_pixel(x_start+20,y_start+14, 0X0000);
write_pixel(x_start+20,y_start+15, 0X0000);
write_pixel(x_start+20,y_start+16, 0X0000);
write_pixel(x_start+20,y_start+20, 0X0000);
write_pixel(x_start+20,y_start+21, 0X0000);
write_pixel(x_start+20,y_start+22, 0X0000);
write_pixel(x_start+20,y_start+23, 0X0000);
write_pixel(x_start+20,y_start+24, 0X0000);


write_pixel(x_start+21,y_start+7, 0X0000);
write_pixel(x_start+21,y_start+8, 0X0000);
write_pixel(x_start+21,y_start+9, 0X0000);
write_pixel(x_start+21,y_start+10, 0X0000);
write_pixel(x_start+21,y_start+11, 0X0000);
write_pixel(x_start+21,y_start+12, 0X0000);
write_pixel(x_start+21,y_start+13, 0X0000);
write_pixel(x_start+21,y_start+14, 0X0000);
write_pixel(x_start+21,y_start+15, 0X0000);
write_pixel(x_start+21,y_start+16, 0X0000);
write_pixel(x_start+21,y_start+21, 0X0000);
write_pixel(x_start+21,y_start+22, 0X0000);
write_pixel(x_start+21,y_start+23, 0X0000);
write_pixel(x_start+21,y_start+24, 0X0000);


write_pixel(x_start+22,y_start+8, 0X0000);
write_pixel(x_start+22,y_start+9, 0X0000);
write_pixel(x_start+22,y_start+10, 0X0000);
write_pixel(x_start+22,y_start+11, 0X0000);
write_pixel(x_start+22,y_start+12, 0X0000);
write_pixel(x_start+22,y_start+13, 0X0000);
write_pixel(x_start+22,y_start+14, 0X0000);
write_pixel(x_start+22,y_start+21, 0X0000);
write_pixel(x_start+22,y_start+22, 0X0000);
write_pixel(x_start+22,y_start+23, 0X0000);
write_pixel(x_start+22,y_start+24, 0X0000);

write_pixel(x_start+23,y_start+22, 0X0000);
write_pixel(x_start+23,y_start+23, 0X0000);
write_pixel(x_start+23,y_start+24, 0X0000);


write_pixel(x_start+24,y_start+22,0X0000 );
write_pixel(x_start+24,y_start+23, 0X0000);
write_pixel(x_start+24,y_start+24, 0X0000);


}


void draw_pawn_white(int y_start, int x_start){

int x,y;
x_start = 40 + (x_start*30) - 30;
y_start = (y_start*30)-30;

write_pixel(x_start+5,y_start+27,0X0000);
write_pixel(x_start+6,y_start+27,0X0000);
write_pixel(x_start+7,y_start+27,0X0000);
write_pixel(x_start+8,y_start+27,0X0000);
write_pixel(x_start+9,y_start+27,0X0000);
write_pixel(x_start+10,y_start+27,0X0000);
write_pixel(x_start+11,y_start+27,0X0000);
write_pixel(x_start+12,y_start+27,0X0000);
write_pixel(x_start+13,y_start+27,0X0000);
write_pixel(x_start+14,y_start+27,0X0000);
write_pixel(x_start+15,y_start+27,0X0000);
write_pixel(x_start+16,y_start+27,0X0000);
write_pixel(x_start+17,y_start+27,0X0000);
write_pixel(x_start+18,y_start+27,0X0000);
write_pixel(x_start+19,y_start+27,0X0000);
write_pixel(x_start+20,y_start+27,0X0000);
write_pixel(x_start+21,y_start+27,0X0000);
write_pixel(x_start+22,y_start+27,0X0000);
write_pixel(x_start+23,y_start+27,0X0000);
write_pixel(x_start+24,y_start+27,0X0000);



write_pixel(x_start+5,y_start+26,0X0000);
write_pixel(x_start+6,y_start+26,0XFFFF);
write_pixel(x_start+7,y_start+26,0XFFFF);
write_pixel(x_start+8,y_start+26,0XFFFF);
write_pixel(x_start+9,y_start+26,0XFFFF);
write_pixel(x_start+10,y_start+26,0XFFFF);
write_pixel(x_start+11,y_start+26,0XFFFF);
write_pixel(x_start+12,y_start+26,0XFFFF);
write_pixel(x_start+13,y_start+26,0XFFFF);
write_pixel(x_start+14,y_start+26,0XFFFF);
write_pixel(x_start+15,y_start+26,0XFFFF);
write_pixel(x_start+16,y_start+26,0XFFFF);
write_pixel(x_start+17,y_start+26,0XFFFF);
write_pixel(x_start+18,y_start+26,0XFFFF);
write_pixel(x_start+19,y_start+26,0XFFFF);
write_pixel(x_start+20,y_start+26,0XFFFF);
write_pixel(x_start+21,y_start+26,0XFFFF);
write_pixel(x_start+22,y_start+26,0XFFFF);
write_pixel(x_start+23,y_start+26,0XFFFF);
write_pixel(x_start+24,y_start+26,0X0000);

write_pixel(x_start+5,y_start+25,0X0000);
write_pixel(x_start+6,y_start+25,0XFFFF);
write_pixel(x_start+7,y_start+25,0XFFFF);
write_pixel(x_start+8,y_start+25,0XFFFF);
write_pixel(x_start+9,y_start+25,0XFFFF);
write_pixel(x_start+10,y_start+25,0XFFFF);
write_pixel(x_start+11,y_start+25,0XFFFF);
write_pixel(x_start+12,y_start+25,0XFFFF);
write_pixel(x_start+13,y_start+25,0XFFFF);
write_pixel(x_start+14,y_start+25,0XFFFF);
write_pixel(x_start+15,y_start+25,0XFFFF);
write_pixel(x_start+16,y_start+25,0XFFFF);
write_pixel(x_start+17,y_start+25,0XFFFF);
write_pixel(x_start+18,y_start+25,0XFFFF);
write_pixel(x_start+19,y_start+25,0XFFFF);
write_pixel(x_start+20,y_start+25,0XFFFF);
write_pixel(x_start+21,y_start+25,0XFFFF);
write_pixel(x_start+22,y_start+25,0XFFFF);
write_pixel(x_start+23,y_start+25,0XFFFF);
write_pixel(x_start+24,y_start+25,0X0000);

write_pixel(x_start+6,y_start+24,0X0000);
write_pixel(x_start+7,y_start+24,0XFFFF);
write_pixel(x_start+8,y_start+24,0XFFFF);
write_pixel(x_start+9,y_start+24,0XFFFF);
write_pixel(x_start+10,y_start+24,0XFFFF);
write_pixel(x_start+11,y_start+24,0XFFFF);
write_pixel(x_start+12,y_start+24,0XFFFF);
write_pixel(x_start+13,y_start+24,0XFFFF);
write_pixel(x_start+14,y_start+24,0XFFFF);
write_pixel(x_start+15,y_start+24,0XFFFF);
write_pixel(x_start+16,y_start+24,0XFFFF);
write_pixel(x_start+17,y_start+24,0XFFFF);
write_pixel(x_start+18,y_start+24,0XFFFF);
write_pixel(x_start+19,y_start+24,0XFFFF);
write_pixel(x_start+20,y_start+24,0XFFFF);
write_pixel(x_start+21,y_start+24,0XFFFF);
write_pixel(x_start+22,y_start+24,0XFFFF);
write_pixel(x_start+23,y_start+24,0X0000);


write_pixel(x_start+7,y_start+23,0XFFFF);
write_pixel(x_start+8,y_start+23,0XFFFF);
write_pixel(x_start+9,y_start+23,0XFFFF);
write_pixel(x_start+10,y_start+23,0XFFFF);
write_pixel(x_start+11,y_start+23,0XFFFF);
write_pixel(x_start+12,y_start+23,0XFFFF);
write_pixel(x_start+13,y_start+23,0XFFFF);
write_pixel(x_start+14,y_start+23,0XFFFF);
write_pixel(x_start+15,y_start+23,0XFFFF);
write_pixel(x_start+16,y_start+23,0XFFFF);
write_pixel(x_start+17,y_start+23,0XFFFF);
write_pixel(x_start+18,y_start+23,0XFFFF);
write_pixel(x_start+19,y_start+23,0XFFFF);
write_pixel(x_start+20,y_start+23,0XFFFF);
write_pixel(x_start+21,y_start+23,0XFFFF);
write_pixel(x_start+22,y_start+23,0XFFFF);


write_pixel(x_start+8,y_start+22,0X0000);
write_pixel(x_start+9,y_start+22,0XFFFF);
write_pixel(x_start+10,y_start+22,0XFFFF);
write_pixel(x_start+11,y_start+22,0XFFFF);
write_pixel(x_start+12,y_start+22,0XFFFF);
write_pixel(x_start+13,y_start+22,0XFFFF);
write_pixel(x_start+14,y_start+22,0XFFFF);
write_pixel(x_start+15,y_start+22,0XFFFF);
write_pixel(x_start+16,y_start+22,0XFFFF);
write_pixel(x_start+17,y_start+22,0XFFFF);
write_pixel(x_start+18,y_start+22,0XFFFF);
write_pixel(x_start+19,y_start+22,0XFFFF);
write_pixel(x_start+20,y_start+22,0XFFFF);
write_pixel(x_start+21,y_start+22,0X0000);


write_pixel(x_start+8,y_start+21,0X0000);
write_pixel(x_start+9,y_start+21,0XFFFF);
write_pixel(x_start+10,y_start+21,0XFFFF);
write_pixel(x_start+11,y_start+21,0XFFFF);
write_pixel(x_start+12,y_start+21,0XFFFF);
write_pixel(x_start+13,y_start+21,0XFFFF);
write_pixel(x_start+14,y_start+21,0XFFFF);
write_pixel(x_start+15,y_start+21,0XFFFF);
write_pixel(x_start+16,y_start+21,0XFFFF);
write_pixel(x_start+17,y_start+21,0XFFFF);
write_pixel(x_start+18,y_start+21,0XFFFF);
write_pixel(x_start+19,y_start+21,0XFFFF);
write_pixel(x_start+20,y_start+21,0XFFFF);
write_pixel(x_start+21,y_start+21,0X0000);

write_pixel(x_start+8,y_start+20,0X0000);
write_pixel(x_start+9,y_start+20,0XFFFF);
write_pixel(x_start+10,y_start+20,0XFFFF);
write_pixel(x_start+11,y_start+20,0XFFFF);
write_pixel(x_start+12,y_start+20,0XFFFF);
write_pixel(x_start+13,y_start+20,0XFFFF);
write_pixel(x_start+14,y_start+20,0XFFFF);
write_pixel(x_start+15,y_start+20,0XFFFF);
write_pixel(x_start+16,y_start+20,0XFFFF);
write_pixel(x_start+17,y_start+20,0XFFFF);
write_pixel(x_start+18,y_start+20,0XFFFF);
write_pixel(x_start+19,y_start+20,0XFFFF);
write_pixel(x_start+20,y_start+20,0XFFFF);
write_pixel(x_start+21,y_start+20,0X0000);


write_pixel(x_start+9,y_start+19,0X0000);
write_pixel(x_start+10,y_start+19,0XFFFF);
write_pixel(x_start+11,y_start+19,0XFFFF);
write_pixel(x_start+12,y_start+19,0XFFFF);
write_pixel(x_start+13,y_start+19,0XFFFF);
write_pixel(x_start+14,y_start+19,0XFFFF);
write_pixel(x_start+15,y_start+19,0XFFFF);
write_pixel(x_start+16,y_start+19,0XFFFF);
write_pixel(x_start+17,y_start+19,0XFFFF);
write_pixel(x_start+18,y_start+19,0XFFFF);
write_pixel(x_start+19,y_start+19,0XFFFF);
write_pixel(x_start+20,y_start+19,0X0000);

write_pixel(x_start+10,y_start+18,0X0000);
write_pixel(x_start+11,y_start+18,0X0000);
write_pixel(x_start+12,y_start+18,0X0000);
write_pixel(x_start+13,y_start+18,0X0000);
write_pixel(x_start+14,y_start+18,0X0000);
write_pixel(x_start+15,y_start+18,0X0000);
write_pixel(x_start+16,y_start+18,0X0000);
write_pixel(x_start+17,y_start+18,0X0000);
write_pixel(x_start+18,y_start+18,0X0000);
write_pixel(x_start+19,y_start+18,0X0000);

write_pixel(x_start+10,y_start+17,0X0000);
write_pixel(x_start+11,y_start+17,0XFFFF);
write_pixel(x_start+12,y_start+17,0XFFFF);
write_pixel(x_start+13,y_start+17,0XFFFF);
write_pixel(x_start+14,y_start+17,0XFFFF);
write_pixel(x_start+15,y_start+17,0XFFFF);
write_pixel(x_start+16,y_start+17,0XFFFF);
write_pixel(x_start+17,y_start+17,0XFFFF);
write_pixel(x_start+18,y_start+17,0XFFFF);
write_pixel(x_start+19,y_start+17,0X0000);

write_pixel(x_start+10,y_start+16,0X0000);
write_pixel(x_start+11,y_start+16,0XFFFF);
write_pixel(x_start+12,y_start+16,0XFFFF);
write_pixel(x_start+13,y_start+16,0XFFFF);
write_pixel(x_start+14,y_start+16,0XFFFF);
write_pixel(x_start+15,y_start+16,0XFFFF);
write_pixel(x_start+16,y_start+16,0XFFFF);
write_pixel(x_start+17,y_start+16,0XFFFF);
write_pixel(x_start+18,y_start+16,0XFFFF);
write_pixel(x_start+19,y_start+16,0X0000);

write_pixel(x_start+10,y_start+15,0X0000);
write_pixel(x_start+11,y_start+15,0XFFFF);
write_pixel(x_start+12,y_start+15,0XFFFF);
write_pixel(x_start+13,y_start+15,0XFFFF);
write_pixel(x_start+14,y_start+15,0XFFFF);
write_pixel(x_start+15,y_start+15,0XFFFF);
write_pixel(x_start+16,y_start+15,0XFFFF);
write_pixel(x_start+17,y_start+15,0XFFFF);
write_pixel(x_start+18,y_start+15,0XFFFF);
write_pixel(x_start+19,y_start+15,0X0000);

write_pixel(x_start+10,y_start+14,0X0000);
write_pixel(x_start+11,y_start+14,0XFFFF);
write_pixel(x_start+12,y_start+14,0XFFFF);
write_pixel(x_start+13,y_start+14,0XFFFF);
write_pixel(x_start+14,y_start+14,0XFFFF);
write_pixel(x_start+15,y_start+14,0XFFFF);
write_pixel(x_start+16,y_start+14,0XFFFF);
write_pixel(x_start+17,y_start+14,0XFFFF);
write_pixel(x_start+18,y_start+14,0XFFFF);
write_pixel(x_start+19,y_start+14,0X0000);

write_pixel(x_start+10,y_start+13,0X0000);
write_pixel(x_start+11,y_start+13,0XFFFF);
write_pixel(x_start+12,y_start+13,0XFFFF);
write_pixel(x_start+13,y_start+13,0XFFFF);
write_pixel(x_start+14,y_start+13,0XFFFF);
write_pixel(x_start+15,y_start+13,0XFFFF);
write_pixel(x_start+16,y_start+13,0XFFFF);
write_pixel(x_start+17,y_start+13,0XFFFF);
write_pixel(x_start+18,y_start+13,0XFFFF);
write_pixel(x_start+19,y_start+13,0X0000);

write_pixel(x_start+9,y_start+12,0X0000);
write_pixel(x_start+10,y_start+12,0X0000);
write_pixel(x_start+11,y_start+12,0X0000);
write_pixel(x_start+12,y_start+12,0X0000);
write_pixel(x_start+13,y_start+12,0X0000);
write_pixel(x_start+14,y_start+12,0X0000);
write_pixel(x_start+15,y_start+12,0X0000);
write_pixel(x_start+16,y_start+12,0X0000);
write_pixel(x_start+17,y_start+12,0X0000);
write_pixel(x_start+18,y_start+12,0X0000);
write_pixel(x_start+19,y_start+12,0X0000);
write_pixel(x_start+20,y_start+12,0X0000);


write_pixel(x_start+7,y_start+11,0X0000);
write_pixel(x_start+8,y_start+11,0X0000);
write_pixel(x_start+9,y_start+11,0XFFFF);
write_pixel(x_start+10,y_start+11,0XFFFF);
write_pixel(x_start+11,y_start+11,0XFFFF);
write_pixel(x_start+12,y_start+11,0XFFFF);
write_pixel(x_start+13,y_start+11,0XFFFF);
write_pixel(x_start+14,y_start+11,0XFFFF);
write_pixel(x_start+15,y_start+11,0XFFFF);
write_pixel(x_start+16,y_start+11,0XFFFF);
write_pixel(x_start+17,y_start+11,0XFFFF);
write_pixel(x_start+18,y_start+11,0XFFFF);
write_pixel(x_start+19,y_start+11,0XFFFF);
write_pixel(x_start+20,y_start+11,0XFFFF);
write_pixel(x_start+21,y_start+11,0X0000);
write_pixel(x_start+22,y_start+11,0X0000);

write_pixel(x_start+7,y_start+10,0X0000);
write_pixel(x_start+8,y_start+10,0XFFFF);
write_pixel(x_start+9,y_start+10,0XFFFF);
write_pixel(x_start+10,y_start+10,0XFFFF);
write_pixel(x_start+11,y_start+10,0XFFFF);
write_pixel(x_start+12,y_start+10,0XFFFF);
write_pixel(x_start+13,y_start+10,0XFFFF);
write_pixel(x_start+14,y_start+10,0XFFFF);
write_pixel(x_start+15,y_start+10,0XFFFF);
write_pixel(x_start+16,y_start+10,0XFFFF);
write_pixel(x_start+17,y_start+10,0XFFFF);
write_pixel(x_start+18,y_start+10,0XFFFF);
write_pixel(x_start+19,y_start+10,0XFFFF);
write_pixel(x_start+20,y_start+10,0XFFFF);
write_pixel(x_start+21,y_start+10,0XFFFF);
write_pixel(x_start+22,y_start+10,0X0000);

write_pixel(x_start+7,y_start+9,0X0000);
write_pixel(x_start+8,y_start+9,0XFFFF);
write_pixel(x_start+9,y_start+9,0XFFFF);
write_pixel(x_start+10,y_start+9,0XFFFF);
write_pixel(x_start+11,y_start+9,0XFFFF);
write_pixel(x_start+12,y_start+9,0XFFFF);
write_pixel(x_start+13,y_start+9,0XFFFF);
write_pixel(x_start+14,y_start+9,0XFFFF);
write_pixel(x_start+15,y_start+9,0XFFFF);
write_pixel(x_start+16,y_start+9,0XFFFF);
write_pixel(x_start+17,y_start+9,0XFFFF);
write_pixel(x_start+18,y_start+9,0XFFFF);
write_pixel(x_start+19,y_start+9,0XFFFF);
write_pixel(x_start+20,y_start+9,0XFFFF);
write_pixel(x_start+21,y_start+9,0XFFFF);
write_pixel(x_start+22,y_start+9,0X0000);

write_pixel(x_start+12,y_start+8,0X0000);
write_pixel(x_start+13,y_start+8,0XFFFF);
write_pixel(x_start+14,y_start+8,0XFFFF);
write_pixel(x_start+15,y_start+8,0XFFFF);
write_pixel(x_start+16,y_start+8,0XFFFF);
write_pixel(x_start+17,y_start+8,0X0000);

write_pixel(x_start+12,y_start+7,0X0000);
write_pixel(x_start+13,y_start+7,0XFFFF);
write_pixel(x_start+14,y_start+7,0XFFFF);
write_pixel(x_start+15,y_start+7,0XFFFF);
write_pixel(x_start+16,y_start+7,0XFFFF);
write_pixel(x_start+17,y_start+7,0X0000);

write_pixel(x_start+12,y_start+6,0X0000);
write_pixel(x_start+13,y_start+6,0XFFFF);
write_pixel(x_start+14,y_start+6,0XFFFF);
write_pixel(x_start+15,y_start+6,0XFFFF);
write_pixel(x_start+16,y_start+6,0XFFFF);
write_pixel(x_start+17,y_start+8,0X0000);

write_pixel(x_start+13,y_start+6,0X0000);
write_pixel(x_start+14,y_start+6,0X0000);
write_pixel(x_start+15,y_start+6,0X0000);
write_pixel(x_start+16,y_start+6,0X0000);


}

void draw_pawn_black(int y_start, int x_start){

x_start = 40 + (x_start*30) - 30;
y_start = (y_start*30)-30;

write_pixel(x_start+5,y_start+27,0X0000);
write_pixel(x_start+6,y_start+27,0X0000);
write_pixel(x_start+7,y_start+27,0X0000);
write_pixel(x_start+8,y_start+27,0X0000);
write_pixel(x_start+9,y_start+27,0X0000);
write_pixel(x_start+10,y_start+27,0X0000);
write_pixel(x_start+11,y_start+27,0X0000);
write_pixel(x_start+12,y_start+27,0X0000);
write_pixel(x_start+13,y_start+27,0X0000);
write_pixel(x_start+14,y_start+27,0X0000);
write_pixel(x_start+15,y_start+27,0X0000);
write_pixel(x_start+16,y_start+27,0X0000);
write_pixel(x_start+17,y_start+27,0X0000);
write_pixel(x_start+18,y_start+27,0X0000);
write_pixel(x_start+19,y_start+27,0X0000);
write_pixel(x_start+20,y_start+27,0X0000);
write_pixel(x_start+21,y_start+27,0X0000);
write_pixel(x_start+22,y_start+27,0X0000);
write_pixel(x_start+23,y_start+27,0X0000);
write_pixel(x_start+24,y_start+27,0X0000);



write_pixel(x_start+5,y_start+26,0X0000);
write_pixel(x_start+6,y_start+26,0X0000);
write_pixel(x_start+7,y_start+26,0X0000);
write_pixel(x_start+8,y_start+26,0X0000);
write_pixel(x_start+9,y_start+26,0X0000);
write_pixel(x_start+10,y_start+26,0X0000);
write_pixel(x_start+11,y_start+26,0X0000);
write_pixel(x_start+12,y_start+26,0X0000);
write_pixel(x_start+13,y_start+26,0X0000);
write_pixel(x_start+14,y_start+26,0X0000);
write_pixel(x_start+15,y_start+26,0X0000);
write_pixel(x_start+16,y_start+26,0X0000);
write_pixel(x_start+17,y_start+26,0X0000);
write_pixel(x_start+18,y_start+26,0X0000);
write_pixel(x_start+19,y_start+26,0X0000);
write_pixel(x_start+20,y_start+26,0X0000);
write_pixel(x_start+21,y_start+26,0X0000);
write_pixel(x_start+22,y_start+26,0X0000);
write_pixel(x_start+23,y_start+26,0X0000);
write_pixel(x_start+24,y_start+26,0X0000);

write_pixel(x_start+5,y_start+25,0X0000);
write_pixel(x_start+6,y_start+25,0X0000);
write_pixel(x_start+7,y_start+25,0X0000);
write_pixel(x_start+8,y_start+25,0X0000);
write_pixel(x_start+9,y_start+25,0X0000);
write_pixel(x_start+10,y_start+25,0X0000);
write_pixel(x_start+11,y_start+25,0X0000);
write_pixel(x_start+12,y_start+25,0X0000);
write_pixel(x_start+13,y_start+25,0X0000);
write_pixel(x_start+14,y_start+25,0X0000);
write_pixel(x_start+15,y_start+25,0X0000);
write_pixel(x_start+16,y_start+25,0X0000);
write_pixel(x_start+17,y_start+25,0X0000);
write_pixel(x_start+18,y_start+25,0X0000);
write_pixel(x_start+19,y_start+25,0X0000);
write_pixel(x_start+20,y_start+25,0X0000);
write_pixel(x_start+21,y_start+25,0X0000);
write_pixel(x_start+22,y_start+25,0X0000);
write_pixel(x_start+23,y_start+25,0X0000);
write_pixel(x_start+24,y_start+25,0X0000);

write_pixel(x_start+6,y_start+24,0X0000);
write_pixel(x_start+7,y_start+24,0X0000);
write_pixel(x_start+8,y_start+24,0X0000);
write_pixel(x_start+9,y_start+24,0X0000);
write_pixel(x_start+10,y_start+24,0X0000);
write_pixel(x_start+11,y_start+24,0X0000);
write_pixel(x_start+12,y_start+24,0X0000);
write_pixel(x_start+13,y_start+24,0X0000);
write_pixel(x_start+14,y_start+24,0X0000);
write_pixel(x_start+15,y_start+24,0X0000);
write_pixel(x_start+16,y_start+24,0X0000);
write_pixel(x_start+17,y_start+24,0X0000);
write_pixel(x_start+18,y_start+24,0X0000);
write_pixel(x_start+19,y_start+24,0X0000);
write_pixel(x_start+20,y_start+24,0X0000);
write_pixel(x_start+21,y_start+24,0X0000);
write_pixel(x_start+22,y_start+24,0X0000);
write_pixel(x_start+23,y_start+24,0X0000);


write_pixel(x_start+7,y_start+23,0X0000);
write_pixel(x_start+8,y_start+23,0X0000);
write_pixel(x_start+9,y_start+23,0X0000);
write_pixel(x_start+10,y_start+23,0X0000);
write_pixel(x_start+11,y_start+23,0X0000);
write_pixel(x_start+12,y_start+23,0X0000);
write_pixel(x_start+13,y_start+23,0X0000);
write_pixel(x_start+14,y_start+23,0X0000);
write_pixel(x_start+15,y_start+23,0X0000);
write_pixel(x_start+16,y_start+23,0X0000);
write_pixel(x_start+17,y_start+23,0X0000);
write_pixel(x_start+18,y_start+23,0X0000);
write_pixel(x_start+19,y_start+23,0X0000);
write_pixel(x_start+20,y_start+23,0X0000);
write_pixel(x_start+21,y_start+23,0X0000);
write_pixel(x_start+22,y_start+23,0X0000);


write_pixel(x_start+8,y_start+22,0X0000);
write_pixel(x_start+9,y_start+22,0X0000);
write_pixel(x_start+10,y_start+22,0X0000);
write_pixel(x_start+11,y_start+22,0X0000);
write_pixel(x_start+12,y_start+22,0X0000);
write_pixel(x_start+13,y_start+22,0X0000);
write_pixel(x_start+14,y_start+22,0X0000);
write_pixel(x_start+15,y_start+22,0X0000);
write_pixel(x_start+16,y_start+22,0X0000);
write_pixel(x_start+17,y_start+22,0X0000);
write_pixel(x_start+18,y_start+22,0X0000);
write_pixel(x_start+19,y_start+22,0X0000);
write_pixel(x_start+20,y_start+22,0X0000);
write_pixel(x_start+21,y_start+22,0X0000);


write_pixel(x_start+8,y_start+21,0X0000);
write_pixel(x_start+9,y_start+21,0X0000);
write_pixel(x_start+10,y_start+21,0X0000);
write_pixel(x_start+11,y_start+21,0X0000);
write_pixel(x_start+12,y_start+21,0X0000);
write_pixel(x_start+13,y_start+21,0X0000);
write_pixel(x_start+14,y_start+21,0X0000);
write_pixel(x_start+15,y_start+21,0X0000);
write_pixel(x_start+16,y_start+21,0X0000);
write_pixel(x_start+17,y_start+21,0X0000);
write_pixel(x_start+18,y_start+21,0X0000);
write_pixel(x_start+19,y_start+21,0X0000);
write_pixel(x_start+20,y_start+21,0X0000);
write_pixel(x_start+21,y_start+21,0X0000);

write_pixel(x_start+8,y_start+20,0X0000);
write_pixel(x_start+9,y_start+20,0X0000);
write_pixel(x_start+10,y_start+20,0X0000);
write_pixel(x_start+11,y_start+20,0X0000);
write_pixel(x_start+12,y_start+20,0X0000);
write_pixel(x_start+13,y_start+20,0X0000);
write_pixel(x_start+14,y_start+20,0X0000);
write_pixel(x_start+15,y_start+20,0X0000);
write_pixel(x_start+16,y_start+20,0X0000);
write_pixel(x_start+17,y_start+20,0X0000);
write_pixel(x_start+18,y_start+20,0X0000);
write_pixel(x_start+19,y_start+20,0X0000);
write_pixel(x_start+20,y_start+20,0X0000);
write_pixel(x_start+21,y_start+20,0X0000);


write_pixel(x_start+9,y_start+19,0X0000);
write_pixel(x_start+10,y_start+19,0X0000);
write_pixel(x_start+11,y_start+19,0X0000);
write_pixel(x_start+12,y_start+19,0X0000);
write_pixel(x_start+13,y_start+19,0X0000);
write_pixel(x_start+14,y_start+19,0X0000);
write_pixel(x_start+15,y_start+19,0X0000);
write_pixel(x_start+16,y_start+19,0X0000);
write_pixel(x_start+17,y_start+19,0X0000);
write_pixel(x_start+18,y_start+19,0X0000);
write_pixel(x_start+19,y_start+19,0X0000);
write_pixel(x_start+20,y_start+19,0X0000);

write_pixel(x_start+10,y_start+18,0X0000);
write_pixel(x_start+11,y_start+18,0X0000);
write_pixel(x_start+12,y_start+18,0X0000);
write_pixel(x_start+13,y_start+18,0X0000);
write_pixel(x_start+14,y_start+18,0X0000);
write_pixel(x_start+15,y_start+18,0X0000);
write_pixel(x_start+16,y_start+18,0X0000);
write_pixel(x_start+17,y_start+18,0X0000);
write_pixel(x_start+18,y_start+18,0X0000);
write_pixel(x_start+19,y_start+18,0X0000);

write_pixel(x_start+10,y_start+17,0X0000);
write_pixel(x_start+11,y_start+17,0X0000);
write_pixel(x_start+12,y_start+17,0X0000);
write_pixel(x_start+13,y_start+17,0X0000);
write_pixel(x_start+14,y_start+17,0X0000);
write_pixel(x_start+15,y_start+17,0X0000);
write_pixel(x_start+16,y_start+17,0X0000);
write_pixel(x_start+17,y_start+17,0X0000);
write_pixel(x_start+18,y_start+17,0X0000);
write_pixel(x_start+19,y_start+17,0X0000);

write_pixel(x_start+10,y_start+16,0X0000);
write_pixel(x_start+11,y_start+16,0X0000);
write_pixel(x_start+12,y_start+16,0X0000);
write_pixel(x_start+13,y_start+16,0X0000);
write_pixel(x_start+14,y_start+16,0X0000);
write_pixel(x_start+15,y_start+16,0X0000);
write_pixel(x_start+16,y_start+16,0X0000);
write_pixel(x_start+17,y_start+16,0X0000);
write_pixel(x_start+18,y_start+16,0X0000);
write_pixel(x_start+19,y_start+16,0X0000);

write_pixel(x_start+10,y_start+15,0X0000);
write_pixel(x_start+11,y_start+15,0X0000);
write_pixel(x_start+12,y_start+15,0X0000);
write_pixel(x_start+13,y_start+15,0X0000);
write_pixel(x_start+14,y_start+15,0X0000);
write_pixel(x_start+15,y_start+15,0X0000);
write_pixel(x_start+16,y_start+15,0X0000);
write_pixel(x_start+17,y_start+15,0X0000);
write_pixel(x_start+18,y_start+15,0X0000);
write_pixel(x_start+19,y_start+15,0X0000);

write_pixel(x_start+10,y_start+14,0X0000);
write_pixel(x_start+11,y_start+14,0X0000);
write_pixel(x_start+12,y_start+14,0X0000);
write_pixel(x_start+13,y_start+14,0X0000);
write_pixel(x_start+14,y_start+14,0X0000);
write_pixel(x_start+15,y_start+14,0X0000);
write_pixel(x_start+16,y_start+14,0X0000);
write_pixel(x_start+17,y_start+14,0X0000);
write_pixel(x_start+18,y_start+14,0X0000);
write_pixel(x_start+19,y_start+14,0X0000);

write_pixel(x_start+10,y_start+13,0X0000);
write_pixel(x_start+11,y_start+13,0X0000);
write_pixel(x_start+12,y_start+13,0X0000);
write_pixel(x_start+13,y_start+13,0X0000);
write_pixel(x_start+14,y_start+13,0X0000);
write_pixel(x_start+15,y_start+13,0X0000);
write_pixel(x_start+16,y_start+13,0X0000);
write_pixel(x_start+17,y_start+13,0X0000);
write_pixel(x_start+18,y_start+13,0X0000);
write_pixel(x_start+19,y_start+13,0X0000);

write_pixel(x_start+9,y_start+12,0X0000);
write_pixel(x_start+10,y_start+12,0X0000);
write_pixel(x_start+11,y_start+12,0X0000);
write_pixel(x_start+12,y_start+12,0X0000);
write_pixel(x_start+13,y_start+12,0X0000);
write_pixel(x_start+14,y_start+12,0X0000);
write_pixel(x_start+15,y_start+12,0X0000);
write_pixel(x_start+16,y_start+12,0X0000);
write_pixel(x_start+17,y_start+12,0X0000);
write_pixel(x_start+18,y_start+12,0X0000);
write_pixel(x_start+19,y_start+12,0X0000);
write_pixel(x_start+20,y_start+12,0X0000);


write_pixel(x_start+7,y_start+11,0X0000);
write_pixel(x_start+8,y_start+11,0X0000);
write_pixel(x_start+9,y_start+11,0X0000);
write_pixel(x_start+10,y_start+11,0X0000);
write_pixel(x_start+11,y_start+11,0X0000);
write_pixel(x_start+12,y_start+11,0X0000);
write_pixel(x_start+13,y_start+11,0X0000);
write_pixel(x_start+14,y_start+11,0X0000);
write_pixel(x_start+15,y_start+11,0X0000);
write_pixel(x_start+16,y_start+11,0X0000);
write_pixel(x_start+17,y_start+11,0X0000);
write_pixel(x_start+18,y_start+11,0X0000);
write_pixel(x_start+19,y_start+11,0X0000);
write_pixel(x_start+20,y_start+11,0X0000);
write_pixel(x_start+21,y_start+11,0X0000);
write_pixel(x_start+22,y_start+11,0X0000);

write_pixel(x_start+7,y_start+10,0X0000);
write_pixel(x_start+8,y_start+10,0X0000);
write_pixel(x_start+9,y_start+10,0X0000);
write_pixel(x_start+10,y_start+10,0X0000);
write_pixel(x_start+11,y_start+10,0X0000);
write_pixel(x_start+12,y_start+10,0X0000);
write_pixel(x_start+13,y_start+10,0X0000);
write_pixel(x_start+14,y_start+10,0X0000);
write_pixel(x_start+15,y_start+10,0X0000);
write_pixel(x_start+16,y_start+10,0X0000);
write_pixel(x_start+17,y_start+10,0X0000);
write_pixel(x_start+18,y_start+10,0X0000);
write_pixel(x_start+19,y_start+10,0X0000);
write_pixel(x_start+20,y_start+10,0X0000);
write_pixel(x_start+21,y_start+10,0X0000);
write_pixel(x_start+22,y_start+10,0X0000);

write_pixel(x_start+7,y_start+9,0X0000);
write_pixel(x_start+8,y_start+9,0X0000);
write_pixel(x_start+9,y_start+9,0X0000);
write_pixel(x_start+10,y_start+9,0X0000);
write_pixel(x_start+11,y_start+9,0X0000);
write_pixel(x_start+12,y_start+9,0X0000);
write_pixel(x_start+13,y_start+9,0X0000);
write_pixel(x_start+14,y_start+9,0X0000);
write_pixel(x_start+15,y_start+9,0X0000);
write_pixel(x_start+16,y_start+9,0X0000);
write_pixel(x_start+17,y_start+9,0X0000);
write_pixel(x_start+18,y_start+9,0X0000);
write_pixel(x_start+19,y_start+9,0X0000);
write_pixel(x_start+20,y_start+9,0X0000);
write_pixel(x_start+21,y_start+9,0X0000);
write_pixel(x_start+22,y_start+9,0X0000);

write_pixel(x_start+12,y_start+8,0X0000);
write_pixel(x_start+13,y_start+8,0X0000);
write_pixel(x_start+14,y_start+8,0X0000);
write_pixel(x_start+15,y_start+8,0X0000);
write_pixel(x_start+16,y_start+8,0X0000);
write_pixel(x_start+17,y_start+8,0X0000);

write_pixel(x_start+12,y_start+7,0X0000);
write_pixel(x_start+13,y_start+7,0X0000);
write_pixel(x_start+14,y_start+7,0X0000);
write_pixel(x_start+15,y_start+7,0X0000);
write_pixel(x_start+16,y_start+7,0X0000);
write_pixel(x_start+17,y_start+7,0X0000);

write_pixel(x_start+12,y_start+6,0X0000);
write_pixel(x_start+13,y_start+6,0X0000);
write_pixel(x_start+14,y_start+6,0X0000);
write_pixel(x_start+15,y_start+6,0X0000);
write_pixel(x_start+16,y_start+6,0X0000);
write_pixel(x_start+17,y_start+8,0X0000);

write_pixel(x_start+13,y_start+6,0X0000);
write_pixel(x_start+14,y_start+6,0X0000);
write_pixel(x_start+15,y_start+6,0X0000);
write_pixel(x_start+16,y_start+6,0X0000);


}

void draw_queen_black(int y_start, int x_start){
int x,y;
x_start = 40 + (x_start*30) - 30;
y_start = (y_start*30)-30;


write_pixel(x_start+5,y_start+26, 0X0000);
write_pixel(x_start+5,y_start+27, 0X0000);

write_pixel(x_start+6,y_start+25, 0X0000);
write_pixel(x_start+6,y_start+26, 0X0000);
write_pixel(x_start+6,y_start+27, 0X0000);


write_pixel(x_start+7,y_start+24, 0X0000);
write_pixel(x_start+7,y_start+25, 0X0000);
write_pixel(x_start+7,y_start+26, 0X0000);
write_pixel(x_start+7,y_start+27, 0X0000);

write_pixel(x_start+8,y_start+23, 0X0000);
write_pixel(x_start+8,y_start+24, 0X0000);
write_pixel(x_start+8,y_start+25, 0X0000);
write_pixel(x_start+8,y_start+26, 0X0000);
write_pixel(x_start+8,y_start+27,0X0000 );

write_pixel(x_start+9,y_start+23, 0X0000);
write_pixel(x_start+9,y_start+24, 0X0000);
write_pixel(x_start+9,y_start+25, 0X0000);
write_pixel(x_start+9,y_start+26, 0X0000);
write_pixel(x_start+9,y_start+27, 0X0000);

write_pixel(x_start+10,y_start+1, 0X0000);
write_pixel(x_start+10,y_start+2, 0X0000);
write_pixel(x_start+10,y_start+3, 0X0000);
write_pixel(x_start+10,y_start+4, 0X0000);
write_pixel(x_start+10,y_start+7, 0X0000);
write_pixel(x_start+10,y_start+8, 0X0000);
write_pixel(x_start+10,y_start+20, 0X0000);
write_pixel(x_start+10,y_start+21, 0X0000);
write_pixel(x_start+10,y_start+22, 0X0000);
write_pixel(x_start+10,y_start+23, 0X0000);
write_pixel(x_start+10,y_start+24, 0X0000);
write_pixel(x_start+10,y_start+25, 0X0000);
write_pixel(x_start+10,y_start+26, 0X0000);
write_pixel(x_start+10,y_start+27, 0X0000);


write_pixel(x_start+11,y_start+1, 0X0000);
write_pixel(x_start+11,y_start+2, 0X0000);
write_pixel(x_start+11,y_start+3, 0X0000);
write_pixel(x_start+11,y_start+4, 0X0000);
write_pixel(x_start+11,y_start+7, 0X0000);
write_pixel(x_start+11,y_start+8, 0X0000);
write_pixel(x_start+11,y_start+9, 0X0000);
write_pixel(x_start+11,y_start+14, 0X0000);
write_pixel(x_start+11,y_start+15, 0X0000);
write_pixel(x_start+11,y_start+16, 0X0000);
write_pixel(x_start+11,y_start+17, 0X0000);
write_pixel(x_start+11,y_start+18, 0X0000);
write_pixel(x_start+11,y_start+19, 0X0000);
write_pixel(x_start+11,y_start+20,0X0000 );
write_pixel(x_start+11,y_start+21, 0X0000);
write_pixel(x_start+11,y_start+22, 0X0000);
write_pixel(x_start+11,y_start+23,0X0000);
write_pixel(x_start+11,y_start+24, 0X0000);
write_pixel(x_start+11,y_start+25, 0X0000);
write_pixel(x_start+11,y_start+26, 0X0000);
write_pixel(x_start+11,y_start+27, 0X0000);


write_pixel(x_start+12,y_start+1, 0X0000);
write_pixel(x_start+12,y_start+2, 0X0000);
write_pixel(x_start+12,y_start+3, 0X0000);
write_pixel(x_start+12,y_start+4, 0X0000);
write_pixel(x_start+12,y_start+5, 0X0000);
write_pixel(x_start+12,y_start+6, 0X0000);
write_pixel(x_start+12,y_start+7, 0X0000);
write_pixel(x_start+12,y_start+8, 0X0000);
write_pixel(x_start+12,y_start+9, 0X0000);
write_pixel(x_start+12,y_start+10, 0X0000);
write_pixel(x_start+12,y_start+11, 0X0000);
write_pixel(x_start+12,y_start+12, 0X0000);
write_pixel(x_start+12,y_start+13, 0X0000);
write_pixel(x_start+12,y_start+14, 0X0000);
write_pixel(x_start+12,y_start+15, 0X0000);
write_pixel(x_start+12,y_start+16, 0X0000);
write_pixel(x_start+12,y_start+17, 0X0000);
write_pixel(x_start+12,y_start+18, 0X0000);
write_pixel(x_start+12,y_start+19, 0X0000);
write_pixel(x_start+12,y_start+20, 0X0000);
write_pixel(x_start+12,y_start+21, 0X0000);
write_pixel(x_start+12,y_start+22, 0X0000);
write_pixel(x_start+12,y_start+23, 0X0000);
write_pixel(x_start+12,y_start+24, 0X0000);
write_pixel(x_start+12,y_start+25, 0X0000);
write_pixel(x_start+12,y_start+26, 0X0000);
write_pixel(x_start+12,y_start+27, 0X0000);


write_pixel(x_start+13,y_start+1, 0X0000);
write_pixel(x_start+13,y_start+2, 0X0000);
write_pixel(x_start+13,y_start+3, 0X0000);
write_pixel(x_start+13,y_start+4, 0X0000);
write_pixel(x_start+13,y_start+5, 0X0000);
write_pixel(x_start+13,y_start+6, 0X0000);
write_pixel(x_start+13,y_start+7, 0X0000);
write_pixel(x_start+13,y_start+8, 0X0000);
write_pixel(x_start+13,y_start+9, 0X0000);
write_pixel(x_start+13,y_start+10, 0X0000);
write_pixel(x_start+13,y_start+11, 0X0000);
write_pixel(x_start+13,y_start+12, 0X0000);
write_pixel(x_start+13,y_start+13, 0X0000);
write_pixel(x_start+13,y_start+14, 0X0000);
write_pixel(x_start+13,y_start+15, 0X0000);
write_pixel(x_start+13,y_start+16, 0X0000);
write_pixel(x_start+13,y_start+17, 0X0000);
write_pixel(x_start+13,y_start+18, 0X0000);
write_pixel(x_start+13,y_start+19, 0X0000);
write_pixel(x_start+13,y_start+20, 0X0000);
write_pixel(x_start+13,y_start+21, 0X0000);
write_pixel(x_start+13,y_start+22, 0X0000);
write_pixel(x_start+13,y_start+23, 0X0000);
write_pixel(x_start+13,y_start+24, 0X0000);
write_pixel(x_start+13,y_start+25, 0X0000);
write_pixel(x_start+13,y_start+26, 0X0000);
write_pixel(x_start+13,y_start+27, 0X0000);

write_pixel(x_start+14,y_start+0,0XFFFF );
write_pixel(x_start+14,y_start+1, 0XFFFF);
write_pixel(x_start+14,y_start+2, 0XFFFF);
write_pixel(x_start+14,y_start+3, 0X0000);
write_pixel(x_start+14,y_start+4, 0X0000);
write_pixel(x_start+14,y_start+5, 0X0000);
write_pixel(x_start+14,y_start+6, 0X0000);
write_pixel(x_start+14,y_start+7, 0X0000);
write_pixel(x_start+14,y_start+8, 0X0000);
write_pixel(x_start+14,y_start+9, 0X0000);
write_pixel(x_start+14,y_start+10, 0X0000);
write_pixel(x_start+14,y_start+11, 0X0000);
write_pixel(x_start+14,y_start+12, 0X0000);
write_pixel(x_start+14,y_start+13, 0X0000);
write_pixel(x_start+14,y_start+14, 0X0000);
write_pixel(x_start+14,y_start+15, 0X0000);
write_pixel(x_start+14,y_start+16, 0X0000);
write_pixel(x_start+14,y_start+17, 0X0000);
write_pixel(x_start+14,y_start+18, 0X0000);
write_pixel(x_start+14,y_start+19, 0X0000);
write_pixel(x_start+14,y_start+20, 0X0000);
write_pixel(x_start+14,y_start+21, 0X0000);
write_pixel(x_start+14,y_start+22, 0X0000);
write_pixel(x_start+14,y_start+23, 0X0000);
write_pixel(x_start+14,y_start+24, 0X0000);
write_pixel(x_start+14,y_start+25, 0X0000);
write_pixel(x_start+14,y_start+26, 0X0000);
write_pixel(x_start+14,y_start+27, 0X0000);

write_pixel(x_start+15,y_start+0,0XFFFF );
write_pixel(x_start+15,y_start+1, 0XFFFF);
write_pixel(x_start+15,y_start+2, 0XFFFF);
write_pixel(x_start+15,y_start+3, 0X0000);
write_pixel(x_start+15,y_start+4, 0X0000);
write_pixel(x_start+15,y_start+5, 0X0000);
write_pixel(x_start+15,y_start+6, 0X0000);
write_pixel(x_start+15,y_start+7, 0X0000);
write_pixel(x_start+15,y_start+8, 0X0000);
write_pixel(x_start+15,y_start+9, 0X0000);
write_pixel(x_start+15,y_start+10, 0X0000);
write_pixel(x_start+15,y_start+11, 0X0000);
write_pixel(x_start+15,y_start+12, 0X0000);
write_pixel(x_start+15,y_start+13, 0X0000);
write_pixel(x_start+15,y_start+14, 0X0000);
write_pixel(x_start+15,y_start+15, 0X0000);
write_pixel(x_start+15,y_start+16, 0X0000);
write_pixel(x_start+15,y_start+17, 0X0000);
write_pixel(x_start+15,y_start+18, 0X0000);
write_pixel(x_start+15,y_start+19, 0X0000);
write_pixel(x_start+15,y_start+20, 0X0000);
write_pixel(x_start+15,y_start+21, 0X0000);
write_pixel(x_start+15,y_start+22, 0X0000);
write_pixel(x_start+15,y_start+23, 0X0000);
write_pixel(x_start+15,y_start+24, 0X0000);
write_pixel(x_start+15,y_start+25, 0X0000);
write_pixel(x_start+15,y_start+26, 0X0000);
write_pixel(x_start+15,y_start+27, 0X0000);


write_pixel(x_start+16,y_start+1, 0X0000);
write_pixel(x_start+16,y_start+2, 0X0000);
write_pixel(x_start+16,y_start+3, 0X0000);
write_pixel(x_start+16,y_start+4, 0X0000);
write_pixel(x_start+16,y_start+5, 0X0000);
write_pixel(x_start+16,y_start+6, 0X0000);
write_pixel(x_start+16,y_start+7,0X0000);
write_pixel(x_start+16,y_start+8, 0X0000);
write_pixel(x_start+16,y_start+9, 0X0000);
write_pixel(x_start+16,y_start+10, 0X0000);
write_pixel(x_start+16,y_start+11, 0X0000);
write_pixel(x_start+16,y_start+12, 0X0000);
write_pixel(x_start+16,y_start+13, 0X0000);
write_pixel(x_start+16,y_start+14, 0X0000);
write_pixel(x_start+16,y_start+15, 0X0000);
write_pixel(x_start+16,y_start+16, 0X0000);
write_pixel(x_start+16,y_start+17, 0X0000);
write_pixel(x_start+16,y_start+18, 0X0000);
write_pixel(x_start+16,y_start+19, 0X0000);
write_pixel(x_start+16,y_start+20, 0X0000);
write_pixel(x_start+16,y_start+21, 0X0000);
write_pixel(x_start+16,y_start+22, 0X0000);
write_pixel(x_start+16,y_start+23, 0X0000);
write_pixel(x_start+16,y_start+24, 0X0000);
write_pixel(x_start+16,y_start+25, 0X0000);
write_pixel(x_start+16,y_start+26, 0X0000);
write_pixel(x_start+16,y_start+27, 0X0000);


write_pixel(x_start+17,y_start+1, 0X0000);
write_pixel(x_start+17,y_start+2, 0X0000);
write_pixel(x_start+17,y_start+3, 0X0000);
write_pixel(x_start+17,y_start+4, 0X0000);
write_pixel(x_start+17,y_start+5, 0X0000);
write_pixel(x_start+17,y_start+6, 0X0000);
write_pixel(x_start+17,y_start+7, 0X0000);
write_pixel(x_start+17,y_start+8, 0X0000);
write_pixel(x_start+17,y_start+9, 0X0000);
write_pixel(x_start+17,y_start+10,0X0000 );
write_pixel(x_start+17,y_start+11, 0X0000);
write_pixel(x_start+17,y_start+12, 0X0000);
write_pixel(x_start+17,y_start+13, 0X0000);
write_pixel(x_start+17,y_start+14, 0X0000);
write_pixel(x_start+17,y_start+15, 0X0000);
write_pixel(x_start+17,y_start+16, 0X0000);
write_pixel(x_start+17,y_start+17, 0X0000);
write_pixel(x_start+17,y_start+18, 0X0000);
write_pixel(x_start+17,y_start+19, 0X0000);
write_pixel(x_start+17,y_start+20, 0X0000);
write_pixel(x_start+17,y_start+21, 0X0000);
write_pixel(x_start+17,y_start+22, 0X0000);
write_pixel(x_start+17,y_start+23, 0X0000);
write_pixel(x_start+17,y_start+24, 0X0000);
write_pixel(x_start+17,y_start+25, 0X0000);
write_pixel(x_start+17,y_start+26, 0X0000);
write_pixel(x_start+17,y_start+27, 0X0000);


write_pixel(x_start+18,y_start+1, 0X0000);
write_pixel(x_start+18,y_start+2, 0X0000);
write_pixel(x_start+18,y_start+3, 0X0000);
write_pixel(x_start+18,y_start+4, 0X0000);
write_pixel(x_start+18,y_start+7, 0X0000);
write_pixel(x_start+18,y_start+8, 0X0000);
write_pixel(x_start+18,y_start+9, 0X0000);
write_pixel(x_start+18,y_start+14, 0X0000);
write_pixel(x_start+18,y_start+15, 0X0000);
write_pixel(x_start+18,y_start+16, 0X0000);
write_pixel(x_start+18,y_start+17, 0X0000);
write_pixel(x_start+18,y_start+18, 0X0000);
write_pixel(x_start+18,y_start+19, 0X0000);
write_pixel(x_start+18,y_start+20, 0X0000);
write_pixel(x_start+18,y_start+21, 0X0000);
write_pixel(x_start+18,y_start+22, 0X0000);
write_pixel(x_start+18,y_start+23,0X0000 );
write_pixel(x_start+18,y_start+24, 0X0000);
write_pixel(x_start+18,y_start+25, 0X0000);
write_pixel(x_start+18,y_start+26, 0X0000);
write_pixel(x_start+18,y_start+27, 0X0000);

write_pixel(x_start+19,y_start+1, 0X0000);
write_pixel(x_start+19,y_start+2, 0X0000);
write_pixel(x_start+19,y_start+3, 0X0000);
write_pixel(x_start+19,y_start+4, 0X0000);
write_pixel(x_start+19,y_start+7, 0X0000);
write_pixel(x_start+19,y_start+8, 0X0000);
write_pixel(x_start+19,y_start+20, 0X0000);
write_pixel(x_start+19,y_start+21, 0X0000);
write_pixel(x_start+19,y_start+22, 0X0000);
write_pixel(x_start+19,y_start+23, 0X0000);
write_pixel(x_start+19,y_start+24, 0X0000);
write_pixel(x_start+19,y_start+25, 0X0000);
write_pixel(x_start+19,y_start+26, 0X0000);
write_pixel(x_start+19,y_start+27,0X0000 );

write_pixel(x_start+20,y_start+23, 0X0000);
write_pixel(x_start+20,y_start+24, 0X0000);
write_pixel(x_start+20,y_start+25, 0X0000);
write_pixel(x_start+20,y_start+26, 0X0000);
write_pixel(x_start+20,y_start+27, 0X0000);

write_pixel(x_start+21,y_start+23, 0X0000);
write_pixel(x_start+21,y_start+24, 0X0000);
write_pixel(x_start+21,y_start+25,0X0000 );
write_pixel(x_start+21,y_start+26, 0X0000);
write_pixel(x_start+21,y_start+27, 0X0000);

write_pixel(x_start+22,y_start+24, 0X0000);
write_pixel(x_start+22,y_start+25, 0X0000);
write_pixel(x_start+22,y_start+26, 0X0000);
write_pixel(x_start+22,y_start+27, 0X0000);

write_pixel(x_start+23,y_start+25, 0X0000);
write_pixel(x_start+23,y_start+26, 0X0000);
write_pixel(x_start+23,y_start+27, 0X0000);


write_pixel(x_start+24,y_start+26, 0X0000);
write_pixel(x_start+24,y_start+27, 0X0000);


}



void draw_queen_white(int y_start, int x_start){
int x,y;
x_start = 40 + (x_start*30) - 30;
y_start = (y_start*30)-30;


write_pixel(x_start+5,y_start+26, 0X0000);
write_pixel(x_start+5,y_start+27, 0X0000);

write_pixel(x_start+6,y_start+25, 0X0000);
write_pixel(x_start+6,y_start+26, 0XFFFF);
write_pixel(x_start+6,y_start+27, 0X0000);


write_pixel(x_start+7,y_start+24, 0X0000);
write_pixel(x_start+7,y_start+25, 0XFFFF);
write_pixel(x_start+7,y_start+26, 0XFFFF);
write_pixel(x_start+7,y_start+27, 0X0000);

write_pixel(x_start+8,y_start+23, 0X0000);
write_pixel(x_start+8,y_start+24, 0XFFFF);
write_pixel(x_start+8,y_start+25, 0XFFFF);
write_pixel(x_start+8,y_start+26, 0XFFFF);
write_pixel(x_start+8,y_start+27,0X0000 );

write_pixel(x_start+9,y_start+23, 0X0000);
write_pixel(x_start+9,y_start+24, 0XFFFF);
write_pixel(x_start+9,y_start+25, 0XFFFF);
write_pixel(x_start+9,y_start+26, 0XFFFF);
write_pixel(x_start+9,y_start+27, 0X0000);

write_pixel(x_start+10,y_start+1, 0X0000);
write_pixel(x_start+10,y_start+2, 0X0000);
write_pixel(x_start+10,y_start+3, 0X0000);
write_pixel(x_start+10,y_start+4, 0X0000);
write_pixel(x_start+10,y_start+7, 0X0000);
write_pixel(x_start+10,y_start+8, 0X0000);
write_pixel(x_start+10,y_start+20, 0X0000);
write_pixel(x_start+10,y_start+21, 0X0000);
write_pixel(x_start+10,y_start+22, 0X0000);
write_pixel(x_start+10,y_start+23, 0X0000);
write_pixel(x_start+10,y_start+24, 0XFFFF);
write_pixel(x_start+10,y_start+25, 0XFFFF);
write_pixel(x_start+10,y_start+26, 0XFFFF);
write_pixel(x_start+10,y_start+27, 0X0000);


write_pixel(x_start+11,y_start+1, 0X0000);
write_pixel(x_start+11,y_start+2, 0XFFFF);
write_pixel(x_start+11,y_start+3, 0XFFFF);
write_pixel(x_start+11,y_start+4, 0X0000);
write_pixel(x_start+11,y_start+7, 0X0000);
write_pixel(x_start+11,y_start+8, 0XFFFF);
write_pixel(x_start+11,y_start+9, 0X0000);
write_pixel(x_start+11,y_start+14, 0X0000);
write_pixel(x_start+11,y_start+15, 0X0000);
write_pixel(x_start+11,y_start+16, 0X0000);
write_pixel(x_start+11,y_start+17, 0X0000);
write_pixel(x_start+11,y_start+18, 0X0000);
write_pixel(x_start+11,y_start+19, 0X0000);
write_pixel(x_start+11,y_start+20,0XFFFF );
write_pixel(x_start+11,y_start+21, 0XFFFF);
write_pixel(x_start+11,y_start+22, 0XFFFF);
write_pixel(x_start+11,y_start+23,0X0000);
write_pixel(x_start+11,y_start+24, 0XFFFF);
write_pixel(x_start+11,y_start+25, 0XFFFF);
write_pixel(x_start+11,y_start+26, 0XFFFF);
write_pixel(x_start+11,y_start+27, 0X0000);


write_pixel(x_start+12,y_start+1, 0X0000);
write_pixel(x_start+12,y_start+2, 0XFFFF);
write_pixel(x_start+12,y_start+3, 0XFFFF);
write_pixel(x_start+12,y_start+4, 0XFFFF);
write_pixel(x_start+12,y_start+5, 0X0000);
write_pixel(x_start+12,y_start+6, 0X0000);
write_pixel(x_start+12,y_start+7, 0X0000);
write_pixel(x_start+12,y_start+8, 0XFFFF);
write_pixel(x_start+12,y_start+9, 0X0000);
write_pixel(x_start+12,y_start+10, 0X0000);
write_pixel(x_start+12,y_start+11, 0X0000);
write_pixel(x_start+12,y_start+12, 0X0000);
write_pixel(x_start+12,y_start+13, 0X0000);
write_pixel(x_start+12,y_start+14, 0XFFFF);
write_pixel(x_start+12,y_start+15, 0XFFFF);
write_pixel(x_start+12,y_start+16, 0XFFFF);
write_pixel(x_start+12,y_start+17, 0XFFFF);
write_pixel(x_start+12,y_start+18, 0XFFFF);
write_pixel(x_start+12,y_start+19, 0XFFFF);
write_pixel(x_start+12,y_start+20, 0XFFFF);
write_pixel(x_start+12,y_start+21, 0XFFFF);
write_pixel(x_start+12,y_start+22, 0XFFFF);
write_pixel(x_start+12,y_start+23, 0X0000);
write_pixel(x_start+12,y_start+24, 0XFFFF);
write_pixel(x_start+12,y_start+25, 0XFFFF);
write_pixel(x_start+12,y_start+26, 0XFFFF);
write_pixel(x_start+12,y_start+27, 0X0000);


write_pixel(x_start+13,y_start+1, 0X0000);
write_pixel(x_start+13,y_start+2, 0XFFFF);
write_pixel(x_start+13,y_start+3, 0XFFFF);
write_pixel(x_start+13,y_start+4, 0XFFFF);
write_pixel(x_start+13,y_start+5, 0XFFFF);
write_pixel(x_start+13,y_start+6, 0XFFFF);
write_pixel(x_start+13,y_start+7, 0X0000);
write_pixel(x_start+13,y_start+8, 0XFFFF);
write_pixel(x_start+13,y_start+9, 0X0000);
write_pixel(x_start+13,y_start+10, 0XFFFF);
write_pixel(x_start+13,y_start+11, 0XFFFF);
write_pixel(x_start+13,y_start+12, 0XFFFF);
write_pixel(x_start+13,y_start+13, 0XFFFF);
write_pixel(x_start+13,y_start+14, 0XFFFF);
write_pixel(x_start+13,y_start+15, 0XFFFF);
write_pixel(x_start+13,y_start+16, 0XFFFF);
write_pixel(x_start+13,y_start+17, 0XFFFF);
write_pixel(x_start+13,y_start+18, 0XFFFF);
write_pixel(x_start+13,y_start+19, 0XFFFF);
write_pixel(x_start+13,y_start+20, 0XFFFF);
write_pixel(x_start+13,y_start+21, 0XFFFF);
write_pixel(x_start+13,y_start+22, 0XFFFF);
write_pixel(x_start+13,y_start+23, 0X0000);
write_pixel(x_start+13,y_start+24, 0XFFFF);
write_pixel(x_start+13,y_start+25, 0XFFFF);
write_pixel(x_start+13,y_start+26, 0XFFFF);
write_pixel(x_start+13,y_start+27, 0X0000);

write_pixel(x_start+14,y_start+0,0X0000 );
write_pixel(x_start+14,y_start+1, 0X0000);
write_pixel(x_start+14,y_start+2, 0X0000);
write_pixel(x_start+14,y_start+3, 0XFFFF);
write_pixel(x_start+14,y_start+4, 0XFFFF);
write_pixel(x_start+14,y_start+5, 0XFFFF);
write_pixel(x_start+14,y_start+6, 0XFFFF);
write_pixel(x_start+14,y_start+7, 0X0000);
write_pixel(x_start+14,y_start+8, 0XFFFF);
write_pixel(x_start+14,y_start+9, 0X0000);
write_pixel(x_start+14,y_start+10, 0XFFFF);
write_pixel(x_start+14,y_start+11, 0XFFFF);
write_pixel(x_start+14,y_start+12, 0XFFFF);
write_pixel(x_start+14,y_start+13, 0XFFFF);
write_pixel(x_start+14,y_start+14, 0XFFFF);
write_pixel(x_start+14,y_start+15, 0XFFFF);
write_pixel(x_start+14,y_start+16, 0XFFFF);
write_pixel(x_start+14,y_start+17, 0XFFFF);
write_pixel(x_start+14,y_start+18, 0XFFFF);
write_pixel(x_start+14,y_start+19, 0XFFFF);
write_pixel(x_start+14,y_start+20, 0XFFFF);
write_pixel(x_start+14,y_start+21, 0XFFFF);
write_pixel(x_start+14,y_start+22, 0XFFFF);
write_pixel(x_start+14,y_start+23, 0X0000);
write_pixel(x_start+14,y_start+24, 0XFFFF);
write_pixel(x_start+14,y_start+25, 0XFFFF);
write_pixel(x_start+14,y_start+26, 0XFFFF);
write_pixel(x_start+14,y_start+27, 0X0000);

write_pixel(x_start+15,y_start+0,0X0000 );
write_pixel(x_start+15,y_start+1, 0X0000);
write_pixel(x_start+15,y_start+2, 0X0000);
write_pixel(x_start+15,y_start+3, 0XFFFF);
write_pixel(x_start+15,y_start+4, 0XFFFF);
write_pixel(x_start+15,y_start+5, 0XFFFF);
write_pixel(x_start+15,y_start+6, 0XFFFF);
write_pixel(x_start+15,y_start+7, 0X0000);
write_pixel(x_start+15,y_start+8, 0XFFFF);
write_pixel(x_start+15,y_start+9, 0X0000);
write_pixel(x_start+15,y_start+10, 0XFFFF);
write_pixel(x_start+15,y_start+11, 0XFFFF);
write_pixel(x_start+15,y_start+12, 0XFFFF);
write_pixel(x_start+15,y_start+13, 0XFFFF);
write_pixel(x_start+15,y_start+14, 0XFFFF);
write_pixel(x_start+15,y_start+15, 0XFFFF);
write_pixel(x_start+15,y_start+16, 0XFFFF);
write_pixel(x_start+15,y_start+17, 0XFFFF);
write_pixel(x_start+15,y_start+18, 0XFFFF);
write_pixel(x_start+15,y_start+19, 0XFFFF);
write_pixel(x_start+15,y_start+20, 0XFFFF);
write_pixel(x_start+15,y_start+21, 0XFFFF);
write_pixel(x_start+15,y_start+22, 0XFFFF);
write_pixel(x_start+15,y_start+23, 0X0000);
write_pixel(x_start+15,y_start+24, 0XFFFF);
write_pixel(x_start+15,y_start+25, 0XFFFF);
write_pixel(x_start+15,y_start+26, 0XFFFF);
write_pixel(x_start+15,y_start+27, 0X0000);


write_pixel(x_start+16,y_start+1, 0X0000);
write_pixel(x_start+16,y_start+2, 0XFFFF);
write_pixel(x_start+16,y_start+3, 0XFFFF);
write_pixel(x_start+16,y_start+4, 0XFFFF);
write_pixel(x_start+16,y_start+5, 0XFFFF);
write_pixel(x_start+16,y_start+6, 0XFFFF);
write_pixel(x_start+16,y_start+7,0X0000);
write_pixel(x_start+16,y_start+8, 0XFFFF);
write_pixel(x_start+16,y_start+9, 0X0000);
write_pixel(x_start+16,y_start+10, 0XFFFF);
write_pixel(x_start+16,y_start+11, 0XFFFF);
write_pixel(x_start+16,y_start+12, 0XFFFF);
write_pixel(x_start+16,y_start+13, 0XFFFF);
write_pixel(x_start+16,y_start+14, 0XFFFF);
write_pixel(x_start+16,y_start+15, 0XFFFF);
write_pixel(x_start+16,y_start+16, 0XFFFF);
write_pixel(x_start+16,y_start+17, 0XFFFF);
write_pixel(x_start+16,y_start+18, 0XFFFF);
write_pixel(x_start+16,y_start+19, 0XFFFF);
write_pixel(x_start+16,y_start+20, 0XFFFF);
write_pixel(x_start+16,y_start+21, 0XFFFF);
write_pixel(x_start+16,y_start+22, 0XFFFF);
write_pixel(x_start+16,y_start+23, 0X0000);
write_pixel(x_start+16,y_start+24, 0XFFFF);
write_pixel(x_start+16,y_start+25, 0XFFFF);
write_pixel(x_start+16,y_start+26, 0XFFFF);
write_pixel(x_start+16,y_start+27, 0X0000);


write_pixel(x_start+17,y_start+1, 0X0000);
write_pixel(x_start+17,y_start+2, 0XFFFF);
write_pixel(x_start+17,y_start+3, 0XFFFF);
write_pixel(x_start+17,y_start+4, 0XFFFF);
write_pixel(x_start+17,y_start+5, 0X0000);
write_pixel(x_start+17,y_start+6, 0X0000);
write_pixel(x_start+17,y_start+7, 0X0000);
write_pixel(x_start+17,y_start+8, 0XFFFF);
write_pixel(x_start+17,y_start+9, 0X0000);
write_pixel(x_start+17,y_start+10,0X0000 );
write_pixel(x_start+17,y_start+11, 0X0000);
write_pixel(x_start+17,y_start+12, 0X0000);
write_pixel(x_start+17,y_start+13, 0X0000);
write_pixel(x_start+17,y_start+14, 0XFFFF);
write_pixel(x_start+17,y_start+15, 0XFFFF);
write_pixel(x_start+17,y_start+16, 0XFFFF);
write_pixel(x_start+17,y_start+17, 0XFFFF);
write_pixel(x_start+17,y_start+18, 0XFFFF);
write_pixel(x_start+17,y_start+19, 0XFFFF);
write_pixel(x_start+17,y_start+20, 0XFFFF);
write_pixel(x_start+17,y_start+21, 0XFFFF);
write_pixel(x_start+17,y_start+22, 0XFFFF);
write_pixel(x_start+17,y_start+23, 0X0000);
write_pixel(x_start+17,y_start+24, 0XFFFF);
write_pixel(x_start+17,y_start+25, 0XFFFF);
write_pixel(x_start+17,y_start+26, 0XFFFF);
write_pixel(x_start+17,y_start+27, 0X0000);


write_pixel(x_start+18,y_start+1, 0X0000);
write_pixel(x_start+18,y_start+2, 0XFFFF);
write_pixel(x_start+18,y_start+3, 0XFFFF);
write_pixel(x_start+18,y_start+4, 0X0000);
write_pixel(x_start+18,y_start+7, 0X0000);
write_pixel(x_start+18,y_start+8, 0XFFFF);
write_pixel(x_start+18,y_start+9, 0X0000);
write_pixel(x_start+18,y_start+14, 0X0000);
write_pixel(x_start+18,y_start+15, 0X0000);
write_pixel(x_start+18,y_start+16, 0X0000);
write_pixel(x_start+18,y_start+17, 0X0000);
write_pixel(x_start+18,y_start+18, 0X0000);
write_pixel(x_start+18,y_start+19, 0X0000);
write_pixel(x_start+18,y_start+20, 0XFFFF);
write_pixel(x_start+18,y_start+21, 0XFFFF);
write_pixel(x_start+18,y_start+22, 0XFFFF);
write_pixel(x_start+18,y_start+23,0X0000 );
write_pixel(x_start+18,y_start+24, 0XFFFF);
write_pixel(x_start+18,y_start+25, 0XFFFF);
write_pixel(x_start+18,y_start+26, 0XFFFF);
write_pixel(x_start+18,y_start+27, 0X0000);

write_pixel(x_start+19,y_start+1, 0X0000);
write_pixel(x_start+19,y_start+2, 0X0000);
write_pixel(x_start+19,y_start+3, 0X0000);
write_pixel(x_start+19,y_start+4, 0X0000);
write_pixel(x_start+19,y_start+7, 0X0000);
write_pixel(x_start+19,y_start+8, 0X0000);
write_pixel(x_start+19,y_start+20, 0X0000);
write_pixel(x_start+19,y_start+21, 0X0000);
write_pixel(x_start+19,y_start+22, 0X0000);
write_pixel(x_start+19,y_start+23, 0X0000);
write_pixel(x_start+19,y_start+24, 0XFFFF);
write_pixel(x_start+19,y_start+25, 0XFFFF);
write_pixel(x_start+19,y_start+26, 0XFFFF);
write_pixel(x_start+19,y_start+27,0X0000 );

write_pixel(x_start+20,y_start+23, 0X0000);
write_pixel(x_start+20,y_start+24, 0XFFFF);
write_pixel(x_start+20,y_start+25, 0XFFFF);
write_pixel(x_start+20,y_start+26, 0XFFFF);
write_pixel(x_start+20,y_start+27, 0X0000);

write_pixel(x_start+21,y_start+23, 0X0000);
write_pixel(x_start+21,y_start+24, 0XFFFF);
write_pixel(x_start+21,y_start+25,0XFFFF );
write_pixel(x_start+21,y_start+26, 0XFFFF);
write_pixel(x_start+21,y_start+27, 0X0000);

write_pixel(x_start+22,y_start+24, 0X0000);
write_pixel(x_start+22,y_start+25, 0XFFFF);
write_pixel(x_start+22,y_start+26, 0XFFFF);
write_pixel(x_start+22,y_start+27, 0X0000);

write_pixel(x_start+23,y_start+25, 0X0000);
write_pixel(x_start+23,y_start+26, 0XFFFF);
write_pixel(x_start+23,y_start+27, 0X0000);


write_pixel(x_start+24,y_start+26, 0X0000);
write_pixel(x_start+24,y_start+27, 0X0000);


}

void draw_king_black(int y_start, int x_start){
int x,y;
x_start = 40 + (x_start*30) - 30;
y_start = (y_start*30)-30;


write_pixel(x_start+5,y_start+26, 0X0000);
write_pixel(x_start+5,y_start+27, 0X0000);

write_pixel(x_start+6,y_start+25, 0X0000);
write_pixel(x_start+6,y_start+26, 0X0000);
write_pixel(x_start+6,y_start+27, 0X0000);


write_pixel(x_start+7,y_start+24, 0X0000);
write_pixel(x_start+7,y_start+25, 0X0000);
write_pixel(x_start+7,y_start+26, 0X0000);
write_pixel(x_start+7,y_start+27, 0X0000);

write_pixel(x_start+8,y_start+23, 0X0000);
write_pixel(x_start+8,y_start+24, 0X0000);
write_pixel(x_start+8,y_start+25, 0X0000);
write_pixel(x_start+8,y_start+26, 0X0000);
write_pixel(x_start+8,y_start+27,0X0000 );

write_pixel(x_start+9,y_start+23, 0X0000);
write_pixel(x_start+9,y_start+24, 0X0000);
write_pixel(x_start+9,y_start+25, 0X0000);
write_pixel(x_start+9,y_start+26, 0X0000);
write_pixel(x_start+9,y_start+27, 0X0000);


write_pixel(x_start+10,y_start+7, 0X0000);
write_pixel(x_start+10,y_start+8, 0X0000);
write_pixel(x_start+10,y_start+20, 0X0000);
write_pixel(x_start+10,y_start+21, 0X0000);
write_pixel(x_start+10,y_start+22, 0X0000);
write_pixel(x_start+10,y_start+23, 0X0000);
write_pixel(x_start+10,y_start+24, 0X0000);
write_pixel(x_start+10,y_start+25, 0X0000);
write_pixel(x_start+10,y_start+26, 0X0000);
write_pixel(x_start+10,y_start+27, 0X0000);



write_pixel(x_start+11,y_start+7, 0X0000);
write_pixel(x_start+11,y_start+8, 0X0000);
write_pixel(x_start+11,y_start+9, 0X0000);
write_pixel(x_start+11,y_start+14, 0X0000);
write_pixel(x_start+11,y_start+15, 0X0000);
write_pixel(x_start+11,y_start+16, 0X0000);
write_pixel(x_start+11,y_start+17, 0X0000);
write_pixel(x_start+11,y_start+18, 0X0000);
write_pixel(x_start+11,y_start+19, 0X0000);
write_pixel(x_start+11,y_start+20,0X0000 );
write_pixel(x_start+11,y_start+21, 0X0000);
write_pixel(x_start+11,y_start+22, 0X0000);
write_pixel(x_start+11,y_start+23,0X0000);
write_pixel(x_start+11,y_start+24, 0X0000);
write_pixel(x_start+11,y_start+25, 0X0000);
write_pixel(x_start+11,y_start+26, 0X0000);
write_pixel(x_start+11,y_start+27, 0X0000);


write_pixel(x_start+12,y_start+1, 0X0000);
write_pixel(x_start+12,y_start+5, 0X0000);
write_pixel(x_start+12,y_start+6, 0X0000);
write_pixel(x_start+12,y_start+7, 0X0000);
write_pixel(x_start+12,y_start+8, 0X0000);
write_pixel(x_start+12,y_start+9, 0X0000);
write_pixel(x_start+12,y_start+10, 0X0000);
write_pixel(x_start+12,y_start+11, 0X0000);
write_pixel(x_start+12,y_start+12, 0X0000);
write_pixel(x_start+12,y_start+13, 0X0000);
write_pixel(x_start+12,y_start+14, 0X0000);
write_pixel(x_start+12,y_start+15, 0X0000);
write_pixel(x_start+12,y_start+16, 0X0000);
write_pixel(x_start+12,y_start+17, 0X0000);
write_pixel(x_start+12,y_start+18, 0X0000);
write_pixel(x_start+12,y_start+19, 0X0000);
write_pixel(x_start+12,y_start+20, 0X0000);
write_pixel(x_start+12,y_start+21, 0X0000);
write_pixel(x_start+12,y_start+22, 0X0000);
write_pixel(x_start+12,y_start+23, 0X0000);
write_pixel(x_start+12,y_start+24, 0X0000);
write_pixel(x_start+12,y_start+25, 0X0000);
write_pixel(x_start+12,y_start+26, 0X0000);
write_pixel(x_start+12,y_start+27, 0X0000);


write_pixel(x_start+13,y_start+1, 0X0000);
write_pixel(x_start+13,y_start+3, 0X0000);
write_pixel(x_start+13,y_start+4, 0X0000);
write_pixel(x_start+13,y_start+5, 0X0000);
write_pixel(x_start+13,y_start+6, 0X0000);
write_pixel(x_start+13,y_start+7, 0X0000);
write_pixel(x_start+13,y_start+8, 0X0000);
write_pixel(x_start+13,y_start+9, 0X0000);
write_pixel(x_start+13,y_start+10, 0X0000);
write_pixel(x_start+13,y_start+11, 0X0000);
write_pixel(x_start+13,y_start+12, 0X0000);
write_pixel(x_start+13,y_start+13, 0X0000);
write_pixel(x_start+13,y_start+14, 0X0000);
write_pixel(x_start+13,y_start+15, 0X0000);
write_pixel(x_start+13,y_start+16, 0X0000);
write_pixel(x_start+13,y_start+17, 0X0000);
write_pixel(x_start+13,y_start+18, 0X0000);
write_pixel(x_start+13,y_start+19, 0X0000);
write_pixel(x_start+13,y_start+20, 0X0000);
write_pixel(x_start+13,y_start+21, 0X0000);
write_pixel(x_start+13,y_start+22, 0X0000);
write_pixel(x_start+13,y_start+23, 0X0000);
write_pixel(x_start+13,y_start+24, 0X0000);
write_pixel(x_start+13,y_start+25, 0X0000);
write_pixel(x_start+13,y_start+26, 0X0000);
write_pixel(x_start+13,y_start+27, 0X0000);

write_pixel(x_start+14,y_start+0,0X0000 );
write_pixel(x_start+14,y_start+1, 0X0000);
write_pixel(x_start+14,y_start+2, 0X0000);
write_pixel(x_start+14,y_start+3, 0X0000);
write_pixel(x_start+14,y_start+4, 0X0000);
write_pixel(x_start+14,y_start+5, 0X0000);
write_pixel(x_start+14,y_start+6, 0X0000);
write_pixel(x_start+14,y_start+7, 0X0000);
write_pixel(x_start+14,y_start+8, 0X0000);
write_pixel(x_start+14,y_start+9, 0X0000);
write_pixel(x_start+14,y_start+10, 0X0000);
write_pixel(x_start+14,y_start+11, 0X0000);
write_pixel(x_start+14,y_start+12, 0X0000);
write_pixel(x_start+14,y_start+13, 0X0000);
write_pixel(x_start+14,y_start+14, 0X0000);
write_pixel(x_start+14,y_start+15, 0X0000);
write_pixel(x_start+14,y_start+16, 0X0000);
write_pixel(x_start+14,y_start+17, 0X0000);
write_pixel(x_start+14,y_start+18, 0X0000);
write_pixel(x_start+14,y_start+19, 0X0000);
write_pixel(x_start+14,y_start+20, 0X0000);
write_pixel(x_start+14,y_start+21, 0X0000);
write_pixel(x_start+14,y_start+22, 0X0000);
write_pixel(x_start+14,y_start+23, 0X0000);
write_pixel(x_start+14,y_start+24, 0X0000);
write_pixel(x_start+14,y_start+25, 0X0000);
write_pixel(x_start+14,y_start+26, 0X0000);
write_pixel(x_start+14,y_start+27, 0X0000);

write_pixel(x_start+15,y_start+0,0X0000 );
write_pixel(x_start+15,y_start+1, 0X0000);
write_pixel(x_start+15,y_start+2, 0X0000);
write_pixel(x_start+15,y_start+3, 0X0000);
write_pixel(x_start+15,y_start+4, 0X0000);
write_pixel(x_start+15,y_start+5, 0X0000);
write_pixel(x_start+15,y_start+6, 0X0000);
write_pixel(x_start+15,y_start+7, 0X0000);
write_pixel(x_start+15,y_start+8, 0X0000);
write_pixel(x_start+15,y_start+9, 0X0000);
write_pixel(x_start+15,y_start+10, 0X0000);
write_pixel(x_start+15,y_start+11, 0X0000);
write_pixel(x_start+15,y_start+12, 0X0000);
write_pixel(x_start+15,y_start+13, 0X0000);
write_pixel(x_start+15,y_start+14, 0X0000);
write_pixel(x_start+15,y_start+15, 0X0000);
write_pixel(x_start+15,y_start+16, 0X0000);
write_pixel(x_start+15,y_start+17, 0X0000);
write_pixel(x_start+15,y_start+18, 0X0000);
write_pixel(x_start+15,y_start+19, 0X0000);
write_pixel(x_start+15,y_start+20, 0X0000);
write_pixel(x_start+15,y_start+21, 0X0000);
write_pixel(x_start+15,y_start+22, 0X0000);
write_pixel(x_start+15,y_start+23, 0X0000);
write_pixel(x_start+15,y_start+24, 0X0000);
write_pixel(x_start+15,y_start+25, 0X0000);
write_pixel(x_start+15,y_start+26, 0X0000);
write_pixel(x_start+15,y_start+27, 0X0000);


write_pixel(x_start+16,y_start+1, 0X0000);
write_pixel(x_start+16,y_start+3, 0X0000);
write_pixel(x_start+16,y_start+4, 0X0000);
write_pixel(x_start+16,y_start+5, 0X0000);
write_pixel(x_start+16,y_start+6, 0X0000);
write_pixel(x_start+16,y_start+7,0X0000);
write_pixel(x_start+16,y_start+8, 0X0000);
write_pixel(x_start+16,y_start+9, 0X0000);
write_pixel(x_start+16,y_start+10, 0X0000);
write_pixel(x_start+16,y_start+11, 0X0000);
write_pixel(x_start+16,y_start+12, 0X0000);
write_pixel(x_start+16,y_start+13, 0X0000);
write_pixel(x_start+16,y_start+14, 0X0000);
write_pixel(x_start+16,y_start+15, 0X0000);
write_pixel(x_start+16,y_start+16, 0X0000);
write_pixel(x_start+16,y_start+17, 0X0000);
write_pixel(x_start+16,y_start+18, 0X0000);
write_pixel(x_start+16,y_start+19, 0X0000);
write_pixel(x_start+16,y_start+20, 0X0000);
write_pixel(x_start+16,y_start+21, 0X0000);
write_pixel(x_start+16,y_start+22, 0X0000);
write_pixel(x_start+16,y_start+23, 0X0000);
write_pixel(x_start+16,y_start+24, 0X0000);
write_pixel(x_start+16,y_start+25, 0X0000);
write_pixel(x_start+16,y_start+26, 0X0000);
write_pixel(x_start+16,y_start+27, 0X0000);


write_pixel(x_start+17,y_start+1, 0X0000);
write_pixel(x_start+17,y_start+5, 0X0000);
write_pixel(x_start+17,y_start+6, 0X0000);
write_pixel(x_start+17,y_start+7, 0X0000);
write_pixel(x_start+17,y_start+8, 0X0000);
write_pixel(x_start+17,y_start+9, 0X0000);
write_pixel(x_start+17,y_start+10,0X0000 );
write_pixel(x_start+17,y_start+11, 0X0000);
write_pixel(x_start+17,y_start+12, 0X0000);
write_pixel(x_start+17,y_start+13, 0X0000);
write_pixel(x_start+17,y_start+14, 0X0000);
write_pixel(x_start+17,y_start+15, 0X0000);
write_pixel(x_start+17,y_start+16, 0X0000);
write_pixel(x_start+17,y_start+17, 0X0000);
write_pixel(x_start+17,y_start+18, 0X0000);
write_pixel(x_start+17,y_start+19, 0X0000);
write_pixel(x_start+17,y_start+20, 0X0000);
write_pixel(x_start+17,y_start+21, 0X0000);
write_pixel(x_start+17,y_start+22, 0X0000);
write_pixel(x_start+17,y_start+23, 0X0000);
write_pixel(x_start+17,y_start+24, 0X0000);
write_pixel(x_start+17,y_start+25, 0X0000);
write_pixel(x_start+17,y_start+26, 0X0000);
write_pixel(x_start+17,y_start+27, 0X0000);


write_pixel(x_start+18,y_start+7, 0X0000);
write_pixel(x_start+18,y_start+8, 0X0000);
write_pixel(x_start+18,y_start+9, 0X0000);
write_pixel(x_start+18,y_start+14, 0X0000);
write_pixel(x_start+18,y_start+15, 0X0000);
write_pixel(x_start+18,y_start+16, 0X0000);
write_pixel(x_start+18,y_start+17, 0X0000);
write_pixel(x_start+18,y_start+18, 0X0000);
write_pixel(x_start+18,y_start+19, 0X0000);
write_pixel(x_start+18,y_start+20, 0X0000);
write_pixel(x_start+18,y_start+21, 0X0000);
write_pixel(x_start+18,y_start+22, 0X0000);
write_pixel(x_start+18,y_start+23,0X0000 );
write_pixel(x_start+18,y_start+24, 0X0000);
write_pixel(x_start+18,y_start+25, 0X0000);
write_pixel(x_start+18,y_start+26, 0X0000);
write_pixel(x_start+18,y_start+27, 0X0000);


write_pixel(x_start+19,y_start+7, 0X0000);
write_pixel(x_start+19,y_start+8, 0X0000);
write_pixel(x_start+19,y_start+20, 0X0000);
write_pixel(x_start+19,y_start+21, 0X0000);
write_pixel(x_start+19,y_start+22, 0X0000);
write_pixel(x_start+19,y_start+23, 0X0000);
write_pixel(x_start+19,y_start+24, 0X0000);
write_pixel(x_start+19,y_start+25, 0X0000);
write_pixel(x_start+19,y_start+26, 0X0000);
write_pixel(x_start+19,y_start+27,0X0000 );

write_pixel(x_start+20,y_start+23, 0X0000);
write_pixel(x_start+20,y_start+24, 0X0000);
write_pixel(x_start+20,y_start+25, 0X0000);
write_pixel(x_start+20,y_start+26, 0X0000);
write_pixel(x_start+20,y_start+27, 0X0000);

write_pixel(x_start+21,y_start+23, 0X0000);
write_pixel(x_start+21,y_start+24, 0X0000);
write_pixel(x_start+21,y_start+25,0X0000 );
write_pixel(x_start+21,y_start+26, 0X0000);
write_pixel(x_start+21,y_start+27, 0X0000);

write_pixel(x_start+22,y_start+24, 0X0000);
write_pixel(x_start+22,y_start+25, 0X0000);
write_pixel(x_start+22,y_start+26, 0X0000);
write_pixel(x_start+22,y_start+27, 0X0000);

write_pixel(x_start+23,y_start+25, 0X0000);
write_pixel(x_start+23,y_start+26, 0X0000);
write_pixel(x_start+23,y_start+27, 0X0000);


write_pixel(x_start+24,y_start+26, 0X0000);
write_pixel(x_start+24,y_start+27, 0X0000);


}


void draw_king_white(int y_start, int x_start){
int x,y;
x_start = 40 + (x_start*30) - 30;
y_start = (y_start*30)-30;


write_pixel(x_start+5,y_start+26, 0X0000);
write_pixel(x_start+5,y_start+27, 0X0000);

write_pixel(x_start+6,y_start+25, 0X0000);
write_pixel(x_start+6,y_start+26, 0XFFFF);
write_pixel(x_start+6,y_start+27, 0X0000);


write_pixel(x_start+7,y_start+24, 0X0000);
write_pixel(x_start+7,y_start+25, 0XFFFF);
write_pixel(x_start+7,y_start+26, 0XFFFF);
write_pixel(x_start+7,y_start+27, 0X0000);

write_pixel(x_start+8,y_start+23, 0X0000);
write_pixel(x_start+8,y_start+24, 0XFFFF);
write_pixel(x_start+8,y_start+25, 0XFFFF);
write_pixel(x_start+8,y_start+26, 0XFFFF);
write_pixel(x_start+8,y_start+27,0X0000 );

write_pixel(x_start+9,y_start+23, 0X0000);
write_pixel(x_start+9,y_start+24, 0XFFFF);
write_pixel(x_start+9,y_start+25, 0XFFFF);
write_pixel(x_start+9,y_start+26, 0XFFFF);
write_pixel(x_start+9,y_start+27, 0X0000);


write_pixel(x_start+10,y_start+7, 0X0000);
write_pixel(x_start+10,y_start+8, 0X0000);
write_pixel(x_start+10,y_start+20, 0X0000);
write_pixel(x_start+10,y_start+21, 0X0000);
write_pixel(x_start+10,y_start+22, 0X0000);
write_pixel(x_start+10,y_start+23, 0X0000);
write_pixel(x_start+10,y_start+24, 0XFFFF);
write_pixel(x_start+10,y_start+25, 0XFFFF);
write_pixel(x_start+10,y_start+26, 0XFFFF);
write_pixel(x_start+10,y_start+27, 0X0000);



write_pixel(x_start+11,y_start+7, 0X0000);
write_pixel(x_start+11,y_start+8, 0XFFFF);
write_pixel(x_start+11,y_start+9, 0X0000);
write_pixel(x_start+11,y_start+14, 0X0000);
write_pixel(x_start+11,y_start+15, 0X0000);
write_pixel(x_start+11,y_start+16, 0X0000);
write_pixel(x_start+11,y_start+17, 0X0000);
write_pixel(x_start+11,y_start+18, 0X0000);
write_pixel(x_start+11,y_start+19, 0X0000);
write_pixel(x_start+11,y_start+20,0XFFFF );
write_pixel(x_start+11,y_start+21, 0XFFFF);
write_pixel(x_start+11,y_start+22, 0XFFFF);
write_pixel(x_start+11,y_start+23,0X0000);
write_pixel(x_start+11,y_start+24, 0XFFFF);
write_pixel(x_start+11,y_start+25, 0XFFFF);
write_pixel(x_start+11,y_start+26, 0XFFFF);
write_pixel(x_start+11,y_start+27, 0X0000);


write_pixel(x_start+12,y_start+1, 0X0000);
write_pixel(x_start+12,y_start+5, 0X0000);
write_pixel(x_start+12,y_start+6, 0X0000);
write_pixel(x_start+12,y_start+7, 0X0000);
write_pixel(x_start+12,y_start+8, 0XFFFF);
write_pixel(x_start+12,y_start+9, 0X0000);
write_pixel(x_start+12,y_start+10, 0X0000);
write_pixel(x_start+12,y_start+11, 0X0000);
write_pixel(x_start+12,y_start+12, 0X0000);
write_pixel(x_start+12,y_start+13, 0X0000);
write_pixel(x_start+12,y_start+14, 0XFFFF);
write_pixel(x_start+12,y_start+15, 0XFFFF);
write_pixel(x_start+12,y_start+16, 0XFFFF);
write_pixel(x_start+12,y_start+17, 0XFFFF);
write_pixel(x_start+12,y_start+18, 0XFFFF);
write_pixel(x_start+12,y_start+19, 0XFFFF);
write_pixel(x_start+12,y_start+20, 0XFFFF);
write_pixel(x_start+12,y_start+21, 0XFFFF);
write_pixel(x_start+12,y_start+22, 0XFFFF);
write_pixel(x_start+12,y_start+23, 0X0000);
write_pixel(x_start+12,y_start+24, 0XFFFF);
write_pixel(x_start+12,y_start+25, 0XFFFF);
write_pixel(x_start+12,y_start+26, 0XFFFF);
write_pixel(x_start+12,y_start+27, 0X0000);


write_pixel(x_start+13,y_start+1, 0X0000);
write_pixel(x_start+13,y_start+3, 0X0000);
write_pixel(x_start+13,y_start+4, 0X0000);
write_pixel(x_start+13,y_start+5, 0XFFFF);
write_pixel(x_start+13,y_start+6, 0XFFFF);
write_pixel(x_start+13,y_start+7, 0X0000);
write_pixel(x_start+13,y_start+8, 0XFFFF);
write_pixel(x_start+13,y_start+9, 0X0000);
write_pixel(x_start+13,y_start+10, 0XFFFF);
write_pixel(x_start+13,y_start+11, 0XFFFF);
write_pixel(x_start+13,y_start+12, 0XFFFF);
write_pixel(x_start+13,y_start+13, 0XFFFF);
write_pixel(x_start+13,y_start+14, 0XFFFF);
write_pixel(x_start+13,y_start+15, 0XFFFF);
write_pixel(x_start+13,y_start+16, 0XFFFF);
write_pixel(x_start+13,y_start+17, 0XFFFF);
write_pixel(x_start+13,y_start+18, 0XFFFF);
write_pixel(x_start+13,y_start+19, 0XFFFF);
write_pixel(x_start+13,y_start+20, 0XFFFF);
write_pixel(x_start+13,y_start+21, 0XFFFF);
write_pixel(x_start+13,y_start+22, 0XFFFF);
write_pixel(x_start+13,y_start+23, 0X0000);
write_pixel(x_start+13,y_start+24, 0XFFFF);
write_pixel(x_start+13,y_start+25, 0XFFFF);
write_pixel(x_start+13,y_start+26, 0XFFFF);
write_pixel(x_start+13,y_start+27, 0X0000);

write_pixel(x_start+14,y_start+0,0X0000 );
write_pixel(x_start+14,y_start+1, 0X0000);
write_pixel(x_start+14,y_start+2, 0X0000);
write_pixel(x_start+14,y_start+3, 0X0000);
write_pixel(x_start+14,y_start+4, 0XFFFF);
write_pixel(x_start+14,y_start+5, 0XFFFF);
write_pixel(x_start+14,y_start+6, 0XFFFF);
write_pixel(x_start+14,y_start+7, 0X0000);
write_pixel(x_start+14,y_start+8, 0XFFFF);
write_pixel(x_start+14,y_start+9, 0X0000);
write_pixel(x_start+14,y_start+10, 0XFFFF);
write_pixel(x_start+14,y_start+11, 0XFFFF);
write_pixel(x_start+14,y_start+12, 0XFFFF);
write_pixel(x_start+14,y_start+13, 0XFFFF);
write_pixel(x_start+14,y_start+14, 0XFFFF);
write_pixel(x_start+14,y_start+15, 0XFFFF);
write_pixel(x_start+14,y_start+16, 0XFFFF);
write_pixel(x_start+14,y_start+17, 0XFFFF);
write_pixel(x_start+14,y_start+18, 0XFFFF);
write_pixel(x_start+14,y_start+19, 0XFFFF);
write_pixel(x_start+14,y_start+20, 0XFFFF);
write_pixel(x_start+14,y_start+21, 0XFFFF);
write_pixel(x_start+14,y_start+22, 0XFFFF);
write_pixel(x_start+14,y_start+23, 0X0000);
write_pixel(x_start+14,y_start+24, 0XFFFF);
write_pixel(x_start+14,y_start+25, 0XFFFF);
write_pixel(x_start+14,y_start+26, 0XFFFF);
write_pixel(x_start+14,y_start+27, 0X0000);

write_pixel(x_start+15,y_start+0,0X0000 );
write_pixel(x_start+15,y_start+1, 0X0000);
write_pixel(x_start+15,y_start+2, 0X0000);
write_pixel(x_start+15,y_start+3, 0X0000);
write_pixel(x_start+15,y_start+4, 0XFFFF);
write_pixel(x_start+15,y_start+5, 0XFFFF);
write_pixel(x_start+15,y_start+6, 0XFFFF);
write_pixel(x_start+15,y_start+7, 0X0000);
write_pixel(x_start+15,y_start+8, 0XFFFF);
write_pixel(x_start+15,y_start+9, 0X0000);
write_pixel(x_start+15,y_start+10, 0XFFFF);
write_pixel(x_start+15,y_start+11, 0XFFFF);
write_pixel(x_start+15,y_start+12, 0XFFFF);
write_pixel(x_start+15,y_start+13, 0XFFFF);
write_pixel(x_start+15,y_start+14, 0XFFFF);
write_pixel(x_start+15,y_start+15, 0XFFFF);
write_pixel(x_start+15,y_start+16, 0XFFFF);
write_pixel(x_start+15,y_start+17, 0XFFFF);
write_pixel(x_start+15,y_start+18, 0XFFFF);
write_pixel(x_start+15,y_start+19, 0XFFFF);
write_pixel(x_start+15,y_start+20, 0XFFFF);
write_pixel(x_start+15,y_start+21, 0XFFFF);
write_pixel(x_start+15,y_start+22, 0XFFFF);
write_pixel(x_start+15,y_start+23, 0X0000);
write_pixel(x_start+15,y_start+24, 0XFFFF);
write_pixel(x_start+15,y_start+25, 0XFFFF);
write_pixel(x_start+15,y_start+26, 0XFFFF);
write_pixel(x_start+15,y_start+27, 0X0000);


write_pixel(x_start+16,y_start+1, 0X0000);
write_pixel(x_start+16,y_start+3, 0X0000);
write_pixel(x_start+16,y_start+4, 0X0000);
write_pixel(x_start+16,y_start+5, 0XFFFF);
write_pixel(x_start+16,y_start+6, 0XFFFF);
write_pixel(x_start+16,y_start+7,0X0000);
write_pixel(x_start+16,y_start+8, 0XFFFF);
write_pixel(x_start+16,y_start+9, 0X0000);
write_pixel(x_start+16,y_start+10, 0XFFFF);
write_pixel(x_start+16,y_start+11, 0XFFFF);
write_pixel(x_start+16,y_start+12, 0XFFFF);
write_pixel(x_start+16,y_start+13, 0XFFFF);
write_pixel(x_start+16,y_start+14, 0XFFFF);
write_pixel(x_start+16,y_start+15, 0XFFFF);
write_pixel(x_start+16,y_start+16, 0XFFFF);
write_pixel(x_start+16,y_start+17, 0XFFFF);
write_pixel(x_start+16,y_start+18, 0XFFFF);
write_pixel(x_start+16,y_start+19, 0XFFFF);
write_pixel(x_start+16,y_start+20, 0XFFFF);
write_pixel(x_start+16,y_start+21, 0XFFFF);
write_pixel(x_start+16,y_start+22, 0XFFFF);
write_pixel(x_start+16,y_start+23, 0X0000);
write_pixel(x_start+16,y_start+24, 0XFFFF);
write_pixel(x_start+16,y_start+25, 0XFFFF);
write_pixel(x_start+16,y_start+26, 0XFFFF);
write_pixel(x_start+16,y_start+27, 0X0000);


write_pixel(x_start+17,y_start+1, 0X0000);
write_pixel(x_start+17,y_start+5, 0X0000);
write_pixel(x_start+17,y_start+6, 0X0000);
write_pixel(x_start+17,y_start+7, 0X0000);
write_pixel(x_start+17,y_start+8, 0XFFFF);
write_pixel(x_start+17,y_start+9, 0X0000);
write_pixel(x_start+17,y_start+10,0X0000 );
write_pixel(x_start+17,y_start+11, 0X0000);
write_pixel(x_start+17,y_start+12, 0X0000);
write_pixel(x_start+17,y_start+13, 0X0000);
write_pixel(x_start+17,y_start+14, 0XFFFF);
write_pixel(x_start+17,y_start+15, 0XFFFF);
write_pixel(x_start+17,y_start+16, 0XFFFF);
write_pixel(x_start+17,y_start+17, 0XFFFF);
write_pixel(x_start+17,y_start+18, 0XFFFF);
write_pixel(x_start+17,y_start+19, 0XFFFF);
write_pixel(x_start+17,y_start+20, 0XFFFF);
write_pixel(x_start+17,y_start+21, 0XFFFF);
write_pixel(x_start+17,y_start+22, 0XFFFF);
write_pixel(x_start+17,y_start+23, 0X0000);
write_pixel(x_start+17,y_start+24, 0XFFFF);
write_pixel(x_start+17,y_start+25, 0XFFFF);
write_pixel(x_start+17,y_start+26, 0XFFFF);
write_pixel(x_start+17,y_start+27, 0X0000);



write_pixel(x_start+18,y_start+7, 0X0000);
write_pixel(x_start+18,y_start+8, 0XFFFF);
write_pixel(x_start+18,y_start+9, 0X0000);
write_pixel(x_start+18,y_start+14, 0X0000);
write_pixel(x_start+18,y_start+15, 0X0000);
write_pixel(x_start+18,y_start+16, 0X0000);
write_pixel(x_start+18,y_start+17, 0X0000);
write_pixel(x_start+18,y_start+18, 0X0000);
write_pixel(x_start+18,y_start+19, 0X0000);
write_pixel(x_start+18,y_start+20, 0XFFFF);
write_pixel(x_start+18,y_start+21, 0XFFFF);
write_pixel(x_start+18,y_start+22, 0XFFFF);
write_pixel(x_start+18,y_start+23,0X0000 );
write_pixel(x_start+18,y_start+24, 0XFFFF);
write_pixel(x_start+18,y_start+25, 0XFFFF);
write_pixel(x_start+18,y_start+26, 0XFFFF);
write_pixel(x_start+18,y_start+27, 0X0000);


write_pixel(x_start+19,y_start+7, 0X0000);
write_pixel(x_start+19,y_start+8, 0X0000);
write_pixel(x_start+19,y_start+20, 0X0000);
write_pixel(x_start+19,y_start+21, 0X0000);
write_pixel(x_start+19,y_start+22, 0X0000);
write_pixel(x_start+19,y_start+23, 0X0000);
write_pixel(x_start+19,y_start+24, 0XFFFF);
write_pixel(x_start+19,y_start+25, 0XFFFF);
write_pixel(x_start+19,y_start+26, 0XFFFF);
write_pixel(x_start+19,y_start+27,0X0000 );

write_pixel(x_start+20,y_start+23, 0X0000);
write_pixel(x_start+20,y_start+24, 0XFFFF);
write_pixel(x_start+20,y_start+25, 0XFFFF);
write_pixel(x_start+20,y_start+26, 0XFFFF);
write_pixel(x_start+20,y_start+27, 0X0000);

write_pixel(x_start+21,y_start+23, 0X0000);
write_pixel(x_start+21,y_start+24, 0XFFFF);
write_pixel(x_start+21,y_start+25,0XFFFF );
write_pixel(x_start+21,y_start+26, 0XFFFF);
write_pixel(x_start+21,y_start+27, 0X0000);

write_pixel(x_start+22,y_start+24, 0X0000);
write_pixel(x_start+22,y_start+25, 0XFFFF);
write_pixel(x_start+22,y_start+26, 0XFFFF);
write_pixel(x_start+22,y_start+27, 0X0000);

write_pixel(x_start+23,y_start+25, 0X0000);
write_pixel(x_start+23,y_start+26, 0XFFFF);
write_pixel(x_start+23,y_start+27, 0X0000);


write_pixel(x_start+24,y_start+26, 0X0000);
write_pixel(x_start+24,y_start+27, 0X0000);


}

void eligibleMove(int y_start, int x_start){
int x,y,j,k;
x_start = 40 + (x_start*30) - 30;
y_start = (y_start*30)-30;

for(x=x_start;x<(x_start+30);x++){
	write_pixel(x,y_start,0x07E0);
}

for(j=x_start;j<(x_start+30);j++){
	write_pixel(j,(y_start+29),0x07E0);
}

for(y=y_start;y<(y_start+30);y++){
	write_pixel(x_start,y,0x07E0);
}

for(k=y_start;k<(y_start+30);k++){
	write_pixel((x_start+29),k,0x07E0);
}


}


void arrow_input(int y_start, int x_start){
int x,y;
x_start = 40 + (x_start*30) - 30;
y_start = (y_start*30)-30;

for(x=x_start;x<(x_start+31);x++){
	write_pixel(x,y_start,0xF800);
}

for(x=x_start;x<(x_start+31);x++){
	write_pixel(x,(y_start+30),0xF800);
}

for(y=y_start;y<(y_start+31);y++){
	write_pixel(x_start,y,0xF800);
}

for(y=y_start;y<(y_start+31);y++){
	write_pixel((x_start+30),y,0xF800);
}


}


void checkmate_screen(){

char* hw = "Checkmate!";	
int x = 15;
   while (*hw) {
     write_char(x, 10, *hw);
	 x++;
	 hw++;
   }
  
}	

int draw_chessboard() {

clear_char_buffer();
   clear_screen();
   int x, y;
   
   draw_row_of_squares_odd(0);
draw_row_of_squares_even(30);
draw_row_of_squares_odd(60);
draw_row_of_squares_even(90);
draw_row_of_squares_odd(120);
draw_row_of_squares_even(150);
draw_row_of_squares_odd(180);
draw_row_of_squares_even(210);
draw_row_of_squares_odd(240);





   return 0;
}


