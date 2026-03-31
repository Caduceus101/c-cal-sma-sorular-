//Kullanıcının girdiği bir metin (string) içerisindeki 
//yan yana tekrar eden (ardışık) karakterleri pointer aritmetiği kullanarak silen ve metni "in-place" (aynı dizi üzerinde) güncelleyen fonksiyonu yazınız. (Örn: "aabccde" -> "abcde").

#include <stdio.h>

void ardisikTekrarlariSil(char *str) {
    if (*str == '\0') return;

    char *okuyan = str; // Metni gezecek pointer
    char *yazan = str;  // Yeni metni oluşturacak pointer

    while (*okuyan != '\0') {
        // Eğer okunan karakter bir sonraki karakterden farklıysa yaz
        if (*okuyan != *(okuyan + 1)) {
            *yazan = *okuyan;
            yazan++;
        }
        okuyan++;
    }
    *yazan = '\0'; // Yeni metnin sonuna NULL karakteri ekle
}

int main() {
    char metin[] = "mmeeerrhhabaaa";
    printf("Orijinal: %s\n", metin);
    ardisikTekrarlariSil(metin);
    printf("Temizlenmis: %s\n", metin);
    return 0;
}
