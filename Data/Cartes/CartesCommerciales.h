#ifndef CARTES_COMMERCIALES_H
#define CARTES_COMMERCIALES_H

#include "../../Backend/Carte.h"


// 5. Bâtiments commerciaux (cartes jaunes)

extern const Commercial *DEPOT_ARGILE;

extern const Commercial *DEPOT_BOIS;

extern const Commercial *DEPOT_PIERRE;

extern const Commercial *TAVERNE;

extern const Commercial *BRASSERIE;

extern const Commercial *CARAVANSERAIL;

extern const Commercial *DOUANES;

extern const Commercial *FORUM;

extern const Commercial *ARENE;

extern const Commercial *ARMURERIE;

extern const Commercial *CHAMBRE_COMMERCE;

extern const Commercial *PHARE;

extern const Commercial *PORT;


#define CARTES_COMMERCIALES_1 DEPOT_ARGILE, DEPOT_BOIS, DEPOT_PIERRE, TAVERNE
#define CARTES_COMMERCIALES_2 BRASSERIE, CARAVANSERAIL, DOUANES, FORUM
#define CARTES_COMMERCIALES_3 ARENE, ARMURERIE, CHAMBRE_COMMERCE, PHARE, PORT

extern const vector<const Commercial *> CARTES_COMMERCIALES;


#endif
