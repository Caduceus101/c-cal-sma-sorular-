//Sýralý eriþimli olarak oluþturulduðu kabul edilen liste.txt isimli 
//bir dosya içerisinde 100 adet integer veri tipinden tamsayý bulunmaktadýr. 
//Bu sayýlarý çift yönlü bir baðlý listeye aktardýktan sonra, 
//bu listeyi tersten ters.txt dosyasýna kaydeden program kodu


#include <stdio.h>
#include <stdlib.h>

// Çift yönlü baðlý liste için düðüm yapýsý
typedef struct Node {
    int veri;
    struct Node* onceki;
    struct Node* sonraki;
} Node;

// Yeni bir düðüm oluþturan fonksiyon
Node* yeniNode(int veri) {
    // Bellekten yer ayýrýp düðümün veri alanýna 'veri' atar
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->veri = veri;
    yeni->onceki = NULL;
    yeni->sonraki = NULL;
    return yeni;
}

// Çift yönlü listeye sona ekleme
// Parametreler: 
//   - bas: Listenin baþýna iþaretçi 
//   - son: Listenin sonuna iþaretçi
//   - veri: Eklenecek deðer
void sonaEkle(Node** bas, Node** son, int veri) {
    // Yeni düðüm oluþtur
    Node* yeni = yeniNode(veri);

    // Eðer liste boþsa (bas == NULL), hem bas hem de son bu yeni düðümü gösterir
    if (*bas == NULL) {
        *bas = *son = yeni;
    } else {
        // Liste boþ deðilse, son düðümün 'sonraki' alanýný yeni düðüme baðla
        (*son)->sonraki = yeni;
        // Yeni düðümün 'onceki' alanýný önceki son düðüm yap
        yeni->onceki = *son;
        // Listenin son göstergesini güncelle
        *son = yeni;
    }
}

// Listeyi tersten (sondan baþa) okuyarak belirtilen dosyaya yazma
void terstenDosyayaYaz(Node* son, const char* dosyaAdi) {
    // Yazma modunda dosya açma
    FILE* dosya = fopen(dosyaAdi, "w");
    if (dosya == NULL) {
        printf("Dosya açýlamadý: %s\n", dosyaAdi);
        return;
    }
    // son göstericisi listenin en son düðümünü iþaret ediyor
    // oradan baþlayarak 'onceki' ile geriye doðru ilerle
    Node* ptr = son;
    while (ptr != NULL) {
        fprintf(dosya, "%d\n", ptr->veri);
        ptr = ptr->onceki;
    }
    fclose(dosya);
}

int main() {
    // Giriþ dosyasý (liste.txt) açýlýr
    FILE* giris = fopen("liste.txt", "r");
    if (giris == NULL) {
        printf("liste.txt dosyasý açýlamadý!\n");
        return 1;
    }

    // Baðlý liste için baþ ve son iþaretçileri baþlangýçta NULL
    Node* bas = NULL; 
    Node* son = NULL; 

    int sayi;
    // liste.txt dosyasýndan sonuna kadar sayýlarý oku, 
    // her okunan sayýyý listenin sonuna ekle
    while (fscanf(giris, "%d", &sayi) == 1) {
        sonaEkle(&bas, &son, sayi);
    }
    fclose(giris);

    // Þimdi oluþturduðumuz çift yönlü baðlý listeyi tersten ters.txt dosyasýna yaz
    terstenDosyayaYaz(son, "ters.txt");

    printf("Veriler ters.txt dosyasýna baþarýyla yazýldý.\n");

    return 0;
}

