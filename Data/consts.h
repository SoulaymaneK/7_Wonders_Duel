#ifndef CONSTS_H
#define CONSTS_H

#include "UtilsClasses.h"

#include "Jetons/JetonsMilitaires.h"
#include "Jetons/JetonsProgres.h"

#include "Cartes/CartesCiviles.h"
#include "Cartes/CartesCommerciales.h"
#include "Cartes/CartesGuildes.h"
#include "Cartes/CartesManufactures.h"
#include "Cartes/CartesMatieresPremieres.h"
#include "Cartes/CartesMerveilles.h"
#include "Cartes/CartesMilitaires.h"
#include "Cartes/CartesScientifiques.h"


// Constantes Joueur.h

#define TOTAL_PIECES_DEPART 7

// Constantes Carte.h


extern vector<const Carte *> CARTES_AGE_1;

extern vector<const Carte *> CARTES_AGE_2;

extern vector<const Carte *> CARTES_AGE_3;

// ----------------------------


// Constantes Plateau.h

#define ARRIVEE_PION_CONFLIT 9
#define NB_JETONS_PROGRES 5

#include <map>
#include <vector>

const map<int, std::vector<int>> DICT_EMPLACEMENTS_AGE_1 = {
        {0,  {2,  3}},
        {1,  {3,  4}},
        {2,  {5,  6}},
        {3,  {6,  7}},
        {4,  {7,  8}},
        {5,  {9,  10}},
        {6,  {10, 11}},
        {7,  {11, 12}},
        {8,  {12, 13}},
        {9,  {14, 15}},
        {10, {15, 16}},
        {11, {16, 17}},
        {12, {17, 18}},
        {13, {18, 19}},
        {14, {}},
        {15, {}},
        {16, {}},
        {17, {}},
        {18, {}},
        {19, {}},
};

const map<int, std::vector<int>> DICT_EMPLACEMENTS_AGE_2 = {
        {0,  {6}},
        {1,  {6,  7}},
        {2,  {7,  8}},
        {3,  {8,  9}},
        {4,  {9,  10}},
        {5,  {10}},
        {6,  {11}},
        {7,  {11, 12}},
        {8,  {12, 13}},
        {9,  {13, 14}},
        {10, {14}},
        {11, {15}},
        {12, {15, 16}},
        {13, {16, 17}},
        {14, {17}},
        {15, {18}},
        {16, {18, 19}},
        {17, {19}},
        {18, {}},
        {19, {}},
};

const map<int, std::vector<int>> DICT_EMPLACEMENTS_AGE_3 = {
        {0,  {2,  3}},
        {1,  {3,  4}},
        {2,  {5,  6}},
        {3,  {6,  7}},
        {4,  {7,  8}},
        {5,  {9}},
        {6,  {9}},
        {7,  {10}},
        {8,  {10}},
        {9,  {11, 12}},
        {10, {13, 14}},
        {11, {15}},
        {12, {15, 16}},
        {13, {16, 17}},
        {14, {17}},
        {15, {18}},
        {16, {18, 19}},
        {17, {19}},
        {18, {}},
        {19, {}},
};


const vector<int> LISTE_EMPLACEMENTS_CACHES_AGE_1 = {3, 4, 5, 10, 11, 12, 13, 14};

const vector<int> LISTE_EMPLACEMENTS_CACHES_AGE_2 = {7, 8, 9, 10, 11, 16, 17, 18};

const vector<int> LISTE_EMPLACEMENTS_CACHES_AGE_3 = {3, 4, 5, 10, 11, 16, 17, 18};

// ----------------------------

// Constantes Jeu.h

#define NB_SYMB_SCI_DIFF_VICTOIRE_SCIENTIFIQUE 6
#define NB_MERVEILLES_MAX 7
#define PALIER_TROIS_POINTS_PION_CONFLIT 6
#define PALIER_DEUX_POINTS_PION_CONFLIT 3
#define PALIER_UN_POINTS_PION_CONFLIT 1

// ----------------------------

#endif
