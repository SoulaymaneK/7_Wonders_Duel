#include "Plateau.h"
#include <iomanip>//formater les entrées et les sorties pour l'affichage

map<int, const Carte *> Plateau::getCartesDisponibles() {
    map<int, const Carte *> cartes_disponibles = {};

    for (auto &dict_carte: dict_cartes) {
        if (find(emplacements_achetes.begin(), emplacements_achetes.end(), dict_carte.first) ==
            emplacements_achetes.end()) {
            if (isCarteAchetable(dict_carte.first)) {
                cartes_disponibles[dict_carte.first] = dict_carte.second;
            }
        }
    }
    return cartes_disponibles;
}

void Plateau::initialiserPlateau(int age, map<int, const Carte *> &cartes) {
    dict_cartes = cartes;
    emplacements_achetes = {};

    if (age == 1) {
        emplacements_caches = LISTE_EMPLACEMENTS_CACHES_AGE_1;
        dict_dependances_emplacements = DICT_EMPLACEMENTS_AGE_1;
        initialiserRandomJetonsProgres();
    } else if (age == 2) {
        emplacements_caches = LISTE_EMPLACEMENTS_CACHES_AGE_2;
        dict_dependances_emplacements = DICT_EMPLACEMENTS_AGE_2;
    } else if (age == 3) {
        emplacements_caches = LISTE_EMPLACEMENTS_CACHES_AGE_3;
        dict_dependances_emplacements = DICT_EMPLACEMENTS_AGE_3;
    } else {
        cout << "L'age doit etre compris entre 1 et 3." << endl;
    }
}

void Plateau::initialiserRandomJetonsProgres() {
    vector<const JetonProgres *> jetons_progres = JETONS_PROGRES;

    for (int i = 0; i < NB_JETONS_PROGRES; i++) {
        int random_index = rand() % jetons_progres.size();
        jetons_progres_disponibles.push_back(jetons_progres[random_index]);
        jetons_progres.erase(jetons_progres.begin() + random_index);
    }
}

void afficherJetonProgres(const JetonProgres *jeton_progres) {
    cout << "Nom: " << jeton_progres->nom << endl;
    cout << "   Pieces : " << jeton_progres->nb_pieces << endl;
    cout << "   Points de victoire : " << jeton_progres->nb_points_victoire << endl;
    cout << "   Effet: " << jeton_progres->effet.nom << endl;
    cout << "      " << jeton_progres->effet.description << endl;
}

const JetonProgres *Plateau::choisirJetonsProgres() {
    if (jetons_progres_disponibles.empty()) {
        cout << "Il n'y a plus de jetons de progres disponibles." << endl;
        return &AUCUN_JETON_PROGRES;
    }

    for (int i = 0; i < jetons_progres_disponibles.size(); i++) {
        cout << "Jeton de progres " << i + 1 << " :" << endl;
        afficherJetonProgres(jetons_progres_disponibles[i]);
    }

    int choix = -1;

    while (choix < 1 || choix > jetons_progres_disponibles.size()) {
        cout << "Choisissez un jeton de progres (1-" << jetons_progres_disponibles.size() << "): ";
        cin >> choix;
    }

    const JetonProgres *jeton_progres = jetons_progres_disponibles[choix - 1];

    // enlève le struct jeton de progrès de la liste des jetons de progrès disponibles
    jetons_progres_disponibles.erase(jetons_progres_disponibles.begin() + choix - 1);

    return jeton_progres;
}

bool Plateau::isCarteAchetable(int emplacement) {
    vector<int> dependances = dict_dependances_emplacements[emplacement];

    for (int dependance: dependances) {
        if (find(emplacements_achetes.begin(), emplacements_achetes.end(), dependance) == emplacements_achetes.end()) {
            return false;
        }
    }
    return true;
}

const Carte *Plateau::acheterCarte(int emplacement) {
    vector<int> dependances = dict_dependances_emplacements[emplacement];

    if (!isCarteAchetable(emplacement)) {
        cout << "Impossible d'acheter la carte a l'emplacement " << emplacement << "." << endl;
        return nullptr;
    } else {
        emplacements_achetes.push_back(emplacement);
        return dict_cartes[emplacement];
    }
}

void Plateau::defausserCarte(int num_carte) {
    if (dict_cartes.find(num_carte) == dict_cartes.end()) {
        cout << "Erreur : la carte a defausser n'est pas sur le plateau." << endl;
        return;
    }

    if (!isCarteAchetable(num_carte)) {
        cout << "Erreur : la carte a defausser n'est pas accessible." << endl;
        return;
    }

    const Carte *carte_a_defausser = dict_cartes[num_carte];

    /* verification utile pour l'achat mais pas dans la défausse
    
    if (carte_a_defausser->getType() == TypeCarte::TMilitaire) {
        int valeur_militaire = static_cast<Militaire *>(carte_a_defausser)->getNbBoucliers();
        avancerPionConflit(valeur_militaire, joueur_courant);
    }
    */
    dict_cartes.erase(num_carte);
}

/*
void Plateau::afficherPlateau(ostream &f = std::cout) {
    cout << "PLATEAU DE JEU" << endl;
    cout << "--------------" << endl;
    cout << "Age I:" << endl;

    // Âge I
    for (int i = 1; i <= 20; i++) {
        if (i % 5 == 0) {
            cout << endl;
        }
        if (find(emplacements_caches.begin(), emplacements_caches.end(), i) != emplacements_caches.end()) {
            cout << " [XX] ";
        } else if (find(emplacements_achetes.begin(), emplacements_achetes.end(), i) != emplacements_achetes.end()) {
            cout << " [AA] ";
        } else {
            const Carte *carte = dict_cartes[i];
            cout << " [" << carte->getNom() << "] ";
        }
    }
    cout << endl;

    // dépendances de l'âge I
    cout << "Dépendances:" << endl;
    for (auto const &entry: DICT_EMPLACEMENTS_AGE_1) {
        int emplacement = entry.first;
        cout << "Emplacement " << emplacement << ": ";
        for (int dep: entry.second) {
            cout << dep << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Âge II
    cout << "Age II:" << endl;
    for (int i = 1; i <= 20; i++) {
        if (i % 5 == 0) {
            cout << endl;
        }
        if (find(emplacements_caches.begin(), emplacements_caches.end(), i) != emplacements_caches.end()) {
            cout << " [XX] ";
        } else if (find(emplacements_achetes.begin(), emplacements_achetes.end(), i) != emplacements_achetes.end()) {
            cout << " [AA] ";
        } else {
            const Carte *carte = dict_cartes[i];
            cout << " [" << carte->getNom() << "] ";
        }
    }
    cout << endl;

    // dépendances de l'âge II
    cout << "Dépendances:" << endl;
    for (auto const &entry: DICT_EMPLACEMENTS_AGE_2) {
        int emplacement = entry.first;
        cout << "Emplacement " << emplacement << ": ";
        for (int dep: entry.second) {
            cout << dep << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Âge III
    cout << "Age III:" << endl;
    for (int i = 1; i <= 20; i++) {
        if (i % 5 == 0) {
            cout << endl;
        }
        if (find(emplacements_caches.begin(), emplacements_caches.end(), i) != emplacements_caches.end()) {
            cout << " [XX] ";
        } else if (find(emplacements_achetes.begin(), emplacements_achetes.end(), i) != emplacements_achetes.end()) {
            cout << " [AA] ";
        } else {
            const Carte *carte = dict_cartes[i];
            cout << " [" << carte->getNom() << "] ";
        }
    }
    cout << endl;

    // dépendances de l'âge III
    cout << "Dépendances:" << endl;
    for (auto const &entry: DICT_EMPLACEMENTS_AGE_3) {
        int emplacement = entry.first;
        cout << "Emplacement " << emplacement << ": ";
        for (int dep: entry.second) {
            cout << dep << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Pion de conflit: " << pion_conflit << endl;
}
//deuxieme version plus synthéthique de afficherPlateu(), on utilisera celle que vous préférer
/*
    void Plateau::afficherPlateau() {
    auto afficherEmplacements = [&](int age, const vector<int>& emplacementsCaches) {
        cout << "Age " << age << ":" << endl;
        for (int i = 1; i <= 20; ++i) {
            if (i % 5 == 1) {
                cout << endl;
            }
            if (find(emplacementsCaches.begin(), emplacementsCaches.end(), i) != emplacementsCaches.end()) {
                cout << setw(6) << "[XX]";
            } else if (find(emplacements_achetes.begin(), emplacements_achetes.end(), i) != emplacements_achetes.end()) {
                cout << setw(6) << "[AA]";
            } else if (dict_cartes.find(i) != dict_cartes.end()) {
                cout << setw(6) << "[" << dict_cartes[i]->getNom() << "]";
            } else {
                cout << setw(6) << "[  ]";
            }
        }
        cout << endl;
    };

    auto afficherDependances = [&](int age, const map<int, vector<int>>& dictDependances) {
        cout << "Dépendances de l'Age " << age << ":" << endl;
        for (const auto& entry : dictDependances) {
            cout << "Emplacement " << entry.first << ": ";
            for (int dep : entry.second) {
                cout << dep << " ";
            }
            cout << endl;
        }
        cout << endl;
    };

    cout << "PLATEAU DE JEU" << endl;
    cout << "--------------" << endl;

    afficherEmplacements(1, LISTE_EMPLACEMENTS_CACHES_AGE_1);
    afficherDependances(1, DICT_EMPLACEMENTS_AGE_1);

    afficherEmplacements(2, LISTE_EMPLACEMENTS_CACHES_AGE_2);
    afficherDependances(2, DICT_EMPLACEMENTS_AGE_2);

    afficherEmplacements(3, LISTE_EMPLACEMENTS_CACHES_AGE_3);
    afficherDependances(3, DICT_EMPLACEMENTS_AGE_3);

    cout << "Pion de conflit: " << pion_conflit << endl;
    cout << "Vainqueur Militaire: " << (vainqueur_militaire == J1 ? "Joueur 1" : vainqueur_militaire == J2 ? "Joueur 2" : "Aucun") << endl;

    cout << "Jetons de Progrès Disponibles: ";
    for (const auto& jeton : jetons_progres_disponibles) {
        cout << jeton.nom << " ";
    }
    cout << endl;
}
*/

Plateau::Plateau() {
    emplacements_caches = LISTE_EMPLACEMENTS_CACHES_AGE_1;

    dict_dependances_emplacements = DICT_EMPLACEMENTS_AGE_1;

    initialiserRandomJetonsProgres();
}

// Plateau::~Plateau() { dict_cartes.clear(); }
