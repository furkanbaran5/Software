#include <stdio.h>
#define MAX 50
void cikti(int N, int head, char jobs[MAX][3], int times[MAX][3]) {
    int i,j,current=head;
    while(current!=-1){
        printf("%c ",jobs[current][0]);
        for(i=0;i<times[current][1]-1;i++){
            printf("%c ",jobs[current][0]);
        }
        current=times[current][2];
    }
    printf("\n");
}
int main() {
    int N,i,j,head,times[MAX][3],flag1=1,flag2=1;
    char jobs[MAX][3];
    while(flag1==1){
    	printf("Is Sayisi: ");
	    scanf("%d", &N);
	    if(N>MAX){
	        printf("Hata: Is sayisi maksimum 50 olabilir.\n");
	    }
	    else{
	    	flag1=0;
		}
	}
    for (i = 0; i < N; i++) {
        printf("Is Kodu %d: ",i+1);
      	scanf(" %c",&jobs[i][0]); 
        printf("Is Suresi %d: ", i+1);
        scanf("%d", &times[i][1]);
        printf("Link Sirasi %d: ", i+1);
        scanf("%d", &times[i][2]);
    }
    printf("Head: ");
    scanf("%d",&head);
    printf("Matris:\n");
    for(i=0;i<N;i++){
        printf("%c   %d   %d\n",jobs[i][0],times[i][1],times[i][2]);
    }
    printf("Cikti: ");
    cikti(N,head,jobs,times);
    return 0;
}

