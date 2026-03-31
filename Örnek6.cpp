//Kullanýcýdan pozitif tam sayýlar alýn (mesela 0 veya negatif girene kadar).
//Bu sayýlarý çift yönlü bir baðlý liste biçiminde saklayýn.
//irilen sayýlar sonrasýnda, bu listedeki elemanlarý (sadece tek sayý deðerlerini) ASCII tablosunda büyükten küçüðe sýralanmýþ þekilde bir metin dosyasýna kaydedin.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int veri;
    struct Node* onceki;
    struct Node* sonraki;
} Node;

Node* yeniNode(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->veri = v;
    n->onceki = NULL;
    n->sonraki = NULL;
    return n;
}

// Sona ekleme
void sonaEkle(Node** bas, Node** son, int v) {
    Node* y = yeniNode(v);
    if (*bas == NULL) {
        *bas = *son = y;
    } else {
        (*son)->sonraki = y;
        y->onceki = *son;
        *son = y;
    }
}

int main() {
    Node *bas = NULL, *son = NULL;
    int sayi;

    // Verileri al
    printf("Pozitif sayilar giriniz (0 veya negatif girince bitiyor):\n");
    while (1) {
        scanf("%d", &sayi);
        if (sayi <= 0) break;
        // Listeye ekle
        sonaEkle(&bas, &son, sayi);
    }

    // Tek sayýlarý geçici bir diziye aktaralým
    // Önce listeyi dolaþarak kaç tane tek var öðrenebiliriz
    int tekCount = 0;
    Node* temp = bas;
    while (temp != NULL) {
        if (temp->veri % 2 == 1) {
            tekCount++;
        }
        temp = temp->sonraki;
    }

    // Tek sayý kadar dinamik dizi
    int *tekDizi = (int*)malloc(tekCount * sizeof(int));
    if (tekDizi == NULL) return 1;

    temp = bas;
    int idx = 0;
    while (temp != NULL) {
        if (temp->veri % 2 == 1) {
            tekDizi[idx++] = temp->veri;
        }
        temp = temp->sonraki;
    }

    // Tek sayýlarý büyükten küçüðe sýralayalým (basit selection sort)
    for (int i = 0; i < tekCount - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < tekCount; j++) {
            if (tekDizi[j] > tekDizi[maxIdx]) {
                maxIdx = j;
            }
        }
        // swap
        int swapTemp = tekDizi[i];
        tekDizi[i] = tekDizi[maxIdx];
        tekDizi[maxIdx] = swapTemp;
    }

    // Sonucu dosyaya yaz
    FILE* dosya = fopen("tekSayilar.txt", "w");
    if (dosya) {
        for (int i = 0; i < tekCount; i++) {
            fprintf(dosya, "%d\n", tekDizi[i]);
        }
        fclose(dosya);
        printf("Tek sayilar siralanmis olarak 'tekSayilar.txt' dosyasina yazildi.\n");
    } else {
        printf("Dosya acilamadi!\n");
    }

    // Dinamik dizi bellegi iade
    free(tekDizi);

    // Listenin tum dugumlerini serbest birak
    temp = bas;
    while (temp != NULL) {
        Node* silinecek = temp;
        temp = temp->sonraki;
        free(silinecek);
    }

    return 0;
}

