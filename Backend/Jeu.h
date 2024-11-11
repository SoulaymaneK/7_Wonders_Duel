#ifndef JEU_H
#define JEU_H

#include "../Data/consts.h"
#include "Joueur.h"
#include "Plateau.h"

using namespace std;

class Jeu {
public:
    static Jeu &getInstance() {
        static Jeu instance;
        return instance;
    }

    Jeu(const Jeu &) = delete;

    void operator=(const Jeu &) = delete;

    int getAge() const { return age; }

    Joueur &getJoueur(NumJoueur j) { return (j == J1) ? joueur1 : joueur2; }

    Plateau getPlateau() const { return plateau; }

    void avancerTour();

    void avancerAge();

    bool verifierVictoire();

    void debuterJeu();

    std::vector<const Carte *> chargerCartes(int age);

    std::map<int, const Carte *> initialiserDictCartesPlateau(int age);

    void acheterCarte(Joueur &joueur_acheteur, int emplacement);

    void ajouterGains(const Carte *carte, Joueur &joueur);

    void partie();

    int choixCarte();

    int choixAction();

    void jouerUnTour(NumJoueur tour);

    void construireMerveille(Joueur &joueur_acheteur, int emplacement, const Merveille *merveille);

    const Merveille *choixMerveilleAconstruire(Joueur &joueur);

    void choixMerveilleDebut(Joueur &joueur1, Joueur &joueur2);

    int calculPointsVictoire(NumJoueur joueur);

    int calculPointsCivil(NumJoueur joueur);

    bool verifierChainage(Joueur *joueur, const Carte *carte);

private:
    Jeu() = default;

    Joueur joueur1 = Joueur("Joueur 1");
    Joueur joueur2 = Joueur("Joueur 2");

    enum NumJoueur tour = J1;

    Plateau plateau;

    int age = 1;

    int winner = -1; // 1 si J1, 2 si J2, 0 si égalité, -1 si pas encore de gagnant

    int nb_merveilles_construites = 0;
};


#endif
