#ifndef PROJV2_MENU_HANDLER_H
#define PROJV2_MENU_HANDLER_H
#include "data_structures.h"
#include "adjuvant_functions.h"
#include "buffer_operations.h"
#include "file_operations.h"

//--------------------------------------
//FUNKCJE OBSLUGI INTERFEJSU UZYTKOWNIKA
//--------------------------------------

//Wyswietlanie komunikatow ogolnych
/*Funkcje writeErrMessage, writeMainMenuText, writeWelcomeMessagePositive, writeWelcomeMessageNegative
 *@Opis:
 * Ponizsze funkcje realizuja wyswietlanie stosonwych komunikatow na wyjscie standardowe.
 * - writeErrMessage - komunikat o blednych danych wejsciowych
 * - writeMainMenuText - wyswietla tekst menu glownego
 * - writeWelcomeMessagePositive - komunikat o pozytywnym odczycie bazy faktur
 * - writeWelcomeMessegeNegative - komunikat o nieudanym odczycie bazy faktur
 *@Parametry:
 * - brak
 *@Zwraca:
 * - void
*/
void writeErrMessage();
void writeMainMenuText();
void writeWelcomeMessagePositive();
void writeWelcomeMessageNegative();

//Wyswietlanie komunikatow zwiazanych z dodawaniem nowej faktury
/*Funkcje writeSellerInputInstructions, writeBuyerInputInstructions,
 *        writeRemainingInputInstructions, writeInstructions,
 *        writeProductInputInstructions
 *@Opis:
 * Ponizsze funkcje realizuja wyswietlanie stosonwych komunikatow na wyjscie standardowe
 * w zaleznosci od parametru skojarzonego z konkretna skladowa elementu listy faktur lub produktow
 * - writeSellerInputInstructions - prosba o podanie odpowiedniej danej personalnej sprzedawcy
 * - writeBuyerInputInstructions - psoba o podanie odpowiedniej danej personalnej nabywcy
 * - writeRemainingInputInstructions - prosba o podanie pozostalych danych faktury
 * - writeInstructions - wywolanie jednej z trzech powyzszych funkcji w zaleznosci od parametru param
 * - writeProductInputInstructions - prosba o podanie odpowiedniej danej produktu
 *@Parametry:
 * - InvParName param - parametr (enum) skojarzony z konkretna skladowa faktury
 * - ProdParName param - parametr (enum) skojarzony z konkretna skladowa produktu
 *@Zwraca:
 * - void
*/
void writeSellerInputInstrucions(InvParName param);
void writeBuyerInputInstructions(InvParName param);
void writeRemainingInputInstructions(InvParName param);
void writeInstructions(InvParName param);
void writeProductInputInstructions(ProdParName param);

//Wyswietlanie komunikatow zwiazanych wyszukiwaniem faktur
/*Funkcje writeSeekInstructions, writeNoResults
 *@Opis:
 * Ponizsze funkcje realizuja wyswietlanie stosonwych komunikatow na wyjscie standardowe.
 * Komunikaty te sa zwiazane z narzedziem wyszukiwania faktur.
 * - writeSeekInstructions - tekst sub-menu wyszukiwania faktur
 * - writeNoResult - komunikat o braku wynikow wyszukiwania
 *@Parametry:
 * - brak
 *@Zwraca:
 * - void
*/
void writeSeekInstructions();
void writeNoResults();

//Wyswietlanie komunikatow zwiazanych z usuwaniem faktur
/*Funkcja writeDeleteMessage
 *@Opis:
 * Funkcja wyswietla tekst sub-menu usuwania faktury na wyjscie standardowe.
 *@Parametry:
 * - brak
 *@Zwraca:
 * - void
*/
void writeDeleteMessage();

//Realizacja sub-menu dodawania nowej faktury/produktu
/*Funkcja productInputHandler
 *@Opis:
 * Funkcja realizuje narzedzie dodawania nowego produktu.
 * W petli realizowane jest wprowadzanie poszczegolnych danych.
 * Kolejnosc jest scisle ustalona. Funkcje ustawiajace odpowiednie wartosci
 * otrzymujac wartosc licznika petli otrzymuja informacje, ktora skladowa
 * nalezy w danym wywolaniu stawic. Analogicznie wywolywane sa funkcje
 * wyswietlajace odpowiednie instrukcje dla uzytkownika.
 * W przypadku podania danych niepoprawnych wyswietlany jest komunikat o bledzie.
 * Program oczekuje na podanie poprawnej wartosci.
 * Na koncu ustawiane sa pozostale kwoty na podstawie
 * odczytanej wartosci netto i stawki podatku.
 * Po wczytaniu danych dodawany jest nowy produkt do listy.
 *@Parametry:
 * - ProdList** head - wskaznik na wskaznik na poczatek listy produktow
 *@Zwraca:
 * - void
*/
void productInputHandler(ProdList** head);
/*Funkcja handleMenuAfterAdding
 *@Opis:
 * Funkcja realizuje krotkie menu po dodaniu nowego produktu do listy produktow.
 * Menu daje mozliwosc dodania nowego produktu lub zapisu nowej faktury wraz
 * z lista produktow i powrotu do sub-menu dodawania faktur.
 *@Parametry:
 * - brak
 *@Zwraca:
 * - wartosc calkowita bedaca informacja dla funkcji invoiceInputHandler
 *  1 - jezeli uzytkownik wprowadzi "1" (dodanie nowego produktu)
 *  0 - jezeli uzytkownik wprowadzi "2" (powrot do sub-menu dodawania faktur)
*/
int handleMenuAfterAdding();
/*Funkcja invoiceInputHandler
 *@Opis:
 * Funkcja realizuje narzedzie dodawania nowej faktury.
 * Na poczatku generowana jest data wystawienia faktury
 * na podstawie aktualnego czasu oraz ID faktury na podstawie daty.
 * Nastepnie w petli realizowane jest wprowadzanie poszczegolnych danych.
 * Kolejnosc jest scisle ustalona. Funkcje ustawiajace odpowiednie wartosci
 * otrzymujac wartosc licznika petli otrzymuja informacje, ktora skladowa
 * nalezy w danym wywolaniu ustawic. Analogicznie wywolywane sa funkcje
 * wyswietlajace odpowiednie instrukcje dla uzytkownika.
 * W przypadku podania danych nieporawnych wyswietlany jest komunikat o bledzie.
 * Program oczekuje na podanie poprawnej wartosci.
 * Po wczytaniu danych dodawana jest nowa faktura.
 * Nastepnie wywolywane jest narzedzie dodawania produktow do faktury.
 * Program wymusza dodanie co najmniej jednego produktu.
 * Po dodaniu jednego produktu wyswietlane jest krotkie menu
 * dajace mozliwosc dodania kolejnego produktu lub zapisu faktury
 * i powrotu do menu glownego (patrz: funkcja gandleMenuAfterAdding)
 * Po dodaniu produktow funkcja sumuje kwoty na liscie produktow i ustawia kwoty podsumowujace na fakturze.
 *@Parametry:
 * - InvList** head - wskaznik na wskaznik na poczatek listy faktur
 *@Zwraca:
 * - void
*/
void invoiceInputHandler(InvList** head);


//Realizacja sub-menu wyszukiwania faktur
/*Funkcje seekIdHandler, seekDataDMYHandler, seekMYHandler, seekYHandler
 *@Opis:
 * Funkcje dzialaja podobnie, realizuja narzedzie wyszukiwania faktur.
 * - seekIdHandler - wyszukuje faktury o zadanym id
 * - seekDateDMYHandler - wyszukuje faktury o zadanej dacie wystawienia
 *                        w formacie "dd.mm.rrrr"
 * - seekDateMYHandler - wyszukuje faktury o zadanej dacie wystawienia
 *                      w formacie "mm.rrrr"
 * - seekDateYHandler - wyszukuje faktury o zadanej dacie wystawienia
 *                      w formacie "rrrr"
 * Funkcje wyswietlaja instrukcje dla uzytkownika.
 * Nastepnie zadaja wprowadzenia odpowiedniej danej.
 * Sprawdzaja poprawnosc danych i wyswietlaja stosowny komunikat
 * w przypadku blednych danych, zadajac ponownego wprowadzenia.
 * Wyszukiwane i wyswietlane sa faktury spelniajace zadane kryteria.
 * W przypadku, gdy szukana faktura nie istnieje, wyswietlany jest komunikat
 * o braku wyniko wyszukiwania.
 *@Parametry:
 * - InvList** head - wskaznik na wskaznik na poczatek listy produktow
 *@Zwraca:
 * - void
*/
void seekIdHandler(InvList** head);
void seekDateDMYHandler(InvList** head);
void seekDateMYHandler(InvList** head);
void seekDateYHandler(InvList** head);
/*Funkcja seekInvoiceHandler
 *@Opis:
 * Funkcja realizuje sub-menu wyszukiwania faktur
 * Wyswietlana jest tekst menu.
 * Nastepnie w zaleznosci od wybranej przez uzytkownika opcji
 * realizowana jest odpowiednia funkcja wyszukiwania faktury.
 * W przypadku podania blednych danych wyswietlany jest komunikat o bledzie
 * oraz prosba o wprowadzenie poprawnych danych.
 *@Parametry:
 * - InvList** head - wskaznik na wskaznik na poczatek listy produktow
 *@Zwraca:
 * - void
*/
void seekInvoiceHandler(InvList** head);

//Realizacja sub-menu usuwania faktur
/*Funkcja deletingHandler
 *@Opis:
 * Funkcja realizuje narzedzie usuwania faktury,
 * Wyswietlana jest prosba o wprowadzenie ID faktury przeznaczonej do usuniecia.
 * Po wprowadzeniu ID faktura jest wyszukiwana i usuwana z listy.
 * W przypadku wprowadzenia niepoprawnego ID (liczby naturalnej)
 * wyswietlany jest komunikat o bledzie i prosba o wprowadzenie
 * poprawnych danych.
 * Gdy nie ma na liscie faktury o otrzymanym ID,
 * wyswietlany jest komunikat o braku wynikow.
 *@Parametry:
 * - InvList** head - wskaznik na wskaznik na poczatek listy produktow
 *@Zwraca:
 * - void
*/
void deletingHandler(InvList** head);
/*Funkcja deletingMenu
 *@Opis:
 * Funkcja realizujaca sub-menu usuwania faktury.
 * Na poczatku wyswietlany jest tekst menu.
 * Uzytkownik moze wybrac opcje wprowadzania ID faktury
 * przeznaczonej do usuniecia albo opcje powrotu do menu glownego.
 * W przypadku przejscia do podawania ID, wywolywana jest funkcja
 * deletingHandler dla wprowadzonego ID.
 * W innym przypadku realizowany jest powrot do menu glownego.
 * W przypadku wprowadzenia blednych danych wyswietlany jest komunikat
 * o bledzie i prosba o wprowadzenie poprawnych danych.
 *@Parametry:
 * - InvList** head - wskaznik na wskaznik na poczatek listy produktow
 *@Zwraca:
 * - void
*/
void deletingMenu(InvList** head);

//Realizacja menu glownego
/*Funkcja startMainMenu
 *@Opis:
 * Funkcja realizuje menu glowne.
 * Na poczatku podejmowana jest proba odczytu bazy faktur.
 * W zaleznosci od wyniku proby jest wyswietlany odpowiedni komunikat.
 * Nastepnie wyswietlany jest tekst menu.
 * Uzytkownik ma do wyboru nastepujace opcje:
 * wprowadzenie nowej faktury, wyszukanie faktury, usuniecie faktury,
 * wyswietlenie calej bazy faktur,zakonczenie programu z nadpisaniem bazy,
 * zakonczenie programu bez zapisywania.
 * W zaleznosci od wyboru uzytkownika, wywolywana jest odpowiednia funkcja
 * realizujaca odpowiednie sub-menu lub funkcja wyswietlajaca faktury
 * lub funkcja zapisujaca zawartosc listy do pliku.
 * W przypadku wprowadzenia blednych danych wyswietlany jset komunikat
 * o bledzie i prosba o wprowadzenie prawidlowych danych.
 *@Parametry:
 * - char* filePath - ciag znakow bedacy sciezka do pliku
 * - InvList** head - wskaznik na wskaznik na poczatek listy produktow
 *@Zwraca:
 * - void
*/
void startMainMenu(InvList** head,char* filePath);

#endif //PROJV2_MENU_HANDLER_H
