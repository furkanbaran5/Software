#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 50
typedef struct player{//Kullan�c�lar dizisi
	char isim[MAX];
	char soyisim[MAX];
	char kullaniciadi[MAX];
	char sifre[MAX];
	int puan;
}PLAYER;
typedef struct sayac{//Toplanan atom alt� par�ac�klar
	int P;
	int p;
	int E;
	int e;
}SAYAC;

int kayitokuma(PLAYER *players);//Textteki oyuncu profillerini structre a at�yorum.
void puansiralama(PLAYER *players,int kisisayisi);//Bubble sort ile ald���m kullan�c�lar� s�ral�yorum.
void AnaMenu(PLAYER *players,int kisisayisi);//Oyun hakk�nda bilgi ve puan tablosunu yazd�rma.
void puantablosu(PLAYER *players,int kisisayisi);//Puan tablosunu ekrana yazan fonksiyon.
void oyuncukayit(PLAYER *players,int *kisisayisi);//Yeni oyuncuyu kay�t eden fonksiyon.
int giris(PLAYER *players,int kisisayisi);//Giri� fonksiyonu.
void HaritaMenu();//Haritalar hakk�nda bilgi
char** dosyaAcma(char **Lab,char dosyaismi[MAX],int* N1,int* M1);//Harita.txt sini Lab matrisine aktar�yorum
void haritayazdirma(char **Lab,int N,int M);//Harita ekrana yazd�rma fonksiyonu
void giriskonumubulma(char **Lab,int N,int M,int *Xk,int *Yk);//Haritadaki X'in konumunu bulma.
void oyunhareketi(char **Lab,int *Xk,int *Yk,int N,int M,int otoormanuel,SAYAC *sayac);//Oyun kurallar�n� uygulay�p oyun i�i hareketi sa�l�yorum.
int oyunadimlari(char **Lab,int *Xk,int *Yk,int Xyenideger,int Yyenideger,SAYAC *sayac,int N,int M);//Hareket ederken bir sonraki ad�mda bulunan de�ere g�re i�lem yap�yorum.
void puanEkleme(PLAYER *players,SAYAC *sayac,int index);//Kar��t proton ve elektronlar� n�trle�tiriyorum sonra k�yaslay�p ka� tane atom olu�turduysa o kadar puan ekliyorum hesab�na.
int kayityazma(PLAYER *players,int kisisayisi);//Son kullan�c� de�erlerini texte yazan fonksyon.

int main(int argc, char *argv[]) {
 	char **Lab,*dosyaismi;
 	int N,M,kisisayisi=0,index,flag=0,flag2=1,flag3=1,Xk,Yk;
 	PLAYER *players;
 	SAYAC sayac;
 	players = (PLAYER *)calloc(MAX, sizeof(PLAYER));//Ge�ici yer ay�rtma.
 	dosyaismi=(char*)calloc(MAX,sizeof(char));
	
	kisisayisi=kayitokuma(players);//Text dosyas�ndaki verileri players isimli Struct dizisine aktar�yorum.
	puansiralama(players,kisisayisi);//Oyuncular�n puanlar�n� s�ral�yorum
	AnaMenu(players,kisisayisi);//Giri� ekran�

	while(flag==0){//Giri� veya kay�t ekran�.
 		printf("Giris yapmak icin 'g' tusuna, kayit yapmak icin 'k' tusuna basiniz: ");
	 	switch(getch()){
		 	case 'k'://Kay�t ad�mlar�
		 		players=(PLAYER*)realloc(players,(kisisayisi+2)*sizeof(PLAYER));//Yeniden yer ay�rtma
		 		oyuncukayit(players,&kisisayisi);
		 		index=kisisayisi-1;//Kay�t etti�im oyuncunun indexini elde tutuyorum.
		 		flag=1;
		 		break;
			case 'g':
				players=(PLAYER*)realloc(players,(kisisayisi)*sizeof(PLAYER));//Yeniden yer ay�rtma
				index=giris(players,kisisayisi);//Structre da buldu�um kullan�c�y� indexe atad�m.
				flag=1;
				break;
			default:
				printf("\nHatali tuslama Lutfen tekrar giriniz\n");
				break;
		}
	}
	
	while(flag2==1){//Oyun d�ng�s�
		do{//Harita se�me ekran�
			flag=1;
			HaritaMenu();//Haritalar� g�steriyorum.
		    printf("\n");
		    switch(getch()){
		    	case 49:
		    		dosyaismi="map1.txt";
					Lab=dosyaAcma(Lab,dosyaismi,&N,&M);//Textteki dosyalar� Lab matrisine aktar�yorum.
		    		haritayazdirma(Lab,N,M);//Se�ilen haritay� ekrana yazd�r�yorma fonksiyonu.
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
		    	case 53://Kullan�c�n�n girece�i haritay� al�yorum
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
		sayac.E=0,sayac.e=0,sayac.P=0,sayac.p=0;//Ba�lang�� atom alt� par�ac�k de�erlerini s�f�rl�yorum.
		while(flag3==1){//Oyunun manuel mi otomatik mi oynanmas�n� se�me ekran�.
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
		puanEkleme(players,&sayac,index);//Oyuncunun puan�n� g�ncelliyorum.
		printf("Oyuncunun puani:%d\nDevam etmek icin 'd' ye basiniz.Cikmak icin herhangi bir tusa basiniz.",players[index].puan);//Tekrardan oynayacak m� diye kontrol ediyorum.
		if(getch()!='d'){
			flag2=0;
		}usleep(2000);system("cls");
	}
	
	puansiralama(players,kisisayisi);//Puanlar� s�ral�yorum.
	puantablosu(players,kisisayisi);//Ekrana yaz�yorum.
	kayityazma(players,kisisayisi);//Son kullan�c� de�erlerini texte yaz�yorum.
	free(Lab);//T�m dizileri serbest b�rak�yorum.
	free(dosyaismi);
	free(players);
	return 0;
}

int kayitokuma(PLAYER *players){//Textteki oyuncu profillerini structre a at�yorum.
	FILE *fp;
	int satir=0,j=0,i;
	if ((fp = fopen("kayit_defteri.txt", "rb"))==NULL) {
		printf("Dosya acilamadi");
		return 0;
    }
	while(!feof(fp)){//Sat�r say�s�n� buluyorum
		if(getc(fp)=='\n'){
			satir++;
		}
	}
	rewind(fp);
    for(i=0;i<satir;i++){//Text dosyas�ndaki kelimelerle oyuncu profillerini ekliyorum
    	fscanf(fp,"%s %s %s %s %d",&players[i].isim,&players[i].soyisim,&players[i].kullaniciadi,&players[i].sifre,&players[i].puan);
    }
	fclose(fp);
	return satir;
}

void puansiralama(PLAYER *players,int kisisayisi){//Bubble sort ile ald���m kullan�c�lar� s�ral�yorum.
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

void AnaMenu(PLAYER *players,int kisisayisi){//Oyun hakk�nda bilgi ve puan tablosunu yazd�rma.
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

void oyuncukayit(PLAYER *players,int *kisisayisi){//Yeni oyuncuyu kay�t eden fonksiyon.
	int i,flag;
	char kullaniciadi[20];
	do{
		flag=0;
		printf("\nLutfen kayit icin bir kullanici adi belirleyiniz: ");
		scanf("%s",&kullaniciadi);
		for(i=0;i<*kisisayisi;i++){//Ald���m kullan�c� ad� kullan�lm�� m� diye kontrol ediyorum
			if(strcmp(players[i].kullaniciadi,kullaniciadi)==0){
				printf("\nBu kullanici adi zaten kullanilmis.\n");
			}else{
				flag++;
			}
		}
	}while(flag!=*kisisayisi);
	strcpy(players[(*kisisayisi)].kullaniciadi,kullaniciadi);//Yeni oyuncumu Structre'm�n sonuna ekliyorum.
	printf("\nLutfen kayit icin bir isim belirleyiniz: ");
	scanf("%s",players[(*kisisayisi)].isim);
	printf("\nLutfen kayit icin bir soyisim belirleyiniz: ");
	scanf("%s",players[(*kisisayisi)].soyisim);
	printf("\nLutfen kayit icin bir sifre belirleyiniz: ");
	scanf("%s",players[(*kisisayisi)].sifre);
	players[(*kisisayisi)].puan=0;
	*kisisayisi+=1;//ki�i say�m� artt�r�yorum.
}

int giris(PLAYER *players,int kisisayisi){//Giri� fonksiyonu.
	char kullaniciadi[MAX],sifre[MAX];
	int index=-1,i,hak=3,basari=0;
	while(index==-1){//Kullan�c� ad� varl��� kontrol noktas�.
		printf("\nLutfen kullanici adi giriniz: ");
		scanf("%s",&kullaniciadi);
		for(i=0;i<kisisayisi;i++){//Ald���m kullan�c� ad�n�n dizideki yerini ar�yorum.
			if(strcmp(players[i].kullaniciadi,kullaniciadi)==0){
				index=i;
			}
		}
		if(index==-1){
			printf("\nBu kullanici adi bulunmamaktadir\n");
		}
	}
	while(hak!=0){//�ifre deneme
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
	if(basari==0){//yanl�� �ifre durumu.
		printf("\nSistem kapatiliyor!!!!\n");
		exit(0);
	}
	return index;
}

void HaritaMenu(){//Haritalar hakk�nda bilgi
	printf("KARSIT MADDE LABIRENTI\nOynamak istediginiz haritayi seciniz");
	printf("\n\n1-)\n[ 0 ][ 0 ][ 1 ][ 0 ][ P ][ 0 ][ e ][ 0 ][ p ][ 0 ]\n[ 1 ][ 0 ][ p ][ 0 ][ 1 ][ E ][ 1 ][ 0 ][ 1 ][ 0 ]\n[ 1 ][ X ][ 1 ][ 0 ][ 1 ][ 0 ][ 1 ][ 0 ][ 0 ][ K ]\n[ 0 ][ 0 ][ P ][ 0 ][ p ][ 0 ][ 0 ][ 0 ][ 1 ][ 0 ]\n[ 0 ][ 1 ][ 1 ][ 0 ][ K ][ C ][ 1 ][ 0 ][ 1 ][ 0 ]\n[ 0 ][ 0 ][ 0 ][ 0 ][ 1 ][ 0 ][ p ][ 0 ][ 0 ][ 0 ]");
	printf("\n\n2-)\n[ X ][ 0 ][ p ][ 0 ][ P ][ 0 ][ 0 ][ 0 ][ p ][ 0 ]\n[ 1 ][ 0 ][ 1 ][ 0 ][ 1 ][ E ][ 1 ][ e ][ 0 ][ 0 ]\n[ 1 ][ 0 ][ 1 ][ 0 ][ 1 ][ 0 ][ 0 ][ 0 ][ 1 ][ K ]\n[ 0 ][ 0 ][ P ][ 0 ][ p ][ 0 ][ 1 ][ 0 ][ 1 ][ 0 ]\n[ 0 ][ 1 ][ 1 ][ K ][ 0 ][ C ][ 1 ][ 0 ][ 1 ][ 0 ]\n[ 0 ][ 0 ][ 0 ][ 0 ][ 1 ][ 0 ][ 0 ][ p ][ 0 ][ 0 ]");
	printf("\n\n3-)\n[ 0 ][ 1 ][ 1 ][ 0 ][ 0 ][ 0 ]\n[ 0 ][ 0 ][ X ][ 0 ][ 1 ][ 0 ]\n[ 1 ][ p ][ 1 ][ P ][ 1 ][ 0 ]\n[ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ]\n[ P ][ 1 ][ 1 ][ p ][ K ][ 1 ]\n[ 0 ][ E ][ 0 ][ 0 ][ C ][ 0 ]\n[ e ][ 1 ][ 1 ][ 0 ][ 1 ][ p ]\n[ 0 ][ 0 ][ 0 ][ 0 ][ 0 ][ 0 ]\n[ p ][ 1 ][ 0 ][ 1 ][ 1 ][ 0 ]\n[ 0 ][ 0 ][ K ][ 0 ][ 0 ][ 0 ]");
	printf("\n\n4-)\n[ X ][ 1 ][ 1 ][ 0 ][ 0 ][ 0 ]\n[ 0 ][ 0 ][ 0 ][ 0 ][ 1 ][ 0 ]\n[ p ][ 1 ][ 1 ][ P ][ 1 ][ 0 ]\n[ 0 ][ 0 ][ 0 ][ 0 ][ K ][ 0 ]\n[ P ][ 1 ][ 1 ][ p ][ 0 ][ 1 ]\n[ 0 ][ E ][ 0 ][ 0 ][ C ][ 0 ]\n[ 0 ][ 1 ][ 0 ][ 1 ][ 1 ][ 0 ]\n[ 0 ][ e ][ 0 ][ 0 ][ 0 ][ p ]\n[ p ][ 0 ][ 1 ][ 1 ][ 1 ][ 0 ]\n[ 0 ][ 0 ][ K ][ 0 ][ 0 ][ 0 ]");
	printf("\n\n5-)Kendi Labirentinizi Once Satir sayisi bosluk Sutunsayisi alt satirinda inip matris seklinde txt dosyasina yazmis\nprojenin oldugu klasore yuklemisseniz eger bu secenegi tuslayiniz.\n\nSecenek:");
}

char** dosyaAcma(char **Lab,char dosyaismi[MAX],int* N1,int* M1){//Harita.txt sini Lab matrisine aktar�yorum
	FILE *fp;
	int i,j,N,M;
	if ( (fp = fopen(dosyaismi,"r"))==NULL) {
		printf("Dosya acilamadi");
		return 0;
    }
    fscanf(fp,"%d %d",&N,&M);//Text dosyas�n�n ilk iki eleman� boyut bilgisi.
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

void haritayazdirma(char **Lab,int N,int M){//Harita ekrana yazd�rma fonksiyonu
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

void oyunhareketi(char **Lab,int *Xk,int *Yk,int N,int M,int otoormanuel,SAYAC *sayac){//Oyun kurallar�n� uygulay�p oyun i�i hareketi sa�l�yorum.
	int tus,flag,g=0,i,Xilkdeger=*Xk,Yilkdeger=*Yk,delikKontrol,Xyenideger,Yyenideger,rasgelesayi,oyunSuresi=100;//Oyun s�resini 100 saniye olarak belirledim istenildi�i gibi de�i�tirilebilir.
	time_t baslangicZamani,simdikiZaman;
	if(otoormanuel==1){//otoormanuel de�eri 1 ise manuel 2 ise otomatik.
		flag=1;
	}else if(otoormanuel==2){
		flag=2;
	}
	haritayazdirma(Lab,N,M);//Ekrana haritay� yazd�r�yorum
	for(i=0;i<5;i++){//Oyun ba�larken 5 saniye geri say�m yap�yorum(Ama�:oyun ba�lamadan oyuncunun haz�rlan�p labirenti g�rmesi.)
		printf("%d saniye sonra oyununuz baslayacaktir.\n",5-i);
		sleep(1);
	}
	system("cls");//Ekran� temizliyorum
	haritayazdirma(Lab,N,M);//Ekrana haritay� yazd�r�yorum
	printf("Sureniz basladi.Oyuna baslayabilirsiniz.\n");
	baslangicZamani=time(NULL);//Oyunun ba�lang�� s�resini not al�yorum
    while (flag==1) {//Manuel oynama b�l�m�
        switch (getch()) {//Y�n tu�lar�na g�re oyunadimlari fonksiyonunu �a��r�p bir sonraki ad�ma g�re i�lem yap�yorum.
            case 27://ESC ��k��.
                printf("Cikis yapildi.\n");
                flag=0;
			default:
                switch (getch()) {
                    case 72://Yukar�
                    	Xyenideger=(*Xk)-1;
                    	Yyenideger=(*Yk);
                        delikKontrol=oyunadimlari(Lab,Xk,Yk,Xyenideger,Yyenideger,sayac,N,M);//Fonksiyona eski ve yeni kordinatlar� g�nderiyorum.
                        break;
                    case 80://A�a��
                    	Xyenideger=(*Xk)+1;
                    	Yyenideger=(*Yk);
                        delikKontrol=oyunadimlari(Lab,Xk,Yk,Xyenideger,Yyenideger,sayac,N,M);
                        break;
                    case 75://Sol
                    	Yyenideger=(*Yk)-1;
                    	Xyenideger=(*Xk);
                        delikKontrol=oyunadimlari(Lab,Xk,Yk,Xyenideger,Yyenideger,sayac,N,M);
                        break;
                    case 77://Sa�
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
        if(g==0){//ilk de�eri G
        	Lab[Xilkdeger][Yilkdeger]='G';
			g=1;
		}
		if(delikKontrol==0){//Kara delik gelmesi durumu
			flag=0;
		}
		if(delikKontrol==2){//C�k�sa gidilmesi durumu
			flag=0;
		}
        usleep(2000);system("cls");//Ekran� temizliyorum
        haritayazdirma(Lab,N,M);//Ekrana haritay� yazd�r�yorum
		printf("Toplanan atom alti parcaciklar\ne+: %d\nP-: %d\ne-: %d\nP+: %d\n",(*sayac).E,(*sayac).p,(*sayac).e,(*sayac).P);//Toplanan atom alt� par�a��klar hakk�nda bilgi veriyom.
        simdikiZaman=time(NULL);//simdiki zaman� al�p s�reyi kontrol ediyorum.
        if(oyunSuresi<=(simdikiZaman-baslangicZamani)){//S�re bitti mi diye kontrol.
        	(*sayac).E=0,(*sayac).e=0,(*sayac).P=0,(*sayac).p=0;
			printf("Verilen sure icinde bitiremediniz. Kaybettiniz.\n");
        	flag=0;
		}
    }
    srand(time(NULL));//Rasgele de�er se�ip sa�a sola rasgele hareket etmesi i�in otomatik oynat�yorum.
	rasgelesayi=rand();
	while(flag==2){//Otomatik oynatma.
		rasgelesayi*=7;//Her seferinde 7 ile �arp�p sa�a sola yukar� a�a�� rastgele gitmesini sa�l�yorum.
		switch (rasgelesayi%4) {
            case 0://Yukar�
                Xyenideger=(*Xk)-1;
                Yyenideger=(*Yk);
                delikKontrol=oyunadimlari(Lab,Xk,Yk,Xyenideger,Yyenideger,sayac,N,M);//Fonksiyona eski ve yeni x de�erlerini g�nderiyorum.
                break;
            case 1://A�a��
               	Xyenideger=(*Xk)+1;
                Yyenideger=(*Yk);
                delikKontrol=oyunadimlari(Lab,Xk,Yk,Xyenideger,Yyenideger,sayac,N,M);
                break;
            case 2://Sol
                Yyenideger=(*Yk)-1;
                Xyenideger=(*Xk);
                delikKontrol=oyunadimlari(Lab,Xk,Yk,Xyenideger,Yyenideger,sayac,N,M);
                break;
            case 3://Sa�
                Yyenideger=(*Yk)+1;
                Xyenideger=(*Xk);
                delikKontrol=oyunadimlari(Lab,Xk,Yk,Xyenideger,Yyenideger,sayac,N,M);
                break;
            default:
                printf("Bilinmeyen yon tusu\n");
                break;
        }
		if(delikKontrol==2){//C�k�sa gidilmesi durumu
			flag=0;
		}
        sleep(1);system("cls");//Ekran� temizliyorum
        haritayazdirma(Lab,N,M);//Ekrana haritay� yazd�r�yorum
		printf("Toplanan atom alti parcaciklar\ne+: %d\nP-: %d\ne-: %d\nP+: %d\n",(*sayac).E,(*sayac).p,(*sayac).e,(*sayac).P);//Toplanan atom alt� par�a��klar hakk�nda bilgi veriyom.
        simdikiZaman=time(NULL);//simdiki zaman� al�p s�reyi kontrol ediyorum.
        if(oyunSuresi<=(simdikiZaman-baslangicZamani)){//S�re bitti mi diye kontrol.
        	(*sayac).E=0,(*sayac).e=0,(*sayac).P=0,(*sayac).p=0;
			printf("Verilen sure icinde bitiremediniz. Kaybettiniz.\n");
        	flag=0;
		}
	}	
}

int oyunadimlari(char **Lab,int *Xk,int *Yk,int Xyenideger,int Yyenideger,SAYAC *sayac,int N,int M){//Hareket ederken bir sonraki ad�mda bulunan de�ere g�re i�lem yap�yorum.
	if(Xyenideger<0 || Yyenideger<0 || Xyenideger>=N || Yyenideger>=M){//Matristen ��k�p ��kmad���n� kontrol ediyorum.
		printf("\nDuvar!!");
		return 1;
	}
	switch(Lab[Xyenideger][Yyenideger]){//Bir sonraki ad�mdaki de�ere g�re i�lem yap�yorum
		case '0'://Sadece x'i ta��yorum
			Lab[*Xk][*Yk]='0';
			*Xk=Xyenideger;
			*Yk=Yyenideger;
			Lab[*Xk][*Yk]='X';
			break;
		case '1'://X hareket etmiyor
			printf("\nDuvar!!");
			break;
		case 'E'://e+ 'y� 1 artt�r�yorum
			(*sayac).E++;
			Lab[*Xk][*Yk]='0';
			*Xk=Xyenideger;
			*Yk=Yyenideger;
			Lab[*Xk][*Yk]='X';
			
			break;
		case 'e'://e- 'y� 1 artt�r�yorum
			(*sayac).e++;
			Lab[*Xk][*Yk]='0';
			*Xk=Xyenideger;
			*Yk=Yyenideger;
			Lab[*Xk][*Yk]='X';
			break;
		case 'P'://p+ 'y� 1 artt�r�yorum
			(*sayac).P++;
			Lab[*Xk][*Yk]='0';
			*Xk=Xyenideger;
			*Yk=Yyenideger;
			Lab[*Xk][*Yk]='X';
			break;
		case 'p'://p- 'y� 1 artt�r�yorum
			(*sayac).p++;
			Lab[*Xk][*Yk]='0';
			*Xk=Xyenideger;
			*Yk=Yyenideger;
			Lab[*Xk][*Yk]='X';
			break;
		case 'K'://Kara delikse toplad��� t�m elemanlar� s�f�rlay�p oyunu bitiriyorum.
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
			return 2;//��k�� ise oyunu bitiriyorum
			break;
	}
	return 1;//return 1 olan yerlerde oyun devam ediyor.
}

void puanEkleme(PLAYER *players,SAYAC *sayac,int index){//Kar��t proton ve elektronlar� n�trle�tiriyorum sonra k�yaslay�p ka� tane atom olu�turduysa o kadar puan ekliyorum hesab�na.
	if((*sayac).p<(*sayac).P){(*sayac).p=0;} else{(*sayac).p-=(*sayac).P;}//Protonlar� n�trle�tiriyorum
	if((*sayac).E<(*sayac).e){(*sayac).E=0;} else{(*sayac).E-=(*sayac).e;}//Elektronlar� n�trle�tiriyorum
	if((*sayac).E<(*sayac).p){players[index].puan+=(*sayac).E;} else{players[index].puan+=(*sayac).p;}//Atom olu�turuyorum.
}

int kayityazma(PLAYER *players,int kisisayisi){//Son kullan�c� de�erlerini texte yazan fonksiyon.
	FILE *fp;
	int i;
	if ((fp = fopen("kayit_defteri.txt", "wb"))==NULL) {
		printf("Dosya acilamadi");
		return 0;
    }
    for(i=0;i<kisisayisi;i++){//Son de�erleri Texte yaz�yorum.
		fprintf(fp,"%s %s %s %s %d\n",players[i].isim,players[i].soyisim,players[i].kullaniciadi,players[i].sifre,players[i].puan);
	}
	fclose(fp);
	return 1;
}

