//32-bit işaretsiz bir tamsayının 
//(unsigned int) tek sıradaki bitleri ile çift sıradaki bitlerinin yerlerini (0. bit ile 1. biti, 2. ile 3. biti vb.) kendi aralarında değiştiren fonksiyonu bitsel maskeleme (bitwise masking) ile yazınız.

#include <stdio.h>

unsigned int tekCiftBitleriDegistir(unsigned int n) {
    // Çift bitleri (0, 2, 4...) almak için maske: 0x55555555 (01010101...)
    // Tek bitleri (1, 3, 5...) almak için maske: 0xAAAAAAAA (10101010...)
    
    unsigned int cift_bitler = n & 0x55555555;
    unsigned int tek_bitler = n & 0xAAAAAAAA;
    
    // Çift bitleri 1 sola, tek bitleri 1 sağa kaydır ve OR (|) ile birleştir
    return (cift_bitler << 1) | (tek_bitler >> 1);
}

int main() {
    unsigned int sayi = 23; // 23 -> 00010111
    unsigned int sonuc = tekCiftBitleriDegistir(sayi); // Sonuc -> 00101011 (43)
    printf("Orijinal: %u, Degistirilmis: %u\n", sayi, sonuc);
    return 0;
}
