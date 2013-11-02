int a=0,b=0;
int P[16][16]={0};
int count(int M[16][16], int i, int j);
void addio();
void randomize(int M[16][16])
{
	int i,j,k;
	for(k=0;k<40;k++){
		i=rand()%16;
		j=rand()%16;
		M[i][j]!=9 ? M[i][j]=9 : k--;
	}
}
void complete(int M[16][16])
{
	int i,j;
	for(i=0;i<16;i++){
		for(j=0;j<16;j++){
			if(M[i][j]!=9) M[i][j]=count(M,i,j);
		}
	}
}
int count(int M[16][16], int i, int j)
{
	int c=0;
	if(i!=0 && j!=0 && M[i-1][j-1]==9) c++;
	if(i!=0 && M[i-1][j]==9) c++;
	if(i!=0 && j!=15 && M[i-1][j+1]==9) c++;
	if(j!=0 && M[i][j-1]==9) c++;
	if(j!=15 && M[i][j+1]==9) c++;
	if(i!=15 && j!=0 && M[i+1][j-1]==9) c++;
	if(i!=15 && M[i+1][j]==9) c++;
	if(i!=15 && j!=15 && M[i+1][j+1]==9) c++;
	return c;
}
void colors(int i)
{
	switch(i){
		case 0: setcolor(BLACK,YELLOW);
			break;
		case 1: setcolor(LIGHTBLUE,BLACK);
			break;
		case 2: setcolor(LIGHTGREEN,BLACK);
			break;
		case 3: setcolor(MAGENTA,BLACK);
			break;
		case 4: setcolor(YELLOW,BLACK);
			break;
		case 5: setcolor(PINK,BLACK);
			break;
		case 6: setcolor(PINK,BLACK);
			break;
		case 7: setcolor(PINK,BLACK);
			break;
		case 8: setcolor(PINK,BLACK);
			break;
		case 9: setcolor(LIGHTGREEN,LIGHTRED);
			break;
		default: setcolor(WHITE,BLACK);
			break;
	}
}
void zero(int M[16][16],int i, int j)
{
	if(M[i][j]!=0){
		P[i][j]=1;
	}
	else if(M[i][j]==0){
		P[i][j]=1;
		if(j!=0&&P[i][j-1]==0) zero(M,i,j-1);
		if(i!=0&&j!=0&&P[i-1][j-1]==0) zero(M,i-1,j-1);
		if(i!=0&&P[i-1][j]==0) zero(M,i-1,j);
		if(i!=0&&j!=15&&P[i-1][j+1]==0) zero(M,i-1,j+1);
		if(j!=15&&P[i][j+1]==0) zero(M,i,j+1);
		if(i!=15&&j!=15&&P[i+1][j+1]==0) zero(M,i+1,j+1);
		if(i!=15&&P[i+1][j]==0) zero(M,i+1,j);
		if(i!=15&&j!=0&&P[i+1][j-1]==0) zero(M,i+1,j-1);
	}
}
int move(int M[16][16])
{
	int stato=0;
	if (getch() == 32) stato=1;
	else{
		switch (getch()) { 
			case 72:if(a!=0) a--; 
				break; 
			case 75: if(b!=0) b--; 
				break; 
			case 77: if(b!=15) b++; 
				break; 
			case 80: if(a!=15) a++; 
				break;
			case 79: stato=2;
				break;
			case 27: addio();
				return 1;
		}
	}
	if(printM(M, stato)==1){
		addio();
		return 1;
	}
	if(printM(M,stato)==2){
		printf("\n\nYOU WON\n\n");
		return 1;
	}
	else return 0;
}
void hello()
{
	int i;
	for(i=0;i<30;i++) print("*");
	print("\n");
	print("ARROWS TO MOVE\n");
	print("SPACE TO OPEN\n");
	print("END TO FLAG\n");
	print("ESC TO EXIT\n");
	for(i=0;i<30;i++) print("*");
	print("\n");
	system("PAUSE");
}
void addio()
{
	printf("\n\nYOU'VE LOST!\n\n");
}
