#include <stdio.h>
#include <stdlib.h>

void randomMatrisGeneration(int **matris,int N,int M,int *capacityOfQueque);
void printMatris(int **matris,int N,int M);
void maxHeapTree (int **matris,int N,int M,int *capacityOfQueque);
int substrictionMatris(int **matris,int N,int M,int *capacityOfQueque,int *endArray,int *endArrayIter);

int main(int argc, char *argv[]) {
	int N,M,i,flag=1,endArrayIter=0;
	int **matris,*capacityOfQueque,*endArray;
	
	printf("Matrisin (NxM) boyutlarini giriniz:\nN=");
	scanf("%d",&N);
	printf("\nM=");
	scanf("%d",&M);
	
	//Bellek ayýrýmý
	capacityOfQueque=(int*)calloc(N,sizeof(int));
	endArray=(int*)calloc(N,sizeof(int));
	matris = (int**) calloc (N,sizeof(int*));
	for(i=0;i<N;i++){
		matris[i] = (int*) calloc (M,sizeof(int));
	}
	
	for(i=0;i<N;i++){//Kuyruk kapasitelerini alma
		printf("%d.Satirin kuyruk kapasitesini giriniz:",i+1);
		scanf("%d",&capacityOfQueque[i]);
	}
	
	randomMatrisGeneration(matris,N,M,capacityOfQueque);//Rastgele matris oluþturma
	printf("\nRastgele olusturulan matris:\n");
	printMatris(matris,N,M);//Matrisi ekrana yazdýrma fonksiyonu
	
	while(flag==1){//Kuyruklar boþalana kadar döndüðüm döngü
		maxHeapTree(matris,N,M,capacityOfQueque);//Her adýmda matrisi MaxHeapTree kuralýný uyguluyorum
		printf("\n---------------------------------\nYeni durum:\n");
		printMatris(matris,N,M);
	
		flag=substrictionMatris(matris,N,M,capacityOfQueque,endArray,&endArrayIter);//En büyük elemaný silme fonksiyonu, eðer tüm kuyruklar boþalýrsa '0' döndürüyorum.
	}
	printf("\nSirasiyla elemanlari tukenen kuyruklar:");
	for(i=0;i<endArrayIter;i++){//Not aldýðým kuyruklarý ekrana yazýyorum
		printf(" %d,",endArray[i]+1);
	}
	
	//Bellek salýmý
	for(i=0;i<N;i++){
		free(matris[i]);
	}
	free(matris);
	free(capacityOfQueque);
	free(endArray);
	return 0;
}

void randomMatrisGeneration(int **matris,int N,int M,int *capacityOfQueque){
	int i,j,*usedNumbers,randomNumber;
	usedNumbers = (int*)calloc((N*M),sizeof(int));
	
	for(i=0;i<N;i++){
		for(j=capacityOfQueque[i];j<M;j++){//Matrisin kullanmadýðým yerlerini -1 yapýyorum
			matris[i][j]=-1;
		}
	}
	srand(time(NULL));
	for(i=0;i<N;i++){
		for(j=0;j<capacityOfQueque[i];j++){
            
			do {//N*M lik dizi açýyorum eðer dizinin randomNumber'ýncý elemaný 0'ise kullanýyorum 1 ise kullanmýyorum.
                randomNumber = rand() % (N * M);
            } while (usedNumbers[randomNumber]);
            
			matris[i][j] = randomNumber;//rastgele sayý atýyorum
            usedNumbers[randomNumber] = 1;//kullandýðým sayýyý 1 yapýyorum
		}
	}
	free(usedNumbers);	
}

void printMatris(int **matris,int N,int M){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%d\t",matris[i][j]);
		}
		printf("\n");
	}
}

void maxHeapTree (int **matris,int N,int M,int *capacityOfQueque){
	int i,j,k,tmp=0,flag;
	for(j=0;j<N;j++){//Matrisin her satýrý için Max-Heap-Tree
		flag=1;
		while(flag==1){//MaxHeapTree þartýný saðlayana kadar dönen döngüm.
			flag=0;
			k=1;
			for(i=0 ; i<capacityOfQueque[j]/2 ; i++){//satýrýn kapasitesi kadar dönüyorum ve maxHeapTree olacak þekilde sýralýyorum.
				if(matris[j][i]<matris[j][k]){
					tmp=matris[j][k];
					matris[j][k]=matris[j][i];
					matris[j][i]=tmp;
					flag=1;
				}
				k++;
				if(matris[j][i]<matris[j][k]){
					tmp=matris[j][k];
					matris[j][k]=matris[j][i];
					matris[j][i]=tmp;
					flag=1;
				}
				k++;
			}
		}
	}
}

int substrictionMatris(int **matris,int N,int M,int *capacityOfQueque,int *endArray,int *endArrayIter){
	int i,maxNumber,maxIter;
	maxNumber=matris[0][0];
	printf("\nKuyruklardan degerleri okunan elemanlar:");
	for(i=0;i<N;i++){
		if(matris[i][0]!=-1){//-1 haricindeki Kuyruklarýn en büyük elemanlarýný yazýyorum.
			printf("%d,",matris[i][0]);
		}
		
		if(matris[i][0]>=maxNumber){//En büyük olaný tutuyorum.
			maxNumber=matris[i][0];
			maxIter=i;
		}
	}
	printf("\nSecilen eleman:%d\n\n",maxNumber);
	if(maxNumber==-1){//En büyük eleman -1 ise döngüyü bitirmek için 0 döndürürüyorum.
		return 0;
	}
	for(i=0;i<capacityOfQueque[maxIter]-1;i++){//En büyük elemanlý kuyruðu sola doðru birer birer aktarýyorum.
		matris[maxIter][i]=matris[maxIter][i+1];
	}
	capacityOfQueque[maxIter]--;//iþlem yaptýðým kuyruðun kapasitesini 1 azaltýyorum iþlem sayýmý azaltmak için
	matris[maxIter][capacityOfQueque[maxIter]]=-1;//iþlem yaptýðým kuyruðun en sonundaki elemanýný -1 yapýyorum
	if(capacityOfQueque[maxIter]==0){//eðer kapasitem 0 olursa kuyruk boþalmýþtýr endArray dizime not alýyorum.
		endArray[*endArrayIter]=maxIter;
		*endArrayIter+=1;
	}
	return 1;
}
