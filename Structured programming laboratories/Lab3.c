#include <stdio.h>
#include <stdlib.h>

struct urun{
    int urunkodu;
    char *urunadi;
    float birimfiyat;
    float kilofiyat;
};
void urunlistele(struct urun urunler[]){
	int i;
	printf("Kod\t\tUrun adi\tBirim fiyat\t\tKilo fiyat\n");
	for(i=0;i<6;i++){
		printf("%d\t\t",urunler[i].urunkodu);
		printf("%s\t\t",urunler[i].urunadi);
		printf("%f\t\t",urunler[i].birimfiyat);
		printf("%f\t\t",urunler[i].kilofiyat);
		printf("\n");
	}
	printf("\n");
}
float tutarhesaplama(struct urun urunler[],float sepet){
	int kod,tip,miktar;
	printf("Urun kodu giriniz:");
	scanf("%d",&kod);
	printf("\nAlis tipi (1:Birim, 2:Kilo): ");
	scanf("%d",&tip);
	printf("\nMiktar Giriniz: ");
	scanf("%d",&miktar);
	if(tip==1){
		sepet+=urunler[kod-1].birimfiyat*miktar;
	}else if(tip==2){
		sepet+=urunler[kod-1].kilofiyat*miktar;
	}
	printf("\nToplam tutar: %f\n",sepet);
	return sepet;
}
int main(int argc, char *argv[]) {
	int kod,tip,i,miktar;
	float sepet=0;
	char kontrol='E';
	struct urun urun1,urun2,urun3,urun4,urun5,urun6;
	struct urun urunler[6];
	
	urun1.urunkodu=1;
	urun1.urunadi="domates";
	urun1.birimfiyat=8.25;
	urun1.kilofiyat=23.75;
	
	urun2.urunkodu=2;
	urun2.urunadi="biber";
	urun2.birimfiyat=6.25;
	urun2.kilofiyat=29.50;
	
	urun3.urunkodu=3;
	urun3.urunadi="sut";
	urun3.birimfiyat=15.85;
	urun3.kilofiyat=27.15;
	
	urun4.urunkodu=4;
	urun4.urunadi="peynir";
	urun4.birimfiyat=23.00;
	urun4.kilofiyat=95.50;
	
	urun5.urunkodu=5;
	urun5.urunadi="muz";
	urun5.birimfiyat=13.45;
	urun5.kilofiyat=45.50;
	
	urun6.urunkodu=6;
	urun6.urunadi="armut";
	urun6.birimfiyat=5.50;
	urun6.kilofiyat=20.15;
	
	urunler[0]=urun1;
	urunler[1]=urun2;
	urunler[2]=urun3;
	urunler[3]=urun4;
	urunler[4]=urun5;
	urunler[5]=urun6;
	
	while(kontrol=='E'){
		urunlistele(urunler);
		sepet=tutarhesaplama(urunler,sepet);
		printf("\nDevam etmek istiyor musunuz? (E/H) :  ");
		scanf(" %c",&kontrol);
	}
	printf("\Toplam tutar : %f ",sepet);
	if(sepet>=100){
		sepet*=0.9;
	}else if(sepet>=50){
		sepet*=0.95;
	}
	printf("\nIndirimli tutar : %f ",sepet);
	return 0;
}
