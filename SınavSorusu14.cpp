//klavyeden okunan 100 elemanlý tamsayý dizisini kullanarak 
//ilk eleman hariç olmak üzere bir önceki elemandan daha büyük 
//deðere sahip elemanlarý dinamik olarak oluþturacaðýnýz baþka 
//bir diziye pointer aritmetiði kullanarak aktaran program kodu


#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main() {
    // 1) Orijinal dizimiz (statik)
    int dizi[SIZE];
    
    // 2) Bu diziyi iþaret edecek bir pointer
    int *p = dizi;
    
    // 3) Dinamik olarak oluþturduðumuz yeni dizi
    //    En fazla 99 eleman kullanabilir çünkü ilk eleman hariç
    //    diðerlerini karþýlaþtýrýyoruz.
    int *yeniDizi = (int *)malloc(SIZE * sizeof(int));
    
    // Yeni dizide dolduracaðýmýz konumu tutan pointer
    int *q = yeniDizi;
    
    // Yeni diziye kaç eleman eklendiðini sayacak sayaç
    int sayac = 0;

    // 4) Kullanýcýdan 100 adet tamsayýyý okuyup 'dizi'ye atýyoruz
    printf("Lütfen %d adet tamsayý girin:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        // p + i, dizi[i]'yi ifade eder
        scanf("%d", p + i);
    }

    // 5) Bir önceki elemandan büyük olan elemanlarý yeniDizi'ye aktar
    //    i=1'den baþlayarak (ilk elemaný atlýyoruz, çünkü onu karþýlaþtýrma yapamýyoruz)
    for (int i = 1; i < SIZE; i++) {
        // *(p + i) -> dizi[i], *(p + i - 1) -> dizi[i-1]
        if (*(p + i) > *(p + i - 1)) {
            // *(q + sayac) -> yeniDizi[sayac]
            *(q + sayac) = *(p + i);
            sayac++;
        }
    }

    // 6) Yeni dizide biriken elemanlarý ekrana yazdýr
    printf("\nBir önceki elemandan büyük olan elemanlar (%d adet):\n", sayac);
    for (int i = 0; i < sayac; i++) {
        // *(q + i) -> yeniDizi[i]
        printf("%d ", *(q + i));
    }
    printf("\n");

    // 7) Dinamik bellek boþaltýlýr
    free(yeniDizi);

    return 0;
}

