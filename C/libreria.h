#ifndef LIBRERIA_H
#define LIBRERIA_H

    #define MAX_LETTERE 50 //Numero massimo di lettere di una parola
    #define MAX_FRASE 200  //Lunghezza massima della frase
    #define MAX_PAROLE 50

    typedef struct {        //Definisco la struttura dati di stringhe per le parole in italiano e in inglese.
        char italiano[MAX_LETTERE];  //Parola in italiano.
        char inglese[MAX_LETTERE];   //Parola in inglese.
    }Traduzioni;

    extern Traduzioni Dizionario[MAX_PAROLE]; //Array principale del dizionario.

    extern int n_parole;  //variabile contatore per il numero di parole DA tradurre.
    extern int n_mancate_traduzioni;  //variabile contatore per il numero di parole NON traducibili.

    extern char ENG[MAX_FRASE];    //array di output (frase tradotta IN INGLESE).
    extern char Parole_Non_Tradotte[MAX_FRASE];   //stringa che conterrà tutte le eventuali parole non tradotte.

    //Dichiarazioni delle funzioni
    void traduttore(char *ITA); //funzione principale; parametri: ITA = stringa di input da tradurre.
    int Ricerca_Traduzione(char *p, Traduzioni *Lista, int dim);  //funzione per la traduzione; parametri: p = parola da tradurre, Lista = dizionario contenente le traduzioni, dim = numero di parole.
    int traduzione_fallita(char *p); //funzione per la creazione della lista di parole non tradotte; p = parola non tradotta.
    void pulizia_stringa(); //funzione per rimuovere gli spazi finali dalle stringhe di output; usa variabili globali.
    void output();  //funzione per la stampa dell'output finale; usa variabili globali.


#endif //LIBRERIA_H
