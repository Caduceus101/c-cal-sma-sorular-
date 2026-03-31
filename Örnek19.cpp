//Tek yönlü bir bağlı listenin (Singly Linked List) başlangıç 
//düğümünü (head) parametre olarak alan ve listeyi özyineli (recursive) olarak, herhangi bir döngü kullanmadan ters çevirip yeni başlangıç düğümünü geri döndüren fonksiyonu yazınız.

#include <stdio.h>
#include <stdlib.h>

// Tek yönlü bağlı liste yapısı
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Listeyi recursive olarak tersine çeviren fonksiyon
Node* recursiveTersCevir(Node* head) {
    // Temel Durum: Liste boşsa veya tek elemanlıysa, kendisini döndür
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Geri kalan listeyi özyineli olarak ters çevir ve yeni head'i tut
    Node* yeniHead = recursiveTersCevir(head->next);
    
    // Mevcut (head) düğümün bir sonraki düğümünü (head->next), kendisine (head) bağla
    head->next->next = head;
    
    // Mevcut düğümün (eski listedeki head) bağını koparıp son eleman yap
    head->next = NULL;
    
    return yeniHead; // Listenin yeni başını geriye doğru taşı
}

// Yardımcı fonksiyon: Düğüm ekleme
Node* basaEkle(Node* head, int data) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = data;
    yeni->next = head;
    return yeni;
}

int main() {
    Node* liste = NULL;
    liste = basaEkle(liste, 3); // Liste: 3
    liste = basaEkle(liste, 2); // Liste: 2 -> 3
    liste = basaEkle(liste, 1); // Liste: 1 -> 2 -> 3
    
    printf("Eski head degeri: %d\n", liste->data);
    
    liste = recursiveTersCevir(liste); // Liste dönüyor: 3 -> 2 -> 1
    
    printf("Yeni head degeri: %d\n", liste->data); // Artık 3 oldu.
    return 0;
}
