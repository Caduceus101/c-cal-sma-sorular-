//0 ile 1000 arasýnda rasgele ürettiðinin 100 adet tam sayýyý sayilar.txt 
//dosyasýna yazýnýz.
//Oluþturduðunuz sayilar.txt dosyasýndaki sayýlarý okuyunuz. 
//Okuduðunuz sayýlardan asal sayý  olanlarý sayilar2.txt 
//dosyasýna kaydediniz. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Asal sayý kontrol fonksiyonu
int is_prime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
int main() {
    FILE *fp;
    int number;
    // Rastgele sayý üretebilmek için zamanla seedleme
    srand(time(NULL));
    // 1- 0 ile 1000 arasýnda rastgele 100 adet tam sayýyý sayilar.txt dosyasýna yazma
    fp = fopen("sayilar.txt", "w");
    if(fp == NULL) {
        printf("sayilar.txt dosyasi acilamadi.\n");
        return 1;
    }
    for(int i = 0; i < 100; i++){
        number = rand() % 1001;  // 0-1000 arasýnda sayý üretir
        fprintf(fp, "%d\n", number);
    }
    fclose(fp);
    // 2- sayilar.txt dosyasýndaki sayýlarý okuyup, asal olanlarý sayilar2.txt dosyasýna kaydetme
    fp = fopen("sayilar.txt", "r");
    if(fp == NULL) {
        printf("sayilar.txt dosyasi acilamadi.\n");
        return 1;
    }
    FILE *fp2 = fopen("sayilar2.txt", "w");
    if(fp2 == NULL) {
        printf("sayilar2.txt dosyasi acilamadi.\n");
        fclose(fp);
        return 1;
    }
    
    while(fscanf(fp, "%d", &number) != EOF) {
        if(is_prime(number)) {
            fprintf(fp2, "%d\n", number);
        }
    }
    fclose(fp);
    fclose(fp2);
    printf("Islemler tamamlandi. sayilar.txt dosyasina rastgele sayilar, sayilar2.txt dosyasina asal sayilar yazildi.\n");
    return 0;
}
