#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"conio3.h"
#include"headersPF.h"
int printM(int M[16][16], int stato);
void zero(int M[16][16],int i, int j);
int move(int M[16][16]);
int cnt=0;
int main(void)
{
	srand(time(NULL));
	int M[16][16]={0};
	hello();
	randomize(M);
	complete(M);
	printM(M,0);
	while(move(M)!=1);
	system("PAUSE");
	return 0;
}
int printM(int M[16][16], int stato)
{
	clrscr();
	int i,j,q=0;
	int p=0,o;
	for(i=0;i<16;i++){
		for(j=0;j<16;j++){
			if(i==a&&j==b){
				if(stato==1){
					if(M[i][j]==0) zero(M,i,j);
					M[i][j]!=9 ? printf("%d ",M[i][j]) : printf("%c%c",254,254);
					if(M[i][j]==9) q=1;
					P[i][j]=1;
				}
				else if(stato==2){
					setcolor(BLUE,YELLOW);
					printf("%c%c",176,176);
					setcolor(WHITE,BLACK);
					P[i][j]=2;
					cnt++;
				} 
				else{
					if(P[i][j]!=1) printf("%c%c",219, 219);
					else{
						setcolor(BLACK,WHITE);
						printf("%d ",M[i][j]);
						setcolor(WHITE,BLACK);
					}
				}
			}
			else if(P[i][j]==0) printf("%c%c",178,178);
			else if(P[i][j]==1){
				colors(M[i][j]);
				printf("%d ",M[i][j]);
				setcolor(WHITE,BLACK);
			}
			else if(P[i][j]==2){
				setcolor(BLUE,YELLOW);
				printf("%c%c",176,176);
				setcolor(WHITE,BLACK);
			}
		}
		printf("\n");
	}
	printf("%20d of 40 flags", cnt/2);
	for(i=0;i<16;i++){
		for(j=0;j<16;j++) P[i][j]!=0 ? p++ : p;
	}
	if(cnt==80&&p==256) return 2;
	if(q==1) return 1;
	else return 0;
}

