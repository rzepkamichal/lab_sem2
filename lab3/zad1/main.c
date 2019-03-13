#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define ARG_NUM 2
#define VAT_INSTRUCTION_LEN 4


/*funkcja isNumber
 * parametry:
 *           - char* str - wskaznik na poczatek ciagu znakow
 * sprawdza, czy przekazany jako parametr string
 * reprezentuje liczbe rzeczywista
 *
 * funkcja zwraca wartosc calkowita:
 *  - 1, jezeli podany ciag stanowi prawidlowa liczbe
 *  - 0 w innym przypadku
 */
int isNumber(char* str){

    //wyszukanie w ciagu kropki i zapisanie wskaznika na nia
    char* dotPtr = strchr(str,'.');

    //zapisanie wskaznikow na pierwszy i ostatni element ciagu znakow
    char* first = str;
    char* last = str + strlen(str) - 1;


    //flaga informujaca, czy jedna i tylko jedna kropka zostala odczytana
    bool dotAppeared = false;

    //sprawdzenie, czy kropka znajduje sie na prawidlowej pozycji
    //i czy pozostale znaki sa cyframi
    if((dotPtr > first && dotPtr < last) || dotPtr == NULL){

        for(int i=0; i<strlen(str); i++){
            if(isdigit(str[i])) {
                continue;
            }else if(!dotAppeared && str[i] == '.'){
                dotAppeared = true;
                continue;
            }else{
                return 0;
            }
        }

        return 1;
    }else{
        return 0;
    }


}

/*Program wiersza polecen przyjmuje jako parametr sciezke do pliku wejsciowego.
 * Z podanego pliku odczytuje wartosc vat zapisana na poczatku w postaci "VAT <wartosc>"
 * Dla zadanej wartosci vat program wylicza stawki z vatem kolejno podanych wartosci rozdzielonych przecinkiem.
 * W katalogu wywołania program tworzy lub nadpisuje plik"output.txt",
 * do ktorego zapisuje wyniki powyzszych operacji rozdzielone przecinkiem.
 * W przypadku blednych danych, nieprawidlowych parametrow cmd - program jest zatrzymywany
 */
int main(int argc, char* argv[]) {

    //zatrzymanie pracy programu
    //gdy liczba arg. wiersza pol. jest niewlasciwa
    assert(argc == ARG_NUM);

    //zapisanie sciezki do pliku do lancucha znakow
    char* filePath[1];
    *filePath = strdup(argv[1]);

    //otwarcie pliku w trybie odczytu
    //program zatrzymuje prace, gdy pliku nie da sie otworzyc
    FILE* iFile = fopen(*filePath,"r");
    assert(iFile);

    char signBuff;//bufor na odczyt pojedynczego znaku
    char buffTmp[32] = "\0";//bufor sluzacy do bezposredniego odczytu z pliku
    char buff[32] = "\0";//bufor dodatkowy na przechowywanie sformatowanej zawartosci buffTmp
    char vatBuff[16] = "\0";//bufor przechowujacy ciag znakow reprezentujaca wartisc vat
    int iterator = 0;//pomocniczazmienna iteracyjna umozliwiajaca zapis czytanych danych do bufora

    //odczyt wartosci VAT
    //odczyt kolejnych znakow do bufora
    signBuff = getc(iFile);
    while(signBuff != EOF){
            buffTmp[iterator] = signBuff;
            if(signBuff == ','){
                break;
            }
            iterator++;
        signBuff = getc(iFile);
    }

    //zapisanie zawartosci bufora tymczasowego
    //do bufora docelowego bez znaku przecinka
    memmove(buff,buffTmp,iterator);

    //szukanie w buforze napisu "VAT"
    //odczytanie wskaznika na pierwsza litere ciagu "VAT"
    //zapisanie do zmienniej vatPtr
    char* vatPtr = strstr(buff,"VAT");

    //zatrzymanie programu, gdy nie znaleziono ciagu liter "VAT"
    assert(vatPtr);

    //odczyt wartosci vat przekazanej po białym znaku i zapisanie do bufora
    memcpy(vatBuff,vatPtr + VAT_INSTRUCTION_LEN,16);

    //zatrzymanie programu, gdy wartosc vat nie jest prawidlowa liczba
    assert(isNumber(vatBuff));

    //rzutowanie wartosci vat na typ zmiennoprzecinkowy
    double vatValue = atof(vatBuff)/100+1;

    //otwarcie lub utworzenie pliku zapisu
    //zatrzymanie pracy programu, gdy pliku nie da sie otworzyc/utworzyc
    FILE* oFile = fopen("output.txt","w");
    assert(oFile);
    double value;

    //pobieranie kolejnych znakow do bufora znakowego
    //zapis do bufora ciagu znakowego przechowujacego kolejne wartosci
    signBuff = getc(iFile);
    char message[32];
    while(signBuff != EOF){
        //czyszcenie bufora
        memset(buffTmp,'\0',32);
        iterator = 0;

        while(signBuff != ',' && signBuff != EOF){
            if(!isspace(signBuff)){
                buffTmp[iterator] = signBuff;
                iterator++;
            }
            signBuff = getc(iFile);
        }
        //jezeli odczytany ciag znakow nie jest liczba
        //ustaw wartosc komunikatu na "bledne dane!" i wyslij do pliku i na wyjscie std
        //zatrzymaj program
        if(!isNumber(buffTmp)){
            sprintf(message,"%s","bledne dane!");
            puts(message);
            fputs(message,oFile);
            fclose(oFile);
            fclose(iFile);
            abort();
        }
        //wyliczenie wartosci z vatem i wypisanie do pliku
        value = atof(buffTmp) * vatValue;
        fprintf(oFile,"%f, ",value);

        if(signBuff != EOF){
            signBuff = getc(iFile);
        }
    }

    //wyslij na wyjscie informacje o poprawnym wykonaniu programu
    sprintf(message,"%s","OK");
    puts(message);
    fputs(message,oFile);

    //zamkniecie plikow
    fclose(iFile);
    fclose(oFile);

    //wykonanie polecenia cmd
    //skopiowanie wygenerowanego pliku wyjsciowego
    //do utworzonego folderu wyjsciowego
    system("mkdir output_files");
    system("cp output.txt output_files");



    return 0;
}