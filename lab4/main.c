#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <afxres.h>

#define LICZBA_ADRESATOW 400 //stala okreslajaca liczbe adresatow
#define LICZBA_CENTRAL 4 //stala okreslajaca liczbe central

//dane dla generatora stanow automatu
#define PRAWD_CENTRALA_ZAJETA 10 //procentowe prawd. ze centrala jest przeciazona
#define PRAWD_ADRESAT_ZAJETY 30 //procentowe prawd. ze adresat jest zajety

//nadanie nazw dla struktur i wyliczen
typedef struct CENTRALA Centrala;
typedef struct ADRESAT Adresat;
typedef struct LOGBUFF LogBuff;
typedef enum STAN Stan;
typedef enum NAZWAC nazwaCentrali;

//enum STAN - reprezentuje stan adresata lub centrali
enum STAN{ waiting, busy };

//struktura reprezentujaca dresatow
struct ADRESAT{
    unsigned short id;//nr adresata
    Stan stan;//stan adresata
};

//struktura reprezentujaca centrale
struct CENTRALA{
    Adresat adresaci[LICZBA_ADRESATOW/4];//tablica adresatow nalezacych do centrali
    Stan stan;//stan centrali
};

//bufor sluzacy do rejestrowania logow automatu
struct LOGBUFF{
    char obecnaData[64];//lancuch przechowuje date polaczenia
    int adresat;//pole przechowuje nr adresata
    char komunikat[64];//lancuch przechowuje komunikat
};

/*Funkcja nadajAdresatow
 * Nadaje nr-y kolejnym adresatom dla kazdej centrali
 * Parametry:
 *  - Centrala *centrale - wskaznik na tablice central
 *  Zwraca:
 *  - void
 */
void nadajAdresatow(Centrala *centrale){

    for(int i=0; i<LICZBA_CENTRAL;i++){
        for(int j = 0; j < (LICZBA_ADRESATOW/4);j++){
            centrale[i].adresaci[j].id = j+1 + LICZBA_ADRESATOW*0.25*i;
        }
    }
}

/*Funkcja generujStan
 * Generuje stan automatu oparciu o generator liczb pseudolosowych
 * oraz stale PRAWD_CENTRALA ZAJETA i PRAWD_ADRESAT_ZAJETY
 * Parametry:
 *  - Centrala *centrala - wskaznik na tablice central
 * Zwraca:
 *  - void
 */
void generujStan(Centrala *centrale){

    int random;
    for(int i=0;i<LICZBA_CENTRAL;i++){

        //liczba pseudolosowa z zakresu <0,100>
        random = (int)rand()*100/RAND_MAX;

        //generowanie stanu centrali
        if(random < PRAWD_CENTRALA_ZAJETA){
            centrale[i].stan = busy;
        }else{
            centrale[i].stan = waiting;
        }

        //generowanie stanu adresatom centrali
        for(int j =0; j<LICZBA_ADRESATOW/4; j++){

            //liczba pseudolosowa z zakresu <0,100>
            random = (int)rand()*100/RAND_MAX;

            if(random < PRAWD_ADRESAT_ZAJETY){
                centrale[i].adresaci[j].stan = busy;
            }else{
                centrale[i].adresaci[j].stan = waiting;
            }
        }
    }

}

/*Funkcja start
 * Funkcja realizuje prace automatu
 * Parametry:
 *  - Centrala *centrale - wskaznik na tablice central
 *  Zwraca:
 *  - void
 */
void start(Centrala *centrale){

    FILE *logFile = fopen("logFile.dat","w");//plik, do ktorego beda zapisywane logi
    char tmp[32];//bufor przechowujacy kolejne dane wprowadzone w konsoli
    int number;//zmienna przechowujaca dane z konsoli rzutowane na wartosci liczbowe
    time_t obecnaData;//zmienna przechowujaca obecna date
    char *dataString;//zmienna przechowujaca obecna date w lancuchu znakow
    LogBuff bufor;//bufor przechowujacy aktualny log

    //wykonanie w petli nieskonczonej
    while(1){

        /*Generowanie stanu centrali
         *Wypisanie menu
         *Zapisanie danych z konsoli do tmp i number
         */
        generujStan(centrale);
        puts("Menu:\n 1 - nowe polaczenie\t 2 - zakoncz prace\n");
        scanf("%s",tmp);
        number = strtol(tmp,NULL,10);

        //analiza danych z konsoli

        /*Uzytkownik wprowadza "1" - uruchamiany jest automat
         *                     "2" - program konczy prace
         *                     inny znak - komunikat o bledzie i kontynuacja petli
         */
        if(number == 1){

            /*Automat zostaje uruchomiony
             *Wyswietlenie zapytania od wprowadzenie nr-u
             *Przypisanie danych z konsoli do tmp i number
             */
            printf("%s,%d\n","Trwa nasluch, podaj nr z zakresu 1",LICZBA_ADRESATOW);
            scanf("%s",tmp);
            number = strtol(tmp,NULL,10);

            //analiza danych z konsoli

            /*Jezeli podany nr nie miesci sie w mozliwym zakresie lub nie jest poprawna liczba,
             *wyswietlany jest komunikat o bledzie i petla jest kontynuowana
             *Jezeli podany nr jest prawidlowy - symulowane jest nawiazanie polaczenia
             */
            if(number){
                if(number < 1 || number > LICZBA_ADRESATOW){
                    puts("Niepoprawne dane wejsciowe!\n");
                    continue;
                }

                //Symulacja proby nawiazania polaczenia
                puts("Wybrano numer, nawiazuje polaczenie...");
                for(int i = 0; i < 10; i++){
                    printf(".");
                    Sleep(200);
                }
                puts("");

                /*Poszukiwanie wybranego nr-a adresata
                 *Odczytanie stanow centrali oraz adresata
                 *Nadanie odpowiednych wartosci dla pol bufora w zaleznosci od odczytanych stanow
                 *Kontynuacja petli
                 */
                for( int i = 0; i<LICZBA_CENTRAL; i++){
                    for(int j = 0; j<(LICZBA_ADRESATOW/4);j++){
                        if(centrale[i].adresaci[j].id == number){

                            /*Jezeli centrala oczekuje, nastepuje sprawdzenie stanu adresata
                             *W przeciwnym razie do bufora zapisywany jest komunikat o przeciazeniu centrali
                             */
                            if(centrale[i].stan == waiting){

                                /*Przypisanie odpowiedniej wartosci do bufora
                                 *W zaleznosci od stanu adresata
                                 */
                                if(centrale[i].adresaci[j].stan == waiting){
                                    puts("Nawiazano polaczenie. Wcisnij dowolny klawisz i zatwierdz aby zakonczyc.\n");
                                    scanf("%s",tmp);
                                    sprintf(bufor.komunikat,"%s","Nawiazano polaczenie.");

                                }else{
                                    sprintf(bufor.komunikat,"%s","Adresat zajety.");
                                    continue;
                                }
                            }else{
                                sprintf(bufor.komunikat,"%s","Przeciazona centrala");
                                continue;
                            }
                        }
                    }
                }

                //zapisanie obecnej daty
                obecnaData = time(NULL);
                dataString = ctime(&obecnaData);

                //nadanie wartosci pozostalym skladowym bufora
                sprintf(bufor.obecnaData,"%s",dataString);
                bufor.adresat = number;

                //wypisanie stanu bufora do pliku i na wyjscie standardowe
                fprintf(logFile,"%s%d, %s\n",bufor.obecnaData,bufor.adresat,bufor.komunikat);
                printf("%s%d, %s\n",bufor.obecnaData,bufor.adresat,bufor.komunikat);
                continue;

            }else{
                puts("Niepoprawne dane wejsciowe!\n");
                continue;
            }

        }else if(number == 2){
            break;
        }else{
            puts("Niepoprawne dane wejsciowe!\n");
            continue;
        }
    }

    //zamkniecie pliku
    fclose(logFile);
}

int main() {

    //ustawienie generatora liczb pseudolosowych
    srand(time(NULL));

    //tablica central
    Centrala centrale[LICZBA_CENTRAL];

    //przypisanie adresatow poszczegolnym centralom
    nadajAdresatow(centrale);

    //uruchomienie automatu
    start(centrale);

    return 0;
}