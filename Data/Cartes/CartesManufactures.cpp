#include "CartesManufactures.h"


const Manufacture *PRESSE = new Manufacture(2101,
                                            "Presse",
                                            1,
                                            {SCAucun, 0, SCAucun, 0},
                                            {{Piece, 1}},
                                            Papyrus,
                                            1);
const Manufacture *VERRERIE = new Manufacture(2102,
                                              "Verrerie",
                                              1,
                                              {SCAucun, 0, SCAucun, 0},
                                              {{Piece, 1}},
                                              Verre,
                                              1);

const Manufacture *SECHOIR = new Manufacture(2201,
                                             "Séchoir",
                                             2,
                                             {SCAucun, 0, SCAucun, 0},
                                             {},
                                             Papyrus,
                                             1);

const Manufacture *SOUFFLERIE = new Manufacture(2202,
                                                "Soufflerie",
                                                2,
                                                {SCAucun, 0, SCAucun, 0},
                                                {},
                                                Verre,
                                                1);

const vector<const Manufacture *> CARTES_MANUFACTURES = {CARTES_MANUFACTURES_1,
                                                         CARTES_MANUFACTURES_2,
                                                         CARTES_MANUFACTURES_3};
