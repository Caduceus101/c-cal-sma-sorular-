//kullanýcýnýn istediði sürece klavyeden girdiði 
//sayýlarýn medyan ve ortalamasýný bulup 
//ekrana yazdýran program kodunu yazýnýz


#include <stdio.h>   // Standart giriþ/çýkýþ fonksiyonlarý için gerekli kütüphane
#include <stdlib.h>  // Dinamik bellek fonksiyonlarý (malloc, realloc, free) ve qsort vb. için gerekli kütüphane

// Karþýlaþtýrma fonksiyonu qsort için
// qsort, dizi öðelerini sýralarken iki öðenin hangi sýrada duracaðýný
// anlamak için bu fonksiyonu kullanýr. Burada iki tamsayý a ve b'nin
// farkýný döndürüyoruz (a - b). Sonuç pozitifse a, b'den büyük demek;
// negatifse a, b'den küçük demek; 0 ise eþitler.
int karsilastir(const void *a, const void *b) {
    // a ve b void* türünde geldiði için önce int*'e cast ediliyor,
    // sonrasýnda iþaret ettikleri deðerler çýkarýlýyor.
    return (*(int*)a - *(int*)b);
}

int main() {
    // Ýlk baþta bir kapasite belirliyoruz, 10 olsun.
    int kapasite = 10;
    
    // 'kapasite' deðerine göre bellekte yer ayýrýyoruz.
    // Sayýlar dizisi (dinamik) için iþaretçimiz 'sayilar'.
    // 10 adet int için bellekte yer ayýrma -> 10 * sizeof(int)
    int *sayilar = (int*) malloc(kapasite * sizeof(int));
    
    // 'sayac' ile kaç tane geçerli sayý girdiðimizi tutacaðýz.
    int sayac = 0;
    
    // Kullanýcýdan alýnan her yeni sayýyý önce 'girdi' deðiþkenine atayacaðýz.
    int girdi;
    
    // malloc'ýn baþarýlý olup olmadýðýný kontrol ediyoruz.
    // Eðer bellek ayrýlamadýysa 'sayilar' NULL döner, hata verip çýkýyoruz.
    if (sayilar == NULL) {
        printf("Bellek ayrýlamadý!\n");
        return 1; // Programý hatalý sonlandýrýyoruz.
    }

    // Kullanýcýya, sayý girmesi ve çýkmak için -1 yazmasý gerektiðini söylüyoruz.
    printf("Sayý girin (çýkmak için -1):\n");

    // Sürekli olarak kullanýcýdan sayý okumak için sonsuz döngü baþlatýyoruz.
    while (1) {
        printf("%d. sayý: ", sayac + 1);  // Kaçýncý sayý olduðunu belirt.
        scanf("%d", &girdi);             // Kullanýcýnýn girdiði sayýyý 'girdi'ye al.

        // Eðer kullanýcý -1 girdiyse, artýk sayý girmeyi býrakmak istediði anlamýna gelir.
        if (girdi == -1) {
            break; // Döngüden çýk.
        }

        // Eðer dizi dolduysa, kapasiteyi iki katýna çýkarýyoruz.
        // (sayac >= kapasite) ise þu anki dizi doldu demek.
        if (sayac >= kapasite) {
            // Kapasiteyi iki katýna çýkarýyoruz.
            kapasite *= 2;
            // Bellek bölgesini 'realloc' ile geniþletiyoruz.
            // Yeni kapasite = kapasite * sizeof(int)
            sayilar = (int*) realloc(sayilar, kapasite * sizeof(int));
            // reallock baþarýsýz olursa da NULL döner.
            if (sayilar == NULL) {
                printf("Bellek geniþletilemedi!\n");
                return 1; // Programý sonlandýrýyoruz.
            }
        }

        // Yeni girilen sayýyý dizinin ilgili indeksine ekliyoruz.
        // 'sayac' dizi boyunca yazýlacak indeksi temsil ediyor.
        sayilar[sayac++] = girdi;

        // Þimdi her seferinde ortalama ve medyan deðerlerini hesaplayacaðýz.
 
        
        // 1) ORTALAMA HESABI
        double toplam = 0.0;  // Toplamý tutacaðýz
        // Dizideki elemanlarýn hepsini toplayalým
        for (int i = 0; i < sayac; i++) {
            toplam += sayilar[i];
        }
        // Ortalamayý bulmak için toplamý eleman sayýsýna bölüyoruz.
        double ortalama = toplam / sayac;

        // 2) MEDYAN HESABI
        // Medyaný bulmak için dizi sýralanmalý.
        // qsort ile 'sayilar' dizisini (sayac elemanlý) int türüne göre sýrala.
        // 'karsilastir' bizim yukarýda tanýmladýðýmýz karþýlaþtýrma fonksiyonu.
        qsort(sayilar, sayac, sizeof(int), karsilastir);

        // Medyan = sýralý dizinin ortadaki elemaný
        // Eleman sayýsý tekse, tam ortadaki
        // Eleman sayýsý çiftse, bu kodda (sayac / 2) - 1'inci elemaný alýyoruz
        // (burada medyan tek sayýda tam ortadaki, çift sayýda ise ortanýn solundaki eleman olarak tanýmlanmýþ)
        int medyan;
        if (sayac % 2 == 1) {
            // Tek eleman sayýsýnda (örneðin 5 eleman),
            // ortanca = [5/2]=2. indeks, 0'dan baþladýðý için 3. eleman
            medyan = sayilar[sayac / 2];
        } else {
            // Çift eleman sayýsýnda (örneðin 4 eleman),
            // bu kod medyan olarak [4/2 - 1]=1. indeksteki elemaný alýyor, 0'dan baþladýðý için 2. eleman
            medyan = sayilar[(sayac / 2) - 1];
        }

        // Kullanýcýya ortalama ve medyaný göster.
        printf("Girdiðiniz %d sayýnýn ortalamasý: %.2f\n", sayac, ortalama);
        printf("Medyan: %d\n", medyan);
        printf("-------------\n");
    }

    // -1 girilirse sonsuz döngü biter, þimdi belleði boþaltabiliriz.
    free(sayilar);

    // Baþarýlý þekilde çýkýþ yapýyoruz.
    return 0;
}

