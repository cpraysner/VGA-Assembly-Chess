typedef int bool;
#define true 1
#define false 0
int inCheckBlack(int y,int x,int* pawnWhite,int* pawnBlack,int* rookWhite,int* rookBlack,int* knightWhite,int* knightBlack,int* bishopWhite,int* bishopBlack,int* queenWhite,int* queenBlack,int* kingWhite,int* kingBlack){
		bool check=false;
		int tempX, tempY;
		int i=0;
		int j=0;
		int compy, compx;
		while(i<8){
		compy=(pawnBlack[i]&0xF);
		compx=(pawnBlack[i]&0xF0);
		compx=compx>>4;
		if(y==compy+1&&x==compx-1){
			check=true;
		}
		if(compy==y+1&&compx==x+1){
			check=true;
		}
		
	i++;
	}
	i=0;
	while(i<2){
		compy=(knightBlack[i]&0xF);
		compx=(knightBlack[i]&0xF0);
		compx=compx>>4;
		if(compy==y+2&&compx==x-1){
			check=true;
		}
		if(compy==y+2&&compx==x+1){
			check=true;
		}
		if(y==compy-2&&x==compx-1){
			check=true;
		}
		if(compy==y-2&&compx==x+1){
			check=true;
		}
		if(y==compy+1&&x==compx-2){
			check=true;
		}
		if(compy==y+1&&compx==x+2){
			check=true;
		}
		if(y==compy-1&&x==compx-2){
			check=true;
		}
		if(compy==y-1&&compx==x+2){
			check=true;
		}
	i++;
	}
	i=0;
	bool isLegal=true;
	while(j<2&&check==false){
	tempX = rookWhite[j]&0xF0;
	tempY = rookWhite[j]&0xF;
	tempX>>4;
	tempY=tempY+1;
	while(tempY<9&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
		i=0;
		while(i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
				break;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
				break;
			}
		i++;	
		}
		
		i = 0;
		
		while(i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;

		while(i < 2){
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}	
		
		if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
		tempY++;
	}
	
	tempX = rookWhite[j]&0xF0;
	tempY = rookWhite[j]&0xF;
	tempX>>4;
	tempX=tempX+1;
	isLegal=true;
	while(tempX < 9&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
			i=0;
		while(isLegal==true&&i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		
		while(isLegal==true&&i < 2){
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		if(isLegal==true){
		
		}
		if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
		tempX++;
	}
	
	tempX = rookWhite[j]&0xF0;
	tempY = rookWhite[j]&0xF;
	tempX>>4;
	tempY=tempY-1;
	isLegal=true;
	while(tempY>0&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
		i=0;
		while(isLegal==true&&i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy ){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		
		while(isLegal==true&&i < 2){
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
		tempY--;
	}
		
		
	tempX = rookWhite[j]&0xF0;
	tempY = rookWhite[j]&0xF;
	tempX>>4;
	tempX=tempX-1;
	isLegal=true;
	while(tempX>0&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
		i=0;
		while(isLegal==true&&i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;

	}
	
	
		while(isLegal==true&&i < 2){
			i=0;
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
	}
	if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
	
	tempX--;
	
	}	
	}
	isLegal=true;
	j=0;
	while(j<2&&check==false){
	tempX=bishopWhite[j]&0xF0;
	tempY=bishopWhite[j]&0xF;
	tempX>>4;
	tempY=tempY+1;
	tempX=tempX+1;
	isLegal=true;
	while(tempY<9&&tempX<9&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
		i=0;
		while(i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
				break;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
 
			if(tempX==compx&&tempY==compy){
				isLegal=false;
				break;
			}
			i++;
		}
		
		i = 0;
		
		while(i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;

		while(i < 2){
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}	
		if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
		tempY++;
		tempX++;
	}
	
	tempX=bishopWhite[j]&0xF0;
	tempY=bishopWhite[j]&0xF;
	tempX>>4;
	tempX=tempX-1;
	tempY=tempY+1;
	isLegal=true;
	while(tempX >0&&tempY<9&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
			i=0;
		while(isLegal==true&&i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		
		while(isLegal==true&&i < 2){
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
		tempX--;
		tempY++;
	}
	
	tempX=bishopWhite[j]&0xF0;
	tempY=bishopWhite[j]&0xF;
	tempX>>4;
	tempY=tempY-1;
	tempX=tempX+1;
	isLegal=true;
	while(tempY>0&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
		i=0;
		while(isLegal==true&&i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy ){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		
		while(isLegal==true&&i < 2){
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
		tempY--;
		tempX++;
	}
			
	tempX=bishopWhite[j]&0xF0;
	tempY=bishopWhite[j]&0xF;
	tempX>>4;
	tempX=tempX-1;
	tempY=tempY-1;
	isLegal=true;
	while(tempX>0&&tempY>0&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
		i=0;
		while(isLegal==true&&i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
	}
	
	
		while(isLegal==true&&i < 2){
			i=0;
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
	}
	if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
	
	tempX--;
	tempY--;
	
	}	
	}
	isLegal=true;
	tempX=queenWhite[0]&0xF0;
	tempY=queenWhite[0]&0xF;
	tempX>>4;
	tempY=tempY+1;
	if(check==false){
	while(tempY<9&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
		i=0;
		while(i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
				break;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
				break;
			}
			i++;
		}
		
		i = 0;
		
		while(i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;

		while(i < 2){
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			
			isLegal=false;
		}
		
		
		if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
		tempY++;
	}
	
	tempX=queenWhite[j]&0xF0;
	tempY=queenWhite[j]&0xF;
	tempX>>4;
	tempX=tempX+1;
	isLegal=true;
	while(tempX < 9&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
			i=0;
		while(isLegal==true&&i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		
		while(isLegal==true&&i < 2){
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		if(isLegal==true){
		
		}
		if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
		tempX++;
	}
	
	tempX=queenWhite[0]&0xF0;
	tempY=queenWhite[0]&0xF;
	tempX>>4;
	tempY=tempY-1;
	isLegal=true;
	while(tempY>0&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
		i=0;
		while(isLegal==true&&i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy ){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		
		while(isLegal==true&&i < 2){
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
		tempY--;
	}
		
		
	tempX=queenWhite[0]&0xF0;
	tempY=queenWhite[0]&0xF;
	tempX>>4;
	tempX=tempX-1;
	isLegal=true;
	while(tempX>0&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
		i=0;
		while(isLegal==true&&i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;

	}
	
	
		while(isLegal==true&&i < 2){
			i=0;
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
	}
	if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
	
	tempX--;
		
	}
	isLegal=true;
	tempX=queenWhite[0]&0xF0;
	tempY=queenWhite[0]&0xF;
	tempX>>4;
	tempY=tempY+1;
	tempX=tempX+1;
	isLegal=true;
	while(tempY<9&&tempX<9&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
		i=0;
		while(i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
				break;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
				break;
			}
			i++;
		}
		
		i = 0;
		
		while(i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;

		while(i < 2){
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			
			isLegal=false;
		}
		
		
		if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
		tempY++;
		tempX++;
	}
	
	tempX=queenWhite[0]&0xF0;
	tempY=queenWhite[0]&0xF;
	tempX>>4;
	tempX=tempX-1;
	tempY=tempY+1;
	isLegal=true;
	while(tempX >0&&tempY<9&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
			i=0;
		while(isLegal==true&&i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		
		while(isLegal==true&&i < 2){
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
		tempX--;
		tempY++;
	}
	
	tempX=queenWhite[0]&0xF0;
	tempY=queenWhite[0]&0xF;
	tempX>>4;
	tempY=tempY-1;
	tempX=tempX+1;
	isLegal=true;
	while(tempY>0&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
		i=0;
		while(isLegal==true&&i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy ){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		
		while(isLegal==true&&i < 2){
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
		tempY--;
		tempX++;
	}
			
	tempX=queenWhite[0]&0xF0;
	tempY=queenWhite[0]&0xF;
	tempX>>4;
	tempX=tempX-1;
	tempY=tempY-1;
	isLegal=true;
	while(tempX>0&&tempY>0&&isLegal==true&&check==false){
		compx=queenWhite[i]&0xF0;
		compy=queenWhite[i]&0xF;
		compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;			
			}
		compx=queenBlack[i]&0xF0;
		compy=queenBlack[i]&0xF;
			 compx=compx>>4;
		if(tempX==compx&&tempY==compy){
			isLegal=false;
		}
		i=0;
		while(isLegal==true&&i<8){
			compx=pawnWhite[i]&0xF0;
			compy=pawnWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=pawnBlack[i]&0xF0;
			compy=pawnBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
			i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=rookWhite[i]&0xF0;
			compy=rookWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=rookBlack[i]&0xF0;
			compy=rookBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
	}
	
	
		while(isLegal==true&&i < 2){
			i=0;
			compx=bishopWhite[i]&0xF0;
			compy=bishopWhite[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=bishopBlack[i]&0xF0;
			compy=bishopBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
		}
		i = 0;
		
		while(isLegal==true&&i < 2){
			compx=knightWhite[i]&0xF0;
			compy=knightWhite[i]&0xF;
			 compx=compx>>4;
			
			if(tempX==compx&&tempY==compy){
				isLegal=false;
			}
			compx=knightBlack[i]&0xF0;
			compy=knightBlack[i]&0xF;
			 compx=compx>>4;
			if(tempX==compx&&tempY==compy){
				
				isLegal=false;
			}
i++;
	}
	if(isLegal==true&&tempX==x&&tempY==y){
			check=true;
		}
	
	tempX--;
	tempY--;
	}
	compy=(kingBlack[0]&0xF);
	compx=(kingBlack[0]&0xF0);
	compx=compx>>4;
		if(y==compy+1&&x==compx-1){
			check=true;
		}
		if(compy+1==y&&compx+1==x){
			check=true;
		}
		if(y==compy-1&&x==compx-1){
			check=true;
		}
		if(y==compy-1&&x==compx+1){
			check=true;
		}
		if(y==compy+1&&x==compx-1){
			check=true;
		}
		if(y==compy+1&&x==compx+1){
			check=true;
		}
		if(y==compy-1&&x==compx-1){
			check=true;
		}
		if(y==compy-1&&x==compx+1){
			check=true;
		}
}
return check;
	
}

	

