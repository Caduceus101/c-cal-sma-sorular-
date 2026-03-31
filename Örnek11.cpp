//Parametre olarak verilen 32-bit işaretsiz bir tamsayının (unsigned int) ikilik tabandaki (binary) gösteriminde kaç adet '1' biti olduğunu 
//bitsel (bitwise) operatörler kullanarak bulan fonksiyonu yazınız.

#include <stdio.h>

int birBitleriniSay(unsigned int n) {
    int sayac = 0;
    while (n > 0) {
        // Sayının en sağındaki bit 1 mi diye AND (&) işlemiyle kontrol et
        if (n & 1) {
            sayac++;
        }
        // Sayıyı 1 bit sağa kaydır (Bir sonraki biti kontrol etmek için)
        n = n >> 1;
    }
    return sayac;
}

int main() {
    unsigned int sayi = 29; // 29 = 11101 (4 adet 1 var)
    printf("%u sayisindaki 1 bitlerinin sayisi: %d\n", sayi, birBitleriniSay(sayi));
    return 0;
}
