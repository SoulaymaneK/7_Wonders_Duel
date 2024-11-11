#ifndef JOUEUR_H
#define JOUEUR_H

#include "../Data/consts.h"

using namespace std;

typedef map<TypeCarte, vector<const Carte *>> DictCartes;


class Joueur {

public:
    Joueur(const string &nom) : nom(nom),
                                dict_ressources({{Pierre,  0},
                                                 {Bois,    0},
                                                 {Argile,  0},
                                                 {Papyrus, 0},
                                                 {Verre,   0},
                                                 {Piece, TOTAL_PIECES_DEPART}}),
                                points(0),
                                dict_symboles_scientifiques({{Plume,     0},
                                                             {Roue,      0},
                                                             {Horloge,   0},
                                                             {Sphere,    0},
                                                             {Mortier,   0},
                                                             {FilAPlomb, 0},
                                                             {Balance,   0}}),
                                liste_jetons_progres({}),
                                dict_cartes({{TMatierePremiere, {}},
                                             {TManufacture,     {}},
                                             {TCivil,           {}},
                                             {TScientifique,    {}},
                                             {TCommercial,      {}},
                                             {TMilitaire,       {}},
                                             {TGuilde,          {}},
                                             {TMerveille,       {}}}),
                                defausse({{TMatierePremiere, {}},
                                          {TManufacture,     {}},
                                          {TCivil,           {}},
                                          {TScientifique,    {}},
                                          {TCommercial,      {}},
                                          {TMilitaire,       {}},
                                          {TGuilde,          {}},
                                          {TMerveille,       {}}}) {};

    ~Joueur() {
        for (const auto &paire: dict_cartes) {
            for (const auto &carte: paire.second) {
                delete carte;
            }
        }
        for (const auto &paire: defausse) {
            for (const auto &carte: paire.second) {
                delete carte;
            }
        }
        for (const auto &merveille: merveille_a_construire) {
            delete merveille;
        }
    }


    string getNom() const { return nom; }

    DictRessources getDictRessources() { return dict_ressources; };

    int getRessource(Ressource type) { return dict_ressources[type]; }

    int getPoints() const { return points; }

    void ajouterPoints(int value) { points += value; }

    DictCartes getCartes() const { return dict_cartes; }

    DictCartes getDefausse() const { return defausse; }

    vector<const Merveille *> getMerveilleAConstruire() { return merveille_a_construire; }

    void ajouterMerveille(const Merveille *merveille) {
        merveille_a_construire.push_back(merveille);
    }

    void retirerMerveille(const Merveille *merveille) {
        auto it = find(merveille_a_construire.begin(), merveille_a_construire.end(), merveille);
        if (it != merveille_a_construire.end()) {
            merveille_a_construire.erase(it);
        }
    }

    void ajouterSymboleScientifique(SymboleScientifique symbole) { dict_symboles_scientifiques[symbole] += 1; }

    int getNbSymboleScientifique(SymboleScientifique symbole) { return dict_symboles_scientifiques[symbole]; }

    void ajouterJetonProgres(const JetonProgres *jeton) { liste_jetons_progres.push_back(jeton); }

    int getTotalSymbolesScientifiques() {
        int total = 0;
        for (const auto &paire: dict_symboles_scientifiques)
            total += paire.second;
        return total;
    }


    int getTotalSymbolesScientifiquesDifferent() {
        int total = 0;
        for (const auto &paire: dict_symboles_scientifiques)
            if (paire.second > 0) {
                total += 1;
            }
        return total;
    }

    int getNombreSymbolesScientifiques(SymboleScientifique symbole) { return dict_symboles_scientifiques[symbole]; }

    void ajouterRessource(Ressource type, int value) { dict_ressources[type] += value; }

    void retirerRessource(Ressource type, int value) {
        dict_ressources[type] -= value;
        if (dict_ressources[type] < 0)
            dict_ressources[type] = 0;
    }

    void ajouterCarte(const Carte *c) { dict_cartes[c->getType()].push_back(c); }

    void retirerCarte(const Carte *c) {
        dict_cartes[c->getType()].erase(find(dict_cartes[c->getType()].begin(), dict_cartes[c->getType()].end(), c));
    }

    void ajouterCarteDefausse(const Carte *c) { defausse[c->getType()].push_back(c); }

    void retirerCarteDefausse(const Carte *c) {
        defausse[c->getType()].erase(find(defausse[c->getType()].begin(), defausse[c->getType()].end(), c));
    }

    bool operator==(const Joueur &autreJoueur) const {
        return this->getNom() == autreJoueur.getNom();
    }

    void afficherJoueur(ostream &f = std::cout) const;

private:
    string nom;
    DictRessources dict_ressources;
    int points;

    map<SymboleScientifique, int> dict_symboles_scientifiques;//création d'un dictionnaire de clé un "enum de symbole scientifique" et en valeur le nombre
    vector<const JetonProgres *> liste_jetons_progres;                //liste des jetons progrès du joueur : dynamique avec Vector

    DictCartes dict_cartes;

    DictCartes defausse;

    vector<const Merveille *> merveille_a_construire;
};

#endif
