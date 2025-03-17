/*
 funzione principale del programma (che prende come parametro solo la string di input dell'utente). La sua finalità è: creare il dizionario contenente le parole in inglese e in italiano (in ordine alfabetico),
 estrarre i token dalla stringa di input e contare quante parole sono presenti, passare la parola alla funzione che si occupa della traduzione effettiva, analizzare se la traduzione è stata effettuata oppure no;
 in questo caso conto quante volte succede e vi è l'attivazione della funzione che si occupa di aggiornare la stringa di parole non tradotte e sostituire nella stringa finale invece della traduzione dei trattini.

 Una volta terminata la stringa di output, attivo una funzione per rimuovere gli spazi in eccesso a fine stringa (sia per la stringa di output sia per quella delle parole non tradotte) e passo alla funzione competente
 le variabili di conteggio del numero di parole sia tradotte che non (usate per verificare il tipo di output che il programma ha ottenuto) e la stringa di output e delle parole non traducibili.
*/

#include <stdlib.h>
#include <string.h>
#include "libreria.h"  //libreria contenente l'inizializzazione delle funzioni e delle variabili globali condivise tra le funzioni.

    //inizializzazione delle variabili globali.
    int n_parole = 0;  //variabile contatore per il numero di parole DA tradurre.
    int n_mancate_traduzioni = 0;  //variabile contatore per il numero di parole NON traducibili.

    char ENG[200] = "";    //Inizializzazione array di output (frase tradotta IN INGLESE).
    char Parole_Non_Tradotte[200] = "";   //stringa che conterrà tutte le eventuali parole non tradotte.


//funzione principale; parametri: ITA = stringa di input da tradurre.
void traduttore(char *ITA){

    Traduzioni Dizionario[] = {     //Dichiaro l'array di "Traduzioni" e inserisco le parole in italiano assieme alle loro traduzioni.
        {"amico","friend"},         //Le parole sono ordinate in ordine alfabetico.
        {"benvenuto","welcome"},
        {"ciao","hello"},
        {"come","how"},
        {"hai","did you"},
        {"inglese","english"},
        {"mio","of mine"},
        {"prova","test"},
        {"stai", "are you"},
        {"superato","pass"},
        {"tempo","weather"},
    };

    int risultato_ricerca = 0;  //variabile di controllo per il risultato della traduzione di una parola (se è stata tradotta o meno).
    char *parola;      //Inizializzaione della stringa contenente le parole estratte dall'array ITA (frase da tradurre).
    parola = strtok(ITA, " ");    //Estraggo la prima parola.

    while (parola != NULL)  //ciclo finchè non finisco tutte le parole della frase.
    {
        risultato_ricerca = Ricerca_Traduzione(parola, Dizionario, sizeof(Dizionario) / sizeof(Dizionario[0])); //aggiorno la stringa di parole tradotte se posso, e aggiorno la variabile di controllo.

        if(risultato_ricerca == 0)  //controllo se la traduzione è fallita.
            {
                n_mancate_traduzioni += traduzione_fallita(parola);  //aggiorno il numero delle traduzione fallite e aggiorno la lista delle parole non traducibili tramite funzione.
            }

        risultato_ricerca = 0;  //reset della variabile per il prossimo ciclo.
        n_parole++;      //conto quante parole stanno venendo analizzate
        parola = strtok(NULL, " ");     //Ricavo la parola successiva.
    }

    pulizia_stringa();  //funzione per la rimozione degli spazi finali, sia della stringa tradotta sia di quella delle parole non tradotte.

    output();  //funzione per la stampa dell'output finale (frase tradotta).
}
