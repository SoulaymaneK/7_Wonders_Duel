#ifndef PLATEAU_H
#define PLATEAU_H

#include "../Data/consts.h"
#include "Carte.h"

using namespace std;

class Plateau {
public:
    Plateau();

    // Les cartes sont allouées dynamiquement, on doit les supprimer à la fin.
    ~Plateau() { for (auto &carte: dict_cartes) delete carte.second; };

    const map<int, const Carte *> &getDictCartesAge() { return dict_cartes; }

    int getPionConflit() const { return pion_conflit; }

    NumJoueur getVainqueurMilitaire() const { return vainqueur_militaire; }

    vector<const JetonProgres *> getJetonsProgresDisponibles() { return jetons_progres_disponibles; }

    bool estVide() { return getCartesDisponibles().empty(); }

    map<int, const Carte *> &getDictCartes() { return dict_cartes; }

    vector<int> &getEmplacementsAchetes() { return emplacements_achetes; }

    vector<int> &getEmplacementsCaches() { return emplacements_caches; }

    map<int, vector<int>> &getDictDependancesEmplacements() { return dict_dependances_emplacements; }

    map<int, const Carte *> getCartesDisponibles();

    void initialiserPlateau(int age, map<int, const Carte *> &cartes);

    void initialiserRandomJetonsProgres();

    const JetonProgres *choisirJetonsProgres();

    void avancerPionConflit(int value, NumJoueur joueur) {
        pion_conflit += (joueur == J1) ? value : -value;
        vainqueur_militaire = victoireMilitaire();
    }

    NumJoueur victoireMilitaire() {
        return (pion_conflit >= ARRIVEE_PION_CONFLIT) ? J1 : (pion_conflit <= -ARRIVEE_PION_CONFLIT) ? J2 : NJAucun;
    }

    bool isCarteAchetable(int emplacement);

    const Carte *acheterCarte(int emplacement);

    void defausserCarte(int num_carte);

    void afficherPlateau(ostream &f = std::cout);

private:
    int pion_conflit = 0;
    NumJoueur vainqueur_militaire = NJAucun;

    vector<const JetonProgres *> jetons_progres_disponibles = {};

    // Lie chaque numéro d'emplacement à une Carte.
    map<int, const Carte *> dict_cartes = {};

    vector<int> emplacements_achetes = {};

    vector<int> emplacements_caches = LISTE_EMPLACEMENTS_CACHES_AGE_1;

    // Dictionnaire d'emplacements, le premier int est le numéro de l'emplacement,
    // le vecteur contient les numéros des emplacements qui doivent être achetés pour acheter le premier int.
    map<int, vector<int>> dict_dependances_emplacements = DICT_EMPLACEMENTS_AGE_1;
};

#endif
