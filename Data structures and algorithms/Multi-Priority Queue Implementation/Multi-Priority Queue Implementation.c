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
	
	//Bellek ay�r�m�
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
	
	randomMatrisGeneration(matris,N,M,capacityOfQueque);//Rastgele matris olu�turma
	printf("\nRastgele olusturulan matris:\n");
	printMatris(matris,N,M);//Matrisi ekrana yazd�rma fonksiyonu
	
	while(flag==1){//Kuyruklar bo�alana kadar d�nd���m d�ng�
		maxHeapTree(matris,N,M,capacityOfQueque);//Her ad�mda matrisi MaxHeapTree kural�n� uyguluyorum
		printf("\n---------------------------------\nYeni durum:\n");
		printMatris(matris,N,M);
	
		flag=substrictionMatris(matris,N,M,capacityOfQueque,endArray,&endArrayIter);//En b�y�k eleman� silme fonksiyonu, e�er t�m kuyruklar bo�al�rsa '0' d�nd�r�yorum.
	}
	printf("\nSirasiyla elemanlari tukenen kuyruklar:");
	for(i=0;i<endArrayIter;i++){//Not ald���m kuyruklar� ekrana yaz�yorum
		printf(" %d,",endArray[i]+1);
	}
	
	//Bellek sal�m�
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
		for(j=capacityOfQueque[i];j<M;j++){//Matrisin kullanmad���m yerlerini -1 yap�yorum
			matris[i][j]=-1;
		}
	}
	srand(time(NULL));
	for(i=0;i<N;i++){
		for(j=0;j<capacityOfQueque[i];j++){
            
			do {//N*M lik dizi a��yorum e�er dizinin randomNumber'�nc� eleman� 0'ise kullan�yorum 1 ise kullanm�yorum.
                randomNumber = rand() % (N * M);
            } while (usedNumbers[randomNumber]);
            
			matris[i][j] = randomNumber;//rastgele say� at�yorum
            usedNumbers[randomNumber] = 1;//kulland���m say�y� 1 yap�yorum
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
	for(j=0;j<N;j++){//Matrisin her sat�r� i�in Max-Heap-Tree
		flag=1;
		while(flag==1){//MaxHeapTree �art�n� sa�layana kadar d�nen d�ng�m.
			flag=0;
			k=1;
			for(i=0 ; i<capacityOfQueque[j]/2 ; i++){//sat�r�n kapasitesi kadar d�n�yorum ve maxHeapTree olacak �ekilde s�ral�yorum.
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
		if(matris[i][0]!=-1){//-1 haricindeki Kuyruklar�n en b�y�k elemanlar�n� yaz�yorum.
			printf("%d,",matris[i][0]);
		}
		
		if(matris[i][0]>=maxNumber){//En b�y�k olan� tutuyorum.
			maxNumber=matris[i][0];
			maxIter=i;
		}
	}
	printf("\nSecilen eleman:%d\n\n",maxNumber);
	if(maxNumber==-1){//En b�y�k eleman -1 ise d�ng�y� bitirmek i�in 0 d�nd�r�r�yorum.
		return 0;
	}
	for(i=0;i<capacityOfQueque[maxIter]-1;i++){//En b�y�k elemanl� kuyru�u sola do�ru birer birer aktar�yorum.
		matris[maxIter][i]=matris[maxIter][i+1];
	}
	capacityOfQueque[maxIter]--;//i�lem yapt���m kuyru�un kapasitesini 1 azalt�yorum i�lem say�m� azaltmak i�in
	matris[maxIter][capacityOfQueque[maxIter]]=-1;//i�lem yapt���m kuyru�un en sonundaki eleman�n� -1 yap�yorum
	if(capacityOfQueque[maxIter]==0){//e�er kapasitem 0 olursa kuyruk bo�alm��t�r endArray dizime not al�yorum.
		endArray[*endArrayIter]=maxIter;
		*endArrayIter+=1;
	}
	return 1;
}
