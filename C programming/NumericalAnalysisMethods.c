#include <stdio.h>
#include <math.h>
#define N 100
void AnaMenu(){
	printf("\n\nQuit: 0\nBisection: 1\nRegula-Falsi: 2\nNewton Raphson: 3\nInverse Matrix: 4\nGauss Elimination: 5\nGauss-Seidel: 6\nNumerical Differentiation: 7\nSimpson's Rule: 8\nTrapezoidal Rule: 9\nGregory-Newton: 10\nChoice: ");	
}
void fonksiyon(double fonks[100],int derece[1]){
	int i,degerlik;
	printf("Polinom kacinci dereceden olacak: ");
	scanf("%d",&derece[0]);
	for(i=derece[0] ; i>=0 ; i--){
		printf("Polinomun %d.dereceden terimli kat sayisini giriniz: ",i);
		scanf("%d",&degerlik);
		fonks[i]=degerlik;
	}
	printf("Function:");
	for(i=derece[0]; i>=0 ; i--){
		if(fonks[i]!=0){
			printf(" + (%.f * x^%d) ",fonks[i],i);
		}
	}
	printf("\n\n");
}
double fonksiyonislem(double x,double fonks[100],int derece[1]){
	int i;
	double f=0;
	//f=1/(1+pow(x,2));  //<-- Trapez yöntemini test etmek için hazýr fonksiyon
	for(i=derece[0]; i>=0 ;i--){
		f+=fonks[i]*pow(x,i);
	}
	return f;
}

void Bisection(double fonks[100],int derece[1]){
	double orta,Durmakriteri=100,baslangic,bitis,epsilon;
	int iteration=0;
	fonksiyon(fonks,derece);
	printf("Baslangic degerini giriniz: ");
	scanf("%lf",&baslangic);
	printf("\nBitis degerini giriniz: ");
	scanf("%lf",&bitis);
	printf("\nEpsilon degerini giriniz: ");
	scanf("%lf",&epsilon);
	
	while(Durmakriteri>epsilon){
		orta=(baslangic+bitis)/2;
		Durmakriteri=fabs(bitis-baslangic)/pow(2,iteration+1);
		iteration+=1;
		printf("\nstart:%lf \nend:%lf \nmid:%lf \nf(start):%lf \nf(end):%lf \nf(mid):%lf \niteration:%d\n",baslangic,bitis,orta,fonksiyonislem(baslangic,fonks,derece),fonksiyonislem(bitis,fonks,derece),fonksiyonislem(orta,fonks,derece),iteration);
		if(fonksiyonislem(baslangic,fonks,derece)*fonksiyonislem(orta,fonks,derece)<0){
			bitis=orta;
		}
		else{
			baslangic=orta;
		}	
	}	
	printf("Bisection yontemine gore sonuc: %f",orta);
}

void Regula_Falsi(double fonks[100],int derece[1]){
	double orta,Durmakriteri=100,baslangic,bitis,epsilon,max_iterations;
	int iteration=0;
	fonksiyon(fonks,derece);
	printf("Baslangic degerini giriniz: ");
	scanf("%lf",&baslangic);
	printf("\nBitis degerini giriniz: ");
	scanf("%lf",&bitis);
	printf("\nEpsilon degerini giriniz: ");
	scanf("%lf",&epsilon);
	while(Durmakriteri>epsilon){
		orta=(baslangic*fonksiyonislem(bitis,fonks,derece)-bitis*fonksiyonislem(baslangic,fonks,derece))/(fonksiyonislem(bitis,fonks,derece)-fonksiyonislem(baslangic,fonks,derece));
		Durmakriteri=fabs(bitis-baslangic)/pow(2,iteration+1);
		iteration+=1;
		printf("\nstart:%lf \nend:%lf \nmid:%lf \nf(start):%lf \nf(end):%lf \nf(mid):%lf \niteration:%d\n",baslangic,bitis,orta,fonksiyonislem(baslangic,fonks,derece),fonksiyonislem(bitis,fonks,derece),fonksiyonislem(orta,fonks,derece),iteration);

		if(fonksiyonislem(baslangic,fonks,derece)*fonksiyonislem(orta,fonks,derece)<0){
			bitis=orta;
		}
		else{
			baslangic=orta;
		}	
	}	
	printf("Regula-Falsi yontemine gore sonuc: %f",orta);
}

double turev(double x,double fonks[100],int derece[1]){
    int i;
    double f=0;
    for(i=derece[0]; i>=0 ;i--){
        if(i!=0){
            f+=i*fonks[i]*pow(x,i-1);
        }
    }
    return f;
}

double Newton_Raphson(double fonks[100], int derece[1]){
    double baslangic,epsilon,max_iterations,h;
    int iteration = 0;
    printf("Baslangic degerini giriniz: ");
    scanf("%lf",&baslangic);
    printf("\nEpsilon degerini giriniz: ");
    scanf("%lf",&epsilon);
    printf("\nMaximum iteration degerini giriniz: ");
    scanf("%lf",&max_iterations);
    while(iteration<max_iterations){
		h=fonksiyonislem(baslangic,fonks,derece)/turev(baslangic,fonks,derece);
        iteration++;
        printf("\nXn:%lf \nXn+1:%lf \nf(Xn):%lf \nf'(Xn):%lf \niteration:%d \n\n",baslangic,baslangic-h,fonksiyonislem(baslangic,fonks,derece),turev(baslangic,fonks,derece),iteration);
		baslangic-=h;
		if(fabs(h)<epsilon){
            printf("iteration: %d\n",iteration);
            return baslangic;
        }
    }
    return baslangic;
}

void matrisTersi() {
    int i,j,k,n;
    double temp,matris[N][N],birimMatris[N][N]={{0}};
    printf("Matrisin boyutunu girin (NxN): ");
    scanf("%d",&n);
    printf("Matris elemanlarini girin:\n");
    for(i=0; i<n ;i++){
        for(j=0; j<n ;j++){
        	printf("[%d][%d]\n",i,j);
            scanf("%lf",&matris[i][j]);
        }
    }
    for(i=0; i<n ;i++){
        birimMatris[i][i]=1;
    }
    for(i=0; i<n ;i++){
    	printf("Matrix:%d\n",i+1);
	    for(j=0; j<n ;j++){
	        for(k=0; k<n ;k++){
	            printf("[%.2lf]",matris[j][k]);
	        }
	        printf("\n");
	    }
	    printf("\n");
        if(matris[i][i]==0){
            printf("Tersi alinamaz.\n");
            return;
        }
        temp=matris[i][i];
        for(j=0; j<n ;j++){
            matris[i][j]/=temp;
            birimMatris[i][j]/=temp;
        }
        for(j=0; j<n ;j++){
            if(j!=i){
                temp=matris[j][i];
                for(k=0; k<n ;k++){
                    matris[j][k]-=matris[i][k]*temp;
                    birimMatris[j][k]-=birimMatris[i][k]*temp;
                }
            }
        }
    }
    printf("Matrisin Tersi:\n");
    for(i=0; i<n ;i++){
        for(j=0; j<n ;j++){
            printf("[%.2lf]",birimMatris[i][j]);
        }
        printf("\n");
    }
}
void gaussEliminasyon() {
    int i,j,k,n;
    double oran,matris[N][N];
	printf("Matrisin boyutunu girin (NxN): ");
    scanf("%d",&n);
    printf("Matris elemanlarini girin:\n");
    for(i=0; i<n ;i++){
        for(j=0; j<n ;j++){
        	printf("[%d][%d]\n",i,j);
            scanf("%lf",&matris[i][j]);
        }
    }
    for(i=0; i<n-1 ;i++){
    	printf("Matrix:%d\n",i+1);
	    for(j=0; j<n ;j++){
	        for(k=0; k<n ;k++){
	            printf("[%.2lf]",matris[j][k]);
	        }
	        printf("\n");
	    }
	    printf("\n");
		if(matris[i][i]==0){
            printf("Gauss eliminasyonu uygulanamaz.\n");
            return;
        }
        for(j=i+1; j<n ;j++){
            oran=matris[j][i]/matris[i][i];
            for(k=i; k<n ;k++){
                matris[j][k]-=oran*matris[i][k];
            }
        }
    }
    printf("Gauss eliminasyonu uygulandiktan sonra matris:\n");
    for(i=0; i<n ;i++){
        for(j=0; j<n ;j++){
            printf("[%.2lf]",matris[i][j]);
        }
        printf("\n");
    }
}
void gaussSeidel(){
    int i,j,iteration=0,flag=0,n,max_iterations=0;
    double matris[N][N],sonuc[N],x[N],y[N],epsilon;
	
	printf("Matrisin boyutunu girin (NxN): ");
    scanf("%d",&n);
    printf("Matris elemanlarini girin:\n");
    for(i=0; i<n ;i++){
        for(j=0; j<n ;j++){
        	printf("[%d][%d]\n",i,j);
        	scanf("%lf",&matris[i][j]);
        }
    }
    printf("Sonuc vektorunu girin:\n");
    for(i=0; i<n ;i++){
        scanf("%lf",&sonuc[i]);
        x[i]=0;
    }
    printf("Epsilon degerini giriniz: ");
    scanf("%lf",&epsilon);
    while(flag==0 && max_iterations<100){
	    max_iterations++;
		iteration++;
		for(i=0; i<n ;i++){
            y[i]=sonuc[i];
            for(j=0; j<n ;j++){
                if(j!=i){
                
                    y[i]-=matris[i][j]*x[j];
                }
            }
            y[i]/=matris[i][i];
            if(fabs(y[i]-x[i])<epsilon){
                flag=1;
            }            
            x[i]=y[i];
        }
    }
    if(max_iterations==100){
    	printf("Iraksiyor");
	}
	else{
		printf("Iteration:%d \nGauss-Seidel yontemine gore sonuc:\n",iteration);
	    for(i=0; i<n ;i++){
	        printf("x%d = %lf\n",i,y[i]);
	    }
	}
}
void Sayisalturev(double fonks[100],int derece[1]) {
	double x,h,merkeziturev,ileriturev,geriturev;
	fonksiyon(fonks,derece);
	printf("Turevini hesaplamak istediginiz noktayi girin: ");
	scanf("%lf",&x);
	printf("Adim boyutunu girin: ");
	scanf("%lf",&h);
    merkeziturev=(fonksiyonislem(x+h,fonks,derece)-fonksiyonislem(x-h,fonks,derece))/(2 * h);
    ileriturev=(fonksiyonislem(x+h,fonks,derece)-fonksiyonislem(x,fonks,derece))/h;
    geriturev=(fonksiyonislem(x,fonks,derece)-fonksiyonislem(x-h,fonks,derece))/h;	    
	printf("Merkezi Farklar Yontemiyle Turev: %.2lf\nIleri Farklar Yontemiyle Turev: %.2lf\nGeri Farklar Yontemiyle Turev: %.2lf\n",merkeziturev,ileriturev,geriturev);
}

void Simpson(double fonks[100],int derece[1]){
    int i,n;
	double h,x,integral2,integral1,a,b;
	fonksiyon(fonks,derece);
	printf("Integralini hesaplamak istediginiz araligi giriniz: ");
	scanf("%lf %lf",&a,&b);
	printf("\nAdim sayisi giriniz: ");
	scanf("%d",&n);
	h=(b-a)/n;
	if(n%2==0){
		integral1=fonksiyonislem(a,fonks,derece)+fonksiyonislem(b,fonks,derece);
	    for(i=1; i<n ;i+=2){
	        x=a+i*h;
	        integral1+=4*fonksiyonislem(x,fonks,derece);
	    }
	    for(i=2; i<n-1 ;i+=2){
	        x=a+i*h;
	        integral1+=2*fonksiyonislem(x,fonks,derece);
	    }
	    integral1*=h/3;
	    printf("Simpson 1-3 kurali: %f \n",integral1);
	}
	else{
		printf("Simpson 1-3 kurali: n sayisi cift olmadigi icin bulunamaz! \n");
	}
	integral2=fonksiyonislem(a,fonks,derece)+fonksiyonislem(b,fonks,derece);
    for(i=1; i<n ;i+=3){
        x=a+i*h;
        integral2+=3*fonksiyonislem(x,fonks,derece);
    }
    for(i=2; i<n ;i+=3){
        x=a+i*h;
        integral2+=3*fonksiyonislem(x,fonks,derece);
    }
    for(i=3; i<n ;i+=3){
		x=a+i*h;
	    integral2+=2*fonksiyonislem(x,fonks,derece);
    }
    integral2*=(3*h)/8;
    printf("Simpson 3-8 kurali: %f \n",integral2);
}
void trapez(double fonks[100],int derece[1]){
    int i;
	double h,toplam,integral,x,a,b,n;
    fonksiyon(fonks,derece);
	printf("Integralin baslangic ve bitis noktasini girin: ");
	scanf("%lf %lf",&a,&b);
	printf("Adim sayisini girin: ");
	scanf("%lf",&n);
    h=(b-a)/n;
    toplam =(fonksiyonislem(a,fonks,derece)+fonksiyonislem(b,fonks,derece))/2;
	for(i=1; i<n ;i++){
		x=a+i*h;
        toplam+=fonksiyonislem(x,fonks,derece);
    }
    integral=h*toplam;
	printf("Sonuc: %f\n",integral);
}

int main() {
	int secenek=100,derece[1];
	double fonks[100];
	while(secenek!=0){
		AnaMenu();
		scanf("%d",&secenek);	
		if(secenek==1){	
			Bisection(fonks,derece);
		}
		if(secenek==2){	
			Regula_Falsi(fonks,derece);
		}
		if(secenek==3){
	        fonksiyon(fonks, derece);
	        printf("Newton-Raphson yontemine gore sonuc: %f", Newton_Raphson(fonks, derece));
	    }
		if(secenek==4){
		    matrisTersi();
		}
		if(secenek==5){
		    gaussEliminasyon();
		}
		if(secenek==6){
		    gaussSeidel();
		}
		if(secenek==7){
			Sayisalturev(fonks,derece);
		}
		if(secenek==8){
			Simpson(fonks,derece);
		}
		if(secenek==9){
			trapez(fonks,derece);
		}
	}
	return 0;
}


