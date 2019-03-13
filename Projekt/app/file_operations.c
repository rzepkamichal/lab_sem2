#include "file_operations.h"

//Odczyt bazy z pliku do listy
int ReadDataBase(char *fileName, InvList** head){

    //ustawienie wartosci zwracanej na 0
    int returnValue = 0;

    //otwarcie pliku
    FILE *iFile = fopen(fileName,"r");

    //jezeli nie udalo sie otworzyc pliku
    if(!iFile){
        return returnValue;
    }

    //wczytanie zawartosci pliku do bufora fileBuffer
    fseek(iFile,0,SEEK_END);
    long fileBufferSize = ftell(iFile);
    char* fileBuffer = malloc(fileBufferSize+1);
    fseek(iFile,0,SEEK_SET);
    fread(fileBuffer,sizeof(char),fileBufferSize,iFile);
    fileBuffer[fileBufferSize] = '\0';

    //zamkniecie pliku
    fclose(iFile);

    //deklaracja potrzebnych zmiennych
    char* dataBuffer = strtok(fileBuffer,","); //bufor na poszczegolne dane rozdzielone przecinkiem
    InvoiceParameters invBuff; //bufor na parametry faktury
    ProductParameters prodBuff; //bufor na parametry produktu
    InvList* headTmp = NULL; //zmienna pomocnicza na zapamietanie ostaniego elementu listy faktur
    int calculate = 0; //licznik petli
    unsigned short prodsAreBeeingRead = 0; //flaga informujaca, czy sa odczytywane produkty

    //petla odczytujaca dane z pliku
    while(dataBuffer) {

        //odczytany jest znak nowej linii
        if (strcmp("\n", dataBuffer) == 0) {
            prodsAreBeeingRead = 0; //ustawienie flagi
            dataBuffer = strtok(NULL,","); //pobranie kolejnego znaku - rozpoczecie wczytywania nowej faktury
            calculate = 0; //zerowanie licznika petli
            continue;

        //odczytany jest kolejny parametr faktury lub produktu
        }else{

            //sa odczytywane produkty
            if(prodsAreBeeingRead){

                //ustawienie skladowej bufora produktow
                setProdBuffParams(&prodBuff,(ProdParName)calculate,dataBuffer);

                //ostatnia dana
                if(calculate == ProdBrutto){
                    //dodanie nowego produktu
                    appendProduct(&(headTmp->headProducts),&prodBuff);
                    //zwolnienie bufora produktow
                    freeProductBuffer(&prodBuff);
                    // zerowanie licznika petli
                    calculate = 0;

                //kontynuuacja odczytu produktow
                }else{
                    calculate++;
                }

            //odczytywane sa parametry faktury
            }else{

                //ustawienie odpowiedniej skladowej bufora faktur
                setInvBuffParams(&invBuff, (InvParName) calculate, dataBuffer, NULL);

                //ostatnia dana
                if(calculate == DeadlineDate){

                    //dodanie nowej faktury
                    appendInvoice(&(*head), &invBuff);

                    //ustawienie wartosci wskaznika na ostatni element
                    if(!(*head)->next){
                        headTmp = *head;
                    }else{
                        headTmp = headTmp-> next;
                    }

                    //zwolnienie bufora faktur
                    freeInvoiceBuffer(&invBuff);

                    //ustawienie flagi na odczyt produktow
                    prodsAreBeeingRead = 1;
                    //zerowanie licznika petli
                    calculate = 0;
                    //odczytano co najmniej jedna fakture - wartosc zwracana ustawiona na 1
                    returnValue = 1;

                }else{
                    calculate++;
                }
            }
        }

        dataBuffer = strtok(NULL,",");
    }
    //zwolnienie bufora przechowujacego zawartosci pliku
    free(fileBuffer);
    return returnValue;
}

//Zapisanie danych z listy do pliku
void writeProductToFile(FILE* oFile,ProdList** head){

    if(!(*head)){
        return;
    }else{
        fprintf(oFile,"%d,",(*head)->data.id);
        fprintf(oFile,"%s,",(*head)->data.name);
        fprintf(oFile,"%d,",(*head)->data.amount);
        fprintf(oFile,"%d,",(*head)->data.taxRate);
        fprintf(oFile,"%d,",(*head)->data.nettoCost);
        fprintf(oFile,"%d,",(*head)->data.taxCost);
        fprintf(oFile,"%d,",(*head)->data.bruttoCost);
        writeProductToFile(oFile,&((*head)->next));
    }
}
void writeInvToFile(FILE* oFile,InvList** head){

    if(!(*head)){
        return;
    }else{
        fprintf(oFile,"%s,",(*head)->data.id);

        fprintf(oFile,"%s,",(*head)->data.seller.name);
        fprintf(oFile,"%s,",(*head)->data.seller.surename);
        fprintf(oFile,"%s,",(*head)->data.seller.street);
        fprintf(oFile,"%s,",(*head)->data.seller.housNumber);
        fprintf(oFile,"%s,",(*head)->data.seller.city);
        fprintf(oFile,"%s,",(*head)->data.seller.postCode);
        fprintf(oFile,"%s,",(*head)->data.seller.mail);
        fprintf(oFile,"%s,",(*head)->data.seller.nipCode);
        fprintf(oFile,"%s,",(*head)->data.seller.accountNumber);

        fprintf(oFile,"%s,",(*head)->data.buyer.name);
        fprintf(oFile,"%s,",(*head)->data.buyer.surename);
        fprintf(oFile,"%s,",(*head)->data.buyer.street);
        fprintf(oFile,"%s,",(*head)->data.buyer.housNumber);
        fprintf(oFile,"%s,",(*head)->data.buyer.city);
        fprintf(oFile,"%s,",(*head)->data.buyer.postCode);
        fprintf(oFile,"%s,",(*head)->data.buyer.mail);
        fprintf(oFile,"%s,",(*head)->data.buyer.nipCode);
        fprintf(oFile,"%s,",(*head)->data.buyer.accountNumber);

        if((*head)->data.paymentType == CARD){
            fprintf(oFile,"%s,","karta");
        }else if((*head)->data.paymentType == CASH){
            fprintf(oFile,"%s,","gotowka");
        }else {
            fprintf(oFile, "%s,", "przelew");
        }

        fprintf(oFile,"%d,",(*head)->data.nettoSum);
        fprintf(oFile,"%d,",(*head)->data.vatSum);
        fprintf(oFile,"%d,",(*head)->data.bruttoSum);

        if((*head)->data.state == PAID){
            fprintf(oFile,"%s,","tak");
        }else{
            fprintf(oFile,"%s,","nie");
        }

        fprintf(oFile,"%s,",(*head)->data.issueDate);
        fprintf(oFile,"%s,",(*head)->data.executionDate);
        fprintf(oFile,"%s,",(*head)->data.deadlineDate);
        writeProductToFile(oFile,&((*head)->headProducts));
        fprintf(oFile,"%s,","\n");

        writeInvToFile(oFile,&((*head)->next));
    }
}
int SaveDataBase(char *fileName, InvList** head){

    FILE* oFile = fopen(fileName,"w");

    //pliku nie udalo sie otworzyc lub utworzyc
    if(!oFile){
        return 0;
    }

    //zapis do pliku i zamkniecie
    writeInvToFile(oFile,&(*head));
    fclose(oFile);
    return 1;
}
