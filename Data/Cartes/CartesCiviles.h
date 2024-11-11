#ifndef CARTES_CIVILES_H
#define CARTES_CIVILES_H

#include "../../Backend/Carte.h"

// 3. Bâtiments civils (cartes bleues)

extern const Civil *AUTEL;

extern const Civil *BAINS;

extern const Civil *THEATRE;

extern const Civil *AQUEDUC;

extern const Civil *ROSTRES;

extern const Civil *STATUE;

extern const Civil *TEMPLE;

extern const Civil *TRIBUNAL;

extern const Civil *HOTEL_DE_VILLE;

extern const Civil *JARDINS;

extern const Civil *OBELISQUE;

extern const Civil *PALACE;

extern const Civil *PANTHEON;

extern const Civil *SENAT;

#define CARTES_CIVILES_1 AUTEL, BAINS, THEATRE
#define CARTES_CIVILES_2 AQUEDUC, ROSTRES, STATUE, TEMPLE, TRIBUNAL
#define CARTES_CIVILES_3 HOTEL_DE_VILLE, JARDINS, OBELISQUE, PALACE, PANTHEON, SENAT

extern const vector<const Civil *> CARTES_CIVILES;

#endif
