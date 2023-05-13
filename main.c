#include <stdio.h>

void selectionSort(int dizi[], int boyut) {
    int i, j, enKucukIndeks, geciciDeger;
    
    for (i = 0; i < boyut-1; i++) {
        enKucukIndeks  = i;

        for (j = i+1; j < boyut; j++) {
            if (dizi[j] < dizi[enKucukIndeks ]) {
                enKucukIndeks  = j;
            }
        }

        geciciDeger = dizi[enKucukIndeks];
        dizi[enKucukIndeks] = dizi[i];
        dizi[i] = geciciDeger;
    }
}

int binarySearch(int dizi[], int sol, int sag, int aranan) {
    if (sag >= sol) {
        int orta = sol + (sag - sol) / 2;

        if (dizi[orta] == aranan) {
            return orta;
        }

        if (dizi[orta] > aranan) {
            return binarySearch(dizi, sol, orta - 1, aranan);
        }

        return binarySearch(dizi, orta + 1, sag, aranan);
    }

    return -1;
}

int main() {
    int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68};
    int diziBoyut = sizeof(dizi) / sizeof(dizi[0]);

    // selectionSort ile diziyi sırala
    selectionSort(dizi, diziBoyut);
    
    printf("---- Aramanin yapildigi dizi--->{4, 8, 3, 84, 47, 76, 9, 24, 68}\n\n");
    printf("Bu dizinin siralanmasi selectionSort ile yapildi.\n\n");
    printf("---- Dizinin selectionSort ile siralanmis hali--->{3,4,8,9,24,47,68,76,84}\n\n");
    
    int aranan;
    printf("Lutfen aramak istediginiz elemani giriniz: ");
    scanf("%d", &aranan);
    printf("\n");

    int sonuc = binarySearch(dizi, 0, diziBoyut - 1, aranan);

    if (sonuc == -1) {
        printf("- Oops! Girilen %d, dizinin icinde bulunamadi!\n", aranan);
    } else {
        printf("- Girilen %d, %d. indekste bulundu.\n", aranan, sonuc + 1);
    }

    return 0;
}
