#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void readFromFile(int matris[][MAX], char *fileName){ //Matris okuma
	int i,j,temp;
	FILE *data=fopen(fileName,"r");
	if(!data){
        printf("Dosya Acilamadi!");
		return;
    }
    while(!feof(data)){
        fscanf(data,"%d %d %d\n",&i,&j,&temp);  
		matris[i][j]=temp; 
    }  
  	fclose(data); 
}
void RastgeleMatrix(int matris[][MAX], int N){ //Matris oluþturma
    int i,j,x,y;
	for(i=0;i<N;i++){
        for (j = 0; j < N; j++) {
            matris[i][j]=0;
        }
    }
    srand(time(NULL));
    for (i=1;i<=N;i++){
    	j=0;
		while(j<2){
	    	x=rand()%N;
	    	y=rand()%N;
	    	if(matris[x][y]==0){
	    		matris[x][y]=i;
	    		j++;
			}
		}
	} 
}
void drawBoard(int matris[][MAX], int N){  //Matris yazdýrma
    int i,j,k;
    for (i = 0; i < N; i++){
        printf("\n");
        for (k=0;k<N;k++)
            printf("-------");
        printf("\n");
        for (j=0;j<N;j++){
            if(matris[i][j]!=0){
                printf("  %d   |", matris[i][j]);
			}
            else{
                printf("      |");            	
			}
        }
    }
    printf("\n");
}
int Oyunlar(int matris[][MAX], int N){//Oyun fonksiyonu
    int choice, hamleSayisi = 0,flag=1,i,j,duvarkontrol=0,dogru=1,skor,geriislem,kaynakSatir, kaynakSutun, hedefSatir, hedefSutun,geri,tempMatris[MAX][MAX] = {{0}};
    geriislem=0,skor=0;
	while(choice!=3){//oyun menüsü
        printf("\n--- OYUN MENUSU ---\n1. Manuel Modda Oyna\n2. Otomatik Modda Oyna\n3. Ana Menuye Don\nSeciminizi yapin: ");
        scanf("%d", &choice);
        duvarkontrol=0;
        switch(choice){
            case 1:
				while(flag==1 && duvarkontrol==0){//Manuel modda oynama
                	flag=0;
					printf("Kaynak hucrenin satirini girin: ");
	                scanf("%d", &kaynakSatir);
	                printf("Kaynak hucrenin sutununu girin: ");
	                scanf("%d", &kaynakSutun);
	                printf("Hedef hucrenin satirini girin: ");
	                scanf("%d", &hedefSatir);
	                printf("Hedef hucrenin sutununu girin: ");
	                scanf("%d", &hedefSutun);
	                for (i=0;i<N;i++){//Matrisi geri alabilmek için baþka bir yere kaydetme
                        for (j=0;j<N;j++){
                            tempMatris[i][j]=matris[i][j];
                        }
                    }
	                if(kaynakSatir==hedefSatir){//Dikeyde hareket
	                	if(hedefSutun<kaynakSutun){
	                		for(i=kaynakSutun-1;i>=hedefSutun;i--){
	                			if(matris[kaynakSatir][i]==0 || matris[kaynakSatir][i]==matris[kaynakSatir][kaynakSutun]){
	                				matris[kaynakSatir][i]=matris[kaynakSatir][kaynakSutun];
								}
								else{
									duvarkontrol=1;
								}
							}
						}
	                	else if(hedefSutun>kaynakSutun){
	                		for(i=kaynakSutun+1;i<=hedefSutun;i++){
	                			if(matris[kaynakSatir][i]==0 || matris[kaynakSatir][i]==matris[kaynakSatir][kaynakSutun]){
	                				matris[kaynakSatir][i]=matris[kaynakSatir][kaynakSutun];
								}
								else{
									duvarkontrol=1;
								}
							}
						}
						else if(duvarkontrol==1){
							printf("\nBaska sayi ile eslesti hatali adim");
						}
	                    hamleSayisi++;
	                }
	                else if(kaynakSutun==hedefSutun){//Yatayda hareket
	                	if(hedefSatir<kaynakSatir){
	                		for(i=kaynakSatir-1;i>=hedefSatir;i--){
	                			if(matris[i][kaynakSutun]==0 || matris[i][kaynakSutun]==matris[kaynakSatir][kaynakSutun]){
	                				matris[i][kaynakSutun]=matris[kaynakSatir][kaynakSutun];
								}
								else{
									duvarkontrol=1;
								}
							}
						}
	                	else if(hedefSatir>kaynakSatir){
	                		for(i=kaynakSatir+1;i<=hedefSatir;i++){
	                			if(matris[i][kaynakSutun]==0 || matris[i][kaynakSutun]==matris[kaynakSatir][kaynakSutun]){
	                				matris[i][kaynakSutun]=matris[kaynakSatir][kaynakSutun];
								}
								else{
									duvarkontrol=1;
								}
							}
						}
	                    hamleSayisi++;
	                }
	            	drawBoard(matris,N);
                    printf("\n1. Devam Et\n2. Hamleyi Geri Al\nSeciminizi yapin: ");
                    scanf("%d", &geri);
                    if(geri==2){//geri alma
                        for(i=0;i<N;i++){
                            for(j=0;j<N;j++){
                                matris[i][j]=tempMatris[i][j];
                            }
                        }
                        geriislem+=1;
                    }
                    drawBoard(matris,N);
                    for(i=0;i<N;i++){//Matriste boþ bir göz kaldý mý diye kontrol etme
				        for(j=0;j<N;j++){
				            if(matris[i][j]==0){
				            	flag=1;
							}
				        }
				    }
				}
				if(duvarkontrol==1){//baþka sayýya çarptýðýný kontrol etme
					printf("\nBaska sayi ile eslesti hatali adim. Oyunu Kaybettiniz!!\n");
				}
				if(flag==0){//Oyun doðru çalýþýp çalýþmadýðýný kontrol etme
					for(i=0;i<N;i++){
		                for(j=0;j<N;j++){
		                    if(matris[i][j]!=matris[i+1][j] && matris[i][j]!=matris[i-1][j] && matris[i][j+1]!=matris[i][j] && matris[i][j-1]!=matris[i][j]){
		                        dogru=0;
							}
		                }
		            }
		            if(dogru==1){
		            	printf("Tebrikler Kazandiniz\n");
		            	skor+=(10*N)-(2*hamleSayisi)-(3*geriislem);//Skor fonksiyonu
					}
					else{
						printf("Malesef Kaybettiniz\n");
						skor=skor-(2*hamleSayisi)-(3*geriislem);
					}
				}
                break;
            case 2:
                while (flag == 1){//Otomatik modda oynama
			        flag = 0;
			       	for (i=0;i < N; i++){
			            for (j=0;j<N;j++){
			                if (matris[i][j] != 0){
			                    // Sol yönde hareket
			                    if (j-1>= 0 && matris[i][j-1] == 0){
									matris[i][j - 1] = matris[i][j];
				                    hamleSayisi++;
				                    flag = 1;                    
								}
				                 // Sað yönde hareket
				                else if (j + 1 < N && matris[i][j + 1] == 0){
				                    matris[i][j + 1] = matris[i][j];
				                    hamleSayisi++;
				                    flag = 1;
				                }
				                // Yukarý yönde hareket
				                else if (i - 1 >= 0 && matris[i - 1][j] == 0){
				                    matris[i - 1][j] = matris[i][j];
				                    hamleSayisi++;
				                    flag = 1;
			                    }
			                    // Aþaðý yönde hareket
			                    else if (i + 1 < N && matris[i + 1][j] == 0){
			                        matris[i + 1][j] = matris[i][j];
			                        hamleSayisi++;
			                        flag = 1;
			                    }
			                }
			            }
			        }
			    }
			    drawBoard(matris,N);
                break;
            default:
                printf("Gecersiz bir secim yaptiniz!\n");
                break;
        }
        printf("Hamle sayisi: %d\nSkor: %d\n",hamleSayisi,skor);
    }
    for (i=0;i<N;i++){//Oyun bittikten sonra tahtayý temizlemek
        for (j=0;j<N;j++){
        	matris[i][j]=0;
        }
    }
	return skor;
}
int main(){
    int N,i=0,choice,j,matris[MAX][MAX]={{0}},tekrarolustur=1,puan[MAX]={0};
    char fileName[20],yarismaci[MAX][MAX];
    srand(time(0));
    while(1){
        printf("\n--- ANA MENU ---\n1. Rastgele Matris Olustur\n2. Dosyadan Matris Olustur\n3. Kullanicilarin Skorlarini Goster\n4. Cikis\nSeciminizi yapin: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1://Rastgele matris oluþturma
                tekrarolustur=1;
				printf("Matris boyutunu girin: ");
                scanf("%d", &N);
                while(tekrarolustur==1){
                	RastgeleMatrix(matris, N);
                	drawBoard(matris, N);//matris yazdýrma
                	printf("\nCozumsuz bir matris ise eger 1'e basiniz cozumlu ise 0'a basiniz: "); //Oynamaya uygun matris seçme     
                	scanf("%d",&tekrarolustur);
				}
				printf("\nYarismaci ismini giriniz: ");
				scanf("%s", &yarismaci[i]);
                puan[i]=Oyunlar(matris, N);//Yarýþmacýlarýn puanýný kaydedip oyuna girme
                i++;
                break;
            case 2:
                printf("Dosya adini girin: ");
                scanf("%s", &fileName);
                printf("Matris boyutunu girin: ");
                scanf("%d", &N);
                readFromFile(matris, fileName);        
				drawBoard(matris, N);
                printf("\nYarismaci ismini giriniz: ");
				scanf("%s", &yarismaci[i]);
				puan[i]=Oyunlar(matris, N);
                i++;
                break;
            case 3:
				printf("--- Kullanicilarin Skorlari ---\nYarismaci\t\tPuan\n");
                for(j=0;j<i;j++){
                    printf("%s\t\t\t%d\n", yarismaci[j],puan[j]);
                }              
				break;
            case 4:
                exit(0); // Programdan çýkýþ
            default:
                printf("Gecersiz bir secim yaptiniz!\n");
                break;
        }
    }
    return 0;
}
