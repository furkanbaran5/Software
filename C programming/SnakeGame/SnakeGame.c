#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int i,j,N,M,kuyruk,koordinat[10][2],satir,sutun,YilanBoyut,flag=1,Puan=0,Yem,Degisken1,Degisken2,Boyutuzatma=0,Kalanyem=0;
	srand(time(NULL));
	char D[100][100],Yilan[20]={'1','\0'},hamle;
	
	printf("Oyun tahtasindan cikarsaniz kaybedersiniz.\nKuyruga carparsaniz kaybedersiniz.\nYukari icin-'u'(up)\nAsagi icin-'d'(down)\nSola icin-'l'(left)\nSaga icin-'r'(right)\n");
	printf("Satir sayisi giriniz:");
	scanf("%d",&N);
	printf("\nSutun sayisi giriniz:");
	scanf("%d",&M);
	printf("\nYem sayisi giriniz:");
	scanf("%d",&Yem);
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			D[i][j]=' ';
		}
	}
	
	i=0;
	while(i<Yem){	
		Degisken1=rand()%N;
		Degisken2=rand()%M;
		if(Yem>=N*M){
			printf("\nYem sayisi tahtadan buyuk olamaz lutfen tekrar giriniz:");
			scanf("%d",&Yem);
		}
		else if(D[Degisken1][Degisken2]==' '){
			D[Degisken1][Degisken2]='0';
			i+=1;
		}
	}
	
	i=0;
	while(i<1){
		satir= rand() % N;
		sutun= rand() % M;
		if(D[satir][sutun]==' '){
			D[satir][sutun]='1';
			i=1;
		}
	}
	
	while(hamle!='x' && flag!=0){
		flag=0;
		kuyruk=0;
		
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				printf("[%c]",D[i][j]);
			}
			printf("\n");
		}
		printf("Hamle sayisi:%d\n",Puan);
		
		if(Boyutuzatma==1){
			Yilan[YilanBoyut]=Yilan[YilanBoyut-1]+1;
			Boyutuzatma=0;
		}
		
		printf("Yapmak istediginiz hamleyi giriniz: ");
		scanf(" %c",&hamle);
		for(YilanBoyut=0;Yilan[YilanBoyut];YilanBoyut++);
		
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				if(D[i][j]==Yilan[kuyruk]){
					koordinat[kuyruk][0]=i;
					koordinat[kuyruk][1]=j;
					kuyruk+=1;
				}
			}
		}
		
		if(hamle=='u'){
			if(D[satir-1][sutun]<'2' && satir>0){
				if(D[satir-1][sutun]=='0'){
					Boyutuzatma=1;	
				}	
				D[satir-1][sutun]=D[satir][sutun];
				D[satir][sutun]=' ';
				satir-=1;
			}
			else{
				hamle='x';
				printf("Yanlis Hamle\n");
			}
			Puan+=1;	
		}
		if(hamle=='l'){
			if(D[satir][sutun-1]<'2' && sutun>0){
				if(D[satir][sutun-1]=='0'){
					Boyutuzatma=1;
				}
				D[satir][sutun-1]=D[satir][sutun];
				D[satir][sutun]=' ';
				sutun-=1;	
			}	
			else{
				hamle='x';
				printf("Yanlis Hamle\n");
			}
			Puan+=1;
		}
		if(hamle=='r'){
			if(D[satir][sutun+1]<'2' && sutun<M-1){
				if(D[satir][sutun+1]=='0'){
					Boyutuzatma=1;
				}
				D[satir][sutun+1]=D[satir][sutun];
				D[satir][sutun]=' ';
				sutun+=1;	
			}
			else{
				hamle='x';
				printf("Yanlis Hamle\n");
			}
			Puan+=1;
		}
		if(hamle=='d'){
			if(D[satir+1][sutun]<'2' && satir<N-1){
				if(D[satir+1][sutun]=='0'){
					Boyutuzatma=1;
				}
				D[satir+1][sutun]=D[satir][sutun];
				D[satir][sutun]=' ';
				satir+=1;	
			}
			else{
				hamle='x';
				printf("Yanlis Hamle\n");
			}
			Puan+=1;
		}	
	
		while(kuyruk<YilanBoyut){
			for(i=0;i<N;i++){
				for(j=0;j<M;j++){
					if(D[i][j]==Yilan[kuyruk]){
						koordinat[kuyruk][0]=i;
						koordinat[kuyruk][1]=j;
					}
				}
			}
			kuyruk+=1;
		}	
		
		kuyruk=0;	
		while(kuyruk<YilanBoyut){
			for(i=0;i<N;i++){
				for(j=0;j<M;j++){
					if(D[i][j]==Yilan[kuyruk] && kuyruk<YilanBoyut){
						D[koordinat[kuyruk][0]][koordinat[kuyruk][1]]=Yilan[kuyruk+1];
					}	
				}		
			}	
			kuyruk+=1;	
		}
		
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				if(D[i][j]=='0'){
					flag=1;
				}
			}
		}
		
		printf("\n\n**********************\n\n");
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("[%c]",D[i][j]);
		}
		printf("\n");
	}
	
	if(hamle=='x'){
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				if(D[i][j]=='0'){
					Kalanyem+=1;
				}
			}
		}
		printf("Kaybettiniz oyun bitti\nHamle sayisi:%d\nYilanin uzunlugu: %d\nKalan yem sayisi: %d",Puan,YilanBoyut,Kalanyem);
	}
	else{
		printf("Kazandiniz\nHamle sayisi:%d",Puan);	
	}
	return 0;
}
