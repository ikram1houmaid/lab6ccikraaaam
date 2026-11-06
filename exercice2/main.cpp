#include <iostream>
#include <string>
using namespace std;

// Classe de base
class Compte {
protected:
    string numero;
    double solde;

public:
    // Constructeur
    Compte(string num, double s) {
        numero = num;
        solde = s;
    }

    // Méthode pour déposer de l'argent
    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            cout << "Depot de " << montant << " DH effectue." << endl;
        } else {
            cout << "Montant invalide !" << endl;
        }
    }

    // Méthode pour retirer de l'argent
    void retirer(double montant) {
        if (montant > 0 && montant <= solde) {
            solde -= montant;
            cout << "Retrait de " << montant << " DH effectue." << endl;
        } else {
            cout << "Retrait impossible !" << endl;
        }
    }

    // Afficher les informations
    void afficher() {
        cout << "Numero du compte : " << numero << endl;
        cout << "Solde : " << solde << " DH" << endl;
    }
};

// Classe dérivée
class CompteEpargne : public Compte {
private:
    double tauxInteret;

public:
    // Constructeur
    CompteEpargne(string num, double s, double taux)
        : Compte(num, s) {
        tauxInteret = taux;
    }

    // Calculer les interets
    void calculerInteret() {
        double interet = solde * tauxInteret / 100;
        solde += interet;

        cout << "Interet ajoute : " << interet << " DH" << endl;
    }
};

// Fonction principale
int main() {

    // Creation d'un compte epargne
    CompteEpargne c1("123456", 5000, 5);

    cout << "===== Informations initiales =====" << endl;
    c1.afficher();

    cout << "\n===== Depot =====" << endl;
    c1.deposer(1000);

    cout << "\n===== Retrait =====" << endl;
    c1.retirer(500);

    cout << "\n===== Calcul des interets =====" << endl;
    c1.calculerInteret();

    cout << "\n===== Solde final =====" << endl;
    c1.afficher();

    return 0;
}
