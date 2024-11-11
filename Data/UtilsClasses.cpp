#include "UtilsClasses.h"

map<Ressource, string> ressource_to_string = {
        {Argile,  "Argile"},
        {Bois,    "Bois"},
        {Pierre,  "Pierre"},
        {Papyrus, "Papyrus"},
        {Verre,   "Verre"},
        {Piece,   "Piece"}
};

map<TypeCarte, string> type_carte_to_string = {
        {TAucun,           "Aucun"},
        {TMatierePremiere, "Matiere Premiere"},
        {TManufacture,     "Manufacture"},
        {TCivil,           "Civil"},
        {TScientifique,    "Scientifique"},
        {TCommercial,      "Commercial"},
        {TMilitaire,       "Militaire"},
        {TGuilde,          "Guilde"},
        {TMerveille,       "Merveille"}
};

map<NomEffetGuilde, string> effet_guilde_to_string = {
        {Armateurs,     "Armateurs"},
        {Batisseurs,    "Batisseurs"},
        {Commercants,   "Commerçants"},
        {Magistrats,    "Magistrats"},
        {Scientifiques, "Scientifiques"},
        {Tacticiens,    "Tacticiens"},
        {Usuriers,      "Usuriers"}
};

map<SymboleScientifique, string> symbole_scientifique_to_string = {
        {Balance,   "Balance"},
        {FilAPlomb, "Fil a plomb"},
        {Horloge,   "Horloge"},
        {Mortier,   "Mortier"},
        {Plume,     "Plume"},
        {Roue,      "Roue"},
        {Sphere,    "Sphere"}
};

map<SymboleChainage, string> symbole_chainage_to_string = {
        {SCAucun,    "Aucun"},
        {Batiment,   "Batiment"},
        {Casque,     "Casque"},
        {Cible,      "Cible"},
        {Engrenage,  "Engrenage"},
        {Epee,       "Epee"},
        {FerACheval, "Fer a cheval"},
        {Goutte,     "Goutte"},
        {Harpe,      "Harpe"},
        {LampeGenie, "Lampe de génie"},
        {Livre,      "Livre"},
        {Lune,       "Lune"},
        {Masque,     "Masque"},
        {Pilier,     "Pilier"},
        {Soleil,     "Soleil"},
        {Tonneau,    "Tonneau"},
        {Tour,       "Tour"},
        {Vase,       "Vase"}
};

string toStringMap(const map<Ressource, int> &dict, const string &name) {
    string result = name + " : ";
    for (const auto &pair: dict) {
        if (pair.second != 0) {
            result += ressource_to_string[pair.first] + ": " + to_string(pair.second) + " ";
        }
    }

    if (result == name + " : ") {
        result += "Aucun";
    }

    return result;
}



/*#ifndef UTILSCLASSES_H
#define UTILSCLASSES_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;


class CException : public exception {
public:
    CException(const string &message) : message(message) {}

    const string &getMessage() const { return message; }

private:
    string message;
};


enum NumJoueur {
    NJAucun = 0,
    J1 = 1,
    J2 = 2
};

enum Piece {
    Piece1 = 1,
    Piece3 = 3,
    Piece6 = 6
};

enum Age {
    Age1 = 1,
    Age2 = 2,
    Age3 = 3
};

enum TypeCarte {
    TAucun,
    TMatierePremiere,
    TManufacture,
    TCivil,
    TScientifique,
    TCommercial,
    TMilitaire,
    TGuilde,
    TMerveille
};

extern map<TypeCarte, string> type_carte_to_string;

enum Ressource {
    Argile,
    Bois,
    Pierre,
    Papyrus,
    Verre,
    Piece
};

extern map<Ressource, string> ressource_to_string;

enum NomEffetGuilde {
    Armateurs,
    Batisseurs,
    Commercants,
    Magistrats,
    Scientifiques,
    Tacticiens,
    Usuriers
};

extern map<NomEffetGuilde, string> effet_guilde_to_string;

// Les Effets de points, boucliers et pièces sont gérés par la classe Carte
enum NomEffetMerveille {
    // Le Circus Maximus
    CarteGriseDefausse,
    UnBouclier,//
    TroisPointsVictoire,

    // Le Colosse
    DeuxBoucliers,// TroisPointsVictoire,

    // La Grande Bibliothèque
    TirageTroisJetonsProgres,// QuatrePointsVictoire,

    // Le Grand Phare
    ProductionMatierePremiereChaqueTour,
    QuatrePointsVictoire,

    // Les Jardins Suspendus
    SixPieces,
    RejouerTour,// TroisPointsVictoire,

    // Le Mausolée
    ChoixCarteDefausse,
    DeuxPointsVictoire,

    // Le Pirée
    ProductionManufactureChaqueTour,// RejouerTour, DeuxPointsVictoire,

    // Les Pyramides
    NeufPointsVictoire,

    // Le Sphinx
    SixPointsVictoire,// RejouerTour,

    // La Statue de Zeus
    CarteMarronDefausse,// UnBouclier, TroisPointsVictoire,

    // Le Temple d'Artémis
    DouzePieces,// RejouerTour,

    // La Via Appia
    AdversairePerdTroisPieces,
    TroisPieces,// RejouerTour, TroisPointsVictoire

};

enum NomEffetJetonProgres {
    AucunEffet,

    // Agriculture
    SixPiecesQuatrePoints,

    // Architecture
    ReductionMerveilles,

    // Économie
    RecupereArgentDepense,

    // Loi
    GagneSymboleScientifique,

    // Maçonnerie
    ReductionCivils,

    // Mathématiques
    TroisPointsVictoireEtTroisPointsVictoireParJetonProgres,

    // Philosophie
    SeptPointsVictoire,

    // Stratégie
    AmeliorationBatimentsMilitaires,

    // Théologie
    RejouerPourChaqueMerveilleConstruite,

    // Urbanisme
    SixPiecesEtQuatrePiecesParChainage
};

enum SymboleScientifique {
    Balance,
    FilAPlomb,
    Horloge,
    Mortier,
    Plume,
    Roue,
    Sphere
};

extern map<SymboleScientifique, string> symbole_scientifique_to_string;

enum SymboleChainage {
    SCAucun,
    Batiment,
    Casque,
    Cible,
    Engrenage,
    Epee,
    FerACheval,
    Goutte,
    Harpe,
    LampeGenie,
    Livre,
    Lune,
    Masque,
    Pilier,
    Soleil,
    Tonneau,
    Tour,
    Vase
};

extern map<SymboleChainage, string> symbole_chainage_to_string;

// --- Structures Jetons ---

typedef struct JetonMilitaire {
    const string nom;
    const string description;
    const int nb_pieces_perdues;
} JetonMilitaire;

std::ostream &operator<<(std::ostream &f, const JetonMilitaire &jeton_militaire);

typedef struct EffetJetonProgres {
    const NomEffetJetonProgres effet;
    const string nom;
    const string description;
} EffetJetonProgres;

std::ostream &operator<<(std::ostream &f, const EffetJetonProgres &effet_jeton_progres);

typedef struct JetonProgres {
    const string nom;
    const EffetJetonProgres effet;
    const int nb_pieces;
    const int nb_points_victoire;
} JetonProgres;

std::ostream &operator<<(std::ostream &f, const JetonProgres &jeton_progres);

// -------------------------


// --- Structures pour Carte.h ---

typedef struct Chainage {
    const SymboleChainage symbole_age_precedent;
    const int id_carte_age_precedent;

    const SymboleChainage symbole_age_suivant;
    const int id_carte_age_suivant;
} Chainage;

std::ostream &operator<<(std::ostream &f, const Chainage &chainage);

typedef struct EffetGuilde {
    const NomEffetGuilde effet;
    const string nom;
    const string description;
} EffetGuilde;

std::ostream &operator<<(std::ostream &f, const EffetGuilde &chainage);

typedef struct EffetMerveille {
    const NomEffetMerveille effet;
    const string nom;
    const string description;
} EffetMerveille;

std::ostream &operator<<(std::ostream &f, const EffetMerveille &effet_merveille);

// -------------------------

#endif
*/