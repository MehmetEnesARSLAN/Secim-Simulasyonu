#include<stdio.h>
#include <stdlib.h>
void oyBilgisiAl(int dizi[],int boyut){
    char partiHarfleri[6]={'A','B','C','D','E','F'};
	int i;
	for(i=0;i<boyut; i++){
            printf("\n%c partisinin oy sayisini girin: ",partiHarfleri[i]);
			scanf("%d",&dizi[i]);
    }
        printf("Sehir icin girdiginiz bilgiler basariyla kaydedilmistir.\n\n");
}

void gecerliOy(int oySayisi[]){
    int gecerliOy=0,i;
    for(i=0;i<6;i++)
	gecerliOy+=oySayisi[i];
	printf("Gecerli oy sayisi: %d\n",gecerliOy);
}

void bubbleSort(int oySayisi[],char partiHarfleri[]){
int aktarici2,i,j;
char aktarici1;
for(i=0;i<6-1;i++){
            for(j=0;j<6-1;j++){
                if(oySayisi[j]<oySayisi[j+1])
                {
                    aktarici1=partiHarfleri[j+1];
                    partiHarfleri[j+1]=partiHarfleri[j];
                    partiHarfleri[j]=aktarici1;
                    aktarici2=oySayisi[j];
                    oySayisi[j]=oySayisi[j+1];
                    oySayisi[j+1]=aktarici2;
                }
            }
        }
}
  void siraliYazdir(int oySayisi[],int kontenjan){
    int i,sonuc[6]={0,0,0,0,0,0},oySayisiKopya[6];
    float yuzde[6];
    char partiHarfleri[6]={'A','B','C','D','E','F'};

    bubbleSort(oySayisi,partiHarfleri);
    yuzdeHesapla(oySayisi,yuzde);
    for(i=0; i<6; i++)
        oySayisiKopya[i]=oySayisi[i];
    mvHesapla(oySayisiKopya,6,kontenjan,sonuc);
    printf("\t\t\t\tOy Sayisi\tOy Yuzdesi\tMilletvekili Sayisi\n");
     for(i=0;i<6;i++){
    printf("%c Partisi:\t\t\t%d\t\t%.2f\t\t\t%d\n",partiHarfleri[i],oySayisi[i],yuzde[i],sonuc[i]);
    }
     for(i=0;i<6;i++){
        sonuc[i]=0;
    }
    printf("Girdiginiz bilgiler basariyla kaydedilmistir.\n");
}

int maxBul(int dizi[], int boyut){
	int i,max=dizi[0];
	for(i=0;i<boyut;i++){
		if (max<=dizi[i]){
			max=dizi[i];
		}
	}
	return max;
}
int hangiIndex(int dizi[],int boyut,int arananSayi){
	int i=0;
	for(i;i<boyut;i++){
    if(arananSayi==dizi[i]){
			return i;
			break;
        }
	}
}
void birincilikHesapla(int oySayisi[],int boyut,int birincilikSonuc[]){
int max,index;
	max=maxBul(oySayisi,boyut);
	index=hangiIndex(oySayisi,boyut,max);
	birincilikSonuc[index]++;
	}
void mvHesapla(int oySayisi[],int boyut,int kontenjan,int sonuc[]){
	int max,index,i;
	for(i=0;i<kontenjan;i++){
	max=maxBul(oySayisi,boyut);
	index=hangiIndex(oySayisi,boyut,max);
	sonuc[index]++;
	oySayisi[index]/=2;
	}
}
void yuzdeHesapla(int oySayisi[],float yuzde[]){
     float oyToplami=0;
    int i;
    for(i=0;i<6;i++){
            oyToplami+=oySayisi[i];
        }
        for(i=0;i<6;i++){
    yuzde[i]=(oySayisi[i]/oyToplami)*100;
        }
}

int main()
{
    int istanbulOySayisi[6],ankaraOySayisi[6],izmirOySayisi[6],adanaOySayisi[6],antalyaOySayisi[6],oyToplam[6],mvToplam[6],kontenjan,i=0;
	int istanbulOyKopya[6],ankaraOyKopya[6],izmirOyKopya[6],adanaOyKopya[6],antalyaOyKopya[6];
	float genelOyYuzde[6],genelMVYuzde[6],toplam1=0,toplam2=0;
	int mvSonuc[]={0,0,0,0,0,0},birincilikSonuc[]={0,0,0,0,0,0};
    char partiHarfleri[6]={'A','B','C','D','E','F'};
	printf("Secim sonuclari algoritmasina hosgeldiniz\nBu secimde:\nSehir sayisi:5\nParti sayisi:6\n\n");
    printf("\nLutfen Istanbul icin oy sayilarini girin\n ");
	oyBilgisiAl(istanbulOySayisi,6);
	printf("\nLutfen Istanbul icin milletvekili kontenjanini girin: ");
    scanf("%d",&kontenjan);
	printf("Milletvekili kontenjani: %d\n",kontenjan);
	gecerliOy(istanbulOySayisi);
    birincilikHesapla(istanbulOySayisi,6,birincilikSonuc);
	for(i=0;i<6;i++)
        istanbulOyKopya[i]=istanbulOySayisi[i];
    mvHesapla(istanbulOyKopya,6,kontenjan,mvSonuc);
    for(i=0;i<6;i++)
        istanbulOyKopya[i]=istanbulOySayisi[i];
    siraliYazdir(istanbulOyKopya,kontenjan);
system("\nPAUSE");
	printf("\nLutfen Ankara icin oy sayilarini girin\n");
	oyBilgisiAl(ankaraOySayisi,6);
	printf("\nLutfen Ankara icin milletvekili kontenjanini girin: ");
    scanf("%d",&kontenjan);
    printf("Milletvekili kontenjani: %d\n",kontenjan);
    gecerliOy(ankaraOySayisi);
    birincilikHesapla(ankaraOySayisi,6,birincilikSonuc);
	for(i=0;i<6;i++)
        ankaraOyKopya[i]=ankaraOySayisi[i];
    mvHesapla(ankaraOyKopya,6,kontenjan,mvSonuc);
    for(i=0;i<6;i++)
        ankaraOyKopya[i]=ankaraOySayisi[i];
	siraliYazdir(ankaraOyKopya,kontenjan);
system("\nPAUSE");
	printf("\nLutfen Izmir icin oy sayilarini girin\n");
	oyBilgisiAl(izmirOySayisi,6);
	printf("\nLutfen Izmir icin milletvekili kontenjanini girin: ");
	scanf("%d",&kontenjan);
	printf("Milletvekili kontenjani: %d\n",kontenjan);
	gecerliOy(izmirOySayisi);
	birincilikHesapla(izmirOySayisi,6,birincilikSonuc);
	for(i=0;i<6;i++)
        izmirOyKopya[i]=izmirOySayisi[i];
	mvHesapla(izmirOyKopya,6,kontenjan,mvSonuc);
	for(i=0;i<6;i++)
        izmirOyKopya[i]=izmirOySayisi[i];
	siraliYazdir(izmirOyKopya,kontenjan);
system("\nPAUSE");
	printf("\nLutfen Adana icin oy sayilarini girin\n");
	oyBilgisiAl(adanaOySayisi,6);
	printf("\nLutfen Adana icin milletvekili kontenjanini girin: ");
	scanf("%d",&kontenjan);
	printf("Milletvekili kontenjani: %d\n",kontenjan);
	gecerliOy(adanaOySayisi);
	birincilikHesapla(adanaOySayisi,6,birincilikSonuc);
	for(i=0;i<6;i++)
        adanaOyKopya[i]=adanaOySayisi[i];
	mvHesapla(adanaOyKopya,6,kontenjan,mvSonuc);
	for(i=0;i<6;i++)
        adanaOyKopya[i]=adanaOySayisi[i];
	siraliYazdir(adanaOyKopya,kontenjan);
system("\nPAUSE");
	printf("\nLutfen Antalya icin oy sayilarini girin\n");
	oyBilgisiAl(antalyaOySayisi,6);
	printf("\nLutfen Antalya icin milletvekili kontenjanini girin: ");
	scanf("%d",&kontenjan);
	printf("Milletvekili kontenjani: %d\n",kontenjan);
	gecerliOy(antalyaOySayisi);
	birincilikHesapla(antalyaOySayisi,6,birincilikSonuc);
	for(i=0;i<6;i++)
       antalyaOyKopya[i]=antalyaOySayisi[i];
	mvHesapla(antalyaOyKopya,6,kontenjan,mvSonuc);
	for(i=0;i<6;i++)
    antalyaOyKopya[i]=antalyaOySayisi[i];
	siraliYazdir(antalyaOyKopya,kontenjan);
    for(i=0;i<6;i++){
    oyToplam[i]=istanbulOySayisi[i]+ankaraOySayisi[i]+izmirOySayisi[i]+adanaOySayisi[i]+antalyaOySayisi[i];
    toplam1+=oyToplam[i];
    toplam2+=mvSonuc[i];
    }
    for(i=0;i<6;i++){
    genelOyYuzde[i]=(oyToplam[i]/toplam1)*100;
    genelMVYuzde[i]=(mvSonuc[i]/toplam2)*100;
    }
    printf("\n\n       \t\t\t\t\t\t-TURKIYE GENELI-      \n\n\n");
    printf("Milletvekili kontenjani: %.0f\nGecerli oy sayisi: %.0f\n",toplam2,toplam1);
    printf("\t\t\t\tOy Sayisi\tOy Yuzdesi\tMV Sayisi\tMV Yuzdesi\t1.lik Sayisi\n");
    for(i=0;i<6;i++){
    printf("%c Partisi:\t\t\t %d\t\t %.2f\t\t   %d\t\t%.2f\t\t     %d\n",partiHarfleri[i],oyToplam[i],genelOyYuzde[i],mvSonuc[i],genelMVYuzde[i],birincilikSonuc[i]);
    }
        bubbleSort(mvSonuc,partiHarfleri);
    printf("Iktidar partisi: %c \n",partiHarfleri[0]);
    printf("Ana muhalefet partisi: %c",partiHarfleri[1]);
}


