#ifndef CARTES_MANUFACTURES_H
#define CARTES_MANUFACTURES_H

#include "../../Backend/Carte.h"


//2. Produits manufacturés (cartes grises)


extern const Manufacture *PRESSE;

extern const Manufacture *VERRERIE;

extern const Manufacture *SECHOIR;

extern const Manufacture *SOUFFLERIE;


#define CARTES_MANUFACTURES_1 PRESSE, VERRERIE
#define CARTES_MANUFACTURES_2 SECHOIR, SOUFFLERIE
#define CARTES_MANUFACTURES_3

extern const vector<const Manufacture *> CARTES_MANUFACTURES;

#endif
