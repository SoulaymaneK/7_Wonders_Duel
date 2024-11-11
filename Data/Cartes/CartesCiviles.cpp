#include "CartesCiviles.h"

const Civil *AUTEL = new Civil(3101,
                               "Autel",
                               1,
                               {SCAucun, 0, Lune, 3204},
                               {},
                               3);


const Civil *BAINS = new Civil(3102,
                               "Bains",
                               1,
                               {SCAucun, 0, Goutte, 3201},
                               {{Pierre, 1}},
                               3);


const Civil *THEATRE = new Civil(3103,
                                 "Theatre",
                                 1,
                                 {SCAucun, 0, Masque, 3203},
                                 {},
                                 3);

const Civil *AQUEDUC = new Civil(3201,
                                 "Aqueduc",
                                 2,
                                 {Goutte, 3102, SCAucun, 0},
                                 {{Pierre, 3}},
                                 5);

const Civil *ROSTRES = new Civil(3202,
                                 "Rostres",
                                 2,
                                 {SCAucun, 0, Batiment, 3306},
                                 {{Pierre, 1},
                                  {Bois,   1}},
                                 4);

const Civil *STATUE = new Civil(3203,
                                "Statue",
                                2,
                                {Masque, 3103, Pilier, 3302},
                                {{Argile, 2}},
                                4);

const Civil *TEMPLE = new Civil(3204,
                                "Temple",
                                2,
                                {Lune, 3101, Soleil, 3305},
                                {{Bois,    1},
                                 {Papyrus, 1}},
                                4);

const Civil *TRIBUNAL = new Civil(3205,
                                  "Tribunal",
                                  2,
                                  {SCAucun, 0, SCAucun, 0},
                                  {{Bois,  2},
                                   {Verre, 1}},
                                  5);

const Civil *HOTEL_DE_VILLE = new Civil(3301,
                                        "Hotel de ville",
                                        3,
                                        {SCAucun, 0, SCAucun, 0},
                                        {{Pierre, 3},
                                         {Bois,   2}},
                                        7);

const Civil *JARDINS = new Civil(3302,
                                 "Jardins",
                                 3,
                                 {Pilier, 3203, SCAucun, 0},
                                 {{Argile, 2},
                                  {Bois,   2}},
                                 6);

const Civil *OBELISQUE = new Civil(3303,
                                   "Obelisque",
                                   3,
                                   {SCAucun, 0, SCAucun, 0},
                                   {{Pierre, 2},
                                    {Verre,  1}},
                                   5);

const Civil *PALACE = new Civil(3304,
                                "Palace",
                                3,
                                {SCAucun, 0, SCAucun, 0},
                                {{Argile, 1},
                                 {Bois,   1},
                                 {Pierre, 1},
                                 {Verre,  2}},
                                7);

const Civil *PANTHEON = new Civil(3305,
                                  "Pantheon",
                                  3,
                                  {Soleil, 3204, SCAucun, 0},
                                  {{Argile,  1},
                                   {Bois,    1},
                                   {Papyrus, 2}},
                                  6);

const Civil *SENAT = new Civil(3306,
                               "Senat",
                               3,
                               {Batiment, 3202, SCAucun, 0},
                               {{Argile,  2},
                                {Pierre,  1},
                                {Papyrus, 1}},
                               5);

const vector<const Civil *> CARTES_CIVILES = {CARTES_CIVILES_1, CARTES_CIVILES_2, CARTES_CIVILES_3};
