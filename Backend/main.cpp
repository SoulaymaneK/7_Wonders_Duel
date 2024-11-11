//
// Créé par Mohamed Tahiri le 18/05/2024.
//

#include "Jeu.h"
#include <iostream>

using namespace std;

int main() {
    srand(time(nullptr));

    Jeu &jeu = Jeu::getInstance();

    jeu.debuterJeu();

    return 0;
}
