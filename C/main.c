#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libreria.h" //libreria delle funzioni e variabili usate.

int main()
{
    char input[200];    //Inizializzazione della stringa di input (da tradurre).

    printf("Inserire la frase da tradurre (dove possibile): ");    //Richiedo all'utente la frase da tradurre (DALL' ITALIANO), dove possibile.
    fgets(input, sizeof(input), stdin);     //ottengo la frase da tradurre.
    input[strcspn(input, "\n")] = '\0';    // Rimuovo il carattere di nuova linea aggiunto dal fgets.

    traduttore(input);    //Function principale per la traduzione della frase.

    return 0; //termina il programma.
}
