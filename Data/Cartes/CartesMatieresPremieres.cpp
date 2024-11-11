#include "CartesMatieresPremieres.h"

const MatierePremiere *BASSIN_ARGILEUX = new MatierePremiere(1101,
                                                             "Bassin argileux",
                                                             1,
                                                             {SCAucun, 0, SCAucun, 0},
                                                             {},
                                                             Argile,
                                                             1);

const MatierePremiere *CAVITE = new MatierePremiere(1102,
                                                    "Cavite",
                                                    1,
                                                    {SCAucun, 0, SCAucun, 0},
                                                    {{Piece, 1}},
                                                    Argile,
                                                    1);

const MatierePremiere *CHANTIER = new MatierePremiere(1103,
                                                      "Chantier",
                                                      1,
                                                      {SCAucun, 0, SCAucun, 0},
                                                      {},
                                                      Bois,
                                                      1);

const MatierePremiere *EXPLOITATION = new MatierePremiere(1104,
                                                          "Exploitation",
                                                          1,
                                                          {SCAucun, 0, SCAucun, 0},
                                                          {{Piece, 1}},
                                                          Bois,
                                                          1);

const MatierePremiere *GISEMENT = new MatierePremiere(1105,
                                                      "Gisement",
                                                      1,
                                                      {SCAucun, 0, SCAucun, 0},
                                                      {},
                                                      Pierre,
                                                      1);

const MatierePremiere *MINE = new MatierePremiere(1106,
                                                  "Mine",
                                                  1,
                                                  {SCAucun, 0, SCAucun, 0},
                                                  {{Piece, 1}},
                                                  Pierre,
                                                  1);

const MatierePremiere *BRIQUETERIE = new MatierePremiere(1201,
                                                         "Briqueterie",
                                                         2,
                                                         {SCAucun, 0, SCAucun, 0},
                                                         {{Piece, 2}},
                                                         Argile,
                                                         2);

const MatierePremiere *CARRIERE = new MatierePremiere(1202,
                                                      "Carriere",
                                                      2,
                                                      {SCAucun, 0, SCAucun, 0},
                                                      {{Piece, 2}},
                                                      Pierre,
                                                      2);

const MatierePremiere *SCIERIE = new MatierePremiere(1203,
                                                     "Scierie",
                                                     2,
                                                     {SCAucun, 0, SCAucun, 0},
                                                     {{Piece, 2}},
                                                     Bois,
                                                     2);

const vector<const MatierePremiere *> CARTES_MATIERES_PREMIERES = {CARTES_MATIERES_PREMIERES_1,
                                                                   CARTES_MATIERES_PREMIERES_2,
                                                                   CARTES_MATIERES_PREMIERES_3};
