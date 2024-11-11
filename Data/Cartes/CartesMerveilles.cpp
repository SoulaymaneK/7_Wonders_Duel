#include "CartesMerveilles.h"

const Merveille *CIRCUS_MAXIMUS = new Merveille(8001,
                                                "Le Circus Maximus",
                                                {{Pierre, 2},
                                                 {Bois,   1},
                                                 {Verre,  1}},
                                                1,
                                                3,
                                                0,
                                                EFFETS_CIRCUS_MAXIMUS);


const Merveille *LE_COLOSSE = new Merveille(8002,
                                            "Le Colosse",
                                            {{Argile, 3},
                                             {Verre,  1}},
                                            2,
                                            3,
                                            0,
                                            EFFETS_COLOSSE);

const Merveille *GRANDE_BIBLIOTHEQUE = new Merveille(8003,
                                                     "La Grande Bibliotheque",
                                                     {{Bois,    3},
                                                      {Verre,   1},
                                                      {Papyrus, 1}},
                                                     0,
                                                     4,
                                                     0,
                                                     EFFETS_GRANDE_BIBLIOTHEQUE);

const Merveille *GRAND_PHARE = new Merveille(8004,
                                             "Le Grand Phare",
                                             {{Bois,    1},
                                              {Pierre,  1},
                                              {Papyrus, 2}},
                                             0,
                                             4,
                                             0,
                                             EFFETS_GRAND_PHARE);

const Merveille *JARDINS_SUSPENDUS = new Merveille(8005,
                                                   "Les Jardins suspendus",
                                                   {{Bois,    2},
                                                    {Verre,   1},
                                                    {Papyrus, 1}},
                                                   0,
                                                   3,
                                                   6,
                                                   EFFETS_JARDINS_SUSPENDUS);

const Merveille *MAUSOLEE = new Merveille(8006,
                                          "Le Mausolee",
                                          {{Argile,  2},
                                           {Verre,   2},
                                           {Papyrus, 1}},
                                          0,
                                          2,
                                          0,
                                          EFFETS_MAUSOLEE);

const Merveille *PIREE = new Merveille(8007,
                                       "Le Piree",
                                       {{Argile, 1},
                                        {Pierre, 1},
                                        {Bois,   2}},
                                       0,
                                       2,
                                       0,
                                       EFFETS_PIREE);


const Merveille *LES_PYRAMIDES = new Merveille(8008,
                                               "Les Pyramides",
                                               {{Pierre,  3},
                                                {Papyrus, 1}},
                                               0,
                                               9,
                                               0,
                                               EFFETS_PYRAMIDES);

const Merveille *SPHINX = new Merveille(8009,
                                        "Le Sphinx",
                                        {{Argile, 1},
                                         {Pierre, 1},
                                         {Verre,  1}},
                                        0,
                                        6,
                                        0,
                                        EFFETS_SPHINX);

const Merveille *STATUE_DE_ZEUS = new Merveille(8010,
                                                "La Statue de Zeus",
                                                {{Argile,  1},
                                                 {Bois,    1},
                                                 {Pierre,  1},
                                                 {Papyrus, 2}},
                                                1,
                                                3,
                                                0,
                                                EFFETS_STATUE_ZEUS);

const Merveille *TEMPLE_D_ARTEMIS = new Merveille(8011,
                                                  "Le Temple d'Artemis",
                                                  {{Bois,    1},
                                                   {Pierre,  1},
                                                   {Verre,   1},
                                                   {Papyrus, 1}},
                                                  0,
                                                  0,
                                                  12,
                                                  EFFETS_TEMPLE_ARTEMIS);

const Merveille *VIA_APPIA = new Merveille(8012,
                                           "La Via Appia",
                                           {{Argile,  2},
                                            {Pierre,  2},
                                            {Papyrus, 1}},
                                           0,
                                           3,
                                           3,
                                           EFFETS_VIA_APPIA);


const vector<const Merveille *> CARTES_MERVEILLES = {
        CIRCUS_MAXIMUS, LE_COLOSSE, GRANDE_BIBLIOTHEQUE,
        GRAND_PHARE, JARDINS_SUSPENDUS, MAUSOLEE, PIREE, LES_PYRAMIDES,
        SPHINX, STATUE_DE_ZEUS, TEMPLE_D_ARTEMIS, VIA_APPIA};
