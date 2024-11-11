#include "../Data/UtilsClasses.h"
#include "Carte.h"
#include "Joueur.h"
#include "Plateau.h"


//Fichier de fonctions d'affichage

std::ostream &operator<<(std::ostream &f, const JetonMilitaire &jeton_militaire) {
    f << "***JETON MILITAIRE" << "\n";
    f << "* Nom: " << jeton_militaire.nom << "\n";
    f << "* Description: " << jeton_militaire.description << "\n";
    f << "* Nombre de pieces 'perdues': " << jeton_militaire.nb_pieces_perdues << "\n";
    return f;
}

std::ostream &operator<<(std::ostream &f, const EffetJetonProgres &effet_jeton_progres) {
    f << "***EFFET JETON PROGRES" << "\n";
    f << "Nom Effet: " << effet_jeton_progres.effet << "\n";
    f << "Nom: " << effet_jeton_progres.nom << "\n";
    f << "Description: " << effet_jeton_progres.description << "\n";
    return f;
}

std::ostream &operator<<(std::ostream &f, const JetonProgres &jeton_progres) {
    f << "***JETON PROGRES" << "\n";
    f << "Nom: " << jeton_progres.nom << "\n";
    f << "Nombre pieces: " << jeton_progres.nb_pieces << "\n";
    f << "Nombre points Victoire: " << jeton_progres.nb_points_victoire << "\n";
    f << jeton_progres.effet;
    return f;
}


std::ostream &operator<<(std::ostream &f, const Chainage &chainage) {
    if (chainage.id_carte_age_precedent != 0)
        f << "Chainee avec l'age precedent par la carte "
          << Carte::getCardByID(chainage.id_carte_age_precedent)->getNom()
          << " ("
          << symbole_chainage_to_string[chainage.symbole_age_precedent] << ")" << "\n";

    if (chainage.id_carte_age_suivant != 0)
        f << "Chainee avec l'age suivant par la carte " << Carte::getCardByID(chainage.id_carte_age_suivant)->getNom()
          << " ("
          << symbole_chainage_to_string[chainage.symbole_age_suivant] << ")" << "\n";

    return f;
}

std::ostream &operator<<(std::ostream &f, const EffetGuilde &effet_guilde) {
    f << "***Effet Guilde" << "\n";
    f << "Nom : " << effet_guilde.nom << "\n";
    f << "Description : " << effet_guilde.description << "\n";
    return f;
}


std::ostream &operator<<(std::ostream &f, const EffetMerveille &effet_merveille) {
    f << "***Effet Merveille" << "\n";
    f << "Nom : " << effet_merveille.nom << "\n";
    f << "Description : " << effet_merveille.description << "\n";
    return f;
}


std::ostream &operator<<(std::ostream &f, const DictRessources &dict_ressources) {
    f << "***Ressources " << "\n";
    for (const auto &pair: dict_ressources) {
        f << "  Ressource : " << ressource_to_string[pair.first] << "| Quantite : " << pair.second << "\n";
    }
    return f;
}


/*
std::ostream& operator <<(std::ostream& f, const CoutsRessources& couts_ressources) {
	f << "***Couts Ressources " << "\n";
	for (const auto& pair : couts_ressources) {
		f << "Ressource: " << pair.first << "| Quantit�: " << pair.second << "\n";
	}
	return f;
}



std::ostream& operator <<(std::ostream& f, const BaissesPrix& baisses_prix) {
	f << "***Baisse prix " << "\n";
	for (const auto& pair : baisses_prix) {
		f << "Ressource: " << pair.first << "| Quantit�: " << pair.second << "\n";
	}
	return f;

}
*/

std::ostream &operator<<(std::ostream &f, const DictCartes &dict_cartes) {
    f << "***Cartes du joueur " << "\n";
    for (const auto &pair: dict_cartes) {
        f << "Type de carte : " << type_carte_to_string[pair.first];

        for (size_t i = 0; i < pair.second.size(); i++) {
            f << pair.second[i];
        }

    }
    return f;
}


void Joueur::afficherJoueur(ostream &f) const {
    f << "***Information sur " << nom << " *** \n";
    f << dict_ressources << "\n";
    f << "Nombre de points : " << points << "\n";
    f << dict_cartes << "\n";
    f << "DEFAUSSE -> " << defausse << "\n";

    f << "* Symboles scientifiques : " << "\n";
    for (const auto &pair: dict_symboles_scientifiques) {
        f << "Symbole : " << symbole_scientifique_to_string[pair.first] << " | Quantite : " << pair.second << "\n";
    }
    f << "* Merveille a construire : " << "\n";
    for (size_t i = 0; i < merveille_a_construire.size(); i++) {
        f << merveille_a_construire[i] << "\n";
    }
}

void Plateau::afficherPlateau(ostream &f) {
    f << "*** Informations sur le Plateau ***\n";
    f << " Position du pion Conflit : " << getPionConflit() << "\n";
    f << " Jetons Progres disponibles : \n";
    for (size_t i = 0; i < getJetonsProgresDisponibles().size(); i++) {
        f << getJetonsProgresDisponibles()[i] << "\n";
    }
    f << " * Cartes disponibles : \n";
    for (const auto &pair: getCartesDisponibles()) {
        f << "Emplacement : " << pair.first << "\n";
        f << "Carte : ";
        pair.second->afficher(f);
        f << "\n";
    }
    f << " * Emplacements non accessibles : \n";
    for (size_t i = 0; i < getEmplacementsCaches().size(); i++) {
        f << "   Emplacement : " << getEmplacementsCaches()[i];
    }

}
