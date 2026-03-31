//Kendisine parametre olarak verilen pozitif bir tamsayının 
//basamaklarındaki rakamların toplamını özyineli (recursive) olarak hesaplayan fonksiyonu yazınız.

#include <stdio.h>

// Sayının basamak toplamını bulan özyineli fonksiyon
int basamakToplami(int n) {
    // Temel durum: Sayı 0'a ulaştığında dur
    if (n == 0) {
        return 0;
    }
    // Son basamağı (n % 10) al ve kalan sayıyı (n / 10) tekrar fonksiyona gönder
    return (n % 10) + basamakToplami(n / 10);
}

int main() {
    int sayi = 1453;
    printf("%d sayisinin basamak toplami: %d\n", sayi, basamakToplami(sayi));
    return 0;
}
