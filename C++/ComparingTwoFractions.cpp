// fikriks

#include<stdio.h>

using namespace std;

int main()
{
    int pecahan_pembilang1, pecahan_penyebut1, pecahan_pembilang2, pecahan_penyebut2;
    float hasil1, hasil2;

    printf("%s\n", "Membandingkan Dua Bilangan Pecahan");
    printf("Masukan Bilangan Pecahan Ke-1 (Format Input = 1/2) = ");
    scanf("%i/%i", &pecahan_pembilang1, &pecahan_penyebut1);

    printf("Masukan Bilangan Pecahan Ke-2 (Format Input = 1/2) = ");
    scanf("%i/%i", &pecahan_pembilang2, &pecahan_penyebut2);

    hasil1 = (float) pecahan_pembilang1 / pecahan_penyebut1;
    hasil2 = (float) pecahan_pembilang2 / pecahan_penyebut2;

    if(hasil1 == hasil2){
        printf("Pecahan Ke-1 (%i/%i) Sama Dengan Pecahan Ke-2 (%i/%i)", pecahan_pembilang1, pecahan_penyebut1, pecahan_pembilang2, pecahan_penyebut2);
    }else if(hasil1 < hasil2){
        printf("Pecahan Ke-1 (%i/%i) Lebih Kecil Dari Pecahan Ke-2 (%i/%i)", pecahan_pembilang1, pecahan_penyebut1, pecahan_pembilang2, pecahan_penyebut2);
    }else if(hasil1 > hasil2){
        printf("Pecahan Ke-1 (%i/%i) Lebih Besar Dari Pecahan Ke-2 (%i/%i)", pecahan_pembilang1, pecahan_penyebut1, pecahan_pembilang2, pecahan_penyebut2);
    }

    return 0;
}
