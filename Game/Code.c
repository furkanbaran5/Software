#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 50
typedef struct player{//Kullanýcýlar dizisi
	char isim[MAX];
	char soyisim[MAX];
	char kullaniciadi[MAX];
	char sifre[MAX];
	int puan;
}PLAYER;
typedef struct sayac{//Toplanan atom altý parçacýklar
	int P;
	int p;
	int E;
	int e;
}SAYAC;

int kayitokuma(PLAYER *players);//Textteki oyuncu profillerini structre a atýyorum.
void puansiralama(PLAYER *players,int kisisayisi);//Bubble sort ile aldýðým kullanýcýlarý sýralýyorum.
void AnaMenu(PLAYER *players,int kisisayisi);//Oyun hakkýnda bilgi ve puan tablosunu yazdýrma.
void puantablosu(PLAYER *players,int kisisayisi);//Puan tablosunu ekrana yazan fonksiyon.
void oyuncukayit(PLAYER *players,int *kisisayisi);//Yeni oyuncuyu kayýt eden fonksiyon.
int giris(PLAYER *players,int kisisayisi);//Giriþ fonksiyonu.
void HaritaMenu();//Haritalar hakkýnda bilgi
char** dosyaAcma(char **Lab,char dosyaismi[MAX],int* N1,int* M1);//Harita.txt sini Lab matrisine aktarýyorum
void haritayazdirma(char **Lab,int N,int M);//Harita ekrana yazdýrma fonksiyonu
void giriskonumubulma(char **Lab,int N,int M,int *Xk,int *Yk);//Haritadaki X'in konumunu bulma.
void oyunhareketi(char **Lab,int *Xk,int *Yk,int N,int M,int otoormanuel,SAYAC *sayac);//Oyun kurallarýný uygulayýp oyun içi hareketi saðlýyorum.
int oyunadimlari(char **Lab,int *Xk,int *Yk,int Xyenideger,int Yyenideger,SAYAC *sayac,int N,int M);//Hareket ederken bir sonraki adýmda bulunan deðere göre iþlem yapýyorum.
void puanEkleme(PLAYER *players,SAYAC *sayac,int index);//Karþýt proton ve elektronlarý nötrleþtiriyorum sonra kýyaslayýp kaç tane atom oluþturduysa o kadar puan ekliyorum hesabýna.
int kayityazma(PLAYER *players,int kisisayisi);//Son kullanýcý deðerlerini texte yazan fonksyon.

int main(int argc, char *argv[]) {
 	char **Lab,*dosyaismi;
 	int N,M,kisisayisi=0,index,flag=0,flag2=1,flag3=1,Xk,Yk;
 	PLAYER *players;
 	SAYAC sayac;
 	players = (PLAYER *)calloc(MAX, sizeof(PLAYER));//Geçici yer ayýrtma.
 	dosyaismi=(char*)calloc(MAX,sizeof(char));
	
	kisisayisi=kayitokuma(players);//Text dosyasýndaki verileri players isimli Struct dizisine aktarýyorum.
	puansiralama(players,kisisayisi);//Oyuncularýn puanlarýný sýralýyorum
	AnaMenu(players,kisisayisi);//Giriþ ekraný

	while(flag==0){//Giriþ veya kayýt ekraný.
 		printf("Giris yapmak icin 'g' tusuna, kayit yapmak icin 'k' tusuna basiniz: ");
	 	switch(getch()){
		 	case 'k'://Kayýt adýmlarý
		 		players=(PLAYER*)realloc(players,(kisisayisi+2)*sizeof(PLAYER));//Yeniden yer ayýrtma
		 		oyuncukayit(players,&kisisayisi);
		 		index=kisisayisi-1;//Kayýt ettiðim oyuncunun indexini elde tutuyorum.
		 		flag=1;
		 		break;
			case 'g':
				players=(PLAYER*)realloc(players,(kisisayisi)*sizeof(PLAYER));//Yeniden yer ayýrtma
				index=giris(players,kisisayisi);//Structre da bulduðum kullanýcýyý indexe atadým.
				flag=1;
				break;
			default:
				printf("\nHatali tuslama Lutfen tekrar giriniz\n");
				break;
		}
	}
	
	while(flag2==1){//Oyun döngüsü
		do{//Harita seçme ekraný
			flag=1;
			HaritaMenu();//Haritalarý gösteriyorum.
		    printf("\n");
		    switch(getch()){
		    	case 49:
		    		dosyaismi="map1.txt";
					Lab=dosyaAcma(Lab,dosyaismi,&N,&M);//Textteki dosyalarý Lab matrisine aktarýyorum.
		    		haritayazdirma(Lab,N,M);//Seçilen haritayý ekrana yazdýrýyorma fonksiyonu.
		    		break;
		    	case 50:
		    		dosyaismi="map2.txt";
					Lab=dosyaAcma(Lab,dosyaismi,&N,&M);
		    		haritayazdirma(Lab,N,M);
		    		break;
		    	case 51:
		    		dosyaismi="map3.txt";
					Lab=dosyaAcma(Lab,dosyaismi,&N,&M);
		    		haritayazdirma(Lab,N,M);
		    		break;
		    	case 52:
		    		dosyaismi="map4.txt";
					Lab=dosyaAcma(Lab,dosyaismi,&N,&M);
		    		haritayazdirma(Lab,N,M);
		    		break;
		    	case 53://Kullanýcýnýn gireceði haritayý alýyorum
		    		printf("\nAcmak istediginiz dosyayi exmap.txt formatinda giriniz:");
		    		scanf("%s",dosyaismi);
		    		Lab=dosyaAcma(Lab,dosyaismi,&N,&M);
		    		haritayazdirma(Lab,N,M);
		    		break;
		    	default:
		    		printf("\nHATALI TUSLAMA !! \n\nTEKRAR SECINIZ\n\n");
		    		flag=0;
			}
			usleep(2000);system("cls");
		}while(flag==0);
		giriskonumubulma(Lab,N,M,&Xk,&Yk);//Haritadaki X'in konumunu buluyorum.
		sayac.E=0,sayac.e=0,sayac.P=0,sayac.p=0;//Baþlangýç atom altý parçacýk deðerlerini sýfýrlýyorum.
		while(flag3==1){//Oyunun manuel mi otomatik mi oynanmasýný seçme ekraný.
			printf("Oyunu Manuel mi Otomatik mi oynamak istiyorsunuz?(m/o):");
			switch(getch()){
				case 'm':
					oyunhareketi(Lab,&Xk,&Yk,N,M,1,&sayac);//6. parametre 1 ise manuel 2 ise otomatik.
					flag3=0;
					break;
				case 'o':
					oyunhareketi(Lab,&Xk,&Yk,N,M,2,&sayac);
					flag3=0;
					break;
				default:
					printf("Yanlis Tusa bastiniz.\n");
					break;
			}
		}
		puanEkleme(players,&sayac,index);//Oyuncunun puanýný güncelliyorum.
		printf("Oyuncunun puani:%d\nDevam etmek icin 'd' ye basiniz.Cikmak icin herhangi bir tusa basiniz.",players[index].puan);//Tekrardan oynayacak mý diye kontrol ediyorum.
		if(getch()!='d'){
			flag2=0;
		}usleep(2000);system("cls");
	}
	
	puansiralama(players,kisisayisi);//Puanlarý sýralýyorum.
	puantablosu(players,kisisayisi);//Ekrana yazýyorum.
	kayityazma(players,kisisayisi);//Son kullanýcý deðerlerini texte yazýyorum.
	free(Lab);//Tüm dizileri serbest býrakýyorum.
	free(dosyaismi);
	free(players);
	return 0;
}

int kayitokuma(PLAYER *players){//Textteki oyuncu profillerini structre a atýyorum.
	FILE *fp;
	int satir=0,j=0,i;
	if ((fp = fopen("kayit_defteri.txt", "rb"))==NULL) {
		printf("Dosya acilamadi");
		return 0;
    }
	while(!feof(fp)){//Satýr sayýsýný buluyorum
		if(getc(fp)=='\n'){
			satir++;
		}
	}
	rewind(fp);
    for(i=0;i<satir;i++){//Text dosyasýndaki kelimelerle oyuncu profillerini ekliyorum
    	fscanf(fp,"%s %s %s %s %d",&players[i].isim,&players[i].soyisim,&players[i].kullaniciadi,&players[i].sifre,&players[i].puan);
    }
	fclose(fp);
	return satir;
}

void puansiralama(PLAYER *players,int kisisayisi){//Bubble sort ile aldýðým kullanýcýlarý sýralýyorum.
	PLAYER tasiyici;
	int i,j;
	for(j=0;j<kisisayisi;j++){
		for(i=0;i<kisisayisi-j-1;i++){	
			if(players[i].puan>players[i+1].puan){
				tasiyici=players[i];
				players[i]=players[i+1];
				players[i+1]=tasiyici;
			}
		}	
	}
}

void AnaMenu(PLAYER *players,int kisisayisi){//Oyun hakkýnda bilgi ve puan tablosunu yazdýrma.
	printf("\t\t\tKARSIT MADDE LABIRENTI\nOyuna hosgeldiniz oyunun kurallari:\n1. Labirentteki yollarda asagidaki parcaciklar bulunmaktadir.\n\tP+ : proton\n\te- : elektron\n\tP- : karsit proton\n\te+ : karsit elektron\n");
	printf("2. Karsit hidrojen uretebilmek icin labirentin cikisinda elinizde sadece P- ve e+ parcaciklari bulunmalidir. \n3. Bir parcacikla o parcacigin zit isaretli karsit parcacigi bir araya gelirse birbirini yok eder.\n4. Karadelikler K ile gosterilmistir. Karadeliklerin bulundugu hucrelerden gecildigi takdirde oyun sonlanir.\n5. 100 saniye icinde kullanici cikisa ulasamazsa oyun sonlanir.\n\n");
	puantablosu(players,kisisayisi);
}

void puantablosu(PLAYER *players,int kisisayisi){//Puan tablosunu ekrana yazan fonksiyon.
	int i;
	printf("\n\t\tPUAN TABLOSU\n");
	for(i=0;i<kisisayisi;i++){
		printf("%d.Kisi:\n\tIsim:%s\n\tPuan:%d\n\n",i+1,players[kisisayisi-i-1].isim,players[kisisayisi-i-1].puan);
	}
}

void oyuncukayit(PLAYER *players,int *kisisayisi){//Yeni oyuncuyu kayýt eden fonksiyon.
	int i,flag;
	char kullaniciadi[20];
	do{
		flag=0;
		printf("\nLutfen kayit icin bir kullanici adi belirleyiniz: ");
		scanf("%s",&kullaniciadi);
		for(i=0;i<*kisisayisi;i++){//Aldýðým kullanýcý adý kullanýlmýþ mý diye kontrol ediyorum
			if(strcmp(players[i].kullaniciadi,kullaniciadi)==0){
				printf("\nBu kullanici adi zaten kullanilmis.\n");
			}else{
				flag++;
			}
		}
	}while(flag!=*kisisayisi);
	strcpy(players[(*kisisayisi)].kullaniciadi,kullaniciadi);//Yeni oyuncumu Structre'mýn sonuna ekliyorum.
	printf("\nLutfen kayit icin bir isim belirleyiniz: ");
	scanf("%s",players[(*kisisayisi)].isim);
	printf("\nLutfen kayit icin bir soyisim belirleyiniz: ");
	scanf("%s",players[(*kisisayisi)].soyisim);
	printf("\nLutfen kayit icin bir sifre belirleyiniz: ");
	scanf("%s",players[(*kisisayisi)].sifre);
	players[(*kisisayisi)].puan=0;
	*kisisayisi+=1;//kiþi sayýmý arttýrýyorum.
}

int giris(PLAYER *players,int kisisayisi){//Giriþ fonksiyonu.
	char kullaniciadi[MAX],sifre[MAX];
	int index=-1,i,hak=3,basari=0;
	while(index==-1){//Kullanýcý adý varlýðý kontrol noktasý.
		printf("\nLutfen kullanici adi giriniz: ");
		scanf("%s",&kullaniciadi);
		for(i=0;i<kisisayisi;i++){//Aldýðým kullanýcý adýnýn dizideki yerini arýyorum.
			if(strcmp(players[i].kullaniciadi,kullaniciadi)==0){
				index=i;
			}
		}
		if(index==-1){
			printf("\nBu kullanici adi bulunmamaktadir\n");
		}
	}
	while(hak!=0){//Þifre deneme
		printf("\nSifre giriniz: ");
		scanf("%s",&sifre);
		if(strcmp(players[index].sifre,sifre)==0){
			printf("\nGiris Basarili!\n");
			basari=1;
			hak=0;
		}else{
			hak--;
			printf("\nHatali Sifre Kalan Hak:%d\n",hak);
		}
	}
	if(basari==0){//yanlýþ þifre durumu.
		printf("\nSistem kapatiliyor!!!!\n");
		exit(0);
	}
	return index;
}

void HaritaMenu(){//Haritalar hakkýnda bilgi
	printf("KARSIT MADDE LABIRENTI\nOynamak istediginiz haritayi seciniz");
	printf("\n\n1-)\n[ 0 ][ 0 ][ 1 ][ 0 ][ P ][ 0 ][ e ][ 0 ][ p ][ 0 ]\n[ 1 ][ 0 ][ p ][ 0 ][ 1 ][ E ][ 1 ][ 0 ][ 1 ][ 0 ]\n[ 1 ][ X ][ 1 ][ 0 ][ 1 ][ 0 ][ 1 ][ 0 ][ 0 ][ K ]\n[ 0 ][ 0 ][ P ][ 0 ][ p ][ 0 ][ 0 ][ 0 ][ 1 ][ 0 ]\n[ 0 ][ 1 ][ 1 ][ 0 ][ K ][ C ][ 1 ][ 0 ][ 1 ][ 0 ]\n[ 0 ][ 0 ][ 0 ][ 0 ][ 1 ][ 0 ][ p ][ 0 ][ 0 ][ 0 ]");
	printf("\n\n2-)\n[ X ][ 0 ][ p ][ 0 ][ P ][ 0 ][ 0 ][ 0 ][ p ][ 0 ]\n[ 1 ][ 0 ][ 1 ][ 0 ][ 1 ][ E ][ 1 ][ e ][ 0 ][ 0 ]\n[ 1 ][ 0 ][ 1 ][ 0 ][ 1 ][ 0 ][ 0 ][ 0 ][ 1 ][ K ]\n[ 0 ][ 0 ][ P ][ 0 ][ p ][ 0 ][ 1 ][ 0 ][ 1 ][ 0 ]\n[ 0 ][ 1 ][ 1 ][ K ][ 0 ][ C ][ 1 ][ 0 ][ 1 ][ 0 ]\n[ 0 ][ 0 ][ 0 ][ 0 ][ 1 ][ 0 ][ 0 ][ p ][ 0 ][ 0 ]");
	printf("\n\n3-)\n[ 0 ][ 1 ][ 1 ][ 0 ][ 0 ][ 0 ]\n[ 0 ][ 0 ][ X ][ 0 ][ 1 ][ 0 ]\n[ 1 ][ p ][ 1 ][ P ][ 1 ][ 0 ]\n[ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ]\n[ P ][ 1 ][ 1 ][ p ][ K ][ 1 ]\n[ 0 ][ E ][ 0 ][ 0 ][ C ][ 0 ]\n[ e ][ 1 ][ 1 ][ 0 ][ 1 ][ p ]\n[ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ]\n[ p ][ 1 ][ 0 ][ 1 ][ 1 ][ 0 ]\n[ 0 ][ 0 ][ K ][ 0 ][ 0 ][ 0 ]");
	printf("\n\n4-)\n[ X ][ 1 ][ 1 ][ 0 ][ 0 ][ 0 ]\n[ 0 ][ 0 ][ 0 ][ 0 ][ 1 ][ 0 ]\n[ p ][ 1 ][ 1 ][ P ][ 1 ][ 0 ]\n[ 0 ][ 0 ][ 0 ][ 0 ][ K ][ 0 ]\n[ P ][ 1 ][ 1 ][ p ][ 0 ][ 1 ]\n[ 0 ][ E ][ 0 ][ 0 ][ C ][ 0 ]\n[ 0 ][ 1 ][ 0 ][ 1 ][ 1 ][ 0 ]\n[ 0 ][ e ][ 0 ][ 0 ][ 0 ][ p ]\n[ p ][ 0 ][ 1 ][ 1 ][ 1 ][ 0 ]\n[ 0 ][ 0 ][ K ][ 0 ][ 0 ][ 0 ]");
	printf("\n\n5-)Kendi Labirentinizi Once Satir sayisi bosluk Sutunsayisi alt satirinda inip matris seklinde txt dosyasina yazmis\nprojenin oldugu klasore yuklemisseniz eger bu secenegi tuslayiniz.\n\nSecenek:");
}

char** dosyaAcma(char **Lab,char dosyaismi[MAX],int* N1,int* M1){//Harita.txt sini Lab matrisine aktarýyorum
	FILE *fp;
	int i,j,N,M;
	if ( (fp = fopen(dosyaismi,"r"))==NULL) {
		printf("Dosya acilamadi");
		return 0;
    }
    fscanf(fp,"%d %d",&N,&M);//Text dosyasýnýn ilk iki elemaný boyut bilgisi.
	Lab=(char**)calloc(N,sizeof(char*));
	for(i=0;i<N;i++){
		Lab[i]=(char*)calloc(N,sizeof(char));
	}
    for(i=0;i<N;i++){
    	for(j=0;j<M;j++){
    		fscanf(fp," %c",&Lab[i][j]);
		}
	}
	*N1=N;
	*M1=M;
	fclose(fp);	
	return Lab;
}

void haritayazdirma(char **Lab,int N,int M){//Harita ekrana yazdýrma fonksiyonu
	int i,j;
	printf("\n\n\n\n");
	for(i=0;i<N;i++){
    	for(j=0;j<M;j++){
    		printf("[ %c ]",Lab[i][j]);
		}
		printf("\n");
	}
}

void giriskonumubulma(char **Lab,int N,int M,int *Xk,int *Yk){//Haritadaki X'in konumunu bulma fonksiyonu.
	int i=0,j=0,flag=0;
	while(flag==0 & i<N){
		while(flag==0 & j<M){
			if(Lab[i][j]=='X'){
				*Xk=i;
				*Yk=j;
				flag=1;
			}
			j++;
		}
		i++;
		j=0;
	}
}

void oyunhareketi(char **Lab,int *Xk,int *Yk,int N,int M,int otoormanuel,SAYAC *sayac){//Oyun kurallarýný uygulayýp oyun içi hareketi saðlýyorum.
	int tus,flag,g=0,i,Xilkdeger=*Xk,Yilkdeger=*Yk,delikKontrol,Xyenideger,Yyenideger,rasgelesayi,oyunSuresi=100;//Oyun süresini 100 saniye olarak belirledim istenildiði gibi deðiþtirilebilir.
	time_t baslangicZamani,simdikiZaman;
	if(otoormanuel==1){//otoormanuel deðeri 1 ise manuel 2 ise otomatik.
		flag=1;
	}else if(otoormanuel==2){
		flag=2;
	}
	haritayazdirma(Lab,N,M);//Ekrana haritayý yazdýrýyorum
	for(i=0;i<5;i++){//Oyun baþlarken 5 saniye geri sayým yapýyorum(Amaç:oyun baþlamadan oyuncunun hazýrlanýp labirenti görmesi.)
		printf("%d saniye sonra oyununuz baslayacaktir.\n",5-i);
		sleep(1);
	}
	system("cls");//Ekraný temizliyorum
	haritayazdirma(Lab,N,M);//Ekrana haritayý yazdýrýyorum
	printf("Sureniz basladi.Oyuna baslayabilirsiniz.\n");
	baslangicZamani=time(NULL);//Oyunun baþlangýç süresini not alýyorum
    while (flag==1) {//Manuel oynama bölümü
        switch (getch()) {//Yön tuþlarýna göre oyunadimlari fonksiyonunu çaðýrýp bir sonraki adýma göre iþlem yapýyorum.
            case 27://ESC çýkýþ.
                printf("Cikis yapildi.\n");
                flag=0;
			default:
                switch (getch()) {
                    case 72://Yukarý
                    	Xyenideger=(*Xk)-1;
                    	Yyenideger=(*Yk);
                        delikKontrol=oyunadimlari(Lab,Xk,Yk,Xyenideger,Yyenideger,sayac,N,M);//Fonksiyona eski ve yeni kordinatlarý gönderiyorum.
                        break;
                    case 80://Aþaðý
                    	Xyenideger=(*Xk)+1;
                    	Yyenideger=(*Yk);
                        delikKontrol=oyunadimlari(Lab,Xk,Yk,Xyenideger,Yyenideger,sayac,N,M);
                        break;
                    case 75://Sol
                    	Yyenideger=(*Yk)-1;
                    	Xyenideger=(*Xk);
                        delikKontrol=oyunadimlari(Lab,Xk,Yk,Xyenideger,Yyenideger,sayac,N,M);
                        break;
                    case 77://Sað
                    	Yyenideger=(*Yk)+1;
                    	Xyenideger=(*Xk);
                        delikKontrol=oyunadimlari(Lab,Xk,Yk,Xyenideger,Yyenideger,sayac,N,M);
                        break;
                    default:
                        printf("Bilinmeyen yon tusu\n");
                        break;
                }
                break;
        }
        if(g==0){//ilk deðeri G
        	Lab[Xilkdeger][Yilkdeger]='G';
			g=1;
		}
		if(delikKontrol==0){//Kara delik gelmesi durumu
			flag=0;
		}
		if(delikKontrol==2){//Cýkýsa gidilmesi durumu
			flag=0;
		}
        usleep(2000);system("cls");//Ekraný temizliyorum
        haritayazdirma(Lab,N,M);//Ekrana haritayý yazdýrýyorum
		printf("Toplanan atom alti parcaciklar\ne+: %d\nP-: %d\ne-: %d\nP+: %d\n",(*sayac).E,(*sayac).p,(*sayac).e,(*sayac).P);//Toplanan atom altý parçaçýklar hakkýnda bilgi veriyom.
        simdikiZaman=time(NULL);//simdiki zamaný alýp süreyi kontrol ediyorum.
        if(oyunSuresi<=(simdikiZaman-baslangicZamani)){//Süre bitti mi diye kontrol.
        	(*sayac).E=0,(*sayac).e=0,(*sayac).P=0,(*sayac).p=0;
			printf("Verilen sure icinde bitiremediniz. Kaybettiniz.\n");
        	flag=0;
		}
    }
    srand(time(NULL));//Rasgele deðer seçip saða sola rasgele hareket etmesi için otomatik oynatýyorum.
	rasgelesayi=rand();
	while(flag==2){//Otomatik oynatma.
		rasgelesayi*=7;//Her seferinde 7 ile çarpýp saða sola yukarý aþaðý rastgele gitmesini saðlýyorum.
		switch (rasgelesayi%4) {
            case 0://Yukarý
                Xyenideger=(*Xk)-1;
                Yyenideger=(*Yk);
                delikKontrol=oyunadimlari(Lab,Xk,Yk,Xyenideger,Yyenideger,sayac,N,M);//Fonksiyona eski ve yeni x deðerlerini gönderiyorum.
                break;
            case 1://Aþaðý
               	Xyenideger=(*Xk)+1;
                Yyenideger=(*Yk);
                delikKontrol=oyunadimlari(Lab,Xk,Yk,Xyenideger,Yyenideger,sayac,N,M);
                break;
            case 2://Sol
                Yyenideger=(*Yk)-1;
                Xyenideger=(*Xk);
                delikKontrol=oyunadimlari(Lab,Xk,Yk,Xyenideger,Yyenideger,sayac,N,M);
                break;
            case 3://Sað
                Yyenideger=(*Yk)+1;
                Xyenideger=(*Xk);
                delikKontrol=oyunadimlari(Lab,Xk,Yk,Xyenideger,Yyenideger,sayac,N,M);
                break;
            default:
                printf("Bilinmeyen yon tusu\n");
                break;
        }
		if(delikKontrol==2){//Cýkýsa gidilmesi durumu
			flag=0;
		}
        sleep(1);system("cls");//Ekraný temizliyorum
        haritayazdirma(Lab,N,M);//Ekrana haritayý yazdýrýyorum
		printf("Toplanan atom alti parcaciklar\ne+: %d\nP-: %d\ne-: %d\nP+: %d\n",(*sayac).E,(*sayac).p,(*sayac).e,(*sayac).P);//Toplanan atom altý parçaçýklar hakkýnda bilgi veriyom.
        simdikiZaman=time(NULL);//simdiki zamaný alýp süreyi kontrol ediyorum.
        if(oyunSuresi<=(simdikiZaman-baslangicZamani)){//Süre bitti mi diye kontrol.
        	(*sayac).E=0,(*sayac).e=0,(*sayac).P=0,(*sayac).p=0;
			printf("Verilen sure icinde bitiremediniz. Kaybettiniz.\n");
        	flag=0;
		}
	}	
}

int oyunadimlari(char **Lab,int *Xk,int *Yk,int Xyenideger,int Yyenideger,SAYAC *sayac,int N,int M){//Hareket ederken bir sonraki adýmda bulunan deðere göre iþlem yapýyorum.
	if(Xyenideger<0 || Yyenideger<0 || Xyenideger>=N || Yyenideger>=M){//Matristen çýkýp çýkmadýðýný kontrol ediyorum.
		printf("\nDuvar!!");
		return 1;
	}
	switch(Lab[Xyenideger][Yyenideger]){//Bir sonraki adýmdaki deðere göre iþlem yapýyorum
		case '0'://Sadece x'i taþýyorum
			Lab[*Xk][*Yk]='0';
			*Xk=Xyenideger;
			*Yk=Yyenideger;
			Lab[*Xk][*Yk]='X';
			break;
		case '1'://X hareket etmiyor
			printf("\nDuvar!!");
			break;
		case 'E'://e+ 'yý 1 arttýrýyorum
			(*sayac).E++;
			Lab[*Xk][*Yk]='0';
			*Xk=Xyenideger;
			*Yk=Yyenideger;
			Lab[*Xk][*Yk]='X';
			
			break;
		case 'e'://e- 'yý 1 arttýrýyorum
			(*sayac).e++;
			Lab[*Xk][*Yk]='0';
			*Xk=Xyenideger;
			*Yk=Yyenideger;
			Lab[*Xk][*Yk]='X';
			break;
		case 'P'://p+ 'yý 1 arttýrýyorum
			(*sayac).P++;
			Lab[*Xk][*Yk]='0';
			*Xk=Xyenideger;
			*Yk=Yyenideger;
			Lab[*Xk][*Yk]='X';
			break;
		case 'p'://p- 'yý 1 arttýrýyorum
			(*sayac).p++;
			Lab[*Xk][*Yk]='0';
			*Xk=Xyenideger;
			*Yk=Yyenideger;
			Lab[*Xk][*Yk]='X';
			break;
		case 'K'://Kara delikse topladýðý tüm elemanlarý sýfýrlayýp oyunu bitiriyorum.
			(*sayac).E=0,(*sayac).e=0,(*sayac).P=0,(*sayac).p=0;
			printf("Kara delige girdiniz\n");
			return 0;
			break;
		case 'C'://Oyunu bitiriyorum
			Lab[*Xk][*Yk]='0';
			*Xk=Xyenideger;
			*Yk=Yyenideger;
			Lab[*Xk][*Yk]='X';
			printf("Cikisa varip oyunu bitirdiniz.\n");
			return 2;//Çýkýþ ise oyunu bitiriyorum
			break;
	}
	return 1;//return 1 olan yerlerde oyun devam ediyor.
}

void puanEkleme(PLAYER *players,SAYAC *sayac,int index){//Karþýt proton ve elektronlarý nötrleþtiriyorum sonra kýyaslayýp kaç tane atom oluþturduysa o kadar puan ekliyorum hesabýna.
	if((*sayac).p<(*sayac).P){(*sayac).p=0;} else{(*sayac).p-=(*sayac).P;}//Protonlarý nötrleþtiriyorum
	if((*sayac).E<(*sayac).e){(*sayac).E=0;} else{(*sayac).E-=(*sayac).e;}//Elektronlarý nötrleþtiriyorum
	if((*sayac).E<(*sayac).p){players[index].puan+=(*sayac).E;} else{players[index].puan+=(*sayac).p;}//Atom oluþturuyorum.
}

int kayityazma(PLAYER *players,int kisisayisi){//Son kullanýcý deðerlerini texte yazan fonksiyon.
	FILE *fp;
	int i;
	if ((fp = fopen("kayit_defteri.txt", "wb"))==NULL) {
		printf("Dosya acilamadi");
		return 0;
    }
    for(i=0;i<kisisayisi;i++){//Son deðerleri Texte yazýyorum.
		fprintf(fp,"%s %s %s %s %d\n",players[i].isim,players[i].soyisim,players[i].kullaniciadi,players[i].sifre,players[i].puan);
	}
	fclose(fp);
	return 1;
}

