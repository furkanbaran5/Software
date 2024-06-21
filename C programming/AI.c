#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
	char **veriKumesi1, **veriKumesi2,*dataset,*dataset2,**uniondataset,**dictionary,*temp;
	int i,j,dataset1Count,dataset2Count,hotVektorCount,**hotvektor1,**hotvektor2;

	veriKumesi1 = (char**) calloc(2000, sizeof(char*));
	veriKumesi2 = (char**) calloc(2000, sizeof(char*));
	uniondataset = (char**) calloc(2000, sizeof(char*));
	dictionary = (char**) calloc(2000, sizeof(char*));
	hotvektor1 = (char**) calloc(2000, sizeof(char*));
	hotvektor2 = (char**) calloc(2000, sizeof(char*));
	dataset = (char*) calloc(30, sizeof(char*));
	dataset2 = (char*) calloc(30, sizeof(char*));

	for(i=0; i<1000; i++) {
        hotvektor1[i] = (char*) calloc(2000, sizeof(char));
        hotvektor2[i] = (char*) calloc(2000, sizeof(char));
		veriKumesi1[i] = (char*) calloc(2000, sizeof(char));
		veriKumesi2[i] = (char*) calloc(2000, sizeof(char));
		uniondataset[i] = (char*) calloc(2000, sizeof(char));
		dictionary[i] = (char*) calloc(2000, sizeof(char*));
	}
    dataset = "dataset1.txt";
    dataset1Count = fileProgres(veriKumesi1,dataset);
    lowercase(veriKumesi1,dataset1Count);

    dataset2 = "dataset2.txt";
    dataset2Count = fileProgres(veriKumesi2,dataset2);
    lowercase(veriKumesi2,dataset2Count);

    hotVektorCount = unionDataset(veriKumesi1,veriKumesi2,uniondataset,dataset1Count,dataset2Count);
    dictionaryCreate(hotVektorCount,dictionary,uniondataset);

    /*for(i=0;i<hotVektorCount;i++){
        printf("%s ",dictionary[i]);
    }*/
    int sentence = hotVektorCreater(hotVektorCount,dataset,dictionary,hotvektor1);

    for(i=0;i<hotVektorCount;i++){
        for(j=0;j<sentence;j++){
            printf("%d ",hotvektor1[i][j]);
        }
        printf("\n");
    }

    return 0;
}
int unionDataset(char** verikumesi1,char** verikumesi2,char** uniondataset,int veri1,int veri2){
    int i ,j,k, control = 1,result,hotvektoCounter = 0,control2 = 1;

    for(i = 0; i<veri1;i++){
        for(k=i; k<veri1;k++){
            if(strcmp(verikumesi1[k],verikumesi1[i]) == 0 && i != k)
            {
               control = 0;

            }
        }
        if (control == 1){
           for(j=0; j<veri2;j++){
            if(strcmp(verikumesi1[i],verikumesi2[j])==0){
                result = 0;
            }
            }
            if(result == 0)
            {
                uniondataset[hotvektoCounter] = verikumesi1[i];
                hotvektoCounter++;
            }else{
                uniondataset[hotvektoCounter] = verikumesi1[i];
                hotvektoCounter++;
            }
        }
        control = 1;
        result = 1;
    }
    for(i = 0; i<veri2 ; i++){
    control2 =1;
    result = 1;
         for(k=i; k<veri2;k++){
            if(strcmp(verikumesi2[k],verikumesi1[i]) == 0 && i != k)
            {
               control2 = 0;
            }
        }
        if (control2 == 1){
           for(j=0; j<hotvektoCounter;j++){
                if(strcmp(verikumesi2[i],uniondataset[j])==0)
                {
                    result = 0;
                }
            }
            if(result == 0)
            {

            }else{
                uniondataset[hotvektoCounter] = verikumesi2[i];
                hotvektoCounter++;
            }
        }
    }
    return hotvektoCounter;
}

void dictionaryCreate(int dictionarySize,char** dictionary,char** uniondataset){
    char temp[20];
    int i,j;

    for(i=0;i<dictionarySize;i++){
        strcpy(dictionary[i],uniondataset[i]);
    }

     for (i = 0; i < dictionarySize - 1; i++) {
        for (j = 0; j < dictionarySize - 1; j++) {
            if (strcmp(dictionary[j], dictionary[j + 1]) > 0) {
                strcpy(temp, dictionary[j]);
                strcpy(dictionary[j], dictionary[j + 1]);
                strcpy(dictionary[j + 1], temp);
            }
        }
}
}

int fileProgres(char **verikumesi, char *file){
    FILE *dosya = fopen(file, "r");
    char kelime[50],karakter;
    int kelimeIndex = 0,i=0,j;
    if (dosya == NULL) {
        printf("File Open Error!\n");
        return 0;
    }

    while ((karakter = fgetc(dosya)) != EOF) {
        if (isalnum(karakter)) {
            kelime[kelimeIndex++] = karakter;
        } else if (kelimeIndex > 0) {

            strcpy(verikumesi[i],kelime);
            i++;
            for( j = 0 ; j< kelimeIndex ; j++)
            {
                kelime[j] = '\0';
            }
            kelimeIndex = 0;
        }
    }
    fclose(dosya);
    return i;
}

void lowercase(char** dictionary,int count){
    int i,j;
    for(i=0;i<count;i++)
    {   j=0;
        while(dictionary[i][j] != '\0')
        {
            dictionary[i][j] = tolower(dictionary[i][j]);
            j++;
        }
    }

}

int hotVektorCreater(int dictionarysize,char* file ,char** dictionary,int** hotvektor){

    FILE *dosya = fopen(file, "r");
    char karakter,temp[50];
    int kelimeIndex = 0,j=0,i,index,k;
    if (dosya == NULL) {
        printf("File Open Error!\n");
        return 0;
    }

    while ((karakter = fgetc(dosya)) != EOF) {
        while(karakter != '.'&& karakter != EOF){
            if(isalnum(karakter)){
                temp[kelimeIndex] = karakter;
                kelimeIndex++;
            }
            else if(isalnum(karakter)==0){
                index=findDictionarIndex(dictionary,temp,dictionarysize);
                hotvektor[index][j]=1;
                //printf("%d x\n",j);
                for(k = 0 ; k< kelimeIndex ; k++)
                {
                    temp[k] = '\0';
                }
                 kelimeIndex =0;
            }
            karakter = fgetc(dosya);
        }
        kelimeIndex = 0;
        j++;
    }
    
    fclose(dosya);
    return j;
}

int findDictionarIndex(char** dictionary,char* kelime,int dictionarSize){
    int i=0,lasti = 0;
     for (i = 0; kelime[i] != '\0'; i++) {
        kelime[i] = tolower(kelime[i]);
    }

    for(i=0;i<dictionarSize;i++){
        if(strcmp(dictionary[i],kelime)==0){
                lasti = i;
                //printf("%s",dictionary[i]);
                //printf("%s\n",kelime);
            return i;
        }
    }
    return lasti;
}
void calculateGradientDescent(int **featureMatrix, int labelVector[], int featureVectorSize, int dataCount, float weights[], float alpha, int epochs){
    int i, j, k;
    int correct;
    float gradient;
    int predictedLabel;

    for(k=0; k<epochs; k++){
        correct = 0;
        for(i=0; i<dataCount; i++){
            predictedLabel = 0;
            for(j=0; j<featureVectorSize; j++){
                predictedLabel += featureMatrix[i][j] * weights[j];
            }

            predictedLabel = predictedLabel > 0 ? 1 : -1;
            correct += labelVector[i] == predictedLabel;

            for(j=0; j<featureVectorSize; j++){
                gradient = labelVector[i] * featureMatrix[i][j];
                weights[j] = weights[j] - alpha * gradient;
            }
        }

        printf("Epoch: %d Correct: %d/%d\n", k+1, correct, dataCount);
    }
}
