#ifndef PROJV2_FILE_OPERATIONS_H
#define PROJV2_FILE_OPERATIONS_H
#include "data_structures.h"
#include "buffer_operations.h"
#include "list_operations.h"

//----------------------
//FUNKCJE OBSLUGI PLIKOW
//----------------------

//Odczyt bazy z pliku do listy
/*Funkcja ReadDataBase
 *@Opis:
 * Funkcja otwiera plik, ktorego sciezka jest podana jako parametr.
 * Poprawnosc danych w pliku nie jest sprawdzana, jako ze z zalozenia
 * dane do pliku sa generowane jedynie za posrednictwem programu, co wymusza
 * prawidlowosc danych - glownie ich scisle okreslona kolejnosc.
 * Funkcja odczytuje zawartosc pliku do bufora i zamyka plik.
 * Z bufora sa pobierane kolejne dane oddzielone przecinkiem
 * do bufora parametrow faktury lub bufora parametrow produktu.
 * Poszczegolne faktury sa oddzielone nowa linia.
 * Po odczytaniu kolejnych produktow lub faktur tworzony jest nowy element listy,
 * Jego skladowe sa ustawiane przez skopiowanie zawartosci bufora.
 * Po dodaniu nowego elementu, bufory sa zwalniane i odczyt jest kontynuuowany
 * az do napotkania znaku konca pliku.
 * Zliczane sa obiego petli. Funkcje ustawiajace odpowiednie wartosci buforow
 * otrzymuja informacje, ktory parametr nalezy ustawic, za posrednictwem
 * licznika petli - zmiennej calculate. Zabieg ten jest umozliwiony
 * dzieki scisle ustalonej kolejnosci danych wystepujacej w pliku.
 * W celu zapisywania danych do listy funkcja ReadDataBase wywoluje
 * funkcje obslugi buforow oraz funkcje obslugi list.
 *@Parametry:
 * - char* fileName - ciag znakow bedacy sciezka do pliku
 * - InvList** head - wskaznik na wskaznik pierwszego elementu listy faktur
 *@Zwraca:
 * - warosc calkowita zapisana w zmiennej returnValue:
 *  - 1 - jezeli odczyt sie powiedzie
 *  - 0 - jezeli pliku nie da sie otworzyc lub plik jest pusty
*/
int ReadDataBase(char *fileName, InvList **head);

//Zapisanie danych z listy do pliku
/*Funkcja writeProductToFile
 *@Opis:
 * Jest to funkcja pomocnicza zapisujaca dane lity produktow do pliku.
 * Kolejnosc zapisu jest scisle okreslona.
 *@Parametry:
 * - FILE* oFile - wskaznik na plik wyjsciowy
 * - ProdList** head - wskaznik na wskaznik na poczatek listy produktow
 *@Zwraca:
 * - void
*/
void writeProductToFile(FILE* oFile,ProdList** head);
/*Funkcja writeProductToFile
 *@Opis:
 * Jest to funkcja pomocnicza zapisujaca dane listy faktur do pliku.
 * Kolejnosc zapisu jest scisle okreslona.
 * Funkcja wywoluje funkcje writeProductToFile w celu zapisu
 * listy produktow poszczegolnych elementow listy faktur do pliku.
 *@Parametry:
 * - FILE* oFile - wskaznik na plik wyjsciowy
 * - InvList** head - wskaznik na wskaznik na poczatek listy faktur.
 *@Zwraca:
 * - void
*/
void writeInvToFile(FILE* oFile,InvList** head);
/*Funkcja SaveDataBase
 *@Opis:
 * Funkcja otwiera plik ktorego sciezka
 * jest przekazana jako parametr w trybie zapisu.
 * Nastepnie wywoluje funkcje writeInvToFile realizujaca
 * zapis danych z listy faktur do pliku.
 *@Parametry:
 * - char* fileName - wskaznik na ciag znakow bedacy sciezka do pliku wyjsciowego
 * - InvList** head - wskaznik na wskaznik na poczatek listy faktur
 *@Zwraca:
 * - wartosc calkowita:
 *  1 - jezeli uda sie zapisac dane do pliku
 *  0 - jezeli sciezka do pliku jest nieprawidlowa
 *      (gdy sciezka ma poprawny format lecz plik nie istnieje, tworzony jest nowy)
*/
int SaveDataBase(char* fileName, InvList **head);

#endif
