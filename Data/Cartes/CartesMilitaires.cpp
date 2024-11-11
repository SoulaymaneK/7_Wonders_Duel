#include "CartesMilitaires.h"

const Militaire *CASERNE = new Militaire(6101,
                                         "Caserne",
                                         1,
                                         {SCAucun, 0, Epee, 6201},
                                         {{Argile, 1}},
                                         1);

const Militaire *ECURIES = new Militaire(6102,
                                         "Ecuries",
                                         1,
                                         {SCAucun, 0, FerACheval, 6203},
                                         {{Bois, 1}},
                                         1);

const Militaire *PALISSADE = new Militaire(6103,
                                           "Palissade",
                                           1,
                                           {SCAucun, 0, Tour, 6304},
                                           {{Piece, 2}},
                                           1);

const Militaire *TOUR_DE_GARDE = new Militaire(6104,
                                               "Tour de garde",
                                               1,
                                               {SCAucun, 0, SCAucun, 0},
                                               {},
                                               1);


const Militaire *BARAQUEMENTS = new Militaire(6201,
                                              "Baraquements",
                                              2,
                                              {Epee, 6101, SCAucun, 0},
                                              {{Piece, 3}},
                                              1);

const Militaire *CHAMP_DE_TIR = new Militaire(6202,
                                              "Champ de tir",
                                              2,
                                              {SCAucun, 0, Cible, 6302},
                                              {{Pierre,  1},
                                               {Bois,    1},
                                               {Papyrus, 1}},
                                              2);

const Militaire *HARAS = new Militaire(6203,
                                       "Haras",
                                       2,
                                       {FerACheval, 6102, SCAucun, 0},
                                       {{Argile, 1},
                                        {Bois,   1}},
                                       1);

const Militaire *MURAILLE = new Militaire(6204,
                                          "Muraille",
                                          2,
                                          {SCAucun, 0, SCAucun, 0},
                                          {{Pierre, 2}},
                                          2);

const Militaire *PLACE_ARMES = new Militaire(6205,
                                             "Place d'armes",
                                             2,
                                             {SCAucun, 0, Casque, 6303},
                                             {{Argile, 2},
                                              {Verre,  1}},
                                             2);


const Militaire *ARSENAL = new Militaire(6301,
                                         "Arsenal",
                                         3,
                                         {SCAucun, 0, SCAucun, 0},
                                         {{Argile, 3},
                                          {Bois,   2}},
                                         3);

const Militaire *ATELIER_SIEGE = new Militaire(6302,
                                               "Atelier de siege",
                                               1,
                                               {Cible, 6202, SCAucun, 0},
                                               {{Bois,  3},
                                                {Verre, 1}},
                                               2);

const Militaire *CIRQUE = new Militaire(6303,
                                        "Cirque",
                                        3,
                                        {Casque, 6205, SCAucun, 0},
                                        {{Argile, 2},
                                         {Pierre, 2}},
                                        2);

const Militaire *FORTIFICATIONS = new Militaire(6304,
                                                "Fortifications",
                                                3,
                                                {Tour, 6103, SCAucun, 0},
                                                {{Pierre,  2},
                                                 {Argile,  1},
                                                 {Papyrus, 1}},
                                                2);

const Militaire *PRETOIRE = new Militaire(6305,
                                          "Pretoire",
                                          3,
                                          {SCAucun, 0, SCAucun, 0},
                                          {{Piece, 8}},
                                          3);


const vector<const Militaire *> CARTES_MILITAIRES = {CARTES_MILITAIRES_1,
                                                     CARTES_MILITAIRES_2,
                                                     CARTES_MILITAIRES_3};
