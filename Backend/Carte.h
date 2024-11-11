#ifndef CARTE_H
#define CARTE_H

// include CExceptions
#include <exception>

#include "../Data/UtilsClasses.h"

typedef map<Ressource, int> DictRessources, CoutsRessources, BaissesPrix;

using namespace std;

class Carte {
public:
    virtual ~Carte() = default;

    bool operator==(const Carte &c) const {
        return id == c.id;
    }

    bool operator!=(const Carte &c) const {
        return id != c.id;
    }

    static const Carte *getCardByID(int id_carte);

    virtual string toString() const = 0;

    void afficher(ostream &f = std::cout) const { //template method
        f << "------------------\n";
        f << "* Nom : " << nom << "\n";
        f << chainage << "\n";
        f << toStringMap(cout_ressources, "* Cout") << "\n";
        f << "* Type : " << type_carte_to_string[type] << "\n";
        f << toString();
    }

    int getId() const { return id; }

    TypeCarte getType() const { return type; }

    const string &getNom() const { return nom; }

    int getAge() const { return age; }

    Chainage getChainage() const { return chainage; }

    SymboleChainage getSymboleChainagePrecedent() const { return chainage.symbole_age_precedent; }

    int getIDChainagePrecedent() const { return chainage.id_carte_age_precedent; }

    SymboleChainage getSymboleChainageSuivant() const { return chainage.symbole_age_suivant; }

    int getIDChainageSuivant() const { return chainage.id_carte_age_suivant; }

    CoutsRessources getCoutRessources() const { return cout_ressources; }

    int getNbCoutRessources() const { return (int) cout_ressources.size(); }

    int getCoutRessource(Ressource ressource) const { return cout_ressources.at(ressource); }

    virtual EffetMerveille getEffet(int index) const { throw CException("Erreur : Pas d'effet merveille"); }

    virtual Ressource getRessourceProduite() const { throw CException("Erreur : Pas de ressources produites"); }

    virtual int getNbRessourcesProduites() const { throw CException("Erreur : Pas de ressources produites"); }

    virtual SymboleScientifique getSymbole() const { throw CException("Erreur : Pas de Symboles"); }

    virtual int getNbPointsVictoire() const { throw CException("Erreur : Pas de points de victoire"); }

    virtual int getNbPieces() const { throw CException("Erreur : Pas de pieces"); }

    virtual Ressource getRessourceGratuite(int index) const {
        throw CException("Erreur : Pas de ressources gratuites");
    }

    virtual int getNbRessourcesGratuites() const { throw CException("Erreur : Pas de ressources gratuites"); }

    virtual BaissesPrix getBaissesPrix(int index) const { throw CException("Erreur : Pas de baisse de prix"); }

    virtual int getNbBaissesPrix() const { throw CException("Erreur : Pas de baisse de prix"); }

    virtual TypeCarte getBatimentGainPieces() const { throw CException("Erreur : Pas de batiment de gain de pieces"); }

    virtual int getGainPiecesParBatiment() const {
        throw CException("Erreur : Pas de gains de pieces par batiment");;
    }

    virtual int getNbBoucliers() const { throw CException("Erreur : pas de Boucliers"); }

    virtual const EffetGuilde getEffet() const { throw CException("Erreur : pas d'effet de Guilde"); }

    virtual int getNbEffets() const { throw CException("Erreur : pas d'effet de Guilde"); }

protected:
    const int id;
    const TypeCarte type;
    const string nom;
    const int age;

    Chainage chainage;

    CoutsRessources cout_ressources;

    Carte(int id,
          TypeCarte type,
          const string &nom,
          int age,
          Chainage chainage,
          CoutsRessources cout_ressources) : id(id),
                                             type(type),
                                             nom(nom),
                                             age(age),
                                             chainage(chainage),
                                             cout_ressources(cout_ressources) {}
};


class MatierePremiere : public Carte {
public:
    MatierePremiere(int id,
                    const string &nom,
                    int age,
                    Chainage chainage,
                    CoutsRessources cout_ressources,
                    Ressource ressource_produite,
                    int nb_ressources_produites) : Carte(id,
                                                         TMatierePremiere,
                                                         nom,
                                                         age,
                                                         chainage,
                                                         cout_ressources),
                                                   ressource_produite(ressource_produite),
                                                   nb_ressources_produites(nb_ressources_produites) {}

    ~MatierePremiere() = default;

    Ressource getRessourceProduite() const override { return ressource_produite; }

    int getNbRessourcesProduites() const override { return nb_ressources_produites; }

    string toString() const override {
        stringstream f;
        f << "***Attributs speciaux Matiere Premiere"
          << "\n";
        f << "Ce batiment produit " << getNbRessourcesProduites() << " " << ressource_to_string[getRessourceProduite()]
          << "(s) par tour. \n";
        return f.str();
    }

private:
    const Ressource ressource_produite;
    const int nb_ressources_produites;
};


class Manufacture : public Carte {
public:
    Manufacture(int id,
                const string &nom,
                int age,
                Chainage chainage,
                CoutsRessources cout_ressources,
                Ressource ressource_produite,
                int nb_ressources_produites) : Carte(id,
                                                     TManufacture,
                                                     nom,
                                                     age,
                                                     chainage,
                                                     cout_ressources),
                                               ressource_produite(ressource_produite),
                                               nb_ressources_produites(nb_ressources_produites) {}

    ~Manufacture() = default;

    Ressource getRessourceProduite() const override { return ressource_produite; }

    int getNbRessourcesProduites() const override { return nb_ressources_produites; }

    string toString() const override {
        stringstream f;
        f << "***Attributs speciaux Manufacture"
          << "\n";

        f << "Ce batiment produit " << getNbRessourcesProduites() << " " << ressource_to_string[getRessourceProduite()]
          << "(s) par tour. \n";
        return f.str();
    }

private:
    const Ressource ressource_produite;
    const int nb_ressources_produites;
};


class Civil : public Carte {
public:
    Civil(int id,
          const string &nom,
          int age,
          Chainage chainage,
          CoutsRessources cout_ressources,
          int nb_points_victoire) : Carte(id,
                                          TCivil,
                                          nom,
                                          age,
                                          chainage,
                                          cout_ressources),
                                    nb_points_victoire(nb_points_victoire) {}

    ~Civil() = default;

    int getNbPointsVictoire() const override { return nb_points_victoire; }

    string toString() const override {
        stringstream f;
        f << "***Attributs speciaux Civil"
          << "\n";
        f << "Nombre de points donnes : " << getNbPointsVictoire() << "\n";
        return f.str();
    }

private:
    const int nb_points_victoire;
};


class Scientifique : public Carte {
public:
    Scientifique(int id,
                 const string &nom,
                 int age,
                 Chainage chainage,
                 CoutsRessources cout_ressources,
                 SymboleScientifique symbole,
                 int nb_points_victoire) : Carte(id,
                                                 TScientifique,
                                                 nom,
                                                 age,
                                                 chainage,
                                                 cout_ressources),
                                           symbole(symbole),
                                           nb_points_victoire(nb_points_victoire) {}

    ~Scientifique() = default;

    SymboleScientifique getSymbole() const override { return symbole; }

    int getNbPointsVictoire() const override { return nb_points_victoire; }

    string toString() const override {
        stringstream f;
        f << "***Attributs speciaux Scientifique"
          << "\n";
        f << "Nombre de points donnes : " << getNbPointsVictoire() << "\n";
        f << "Symbole Scientifique : " << symbole_scientifique_to_string[getSymbole()] << "\n";
        return f.str();
    }

private:
    const SymboleScientifique symbole;
    const int nb_points_victoire;
};


class Commercial : public Carte {
public:
    Commercial(int id,
               const string &nom,
               int age,
               Chainage chainage,
               CoutsRessources cout_ressources,
               int nb_pieces,
               int nb_points_victoire,
               const vector<Ressource> ressources_gratuites,
               const BaissesPrix baisses_prix,
               TypeCarte batiment_gain_pieces,
               int gain_pieces_par_batiment) : Carte(id,
                                                     TCommercial,
                                                     nom,
                                                     age,
                                                     chainage,
                                                     cout_ressources),
                                               nb_pieces(nb_pieces),
                                               nb_points_victoire(nb_points_victoire),
                                               ressources_gratuites(ressources_gratuites),
                                               baisses_prix(baisses_prix),
                                               batiment_gain_pieces(batiment_gain_pieces),
                                               gain_pieces_par_batiment(gain_pieces_par_batiment) {}

    ~Commercial() = default;

    int getNbPieces() const override { return nb_pieces; }

    int getNbPointsVictoire() const override { return nb_points_victoire; }

    Ressource getRessourceGratuite(int index) const override { return ressources_gratuites[index]; }

    int getNbRessourcesGratuites() const override { return (int) ressources_gratuites.size(); }

    BaissesPrix getBaissesPrix(int index) const override { return baisses_prix; }

    int getNbBaissesPrix() const override { return (int) baisses_prix.size(); }

    TypeCarte getBatimentGainPieces() const override { return batiment_gain_pieces; }

    int getGainPiecesParBatiment() const override { return gain_pieces_par_batiment; }

    string toString() const override {
        stringstream f;
        f << "***Attributs speciaux Commercial"
          << "\n";
        f << "Nombre de pieces : " << getNbPieces() << "\n";
        f << "Nombre de points donnes : " << getNbPointsVictoire() << "\n";

        for (size_t i = 0; i <
                           ressources_gratuites.size(); i++) {//Erreur : possible car j'accede directement par l'attribut ? Si oui -> Besoin d'un getter global
            f << "Ressource gratuite numero " << i + 1 << " - " << ressource_to_string[getRessourceGratuite(i)] << "\n";
        }

        for (const auto &pair: baisses_prix) {
            f << ressource_to_string[pair.first] << " passe a " << pair.second << " piece(s) \n";
        }

        if (type_carte_to_string[getBatimentGainPieces()] != "Aucun") {
            f << type_carte_to_string[getBatimentGainPieces()] << " donne " << getGainPiecesParBatiment()
              << " pieces par unite possedee." << "\n";
        }
        return f.str();
    }

private:
    const int nb_pieces;
    const int nb_points_victoire;

    const vector<Ressource> ressources_gratuites;

    const BaissesPrix baisses_prix;

    const TypeCarte batiment_gain_pieces;
    const int gain_pieces_par_batiment;
};


class Militaire : public Carte {
public:
    Militaire(int id,
              const string &nom,
              int age,
              Chainage chainage,
              CoutsRessources cout_ressources,
              int nb_boucliers) : Carte(id,
                                        TMilitaire,
                                        nom,
                                        age,
                                        chainage,
                                        cout_ressources),
                                  nb_boucliers(nb_boucliers) {}

    ~Militaire() = default;

    int getNbBoucliers() const override { return nb_boucliers; }

    string toString() const override {
        stringstream f;
        f << "***Attributs speciaux de Militaire"
          << "\n";
        f << "Nombre de Boucliers donnes : " << getNbBoucliers() << "\n";
        return f.str();
    }

private:
    const int nb_boucliers;
};


class Guilde : public Carte {
public:
    Guilde(int id,
           const string &nom,
           CoutsRessources cout_ressources,
           const EffetGuilde effet) : Carte(id,
                                            TGuilde,
                                            nom,
                                            3,
                                            {SCAucun, 0, SCAucun, 0},
                                            cout_ressources),
                                      effet(effet) {}

    ~Guilde() = default;

    const EffetGuilde getEffet() const override { return effet; }

    string toString() const override {
        stringstream f;
        f << "***Attributs speciaux de Guilde"
          << "\n";
        f << getEffet() << "\n";
        return f.str();
    }

private:
    const EffetGuilde effet;
};


class Merveille : public Carte {
public:
    Merveille(int id,
              const string &nom,
              CoutsRessources cout_ressources,
              int nb_boucliers,
              int nb_points_victoire,
              int nb_pieces,
              vector<EffetMerveille> effets) : Carte(id,
                                                     TMerveille,
                                                     nom,
                                                     0,
                                                     {SCAucun, 0, SCAucun, 0},
                                                     cout_ressources),
                                               nb_boucliers(nb_boucliers),
                                               nb_points_victoire(nb_points_victoire),
                                               nb_pieces(nb_pieces),
                                               effets(effets) {}

    ~Merveille() = default;

    int getNbBoucliers() const override { return nb_boucliers; }

    int getNbPointsVictoire() const override { return nb_points_victoire; }

    int getNbPieces() const override { return nb_pieces; }

    EffetMerveille getEffet(int index) const override { return effets[index]; }

    int getNbEffets() const override { return (int) effets.size(); }

    string toString() const override {
        stringstream f;
        f << "***Attributs speciaux de Merveille"
          << "\n";
        f << "Nombre de Boucliers donnes : " << getNbBoucliers() << "\n";
        f << "Nombre de points donnes : " << getNbPointsVictoire() << "\n";
        f << "Nombre de pieces donnes : " << getNbPieces() << "\n";
        f << "Nombre d'effets : " << getNbEffets() << "\n";
        for (size_t i = 0; i < getNbEffets(); i++) {
            f << getEffet((int) i) << "\n";
        }

        return f.str();
    }

private:
    const int nb_boucliers;
    const int nb_points_victoire;
    const int nb_pieces;

    const vector<EffetMerveille> effets;
};

#endif
