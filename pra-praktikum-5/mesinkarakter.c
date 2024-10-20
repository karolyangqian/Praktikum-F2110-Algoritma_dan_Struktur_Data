#include <stdio.h>
#include "mesinkarakter.h"

static FILE *pita;
static int retval;

char currentChar;
boolean EOP;

void START() {
    // pita = fopen("pitakar.txt", "r");
    pita = stdin;
    ADV();
}
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV() {
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if(EOP) {
        fclose(pita);
    }
}
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */