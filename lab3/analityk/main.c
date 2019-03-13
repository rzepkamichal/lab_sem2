#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <mem.h>

//stala przechowujaca liczbe dni w roku
#define YEAR_LEN 365

//stala przechowujaca dlugosc bufora na dane
#define BUF_LEN 32

/*Funkcja sortValues
 * sortuje wartosci w tablicy liczb calkowitych
 * kolejnosc sortowania: min,...,max
 * parametry:
 *  - int* values - wskaznik na tablice liczb calkowitych
 *  - int size
 * zwraca:
 *  - void
 */
void sortValues(int* values, int size){

    int tmp;
    //bubblesort
    for(int i = 0; i < size -1; i++){
        for(int j = 0; j < size -1;j++){
            if(values[j] > values[j+1]){
                tmp = values[j];
                values[j] = values[j+1];
                values[j+1] = tmp;
            }
        }
    }
}

/*Funkcja average
 * wilicza srednia aryt.
 * z przekazanych w tablicy liczb calkowitych wartosci
 * parametry:
 *  - int* values - wskaznik na poczatek tablicy
 *  - int size - liczba elem. tablicy
 * zwraca:
 *  double sum/size - iloraz obliczonej sumy elementow przez ich ilosc
 */
double average(int* values, int size){
    unsigned long sum = 0;

    for(int i = 0; i < size; i++){
        sum += values[i];
    }

    return sum/size;
}

/*Funkcja median
 *Wyznacza mediane z przekazanych w posortowanej tablicy
 *liczb calkowitych wartosci
 *parametry:
 *  - int* values - wskaznik na tablice wartosci
 *  - int size - rozmiar tablicy
 *zwraca:
 *  - double mediana - wyliczona wartosc mediany
 */
double median(int* values, int size){

    double mediana;
    if(size % 2 == 0){
        mediana = 0.5*(values[size/2 -1] + values[size/2]);
    }else{
        mediana = values[(size-1)/2];
    }

    return mediana;
}

int main(int argc, char* argv[]) {

    //otworzenie pliku z danymi w trybie odczytu
    //sciezka do pliku to pierwszy parametr programu
    FILE* iFile = fopen(argv[1],"r");

    //zapisanie kosztu jednostki wody do zmiennej
    //wartosc kosztu jednostki jest drugim parametrem programu
    double cost = atof(argv[2]);

    //deklaracja tablicy przechowujacej
    //wczytane wartosci
    int values[YEAR_LEN];

    //deklaracja bufora na wczytywane dane
    char buffer[BUF_LEN];
    //deklaracja bufora na pojedyncze znaki
    char signBuff;

    //iterator pomocniczy
    //do zapelniania bufora
    int iterator = 0;
    //iterator pomocniczy do zapelniania tablicy
    int valuesIterator = 0;

    signBuff = getc(iFile);

    //odczyt wartosci
    while(signBuff != EOF && valuesIterator < YEAR_LEN){
        if(!isspace(signBuff) && isdigit(signBuff)){
            //zapisanie kolejnego znaku do bufora
            //jezeli odczytana wartosc jest cyfra
            buffer[iterator] = signBuff;
            iterator++;
            signBuff = getc(iFile);

        }else if(signBuff == ','){
            //zapisanie zawartosci bufora do tablicy wartosci
            //w przypadku napotkania przecinka
            iterator = 0;
            values[valuesIterator] = atoi(buffer);
            valuesIterator++;
            signBuff = getc(iFile);

            //zwalnianie bufora
            memset(buffer,'\0',BUF_LEN);

        }
        else{
            //w przypadku odczytu wartosci innej
            //niz przecinek albo cyfra
            //nastepuje pobranie nastepnego znaku
            signBuff = getc(iFile);
        }
    }

    FILE* oFile = fopen("output.csv","w");

    //wypisanie naglowkow w pliku
    fprintf(oFile,"Srednia,\tMediana,\tMinimum,\tMaximum\n");

    sortValues(values, YEAR_LEN);//posortowanie tablicy
    double avg = average(values, YEAR_LEN);//wyznaczenie wart. sredniej
    double med = median(values,YEAR_LEN);//wyznaczenie mediany
    int min = values[0];//minimum to pierwszy element posortowanej tablicy
    int max = values[YEAR_LEN-1];//maksimum to ostatni element posortowanej tablicy

    //wypisanie powyzszych wartosci do pliku pod odp. naglowkami
    fprintf(oFile,"%.2f,\t%.2f,\t%d,\t%d\n\n",avg, med, min, max);

    //wypisanie do pliku kolejnych naglowkow
    fprintf(oFile,"Liczba jednostek wody,\tCena,\tKoszt\n\n");

    unsigned long sum = 0;//przechowuje sume wartosci w tablicy
    //obliczenie i wypisanie kosztow pod odpowiednimi naglowkami w pliku
    for(int i=0; i<YEAR_LEN; i++){
        fprintf(oFile,"%d,\t%.2f,\t%.2f\n",values[i],cost,cost*values[i]);
        sum += values[i];
    }
    //wypisanie do pliku kolejnych naglowkow
    fprintf(oFile,"\nSuma jednostek wody,\tKoszt calkowity\n\n");

    //obliczenie kosztow calkowitych
    //zapisanie do pliku pod odpowiednimi naglowkami
    fprintf(oFile,"%d,\t%.2f\n",sum, sum*cost);

    return 0;
}
