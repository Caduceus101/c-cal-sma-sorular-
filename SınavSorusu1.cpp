//kullanýcýnýn istediði sürece 
//klavyeden girdiði metin içerisindeki karakterin 
//ASCII kodunun 5.biti 1 ise karakter yerine ilgili 
//karakterin 1 defa sola kaydýrýlmýþ halini, 
//5. bit 0 ise karakterin yerine ilgili karakterin 1 defa saða 
//kaydýrýlmýþ halini metin.txt dosyasýna yazan program kodunu yaz


#include <stdio.h>    // Standart girdi/çýktý (I/O) fonksiyonlarýný kullanabilmek için gerekli kütüphane.
#include <stdlib.h>   // Bazý yardýmcý fonksiyonlar (örneðin exit, malloc vb.) için gerekli kütüphane.

int main(void) {
    char metin[1000];  // Kullanýcýdan alýnacak metni saklamak için 1000 karakterlik bir dizi tanýmý.
    FILE *dosya;       // Dosya iþaretçisi tanýmý. Bu iþaretçiyle metin.txt dosyasýný açýp yazacaðýz.

    printf("Bir metin giriniz: "); 
    // Ekrana "Bir metin giriniz:" þeklinde bir mesaj basar.
    fgets(metin, sizeof(metin), stdin);  
    // Kullanýcýdan klavyeden bir satýr metin almaya yarar.
    // Alýnan metin 'metin' dizisine yazýlýr, en fazla 999 karakter + sonlandýrýcý '\0' alabilir.
    // 'stdin', standart giriþtir (klavye).
    // 'sizeof(metin)' -> 1000.

    dosya = fopen("metin.txt", "w");
    // fopen fonksiyonu dosyayý açar ve dosya iþaretçisini (FILE*) döndürür.
    // Eðer "metin.txt" adlý dosya yoksa oluþturur, varsa içeriðini silip baþtan "yazma" modunda ("w") açar.

    if(dosya == NULL) {
        printf("Dosya acilamadi.\n");
        return 1;
        // Eðer dosya açýlamadýysa (örneðin yazma izni yoksa), NULL döner.
        // Bu durumda hatayý bildirip programý sonlandýrýyoruz.
    }

    for (int i = 0; metin[i] != '\0'; i++) {
        // Burada metin dizisinin sonundaki '\0' karakterine (C dilinin string bitiþ karakteri) 
        // ulaþana kadar döngü dönecektir. 
        // Yani kullanýcýdan aldýðýmýz metindeki her karakteri teker teker inceleyeceðiz.
        
        char ch = metin[i];
        // 'ch', metin dizisinin o anki karakterini tutar.

        // 5. bitin kontrolü (bit konum 5 = 1 << 5 = 32)
        if(ch & (1 << 5)) {
            // Bir karakteri (char) bit seviyesinde inceleyeceðimiz zaman, 
            // "1 << 5" ifadesi 5. bit maskesini temsil eder (32 deðerindedir).
            //
            // & (bitwise AND) iþleminde, 'ch' nin 5. bitinin 1 olup olmadýðý kontrol edilir.
            // Eðer (ch & 32) ? 0 ise, bu durum ch karakterinin 5. bitinin 1 olduðunu gösterir.

            // 5. bit 1 ise; karakteri 1 defa sola kaydýr (<< 1)
            ch = ch << 1;
            // ch << 1 demek, ch'nin bitlerini 1 konum sola kaydýrmak demektir.
            // Örneðin: 0100 0001 (0x41 - 'A') sola kaydýrýlýrsa 1000 0010 (0x82) olur.
            // Numerik deðeri, 2 katýna çýkar, ancak bitler soldan taþabilir (char'ýn üst sýnýrý!).
            // Bu bazen iþaretli/iþaretsiz karakter davranýþý vb. konularda ilginç sonuçlar yaratabilir.
        } else {
            // 5. bit 0 ise; karakteri 1 defa saða kaydýr (>> 1)
            ch = ch >> 1;
            // ch >> 1 demek, ch'nin bitlerini 1 konum saða kaydýrmak demektir.
            // Örneðin: 0100 0001 (0x41 - 'A') saða kaydýrýlýrsa 0010 0000 (0x20) olur.
            // Numerik deðeri yarýya iner, saða doðru atýlan bitler kaybolur.
        }

        fputc(ch, dosya);
        // Kaydýrma iþleminden sonra elde ettiðimiz yeni karakteri (ch), 
        // 'dosya' isimli dosyaya (metin.txt) yazar.
    }

    fclose(dosya);
    // Dosyadaki iþlemler bittikten sonra dosyayý kapatýyoruz.
    // Her zaman dosya ile iþimiz bitince fclose kullanmak gerekir.

    printf("Islem tamamlandi. Sonuc metin.txt dosyasina yazildi.\n");
    // Ekrana iþlem tamamlandýðýna dair bir mesaj basar.

    return 0;
    // Programý 0 ile sonlandýrýr (baþarýyla bittiðini bildirir).
}

