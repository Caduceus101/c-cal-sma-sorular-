//Kullanýcýdan kaç adet sayý gireceðini sorun (örneðin n). Ardýndan n adet tamsayýyý dinamik olarak oluþturacaðýnýz bir diziye kaydedin.
//Bir özyinelemeli fonksiyon yazarak bu dizideki en büyük sayýyý bulun.
//Bulunan en büyük sayýyý ekrana yazdýrýn.
//Program sonlanmadan önce dinamik belleði free() ile geri verin.

#include <stdio.h>
#include <stdlib.h>

// dizi içerisindeki en büyük sayýyý bulan özyinelemeli fonksiyon
int enBuyukBul(int *arr, int n) {
    // Temel durum
    if (n == 1) {
        return arr[0];
    } else {
        // arr[0] ile geri kalan kýsým arasýnda seçim yap
        int sonrakiBuyuk = enBuyukBul(arr + 1, n - 1);
        return (arr[0] > sonrakiBuyuk) ? arr[0] : sonrakiBuyuk;
    }
}

int main() {
    int n;
    printf("Kac sayi gireceksiniz? ");
    scanf("%d", &n);

    // n elemanlik dinamik dizi
    int *dizi = (int*)malloc(n * sizeof(int));
    if (dizi == NULL) {
        printf("Bellek ayrýlamadý!\n");
        return 1;
    }

    printf("%d adet sayýyý girin:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", dizi + i); 
    }

    int enBuyuk = enBuyukBul(dizi, n);
    printf("En buyuk deger: %d\n", enBuyuk);

    free(dizi); // Dinamik bellek iade

    return 0;
}

