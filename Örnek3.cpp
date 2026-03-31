//Kullanýcýdan pozitif tamsayýlar okuyarak (örneðin en fazla 20 tane), bunlarý bir diziye yerleþtiren bir program yazýn.
//Daha sonra, pointer aritmetiði kullanarak dizinin elemanlarýný ikiye bölünmüþ þekilde baþka bir diziye aktarýn.
//Yani, örneðin ilk dizideki her elemaný 2’ye bölüp (tam sayý bölmesi) yeni dizide saklayýn.
//Yeni diziyi ekrana yazdýrýn.

#include <stdio.h>

int main() {
    int arr[20];
    int arr2[20];
    int *p = arr;    // arr dizisinin baþlangýç adresi
    int *q = arr2;   // arr2 dizisinin baþlangýç adresi
    
    int n = 0;       // Gerçekte kaç sayý girildi
    int temp;

    printf("Pozitif tam sayýlar giriniz (0 veya negatif girince bitiyor):\n");

    // En fazla 20 tane okuyalým
    while (1) {
        if (n >= 20) break;  // 20'den fazla okuma yok
        scanf("%d", &temp);
        if (temp <= 0) break; 
        // arr dizisinde n. elemana pointer aritmetiði ile eriþ
        *(p + n) = temp;  
        n++;
    }

    // arr'deki her elemaný 2'ye bölerek arr2'ye kopyala
    for (int i = 0; i < n; i++) {
        *(q + i) = *(p + i) / 2;
    }

    // arr2 dizisini ekrana yazdýr
    printf("\nDizinin elemanlari 2'ye bölünmüþ hali:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(q + i));
    }
    printf("\n");

    return 0;
}

