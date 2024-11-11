#include "CartesScientifiques.h"

const Scientifique *ATELIER = new Scientifique(4101,
                                               "Atelier",
                                               1,
                                               {SCAucun, 0, SCAucun, 0},
                                               {{Papyrus, 1}},
                                               FilAPlomb,
                                               1);

const Scientifique *APOTHICAIRE = new Scientifique(4102,
                                                   "Apothicaire",
                                                   1,
                                                   {SCAucun, 0, SCAucun, 0},
                                                   {{Verre, 1}},
                                                   Roue,
                                                   1);

const Scientifique *OFFICINE = new Scientifique(4103,
                                                "Officine",
                                                1,
                                                {SCAucun, 0, Engrenage, 4202},
                                                {{Piece, 2}},
                                                Mortier,
                                                0);

const Scientifique *SCRIPTORIUM = new Scientifique(4104,
                                                   "Scriptorium",
                                                   1,
                                                   {SCAucun, 0, Livre, 4201},
                                                   {{Piece, 2}},
                                                   Plume,
                                                   0);

const Scientifique *BIBLIOTHEQUE = new Scientifique(4201,
                                                    "Bibliotheque",
                                                    2,
                                                    {Livre, 4104, SCAucun, 0},
                                                    {{Pierre, 1},
                                                     {Bois,   1},
                                                     {Verre,  1}},
                                                    Plume,
                                                    2);

const Scientifique *DISPENSAIRE = new Scientifique(4202,
                                                   "Dispensaire",
                                                   2,
                                                   {Engrenage, 4103, SCAucun, 0},
                                                   {{Argile, 2},
                                                    {Pierre, 1}},
                                                   Mortier,
                                                   2);

const Scientifique *ECOLE = new Scientifique(4203,
                                             "Ecole",
                                             2,
                                             {SCAucun, 0, Harpe, 4304},
                                             {{Bois,    1},
                                              {Papyrus, 2}},
                                             Roue,
                                             1);

const Scientifique *LABORATOIRE = new Scientifique(4204,
                                                   "Laboratoire",
                                                   2,
                                                   {SCAucun, 0, LampeGenie, 4303},
                                                   {{Bois,  1},
                                                    {Verre, 2}},
                                                   FilAPlomb,
                                                   1);

const Scientifique *ACADEMIE = new Scientifique(4301,
                                                "Academie",
                                                3,
                                                {SCAucun, 0, SCAucun, 0},
                                                {{Pierre, 1},
                                                 {Bois,   1},
                                                 {Verre,  2}},
                                                Horloge,
                                                3);

const Scientifique *ETUDE = new Scientifique(4302,
                                             "Etude",
                                             3,
                                             {SCAucun, 0, SCAucun, 0},
                                             {{Bois,    2},
                                              {Verre,   1},
                                              {Papyrus, 1}},
                                             Horloge,
                                             3);

const Scientifique *OBSERVATOIRE = new Scientifique(4303,
                                                    "Observatoire",
                                                    3,
                                                    {LampeGenie, 4204, SCAucun, 0},
                                                    {{Pierre,  1},
                                                     {Papyrus, 2}},
                                                    Sphere,
                                                    2);

const Scientifique *UNIVERSITE = new Scientifique(4304,
                                                  "Universite",
                                                  3,
                                                  {Harpe, 4203, SCAucun, 0},
                                                  {{Argile,  1},
                                                   {Verre,   1},
                                                   {Papyrus, 1}},
                                                  Sphere,
                                                  2);

const vector<const Scientifique *> CARTES_SCIENTIFIQUES = {CARTES_SCIENTIFIQUES_1,
                                                           CARTES_SCIENTIFIQUES_2,
                                                           CARTES_SCIENTIFIQUES_3};
