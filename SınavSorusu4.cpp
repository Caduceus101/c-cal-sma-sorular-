//kullanýcý tarafýndan girilen 0 ile 255 arasýndaki 4 adet tam sayýyý 
//iþaretsiz integer türünden bir tam sayý içerisine bitsel iþlemler 
//kullanarak yerleþtiren program kodunu yaz


#include <stdio.h>

int main() {
    unsigned int sonuc = 0;    // 32 bitlik iþaretsiz tam sayý
    unsigned char sayilar[4];  // 4 adet 8 bitlik (0-255) sayý saklamak için dizi
    int i;

    // Kullanýcýdan 4 sayý al
    for (i = 0; i < 4; i++) {
        printf("%d. sayýyý girin (0-255): ", i + 1);
        scanf("%hhu", &sayilar[i]);  // %hhu -> unsigned char tipini okumak için

        // Hatalý giriþ kontrolü
        if (sayilar[i] > 255) {
            printf("Hatalý giriþ! 0-255 arasýnda bir sayý girin.\n");
            return 1; // Programý hatalý giriþle sonlandýr
        }
    }

    // Bitsel iþlemlerle sayýlarý 32 bit içerisine yerleþtirme:
    // Not: Burada en büyük indeks (sayilar[0]) en sol (üst) bayta, 
    //      en küçük indeks (sayilar[3]) ise en sað (alt) bayta yerleþtirilir.
    sonuc |= (sayilar[0] << 24); // 1. sayý: 24-31. bit aralýðý
    sonuc |= (sayilar[1] << 16); // 2. sayý: 16-23. bit aralýðý
    sonuc |= (sayilar[2] << 8);  // 3. sayý:  8-15. bit aralýðý
    sonuc |=  sayilar[3];        // 4. sayý:  0-7.  bit aralýðý

    // Sonucu yazdýr
    printf("\nOluþturulan 32 bitlik tam sayý: %u\n", sonuc);
    // Onaltýlýk (hex) formatta yazdýrma
    printf("Hexadecimal (16'lýk) format: 0x%X\n", sonuc);

    return 0;
}

