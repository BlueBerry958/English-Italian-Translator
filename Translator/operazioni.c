// Funzioni utilizzate dalla funzione principale "dizionario.c".
#include "libreria.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//funzione per la traduzione, sfrutta l'algoritmo di ricerca binaria ricorsiva; parametri: p = parola da tradurre, Lista = dizionario contenente le traduzioni, dim = numero di parole.
int Ricerca_Traduzione(char *p, Traduzioni *Lista, int dim) {
    int medio;

    if (dim == 0) {
        return 0;  //segnala che la traduzione non è stata trovata nel dizionario.
    }

    medio = (dim - 1) / 2;

    if (strcmp(p, Lista[medio].italiano) == 0) {
        strcat(ENG, Lista[medio].inglese);  //se trova la parola, inserisce la traduzione nella stringa di output.
        strcat(ENG, " "); //aggiunge uno spazio.
        return 1;  //segnala alla funzione chiamante che la traduzione è presente.
    } else if (strcmp(p, Lista[medio].italiano) < 0) {
        return Ricerca_Traduzione(p, Lista, medio);
    } else {
        return Ricerca_Traduzione(p, Lista + 1 + medio, dim - medio - 1);
    }
}


//funzione per la creazione della lista di parole non tradotte; p = parola non tradotta.
int traduzione_fallita(char *p) {
    strcat(ENG, "--"); //aggiungi dei tratti per segnalare la traduzione fallita della parola.
    strcat(ENG, " ");

    strcat(Parole_Non_Tradotte, p); //aggiungi la parola alla lista di parole non tradotte.
    strcat(Parole_Non_Tradotte, ", ");

    return 1; //aumenta il counter delle parole non traducibili.
}


//funzione per rimuovere gli spazi finali dalle stringhe di output; usa variabili globali.
void pulizia_stringa() {
    int len = strlen(ENG);
    if (len > 0 && ENG[len - 1] == ' ') {  //rimuovi lo spazio finale e termina la stringa.
        ENG[len - 1] = '\0';
    }

    int len2 = strlen(Parole_Non_Tradotte);
    if (len2 > 0 && Parole_Non_Tradotte[len2 - 2] == ',') { //rimuovi la virgola in eccesso e lo spazio finale e termina la stringa.
        Parole_Non_Tradotte[len2 - 2] = '\0';
    }
}


//funzione per la stampa dell'output finale; usa variabili globali.
void output() {
    if (n_mancate_traduzioni == n_parole)  //se nessuna parola è stata tradotta.
        {
            printf("\nNon e\' stato possibile tradurre la frase (le parole non sono presenti nel dizionario).\n");
        }
    else if (n_mancate_traduzioni != 0)  //se solo alcune parole sono state tradotte.
        {
            printf("\nFrase tradotta: %s.\n", ENG);
            printf("\nNon e\' stato possibile tradurre tutte le parole [N:%d - {%s}].\n", n_mancate_traduzioni, Parole_Non_Tradotte);
        }
    else  //traduzione completa.
        {
            printf("\nFrase tradotta: %s.\n", ENG);
        }
}
