#ifndef JETONS_MILITAIRES_H
#define JETONS_MILITAIRES_H

#include "../Data/UtilsClasses.h"

const JetonMilitaire MOINS_DEUX_PIECES = {"Saccage de 2 pièces",
                                          "L’adversaire perd 2 pièces. Elles sont remises  à la banque. Puis le jeton est remis dans la boîte.\n"
                                          "Si l’adversaire ne possède pas assez de pièces, il perd la totalité de son trésor.",
                                          -2};

const JetonMilitaire MOINS_CINQ_PIECES = {"Saccage de 5 pièces",
                                          "L’adversaire perd 5 pièces. Elles sont remises  à la banque. Puis le jeton est remis dans la boîte.\n"
                                          "Si l’adversaire ne possède pas assez de pièces, il perd la totalité de son trésor.",
                                          -5};

const vector<const JetonMilitaire *> JETONS_MILITAIRES = {&MOINS_DEUX_PIECES, &MOINS_CINQ_PIECES};

#endif