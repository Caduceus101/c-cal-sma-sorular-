//Parametre olarak verilen onluk tabandaki (decimal) bir tamsayıyı 
//ikilik (binary) tabana çevirip doğrudan ekrana yazdıran özyineli (recursive) fonksiyonu yazınız. (Dizi kullanılmayacaktır).

#include <stdio.h>

void ikilikYazdir(int n) {
    // Temel durum: Bölme işlemi 1'den küçük olana kadar devam eder
    if (n > 1) {
        ikilikYazdir(n / 2); // Kalanı bulmadan önce bölümü fonksiyona tekrar yolla
    }
    // Geriye doğru dönerken kalanları ekrana yazdır
    printf("%d", n % 2);
}

int main() {
    int sayi = 45; // 45 -> 101101
    printf("%d sayisinin ikilik karsiligi: ", sayi);
    ikilikYazdir(sayi);
    printf("\n");
    return 0;
}
