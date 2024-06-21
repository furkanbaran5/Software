#include <stdio.h>

int main() {
	
	int i,j,a,b,sayac=0,bolen=0,M,N,k,flag=0;
	int Dizi[100][100];
	int Filtre[100][100];
	int Son[100][100];
	printf("Satir sayisi giriniz:");
	scanf(" %d",&M);
	printf("\nSutun sayisi giriniz:");
	scanf("%d",&N);
	printf("\nFiltre matrisin boyutunu giriniz:");
	scanf("%d",&k);
	while(flag!=1){
	if(k%2!=1 || k>=N || k>=M){
		printf("\nHatali filtre boyutu lutfen tekrar giriniz:");
		scanf("%d",&k);
	}
	else{
		flag=1;
	}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("\n%d.Satir %d.Sutun elemani giriniz:",i+1,j+1);
			scanf("%d",&Dizi[i][j]);
		}
	}
		
	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
			printf("\nFiltre matrisinin %d.Satir %d.Sutun elemani giriniz:",i+1,j+1);
			scanf("%d",&Filtre[i][j]);
		}
	}
	for(a=0;a<M-k+1;a++){
		for(b=0;b<N-k+1;b++){
			for(i=0;i<k;i++){
				for(j=0;j<k;j++){
					sayac+=Dizi[i+a][j+b]*Filtre[i][j];
					bolen+=Filtre[i][j];	
				}
			}
			Son[a][b]=sayac/bolen;
			sayac=0;
			bolen=0;
		}
	}
	printf("\n------\n");
	for(i=0;i<M-k+1;i++){
		for(j=0;j<N-k+1;j++){
			printf("|%d|",Son[i][j]);
		}
		printf("\n------\n");
	}
	return 0;
}
