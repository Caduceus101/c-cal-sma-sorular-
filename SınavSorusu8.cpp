//pointer aritmetiði kullanarak kullanýcýnýn girdiði 
//sayýlarý tek ve çift olarak iki ayrý diziye ayýrmamýz

#include <stdio.h>
#define MAX_SIZE 100  // Maksimum eleman sayýsý

int main() {
    int sayilar[MAX_SIZE];  // Kullanýcýnýn girdiði tüm sayýlarý tutar.
    int tekler[MAX_SIZE];   // Tek sayýlarý saklayacak dizi.
    int ciftler[MAX_SIZE];  // Çift sayýlarý saklayacak dizi.

    int n;                  // Kaç sayý girileceði.
    int *pSayilar, *pTek, *pCift; // Dizilere eriþimi pointer'lar üzerinden yapacaðýz.
    int tekSayac = 0;       // Kaç adet tek sayý olduðunu tutar.
    int ciftSayac = 0;      // Kaç adet çift sayý olduðunu tutar.

    // Tekler dizisinin baþlangýç adresini pTek'e ata
    pTek = tekler;
    // Çiftler dizisinin baþlangýç adresini pCift'e ata
    pCift = ciftler;

    // Kullanýcýdan kaç sayý gireceðini öðren
    printf("Kaç sayý gireceksiniz? ");
    scanf("%d", &n);

    // Kullanýcýdan n adet sayý girmesini iste
    printf("%d adet sayý girin: \n", n);

    // pSayilar'ý, sayilar dizisinin baþýna iþaret ettir.
    // pSayilar < sayilar + n olduðunda, sayilar dizisinin sonuna kadar ilerlemiþ olur.
    for (pSayilar = sayilar; pSayilar < sayilar + n; pSayilar++) {
        // scanf ile dizinin ilgili konumuna deðer atýyoruz (pointer aritmetiði).
        scanf("%d", pSayilar);
    }

    // Girilen sayýlarý tek ve çift olarak iki ayrý diziye ayýr.
    // Yine pSayilar'ý baþa çekip sayilar dizisini dolaþýyoruz.
    for (pSayilar = sayilar; pSayilar < sayilar + n; pSayilar++) {
        // *pSayilar, dizinin o anki öðesinin deðerini verir.
        if (*pSayilar % 2 == 0) {
            // Eðer sayý çift ise, ciftler dizisine ekliyoruz
            // pCift + ciftSayac, ciftler dizisinin ciftSayac'ýncý konumu
            *(pCift + ciftSayac) = *pSayilar;
            ciftSayac++;  // bir adet çift daha eklenmiþ oldu
        } else {
            // Eðer sayý tek ise, tekler dizisine ekliyoruz
            *(pTek + tekSayac) = *pSayilar;
            tekSayac++;   // bir adet tek daha eklenmiþ oldu
        }
    }

    // Tek sayýlarý yazdýrma
    printf("\nTek sayýlar: ");
    // Diziye pointer üzerinden eriþim: *(pTek + i) -> tekler[i]
    for (int i = 0; i < tekSayac; i++) {
        printf("%d ", *(pTek + i));
    }

    // Çift sayýlarý yazdýrma
    printf("\nÇift sayýlar: ");
    // Diziye pointer üzerinden eriþim: *(pCift + i) -> ciftler[i]
    for (int i = 0; i < ciftSayac; i++) {
        printf("%d ", *(pCift + i));
    }

    printf("\n");
    return 0;  // Programý baþarýyla sonlandýr
}

