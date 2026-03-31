//Kullanýcýdan iki matris (A ve B) için 3x3 = 9’ar toplam 18 sayý okunur.
//A’nýn sütunlarýný, B’nin satýrlarýna aktarýr ve ortaya “yeni B” (B2) çýkar. Yani B2[i][j] = A[j][i].
//B’nin sütunlarýný, A’nýn satýrlarýna aktarýr ve ortaya “yeni A” (A2) çýkar. Yani A2[i][j] = B[j][i].
//Ortaya çýkan A2 ve B2 matrislerini, degismis.txt dosyasýna yazar.

#include <stdio.h>

// Boyut sabitleri
#define N 3

int main() {
    int A[N][N], B[N][N];     // Orijinal A ve B
    int A2[N][N], B2[N][N];   // Deðiþtirilmiþ A ve B

    // 1) A matrisini oku
    printf("A Matrisini olusturmak icin 9 sayi giriniz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // B matrisini oku
    printf("\nB Matrisini olusturmak icin 9 sayi giriniz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // 2) A’nin sütunlarýný B’nin satýrlarýna = "yeni B" (B2)
    //    B2[i][j] = A[j][i]
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // pointer aritmetiði gösterimi:
            *(*(B2 + i) + j) = *(*(A + j) + i);
        }
    }

    // 3) B’nin sütunlarýný A’nýn satýrlarýna = "yeni A" (A2)
    //    A2[i][j] = B[j][i]
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(*(A2 + i) + j) = *(*(B + j) + i);
        }
    }

    // 4) A2 ve B2 matrislerini degismis.txt dosyasýna yaz
    FILE *fp = fopen("degismis.txt", "w");
    if (!fp) {
        printf("degismis.txt dosyasi acilamadi!\n");
        return 1;
    }

    // A2 matrisini yaz
    fprintf(fp, "---- A2 Matrisi (B'nin sutunlari, A'nin satirlari) ----\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(fp, "%d ", *(*(A2 + i) + j));
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "\n");

    // B2 matrisini yaz
    fprintf(fp, "---- B2 Matrisi (A'nin sutunlari, B'nin satirlari) ----\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(fp, "%d ", *(*(B2 + i) + j));
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    printf("\nMatrizlerin degismis versiyonu 'degismis.txt' dosyasina kaydedildi.\n");
    return 0;
}

