//Kendisine parametre olarak verilen x tamsayý deðerine 
//baðlý olarak verilen f(x) matematiksel denklemini hesaplayan 
//recursive fonksiyon kodunu yaz 
//f(x)={ x > 2 ise f(x/2)+f(2x/5), x <= 2 ise g(x) } 
//g(x)={ x <=0 ise 0, x>5 ise g(x-5) }


#include <stdio.h>

// g(x) fonksiyonu:
// 1) x <= 0 ise 0 döndür
// 2) x > 5 ise g(x - 5) olarak özyinelemeli çaðrý
// 3) 0 < x <= 5 aralýðýnda ise x deðerini döndür
int g(int x) {
    if (x <= 0)
        return 0;
    else if (x > 5)
        return g(x - 5);
    else
        return x;  // 0 < x <= 5 arasýnda ise x'in kendisi
}

// f(x) fonksiyonu:
// 1) x > 2 ise: f(x/2) + f((2x)/5)
// 2) x <= 2 ise: g(x)
int f(int x) {
    if (x > 2)
        return f(x / 2) + f((2 * x) / 5);
    else
        return g(x);
}

int main() {
    int x;
    printf("x deðerini girin: ");
    scanf("%d", &x);

    // f(x) fonksiyonunu çaðýr ve sonucu ekrana yazdýr
    int sonuc = f(x);
    printf("f(%d) = %d\n", x, sonuc);

    return 0;
}

