#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct edge{//Kenarlar
	char node1;
	char node2;
	int weight;
}EDGE;

typedef struct wayStack{//Gidiþ yolu stack'i
	char node;
	struct wayStack *previous;
}WAY;

typedef struct queue{//Yollarý tutan kuyruk
	int countGon;
	int totalWeight;
	WAY *stack;
	struct queue *next;
}QUEUE;

typedef struct polygon{//Çokgenleri tutan struct.
	char way[MAX];
	int weight;
}POLYGON;

char *nodes;
int sizeNodes=0;
int countQueue=0;
POLYGON **polygons;
int pI=0;

void searchPolygon(QUEUE *front,EDGE **head,int M);
void addPolygon(QUEUE *front,int weight);
void addQueue(char node,int countGon,int totalWeight,QUEUE **rear,WAY *stack);
EDGE** readText(EDGE **head,int M);
void searchEdge(QUEUE *front,QUEUE **rear,EDGE **head,int M);
void printPolygon();

int main(int argc, char *argv[]) {
	EDGE **head;
	int i,N,M;
	printf("Lutfen Dugum Sayisini giriniz:");
	scanf("%d",&N);
	printf("Lutfen Kenar Sayisini giriniz:");
	scanf("%d",&M);
	
	QUEUE *front,*rear;
	
	polygons = (POLYGON**)malloc(MAX*sizeof(POLYGON*));
	polygons[0]= (POLYGON*)malloc(sizeof(POLYGON));
	
	front=(QUEUE*)malloc(sizeof(QUEUE));
	rear=(QUEUE*)malloc(sizeof(QUEUE));
	
	head=readText(head,M);//Text dosyasýndaki kenarlarý head listesine kaydediyorum.Ayný zamanda düðümleri belirleyip global tanýmladýðým nodes dizisine ekliyorum
	
	for(i=0;i<sizeNodes;i++){//nodes dizisindeki her düðüm için birer stack yapýsý oluþturuyorum
		WAY *tmpStack;
		QUEUE *tmpQueue;
		
		tmpStack=(WAY*)malloc(sizeof(WAY));
		tmpQueue=(QUEUE*)malloc(sizeof(QUEUE));
		
		tmpStack->node=nodes[i];
		tmpStack->previous=NULL;
		
		tmpQueue->stack=tmpStack;
		tmpQueue->next=NULL;
		tmpQueue->countGon=1;
		tmpQueue->totalWeight=0;
		
		if(i==0){front=tmpQueue;}
		
		rear->next=tmpQueue;
		rear=tmpQueue;
		countQueue++;
	}
	
	searchEdge(front,&rear,head,M);//belirlenen düðümden baþka düðüme kenar var mý?

	printPolygon();//Çokgenleri yazan fonksiyon
	
	return 0;
}

EDGE** readText(EDGE **head,int M){//Text dosyasýndaki kenarlarý head listesine kaydediyorum.Ayný zamanda düðümleri belirleyip global tanýmlanan fonksiyon.
	FILE *fp;
	int i,flag,j,k=1;
	
	nodes=(char*)calloc(k,sizeof(char));
	
	if ((fp = fopen("sample.txt", "rb"))==NULL) {//Dosyayý açýyorum.
		printf("Dosya acilamadi");
		return 0;
    }
	head=(EDGE**)malloc(M*sizeof(EDGE*));//head listesi için yer ayýrtýyorum
	for(i=0;i<M;i++){
    	
		head[i]=(EDGE*)malloc(sizeof(EDGE));
    	fscanf(fp," %c %c %d ",&head[i]->node1,&head[i]->node2,&head[i]->weight);//deðerler listeye kaydediliyor
    	
    	flag=1;	j=0;
		while(j<sizeNodes && flag==1){//listedeki düðümleri belirleyip nodes'a ekliyorum
    		if(nodes[j]==head[i]->node1){
    			flag=0;
			}
			j++;
		}
		if(flag==1){
			k++;
			nodes=(char*)realloc(nodes,k*sizeof(char));
			nodes[sizeNodes]=head[i]->node1;
			sizeNodes++;
		}
		
		flag=1; j=0;
		while(j<sizeNodes && flag==1){//Ayný þeyi node2 için tekrarlýyorum.
    		if(nodes[j]==head[i]->node2){
    			flag=0;
			}
			j++;
		}
		if(flag==1){//varsa geçiyorum yoksa ekliyorum.
			k++;
			nodes=(char*)realloc(nodes,k*sizeof(char));
			nodes[sizeNodes]=head[i]->node2;
			sizeNodes++;
		}
    }
	fclose(fp);
	return head;
}

void searchEdge(QUEUE *front,QUEUE **rear,EDGE **head,int M){
	QUEUE *tmpFront=front;
	WAY *stack;
	int i,j,flag;

	for(j=0;j<countQueue;j++){//Kuyruk sayýsý kadar dönüyorum
		stack=tmpFront->stack;
		flag=0;
	
		for(i=0;i<M;i++){//Kenar sayýsý kadar dönüyorum
			
			if(stack->node==head[i]->node1){//Düðüm kenarlardaki herhangi bir düðümle eþleþiyor mu
				WAY *stackCPY = stack;
				
				while(stackCPY!=NULL && flag==0){
				
					if(stackCPY->node==head[i]->node2){	flag=1;	}//Kenarýn düðümü Stack'te bulunuyor mu,bulunuyorsa flag'i 1 yap ve kenarý ekleme
					stackCPY=stackCPY->previous;//Stackte gez
					
				}
				if(flag==0){	addQueue(head[i]->node2,tmpFront->countGon,tmpFront->totalWeight+head[i]->weight,rear,stack);	}//eðer diðer düðüm stackte yoksa addQueue fonksiyonu ile kuyruða yeni stack'i yaz
			}
			else if(stack->node==head[i]->node2){//Yukarýdaki iþlemin simetriði
				WAY *stackCPY = stack;
			
				while(stackCPY!=NULL && flag==0){
					
					if(stackCPY->node==head[i]->node1){	flag=1;	}
					stackCPY=stackCPY->previous;
					
				}
				if(flag==0){	addQueue(head[i]->node1,tmpFront->countGon,tmpFront->totalWeight+head[i]->weight,rear,stack);	}
			}
		}
		
		if(tmpFront->countGon>=3){	searchPolygon(tmpFront,head,M);	}//Kenar sayýsý 3'ü geçerse çokgen oluþturuyor mu diye kontrol et.
		
		tmpFront=tmpFront->next;//Kuyrukta devam et
	}
}

void addQueue(char node,int countGon,int totalWeight,QUEUE **rear,WAY *stack){//Kuyruða yeni stack'i ekle
	QUEUE *newQueue;
	WAY *newStack2;
	newQueue=(QUEUE*)malloc(sizeof(QUEUE));
	newStack2=(WAY*)malloc(sizeof(WAY));
	newStack2->node=node;
	newStack2->previous=stack;
					
	newQueue->stack=newStack2;
	newQueue->countGon=countGon+1;
	newQueue->totalWeight=totalWeight;
	newQueue->next=NULL;
					
	(*rear)->next=newQueue;
	(*rear)=(*rear)->next;
					
	countQueue++;
}

void searchPolygon(QUEUE *front,EDGE **head,int M){
	WAY *tmpStack;
	int i,j,k,flag=0;
	
	tmpStack=front->stack;
	while(tmpStack->previous!=NULL){//Stack'in ilk elemanýný bul
		tmpStack=tmpStack->previous;
	}
	for(k=0;k<M;k++){
		if(front->stack->node==head[k]->node1){// son elemanýn kenarlarýný bulup
			if(tmpStack->node==head[k]->node2){//ilk elemanla baðlantýsý var mý kontrolu
				addPolygon(front,head[k]->weight);//Varsa eðer çokgen oluþtur
			}
		}
		if(front->stack->node==head[k]->node2){//Yukarýdaki iþlemin simetriði
			if(tmpStack->node==head[k]->node1){
				addPolygon(front,head[k]->weight);
			}
		}
	}
}

void addPolygon(QUEUE *front,int weight){
	int i=0,j,flag=0,boyut=-1;
	WAY *tmpStack;
	while(i<pI && boyut<flag){//Verilen çokgen polygons listesinde var mý
		tmpStack=front->stack;
		flag=0;
		boyut=-1;
		while(tmpStack!=NULL){
			j=front->countGon-1;
			while(j>-1){
				if(polygons[i]->way[j]==tmpStack->node){
					flag++;
				}
				j--;
			}
			tmpStack=tmpStack->previous;
			if(flag==front->countGon){
				boyut=flag;
			}
		}
		i++;
	}
	if(flag!=boyut){//polygon listesinde yoksa yeni bir tane oluþtur yeni çokgeni ekle
		j=0;
		
		tmpStack=front->stack;
		while(tmpStack!=NULL){
			polygons[pI]->way[j]=tmpStack->node;
			tmpStack=tmpStack->previous;
			j++;
		}
		polygons[pI]->weight=front->totalWeight;
		polygons[pI]->weight+=weight;
		pI++;
		polygons[pI]= (POLYGON*)malloc(sizeof(POLYGON));
		return;
	}
}

void printPolygon(){//Çokgenleri ekrana yazdýrma.
	int i,j;
	printf("Sekil sayisi: %d\n\n",pI);
	for(i=0;i<pI;i++){
		printf("%d'Gen :",strlen(polygons[i]->way));
		for(j=0;j<strlen(polygons[i]->way);j++){
			printf(" %c -",polygons[i]->way[j]);
			if(j==strlen(polygons[i]->way)-1){
				printf(" %c ",polygons[i]->way[0]);
			}
		}
		printf("\tUzunluk: %d\n\n",polygons[i]->weight);
	}
}

