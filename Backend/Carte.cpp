//
// Créé par Mohamed Tahiri le 18/05/2024.
//

#include "../Data/consts.h"
#include "Carte.h"

const Carte *Carte::getCardByID(int id_carte) {
    for (const Carte *carte: CARTES_AGE_1) {
        if (carte->getId() == id_carte) {
            return (Carte *) carte;
        }
    }
    for (const Carte *carte: CARTES_AGE_2) {
        if (carte->getId() == id_carte) {
            return (Carte *) carte;
        }
    }
    for (const Carte *carte: CARTES_AGE_3) {
        if (carte->getId() == id_carte) {
            return (Carte *) carte;
        }
    }
    return nullptr;
}
