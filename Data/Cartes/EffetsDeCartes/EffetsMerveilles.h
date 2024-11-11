#ifndef EFFETS_MERVEILLES_H
#define EFFETS_MERVEILLES_H

#include "../../UtilsClasses.h"

const EffetMerveille CARTE_GRISE_DEFAUSSE = {
        CarteGriseDefausse,
        "Carte Grise en défausse",
        "Le joueur place dans la défausse une carte grise (produit manufacturé) de son choix construite par son adversaire."};

const EffetMerveille PRODUCTION_MATIERE_PREMIERE_CHAQUE_TOUR = {
        ProductionMatierePremiereChaqueTour,
        "Production d'une matière première à chaque tour",
        "Cette Merveille produit à chaque tour, pour le joueur, une unité de Pierre, d'Argile ou de Bois)."};

const EffetMerveille REJOUER_TOUR = {
        RejouerTour,
        "Rejouer un tour",
        "Le joueur rejoue immédiatement un tour."};

const EffetMerveille TIRAGE_TROIS_JETONS_PROGRES = {
        TirageTroisJetonsProgres,
        "Tirage de trois jetons progrès",
        "Le joueur tire aléatoirement 3 jetons Progrès parmi ceux écartés au début de partie.\n"
        "Il en choisit un et remet les 2 autres dans la boîte."};

const EffetMerveille CHOIX_CARTE_DEFAUSSE = {
        ChoixCarteDefausse,
        "Choix d'une carte défaussée",
        "Le joueur prend toutes les cartes défaussées depuis le début de la partie et en construit gratuitement une au choix."};
// Précision : Les cartes écartées lors de la préparation ne font pas partie de la défausse.

const EffetMerveille PRODUCTION_MANUFACTURE_CHAQUE_TOUR{
        ProductionManufactureChaqueTour,
        "Production d'une manufacture à chaque tour",
        "Cette Merveille produit à chaque tour, pour le joueur, une unité de Verre ou de Papyrus."};

const EffetMerveille CARTE_MARRON_DEFAUSSE = {
        CarteMarronDefausse,
        "Carte Marron en défausse",
        "Le joueur place dans la défausse une carte marron (matière première) de son choix construite par son adversaire."};

const EffetMerveille ADVERSAIRE_PERD_TROIS_PIECES = {
        AdversairePerdTroisPieces,
        "L'adversaire perd trois pièces",
        "L’adversaire perd 3 pièces qui sont remises à la banque."};

// --- Effets esthétiques mais non fonctionnels car gérés par la classe Merveille ---
const EffetMerveille UN_BOUCLIER = {
        UnBouclier,
        "+1 bouclier",
        "Cette merveille rapport 1 bouclier."};

const EffetMerveille DEUX_BOUCLIERS = {
        DeuxBoucliers,
        "+2 boucliers",
        "Cette merveille rapport 2 boucliers."};

const EffetMerveille DEUX_POINTS_VICTOIRE = {
        DeuxPointsVictoire,
        "+2 points de victoire",
        "Cette Merveille rapporte 2 points de victoire."};

const EffetMerveille TROIS_POINTS_VICTOIRE = {
        TroisPointsVictoire,
        "+3 points de victoire",
        "Cette Merveille rapporte 3 points de victoire."};

const EffetMerveille QUATRE_POINTS_VICTOIRE = {
        QuatrePointsVictoire,
        "+4 points de victoire",
        "Cette Merveille rapporte 4 points de victoire."};

const EffetMerveille SIX_POINTS_VICTOIRE = {
        SixPointsVictoire,
        "+6 points de victoire",
        "Cette Merveille rapporte 6 points de victoire."};

const EffetMerveille NEUF_POINTS_VICTOIRE = {
        NeufPointsVictoire,
        "+9 points de victoire",
        "Cette Merveille rapporte 9 points de victoire."};

const EffetMerveille TROIS_PIECES = {
        TroisPieces,
        "+3 pièces",
        "Cette Merveille rapporte 3 pièces."};

const EffetMerveille SIX_PIECES = {
        SixPieces,
        "+6 pièces",
        "Cette Merveille rapporte 6 pièces."};

const EffetMerveille DOUZE_PIECES = {
        DouzePieces,
        "+12 pièces",
        "Cette Merveille rapporte 12 pièces."};
// ----------------------------

typedef vector<EffetMerveille> ListeEffetsMerveilles;

const ListeEffetsMerveilles EFFETS_CIRCUS_MAXIMUS = {CARTE_GRISE_DEFAUSSE,
                                                     UN_BOUCLIER,
                                                     TROIS_POINTS_VICTOIRE};

const ListeEffetsMerveilles EFFETS_COLOSSE = {DEUX_BOUCLIERS,
                                              TROIS_POINTS_VICTOIRE};

const ListeEffetsMerveilles EFFETS_GRANDE_BIBLIOTHEQUE = {TIRAGE_TROIS_JETONS_PROGRES,
                                                          QUATRE_POINTS_VICTOIRE};

const ListeEffetsMerveilles EFFETS_GRAND_PHARE = {PRODUCTION_MATIERE_PREMIERE_CHAQUE_TOUR,
                                                  QUATRE_POINTS_VICTOIRE};

const ListeEffetsMerveilles EFFETS_JARDINS_SUSPENDUS = {SIX_PIECES,
                                                        REJOUER_TOUR,
                                                        TROIS_POINTS_VICTOIRE};

const ListeEffetsMerveilles EFFETS_MAUSOLEE = {TIRAGE_TROIS_JETONS_PROGRES,
                                               DEUX_POINTS_VICTOIRE};

const ListeEffetsMerveilles EFFETS_PIREE = {PRODUCTION_MANUFACTURE_CHAQUE_TOUR,
                                            REJOUER_TOUR,
                                            DEUX_POINTS_VICTOIRE};

const ListeEffetsMerveilles EFFETS_PYRAMIDES = {NEUF_POINTS_VICTOIRE};

const ListeEffetsMerveilles EFFETS_SPHINX = {REJOUER_TOUR,
                                             SIX_POINTS_VICTOIRE};

const ListeEffetsMerveilles EFFETS_STATUE_ZEUS = {CARTE_MARRON_DEFAUSSE,
                                                  UN_BOUCLIER,
                                                  TROIS_POINTS_VICTOIRE};

const ListeEffetsMerveilles EFFETS_TEMPLE_ARTEMIS = {DOUZE_PIECES,
                                                     REJOUER_TOUR};

const ListeEffetsMerveilles EFFETS_VIA_APPIA = {TROIS_PIECES,
                                                ADVERSAIRE_PERD_TROIS_PIECES,
                                                REJOUER_TOUR,
                                                TROIS_POINTS_VICTOIRE};

#endif
