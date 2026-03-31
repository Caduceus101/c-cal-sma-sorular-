//özyinelemeli fonksiyon ile 5 4 3 2 1 yazdýrma 

#include <stdio.h>

// özyinelemeli (recursive) fonksiyon
void yazdir(int n) {
    // Temel durum: n sýfýra ulaþýnca fonksiyondan çýkýlacak
    if (n == 0)
        return;

    // Fonksiyonun her çaðrýsýnda 'n' deðeri ekrana yazdýrýlýr.
    printf("%d ", n);

    // Ardýndan ayný fonksiyonu, n-1 argümanýyla tekrar çaðýrýr.
    yazdir(n - 1);
}

int main() {
    // 5'ten baþlayarak 1'e kadar azalan sayýlarý ekrana yazdýracak.
    yazdir(5);

    printf("\n"); // Satýr sonu
    return 0;
}

