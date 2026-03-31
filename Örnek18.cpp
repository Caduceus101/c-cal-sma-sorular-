//sifresiz.txt dosyasındaki her bir karakteri (1 byte), bitsel operatörler kullanarak 3 bit sola dairesel kaydırma (circular left shift) işlemine tabi tutan ve şifrelenmiş verileri 
//sifreli.txt dosyasına yazan programı C dilinde kodlayınız. (Normal sola kaydırmada en soldan düşen bitler kaybolur, dairesel kaydırmada ise bu bitler en sağdan geri eklenmelidir).

#include <stdio.h>

// 8-bit karakter için 3 bit sola dairesel kaydırma işlemi
unsigned char daireselSolaKaydir(unsigned char c) {
    // Normal 3 bit sola kaydır: c << 3
    // Soldan düşecek 3 biti sağa al: c >> (8 - 3) yani c >> 5
    // OR (|) ile birleştir.
    return (c << 3) | (c >> 5);
}

int main() {
    FILE *fpOku = fopen("sifresiz.txt", "rb"); // Binary modda okuma
    FILE *fpYaz = fopen("sifreli.txt", "wb");  // Binary modda yazma
    
    if (fpOku == NULL || fpYaz == NULL) return 1;
    
    int c;
    while ((c = fgetc(fpOku)) != EOF) {
        // Karakteri işaretsiz (unsigned) byte olarak alıp dairesel kaydır
        unsigned char sifreliKarakter = daireselSolaKaydir((unsigned char)c);
        fputc(sifreliKarakter, fpYaz);
    }
    
    fclose(fpOku);
    fclose(fpYaz);
    printf("Dosya dairesel kaydirma ile sifrelendi.\n");
    return 0;
}
