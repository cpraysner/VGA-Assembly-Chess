typedef int bool;
#define true 1
#define false 0
void king_legal_white(int x, int y, int* pawnWhite, int* pawnBlack, int* rooksWhite, int* rooksBlack, int* knightWhite, int*knightBlack, int* bishopWhite, int* bishopBlack, int* queensWhite, int* queensBlack, int* kingWhite, int* kingBlack, int* array_legal){
	int compx, compy;
	int king_legal[8];
	int legal;
	int j=0;
	bool isLegal0=true;
	bool isLegal1=true;
	bool isLegal2=true;
	bool isLegal3=true;
	bool isLegal4=true;
	bool isLegal5=true;
	bool isLegal6=true;
	bool isLegal7=true;
	bool check=false;
	bool check0=false;
	bool check1=false;
	bool check2=false;
	bool check3=false;
	bool check4=false;
	bool check5=false;
	bool check6=false;
	bool check7=false;
	check0=inCheckWhite(y+1,x-1, pawnWhite, pawnBlack, rooksWhite,rooksBlack,knightWhite,knightBlack,bishopWhite,bishopBlack,queensWhite,queensBlack,kingWhite,kingBlack);
	check1=inCheckWhite(y+1,x, pawnWhite, pawnBlack, rooksWhite,rooksBlack,knightWhite,knightBlack,bishopWhite,bishopBlack,queensWhite,queensBlack,kingWhite,kingBlack);
	check2=inCheckWhite(y+1,x+1, pawnWhite, pawnBlack, rooksWhite,rooksBlack,knightWhite,knightBlack,bishopWhite,bishopBlack,queensWhite,queensBlack,kingWhite,kingBlack);
	check3=inCheckWhite(y,x+1, pawnWhite, pawnBlack, rooksWhite,rooksBlack,knightWhite,knightBlack,bishopWhite,bishopBlack,queensWhite,queensBlack,kingWhite,kingBlack);
	check4=inCheckWhite(y,x-1, pawnWhite, pawnBlack, rooksWhite,rooksBlack,knightWhite,knightBlack,bishopWhite,bishopBlack,queensWhite,queensBlack,kingWhite,kingBlack);
	check5=inCheckWhite(y-1,x-1, pawnWhite, pawnBlack, rooksWhite,rooksBlack,knightWhite,knightBlack,bishopWhite,bishopBlack,queensWhite,queensBlack,kingWhite,kingBlack);
	check6=inCheckWhite(y-1,x, pawnWhite, pawnBlack, rooksWhite,rooksBlack,knightWhite,knightBlack,bishopWhite,bishopBlack,queensWhite,queensBlack,kingWhite,kingBlack);
	check7=inCheckWhite(y-1,x+1, pawnWhite, pawnBlack, rooksWhite,rooksBlack,knightWhite,knightBlack,bishopWhite,bishopBlack,queensWhite,queensBlack,kingWhite,kingBlack);

	int i=0;
	while(i<8){
		compy=(pawnWhite[i]&0xF);
		compx=(pawnWhite[i]&0xF0);
		compx=compx>>4;
		if((compy==y+1&&compx==x)||check1==true||y>7){
			isLegal1=false;	
		}
		if((compy==y+1&&compx==x-1)||check0==true||y>7||x<2){
			isLegal0=false;
		}
		if((compy==y+1&&compx==x+1)||check2==true||y>7||x>7){
			isLegal2=false;
		}
		if((compy==y&&compx==x+1)||check3==true||x>7){
				isLegal3=false;
		}
		if((compy==y&&compx==x-1)||check4==true||x<2){
				isLegal4=false;
		}
		if((compy==y-1&&compx==x-1)||check5==true||y<2||x<2){
				isLegal5=false;
		}
		if((compy==y-1&&compx==x)||check6==true||y<2){
				isLegal6=false;
		}
		if((compy==y-1&&compx==x+1)||check7==true||y<2||x>7){
				isLegal7=false;
		}
	i++;
	}

	i=0;
	while(i<8){
		compy=(rooksWhite[i]&0xF);
		compx=(rooksWhite[i]&0xF0);
		compx=compx>>4;
		if((compy==y+1&&compx==x)||check1==true||y>7){
			isLegal1=false;	
		}
		if((compy==y+1&&compx==x-1)||check0==true||y>7||x<2){
			isLegal0=false;
		}
		if((compy==y+1&&compx==x+1)||check2==true||y>7||x>7){
			isLegal2=false;
		}
		if((compy==y&&compx==x+1)||check3==true||x>7){
				isLegal3=false;
		}
		if((compy==y&&compx==x-1)||check4==true||x<2){
				isLegal4=false;
		}
		if((compy==y-1&&compx==x-1)||check5==true||y<2||x<2){
				isLegal5=false;
		}
		if((compy==y-1&&compx==x)||check6==true||y<2){
				isLegal6=false;
		}
		if((compy==y-1&&compx==x+1)||check7==true||y<2||x>7){
				isLegal7=false;
		}
	i++;
	}
	
		i=0;
	while(i<2){
		compy=(knightWhite[i]&0xF);
		compx=(knightWhite[i]&0xF0);
		compx=compx>>4;
		if((compy==y+1&&compx==x)||check1==true||y>7){
			isLegal1=false;	
		}
		if((compy==y+1&&compx==x-1)||check0==true||y>7||x<2){
			isLegal0=false;
		}
		if((compy==y+1&&compx==x+1)||check2==true||y>7||x>7){
			isLegal2=false;
		}
		if((compy==y&&compx==x+1)||check3==true||x>7){
				isLegal3=false;
		}
		if((compy==y&&compx==x-1)||check4==true||x<2){
				isLegal4=false;
		}
		if((compy==y-1&&compx==x-1)||check5==true||y<2||x<2){
				isLegal5=false;
		}
		if((compy==y-1&&compx==x)||check6==true||y<2){
				isLegal6=false;
		}
		if((compy==y-1&&compx==x+1)||check7==true||y<2||x>7){
				isLegal7=false;
		}
	i++;
	}
	i=0;
	
	while(i<2){
		compy=(bishopWhite[i]&0xF);
		compx=(bishopWhite[i]&0xF0);
		compx=compx>>4;
				if((compy==y+1&&compx==x)||check1==true||y>7){
			isLegal1=false;	
		}
		if((compy==y+1&&compx==x-1)||check0==true||y>7||x<2){
			isLegal0=false;
		}
		if((compy==y+1&&compx==x+1)||check2==true||y>7||x>7){
			isLegal2=false;
		}
		if((compy==y&&compx==x+1)||check3==true||x>7){
				isLegal3=false;
		}
		if((compy==y&&compx==x-1)||check4==true||x<2){
				isLegal4=false;
		}
		if((compy==y-1&&compx==x-1)||check5==true||y<2||x<2){
				isLegal5=false;
		}
		if((compy==y-1&&compx==x)||check6==true||y<2){
				isLegal6=false;
		}
		if((compy==y-1&&compx==x+1)||check7==true||y<2||x>7){
				isLegal7=false;
		}
	i++;
	}

	compy=(queensWhite[i]&0xF);
	compx=(queensWhite[i]&0xF0);
	compx=compx>>4;
		if((compy==y+1&&compx==x)||check1==true||y>7){
			isLegal1=false;	
		}
		if((compy==y+1&&compx==x-1)||check0==true||y>7||x<2){
			isLegal0=false;
		}
		if((compy==y+1&&compx==x+1)||check2==true||y>7||x>7){
			isLegal2=false;
		}
		if((compy==y&&compx==x+1)||check3==true||x>7){
				isLegal3=false;
		}
		if((compy==y&&compx==x-1)||check4==true||x<2){
				isLegal4=false;
		}
		if((compy==y-1&&compx==x-1)||check5==true||y<2||x<2){
				isLegal5=false;
		}
		if((compy==y-1&&compx==x)||check6==true||y<2){
				isLegal6=false;
		}
		if((compy==y-1&&compx==x+1)||check7==true||y<2||x>7){
				isLegal7=false;
		}

	
	if(isLegal0==true){
		eligibleMove(y+1,x-1);
		legal=x-1;
		legal<<4;
		legal=legal|(y+1);
		king_legal[j]=legal;
		j++;
	}
	if(isLegal1==true){
		eligibleMove(y+1,x);
		legal=legal|(y+1);
		king_legal[j]=legal;
		j++;
	}
	if(isLegal2==true){
		eligibleMove(y+1,x+1);
		legal=legal|(y+1);
		king_legal[j]=legal;
		j++;
	}
	if(isLegal3==true){
		eligibleMove(y,x+1);
		legal=legal|(y+1);
		king_legal[j]=legal;
		j++;
	}
	if(isLegal4==true){
		eligibleMove(y,x-1);
		legal=legal|(y+1);
		king_legal[j]=legal;
		j++;
	}
	if(isLegal5==true){
		eligibleMove(y-1,x-1);
		legal=legal|(y+1);
		king_legal[j]=legal;
		j++;
	}
	if(isLegal6==true){
		eligibleMove(y-1,x);
		legal=legal|(y+1);
		king_legal[j]=legal;
		j++;
	}
	if(isLegal7==true){
		eligibleMove(y-1,x+1);
		legal=legal|(y+1);
		king_legal[j]=legal;
		j++;
	}
	//check=inCheckWhite(y,x, pawnWhite, pawnBlack, rooksWhite,rooksBlack,knightWhite,knightBlack,bishopWhite,bishopBlack,queensWhite,queensBlack,kingWhite,kingBlack);
	/* return king_legal; */
}

	