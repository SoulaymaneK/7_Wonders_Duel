#ifndef CARTES_MATIERES_PREMIERES_H
#define CARTES_MATIERES_PREMIERES_H

#include "../../Backend/Carte.h"


//1. Matières premières (cartes marrons)


extern const MatierePremiere *BASSIN_ARGILEUX;

extern const MatierePremiere *CAVITE;

extern const MatierePremiere *CHANTIER;

extern const MatierePremiere *EXPLOITATION;

extern const MatierePremiere *GISEMENT;

extern const MatierePremiere *MINE;

extern const MatierePremiere *BRIQUETERIE;

extern const MatierePremiere *CARRIERE;

extern const MatierePremiere *SCIERIE;


#define CARTES_MATIERES_PREMIERES_1 BASSIN_ARGILEUX, CAVITE, CHANTIER, EXPLOITATION, GISEMENT, MINE
#define CARTES_MATIERES_PREMIERES_2 BRIQUETERIE, CARRIERE, SCIERIE
#define CARTES_MATIERES_PREMIERES_3

extern const vector<const MatierePremiere *> CARTES_MATIERES_PREMIERES;

#endif
