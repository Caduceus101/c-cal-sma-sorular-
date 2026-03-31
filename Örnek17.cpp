//Kullanıcının gireceği boyutlarda (NXM) dinamik bir 2 boyutlu matris oluşturun. 
//Matrisi rastgele sayılarla doldurduktan sonra, her bir sütunun toplamını ayrı bir tek boyutlu dinamik diziye atayan ve ekrana yazdıran programı yazınız.C

#include <stdio.h>
#include <stdlib.h>

int main() {
    int satir = 3, sutun = 4;
    
    // 2 Boyutlu Dinamik Matris Oluşturma
    int **matris = (int**)malloc(satir * sizeof(int*));
    for (int i = 0; i < satir; i++) {
        matris[i] = (int*)malloc(sutun * sizeof(int));
    }
    
    // Sütun toplamları için dinamik dizi
    int *toplamlar = (int*)calloc(sutun, sizeof(int)); // calloc ile 0'a eşitlendi
    
    // Matrisi doldur ve sütun toplamlarını hesapla
    printf("Matris:\n");
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            matris[i][j] = i + j; // Örnek doldurma
            toplamlar[j] += matris[i][j]; // Sütun indeksine (j) ekle
            printf("%d\t", matris[i][j]);
        }
        printf("\n");
    }
    
    printf("\nSutun Toplamlari:\n");
    for (int j = 0; j < sutun; j++) {
        printf("Sutun %d: %d\n", j, toplamlar[j]);
    }
    
    // Bellek temizliği
    for (int i = 0; i < satir; i++) free(matris[i]);
    free(matris);
    free(toplamlar);
    
    return 0;
}
