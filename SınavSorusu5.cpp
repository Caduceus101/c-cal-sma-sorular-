//kendisine parametre olarak gelen metni 
//yine kendisine parametre olarak gelen deðer kadar 
//karakter temelli right rotated shift ( bitsel deðil ) yapan 
//fonksiyon kodunu pointer aritmetiði kullanarak yaz


#include <stdio.h>   // Standart giriþ-çýkýþ fonksiyonlarý için gerekli kütüphane
#include <string.h>  // strlen fonksiyonu gibi string iþlemleri için gerekli kütüphane

// Saða karakter temelli (bitsel deðil) döndürme fonksiyonu
// Pointer aritmetiði kullanarak, 'str' ifadesini 'n' karakter saða kaydýrýr.
void rightRotateString(char *str, int n) {
    // Metnin uzunluðunu bul (strlen, '\0' karakterine kadar sayar)
    int len = strlen(str);

    // Eðer boþ bir string veya kaydýrma miktarý 0 veya daha az ise, iþlem yapmaya gerek yok
    if (len == 0 || n <= 0) return;

    // n, metnin uzunluðundan büyükse, mod alarak efektif kaydýrma miktarýný buluruz
    n = n % len;

    // Eðer mod iþlemi sonucunda kaydýrma 0 çýkýyorsa, döndürmeye gerek yok
    if (n == 0) return;

    // Geçici dizi: Son n karakteri saklayacaðýz
    // Örneðin, metin "ABCDE", n = 2 ise son 2 karakter ("DE") buraya kopyalanacak.
    char temp[n];

    // 'p' iþaretçisi, metnin son n karakterinin baþlangýç adresini tutar
    // len - n, sondan n karakter kalacak þekilde konumlanýr
    char *p = str + len - n;

    // 1) Son n karakteri 'temp' dizisine kopyala (pointer aritmetiði kullanarak)
    for (int i = 0; i < n; i++) {
        *(temp + i) = *(p + i);
    }

    // 2) Metnin geri kalan kýsmýný (ilk len-n karakter) saða doðru kaydýr
    //    Yani, orijinal dizinin sonundan baþlayarak n'li adýmlarla saða öteleyerek yazacaðýz.
    //    Döngüyü sondan baþa doðru çalýþtýrmak önemli, çünkü aksi halde karakterler üzerine yazýlabilir.
    for (int i = len - 1; i >= n; i--) {
        *(str + i) = *(str + i - n);
    }

    // 3) 'temp' dizisindeki karakterleri metnin baþýna taþý
    //    Çünkü saða kaydýrmadan önce sakladýðýmýz son n karakter, þimdi baþa gelecek.
    for (int i = 0; i < n; i++) {
        *(str + i) = *(temp + i);
    }
}

int main() {
    char str[100];  // Kullanýcýnýn gireceði metin (en fazla 99 karakter + son '\0')
    int shift;      // Kaç karakter saða döndürüleceðini saklayacak deðiþken
    
    printf("Bir metin girin: ");
    // 'scanf("%s", str)' boþluk gördüðünde okumayý býrakýr (çok kelimeli metinlerde sorun).
    // Eðer boþluklu bir metin isteniyorsa, fgets kullanýlabilir.
    scanf("%s", str);

    printf("Kaç karakter saða kaydýrýlsýn? ");
    scanf("%d", &shift);

    // rightRotateString fonksiyonu ile metni shift kadar saða döndür
    rightRotateString(str, shift);

    // Kaydýrma sonucu elde edilen metni ekrana yazdýr
    printf("Kaydýrýlmýþ metin: %s\n", str);

    return 0;  // Programý baþarýyla sonlandýr
}

