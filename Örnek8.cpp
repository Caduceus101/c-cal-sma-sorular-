//Kullanýcýdan 9 sayý alýp matrise atama,
//Her satýrýn ve her sütunun toplamýný pointer aritmetiði kullanarak hesaplama,
//Ardýndan matrisi yerinde (in-place) transpoze (satýr-sütun takasý) etme,
//Tekrar satýr ve sütun toplamlarýný yazdýrma

#include <stdio.h>

// 3x3 matris boyutlarý
#define N 3

// Yardýmcý fonksiyon: In-place Transpoze
// mat[i][j] ile mat[j][i]'yi yer deðiþtirir
void transpose3x3(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // pointer aritmetiði -> *(*(mat + i) + j)  matriste [i][j]
            int temp = *(*(mat + i) + j);
            *(*(mat + i) + j) = *(*(mat + j) + i);
            *(*(mat + j) + i) = temp;
        }
    }
}

// Yardýmcý fonksiyon: 3x3 matrisin satýr ve sütun toplamlarýný yazdýr
void printSums(int mat[N][N]) {
    // Satýr toplamlarý
    for (int i = 0; i < N; i++) {
        int satirToplam = 0;
        for (int j = 0; j < N; j++) {
            satirToplam += *(*(mat + i) + j);
        }
        printf("%d. satir toplami = %d\n", i + 1, satirToplam);
    }

    // Sütun toplamlarý
    for (int j = 0; j < N; j++) {
        int sutunToplam = 0;
        for (int i = 0; i < N; i++) {
            sutunToplam += *(*(mat + i) + j);
        }
        printf("%d. sutun toplami = %d\n", j + 1, sutunToplam);
    }
}

int main() {
    int mat[N][N];

    // 1) Kullanýcýdan 9 sayý alarak 3x3 matrise atama
    printf("3x3 matris icin 9 sayi giriniz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // 2) Pointer kullanarak her satir ve sütun toplamini ekrana yazdirma
    printf("\n--- Orijinal Matris ---\n");
    // Orijinal matrisi ekrana basalým (isteðe baðlý)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", *(*(mat + i) + j));
        }
        printf("\n");
    }

    printf("\nOrijinal Matrisin Satir ve Sutun Toplamlari:\n");
    printSums(mat);

    // 3) Matrisi in-place transpoze et (satir-sutun yer degistir)
    transpose3x3(mat);

    // 4) Transpoze sonrasi matris ve toplamlari ekrana yazdir
    printf("\n--- Transpoze Edilmis Matris ---\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", *(*(mat + i) + j));
        }
        printf("\n");
    }

    printf("\nTranspoze Matrisin Satir ve Sutun Toplamlari:\n");
    printSums(mat);

    return 0;
}

