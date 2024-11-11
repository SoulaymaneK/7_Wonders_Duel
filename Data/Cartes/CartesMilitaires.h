#ifndef CARTES_MILITAIRES_H
#define CARTES_MILITAIRES_H

#include "../../Backend/Carte.h"


//6. Bâtiments militaires (cartes rouges)


extern const Militaire *CASERNE;

extern const Militaire *ECURIES;

extern const Militaire *PALISSADE;

extern const Militaire *TOUR_DE_GARDE;

extern const Militaire *BARAQUEMENTS;

extern const Militaire *CHAMP_DE_TIR;

extern const Militaire *HARAS;

extern const Militaire *MURAILLE;

extern const Militaire *PLACE_ARMES;

extern const Militaire *ARSENAL;

extern const Militaire *ATELIER_SIEGE;

extern const Militaire *CIRQUE;

extern const Militaire *FORTIFICATIONS;

extern const Militaire *PRETOIRE;

#define CARTES_MILITAIRES_1 CASERNE, ECURIES, PALISSADE, TOUR_DE_GARDE
#define CARTES_MILITAIRES_2 BARAQUEMENTS, CHAMP_DE_TIR, HARAS, MURAILLE, PLACE_ARMES
#define CARTES_MILITAIRES_3 ARSENAL, ATELIER_SIEGE, CIRQUE, FORTIFICATIONS, PRETOIRE

extern const vector<const Militaire *> CARTES_MILITAIRES;

#endif
