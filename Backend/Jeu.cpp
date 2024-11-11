//
// Cre par Mohamed Tahiri le 18/05/2024.
//

#include "Jeu.h"

using namespace std;

bool Jeu::verifierVictoire() {

    // victoire militaire
    if (plateau.getPionConflit() == ARRIVEE_PION_CONFLIT)
        winner = 1;
    else if (plateau.getPionConflit() == -(ARRIVEE_PION_CONFLIT))
        winner = 2;

        // victoire scientifique
    else if (joueur1.getTotalSymbolesScientifiquesDifferent() == NB_SYMB_SCI_DIFF_VICTOIRE_SCIENTIFIQUE)
        winner = 1;
    else if (joueur2.getTotalSymbolesScientifiquesDifferent() == NB_SYMB_SCI_DIFF_VICTOIRE_SCIENTIFIQUE)
        winner = 2;

        // victoire par points de victoire
    else if (age == 3 && plateau.estVide()) {
        cout << "La partie est terminee, il n'y a eu ni victoire militaire ni victoire scientifique." << endl;
        cout << "Place au compte des points de victoire des joueurs." << endl;

        int points_victoire_j1 = calculPointsVictoire(J1);
        cout << joueur1.getNom() << " a obtenu " << points_victoire_j1 << " points de victoire." << endl;
        int points_victoire_j2 = calculPointsVictoire(J2);
        cout << joueur2.getNom() << " a obtenu " << points_victoire_j2 << " points de victoire." << endl;

        if (points_victoire_j1 == points_victoire_j2) {
            cout << "Les deux joueurs ont autant de points de victoire." << endl;
            cout << "Place au compte des points civils des joueurs." << endl;
            int points_civil_j1 = calculPointsCivil(J1);
            cout << joueur1.getNom() << " a obtenu " << points_civil_j1 << " points civils." << endl;
            int points_civil_j2 = calculPointsCivil(J2);
            cout << joueur2.getNom() << " a obtenu " << points_civil_j2 << " points civils." << endl;

            if (points_civil_j1 == points_civil_j2) {
                winner = 0;
                cout << "Il y a egalite." << endl;
            } else if (points_civil_j1 > points_civil_j2) {
                winner = 1;
                cout << joueur1.getNom() << " a gagne !!!" << endl;
            } else {
                winner = 2;
                cout << joueur2.getNom() << " a gagne !!!" << endl;
            }
        } else if (points_victoire_j1 > points_victoire_j2) {
            winner = 1;
            cout << joueur1.getNom() << " a gagne !!!" << endl;
        } else {
            winner = 2;
            cout << joueur2.getNom() << " a gagne !!!" << endl;
        }
    } else {
        winner = -1;
    }

    return winner != -1;
}


vector<const Carte *> Jeu::chargerCartes(int age) {
    if (age == 1) {
        return CARTES_AGE_1;
    } else if (age == 2) {
        return CARTES_AGE_2;
    } else {
        return CARTES_AGE_3;
    }
}

map<int, const Carte *> Jeu::initialiserDictCartesPlateau(int age) {
    vector<const Carte *> cartes_age_courant = chargerCartes(age);

    map<int, const Carte *> dict_cartes_plateau;

    for (int i = 0; i < 20; i++) {
        int index = rand() % cartes_age_courant.size();
        dict_cartes_plateau[i] = cartes_age_courant[index];
        cartes_age_courant.erase(cartes_age_courant.begin() + index);
    }

    return dict_cartes_plateau;
}

void Jeu::debuterJeu() {
    winner = -1;
    age = 1;
    tour = J1;

    cout << "Debut de la partie." << endl;
    cout << "Initialisation des joueurs." << endl;

    cout << "Joueur 1, veuillez entrer votre nom : ";
    string nom_joueur1;
    cin >> nom_joueur1;
    joueur1 = Joueur(nom_joueur1);

    cout << "Joueur 2, veuillez entrer votre nom : ";
    string nom_joueur2;
    cin >> nom_joueur2;
    joueur2 = Joueur(nom_joueur2);

    map<int, const Carte *> dict_cartes_plateau = initialiserDictCartesPlateau(age);
    plateau.initialiserPlateau(age, dict_cartes_plateau);

    choixMerveilleDebut(joueur1, joueur2);

    partie();
}

void Jeu::partie() {
    bool victoire = false;

    while (!victoire) {
        jouerUnTour(tour);
        victoire = verifierVictoire();
        avancerAge();// on tente de changer d'ege
    }

    cout << "Fin de la partie." << endl;
}

void Jeu::avancerAge() {// et gestion de l'avancement des tours
    if (plateau.estVide() && age < 3) {
        age++;

        map<int, const Carte *> dict_cartes_plateau = initialiserDictCartesPlateau(age);
        plateau.initialiserPlateau(age, dict_cartes_plateau);

        cout << "Avancement a l'age " << age << "." << endl;

        if (plateau.getPionConflit() < 0) {
            cout << joueur1.getNom() << " decide qui commence le prochain tour." << endl;

            cout << joueur1.getNom() << " : Choisissez 1 pour vous et 2 pour " << joueur2.getNom() << " : ";
            int choix;
            cin >> choix;
            tour = (NumJoueur) choix;
            cout << "C'est au tour de " << ((tour == J1) ? joueur1.getNom() : joueur2.getNom()) << endl;
        } else if (plateau.getPionConflit() > 0) {
            cout << joueur2.getNom() << " decide qui commence le prochain tour." << endl;

            cout << joueur2.getNom() << " : Choisissez 1 pour " << joueur1.getNom() << " et 2 pour vous : ";
            int choix;
            cin >> choix;
            tour = (NumJoueur) choix;
            cout << "C'est au tour de " << ((tour == J1) ? joueur1.getNom() : joueur2.getNom()) << endl;
        } else {
            cout << "Le joueur qui a commence juste avant continue." << endl;
            // Le joueur courant reste le meme, donc avancerTour() n'est pas appele
            cout << "C'est au tour de " << ((tour == J1) ? joueur1.getNom() : joueur2.getNom()) << endl;
        }
        return;
    } else if (plateau.estVide() && age == 3) {
        return; // tout a deje ete gere dans verifierVictoire()
    } else {
        // cout << "Les conditions pour avancer l'ege ne sont pas remplies." << endl;
        avancerTour();
    }
}

void Jeu::choixMerveilleDebut(Joueur &joueur1, Joueur &joueur2) {

    // premiere vague de choix des merveilles => J1 en choisit 1 ; J2 en choisit 2 ; J1 a la derniere
    //creation de la liste des merveilles e choisir (aleatoirement)
    vector<const Merveille *> list_merveille;
    vector<const Merveille *> copie_merveille = CARTES_MERVEILLES;

    for (size_t i = 0; i < 4; i++) {
        int random = rand() % copie_merveille.size();
        const Merveille *merveille = copie_merveille[random];
        list_merveille.push_back(merveille);
        copie_merveille.erase(copie_merveille.begin() + random);
    }
    for (size_t i = 0; i < list_merveille.size(); i++) {
        cout << "Merveille " << i + 1 << " : " << endl;
        list_merveille[i]->afficher();
    }

    cout << joueur1.getNom() << ", veuillez choisir une merveille : ";
    //ajout de la merveille et supression de la liste des merveilles e choisir
    int choix;
    cin >> choix;
    choix--;

    joueur1.ajouterMerveille(list_merveille[choix]);
    list_merveille.erase(list_merveille.begin() + choix);

    //tour du joueur 2
    for (size_t i = 0; i < list_merveille.size(); i++) {
        cout << "Merveille " << i + 1 << " : " << list_merveille[i]->getNom() << endl;
    }
    cout << joueur2.getNom() << ", veuillez choisir une merveille parmi les merveilles restantes : ";
    cin >> choix;
    choix--;

    joueur2.ajouterMerveille(list_merveille[choix]);
    list_merveille.erase(list_merveille.begin() + choix);

    for (size_t i = 0; i < list_merveille.size(); i++) {
        cout << "Merveille " << i + 1 << ": " << list_merveille[i]->getNom() << endl;
    }
    cout << joueur2.getNom() << ", veuillez choisir une 2eme merveille parmi les merveilles restantes : ";
    cin >> choix;
    choix--;

    joueur2.ajouterMerveille(list_merveille[choix]);
    list_merveille.erase(list_merveille.begin() + choix);

    //ajout de la derniere carte au joueur 1

    cout << joueur1.getNom() << ", vous obtenez la merveille " << list_merveille[0]->getNom() << " par defaut." << endl;
    joueur1.ajouterMerveille(list_merveille[0]);
    list_merveille.clear();


    // deuxieme vague de choix des merveilles, avec inversion => J2 en choisit 1 ; J1 en choisit 2 ; J2 a la derniere
    //recreation d'une liste de 4 merveilles
    for (size_t i = 0; i < 4; i++) {
        int random = rand() % copie_merveille.size();
        const Merveille *merveille = copie_merveille[random];
        list_merveille.push_back(merveille);
        copie_merveille.erase(copie_merveille.begin() + random);
    }

    for (size_t i = 0; i < list_merveille.size(); i++) {
        cout << "Merveille " << i + 1 << " : " << endl;
        list_merveille[i]->afficher();
    }

    cout << joueur2.getNom() << ", veuillez choisir une merveille : ";
    //ajout de la merveille et supression de la liste des merveilles e choisir
    cin >> choix;
    choix--;

    joueur2.ajouterMerveille(list_merveille[choix]);
    list_merveille.erase(list_merveille.begin() + choix);
    //tour du joueur 2
    for (size_t i = 0; i < list_merveille.size(); i++) {
        cout << "Merveille " << i + 1 << " : " << list_merveille[i]->getNom() << endl;
    }
    cout << joueur1.getNom() << ", veuillez choisir une merveille parmi les merveilles restantes : ";
    cin >> choix;
    choix--;

    joueur1.ajouterMerveille(list_merveille[choix]);
    list_merveille.erase(list_merveille.begin() + choix);

    for (size_t i = 0; i < list_merveille.size(); i++) {
        cout << "Merveille " << i + 1 << ": " << list_merveille[i]->getNom() << endl;
    }
    cout << joueur1.getNom() << ", veuillez choisir une 2eme merveille parmi les merveilles restantes : ";
    cin >> choix;
    choix--;

    joueur1.ajouterMerveille(list_merveille[choix]);
    list_merveille.erase(list_merveille.begin() + choix);

    //ajout de la derniere carte au joueur 1

    cout << joueur2.getNom() << ", vous obtenez la merveille " << list_merveille[0]->getNom() << " par defaut.\n\n"
         << endl;
    joueur2.ajouterMerveille(list_merveille[0]);
    list_merveille.clear();
    copie_merveille.clear();
}


const Merveille *Jeu::choixMerveilleAconstruire(Joueur &joueur) {
    cout << "Quel merveille voulez vous construire ? " << endl;
    vector<const Merveille *> merveilleJoueur = joueur.getMerveilleAConstruire();
    cout << "Liste des merveilles : " << endl;
    for (size_t i = 0; i < merveilleJoueur.size(); i++) {
        cout << "Merveille " << i + 1 << " : " << merveilleJoueur[i]->getNom()
             << toStringMap(merveilleJoueur[i]->getCoutRessources(), " (Cout") << ")" << endl;
    }
    cout << " Quel est le numero de la merveille voulue ? : ";
    int choix;
    cin >> choix;
    choix--;

    if (choix < 0 || choix >= merveilleJoueur.size()) {
        cout << "Veuillez choisir une merveille valide." << endl;
        choixMerveilleAconstruire(joueur);
        return nullptr;
    } else {
        return merveilleJoueur[choix];
    }
}

void Jeu::construireMerveille(Joueur &joueur_constructeur, int emplacement, const Merveille *merveille) {
    const Carte *carte = plateau.getCartesDisponibles()[emplacement];
    bool construction = true;
    for (const auto &pair: carte->getCoutRessources()) {
        if (pair.second > joueur_constructeur.getRessource(pair.first)) {
            construction = false;
        }
    }
    if (construction) {
        for (const auto &pair: carte->getCoutRessources()) {
            joueur_constructeur.retirerRessource(pair.first, pair.second);
        }
        joueur_constructeur.ajouterCarte(merveille);
        plateau.acheterCarte(emplacement);
        nb_merveilles_construites++;
        // TODO : gestion des effets de la merveille
    } else {
        cout << "Vous n'avez pas les ressources necessaires pour construire cette merveille.\n\n" << endl;
        jouerUnTour(((joueur_constructeur == joueur1) ? J1 : J2));
    }
}


void Jeu::acheterCarte(Joueur &joueur_acheteur, int emplacement) {
    const Carte *carte = plateau.getCartesDisponibles()[emplacement]; // faut vérifier que l'emplacement est disponible
    bool achat_possible = true;
    bool effet_ressource_gratuite_commerce_utilise = false;// cet effet ne peut etre utilise qu'une fois
    Joueur &joueur_adversaire = (joueur_acheteur == joueur1) ? joueur2 : joueur1;

    if (verifierChainage(&joueur_acheteur, carte)) {
        cout << "Vous obtenez la carte gratuitement grace a un effet de chainage !" << endl;
    } else {
        //on verifie si les ressources du joueur, telles quelles, sont suffisantes pour acheter la carte
        for (const auto &pair: carte->getCoutRessources()) {
            int nb_ressources_residuel = pair.second - joueur_acheteur.getRessource(pair.first);

            // on verifie si la ressource e laquelle on s'interesse dans cette iteration beneficie d'un effet ressource gratuite
            // donne par les cartes Commerciales possedees par le joueur, qui enlevent donc 1 au nb_ressources_residuel
            if (!effet_ressource_gratuite_commerce_utilise) {
                bool ressource_trouvee = false;
                for (const auto &pair_cartes: joueur_acheteur.getCartes()) {
                    if (pair_cartes.first == TCommercial) {
                        // pour eviter de parcourir toutes les cartes
                        for (const Carte *carte_joueur: pair_cartes.second) {
                            const Commercial *carte_commerciale = static_cast<const Commercial *>(carte_joueur);
                            for (int i = 0; i < carte_commerciale->getNbRessourcesGratuites(); i++) {
                                if (carte_commerciale->getRessourceGratuite(i) == pair.first) {
                                    nb_ressources_residuel -= 1;
                                    ressource_trouvee = true;
                                    effet_ressource_gratuite_commerce_utilise = true;
                                    break;
                                }
                            }
                            if (ressource_trouvee) {
                                break;
                            }
                        }
                        if (ressource_trouvee) {
                            break;
                        }
                    }
                }
            }

            // si le joueur n'a pas assez de la ressource, on verifie s'il peut en acheter e la banque
            if (nb_ressources_residuel > 0) {
                // on verifie tout d'abord si le joueur dispose d'une carte commerciale qui change la regle du commerce pour la ressource
                // e laquelle on s'interesse dans cette iteration

                int cout_monetaire_unitaire;
                bool regle_changee = false;
                for (const auto &pair_cartes: joueur_acheteur.getCartes()) {
                    if (pair_cartes.first == TCommercial) {
                        for (const Carte *carte: pair_cartes.second) {
                            const Commercial *commercial = static_cast<const Commercial *>(carte);
                            for (int i = 0; i < commercial->getNbBaissesPrix(); i++) {
                                BaissesPrix baisses_prix = commercial->getBaissesPrix(i);
                                if (baisses_prix.find(pair.first) != baisses_prix.end()) {
                                    cout_monetaire_unitaire = baisses_prix.at(pair.first);
                                    regle_changee = true;
                                    break;
                                }
                            }
                            if (regle_changee) {
                                break;
                            }
                        }
                    }
                    if (regle_changee) {
                        break;
                    }
                }
                if (!regle_changee) {
                    // TODO Les ressources produites par les cartes jaunes et les Merveilles ne comptent pas dans le coet du commerce.
                    int nb_ressources_joueur_adversaire = joueur_adversaire.getRessource(pair.first);
                    cout_monetaire_unitaire = 2 + nb_ressources_joueur_adversaire;
                }
                int cout_monetaire_total = nb_ressources_residuel * cout_monetaire_unitaire;
                if (cout_monetaire_total > joueur_acheteur.getRessource(Piece)) {
                    achat_possible = false;
                } else {
                    // on retire directement les pieces necessaires e l'achat des ressources du joueur
                    joueur_acheteur.retirerRessource(Piece, cout_monetaire_total);
                }
            }
        }

        // on ne le fait pas dans le cas du chainage, car la carte est gratuite donc n'enleve aucune ressource
        if (achat_possible) {
            for (const auto &pair: carte->getCoutRessources()) {
                int nb_ressources_joueur = joueur_acheteur.getRessource(pair.first);
                if (nb_ressources_joueur <
                    pair.second) {// Cela veut dire qu'il manquait des ressources au joueur_acheteur,
                    // donc il a achete des ressources grece e ses pieces (qui lui ont deje ete retirees pour payer cet achat).
                    // On retire donc toutes les ressources du joueur, de faeon e ce qu'il en ait 0 et non pas un nombre negatif.
                    joueur_acheteur.retirerRessource(pair.first,
                                                     nb_ressources_joueur);
                } else {// Cela veut dire que, pour la ressource dont il est question dans l'iteration,
                    // le nb_ressources_residuel etait <= 0
                    joueur_acheteur.retirerRessource(pair.first, pair.second);
                }
            }
        }
    }

    // si l'achat est possible (par chainage ; simplement avec les ressources dont il dispose ; apres achat e la banque) :
    if (achat_possible) {
        // on ajoute la carte au deck du joueur_acheteur
        joueur_acheteur.ajouterCarte(carte);

        // on ajoute les gains donnes par la carte au joueur_acheteur
        ajouterGains(carte, joueur_acheteur);

        // on supprime la carte des cartes disponibles
        plateau.acheterCarte(emplacement);
    } else {
        cout
                << "La carte ne peut etre achete(e), car vous manquez a la fois de ressources mais aussi de pieces pour en acheter le nombre suffisant manquant."
                << endl;
        jouerUnTour(((joueur_acheteur == joueur1) ? J1 : J2));
    }
}

void Jeu::ajouterGains(const Carte *carte, Joueur &joueur) {
    TypeCarte type_carte = carte->getType();

    if (type_carte == TypeCarte::TMatierePremiere || type_carte == TypeCarte::TManufacture) {
        joueur.ajouterRessource(carte->getRessourceProduite(), carte->getNbRessourcesProduites());
    } else if (type_carte == TypeCarte::TCivil) {
        joueur.ajouterPoints(carte->getNbPointsVictoire());
    } else if (carte->getType() == TypeCarte::TScientifique) {
        joueur.ajouterPoints(carte->getNbPointsVictoire());
        joueur.ajouterSymboleScientifique(carte->getSymbole());
        int nb_symbole_scientifique = joueur.getNbSymboleScientifique(carte->getSymbole());
        if (nb_symbole_scientifique == 2) {
            // TODO : choix du symbole scientifique et gestion de l'effet associe
        }
    } else if (carte->getType() == TypeCarte::TMilitaire) {
        int valeur_militaire = static_cast<const Militaire *>(carte)->getNbBoucliers();
        plateau.avancerPionConflit(valeur_militaire, this->tour);
    } else if (carte->getType() == TypeCarte::TCommercial) {
        joueur.ajouterRessource(Piece, carte->getNbPieces());
        joueur.ajouterPoints(carte->getNbPointsVictoire());
        // TODO getRessourceGratuite() + getNbRessourcesGratuites() + getBaissesPrix() + getNbBaissesPrix()
        TypeCarte type_carte_donnant_points = carte->getBatimentGainPieces();
        if (type_carte_donnant_points != TAucun) {
            int nb_cartes_du_type_possedees = joueur.getCartes()[type_carte_donnant_points].size();
            joueur.ajouterPoints(carte->getGainPiecesParBatiment() * nb_cartes_du_type_possedees);
        }
    } else {// TGuilde
        // TODO affecter les effets de la carte au joueur
    }
}

int Jeu::choixCarte() {
    map<int, const Carte *> disponible = plateau.getCartesDisponibles();
    //affichage cartes dispo
    for (const auto &pair: disponible) {
        cout << "Position : " << pair.first + 1 << ", Carte : " << pair.second->getNom()
             << toStringMap(pair.second->getCoutRessources(), " (Cout") << ")" << endl;
        cout << pair.second->toString();
        cout << pair.second->getChainage() << endl;
    }

    Joueur &joueur = getJoueur(tour);
    //fin affichage
    cout << joueur.getNom() << ", vous possedez"
         << toStringMap(joueur.getDictRessources(), "") << ", " << joueur.getPoints() << " points de victoire et "
         << joueur.getTotalSymbolesScientifiquesDifferent() << " symboles scientifiques differents." << endl;
    cout << "Quelle carte voulez-vous ? Rentrez sa position : ";
    int carte_choisie;
    cin >> carte_choisie;
    carte_choisie--;
    if (disponible.find(carte_choisie) == disponible.end()) {
        cout << "Veuillez choisir une carte valide." << endl;
        return choixCarte();
    } else {
        return carte_choisie;
    }
}

int Jeu::choixAction() {
    cout << "Veuillez choisir une action" << endl
         << "1- Construire le Batiment " << endl
         << "2- Defausser la carte" << endl;

    int choix_max = 2;
    if (nb_merveilles_construites < NB_MERVEILLES_MAX) {
        cout << "3- Construire une merveille" << endl;
        choix_max++;
    }
    cout << "Votre choix : ";
    int choix;
    cin >> choix;
    if (choix < 1 || choix > choix_max) {
        cout << "Veuillez choisir une action valide" << endl;
        return choixCarte();
    }
    return choix;
}

void Jeu::jouerUnTour(NumJoueur j) {
    Joueur &joueur = getJoueur(j);
    int position_carte = choixCarte();
    int action = choixAction();

    // construire
    if (action == 1) {
        acheterCarte(joueur, position_carte);
    }

        //defausser
    else if (action == 2) {
        const Carte *carte = plateau.getCartesDisponibles()[position_carte];
        // plateau.defausserCarte(position_carte);
        // on supprime la carte des cartes disponibles
        plateau.acheterCarte(position_carte);
        joueur.ajouterCarteDefausse(carte);
        // pour ajouter les gains associes e cette defausse au joueur
        DictCartes cartes_joueur = joueur.getCartes();
        int nombre_cartes_commerciales = cartes_joueur[TCommercial].size();
        joueur.ajouterRessource(Piece, 2 + nombre_cartes_commerciales);
    }
        //Construire merveille
    else {
        const Merveille *merveille = choixMerveilleAconstruire(joueur);
        construireMerveille(joueur, position_carte, merveille);
    }
}


int Jeu::calculPointsVictoire(NumJoueur joueur) {
    int points = 0;
    Joueur &j = getJoueur(joueur);
    points += j.getPoints();// ce sont les points de victoire rapportes par les cartes Betiment, les Merveilles et les Jetons Progres

    // calcul des points rapportes par les pieces => 3 pieces rapportent 1 point
    int pieces = j.getRessource(Piece);
    points += pieces / 3;

    // calcul des points rapportes par la position du Pion Conflit
    if (joueur == J1) {
        if (plateau.getPionConflit() <= (-PALIER_TROIS_POINTS_PION_CONFLIT)) {
            points += 10;
        } else if (plateau.getPionConflit() <= (-PALIER_DEUX_POINTS_PION_CONFLIT)) {
            points += 5;
        } else if (plateau.getPionConflit() <= (-PALIER_UN_POINTS_PION_CONFLIT)) {
            points += 2;
        }
    } else if (joueur == J2) {
        if (plateau.getPionConflit() >= PALIER_TROIS_POINTS_PION_CONFLIT) {
            points += 10;
        } else if (plateau.getPionConflit() >= PALIER_DEUX_POINTS_PION_CONFLIT) {
            points += 5;
        } else if (plateau.getPionConflit() >= PALIER_UN_POINTS_PION_CONFLIT) {
            points += 2;
        }
    }

    return points;
}

int Jeu::calculPointsCivil(NumJoueur joueur) {
    DictCartes cartes = getJoueur(joueur).getCartes();
    int points = 0;

    for (const auto &pair: cartes) {
        for (const auto &carte: pair.second) {
            if (carte->getType() == TypeCarte::TCivil) {
                points += carte->getNbPointsVictoire();
            }
        }
    }

    return points;
}

bool Jeu::verifierChainage(Joueur *joueur, const Carte *carte) {
    int id_a_trouver = carte->getIDChainagePrecedent();

    if (id_a_trouver == 0) {
        return false;
    }

    for (const auto &pair: joueur->getCartes()) {
        for (const auto &c: pair.second) {
            if (c->getIDChainageSuivant() == id_a_trouver) {
                return true;
            }
        }
    }

    return false;
}

void Jeu::avancerTour() {
    tour = (tour == J1) ? J2 : J1;
    cout << "\nC'est au tour de " << ((tour == J1) ? joueur1.getNom() : joueur2.getNom())
         << ". Position du pion de conflit : " << plateau.getPionConflit() << endl;
}