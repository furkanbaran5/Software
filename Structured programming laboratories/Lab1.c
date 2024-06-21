#include <stdio.h>
#define MAX 100

void siralama(int *dizi,int N){
	int i,tasiyici,j;
	for(j=0;j<N;j++){
		for(i=0;i<N-j-1;i++){	
			if(dizi[i]>dizi[i+1]){
				tasiyici=dizi[i];
				dizi[i]=dizi[i+1];
				dizi[i+1]=tasiyici;
			}
		}	
	}
}


int main() {
	int dizi[MAX],N,i,enkucuktoplam,enbuyuktoplam;
	
	printf("Lutfen ogrenci sayisini giriniz:");
	scanf("%d",&N);
	
	if(N<6){
		printf("\nOgrenci sayisi 6'dan kucuk olamaz.\nLutfen ogrenci sayisini giriniz:");
		scanf("%d",&N);
	}
	printf("\n\n");
	for(i=0;i<N;i++){
		printf("%d.Ogrencinin notunu giriniz:",i+1);
		scanf("%d",&dizi[i]);
	}
	siralama(dizi,N);
	enkucuktoplam=dizi[0]+dizi[1]+dizi[2];
	enbuyuktoplam=dizi[N-1]+dizi[N-2]+dizi[N-3];
	printf("En buyuk 3 ogrencinin not toplami:%d\nEn buyuk 3 ogrenci notu:%d,%d,%d\nEn kucuk 3 ogrencinin not toplami:%d\nEn kucuk 3 ogrenci notu:%d,%d,%d",enbuyuktoplam,dizi[N-1],dizi[N-2],dizi[N-3],enkucuktoplam,dizi[0],dizi[1],dizi[2]);
	
	return 0;
}
