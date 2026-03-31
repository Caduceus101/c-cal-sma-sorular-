//kendisine parametre olarak verilen tamsayýnýn 
//asal sayý olup olmadýgýný belirleyen recursive fonksiyon kodunu yaz


#include <stdio.h>

// asalMi fonksiyonu: sayýnýn asallýðýný özyinelemeli (recursive) olarak kontrol eder.
// Parametreler:
//   - sayi: Asallýðý test edilecek sayý.
//   - bolen: Bu test sýrasýnda kullanýlacak bölen (sayi-1'den 1'e kadar azalacak).
int asalMi(int sayi, int bolen) {
    // 1) Sýnýr kontrolü: sayi eðer 1 veya daha küçükse asal deðildir.
    if (sayi <= 1)
        return 0; // 0 döndürerek "asal deðil" bilgisini verir.

    // 2) Eðer bolen 1'e kadar geldiyse ve hala hiçbir bölünme olmadýysa,
    //    bu sayý asaldýr.
    if (bolen == 1)
        return 1; // 1 döndürerek "asal" olduðunu belirtir.

    // 3) Asýl kontrol: sayý, bu 'bolen' deðerine tam bölünüyorsa asal deðildir.
    if (sayi % bolen == 0)
        return 0; // Bölündüðü an yakalar, 0 döndürür.

    // 4) Eðer yukarýdaki koþullar saðlanmadýysa (bölünme yoksa), 
    //    boleni 1 azaltarak fonksiyonu özyinelemeli þekilde çaðýrýr.
    return asalMi(sayi, bolen - 1);
}

// Ana fonksiyon: Kullanýcýdan sayý okur, asal olup olmadýðýný test eder ve sonucu yazdýrýr.
int main() {
    int sayi;
    printf("Bir tamsayý girin: ");
    scanf("%d", &sayi);

    // asalMi fonksiyonunu, sayiyi (sayi - 1)'e kadar test edecek þekilde çaðýrýr.
    if (asalMi(sayi, sayi - 1))
        printf("%d bir asal sayýdýr.\n", sayi);
    else
        printf("%d asal sayý deðildir.\n", sayi);

    return 0; // Programý baþarýyla sonlandýrýr.
}

