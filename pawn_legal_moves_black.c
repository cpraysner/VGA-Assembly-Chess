typedef int bool;
#define true 1
#define false 0

void pawn_legal_black(int x, int y, int* pawnWhite, int* pawnBlack, int* rooksWhite, int* rooksBlack, int* knightsWhite, int*knightsBlack, int* bishopsWhite, int* bishopsBlack, int* queensWhite, int* queensBlack, int* kingsWhite, int* kingsBlack, int* array_legal){
	
	int legal;
	
	int j = 0;
	int tempX;
	int tempY;
	int compx, compy;
	bool isLegal0=false;
	bool isLegal1=true;
	bool isLegal2=false;
	bool isLegal3=true;
	int i=0;
	while(i<8){
		compy=(pawnWhite[i]&0xF);
		compx=(pawnWhite[i]&0xF0);
		compx>>4;
		if(compy==y-1&&compx==x){
			isLegal1=false;
			isLegal3=false;
		}
		if(compy==y-1&&compx==x-1){
			isLegal0=true;
			
		}
		if(compy==y-1&&compx==x+1){
			isLegal2=true;
		}
		if(y==7){
			if(compy==y-2&&compx==x){
				isLegal3=false;
			}
			
		}else{
			isLegal3=false;
		}
	i++;
	}
	i=0;
	while(i<8){
		compy=(pawnBlack[i]&0xF);
		compx=(pawnBlack[i]&0xF0);
		compx>>4;
		if(compy==y-1&&compx==x){
			isLegal1=false;
			isLegal3=false;
		}
		if(compy==y-1&&compx==x-1){
			isLegal0=false;
		}
		if(compy==y-1&&compx==x+1){
			isLegal2=false;
		}
		if(y==7){
			if(compy==y-2&&compx==x){
				isLegal3=false;
			}
			
		}else{
			isLegal3=false;
		}
	i++;
	}
	i=0;
	while(i<2){
		compy=(rooksBlack[i]&0xF);
		compx=(rooksBlack[i]&0xF0);
		compx>>4;
		if(compy==y-1&&compx==x){
			isLegal1=false;
			isLegal3=false;
		}
		if(compy==y-1&&compx==x-1){
			isLegal0=false;
		}
		if(compy==y-1&&compx==x+1){
			isLegal2=false;
		}
		if(y==7){
			if(compy==y-2&&compx==x){
				isLegal3=false;
			}
			
		}else{
			isLegal3=false;
		}
	i++;
	}
	i=0;
	while(i<2){
		compy=(rooksWhite[i]&0xF);
		compx=(rooksWhite[i]&0xF0);
		compx>>4;
		if(compy==y-1&&compx==x){
			isLegal1=false;
		}
		if(compy==y-1&&compx==x-1){
			isLegal0=true;
		}
		if(compy==y-1&&compx==x+1){
			isLegal2=true;
		}
		if(y==7){
			if(compy==y-2&&compx==x){
				isLegal3=false;
			}
			
		}else{
			isLegal3=false;
		}
	i++;
	}
	i=0;
	while(i<2){
		compy=(knightsBlack[i]&0xF);
		compx=(knightsBlack[i]&0xF0);
		compx>>4;
		if(compy==y-1&&compx==x){
			isLegal1=false;
			isLegal3=false;
		}
		if(compy==y-1&&compx==x-1){
			isLegal0=false;
		}
		if(compy==y-1&&compx==x+1){
			isLegal2=false;
		}
		if(y==7){
			if(compy==y-2&&compx==x){
				isLegal3=false;
			}
			
		}else{
			isLegal3=false;
		}
	i++;
	}
		i=0;
	while(i<2){
		compy=(knightsWhite[i]&0xF);
		compx=(knightsWhite[i]&0xF0);
		compx>>4;
		if(compy==y-1&&compx==x){
			isLegal1=false;
			isLegal3=false;
		}
		if(compy==y-1&&compx==x-1){
			isLegal0=true;
		}
		if(compy==y-1&&compx==x+1){
			isLegal2=true;
		}
		if(y==7){
			if(compy==y-2&&compx==x){
				isLegal3=false;
			}
			
		}else{
			isLegal3=false;
		}
	i++;
	}
		i=0;
	while(i<2){
		compy=(bishopsBlack[i]&0xF);
		compx=(bishopsBlack[i]&0xF0);
		compx>>4;
		if(compy==y-1&&compx==x){
			isLegal1=false;
			isLegal3=false;
		}
		if(compy==y-1&&compx==x-1){
			isLegal0=false;
		}
		if(compy==y-1&&compx==x+1){
			isLegal2=false;
		}
		if(y==7){
			if(compy==y-2&&compx==x){
				isLegal3=false;
			}
			
		}else{
			isLegal3=false;
		}
	i++;
	}	i=0;
	while(i<2){
		compy=(bishopsWhite[i]&0xF);
		compx=(bishopsWhite[i]&0xF0);
		compx>>4;
		if(compy==y-1&&compx==x){
			isLegal1=false;
			isLegal3=false;
		}
		if(compy==y-1&&compx==x-1){
			isLegal0=true;
		}
		if(compy==y-1&&compx==x+1){
			isLegal2=true;
		}
		if(y==7){
			if(compy==y-2&&compx==x){
				isLegal3=false;
			}
			
		}else{
			isLegal3=false;
		}
	i++;
	}

	
	compy=(queensBlack[i]&0xF);
	compx=(queensBlack[i]&0xF0);
	compx>>4;
	if(compy==y-1&&compx==x){
		isLegal1=false;
		isLegal3=false;
		}
		if(compy==y-1&&compx==x-1){
			isLegal0=false;
		}
		if(compy==y-1&&compx==x+1){
			isLegal2=false;
		}
		if(y==7){
			if(compy==y-2&&compx==x){
				isLegal3=false;
			}
			
		}else{
			isLegal3=false;
		}
	compy=(queensWhite[i]&0xF);
	compx=(queensWhite[i]&0xF0);
	compx>>4;
	if(compy==y-1&&compx==x){
		isLegal1=false;
		isLegal3=false;
		}
		if(compy==y-1&&compx==x-1){
			isLegal0=false;
		}
		if(compy==y-1&&compx==x+1){
			isLegal2=true;
		}
		if(y==7){
			if(compy==y-2&&compx==x){
				isLegal3=true;
			}
			
		}else{
			isLegal3=false;
		}
	compy=(kingsBlack[i]&0xF);
	compx=(kingsBlack[i]&0xF0);
	compx>>4;
	if(compy==y-1&&compx==x){
		isLegal1=false;
		isLegal3=false;
		}
		if(compy==y-1&&compx==x-1){
			isLegal0=false;
		}
		if(compy==y-1&&compx==x+1){
			isLegal2=false;
		}
		if(y==7){
			if(compy==y-2&&compx==x){
				isLegal3=true;
			}
			
		}else{
			isLegal3=false;
		}
	compy=(kingsWhite[i]&0xF);
	compx=(kingsWhite[i]&0xF0);
	compx>>4;
	if(compy==y-1&&compx==x){
		isLegal1=false;
		isLegal3=false;
		}
		if(compy==y-1&&compx==x-1){
			isLegal0=true;
		}
		if(compy==y-1&&compx==x+1){
			isLegal2=true;
		}
		if(y==7){
			if(compy==y-2&&compx==x){
				isLegal3=false;
			}
			
		}else{
			isLegal3=false;
		}
	
	if(isLegal0==true){
		eligibleMove(y-1,x-1);
		
		legal=(x-1);
		legal<<4;
		legal=legal|(y-1);
	}
	if(isLegal1==true){
		eligibleMove(y-1,x);
		
		legal=x;
		legal<<4;
		legal=legal|(y-1);
	}
	if(isLegal2==true){
		eligibleMove(y-1,x+1);
		
		legal=(x+1);
		legal<<4;
		legal=legal|(y-1);
	}
	if(isLegal3==true){
		eligibleMove(y-2,x);
		
		legal=x;
		legal<<4;
		legal=legal|(y-2);
	}
		
}
	