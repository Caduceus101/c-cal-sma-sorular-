#include <stdio.h>
#include <string.h>
// Dizi kopyalama (hazýr fonksiyonlar olmadan)
void metinKopyala(char *hedef, const char *kaynak) {
    while (*kaynak) {
        *hedef = *kaynak;
        hedef++;
        kaynak++;
    }
    *hedef = '\0';
}
// 1. SELECTION SORT
void selectionSort(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        int max = i;
        for (int j = i + 1; str[j] != '\0'; j++) {
            if (str[j] > str[max])
                max = j;
        }
        if (max != i) {
            char temp = str[i];
            str[i] = str[max];
            str[max] = temp;
        }
    }
}
// 2. INSERTION SORT
void insertionSort(char *str) {
    for (int i = 1; str[i] != '\0'; i++) {
        char key = str[i];
        int j = i - 1;
        while (j >= 0 && str[j] < key) {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = key;
    }
}
// 3. BUBBLE SORT
void bubbleSort(char *str) {
    int n = 0;
    while (str[n] != '\0') n++;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (str[j] < str[j + 1]) {
                char tmp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = tmp;
            }
        }
    }
}
// 4. MERGE SORT (yardýmcý fonksiyonlarla)
void merge(char *str, int sol, int orta, int sag) {
    int n1 = orta - sol + 1;
    int n2 = sag - orta;

    char L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = str[sol + i];
    for (int j = 0; j < n2; j++) R[j] = str[orta + 1 + j];

    int i = 0, j = 0, k = sol;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) str[k++] = L[i++];
        else str[k++] = R[j++];
    }
    while (i < n1) str[k++] = L[i++];
    while (j < n2) str[k++] = R[j++];
}

void mergeSort(char *str, int sol, int sag) {
    if (sol < sag) {
        int orta = (sol + sag) / 2;
        mergeSort(str, sol, orta);
        mergeSort(str, orta + 1, sag);
        merge(str, sol, orta, sag);
    }
}
// 5. QUICK SORT
int partition(char *str, int low, int high) {
    char pivot = str[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (str[j] >= pivot) {
            i++;
            char tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
        }
    }
    char tmp = str[i + 1];
    str[i + 1] = str[high];
    str[high] = tmp;
    return i + 1;
}

void quickSort(char *str, int low, int high) {
    if (low < high) {
        int pi = partition(str, low, high);
        quickSort(str, low, pi - 1);
        quickSort(str, pi + 1, high);
    }
}

// Ana program
int main() {
    char metin[100];
    char kopya[100];

    printf("Bir metin girin: ");
    fgets(metin, sizeof(metin), stdin);
    metin[strcspn(metin, "\n")] = '\0'; // \n karakterini kaldýr

    // 1. Selection Sort
    metinKopyala(kopya, metin);
    selectionSort(kopya);
    printf("\nSelection Sort: %s", kopya);

    // 2. Insertion Sort
    metinKopyala(kopya, metin);
    insertionSort(kopya);
    printf("\nInsertion Sort: %s", kopya);

    // 3. Bubble Sort
    metinKopyala(kopya, metin);
    bubbleSort(kopya);
    printf("\nBubble Sort: %s", kopya);

    // 4. Merge Sort
    metinKopyala(kopya, metin);
    mergeSort(kopya, 0, strlen(kopya) - 1);
    printf("\nMerge Sort: %s", kopya);

    // 5. Quick Sort
    metinKopyala(kopya, metin);
    quickSort(kopya, 0, strlen(kopya) - 1);
    printf("\nQuick Sort: %s\n", kopya);

    return 0;
}

