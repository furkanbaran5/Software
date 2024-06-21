#include <stdio.h>
#include <time.h>

int main() {
	
	int D[100][100],N,i,j,k,t,tasiyici,Betulpuan,Aysepuan;
	char Bitis='E';
	

	while(Bitis=='E'||Bitis=='e'){
		printf("Lutfen matrisin boyutunu giriniz:");
		scanf("%d",&N);
		srand(time(NULL));
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				D[i][j]=rand()%(N*N);
			}
		}
			for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				printf("[%d]",D[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
		Betulpuan=0;
		Aysepuan=0;
		t=0;
		for(k=0;k<6;k++){
			for (i=0;i<N/2; i++) {
		        for (j=i;j<N-i-1;j++) {
		            tasiyici=D[i][j];
		            D[i][j]=D[N-j-1][i];
		            D[N-j-1][i]=D[N-i-1][N-j-1];
		            D[N-i-1][N-j-1]=D[j][N-i-1];
		            D[j][N-i-1]=tasiyici;
		        }
		    }
			if(t%2==0){
				for(i=0;i<N;i++){
				Betulpuan+=D[N-1][i];
				t+=1;
				}	
			}
			else{
				for(i=0;i<N;i++){
				Aysepuan+=D[N-1][i];
				t+=1;
				}
			}	
			for(i=0;i<N;i++){
				for(j=0;j<N;j++){
					printf("[%d]",D[i][j]);
				}
				printf("\n");
			}
			printf("\n");	
			printf("Betul:%d    Ayse:%d\n",Betulpuan,Aysepuan);
			printf("\n");
		}	
		if(Betulpuan>Aysepuan){
			printf("Betul kazandi\n\n");
		}
		else{
			if(Betulpuan==Aysepuan){
				printf("Berabere\n\n");
			}
			else{
				printf("Ayse kazandi\n\n");
			}
		}
		printf("Programin devam etmesini istiyorsaniz E veya e ye basiniz baska bir karakter girerseniz program sonlanir");
		scanf(" %c",&Bitis);				
		
	}
	
	
	return 0;
}
