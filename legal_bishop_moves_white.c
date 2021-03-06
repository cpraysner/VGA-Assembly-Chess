typedef int bool;
#define true 1
#define false 0
void legal_bishop_moves_white(int x, int y, int* pawnWhite, int* pawnBlack, int* rookWhite, int* rookBlack, int* knightWhite, int*knightBlack, int*bishopWhite, int* bishopBlack, int* queenWhite, int* queenBlack, int* kingWhite, int* kingBlack, int* array_legal){
	
	int legal;
	int compx, compy;
	int j = 0;

	int tempX;
	int tempY;
	bool isLegal1=true;
	bool isLegal2=true;
	bool isLegal3=true;
	bool isLegal4 = true;
	int i=0;
	tempX = x+1;
	tempY = y+1;
	while(tempY<9 && tempX < 9&&isLegal1==true){
		i=0;
		while(i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal1=false;
				
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				eligibleMove(tempY,tempX); array_legal[j] = pawnBlack[i];j++;
				isLegal1=false;
				
			}
		i++;	
		}
		
		i = 0;
		
		while(i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal1=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				eligibleMove(tempY,tempX); array_legal[j] = rookBlack[i];j++;
				isLegal1=false;
			}
i++;
		}
		
		i = 0;
		
		
		while(i < 2){
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal1=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				eligibleMove(tempY,tempX); array_legal[j] = bishopBlack[i];j++;
				isLegal1=false;
			}
i++;
		}
		
		i = 0;
		
		while(i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal1=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				eligibleMove(tempY,tempX); array_legal[j] = knightBlack[i];j++;
				isLegal1=false;
			}
i++;
		}
		
		
		compx=kingBlack[0]&0xF0;
		compy=kingBlack[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			eligibleMove(tempY,tempX); array_legal[j] = kingBlack[i];j++;
			isLegal1=false;
		}	
		compx=queenBlack[0]&0xF0;
		compy=queenBlack[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			eligibleMove(tempY,tempX); array_legal[j] = queenBlack[i];j++;;
			isLegal1=false;
		}
		compx=kingWhite[0]&0xF0;
		compy=kingWhite[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			isLegal1=false;
		}	
		compx=queenWhite[0]&0xF0;
		compy=queenWhite[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			isLegal1=false;
		}
		if(isLegal1==true){
		eligibleMove(tempY, tempX);
		legal=tempX<<4;
		legal=legal|tempY;
		array_legal[j]=legal;
		j++;
		}
		tempX++;
		tempY++;
	}
	
	tempX = x+1;
	tempY = y-1;
	while(tempY>0 && tempX < 9&&isLegal2==true){
			i=0;
		while(i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal2=false;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				eligibleMove(tempY,tempX); array_legal[j] = pawnBlack[i];j++;
				isLegal2=false;
			}
			i++;
		}
		i = 0;
		
		while(i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal2=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				eligibleMove(tempY,tempX); array_legal[j] = rookBlack[i];j++;
				isLegal2=false;
			}
i++;
		}
		i = 0;
		
		
		while(i < 2){
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal2=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				eligibleMove(tempY,tempX); array_legal[j] = bishopBlack[i];j++;
				isLegal2=false;
			}
i++;
		}
		i = 0;
		
		while(i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal2=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				eligibleMove(tempY,tempX); array_legal[j] = knightBlack[i];j++;
				isLegal2=false;
			}
i++;
		}
		
		compx=kingBlack[0]&0xF0;
		compy=kingBlack[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			eligibleMove(tempY,tempX); array_legal[j] = kingBlack[i];j++;
			isLegal2=false;
		}	
		compx=queenBlack[0]&0xF0;
		compy=queenBlack[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			eligibleMove(tempY,tempX); array_legal[j] = queenBlack[i];j++;;
			isLegal2=false;
		}
		compx=kingWhite[0]&0xF0;
		compy=kingWhite[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			isLegal2=false;
		}	
		compx=queenWhite[0]&0xF0;
		compy=queenWhite[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			isLegal2=false;
		}
		if(isLegal2==true){
		eligibleMove(tempY, tempX);
		legal=tempX<<4;
		legal=legal|tempY;
		array_legal[j]=legal;
		j++;
		}
		tempX++;
		tempY--;
	}
	
	tempX = x-1;
	tempY = y-1;
	while(tempX>0 && tempY>0&&isLegal3==true){
		i=0;
		while(i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal3=false;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				eligibleMove(tempY,tempX); array_legal[j] = pawnBlack[i];j++;
				isLegal3=false;
			}
			i++;
		}
		i = 0;
		
		while(i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal3=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy) ){
				eligibleMove(tempY,tempX); array_legal[j] = rookBlack[i];j++;
				isLegal3=false;
			}
i++;
		}
		i = 0;
		
		
		while(i < 2){
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal3=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				eligibleMove(tempY,tempX); array_legal[j] = bishopBlack[i];j++;
				isLegal3=false;
			}
i++;
		}
		i = 0;
		
		while(i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal3=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				eligibleMove(tempY,tempX); array_legal[j] = knightBlack[i];j++;
				isLegal3=false;
			}
i++;
		}
		
		compx=kingBlack[0]&0xF0;
		compy=kingBlack[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			eligibleMove(tempY,tempX); array_legal[j] = kingBlack[i];j++;
			isLegal3=false;
		}	
		compx=queenBlack[0]&0xF0;
		compy=queenBlack[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			eligibleMove(tempY,tempX); array_legal[j] = queenBlack[i];j++;;
			isLegal3=false;
		}
		compx=kingWhite[0]&0xF0;
		compy=kingWhite[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			isLegal3=false;
		}	
		compx=queenWhite[0]&0xF0;
		compy=queenWhite[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			isLegal3=false;
		}
		if(isLegal3==true){
		eligibleMove(tempY, tempX);
		legal=tempX<<4;
		legal=legal|tempY;
		array_legal[j]=legal;
		j++;
		}	
		tempX--;
		tempY--;
	}
		
		
	tempX = x-1;
	tempY = y+1;
	while(tempX>0&&tempY>9&&isLegal4==true){
		i=0;
		while(i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal4=false;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				eligibleMove(tempY,tempX); array_legal[j] = pawnBlack[i];j++;
				isLegal4=false;
			}
		i++;
		}
		i = 0;
		
		while(i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal4=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				eligibleMove(tempY,tempX); array_legal[j] = rookBlack[i];j++;
				isLegal4=false;
			}
i++;
	}
	
	
		while(i < 2){
			i=0;
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal4=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				eligibleMove(tempY,tempX); array_legal[j] = bishopBlack[i];j++;
				isLegal4=false;
			}
i++;
		}
		i = 0;
		
		while(i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				isLegal4=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
		 compx=compx>>4;
			if((tempX==compx)&&(tempY==compy)){
				eligibleMove(tempY,tempX); array_legal[j] = knightBlack[i];j++;
				isLegal4=false;
			}
i++;
	}
	
		compx=kingBlack[0]&0xF0;
		compy=kingBlack[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			eligibleMove(tempY,tempX); array_legal[j] = kingBlack[i];j++;
			isLegal4=false;
		}	
		compx=queenBlack[0]&0xF0;
		compy=queenBlack[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			eligibleMove(tempY,tempX); array_legal[j] = queenBlack[i];j++;
			isLegal4=false;
		}
		compx=kingWhite[0]&0xF0;
		compy=kingWhite[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			isLegal4=false;
		}	
		compx=queenWhite[0]&0xF0;
		compy=queenWhite[0]&0xF;
		 compx=compx>>4;
		if((tempX==compx)&&(tempY==compy)){			
			isLegal4=false;
		}
	if(isLegal4==true){
		eligibleMove(tempY, tempX);
		legal=tempX<<4;
		legal=legal|tempY;
		array_legal[j]=legal;
		j++;
	}
	tempX--;
	tempY++;
	
	}

/* array_legal[j] = 0;	
return array_legal;	 */
}
	