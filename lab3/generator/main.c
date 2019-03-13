#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//stala przechowujaca dlugosc roku
//ilość danych potrzebnych do wygenerowania
#define YEAR_LEN 365

int main(int argc, char* argv[]) {

    //otwarcie lub otworzenie pliku wyjsciowego
    //w trybie zapisu
    FILE* oFile = fopen("data.csv","w");

    //zapisanie parametrow wiersza polecen
    //do odpowiednich wartosci
    int minVal = atoi(argv[1]);//najwieksza mozliwa liczba pseudolosowa
    int maxVal = atoi(argv[2]);//najmniejsza mozliwa liczba pseudolsoowa
    int random;//bufor na liczbe losowa
    srand(time(NULL));

    for(int i=0; i<YEAR_LEN; i++){
        //wygenerowanie i odpowiednie sformatowanie liczby pseudolosowej
        random = (int)(rand()*((1.0/RAND_MAX))*(maxVal-minVal+1)+minVal);

        //zapis liczby do pliku w formacie csv
        fprintf(oFile,"%d,",random);
    }
    fclose(oFile);

    //zapis parametrow do pliku binarnego
    FILE* bFile = fopen("propertis.dat","wb");
    fwrite(&minVal,sizeof(int),1,oFile);
    fwrite(&maxVal,sizeof(int),1,oFile);

    return 0;
}