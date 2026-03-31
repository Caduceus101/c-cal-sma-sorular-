//Kullanýcýdan en fazla 100 karakterlik bir metin (string) alýn (boþluklu olabilir).
//Yalnýzca pointer aritmetiðini kullanarak bu metni ters çeviren bir fonksiyon yazýn. (Örneðin void tersCevir(char *str) )
//Ters çevrildikten sonra ana fonksiyonda ekrana yazdýrýn.

#include <stdio.h>
#include <string.h>

// Pointer aritmetiðiyle string ters çevirme
void tersCevir(char *str) {
    int len = 0;
    while (*(str + len) != '\0') {
        len++;
    }

    int i = 0;
    int j = len - 1;
    while (i < j) {
        // Swap
        char temp = *(str + i);
        *(str + i) = *(str + j);
        *(str + j) = temp;

        i++;
        j--;
    }
}

int main() {
    char metin[101]; // en fazla 100 karakter + '\0'

    printf("Bir metin girin: ");
    fgets(metin, 101, stdin);

    // \n karakterini silelim (opsiyonel)
    // strcspn, ilk parametredeki metinde "\n"i arar, bulduðu indeksi döndürür.
    metin[strcspn(metin, "\n")] = '\0';

    tersCevir(metin);

    printf("Ters cevrilmis metin: %s\n", metin);

    return 0;
}

