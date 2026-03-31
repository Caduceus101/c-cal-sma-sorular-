//3x3 boyutunda iki boyutlu bir dizi tanýmlayýn (statik veya dinamik).
//Kullanýcýdan 9 adet sayý alarak bu matrisin elemanlarýna atayýn.
//Ardýndan pointer kullanarak, her satýrýn toplamýný ve her sütunun toplamýný ayrý ayrý hesaplayýp ekrana yazdýrýn.

#include <stdio.h>

int main() {
    int mat[3][3];
    // 3x3 matrisin baþlangýç adresini tutmak istersek:
    // int (*p)[3] = mat; // p, 3 lük satýrlardan oluþan bir matris iþaret edebilir

    // Kullanýcýdan 9 sayý al
    printf("3x3 matris icin 9 sayi girin:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Satir toplamlarini hesapla (pointer aritmetiði ile gösterim)
    for (int i = 0; i < 3; i++) {
        int satirToplam = 0;
        for (int j = 0; j < 3; j++) {
            // mat[i][j] -> *(*(mat + i) + j)
            satirToplam += *(*(mat + i) + j);
        }
        printf("%d. satir toplami = %d\n", i + 1, satirToplam);
    }

    // Sutun toplamlarini hesapla
    for (int j = 0; j < 3; j++) {
        int sutunToplam = 0;
        for (int i = 0; i < 3; i++) {
            sutunToplam += *(*(mat + i) + j);
        }
        printf("%d. sutun toplami = %d\n", j + 1, sutunToplam);
    }

    return 0;
}

