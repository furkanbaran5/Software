#include <stdio.h>

int main() {
	int a,b,i,p,x,y,n,j=0,sayac=0,top=0,HarfKontrol;
	char D[10]={'m','p','g','e','y','a','o','r','u','b'};
	char kelimeler[][7]={"mergup","baryum","uygar","amper","yorum","muare","opera","perma","erbap","boyar","burma","gurme","gaye","yoga","morg","puma","mayo","brom","obur","ramp","baro","mera","gam","bay","ego","pay","arp","gar","ray","org","mey","mor","oya","yem","bar","bre","ram","abu","ey","ay"};
	char istek[10];
	//Dizilerin elemanlarýný bulma noktasý
	for(x=0;kelimeler[x][0];x++);
	for(y=0;D[y];y++);
	//Bilgi verme noktasý
	printf("\t\t||Kelime Tahmin Oyununa Hos Geldiniz ||\n\t\t***************************************\n\n");
	printf("Oyunun kurallari:\n1-Verilen harflerden kelime uretilecek\n2-Ayni harf iki kere kullanilamaz\n3-Yanlis bilinen her kelime icin kelimenin harf sayisi kadar (-) puan alinir\n4-Bilinen her dogru kelime icin harf sayisi kadar (+) puan alinir\n");
	printf("5-Ayni kelime ikinci kez kullanilirsa harf sayisi kadar (-) puan alir\n6-En az iki harfli kelimeler olmak zorundadir\n7-Yarismayi bitirip puaninizi ogrenmek icin 0 degeri girmeniz yeterlidir\n8-Tum harfler kucuk olmak zorundadir\nHARFLER: ");
	for(i=0;i<y;i++){
		printf("'%c'\t",D[i]);
	}

	
	while(istek[0]!='0'){
		//Oyunun baþlama noktasý
		printf("\n**************************************\n\nKelime tahmin ediniz: ");
		scanf("%s", istek);
		
		for(n=0;istek[n];n++);
		
		if(n>1){
			
			//Yanlýþ Harf kullanýmý var mý diye kontrol noktasý
			for(a=0;a<n;a++){
				for(b=0;b<y;b++){
					if(istek[a]==D[b]){
						HarfKontrol+=1;
					}
				}
			}
			if(HarfKontrol!=n){
				printf("\nHatali harf kullanimi\n");
			}
			HarfKontrol=0;
			
			//Yazýlan kelime doðru mu deðil mi kontrol noktasý
			for(i=0; i<x ; i++){
				while(j<y && kelimeler[i][j]!=NULL){
					
					if(istek[j]==kelimeler[i][j]){
						sayac=sayac+1;		
					}
					else{
						sayac=sayac-1;
					}
					j=j+1;
				}
				
				if(sayac==n){
					kelimeler[i][0]='!';
					p=1;
				}
				
				sayac=0;
				j=0;
			}
			
			//Sonuç yeri
			if(p==1){
				printf("\nPuan:%d\n",n);
				top=top+n;
			}
			else{
				printf("\nPuan:-%d\n",n);
				top=top-n;
			}	
			p=0;
		}
		
		else{
			printf("\nTek harfli kelime girdiniz\n");
		}
	
	}
	printf("\n**************************************\n Toplam Puaniniz:  %d",top);
	return 0;
}
