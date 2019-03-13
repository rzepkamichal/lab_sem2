#ifndef PROJV2_ADJUVANT_FUNCTIONS_H
#define PROJV2_ADJUVANT_FUNCTIONS_H
#include "data_structures.h"
#include "list_operations.h"

//---------------------------
//ZESTAW FUNKCJI POMOCNICZYCH
//---------------------------

//Funkcje sprawdzajace wprowadzane dane faktury
/*Funkcja checkPaymentType
 *@Opis:
 * sprawdza, czy podany lancuch znakow to jeden z dopuszczonych rodzajow platnosci:
 * "karta" lub "przelew" lub "gotowka"
 *@Parametry:
 * -char* data - wskaznik na badany lancuch znakow
 *@Zwraca:
 * - wartosc typu calkowitego:
 *  1 - jezeli podany ciag jest jednym z trzech oczekiwanych
 *  0 - w przeciwnym przypadku
*/
int checkPaymentType(char* data);
/*Funkcja checkPaymentState
 *@Opis:
 * sprawdza, czy podany lancuch znakow to jeden z dopuszczonych stanow faktury:
 * "tak" - jesli faktura jest oplacona lub "nie" - w jesli faktura nie jest oplacona
 *@Parametry:
 * -char* data - wskaznik na badany lancuch znakow
 *@Zwraca:
 * - wartosc typu calkowitego:
 *  1 - jezeli podany ciag jest jednym z dwoch oczekiwanych
 *  0 - w przeciwnym przypadku
*/
int checkPaymentState(char* data);
/*Funkcja checkConsoleInput
 *@Opis:
 * sprawdza poprawnosc danych wejsciowych
 * dla przekazanego parametru faktury param
 * w celu sprawdzenia poprawnosci wywolywane moga byc funkcje:
 * - checkPaymentType
 * - checkPaymentState
 * - checkDateDMY
 *@Parametry:
 * -char* data - wskaznik na badany lancuch znakow
 * -InvParName param - parametr (enum) skojarzony z konkretnym parametrem faktury
 *@Zwraca:
 * - wartosc typu calkowitego:
 *  1 - jezeli podany ciag dla podanego parametru jest poprawny
 *  0 - w przeciwnym przypadku
*/
int checkConsoleInput(char* data, InvParName param);

//Funkcje sprawdzajace poprawnosc formatu wprowadzonych dat
/*Funkcje checkDate_DMY, checkDate_MY, checkDate_Y
 *@Opis:
 * Funkcje dzialaja bardzo podobnie.
 * Sprawdzaja, czy dany ciag znakow to poprawnie zapisana data:
 * - dla funkcji checkDate_DMY jest to format "dd.mm.rrrr"
 * - dla funkcji checkDate_MY jest to format "mm.rrrr"
 * - dla funkcji checkDate_Y jest to format "rrrr"
 *@Parametry:
 * -char* date - wskaznik na badany lancuch znakow
 *@Zwraca:
 * - wartosc typu calkowitego:
 *  1 - jezeli podany ciag to poprawnie zapisana data
 *  0 - w przeciwnym przypadku
*/
int checkDate_DMY(char* date);
int checkDate_MY(char* date);
int checkDate_Y(char* date);

//Funkcje porownujace otrzymana date z data bedaca w pamieci
/*Funkcje CompareDates_MY, CopareDates_Y
 *@Opis:
 * Funkcje dzialaja bardzo podobnie.
 * Wyodrebniaja czesc daty w formacie "dd.mm.rrrr" tak,
 * zeby jej format dopasowac do do drugiej daty.
 * Nastepnie wyodrebniona czesc daty i druga data sa porownywane.
 *@Parametry:
 * -char* dateEntireFormat - wskaznik na ciag znakow reprezentujacy date w pelnym formacie
 * -char* dateMY - wskaznik na ciag znakow reprezentujacy date w formacie "mm.rrrr"
 * -char* dateY - wskaznik na ciag znakow reprezentujacy date w formacie "rrrr"
 *@Zwraca:
 * - wartosc typu calkowitego:
 *  1 - jezeli porownane daty (po wyodrebnieniu) sa identyczne
 *  0 - w przeciwnym przypadku
*/
int CompareDates_MY(char *dateEntireFormat, char *dateMY);
int CompareDates_Y(char *dateEntireFormat, char *dateY);
/*Funkcja checkMenuInput
 *@Opis:
 * Funkcja sprawdza, czy dane wejsciowe (oczekiwane liczby naturalne)
 * interpretowane jako komendy menu sa poprawne
 *@Parametry:
 * -char* data - wskaznik na wprowadzony lancuch znakow
 * -int max - najwieksza wartosc mozliwych komend menu
 * -int min - dolny zakres mozliwych komend menu
 *@Zwraca:
 *wartość całkowita:
 *	- wartość liczby z ciągu znaków rzutowana na typ int – gdy badany ciąg jest poprawny
 *	- 0  w przeciwnym przypadku
*/
int checkMenuInput(char *data, int max, int min);

//Funkcje pomocnicze do sprawdzania danych zwiazanych z wprowadzaniem produktow
/*Funkcja isNatural
 *@Opis:
 * Funkcja sprawdza, czy podany ciag znakow to liczba naturalna.
 *@Parametry:
 * -char* data - wskaznik na badany lancuch znakow
 *@Zwraca:
 * - wartosc typu calkowitego:
 *  1 - jezeli podany ciag to liczba naturalna
 *  0 - w przeciwnym przypadku
*/
int isNatural(char* data);
/*Funkcja isDecimal
 *@Opis:
 * Funkcja sprawdza, czy podany ciag znakow to liczba dziesietna bez znaku.
 *@Parametry:
 * -char* data - wskaznik na badany lancuch znakow
 *@Zwraca:
 * - wartosc typu calkowitego:
 *  1 - jezeli podany ciag to oczekiwana liczba dziesietna
 *  0 - w przeciwnym przypadku
*/
int isDecimal(char* data);
/*Funkcja checkProductInput
 *@Opis:
 * Funkcja sprawdza, czy wprowadzona dana
 * skojarzona z parametrem produktu param jest poprawna.
 *@Parametry:
 * -char* data - wskaznik na badany lancuch znakow
 * -ProdParName param - parametr (enum) skojarzony z konkretnym parametrem produktu
 *@Zwraca:
 * - wartosc typu calkowitego:
 *  1 - jezeli podany ciag dla danego parametru jest poprawny
 *  0 - w przeciwnym przypadku
*/
int checkProductInput(char* data, ProdParName param);



#endif //PROJV2_ADJUVANT_FUNCTIONS_H
