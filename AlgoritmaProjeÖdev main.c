#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Kisi
{
    char Ad[20];
    char Soyad[20];
    int no;
};
void sezarSifrele(char *ptr, int anahtar)
{
    while (*ptr != '\0')
    {
        *ptr = *ptr + anahtar;
         ptr++;
    }
}

void sezarSifreCoz(char *ptr, int anahtar)
{
    while (*ptr != '\0')
    {
        *ptr = *ptr - anahtar;
         ptr++;
    }
}

void dosyayaYazdir(char *ptr)
{
    FILE *fp;
    fp = fopen("sifrelimetin.txt", "w+");

    if (fp == NULL)
    {
        printf("Dosya acilamadi.\n");
        exit(1);
    }
    else
    {
        fprintf(fp, "%s", ptr);
    }
    fclose(fp);
}
char *dosyaOku()
{
    static char metin[20];
    FILE *fp;
    fp = fopen("sifrelimetin.txt", "r");

    if (fp == NULL)
    {
        printf("Dosya acilamadi.\n");
        exit(1);
    }
    else
    {
        fscanf(fp, "%s", metin);
    }
    return metin;
}

int asalCarpanbulma(int ptr)   // asal carpan bulma
{

    int dizi[10];
    int a = 0;
    int bolen = 2;
    int bolunen = ptr;

    while (bolen < ptr)
    {
        if (bolunen % bolen == 0)
        {
            dizi[a] = bolen;
            a++;
            bolunen /= bolen;
        }
        else
        {
            bolen++;
        }
    }

    int enbuyuk;

    for(int i = 0; i < a; i++)
    {
        if (i == 0)
        {
            enbuyuk = dizi[i];
        }
        if (dizi[i] > enbuyuk)
        {
            enbuyuk = dizi[i];
        }
    }
    printf("*Ogrenci numaranizin en buyuk asal carpan degeri: %d\n\n", enbuyuk);  //Parola

    return enbuyuk;
}

int main()
{
    int anahtar = 0;
    struct Kisi kisi_bilgisi1;
    printf("******************SIFRELEME*****************\n\n");
    printf("Sifrelemek istediginiz verileri giriniz..\n\n");
    printf("%c",26);
    printf("AD: ");
    scanf("%s", &kisi_bilgisi1.Ad);
    printf("%c",26);
    printf("SOYAD: ");
    scanf("%s", &kisi_bilgisi1.Soyad);
    printf("\nGirdiginiz veilerin sifrelenebilmesi icin okul numaranizi giriniz..\n\n");
    printf("%c",26);
    printf("NO: ");
    scanf("%d", &kisi_bilgisi1.no);
    printf("\n********************************************\n\n");
    while (kisi_bilgisi1.no % 10 == 0)
    {
        kisi_bilgisi1.no = kisi_bilgisi1.no / 10;
    }

    strcat(kisi_bilgisi1.Ad, kisi_bilgisi1.Soyad);
     // printf("Sonuc: %s\n",kisi_bilgisi1.Ad);

    anahtar = kisi_bilgisi1.no % 10;                      // anahtar bulma
    // printf("Kaydirma miktari: %d\n",anahtar);

    sezarSifrele(kisi_bilgisi1.Ad, anahtar);              //sifreleme
    dosyayaYazdir(kisi_bilgisi1.Ad);                      //sifreyi dosyaya yazdirma

    printf("*Ogrenci numaraniz nedir? %c ",26);
    scanf("%d", &kisi_bilgisi1.no);
    printf("\n");
    printf("Ogrenci numaranizin en buyuk asal carpan degeri hesaplaniyor.Lutfen bekleyiniz..\n\n");

    int enbuyuk = asalCarpanbulma(kisi_bilgisi1.no);

    int parola;

    do{
    printf("*PAROLA(Ogrenci numaranizin en buyuk asal carpani nedir?): ");
    scanf("%d", &parola);
    printf("\n");

    if (parola == enbuyuk)
    {
        printf("Veriler metin dosyasindan okunuyor...\n\n");
        printf("\n %c Ogrenci No : %d",16, kisi_bilgisi1.no);
        char *metin=dosyaOku();
        printf("\n %c Sifrelenmis Metin : %s\n",16, metin);
        sezarSifreCoz(metin, anahtar);
        printf(" %c Cozumlenmis Metin : %s \n\n",16, metin);
    }

    else{printf("!!Hatali bir parola girdiniz.Tekrar deneyiniz..\n\n");}
     }
    while(parola!=enbuyuk);

    return 0;
}
