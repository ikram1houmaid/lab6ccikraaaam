
#include <iostream>
#include <string>
using namespace std;

// Classe de base
class Employe {
protected:
    string nom;
    int id;
    float salaireDeBase;

public:
    // Constructeur
    Employe(string n, int i, float s) {
        nom = n;
        id = i;
        salaireDeBase = s;
    }

    // Methode virtuelle
    virtual void afficherInfos() {
        cout << "Nom : " << nom << endl;
        cout << "ID : " << id << endl;
        cout << "Salaire de base : " << salaireDeBase << " DH" << endl;
    }

    // Destructeur virtuel
    virtual ~Employe() {
        cout << "Destruction de l'employe : " << nom << endl;
    }
};

// Classe derivee Permanent
class Permanent : public Employe {
private:
    float primeAnnuelle;

public:
    // Constructeur
    Permanent(string n, int i, float s, float prime)
        : Employe(n, i, s) {
        primeAnnuelle = prime;
    }

    // Redefinition de afficherInfos()
    void afficherInfos() override {
        cout << "=== Employe Permanent ===" << endl;
        Employe::afficherInfos();
        cout << "Prime annuelle : " << primeAnnuelle << " DH" << endl;
    }
};

// Classe derivee Contractuel
class Contractuel : public Employe {
private:
    int dureeContrat;
    float tauxHoraire;

public:
    // Constructeur
    Contractuel(string n, int i, float s, int duree, float taux)
        : Employe(n, i, s) {
        dureeContrat = duree;
        tauxHoraire = taux;
    }

    // Calcul du salaire mensuel
    float calculerSalaireMensuel(int heures) {
        return heures * tauxHoraire;
    }

    // Redefinition de afficherInfos()
    void afficherInfos() override {
        cout << "=== Employe Contractuel ===" << endl;
        Employe::afficherInfos();
        cout << "Duree du contrat : " << dureeContrat << " mois" << endl;
        cout << "Taux horaire : " << tauxHoraire << " DH" << endl;
    }
};

// Fonction principale
int main() {

    // Creation d'un tableau dynamique de pointeurs
    Employe** employes = new Employe*[3];

    // Creation des employes
    employes[0] = new Permanent("Ikram", 1, 6000, 3000);
    employes[1] = new Contractuel("Sara", 2, 4000, 6, 50);
    employes[2] = new Permanent("Amine", 3, 7000, 5000);

    // Affichage des informations
    cout << "===== LISTE DES EMPLOYES =====" << endl;

    for (int i = 0; i < 3; i++) {
        cout << endl;
        employes[i]->afficherInfos();
    }

    // Test de calcul du salaire contractuel
    cout << "\n===== CALCUL DU SALAIRE =====" << endl;

    Contractuel* c = dynamic_cast<Contractuel*>(employes[1]);

    if (c != nullptr) {
        cout << "Salaire mensuel de Sara : "
             << c->calculerSalaireMensuel(160)
             << " DH" << endl;
    }

    // Liberation de la memoire
    for (int i = 0; i < 3; i++) {
        delete employes[i];
    }

    delete[] employes;

    return 0;
}
