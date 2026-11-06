#include <iostream>
#include <string>
using namespace std;

// Classe de base
class Personne {
protected:
    string nom;
    int age;

public:
    // Constructeur
    Personne(string n, int a) {
        nom = n;
        age = a;
    }

    // Méthode afficher
    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Age : " << age << endl;
    }
};

// Classe dérivée
class Etudiant : public Personne {
private:
    string niveau;

public:
    // Constructeur de la classe Etudiant
    Etudiant(string n, int a, string niv)
        : Personne(n, a) {
        niveau = niv;
    }

    // Méthode afficher
    void afficher() {
        Personne::afficher();
        cout << "Niveau : " << niveau << endl;
    }
};

// Fonction principale
int main() {

    Etudiant e1("Ikram", 21, "Licence");

    cout << "Informations de l'etudiant :" << endl;
    e1.afficher();

    return 0;
}
