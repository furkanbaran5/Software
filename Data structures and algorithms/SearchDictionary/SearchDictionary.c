#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

char **words;//Kelime dizim
int wordCount = 100;//Kelimeler i�in ilk boyutum.

typedef struct node{
	char kelime[MAX];
	struct node *previous;
}NODE;

typedef struct queue{
	NODE *stack;
	struct queue *next;
}QUEUE;

void readDictionary(int sizeWord);
void print(QUEUE *tmpRear);
void searchInWords(NODE **top,QUEUE **front,int sizeWord);
void printRoad(NODE *tmpStack);

int main(int argc, char *argv[]) {
	char kelime[MAX];		int i,sizeWord=0,sizeSourceWord=0;
	QUEUE *rear,*front;		NODE *top;
	
	top = (NODE*)malloc(sizeof(NODE));	top->previous=NULL;//ilk stack yap�s�n� olu�turuyorum
	
	printf("Please Enter to Source Word: ");	scanf("%s",top->kelime);
	printf("\nPlease Enter to Goal Word: ");	scanf("%s",kelime);
	
	while(top->kelime[sizeSourceWord]!='\0') sizeSourceWord++;//Kelimelerin uzunlu�unu hesapl�yorum.
	while(kelime[sizeWord]!='\0') sizeWord++;
	
	words=(char**)calloc(wordCount,sizeof(char*));	for(i=0;i<wordCount;i++){ words[i]=(char*)calloc(MAX,sizeof(char));	}	//Global tan�mlad���m diziye yer ay�rt�yorum.
	
	if(sizeSourceWord!=sizeWord){//Hedef ile kaynak kelimenin uzunlu�u e�it de�ilse program �al��maz.
		printf("\nERROR!!	The source and goal word aren't equal in length.");
	}else{
		front = (QUEUE*)malloc(sizeof(QUEUE));	front->stack = top;	front->next = NULL;//Kuyruk yap�s� i�in front ve rear� tan�ml�yorum ve ilk stack'i ekliyorum.
		rear = (QUEUE*)malloc(sizeof(QUEUE));	rear=front;	
		
		readDictionary(sizeWord);//S�zl�kteki e�it uzunluktaki kelimeleri global diziye aktar�yorum.
		
		print(rear);//ilk stack'i yazd�r�yorum ekrana
		
		while(strcmp(kelime,rear->stack->kelime) && rear!=NULL){//Kelime bulunduysa veya kuyruk bo�ald�ysa aramay� bitiriyorum.
			searchInWords(&rear->stack,&front,sizeWord);//Kelimeyi ar�yorum.
			rear=rear->next;
			//print(rear);
		}
		if(!strcmp(kelime,rear->stack->kelime)){//Kelime varsa yolunu yazd�r�yorum.
			printRoad(rear->stack);
		}
	}
	return 0;
}

void readDictionary(int sizeWord){//S�zl�kteki kelimeleri diziye kaydetme fonksiyonu
	FILE *fp;
	int row=0,i,arraySizeControl=0,j,sizeNewWord=0,addArray=0;
	char *geciciKelime;
	
	geciciKelime=(char*)calloc(MAX,sizeof(char));
	
	if((fp = fopen("dictionary.txt" , "r"))==NULL){		printf("Dosya acilamadi");		}
	
	while(!feof(fp)){//Sat�r say�s�n� buluyorum
		if(getc(fp)=='\n'){		row++;	}
	}rewind(fp);
	
	for(i=0;i<row;i++){
    	fscanf(fp,"%s",geciciKelime);
    	while(geciciKelime[sizeNewWord]!='\0') sizeNewWord++;
    	
		if(sizeWord==sizeNewWord){//S�zl�kteki kaynak kelime ile harf say�s� ayn� olanlar� diziye al�yorum.
			if(addArray>=wordCount){//Ald���m kelimelerin say�s� dizinin boyutunu ge�erse 100 artt�r�yorum.
				wordCount+=100;
				words=(char**)realloc(words,wordCount*sizeof(char*));
				for(j=wordCount-100;j<wordCount;j++){ words[j]=(char*)calloc(MAX,sizeof(char));	}
			}
			strcpy(words[addArray],geciciKelime);//Ald���m kelimeyi diziye kopyal�yorum
			addArray++;//Bu de�i�kende ald���m kelime say�s�n� tutuyorum
		}
		sizeNewWord=0;
    }
	fclose(fp);
}

void print(QUEUE *tmpRear){
	printf("\n--------------QUEUE----------------\n");
	while(tmpRear != NULL){//Kuyruk bo� olana kadar yazd�r.
		printf("\n--------------STACK-------------\n");
		NODE *tmpStack = tmpRear->stack; // �kinci bir ge�ici de�i�ken kullanarak orijinal de�eri koruyorum
		while(tmpStack != NULL){//Stack bo� olana kadar yazd�r.
			printf(" <- [%s]", tmpStack->kelime);//Stackteki kelimeleri en alttaki en sa�da olacak �ekilde yaz�yorum
			if(tmpStack->previous == NULL){		tmpStack = NULL;	}//Stack bo�ald�ysa NULL yap�yorum.aksi takdirde bi alta inip stacki bo�alt�yorum.
			else{	tmpStack = tmpStack->previous;	}
		}
		printf("\n--------------------------------\n");
		if(tmpRear->next == NULL){		tmpRear = NULL;		}//Kuyruk bo�ald�ysa NULL de�ilse devam ediyorum.
		else{		tmpRear = tmpRear->next;}	
	}printf("\n\n");
}

void searchInWords(NODE **top,QUEUE **front,int sizeWord){
	int i,j=0,wrongWord=0;
	for(i=0;i<wordCount;i++){
		while(j<sizeWord && wrongWord<2){//Farkl� iki harf olmayana kadar ve harf say�s�n� ge�meyene kadar ar�yorum.
			if(words[i][j]!=(*top)->kelime[j]){		wrongWord++;	} //Farkl� harf olduk�a sayac� artt�r�yorum.
			j++;
		}
		if(wrongWord==1){//Sadece 1 tane farkl� harf varsa Stack olusturup kuyru�a bas�yorum.
			NODE *newTop,*node;
			QUEUE *newQueue;
				
			newQueue = (QUEUE*)malloc(sizeof(QUEUE));//Ge�i�ici kuyruk olu�turuyorum.
			
			newTop = *top;//top de�erini yenisine at�yorum
			
			node = (NODE*)malloc(sizeof(NODE)); //Bir tane d���m olu�turuyorum.
			strcpy(node->kelime , words[i]);
			node->previous=newTop;
			
			newTop=node;//Yeni Stack olu�turuyorum.
			
			//Kuyru�a enqueue ediyorum.	
			newQueue->next=NULL;
			newQueue->stack=newTop;
			(*front)->next=newQueue;
			*front=newQueue;
			
			strcpy(words[i],"xxxxxxxxxxxx");//Kulland���m kelimeyi dizide de�i�tiriyorum bir daha kullanmamak i�in.
		}
		j=0;
		wrongWord=0;
	}	
}

void printRoad(NODE *tmpStack){//Buldu�um Stack'i yazd�r�yorum
	printf("[%s]",tmpStack->kelime);
	tmpStack = tmpStack->previous;
	while(tmpStack != NULL){
		printf(" <- [%s]",tmpStack->kelime);
		tmpStack = tmpStack->previous;
	}
}
