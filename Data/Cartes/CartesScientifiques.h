#ifndef CARTES_SCIENTIFIQUES_H
#define CARTES_SCIENTIFIQUES_H

#include "../../Backend/Carte.h"

//4. Bâtiments scientifiques (cartes vertes)

extern const Scientifique *ATELIER;

extern const Scientifique *APOTHICAIRE;

extern const Scientifique *OFFICINE;

extern const Scientifique *SCRIPTORIUM;

extern const Scientifique *BIBLIOTHEQUE;

extern const Scientifique *DISPENSAIRE;

extern const Scientifique *ECOLE;

extern const Scientifique *LABORATOIRE;

extern const Scientifique *ACADEMIE;

extern const Scientifique *ETUDE;

extern const Scientifique *OBSERVATOIRE;

extern const Scientifique *UNIVERSITE;

#define CARTES_SCIENTIFIQUES_1 ATELIER, APOTHICAIRE, OFFICINE, SCRIPTORIUM
#define CARTES_SCIENTIFIQUES_2 BIBLIOTHEQUE, DISPENSAIRE, ECOLE, LABORATOIRE
#define CARTES_SCIENTIFIQUES_3 ACADEMIE, ETUDE, OBSERVATOIRE, UNIVERSITE

extern const vector<const Scientifique *> CARTES_SCIENTIFIQUES;

#endif
