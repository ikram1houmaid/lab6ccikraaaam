# TP : Héritage et Polymorphisme en C++

## Présentation générale

Ce TP a pour objectif de mettre en pratique les concepts fondamentaux de la programmation orientée objet (POO) en C++, notamment l'héritage, la redéfinition des méthodes, les fonctions virtuelles et le polymorphisme.

À travers quatre exercices, nous allons créer des classes de base et des classes dérivées afin de comprendre comment réutiliser les attributs et les méthodes d'une classe, tout en ajoutant des fonctionnalités spécifiques à chaque classe dérivée.

## Objectifs pédagogiques

- Comprendre le principe de l'héritage en C++.
- Utiliser l'héritage public (`public`).
- Réutiliser les attributs et les méthodes d'une classe de base.
- Maîtriser les constructeurs et les destructeurs dans l'héritage.
- Redéfinir les méthodes dans les classes dérivées.
- Comprendre le fonctionnement des méthodes virtuelles (`virtual`).
- Appliquer le polymorphisme.
- Gérer dynamiquement les objets avec les pointeurs.
- Libérer correctement la mémoire avec `delete`.

---

## Exercice 1 : Classe Personne et Etudiant

### Objectif

Comprendre le principe de l'héritage simple et la réutilisation des attributs d'une classe de base.

### Description

Cet exercice consiste à créer deux classes :

**1. Classe Personne :**
- `nom` : nom de la personne.
- `age` : âge de la personne.
- `afficher()` : méthode permettant d'afficher les informations de la personne.

**2. Classe Etudiant :**
- Hérite publiquement de la classe `Personne`.
- Possède un attribut supplémentaire `niveau`.
- Redéfinit la méthode `afficher()` pour afficher les informations complètes de l'étudiant.

### Fonctionnalités réalisées

- Création d'une classe de base `Personne`.
- Création d'une classe dérivée `Etudiant`.
- Utilisation de l'héritage public.
- Appel du constructeur de la classe de base depuis le constructeur de la classe dérivée.
- Affichage des informations de l'étudiant.

### Résultat attendu

Le programme crée un objet étudiant et affiche son nom, son âge et son niveau.

### Notions utilisées

- Héritage simple.
- Classe de base et classe dérivée.
- Constructeurs dans l'héritage.
- Redéfinition des méthodes.

---

## Exercice 2 : Compte bancaire

### Objectif

Appliquer l'héritage pour spécialiser une classe bancaire et ajouter des fonctionnalités spécifiques à un compte d'épargne.

### Description

Cet exercice consiste à créer deux classes :

**1. Classe Compte :**

Elle contient :
- `numero` : numéro du compte.
- `solde` : solde disponible.
- `deposer()` : permet d'ajouter de l'argent au compte.
- `retirer()` : permet de retirer de l'argent du compte.

**2. Classe CompteEpargne :**

Elle hérite de la classe `Compte` et contient :
- `tauxInteret` : taux d'intérêt du compte.
- `calculerInteret()` : permet de calculer les intérêts à partir du solde et du taux d'intérêt.

### Fonctionnalités réalisées

- Création d'une classe de base `Compte`.
- Création d'une classe dérivée `CompteEpargne`.
- Utilisation de l'héritage public.
- Réutilisation des attributs et méthodes de la classe de base.
- Appel du constructeur de `Compte` dans le constructeur de `CompteEpargne`.
- Réalisation des opérations de dépôt et de retrait.
- Calcul des intérêts du compte d'épargne.

### Résultat attendu

Le programme crée un compte d'épargne, effectue plusieurs opérations bancaires et affiche le solde ainsi que les intérêts calculés.

### Notions utilisées

- Héritage public.
- Constructeurs dans les classes dérivées.
- Réutilisation des méthodes.
- Spécialisation d'une classe.

---

## Exercice 3 : Hiérarchie de produits

### Objectif

Comprendre l'héritage et la redéfinition des méthodes virtuelles pour gérer plusieurs catégories de produits.

### Description

Cet exercice consiste à créer une classe de base `Produit` et deux classes dérivées.

**1. Classe Produit :**

Elle contient :
- `nom` : nom du produit.
- `prix` : prix du produit.
- `afficherInfos()` : méthode virtuelle permettant d'afficher les informations générales du produit.

**2. Classe ProduitAlimentaire :**

Elle hérite de `Produit` et ajoute :
- `dateExpiration` : date d'expiration du produit.

Elle redéfinit la méthode `afficherInfos()` pour afficher le nom, le prix et la date d'expiration.

**3. Classe ProduitElectronique :**

Elle hérite également de `Produit` et ajoute :
- `garantie` : durée de garantie du produit.

Elle redéfinit la méthode `afficherInfos()` pour afficher le nom, le prix et la garantie.

### Fonctionnalités réalisées

- Création d'une classe de base `Produit`.
- Création de deux classes dérivées.
- Déclaration d'une méthode virtuelle avec le mot-clé `virtual`.
- Redéfinition de `afficherInfos()` dans chaque classe dérivée.
- Affichage des informations spécifiques à chaque catégorie de produits.

### Résultat attendu

Le programme crée plusieurs produits alimentaires et électroniques et affiche leurs informations complètes selon leur catégorie.

### Notions utilisées

- Héritage simple.
- Méthodes virtuelles (`virtual`).
- Redéfinition des méthodes.
- Spécialisation des classes.

---

## Exercice 4 : Système de gestion d'employés

### Objectif

Maîtriser l'héritage et le polymorphisme à travers un système de gestion de différents types d'employés.

### Description

Une entreprise souhaite gérer deux catégories d'employés : les employés permanents et les employés contractuels.

**1. Classe de base Employe :**

Elle contient les attributs communs :
- `nom` : nom de l'employé.
- `id` : identifiant de l'employé.
- `salaireDeBase` : salaire de base.

Elle possède également :
- Un constructeur prenant tous les attributs.
- Une méthode virtuelle `afficherInfos()`.
- Un destructeur virtuel pour garantir une destruction correcte des objets dérivés.

**2. Classe dérivée Permanent :**

Elle hérite de `Employe` et ajoute :
- `primeAnnuelle` : prime annuelle de l'employé.

Elle redéfinit `afficherInfos()` pour afficher les informations générales ainsi que la prime annuelle.

**3. Classe dérivée Contractuel :**

Elle hérite également de `Employe` et ajoute :
- `dureeContrat` : durée du contrat en mois.
- `tauxHoraire` : rémunération par heure travaillée.

Elle contient une méthode `calculerSalaireMensuel(int heures)` permettant de calculer le salaire mensuel en fonction du nombre d'heures travaillées.

### Fonctionnalités réalisées

- Création d'une classe de base `Employe`.
- Création des classes dérivées `Permanent` et `Contractuel`.
- Utilisation de l'héritage public.
- Déclaration et redéfinition de méthodes virtuelles.
- Création d'un tableau dynamique de pointeurs vers `Employe`.
- Instanciation de plusieurs employés de types différents.
- Appel de `afficherInfos()` à travers les pointeurs de la classe de base.
- Utilisation du polymorphisme pour exécuter la bonne version de la méthode selon le type réel de l'objet.
- Libération de la mémoire avec `delete`.
- Utilisation d'un destructeur virtuel pour assurer la destruction correcte des objets dérivés.

### Résultat attendu

Le programme crée au minimum trois employés de types différents, les stocke dans un tableau dynamique de pointeurs vers `Employe`, puis affiche leurs informations grâce au polymorphisme.

Il calcule également le salaire mensuel des employés contractuels et libère correctement la mémoire à la fin du programme.

### Notions utilisées

- Héritage public.
- Polymorphisme.
- Fonctions virtuelles (`virtual`).
- Redéfinition des méthodes.
- Pointeurs vers la classe de base.
- Allocation dynamique avec `new`.
- Libération de mémoire avec `delete`.
- Destructeur virtuel.

---

## Technologies et outils utilisés

- **Langage de programmation :** C++
- **Environnement de développement :** Eclipse IDE
- **Paradigme :** Programmation orientée objet (POO)
- **Concepts principaux :** Héritage, polymorphisme, constructeurs, destructeurs et méthodes virtuelles.

## Conclusion générale

Ce TP nous a permis de mettre en pratique les principaux concepts de l'héritage et du polymorphisme en C++.

À travers les quatre exercices, nous avons appris à créer des classes de base et des classes dérivées, à réutiliser les attributs et les méthodes, à redéfinir les fonctions et à utiliser les méthodes virtuelles.

Nous avons également découvert comment gérer plusieurs types d'objets à travers des pointeurs vers une classe de base et comment assurer une libération correcte de la mémoire grâce aux destructeurs virtuels.

**Les quatre exercices constituent une application pratique des principes fondamentaux de la programmation orientée objet en C++.**
<img width="960" height="540" alt="image" src="https://github.com/user-attachments/assets/ec294d14-8270-4a25-8fb1-0146c517b77f" />
