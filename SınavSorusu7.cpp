//kullanýcý metin girecek sonrasýnda kullanýcýdan aranacak 
//bir harf alýnacak kaç tane ve hangi sýrada o harfin metinde 
//oldugunu pointer aritmetiði kullanarak bulan program 


#include <stdio.h>
#define MAX_LEN 100

int main() {
    char metin[MAX_LEN];  // Kullanýcýdan alýnacak metni saklayacak dizi.
    char harf;            // Kullanýcýnýn aradýðý harf.
    char *p = metin;      // 'metin' dizisine iþaret eden bir pointer.
    int pozisyon = 0;     // Metin içindeki karakterlerin indeksini (sýrasýný) tutar.
    int sayac = 0;        // Aranan harfin kaç kez bulunduðunu sayar.

    // Kullanýcýdan bir metin girmesini iste.
    // 'fgets' ile satýr sonuna kadar okur, en fazla MAX_LEN-1 karakter + '\0' ekler.
    printf("Bir metin girin: ");
    fgets(metin, MAX_LEN, stdin);

    // Kullanýcýdan aramak istediði bir harfi girmesini iste.
    // " %c" formatý, önceki scanf/fgets'ten kalan '\n' gibi boþluk karakterlerini yok saymak için kullanýlýr.
    printf("Aranacak harfi girin: ");
    scanf(" %c", &harf);

    printf("\n'%c' harfi þu konumlarda bulundu: ", harf);

    // Pointer 'p' ile metnin baþýndan '\0' karakterine kadar döngü oluþturuyoruz.
    // Bu sayede *p (yani p'nin iþaret ettiði karakter) üzerinden metnin her karakterine eriþilebilir.
    while (*p != '\0') {
        // *p, dizideki mevcut karakter. Eðer aradýðýmýz harfse, pozisyonu ekrana basar ve sayacý artýrýr.
        if (*p == harf) {
            printf("%d ", pozisyon);
            sayac++;
        }
        // Sonraki karaktere geçmek için pointer'ý bir artýrýrýz (p++)
        // Ayný zamanda pozisyon deðerini de bir artýrýrýz.
        p++;
        pozisyon++;
    }

    // Aranan harfin toplam kaç kez bulunduðunu ekrana yaz.
    printf("\nToplam %d adet '%c' harfi bulundu.\n", sayac, harf);

    return 0;  // Programý baþarýyla sonlandýr.
}

