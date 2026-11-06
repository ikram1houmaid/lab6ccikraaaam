#include <iostream>
#include <string>
using namespace std;

// Classe de base
class Produit {
protected:
    string nom;
    double prix;

public:
    // Constructeur
    Produit(string n, double p) {
        nom = n;
        prix = p;
    }

    // Methode virtuelle
    virtual void afficherInfos() {
        cout << "Nom du produit : " << nom << endl;
        cout << "Prix : " << prix << " DH" << endl;
    }

    // Destructeur virtuel
    virtual ~Produit() {}
};

// Classe derivee : ProduitAlimentaire
class ProduitAlimentaire : public Produit {
private:
    string dateExpiration;

public:
    // Constructeur
    ProduitAlimentaire(string n, double p, string date)
        : Produit(n, p) {
        dateExpiration = date;
    }

    // Redefinition de la methode
    void afficherInfos() override {
        cout << "=== Produit Alimentaire ===" << endl;
        Produit::afficherInfos();
        cout << "Date d'expiration : " << dateExpiration << endl;
    }
};

// Classe derivee : ProduitElectronique
class ProduitElectronique : public Produit {
private:
    int garantie;

public:
    // Constructeur
    ProduitElectronique(string n, double p, int g)
        : Produit(n, p) {
        garantie = g;
    }

    // Redefinition de la methode
    void afficherInfos() override {
        cout << "=== Produit Electronique ===" << endl;
        Produit::afficherInfos();
        cout << "Garantie : " << garantie << " ans" << endl;
    }
};

// Fonction principale
int main() {

    // Creation des objets
    ProduitAlimentaire p1("Lait", 8.5, "15/12/2026");

    ProduitElectronique p2("Ordinateur", 6500, 2);

    // Affichage des informations
    p1.afficherInfos();

    cout << endl;

    p2.afficherInfos();

    return 0;
}
