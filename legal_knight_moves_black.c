typedef int bool;
#define true 1
#define false 0
void legal_knight_moves_black(int x, int y, int* pawnWhite, int* pawnBlack, int* rookWhite, int* rookBlack, int* knightWhite, int*knightBlack, int*bishopWhite, int* bishopBlack, int* queenWhite, int* queenBlack, int* kingWhite, int* kingBlack, int* array_legal){
	int compx, compy;
	int tempX;
	int tempY;
	bool isLegal1 = true;
	bool isLegal2 = true;
	bool isLegal3 = true;
	bool isLegal4 = true;
	bool isLegal5 = true;
	bool isLegal6 = true;
	bool isLegal7 = true;
	bool isLegal8 = true;
	
	tempX = x+1;
	tempY = y-2;
	
	int i=0;
	
	while(i<8){
		compx=pawnBlack[i]&0xF0;
		compy=pawnBlack[i]&0xF;
		 compx=compx>>4;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			isLegal1=false;
		}
		i++;
	}
	i = 0;
	
	while(i < 2){
		compx=rookBlack[i]&0xF0;
		compy=rookBlack[i]&0xF;
		 compx=compx>>4;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			isLegal1=false;
		}
		i++;
			}
	i = 0;
	
	
	while(i < 2){
		compx=bishopBlack[i]&0xF0;
		compy=bishopBlack[i]&0xF;
		 compx=compx>>4;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX<8||tempY<8){
			isLegal1=false;
		}
	
i++;
	}
	i = 0;
	
	while(i < 2){
		compx=kingBlack[i]&0xF0;
		compy=kingBlack[i]&0xF;
		 compx=compx>>4;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			isLegal1=false;
		}
	i++;
	}
	i = 0;
	
	compx=kingBlack[0]&0xF0;
compy=kingBlack[0]&0xF;
		 compx=compx>>4;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal1=false;
}

compx=queenBlack[0]&0xF0;
compy=queenBlack[0]&0xF;
		 compx=compx>>4;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal1=false;
}
	
	
	tempX = x+2;
	tempY = y-1;
	
	i=0;
	while(i<8){
		compx=pawnBlack[i]&0xF0;
		compy=pawnBlack[i]&0xF;
		 compx=compx>>4;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			isLegal2=false;
		}
	i++;
	}
	i = 0;
	
	while(i < 2){
		compx=rookBlack[i]&0xF0;
		compy=rookBlack[i]&0xF;
		 compx=compx>>4;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			isLegal2=false;
		}
	i++;
	}
	i = 0;
	
	
	while(i < 2){
		compx=bishopBlack[i]&0xF0;
		compy=bishopBlack[i]&0xF;
		 compx=compx>>4;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			isLegal2=false;
		}
	i++;
	}
	i = 0;
	
	while(i < 2){
		compx=knightBlack[i]&0xF0;
		compy=knightBlack[i]&0xF;
		 compx=compx>>4;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			isLegal2=false;
		}
i++;
	}
	i = 0;
	
compx=kingBlack[0]&0xF0;
compy=kingBlack[0]&0xF;
		 compx=compx>>4;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal2=false;
}	

compx=queenBlack[0]&0xF0;
compy=queenBlack[0]&0xF;
		 compx=compx>>4;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal2=false;
}
	

	
	
	tempX = x+2;
	tempY = y+1;

	i=0;
	while(i<8){
		compx=pawnBlack[i]&0xF0;
		compy=pawnBlack[i]&0xF;
		 compx=compx>>4;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			isLegal3=false;
		}
	i++;
	}
	i = 0;
	
	while(i < 2){
		compx=rookBlack[i]&0xF0;
		compy=rookBlack[i]&0xF;
		 compx=compx>>4;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			isLegal3=false;
		}
i++;
	}
	i = 0;
	
	
	while(i < 2){
		compx=bishopBlack[i]&0xF0;
		compy=bishopBlack[i]&0xF;
		 compx=compx>>4;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			isLegal3=false;
		}
i++;
	}
	i = 0;
	
	while(i < 2){
		compx=knightBlack[i]&0xF0;
		compy=knightBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			
			isLegal3=false;
		}
i++;
	}
	i = 0;
	
compx=kingBlack[0]&0xF0;
compy=kingBlack[0]&0xF;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal3=false;
}	
compx=queenBlack[0]&0xF0;
compy=queenBlack[0]&0xF;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal3=false;
}
	

	
	
	
	tempX = x+1;
	tempY = y+2;
	
	i=0;
	while(i<8){

		compx=pawnBlack[i]&0xF0;
		compy=pawnBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			isLegal4=false;
		}
		i++;
	}
	i = 0;
	
	while(i < 2){
		compx=rookBlack[i]&0xF0;
		compy=rookBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			isLegal4=false;
		}
i++;
	}
	i = 0;
	
	
	while(i < 2){
		compx=bishopBlack[i]&0xF0;
		compy=bishopBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			
			isLegal4=false;
		}
i++;
	}
	i = 0;
	
	while(i < 2){

		compx=knightBlack[i]&0xF0;
		compy=knightBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			
			isLegal4=false;
		}
i++;
	}
	i = 0;
	
	compx=kingBlack[0]&0xF0;
compy=kingBlack[0]&0xF;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal4=false;
}

compx=queenBlack[0]&0xF0;
compy=queenBlack[0]&0xF;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal4=false;
}
	
	
	
	tempX = x-1;
	tempY = y+2;
	
	i=0;
	while(i<8){
		compx=pawnBlack[i]&0xF0;
		compy=pawnBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			
			isLegal5=false;
		}
		i++;
	}
	i = 0;
	
	while(i < 2){
		compx=rookBlack[i]&0xF0;
		compy=rookBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			
			isLegal5=false;
		}
i++;
	}
	i = 0;
	
	
	while(i < 2){

		compx=bishopBlack[i]&0xF0;
		compy=bishopBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
		
			isLegal5=false;
		}
i++;
	}
	i = 0;
	
	while(i < 2){
		compx=knightBlack[i]&0xF0;
		compy=knightBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			
			isLegal5=false;
		}
i++;
	}
	i = 0;
	
	compx=kingBlack[0]&0xF0;
compy=kingBlack[0]&0xF;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal5=false;
}
compx=queenBlack[0]&0xF0;
compy=queenBlack[0]&0xF;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal5=false;
}
	
	
	tempX = x-2;
	tempY = y+1;
	
	i=0;
	while(i<8){

		compx=pawnBlack[i]&0xF0;
		compy=pawnBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			
			isLegal6=false;
		}
		i++;
	}
	i = 0;
	
	while(i < 2){

		compx=rookBlack[i]&0xF0;
		compy=rookBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
		
			isLegal6=false;
		}
i++;
	}
	i = 0;
	
	
	while(i < 2){

		compx=bishopBlack[i]&0xF0;
		compy=bishopBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			
			isLegal6=false;
		}
i++;
	}
	i = 0;
	
	while(i < 2){

		compx=knightBlack[i]&0xF0;
		compy=knightBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			isLegal6=false;
		}
i++;
	}
	i = 0;
	
	compx=kingBlack[0]&0xF0;
compy=kingBlack[0]&0xF;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal6=false;
}
compx=queenBlack[0]&0xF0;
compy=queenBlack[0]&0xF;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal6=false;
}
	
	tempX = x-2;
	tempY = y-1;
	
	i=0;
	while(i<8){
		compx=pawnBlack[i]&0xF0;
		compy=pawnBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			isLegal7=false;
		}
		i++;
	}
	i = 0;
	
	while(i < 2){
		compx=rookBlack[i]&0xF0;
		compy=rookBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			
			isLegal7=false;
		}
i++;
	}
	i = 0;
	
	
	while(i < 2){

		compx=bishopBlack[i]&0xF0;
		compy=bishopBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			
			isLegal7=false;
		}
i++;
	}
	i = 0;
	
	while(i < 2){

		compx=knightBlack[i]&0xF0;
		compy=knightBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			
			isLegal7=false;
		}
i++;
	}
	i = 0;
	
compx=kingBlack[0]&0xF0;
compy=kingBlack[0]&0xF;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal7=false;
}
compx=queenBlack[0]&0xF0;
compy=queenBlack[0]&0xF;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal7=false;
}

	
	tempX = x-1;
	tempY = y-2;
	
	i=0;
	while(i<8){

		compx=pawnBlack[i]&0xF0;
		compy=pawnBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			
			isLegal8=false;
		}
		i++;
	}
	i = 0;
	
	while(i < 2){
		
		compx=rookBlack[i]&0xF0;
		compy=rookBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			
			isLegal8=false;
		}
i++;
	}
	i = 0;
	
	
	while(i < 2){

		compx=bishopBlack[i]&0xF0;
		compy=bishopBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			
			isLegal8=false;
		}
i++;
	}
	i = 0;
	
	while(i < 2){
		compx=knightBlack[i]&0xF0;
		compy=knightBlack[i]&0xF;
		 compx=compx>>4;
		if(tempX==compx&&tempY==compy||tempX>8||tempY>8){
			
			isLegal8=false;
		}
i++;
	}
	i = 0;
	
	
compx=kingBlack[0]&0xF0;
compy=kingBlack[0]&0xF;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal8=false;
}
compx=queenBlack[0]&0xF0;
compy=queenBlack[0]&0xF;
		 compx=compx>>4;
if(tempX==compx&&tempY==compy||tempX>8||tempY>8){			
isLegal8=false;
}



	if(isLegal1==true){
		eligibleMove(y-2,x+1);
	}
	if(isLegal2==true){
		eligibleMove(y-1,x+2);
	}
	if(isLegal3==true){
		eligibleMove(y+1,x+2);
	}
	if(isLegal4==true){
		eligibleMove(y+2,x+1);
	}
	if(isLegal5==true){
		eligibleMove(y+2,x-1);
	}
	if(isLegal6==true){
		eligibleMove(y+1,x-2);
	}
	if(isLegal7==true){
		eligibleMove(y-1,x-2);
	}
	if(isLegal8==true){
		eligibleMove(y-2,x-1);
	}

		
}
	