#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "carrello.h"
#include "prodotto.h"

// da completare riga ***
void stampaEordina(Carrello c){
	printf("\n-- Stampa carrello originale --\n");
	printCarrello(c);
	printf("\n-- Stampa carrello dopo ordinamento per prezzo finale --\n");

	// *** inserire qui la chiamata all'operatore che ordina il carrello
    sortbyPrezzo(c);
	
	printCarrello(c);
	printf("\n\n");
}

// funzione che restituisce un numero intero tra 0 e 50 (percentuale di sconto)
int randomSconto() {
	return (rand() % 51);
}

int main() { 
	srand(time(NULL)); 

	Carrello c1 = createCarrello("Carrello vuoto");
	stampaEordina(c1);

	// 2. Carrello singolo (1 prodotto, sconto 10)
	Carrello c2 = createCarrello("Carrello singolo");
	Prodotto p_singolo = initProdotto("Maglietta", "Abbigliamento", 20.00);
	setSconto(p_singolo, 10);
	addProdotto(c2, p_singolo);
	stampaEordina(c2);

	// 3. Carrello base (2 prodotti, sconto 0 e 20)
	// Inserisco al contrario: Torta, poi Pane
	Carrello c3 = createCarrello("Carrello base");
	Prodotto p_torta = initProdotto("Torta", "Dolci", 10.00); setSconto(p_torta, 20);
	Prodotto p_pane = initProdotto("Pane", "Alimentari", 4.00); setSconto(p_pane, 0);
	addProdotto(c3, p_torta);
	addProdotto(c3, p_pane);
	stampaEordina(c3);

	// 4. Carrello spesa media
	// Inserisco al contrario per rispecchiare la stampa iniziale dell'esempio: Bistecca, Pasta, Patatine, Acqua
	Carrello c4 = createCarrello("Carrello spesa media");
	Prodotto p_bistecca = initProdotto("Bistecca", "Carne", 15.00); setSconto(p_bistecca, 10);
	Prodotto p_pasta = initProdotto("Pasta", "Alimentari", 1.50); setSconto(p_pasta, 0);
	Prodotto p_patatine = initProdotto("Patatine", "Snack", 3.00); setSconto(p_patatine, 50);
	Prodotto p_acqua = initProdotto("Acqua", "Bevande", 2.00); setSconto(p_acqua, 0);
	addProdotto(c4, p_bistecca);
	addProdotto(c4, p_pasta);
	addProdotto(c4, p_patatine);
	addProdotto(c4, p_acqua);
	stampaEordina(c4);

	// 5. Carrello casuale
	Carrello c5 = createCarrello("Carrello casuale");
	Prodotto p5 = initProdotto("Prodotto5", "Cat5", 50.00); setSconto(p5, randomSconto());
	Prodotto p4 = initProdotto("Prodotto4", "Cat4", 40.00); setSconto(p4, randomSconto());
	Prodotto p3 = initProdotto("Prodotto3", "Cat3", 30.00); setSconto(p3, randomSconto());
	Prodotto p2 = initProdotto("Prodotto2", "Cat2", 20.00); setSconto(p2, randomSconto());
	Prodotto p1 = initProdotto("Prodotto1", "Cat1", 10.00); setSconto(p1, randomSconto());
	addProdotto(c5, p5);
	addProdotto(c5, p4);
	addProdotto(c5, p3);
	addProdotto(c5, p2);
	addProdotto(c5, p1);
	stampaEordina(c5);
    return 0;
}