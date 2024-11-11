#ifndef EFFETS_GUILDES_H
#define EFFETS_GUILDES_H

#include "../../UtilsClasses.h"

const EffetGuilde EFFET_ARMATEURS = {
        Armateurs,
        "Guilde des Armateurs",
        "Au moment où elle est construite, la carte rapporte 1 pièce au joueur par carte marron et grise dans la cité qui en possède le plus grand nombre.\n"
        "À la fin du jeu, cette carte rapporte 1 point de victoire par carte marron et grise dans la cité qui en possède le plus grand nombre.\n"
        "Précision : Le joueur est obligé de choisir une et une seule cité pour les 2 couleurs de carte."};

const EffetGuilde EFFET_BATISSEURS = {
        Batisseurs,
        "Guilde des Bâtisseurs",
        "À la fin du jeu, cette carte rapporte 2 points de victoire par Merveille construite dans la cité qui en possède le plus grand nombre."};

const EffetGuilde EFFET_COMMERCANTS = {
        Commercants,
        "Guilde des Commerçants",
        "Au moment où elle est construite, la carte rapporte 1 pièce au joueur par carte jaune dans la cité qui en possède le plus grand nombre.\n"
        "À la fin du jeu, cette carte rapporte 1 point de victoire par  carte jaune dans la cité qui en possède le plus grand nombre."};

const EffetGuilde EFFET_MAGISTRATS = {
        Magistrats,
        "Guilde des Magistrats",
        "Au moment où elle est construite, la carte rapporte 1 pièce au joueur par carte bleue dans la cité qui en possède le plus grand nombre.\n"
        "À la fin du jeu, cette carte rapporte 1 point de victoire par  carte bleue dans la cité qui en possède le plus grand nombre."};

const EffetGuilde EFFET_TACTICIENS = {
        Tacticiens,
        "Guilde des Tacticiens",
        "Au moment où elle est construite, la carte rapporte 1 pièce au joueur par carte rouge dans la cité qui en possède le plus grand nombre.\n"
        "À la fin du jeu, cette carte rapporte 1 point de victoire par  carte rouge dans la cité qui en possède le plus grand nombre."};

const EffetGuilde EFFET_SCIENTIFIQUES = {
        Scientifiques,
        "Guilde des Scientifiques",
        "Au moment où elle est construite, la carte rapporte 1 pièce au joueur par carte verte dans la cité qui en possède le plus grand nombre.\n"
        "À la fin du jeu, cette carte rapporte 1 point de victoire par  carte verte dans la cité qui en possède le plus grand nombre."};

const EffetGuilde EFFET_USURIERS = {
        Usuriers,
        "Guilde des Usuriers",
        "À la fin du jeu, cette carte rapporte 1 point de victoire par  lot de 3 pièces dans la cité la plus riche."};

#endif
