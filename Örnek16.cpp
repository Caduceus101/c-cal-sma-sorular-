//metin.txt adlı dosyayı okuyup, içerisindeki büyük/küçük harf ayrımı 
//yapmaksızın sesli harflerin (a, e, i, o, u) toplam sayısını bulup sonucu sonuc.txt dosyasına yazan programı yazınız.

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fpOku = fopen("metin.txt", "r");
    FILE *fpYaz = fopen("sonuc.txt", "w");
    
    if (fpOku == NULL || fpYaz == NULL) {
        printf("Dosya hatasi!\n");
        return 1;
    }
    
    int sesliSayaci = 0;
    char c;
    
    // Dosyanın sonuna (EOF) gelene kadar karakter karakter oku
    while ((c = fgetc(fpOku)) != EOF) {
        c = tolower(c); // Küçük harfe çevir
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            sesliSayaci++;
        }
    }
    
    fprintf(fpYaz, "Toplam sesli harf sayisi: %d\n", sesliSayaci);
    
    fclose(fpOku);
    fclose(fpYaz);
    return 0;
}
