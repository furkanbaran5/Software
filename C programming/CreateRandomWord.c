#include <stdio.h>


int main() {
	int n,i,j,a=0,k=0;
	char bitis,tasiyici,D[100];
	printf("Harf sayisi giriniz:");
	scanf("%d",&n);
	while(i<n){
		printf("Harfleri %d. giriniz: ",i+1);
		scanf(" %c", &D[i]);	
		i+=1;
	}
	do{
		a=0;
		do{
			i=0;
			while(i<n){
				printf("%c", D[i]);
				i+=1;
			}
			
			tasiyici=D[0];
			j=0;
			while(j<n){
				D[j]=D[j+1];
				j+=1;
			}
			D[n-1]=tasiyici;
			a+=1;
			printf("\n\n");
		}
		while(a<=n);
		printf("Programin bitmesini istiyorsaniz e ye basiniz ");
		scanf(" %c",&bitis);
		if(bitis=='e' & bitis=='E'){
			k=1;
		}
		
	}
while(k!=1);




	return 0;
}
