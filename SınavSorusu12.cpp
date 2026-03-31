//Kullanýcý pozitif tam sayý girdiði sürece, bu sayýlarý 
//tek yönlü bir baðlý listeye ekleyiniz. Ekleme iþleminde 
//ilk eleman hariç olmak üzere eklenecek olan yeni sayý tek yönlü 
//baðlý listenin en son elemanýný üç katýndan daha büyükse listenin sonuna 
//daha küçük ise listenin baþýna ekleyen program kodunu yaz

                     

#include <stdio.h>    // printf, scanf vb. fonksiyonlar için
#include <stdlib.h>   // malloc, free vb. fonksiyonlar için

// Tek yönlü baðlý liste düðüm yapýsý
struct Node {
    int veri;              // Düðümde saklanacak sayý (deðer)
    struct Node *sonraki;  // Bir sonraki düðüme iþaretçi
};

// Yeni düðüm oluþturma fonksiyonu
// Parametre: eklenecek deðer (int)
// Döndürdüðü: Heap üzerinde oluþturulmuþ yeni bir Node* (düðümün adresi)
struct Node* yeniNode(int deger) {
    // Dinamik bellekten yer ayýrýyoruz (malloc)
    struct Node* yeni = (struct Node*)malloc(sizeof(struct Node));
    yeni->veri = deger;     // Düðümün veri alanýna 'deger' atar
    yeni->sonraki = NULL;   // Baþlangýçta sonraki düðüm iþaretçisi yok
    return yeni;            // Bu yeni düðümün adresini döndür
}

// Liste baþýna eleman ekleme fonksiyonu
// Parametre: bas (listenin baþýna iþaretçi), deger (eklencek sayý)
void basaEkle(struct Node** bas, int deger) {
    // Yeni düðüm oluþtur
    struct Node* yeni = yeniNode(deger);
    // Yeni düðümün 'sonraki' iþaretçisi, mevcut listenin baþýný göstersin
    yeni->sonraki = *bas;
    // Liste baþý artýk yeni düðüm olsun
    *bas = yeni;
}

// Liste sonuna eleman ekleme fonksiyonu
// Parametre: bas (listenin baþýna iþaretçi), deger (eklencek sayý)
void sonaEkle(struct Node** bas, int deger) {
    // Yeni düðüm oluþtur
    struct Node* yeni = yeniNode(deger);

    // Eðer liste boþsa, yeni düðüm ilk eleman olsun
    if (*bas == NULL) {
        *bas = yeni;
    } else {
        // Aksi takdirde, son düðümü bulmak için listenin sonunda dolaþ
        struct Node* temp = *bas;
        while (temp->sonraki != NULL) {
            temp = temp->sonraki;
        }
        // Son düðümün 'sonraki' alanýný yeni düðüme baðla
        temp->sonraki = yeni;
    }
}

// Listeyi ekrana yazdýrma fonksiyonu
// Parametre: bas (liste baþý)
void listeyiYazdir(struct Node* bas) {
    printf("\nListe: ");
    // Listenin baþýndan null'a gelene kadar ilerleyerek veri alanlarýný yazdýr
    while (bas != NULL) {
        printf("%d ", bas->veri);
        bas = bas->sonraki;
    }
    printf("\n");
}

// Listenin son elemanýný döndüren fonksiyon
int sonEleman(struct Node* bas) {
    // Son düðüme ulaþana kadar ilerle
    while (bas->sonraki != NULL) {
        bas = bas->sonraki;
    }
    // Son düðümün 'veri' alanýný döndür
    return bas->veri;
}

int main() {
    struct Node* bas = NULL;  // Liste baþý baþlangýçta boþ (NULL)
    int sayi;

    printf("Pozitif tam sayýlar girin (bitirmek için 0 veya negatif sayý):\n");

    // Sonsuz döngü ile kullanýcýdan sayýlar istenir
    while (1) {
        printf("Sayý: ");
        scanf("%d", &sayi);

        // 0 veya negatif girildiðinde döngü kýrýlýr, sayý eklenmez
        if (sayi <= 0)
            break;

        // Eðer liste boþsa (ilk sayý)
        if (bas == NULL) {
            // Ýlk düðümü oluþtur ve liste baþýna ata
            bas = yeniNode(sayi);
        } else {
            // Listenin son elemanýný bulalým
            int son = sonEleman(bas);

            // Yeni sayý, son elemanýn 3 katýndan büyük mü?
            if (sayi > 3 * son) {
                // Büyükse listenin sonuna ekle
                sonaEkle(&bas, sayi);
            } else {
                // Deðilse (küçük veya eþitse) listenin baþýna ekle
                basaEkle(&bas, sayi);
            }
        }
    }

    // Listeyi ekrana yazdýr
    listeyiYazdir(bas);

    return 0;
}

