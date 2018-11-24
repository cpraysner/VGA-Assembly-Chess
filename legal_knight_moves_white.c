typedef int bool;
#define true 1
#define false 0



void legal_knight_moves_white(int x, int y, int* pawnWhite, int* pawnBlack, int* rookWhite, int* rookBlack, int* knightWhite, int*knightBlack, int*bishopWhite, int* bishopBlack, int* queenWhite, int* queenBlack, int* kingWhite, int* kingBlack, int* array_legal){
	bool isLegal1 = true;
	bool isLegal2 = true;
	bool isLegal3 = true;
	bool isLegal4 = true;
	bool isLegal5 = true;
	bool isLegal6 = true;
	bool isLegal7 = true;
	bool isLegal8 = true;
	int tempX,tempY,compx,compy;
	
	tempX = x+1;
	tempY = y-2;
	
	int i=0;
	
	while(i<8){
		compx=pawnWhite[i]&0xF0;
		compy=pawnWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX>8||tempY<1){
			isLegal1=false;
		}
		i++;
	}
	i = 0;
	
	while(i < 2){
		compx=rookWhite[i]&0xF0;
		compy=rookWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX>8||tempY<1){
			isLegal1=false;
		}
		i++;
			}
	i = 0;
	
	
	while(i < 2){
		compx=bishopWhite[i]&0xF0;
		compy=bishopWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<8||tempY<8){
			isLegal1=false;
		}
	
i++;
	}
	i = 0;
	
	while(i < 2){
		compx=kingWhite[i]&0xF0;
		compy=kingWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX>8||tempY<1){
			isLegal1=false;
		}
	i++;
	}
	i = 0;
	
	compx=kingWhite[0]&0xF0;
compy=kingWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX>8||tempY<1){			
isLegal1=false;
}

compx=queenWhite[0]&0xF0;
compy=queenWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX>8||tempY<1){			
isLegal1=false;
}
	
	
	tempX = x+2;
	tempY = y-1;
	
	i=0;
	while(i<8){
		compx=pawnWhite[i]&0xF0;
		compy=pawnWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX>8||tempY<1){
			isLegal2=false;
		}
	i++;
	}
	i = 0;
	
	while(i < 2){
		compx=rookWhite[i]&0xF0;
		compy=rookWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX>8||tempY<1){
			isLegal2=false;
		}
	i++;
	}
	i = 0;
	
	
	while(i < 2){
		compx=bishopWhite[i]&0xF0;
		compy=bishopWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX>8||tempY<1){
			isLegal2=false;
		}
	i++;
	}
	i = 0;
	
	while(i < 2){
		compx=knightWhite[i]&0xF0;
		compy=knightWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX>8||tempY<1){
			isLegal2=false;
		}
i++;
	}
	i = 0;
	
compx=kingWhite[0]&0xF0;
compy=kingWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX>8||tempY<1){			
isLegal2=false;
}	

compx=queenWhite[0]&0xF0;
compy=queenWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX>8||tempY<1){			
isLegal2=false;
}
	

	
	
	tempX = x+2;
	tempY = y+1;

	i=0;
	while(i<8){
		compx=pawnWhite[i]&0xF0;
		compy=pawnWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX>8||tempY>8){
			isLegal3=false;
		}
	i++;
	}
	i = 0;
	
	while(i < 2){
		compx=rookWhite[i]&0xF0;
		compy=rookWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX>8||tempY>8){
			isLegal3=false;
		}
i++;
	}
	i = 0;
	
	
	while(i < 2){
		compx=bishopWhite[i]&0xF0;
		compy=bishopWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX>8||tempY>8){
			isLegal3=false;
		}
i++;
	}
	i = 0;
	
	while(i < 2){
		compx=knightWhite[i]&0xF0;
		compy=knightWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX>8||tempY>8){
			
			isLegal3=false;
		}
i++;
	}
	i = 0;
	
compx=kingWhite[0]&0xF0;
compy=kingWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX>8||tempY>8){			
isLegal3=false;
}	
compx=queenWhite[0]&0xF0;
compy=queenWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX>8||tempY>8){			
isLegal3=false;
}
	

	
	
	
	tempX = x+1;
	tempY = y+2;
	
	i=0;
	while(i<8){

		compx=pawnWhite[i]&0xF0;
		compy=pawnWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX>8||tempY>8){
			isLegal4=false;
		}
		i++;
	}
	i = 0;
	
	while(i < 2){
		compx=rookWhite[i]&0xF0;
		compy=rookWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX>8||tempY>8){
			isLegal4=false;
		}
i++;
	}
	i = 0;
	
	
	while(i < 2){
		compx=bishopWhite[i]&0xF0;
		compy=bishopWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX>8||tempY>8){
			
			isLegal4=false;
		}
i++;
	}
	i = 0;
	
	while(i < 2){

		compx=knightWhite[i]&0xF0;
		compy=knightWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX>8||tempY>8){
			
			isLegal4=false;
		}
i++;
	}
	i = 0;
	
	compx=kingWhite[0]&0xF0;
compy=kingWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX>8||tempY>8){			
isLegal4=false;
}

compx=queenWhite[0]&0xF0;
compy=queenWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX>8||tempY>8){			
isLegal4=false;
}
	
	
	
	tempX = x-1;
	tempY = y+2;
	
	i=0;
	while(i<8){
		compx=pawnWhite[i]&0xF0;
		compy=pawnWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY>8){
			
			isLegal5=false;
		}
		i++;
	}
	i = 0;
	
	while(i < 2){
		compx=rookWhite[i]&0xF0;
		compy=rookWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY>8){
			
			isLegal5=false;
		}
i++;
	}
	i = 0;
	
	
	while(i < 2){

		compx=bishopWhite[i]&0xF0;
		compy=bishopWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY>8){
		
			isLegal5=false;
		}
i++;
	}
	i = 0;
	
	while(i < 2){
		compx=knightWhite[i]&0xF0;
		compy=knightWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY>8){
			
			isLegal5=false;
		}
i++;
	}
	i = 0;
	
	compx=kingWhite[0]&0xF0;
compy=kingWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX<1||tempY>8){			
isLegal5=false;
}
compx=queenWhite[0]&0xF0;
compy=queenWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX<1||tempY>8){			
isLegal5=false;
}
	
	
	tempX = x-2;
	tempY = y+1;
	
	i=0;
	while(i<8){

		compx=pawnWhite[i]&0xF0;
		compy=pawnWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY>8){
			
			isLegal6=false;
		}
		i++;
	}
	i = 0;
	
	while(i < 2){

		compx=rookWhite[i]&0xF0;
		compy=rookWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY>8){
		
			isLegal6=false;
		}
i++;
	}
	i = 0;
	
	
	while(i < 2){

		compx=bishopWhite[i]&0xF0;
		compy=bishopWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY>8){
			
			isLegal6=false;
		}
i++;
	}
	i = 0;
	
	while(i < 2){

		compx=knightWhite[i]&0xF0;
		compy=knightWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY>8){
			isLegal6=false;
		}
i++;
	}
	i = 0;
	
	compx=kingWhite[0]&0xF0;
compy=kingWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX<1||tempY>8){			
isLegal6=false;
}
compx=queenWhite[0]&0xF0;
compy=queenWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX<1||tempY>8){			
isLegal6=false;
}
	
	tempX = x-2;
	tempY = y-1;
	
	i=0;
	while(i<8){
		compx=pawnWhite[i]&0xF0;
		compy=pawnWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY<1){
			isLegal7=false;
		}
		i++;
	}
	i = 0;
	
	while(i < 2){
		compx=rookWhite[i]&0xF0;
		compy=rookWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY<1){
			
			isLegal7=false;
		}
i++;
	}
	i = 0;
	
	
	while(i < 2){

		compx=bishopWhite[i]&0xF0;
		compy=bishopWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY<1){
			
			isLegal7=false;
		}
i++;
	}
	i = 0;
	
	while(i < 2){

		compx=knightWhite[i]&0xF0;
		compy=knightWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY<1){
			
			isLegal7=false;
		}
i++;
	}
	i = 0;
	
compx=kingWhite[0]&0xF0;
compy=kingWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX<1||tempY<1){			
isLegal7=false;
}
compx=queenWhite[0]&0xF0;
compy=queenWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX<1||tempY<1){			
isLegal7=false;
}

	
	tempX = x-1;
	tempY = y-2;
	
	i=0;
	while(i<8){

		compx=pawnWhite[i]&0xF0;
		compy=pawnWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY<1){
			
			isLegal8=false;
		}
		i++;
	}
	i = 0;
	
	while(i < 2){
		
		compx=rookWhite[i]&0xF0;
		compy=rookWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY<1){
			
			isLegal8=false;
		}
i++;
	}
	i = 0;
	
	
	while(i < 2){

		compx=bishopWhite[i]&0xF0;
		compy=bishopWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY<1){
			
			isLegal8=false;
		}
i++;
	}
	i = 0;
	
	while(i < 2){
		compx=knightWhite[i]&0xF0;
		compy=knightWhite[i]&0xF;
		 compx=compx>>4;
		if((tempX==compx&&tempY==compy)||tempX<1||tempY<1){
			
			isLegal8=false;
		}
i++;
	}
	i = 0;
	
	
compx=kingWhite[0]&0xF0;
compy=kingWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX<1||tempY<1){			
isLegal8=false;
}
compx=queenWhite[0]&0xF0;
compy=queenWhite[0]&0xF;
		 compx=compx>>4;
if((tempX==compx&&tempY==compy)||tempX<1||tempY<1){			
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
	