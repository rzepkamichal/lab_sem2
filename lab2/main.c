#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BUFFER_SIZE 5
#define MAX_ROW_LENGTH 10

/*struktura RingBuffer- reprezentuje bufor cykliczny
 * składowe:
 *  int data[BUFFER_SIZE] //tablica przechowujaca dane
 *  int* pWrite - wskaznik na indeks tablicy, pod ktory aktualnie jest zapisywana dana
 */
struct RingBuffer{
    int data[BUFFER_SIZE];
    int* pWrite;
};

typedef struct DLLIST dlList;
typedef struct TEMPERATURE temperature;
typedef struct WIND wind;
typedef struct PRECIPITATION precipitation;
typedef union WEATHER weather;

struct DLLIST{
    int value;//wartosc
    struct dlList* pPrev;//wskaznik na element poprzedni
    struct dlList* pNext;//wskaznik na element nastepny
};

struct TEMPERATURE{
    int value;
    char units[10];
};

struct WIND{
    int speed;
    char units[10];
};

struct PRECIPITATION{
    int amount;
    char units[10];
};

union WEATHER{
    temperature temp;
    wind wind;
    precipitation precip;
};

enum WeatherValues {TEMP,WIN,PREC};


/*funkcje setTemp, setWind, setPrec
 *sluza do zapisu wartosci do unii
 */
void setTemp(weather conditions, int value, char* units){
    conditions.temp.value = value;
    for(int i = 0;i<10;i++){
        conditions.temp.units[i] = units[i];
    }
}
void setWind(weather conditions, int value, char* units){
    conditions.wind.speed = value;
    for(int i = 0;i<10;i++){
        conditions.wind.units[i] = units[i];
    }
}
void setPrec(weather conditions, int value, char* units){
    conditions.precip.amount = value;
    for(int i = 0;i<10;i++){
        conditions.precip.units[i] = units[i];
    }
}

/*funkcja WriteConditions
 *zapisuje odpowiednia wartosc do unii w zaleznosci od przekazanego parametru
 */
void WriteConditions(weather conditions, enum WeatherValues param, int value, char* units){

    if(param == TEMP){
        setTemp(conditions, value, units);
    }

    if(param == WIN){
        setWind(conditions, value, units);
    }

    if(param == PREC){
        setPrec(conditions, value, units);
    }
}




/*funkcja WriteToFile
 *otrzymana jako parametr wartosc zapisuje do pliku
 * parametry:
 *  int output - wartosc, ktora ma zostac zapisana do pliku
 *  FILE *file - wskaznik na plik docelowy
 * zwraca:
 *  funkcja nic nie zwraca
 */
void WriteToFile(int output, FILE *file){
    fprintf(file,"%d\n",output);
}

/*funkcja WriteToBuff
 *funkcja zapisuje otrzymana przez parametr dana do bufora,
 *dana nadpisywana funkcja zapisuje do pliku (z wykorzystaniem fun. WriteToFile)
 * parametry:
 *  struct RingBuffer* buff - wskaznik na strukture reprezentujacej bufor
 *  int input - dana, ktora ma zostac zapisana w buforze
 *  FILE* file - wskaznik na plik docelowy
 * zmienne:
 *  static int firstCycle - flaga - przekazuje informacje, czy wszystkie elementy tablicy
 *                          przechowujacej dane zostaly juz poprawnie zainicjalizowane
 * zwraca:
 *  funkcja nic nie zwraca
 */
void WriteToBuff(struct RingBuffer *buff, int input, FILE* file){

    static int firstCycle = 1;

    //poza pierwszym cyklem zapisu, wartosci sa nadpisywane
    //wartosc poprzednia zostaje zapisana do pliku
    if(!firstCycle) {
        WriteToFile(*(buff-> pWrite), file);
    }

    //zapisanie (nadpisanie) wartosci w buforze
    *buff-> pWrite = input;

    //jezeli wskaznik wskazuje na ostatni element tablicy,
    //ustaw go spowrotem na pierwszy element
    //w przeciwnym razie - ikrementuj wskaznik
    if(buff-> pWrite == buff-> data + BUFFER_SIZE-1){

        buff-> pWrite = buff-> data;

        //jezeli to pierwszy cykl zapisu, zmien flage na przeciwna
        if(firstCycle){
            firstCycle = 0;
        }

    }else{
        buff-> pWrite++;
    }
}

/*funkcja GenerateTemp
 *generuje pseudolosowa wartosc temperatury interpretowanej
 *w st. Celsjusza z zakresu wartosci [ -50, +50 ]
 * parametry:
 *  - brak
 * zwraca:
 *  wartosc calkowita reprezentujaca temp. w st. Celsjusza
 */
int GenerateTemp(){
    int temperature = (int)(rand()*(1.0/RAND_MAX)*100-50);
    return temperature;
}

/*funkcja PushBack
 *dodaje nowy element na kuniec listy dwukierunkowej
 *parametry:
 *  - dlList** pHead - wskaznik na wskaznik na początek listy
 *  - int value - wartosc, ktora ma byc zapisana w elemencie listy
 *zwraca:
 *  - funkcja nic nie zwraca
 */
void pushBack(dlList** pHead,int value){

    dlList* new_elem = (dlList*) malloc(sizeof(dlList));
    dlList* tmp = *pHead;

    new_elem->value = value;
    new_elem->pNext = NULL;

    if(!(*pHead)){
        new_elem->pPrev = NULL;
        *pHead = new_elem;
    }else{
        while(tmp->pNext){
            tmp = tmp->pNext;
        }

        tmp->pNext = new_elem;
        new_elem->pPrev = tmp;
    }
}

/*funkcja removeList
 *usuwa liste przekazana jako parametr
 * parametry:
 *  - dlList** pHead - wskaznik na wskaznik na poczatek listy
 * zwraca:
 *  - funkcja nic nie zwraca
 */
void removeList(dlList** pHead){

    dlList* tmp = *pHead;

    while(tmp->pNext){
        tmp = tmp->pNext;
    }

    tmp = tmp->pPrev;

    while(tmp){
        free(tmp->pNext);
        tmp = tmp->pPrev;
    }
}

void writeList(dlList** pHead){

    dlList* tmp = *pHead;

    while(tmp){
        printf("%d\n",tmp->value);
        tmp = tmp->pNext;
    }
}



/*funkcja countTemp
 *zapisuje wartosci temp. z pliku do listu dwukierunkowej
 *zlicza wart. temp. wieksze od zadanego parametru
 *parametry:
 * - FILE* file - wskaznik do pliku
 * - int param - zadany parametr
 *zwraca:
 * - wartosc zmiennej int count - ilosc wartosci temp. wiekszych od zadanego parametru
 */
int countTemp(FILE* file, int param){

    dlList* head = NULL;
    int count = 0;

    char buffer[MAX_ROW_LENGTH];
    int value;

    //odczyt z pliku i zapis do listy
    while(fgets(buffer,MAX_ROW_LENGTH,file)){
        value = atoi(buffer);
        pushBack(&head, value);

    }
    //zmienna pomocnicza
    dlList* tmp = head;

    //porownywanie i zliczanie wartosci wiekszych od zadanego parametru
    while(tmp){
        if(tmp->value > param)
            count++;
        tmp = tmp -> pNext;
    }

    removeList(&head);
    return count;
}

int main() {

    dlList* head = NULL;
    srand(time(NULL));//ustawienie punktu startowego generat. liczb pseudolos.

    //buff - wskaznik na strukture reprezentujaca bufor cykliczny
    //alokacja pamieci
    struct RingBuffer* buff = (struct RingBuffer*) malloc(sizeof(struct RingBuffer));
    //buff-> pWrite = (int*) malloc(sizeof(int*));

    //ustawienie wskaznika indeksu zapisu na poczatek tablicy
    buff-> pWrite = buff-> data;

    //otworzenie (ew. utworzenie) pliku do zapisu
    FILE *file = fopen("hist.txt","w");

    //ilosc generowanych temperatur
    int tempAmount = 17;

    //generowanie temperatur i zapis do bufora cyklicznego
    for(int i=0;i<tempAmount;i++){
       WriteToBuff(buff,GenerateTemp(),file);
    }

    //zamkniecie pliku i zwolnienie pamieci
    fclose(file);
    free(buff);

    file = fopen("hist.txt","r");

    int x=countTemp(file, 11);

    printf("\n%d\n",x);

    /*weather conditions;
    enum WeatherValues param = TEMP;
    int value = 15;
    char units[10] = "degree_C";
    WriteConditions(conditions,param,value,units);
    */

    return 0;
}






