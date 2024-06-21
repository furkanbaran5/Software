#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

char **words;//Kelime dizim
int wordCount = 100;//Kelimeler için ilk boyutum.

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
	
	top = (NODE*)malloc(sizeof(NODE));	top->previous=NULL;//ilk stack yapýsýný oluþturuyorum
	
	printf("Please Enter to Source Word: ");	scanf("%s",top->kelime);
	printf("\nPlease Enter to Goal Word: ");	scanf("%s",kelime);
	
	while(top->kelime[sizeSourceWord]!='\0') sizeSourceWord++;//Kelimelerin uzunluðunu hesaplýyorum.
	while(kelime[sizeWord]!='\0') sizeWord++;
	
	words=(char**)calloc(wordCount,sizeof(char*));	for(i=0;i<wordCount;i++){ words[i]=(char*)calloc(MAX,sizeof(char));	}	//Global tanýmladýðým diziye yer ayýrtýyorum.
	
	if(sizeSourceWord!=sizeWord){//Hedef ile kaynak kelimenin uzunluðu eþit deðilse program çalýþmaz.
		printf("\nERROR!!	The source and goal word aren't equal in length.");
	}else{
		front = (QUEUE*)malloc(sizeof(QUEUE));	front->stack = top;	front->next = NULL;//Kuyruk yapýsý için front ve rearý tanýmlýyorum ve ilk stack'i ekliyorum.
		rear = (QUEUE*)malloc(sizeof(QUEUE));	rear=front;	
		
		readDictionary(sizeWord);//Sözlükteki eþit uzunluktaki kelimeleri global diziye aktarýyorum.
		
		print(rear);//ilk stack'i yazdýrýyorum ekrana
		
		while(strcmp(kelime,rear->stack->kelime) && rear!=NULL){//Kelime bulunduysa veya kuyruk boþaldýysa aramayý bitiriyorum.
			searchInWords(&rear->stack,&front,sizeWord);//Kelimeyi arýyorum.
			rear=rear->next;
			//print(rear);
		}
		if(!strcmp(kelime,rear->stack->kelime)){//Kelime varsa yolunu yazdýrýyorum.
			printRoad(rear->stack);
		}
	}
	return 0;
}

void readDictionary(int sizeWord){//Sözlükteki kelimeleri diziye kaydetme fonksiyonu
	FILE *fp;
	int row=0,i,arraySizeControl=0,j,sizeNewWord=0,addArray=0;
	char *geciciKelime;
	
	geciciKelime=(char*)calloc(MAX,sizeof(char));
	
	if((fp = fopen("dictionary.txt" , "r"))==NULL){		printf("Dosya acilamadi");		}
	
	while(!feof(fp)){//Satýr sayýsýný buluyorum
		if(getc(fp)=='\n'){		row++;	}
	}rewind(fp);
	
	for(i=0;i<row;i++){
    	fscanf(fp,"%s",geciciKelime);
    	while(geciciKelime[sizeNewWord]!='\0') sizeNewWord++;
    	
		if(sizeWord==sizeNewWord){//Sözlükteki kaynak kelime ile harf sayýsý ayný olanlarý diziye alýyorum.
			if(addArray>=wordCount){//Aldýðým kelimelerin sayýsý dizinin boyutunu geçerse 100 arttýrýyorum.
				wordCount+=100;
				words=(char**)realloc(words,wordCount*sizeof(char*));
				for(j=wordCount-100;j<wordCount;j++){ words[j]=(char*)calloc(MAX,sizeof(char));	}
			}
			strcpy(words[addArray],geciciKelime);//Aldýðým kelimeyi diziye kopyalýyorum
			addArray++;//Bu deðiþkende aldýðým kelime sayýsýný tutuyorum
		}
		sizeNewWord=0;
    }
	fclose(fp);
}

void print(QUEUE *tmpRear){
	printf("\n--------------QUEUE----------------\n");
	while(tmpRear != NULL){//Kuyruk boþ olana kadar yazdýr.
		printf("\n--------------STACK-------------\n");
		NODE *tmpStack = tmpRear->stack; // Ýkinci bir geçici deðiþken kullanarak orijinal deðeri koruyorum
		while(tmpStack != NULL){//Stack boþ olana kadar yazdýr.
			printf(" <- [%s]", tmpStack->kelime);//Stackteki kelimeleri en alttaki en saðda olacak þekilde yazýyorum
			if(tmpStack->previous == NULL){		tmpStack = NULL;	}//Stack boþaldýysa NULL yapýyorum.aksi takdirde bi alta inip stacki boþaltýyorum.
			else{	tmpStack = tmpStack->previous;	}
		}
		printf("\n--------------------------------\n");
		if(tmpRear->next == NULL){		tmpRear = NULL;		}//Kuyruk boþaldýysa NULL deðilse devam ediyorum.
		else{		tmpRear = tmpRear->next;}	
	}printf("\n\n");
}

void searchInWords(NODE **top,QUEUE **front,int sizeWord){
	int i,j=0,wrongWord=0;
	for(i=0;i<wordCount;i++){
		while(j<sizeWord && wrongWord<2){//Farklý iki harf olmayana kadar ve harf sayýsýný geçmeyene kadar arýyorum.
			if(words[i][j]!=(*top)->kelime[j]){		wrongWord++;	} //Farklý harf oldukça sayacý arttýrýyorum.
			j++;
		}
		if(wrongWord==1){//Sadece 1 tane farklý harf varsa Stack olusturup kuyruða basýyorum.
			NODE *newTop,*node;
			QUEUE *newQueue;
				
			newQueue = (QUEUE*)malloc(sizeof(QUEUE));//Geçiçici kuyruk oluþturuyorum.
			
			newTop = *top;//top deðerini yenisine atýyorum
			
			node = (NODE*)malloc(sizeof(NODE)); //Bir tane düðüm oluþturuyorum.
			strcpy(node->kelime , words[i]);
			node->previous=newTop;
			
			newTop=node;//Yeni Stack oluþturuyorum.
			
			//Kuyruða enqueue ediyorum.	
			newQueue->next=NULL;
			newQueue->stack=newTop;
			(*front)->next=newQueue;
			*front=newQueue;
			
			strcpy(words[i],"xxxxxxxxxxxx");//Kullandýðým kelimeyi dizide deðiþtiriyorum bir daha kullanmamak için.
		}
		j=0;
		wrongWord=0;
	}	
}

void printRoad(NODE *tmpStack){//Bulduðum Stack'i yazdýrýyorum
	printf("[%s]",tmpStack->kelime);
	tmpStack = tmpStack->previous;
	while(tmpStack != NULL){
		printf(" <- [%s]",tmpStack->kelime);
		tmpStack = tmpStack->previous;
	}
}
