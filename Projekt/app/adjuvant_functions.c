#include "adjuvant_functions.h"

//Funkcje sprawdzajace wprowadzane dane faktury
int checkPaymentType(char* data){

    if(strcmp(data,"przelew") == 0){
        return 1;
    }else if(strcmp(data,"karta") == 0){
        return 1;
    }else if(strcmp(data,"gotowka") == 0){
        return 1;
    }else{
        return 0;
    }
}
int checkPaymentState(char* data){

    if(strcmp(data,"tak") == 0){
        return 1;
    }else if(strcmp(data,"nie") == 0){
        return 1;
    }else{
        return 0;
    }
}
int checkConsoleInput(char* data, InvParName param){
    switch(param){
        case State:
            if(checkPaymentState(data))
                return 1;
            else
                return 0;
        case PType:
            if(checkPaymentType(data))
                return 1;
            else
                return 0;
        case ExecutionDate:
            if(checkDate_DMY(data))
                return 1;
            else
                return 0;
        case DeadlineDate:
            if(checkDate_DMY(data))
                return 1;
            else
                return 0;
        default: return 1;
    }
}

//Funkcje sprawdzajace poprawnosc formatu wprowadzonych dat
int checkDate_DMY(char* date){

    char* bufferTmp = malloc(strlen(date) + 1);
    strcpy(bufferTmp,date);

    char* buffer = strtok(bufferTmp,".");
    int numericValue = atoi(buffer);

    if(numericValue >= 1 && numericValue <= 31){

        buffer = strtok(NULL,".");
        numericValue = atoi(buffer);

        if(numericValue >= 1 && numericValue <= 12){

            buffer = strtok(NULL,".");
            numericValue = atoi(buffer);

            if(numericValue >= MIN_YEAR && numericValue <= MAX_YEAR){
                free(bufferTmp);
                return 1;
            }
        }

    }

    free(bufferTmp);
    return 0;

}
int checkDate_MY(char* date){

    char* bufferTmp = malloc(strlen(date) + 1);
    strcpy(bufferTmp,date);
    char* buffer = strtok(bufferTmp,".");

    int numericValue = atoi(buffer);
    if(numericValue >= 1 && numericValue <= 12){

        buffer = strtok(NULL,".");
        numericValue = atoi(buffer);

        if(numericValue >= MIN_YEAR && numericValue <= MAX_YEAR){
            free(bufferTmp);
            return 1;
        }
    }

    free(bufferTmp);
    return 0;

}
int checkDate_Y(char* date){
    char* bufferTmp = malloc(strlen(date) + 1);
    strcpy(bufferTmp,date);
    char* buffer = strtok(bufferTmp,".");
    int numericValue = atoi(buffer);

    if(numericValue >= MIN_YEAR && numericValue <= MAX_YEAR){
        free(bufferTmp);
        return 1;
    }

    free(bufferTmp);
    return 0;
}

//Funkcje porownujace otrzymana date z data bedaca w pamieci
int CompareDates_MY(char *dateEntireFormat, char *dateMY){

    char* entireDateCopy = malloc(strlen(dateEntireFormat) + 1);
    strcpy(entireDateCopy,dateEntireFormat);

    //wskaznik pomocniczy zeby nie zgubic poczatku entireDateCopy
    char* entireDateTmp = strchr(entireDateCopy,'.') + 1;

    if(strcmp(entireDateTmp,dateMY) == 0){
        free(entireDateCopy);
        return 1;
    }else{
        free(entireDateCopy);
        return 0;
    }

}
int CompareDates_Y(char *dateEntireFormat, char *dateY){

    char* entireDateCopy = malloc(strlen(dateEntireFormat) + 1);
    strcpy(entireDateCopy,dateEntireFormat);

    //deklaracja wskaznika pomocniczego zeby uniknac wyciekow
    char* entireDateTmp = strchr(entireDateCopy,'.') +1;

    char* dateMYCopy = malloc(strlen(entireDateTmp) + 1);
    strcpy(dateMYCopy,entireDateCopy);

    //deklaracja wskaznika pomocniczego zeby uniknac wyciekow
    char* dateMYTmp = strchr(dateMYCopy,'.') +1;

    if(strcmp(dateMYTmp,dateY) == 0){
        free(entireDateCopy);
        free(dateMYCopy);
        return 1;
    }else{
        free(entireDateCopy);
        free(dateMYCopy);
        return 0;
    }
}

//
int checkMenuInput(char *data, int max, int min){

    if(strtol(data,NULL,10)){
        int number = strtol(data,NULL,10);

        if(number >= min && number <= max){
            return number;
        }

        return 0;
    }

    return 0;
}

//Funkcje pomocnicze do sprawdzania danych zwiazanych z wprowadzaniem produktow
int isNatural(char* data){

    for(int i = 0; i<strlen(data);i++){
        if(isdigit(data[i])){
            continue;
        }else{
            return 0;
        }
    }

    return 1;
}
int isDecimal(char* data){

    unsigned char dotWasGiven = 0;
    for(int i = 0; i < strlen(data); i++){
        if(isdigit(data[i])){
        }else if(data[i] == '.' && !dotWasGiven && i>0 && i<strlen(data)-1){
            dotWasGiven = 1;
        }else{
            return 0;
        }
    }

    return 1;
}
int checkProductInput(char* data, ProdParName param){
    switch(param){
        case Amount:
            if(isNatural(data))
                return 1;
            else
                return 0;
        case ProdTaxRate:
            if(isNatural(data))
                return 1;
            else
                return 0;
        case ProdNetto:
            if(isDecimal(data))
                return 1;
            else
                return 0;

        default: return 1;
    }
}



