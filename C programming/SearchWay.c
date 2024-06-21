#include <stdio.h>
#define MAX_Boyut 100

int matris[MAX_Boyut][MAX_Boyut];
int yol[MAX_Boyut * 2][2];  
// En fazla yol sayýsý matris boyutunun 2 katý olabilir

void matrisBoyutu(int *boyut) {
    printf("Matrisin boyutunu girin: ");
    scanf("%d", boyut);
}

void matrisElemanlari(int boyut) {
    int i,j;
	printf("Matris elemanlarini girin (acik ise 0 kapali ise 1 giriniz):\n");
    for (i = 0; i < boyut; i++) {
        for (j = 0; j < boyut; j++) {
            scanf("%d", &matris[i][j]);
        }
    }
}

void matrisiYazdir(int boyut) {
    int i,j;
	printf("Matris:\n");
    for (i = 0; i < boyut; i++) {
        for (j = 0; j < boyut; j++) {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}

int yolfonksiyonu(int x, int y, int boyut, int adim) {
    int i;
	if (x == boyut - 1 && y == boyut - 1 && matris[x][y] == 1) {
        yol[adim][0] = x;
        yol[adim][1] = y;
        printf("Guzergah: ");
        for (i = 0; i <= adim; i++) {
            printf("(%d %d)", yol[i][0],yol[i][1]);
        }
        printf("\n");
        return 1;  
    }

    int yolSayisi = 0;

    if (y + 1 < boyut && matris[x][y + 1] == 1) {
        yol[adim][0] = x;
        yol[adim][1] = y;
        yolSayisi += yolfonksiyonu(x, y + 1, boyut, adim + 1);
    }

    if (x + 1 < boyut && matris[x + 1][y] == 1) {
        yol[adim][0] = x;
        yol[adim][1] = y;
        yolSayisi += yolfonksiyonu(x + 1, y, boyut, adim + 1);
    }

    return yolSayisi;
}

int main() {
    int boyut;
    matrisBoyutu(&boyut);
    matrisElemanlari(boyut);
    matrisiYazdir(boyut);

    int toplamYol = yolfonksiyonu(0, 0, boyut, 0);
    printf("Toplam yol sayisi: %d\n", toplamYol);

    return 0;
}
