#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct node{
	char *address;
	int count;
	struct node *prev;
	struct node *next;
}NODE;

void createFirstNode(NODE **head);
void printNode(NODE *head);
void NewInput (NODE **head,int *exit,int T);
void clearNodes(NODE *head);
NODE* searchNode (NODE **head,char *searchAddress,int T);
NODE *moveToTheHead(NODE *head,NODE *tmpNode);
NODE *createNode (NODE* head,char* girilecekKelime,int boyut);
int countNodeFunction(NODE *head);
void deleteNode(NODE *head);
void readText(NODE **head,int T,int L);

int main(int argc, char *argv[]) {
	int T=5,L=4,exit=1,flag=1;
	NODE *head;
	char choice;
	printf("Please enter the threshold value of the count: ");
	scanf("%d",&T);
	printf("\nPlease enter length of Nodes: ");
	scanf("%d",&L);
	while(flag==1){
		printf("\nDo you want to read the addresses from text or enter them manually? Enter 'T' for Text and 'M' for manual.");
		scanf(" %c",&choice);
		
		if(choice=='M'){
			createFirstNode(&head);// ilk düðümü oluþturma fonksiyonu
			while(exit==1){
				//Node'larýmý yazacak fonksiyonu çaðýrýyorum
				printNode(head);
				//Yeni girdi alacak fonksiyonu çaðrýyorum
				NewInput(&head,&exit,T);
				//Node sayým eþik deðerini geçmiþse sondakini siliyorum.
				if(countNodeFunction(head)>L){
					deleteNode(head);
				}
			}
			flag=0;
		}
		else if(choice=='T'){//Textten okuma
			readText(&head,T,L);
			flag=0;
		}
		else{
			printf("\nUndefined character");
		}
	}
	
	printf("\n\nSystem closed.");
	printNode(head);
	clearNodes(head);
	return 0;
}

void readText(NODE **head,int T,int L){
	FILE *fp;
	NODE *node;
	int row=0,i,boyut=0;
	char *geciciKelime;
	
	geciciKelime=(char*)calloc(MAX,sizeof(char));
	*head = (NODE*)malloc(sizeof(NODE));
	
	if((fp = fopen("dosya.txt" , "r"))==NULL){
		printf("Dosya acilamadi");
	}
	while(!feof(fp)){//Satýr sayýsýný buluyorum
		if(getc(fp)=='\n'){
			row++;
		}
	}rewind(fp);
	
	(*head)->address=(char*) calloc (MAX,sizeof(char));
	fscanf(fp,"%s",geciciKelime);
	strcpy((*head)->address, geciciKelime);
	(*head)->count=1;	(*head)->next=NULL;	(*head)->prev=NULL;
	
	for(i=0;i<row-1;i++){
		printNode(*head);
    	fscanf(fp,"%s",geciciKelime);
    	while(geciciKelime[boyut]!='\0') boyut++;
    	node = searchNode(head,geciciKelime,T);//istenilen düðümün varlýðýný kontrol ediyorum
		if(node==NULL){//Düðüm yoksa yeni bir tane oluþturuyorum
			*head = createNode(*head,geciciKelime,boyut);
		}
		if(countNodeFunction(*head)>L){
			deleteNode(*head);
		}
		boyut=0;
    }
    free(node);	
    free(geciciKelime);
	fclose(fp);
}

void createFirstNode(NODE **head){
	int boyut=0;
	char *girilecekKelime;
	girilecekKelime=(char*)calloc(MAX,sizeof(char));
	printf("Please Input The Address: ");
	scanf("%s",girilecekKelime);
	while(girilecekKelime[boyut]!='\0') boyut++;
	(*head) = (NODE*) malloc (sizeof(NODE));
	(*head)->address=(char*)calloc(boyut,sizeof(char));
	strcpy((*head)->address,girilecekKelime);
	(*head)->count=1;(*head)->prev=NULL;(*head)->next=NULL;
	free(girilecekKelime);
}

void printNode(NODE *head){
	printf("\n\nPlease enter 'Exit' for exit and enter 'Clear' for clearing all nodes.\n\n");
	printf("\t[%s,%d]",head->address,head->count);
	head=head->next;
	while(head!=NULL){
		printf(" <-> [%s,%d]",head->address,head->count);
		head=head->next;
	}
	printf("\n\n");
}

void NewInput (NODE **head,int *exit,int T){
	int boyut=0;
	char *girilecekKelime;
	NODE *node;
	
	girilecekKelime=(char*)calloc(MAX,sizeof(char));
	printf("Please Input The Address: ");
	scanf("%s",girilecekKelime);
	while(girilecekKelime[boyut]!='\0') boyut++;//kelimenin boyuutunu düðüm oluþturduðumda dinamik yapmak için alýyorum.
	
	if(!strcmp(girilecekKelime,"Exit")){//Exit yazýlýrsa program çalýþtýrmayý durduracak
		*exit=0;
		free(girilecekKelime);
	}
	else if(!strcmp(girilecekKelime,"Clear")){//Clear yazýlýrsa 
		clearNodes(*head);//Nodelarý sildirip
		printf("\n\nAll nodes cleared.\n\n");
		NODE *head;
		createFirstNode(&head);//ilk node'u tekrardan oluþturuyorum
	}
	else{//Exit veya Clear yazýlmamasý durumu
		node = searchNode(head,girilecekKelime,T);//istenilen düðümün varlýðýný kontrol ediyorum
		if(node==NULL){//Düðüm yoksa yeni bir tane oluþturuyorum
			*head = createNode(*head,girilecekKelime,boyut);
		}
	}
}

void clearNodes(NODE *head){
	int flag=1;
	NODE *tmpNode;
	while(flag==1){
		if(head->next == NULL){
			flag=0;
		}
		else{
			head=head->next;
		}
	}
	flag=1;
	while(flag==1){
		if(head->prev!=NULL){
			tmpNode=head->prev;
			tmpNode->next=NULL;
			free(head);
		}
		else if(head->prev==NULL){
			free(head);
			flag=0;
		}
		else{
			flag=0;
		}
		head = (NODE*)malloc(sizeof(NODE));
		head=tmpNode;
	}
	free(tmpNode);
}

NODE* searchNode (NODE **head,char *searchAddress,int T){
	int flag=1;
	NODE *tmpNode;	
	tmpNode=*head;
	while(flag==1){
		if(!strcmp(tmpNode->address,searchAddress)){//düðümlerin adresi ile gelen adresi karþýlaþtýrýyorum.
			if(tmpNode->count>=T){//count deðeri eþik deðerini geçerse düðümü baþa taþýyorum.
				*head = moveToTheHead(*head,tmpNode);
			}
			tmpNode->count+=1;//sayacý arttýrýyorum
			flag=0;
		}else if(tmpNode->next==NULL){
			tmpNode=NULL;
			flag=0;
		}else{
			tmpNode=tmpNode->next;
		}
	}
	return tmpNode;
}

NODE *moveToTheHead(NODE *head,NODE *tmpNode){	
	if(tmpNode->next==NULL){
		tmpNode->prev->next=NULL;
	}
	else if(tmpNode->prev==NULL){
		return tmpNode;
	}
	else{
		tmpNode->prev->next=tmpNode->next;
		tmpNode->next->prev=tmpNode->prev;
	}
	tmpNode->next=head;
	tmpNode->prev=NULL;
	head->prev=tmpNode;
	return tmpNode;
}

NODE *createNode (NODE* head,char* girilecekKelime,int boyut){
	NODE *newNode;
	newNode = (NODE*) malloc (sizeof(NODE));	newNode->address=(char*)calloc(boyut,sizeof(char));
	strcpy(newNode->address,girilecekKelime); 	newNode->count=1;
	newNode->next=head;	newNode->prev=NULL;	head->prev=newNode;
	return newNode;
}

int countNodeFunction(NODE *head){
	int countNode=0;
	while(head!=NULL){
		countNode++;
		head = head->next;
	}
	return countNode;
}

void deleteNode(NODE *head){
	int flag=1;
	while(flag==1){
		if(head->next == NULL){
			head->prev->next=NULL;
			free(head);
			flag=0;
		}
		else{
			head=head->next;
		}
	}
}
