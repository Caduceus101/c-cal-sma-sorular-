//Kendisine parametre olarak verilen metni, metindeki karakterlerin 
//ASCII deðerlerine baðlý olarak büyükten küçüðe Selection Sort algoritmasý 
//kullanarak sýralayýp geri döndüren fonksiyon kodunu yaz



#include <stdio.h>

// Manuel olarak string uzunluðunu hesaplayan fonksiyon
int uzunluk(char *metin) {
    int i = 0;
    // '\0' karakterine ulaþtýðýmýzda döngü biter
    while (metin[i] != '\0') {
        i++;
    }
    return i;
}

// Selection Sort ile ASCII deðerlerine göre büyükten küçüðe sýralama
void siralaASCII(char *metin) {
    int i, j, maxIndex;
    char temp;
    int len = uzunluk(metin);

    // Dizi üzerinde Selection Sort
    for (i = 0; i < len - 1; i++) {
        // i. konum için en büyük ASCII deðere sahip elemaný bulup i. indise yerleþtireceðiz
        maxIndex = i;
        for (j = i + 1; j < len; j++) {
            // Büyükten küçüðe olduðu için metin[j] > metin[maxIndex] kontrolü
            if (metin[j] > metin[maxIndex]) {
                maxIndex = j;
            }
        }
        // Bulunan en büyük karakteri i. pozisyona yerleþtiriyoruz (swap)
        temp = metin[i];
        metin[i] = metin[maxIndex];
        metin[maxIndex] = temp;
    }
}

int main() {
    char metin[100];
    int i = 0;
    printf("Bir metin girin: ");

    // Karakter karakter okuma (Enter'a kadar)
    char ch;
    while ((ch = getchar()) != '\n' && i < 99) {
        metin[i++] = ch;
    }
    // Sonuna null terminator ekleyerek C-string yap
    metin[i] = '\0';

    // Metni Selection Sort ile sýralama
    siralaASCII(metin);

    // Sonucu ekrana yazdýr
    printf("Sýralanmýþ metin (ASCII büyükten küçüðe): %s\n", metin);

    return 0;
}

