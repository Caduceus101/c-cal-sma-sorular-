//Aynı boyuttaki iki farklı tamsayı dizisini pointer aritmetiği 
//kullanarak dinamik olarak oluşturulmuş üçüncü bir dizide sırayla (bir 1. diziden, bir 2. diziden olacak şekilde) birleştiren programı yazınız.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3;
    int dizi1[] = {1, 3, 5};
    int dizi2[] = {2, 4, 6};
    
    // 2n boyutunda dinamik bellek tahsisi
    int *sonuc = (int*)malloc(2 * n * sizeof(int));
    
    // Pointer'ları başlangıç adreslerine ata
    int *p1 = dizi1;
    int *p2 = dizi2;
    int *pSonuc = sonuc;
    
    // Pointer aritmetiği ile birleştirme
    for (int i = 0; i < n; i++) {
        *pSonuc++ = *p1++; // Dizi1'den eleman al ve pointerları 1 ileri kaydır
        *pSonuc++ = *p2++; // Dizi2'den eleman al ve pointerları 1 ileri kaydır
    }
    
    printf("Birlestirilmis Dizi: ");
    for (int i = 0; i < 2 * n; i++) {
        printf("%d ", *(sonuc + i));
    }
    
    free(sonuc);
    return 0;
}
