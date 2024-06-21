#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int diziAl(char **geciciDizi,int boyut,int *satirSayisi){
	int i;
	for(i=0;i<satirSayisi; i++){
		printf("%d. Kelimeyi giriniz:",i+1);
		scanf("%s", *(geciciDizi + i));
		
		if(strlen(*(geciciDizi+i))>boyut){
			boyut=strlen(*(geciciDizi+i));
		}
	}
	return boyut;
}
void diziYaz(char **alinacakDizi,int boyut,int satirSayisi){
	int i,j;
	for(i=0;i<satirSayisi; i++){
		for(j=0;j<boyut; j++){
			if(alinacakDizi[i][j]==0)
				alinacakDizi[i][j]='*';
			printf("%c",alinacakDizi[i][j]);
		}
		printf("\n");
	}
}
int main() {
	char **alinacakDizi,**geciciDizi;
	int i,satirSayisi,boyut=0;
	do{
		printf("Kelime sayisini maximum 50 kelime olacak sekilde giriniz:");
		scanf("%d",&satirSayisi);
	}while(satirSayisi>50);
	
	alinacakDizi = (char **)malloc(satirSayisi * sizeof(char *));
	
	geciciDizi = (char**)calloc(satirSayisi, sizeof(char*));
    
	for (i = 0; i < satirSayisi; i++)
        geciciDizi[i] = (char*)calloc(50, sizeof(char));
	
	boyut = diziAl(geciciDizi,boyut,satirSayisi);
	
	for (i = 0; i < satirSayisi; i++)
        alinacakDizi[i] = (char*)calloc(boyut, sizeof(char));
	
	for(i=0;i<satirSayisi; i++){
		*(alinacakDizi+i)=*(geciciDizi+i);
	}
	free(geciciDizi);
	diziYaz(alinacakDizi,boyut,satirSayisi);		
	return 0;
}
