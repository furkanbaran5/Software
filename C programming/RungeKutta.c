#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct function{
	int katsayi;
}F;

double fonksiyon(double x,double y,int polinomderece,F *function){
	int i;
	double yturev=0;
	for(i=2;i<polinomderece+3;i++){
		yturev+=(function[i].katsayi*pow(x,(polinomderece-i+2)));
	}
	yturev-=(function[1].katsayi*y);
	yturev/=function[0].katsayi;
	return yturev;
}

double rungeKutta(double h,double *x,double *y,int polinomderece,F *function){
	double k1,k2,k3,k4;
	
	k1=fonksiyon(*x,*y,polinomderece,function);
	k2=fonksiyon((*x+(h/2)),(*y+(k1*h/2)),polinomderece,function);
	k3=fonksiyon((*x+(h/2)),(*y+(k2*h/2)),polinomderece,function);
	k4=fonksiyon((*x+h),(*y+(k3*h)),polinomderece,function);
	*x+=h;
	*y=(*y)+(k1+2*(k2+k3)+k4)*(h/6);
}

int main() {
	int i,polinomderece,iter=0;
	double y,x0,y0,istenilendeger,h,mutlakhata;
	F *function;
	
	printf("Polinomun derecesini giriniz.");
	scanf("%d",&polinomderece);
	function=(F*)calloc(polinomderece,sizeof(F));
	
	printf("\nay'+by=c(x^n)+d(x^(n-1))+.... seklinde fonksiyonun katsayilarini giriniz.\n");
	printf("\n(y') teriminin katsayisini giriniz.");
	scanf("%d",&function[0].katsayi);
	printf("\n(y) teriminin katsayisini giriniz.");
	scanf("%d",&function[1].katsayi);
	for(i=2;i<polinomderece+3;i++){
		printf("\n(X)^%d teriminin katsayisini giriniz.",(polinomderece+2-i));
		scanf("%d",&function[i]);
	}
	
	printf("\n%dy'+%dy=",function[0],function[1]);
	for(i=2;i<polinomderece+2;i++){
		printf(" %d(x^%d) +",function[i].katsayi,(polinomderece+2-i));
	}
	printf(" %d",function[polinomderece+2].katsayi);
	printf("\n\nX,Y,istenilen degeri,h degerini,Y'nin gercek degerini bosluklu halde giriniz:");
	scanf("%lf %lf %lf %lf %lf",&x0,&y0,&istenilendeger,&h,&y);
	
	while(istenilendeger>x0){
		iter++;
		rungeKutta(h,&x0,&y0,polinomderece,function);
		printf("\n%d.iter: y(%.2lf)=%lf",iter,x0,y0);
	}
	mutlakhata=(y-y0)/pow(2,iter);
	if(mutlakhata<0){
    	mutlakhata*=-1;
  	}
	printf("\nMutlak Hata: %lf",mutlakhata);
	free(function);
	return 0;
}
