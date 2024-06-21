#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct{
	int sipariskodu;
	int ID;
	char isim[MAX];
	char tip[MAX];
	char gun[MAX];
}MUSTERI;

int dosyaOkuma(MUSTERI *musteriler){
	FILE *fp;
	int satir,i,j;
	MUSTERI tasiyici;
	if ( (fp = fopen("input.txt","r"))==NULL) {
		printf("Dosya acilamadi");
		return 0;
    }
    while(!feof(fp)){
		if(getc(fp)=='\n'){
			satir++;
		}
	}
	musteriler=(MUSTERI*)realloc(musteriler,satir*sizeof(MUSTERI));
	rewind(fp);
	for(i=0;i<satir;i++){
		fscanf(fp,"%d %d %s %s %s",&musteriler[i].sipariskodu,&musteriler[i].ID,&musteriler[i].isim,&musteriler[i].tip,&musteriler[i].gun);
	}
   
	for(j=0;j<satir;j++){
		for(i=0;i<satir-j-1;i++){	
			if(musteriler[i].sipariskodu>musteriler[i+1].sipariskodu){
				tasiyici=musteriler[i];
				musteriler[i]=musteriler[i+1];
				musteriler[i+1]=tasiyici;
			}
		}	
	}
	return satir;
	fclose(fp);
}

int dosyayazma(MUSTERI *musteriler,int kisisayisi){
	FILE *fp;
	int i;

	for(i=0;i<kisisayisi;i++){
		if ((fp = fopen(musteriler[i].isim, "w"))==NULL) {
			printf("Dosya acilamadi");
			return 0;
	    }
	    fprintf(fp,"Merhaba %s,%s gunu tarafýnýzdan siparis numarasý %d olan musteri ID: %d olan %s alisverisi gerceklestirilmistir. Iyi gunler.",musteriler[i].isim,musteriler[i].gun,musteriler[i].sipariskodu,musteriler[i].ID,musteriler[i].tip);
	    fclose(fp);
	}
	return 1;
    
    
}

int main(int argc, char *argv[]) {
	MUSTERI *musteriler;
	musteriler=(MUSTERI*)calloc(MAX,sizeof(MUSTERI));
	int kisisayisi;
	kisisayisi=dosyaOkuma(musteriler);
	dosyayazma(musteriler,kisisayisi);
	printf("%d %d %s %s %s\n",musteriler[0].sipariskodu,musteriler[0].ID,musteriler[0].isim,musteriler[0].tip,musteriler[0].gun);
	printf("%d %d %s %s %s\n",musteriler[1].sipariskodu,musteriler[1].ID,musteriler[1].isim,musteriler[1].tip,musteriler[1].gun);
	printf("%d %d %s %s %s\n",musteriler[2].sipariskodu,musteriler[2].ID,musteriler[2].isim,musteriler[2].tip,musteriler[2].gun);
	printf("%d %d %s %s %s",musteriler[3].sipariskodu,musteriler[3].ID,musteriler[3].isim,musteriler[3].tip,musteriler[3].gun);
	
	return 0;
}
