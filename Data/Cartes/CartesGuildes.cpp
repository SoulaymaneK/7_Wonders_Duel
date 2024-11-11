#include "CartesGuildes.h"

const Guilde *ARMATEURS = new Guilde(7001,
                                     "Guilde des Armateurs",
                                     {{Argile,  1},
                                      {Pierre,  1},
                                      {Verre,   1},
                                      {Papyrus, 1}},
                                     EFFET_ARMATEURS);

const Guilde *BATISSEURS = new Guilde(7002,
                                      "Guilde des Batisseurs",
                                      {{Pierre, 2},
                                       {Argile, 1},
                                       {Bois,   1},
                                       {Verre,  1}},
                                      EFFET_BATISSEURS);

const Guilde *COMMERCANTS = new Guilde(7003,
                                       "Guilde des Commercants",
                                       {{Argile,  1},
                                        {Bois,    1},
                                        {Pierre,  1},
                                        {Papyrus, 1}},
                                       EFFET_COMMERCANTS);

const Guilde *MAGISTRATS = new Guilde(7004,
                                      "Guilde des Magistrats",
                                      {{Bois,    2},
                                       {Argile,  1},
                                       {Papyrus, 1}},
                                      EFFET_MAGISTRATS);

const Guilde *SCIENTIFIQUES = new Guilde(7005,
                                         "Guilde des Scientifiques",
                                         {{Argile, 2},
                                          {Bois,   2}},
                                         EFFET_SCIENTIFIQUES);

const Guilde *TACTICIENS = new Guilde(7006,
                                      "Guilde des Tacticiens",
                                      {{Pierre,  2},
                                       {Argile,  1},
                                       {Papyrus, 1}},
                                      EFFET_TACTICIENS);

const Guilde *USURIERS = new Guilde(7007,
                                    "Guilde des Usuriers",
                                    {{Pierre, 2},
                                     {Bois,   2}},
                                    EFFET_USURIERS);
