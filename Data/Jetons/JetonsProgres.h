#ifndef JETONS_PROGRES_H
#define JETONS_PROGRES_H

#include "../Data/UtilsClasses.h"

// --- Effets Jetons Progrès ---

// Agriculture
const EffetJetonProgres SIX_PIECES_QUATRE_POINTS = {SixPiecesQuatrePoints,
                                                    "+6 pièces, +4 points de victoire",
                                                    "Le joueur gagne six pièces et quatre points de victoire."};
// Architecture
const EffetJetonProgres REDUCTION_MERVEILLES = {ReductionMerveilles,
                                                "Réduction sur les Merveilles",
                                                "Les prochaines Merveilles construites par le joueur lui coûteront 2 ressources de moins.\n"
                                                "À chaque construction, le joueur est libre de choisir sur quelles ressources porte la réduction."};

// Économie
const EffetJetonProgres RECUPERE_ARGENT_DEPENSE = {RecupereArgentDepense,
                                                   "Récupère l'argent dépensé",
                                                   "Le joueur récupère l’argent dépensé par son adversaire lorsqu’il achète des ressources."};

// Loi
const EffetJetonProgres GAGNE_SYMBOLE_SCIENTIFIQUE = {GagneSymboleScientifique,
                                                      "Gagne un symbole scientifique",
                                                      "Ce jeton rapport un symbole scientifique."};

// Maçonnerie
const EffetJetonProgres REDUCTION_CIVILS = {ReductionCivils,
                                            "Réduction sur les cartes civiles",
                                            "Les prochains bâtiments civils (cartes bleues) construits par le joueur lui coûteront 2 ressources de moins.\n"
                                            "À chaque construction, le joueur est libre de choisir sur quelles ressources porte la réduction."};

// Mathématiques
const EffetJetonProgres TROIS_POINTS_VICTOIRE_ET_TROIS_POINTS_VICTOIRE_PAR_JETON_PROGRES = {
        TroisPointsVictoireEtTroisPointsVictoireParJetonProgres,
        "+3 points de victoire et 3 points de victoire par jeton progrès",
        "Le joueur gagne immédiatement 3 points de victoire.\n"
        "À la fin de la partie, le joueur marque 3 points de victoire pour chaque jeton Progrès en sa possession."};

// Philosophie
const EffetJetonProgres SEPT_POINTS_VICTOIRE = {SeptPointsVictoire,
                                                "+7 points de victoire",
                                                "Le joueur gagne sept points de victoire."};

// Stratégie
const EffetJetonProgres AMELIORATION_BATIMENTS_MILITAIRES = {AmeliorationBatimentsMilitaires,
                                                             "Amélioration des bâtiments militaires",
                                                             "À partir du moment où le joueur possède la Stratégie, les prochains bâtiments militaires (cartes rouges) qu’il construit bénéficieront de 1 bouclier supplémentaire."};

// Théologie
const EffetJetonProgres REJOUER_POUR_CHAQUE_MERVEILLE_CONSTRUITE = {RejouerPourChaqueMerveilleConstruite,
                                                                    "Rejouer pour chaque Merveille construite",
                                                                    "Les prochaines Merveilles construites par le joueur sont considérées comme ayant toutes l’effet « Rejouer ».\n"
                                                                    "Attention, les Merveilles qui disposent déjà de cet effet ne sont pas affectées."};

// Urbanisme
const EffetJetonProgres SIX_PIECES_ET_QUATRE_PIECES_PAR_CHAINAGE = {SixPiecesEtQuatrePiecesParChainage,
                                                                    "+6 pièces, 4 pièces par chainage",
                                                                    "Le joueur prend immédiatement 6 pièces.\n"
                                                                    "Chaque fois que le joueur construit un bâtiment gratuitement par chaînage, il reçoit 4 pièces."};

const EffetJetonProgres AUCUN_EFFET_JETON_PROGRES = {AucunEffet,
                                                     "Aucun effet",
                                                     "Ce jeton n'a aucun effet."};

// ------------------------------

// --- Jetconst ons Progrès ---

const JetonProgres AGRICULTURE = {"Agriculture", SIX_PIECES_QUATRE_POINTS, 6, 4};

const JetonProgres ARCHITECTURE = {"Architecture", REDUCTION_MERVEILLES, 0, 0};

const JetonProgres ECONOMIE = {"Économie", RECUPERE_ARGENT_DEPENSE, 0, 0};

const JetonProgres LOI = {"Loi", GAGNE_SYMBOLE_SCIENTIFIQUE, 0, 0};

const JetonProgres MACONNERIE = {"Maçonnerie", REDUCTION_CIVILS, 0, 0};

const JetonProgres MATHEMATIQUES = {"Mathématiques", TROIS_POINTS_VICTOIRE_ET_TROIS_POINTS_VICTOIRE_PAR_JETON_PROGRES,
                                    0, 3};

const JetonProgres PHILOSOPHIE = {"Philosophie", SEPT_POINTS_VICTOIRE, 7, 0};

const JetonProgres STRATEGIE = {"Stratégie", AMELIORATION_BATIMENTS_MILITAIRES, 0, 0};

const JetonProgres THEOLOGIE = {"Théologie", REJOUER_POUR_CHAQUE_MERVEILLE_CONSTRUITE, 0, 0};

const JetonProgres URBANISME = {"Urbanisme", SIX_PIECES_ET_QUATRE_PIECES_PAR_CHAINAGE, 6, 0};

const JetonProgres AUCUN_JETON_PROGRES = {"Aucun jeton de progrès", AUCUN_EFFET_JETON_PROGRES, 0, 0};

// ------------------------------

// --- Liste des Jetons Progrès ---

const vector<const JetonProgres *> JETONS_PROGRES = {&AGRICULTURE, &ARCHITECTURE, &ECONOMIE, &LOI, &MACONNERIE,
                                                     &MATHEMATIQUES, &PHILOSOPHIE, &STRATEGIE, &THEOLOGIE, &URBANISME};

#endif