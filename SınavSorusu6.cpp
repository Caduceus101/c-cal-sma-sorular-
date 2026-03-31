//bitsel operatör kullanrak 40 karakterlik bir metin dizisini 
//int türünde 10 bit sýðdýrma


#include <stdio.h>
#include <string.h>

#define MAX_LEN 40   // Maksimum 40 karakter
#define INT_BITS 32  // unsigned int 32 bit

// 'str' adlý metni, 10 bitlik bloklar halinde 'encoded' dizisine yazar.
// Her 3 karakter -> 1 unsigned int (3 x 10 bit = 30 bit kullanýlýyor).
// 'size' ise kaç tane unsigned int kullanýldýðýný geri döndürür.
void encodeString(char *str, unsigned int *encoded, int *size) {
    int len = strlen(str);

    // (len + 2) / 3, metnin her 3 karakteri için 1 adet int kullandýðýmýzý belirler.
    // Örneðin len=8 ise, (8+2)/3 = 3 adet 32-bit int gerekir.
    *size = (len + 2) / 3;

    // Her adýmda 3 karakteri bir int'e yerleþtiriyoruz.
    // [i*3]      -> üst 10 bitler (bit 31..22),
    // [i*3 + 1]  -> orta 10 bitler (bit 21..12),
    // [i*3 + 2]  -> alt 10 bitler (bit 11.. 2) (kodda 0..9 olarak kullanýlýyor).
    for (int i = 0; i < *size; i++) {
        encoded[i] = ( (unsigned int)str[i * 3]     << 20 ) |
                     ( ( i * 3 + 1 < len ? (unsigned int)str[i * 3 + 1] : 0 ) << 10 ) |
                       ( i * 3 + 2 < len ? (unsigned int)str[i * 3 + 2] : 0 );
    }
}

// 'encoded' dizisindeki veriyi çözerek 'decoded' dizisine yerleþtirir.
// 3 karakter (toplam 30 bit) decode edilirken:
// - ilk karakter: bit 31..22 (10 bit) -> saða kaydýrarak & 1023 ile maskeleme
// - ikinci karakter: bit 21..12 (10 bit)
// - üçüncü karakter: bit 11.. 2 (10 bit)
void decodeString(unsigned int *encoded, int size, char *decoded, int len) {
    for (int i = 0; i < size; i++) {
        // Ýlk 10 bit (bit 31..22)
        decoded[i * 3]     = (encoded[i] >> 20) & 1023;  
        
        // Ortadaki 10 bit (bit 21..12)
        decoded[i * 3 + 1] = (encoded[i] >> 10) & 1023; 
        
        // Son 10 bit (bit 11.. 2)
        decoded[i * 3 + 2] =  encoded[i]        & 1023; 
    }
    // Metnin sonuna null-terminator ekleyerek C string'i tamamlarýz
    decoded[len] = '\0';
}

int main() {
    char metin[MAX_LEN + 1];  // Okunacak metin için yer (40 + '\0')
    unsigned int encoded[MAX_LEN / 3 + 1] = {0}; 
    int encodedSize;

    printf("Bir metin girin (maksimum 40 karakter): ");
    fgets(metin, MAX_LEN + 1, stdin);
    // fgets sonunda gelen '\n' karakterini silme
    metin[strcspn(metin, "\n")] = '\0';

    // Encoding (3 karakter -> 30 bit -> 1 int)
    encodeString(metin, encoded, &encodedSize);

    printf("\nKodlanmýþ (encoded) veri:\n");
    for (int i = 0; i < encodedSize; i++) {
        printf("%u ", encoded[i]);
    }
    printf("\n");

    // Decoding yaparak ayný metni geri elde edelim
    char decoded[MAX_LEN + 1];
    decodeString(encoded, encodedSize, decoded, strlen(metin));

    printf("\nÇözülen (decoded) metin: %s\n", decoded);

    return 0;
}

