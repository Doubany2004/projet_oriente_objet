#include <iostream>
#include <vector>
#include "Employe.h"
#include "Article.h"

using namespace std;

int main()
{
    // -----------------------------------------
    // Création de la liste des employés
    // -----------------------------------------
    vector<Employe> employes =
    {
        Employe("001", "Andrew"),
        Employe("002", "Nabil"),
        Employe("003", "Marc"),
        Employe("004", "Jean-Gabriel"),
        Employe("005", "Caroline")
    };

    // declaration de la liste des produit 
    Article produit1("A1", "Crayon", 3.99);
    Article produit2("A2", "Cahier Canadda", 1.59);
    Article produit3("B1", "Table Pliante", 66.99);
    Article produit4("B2", "Fauteuil en Cuir", 199.99);
    Article produit5("B3", "Bureau d'etudiant", 118.99);
    Article produit6("L1", "Laptop ASUS", 600.89);
    Article produit7("L2", "Laptop Hp", 700.89);
    Article produit8("L3", "Laptop Acer", 250.99);


    string numero;

    // index de l'employé trouvé
    // -1 signifie qu'on n'a trouvé personne
    int indexEmploye = -1;

    // -----------------------------------------
    // AUTHENTIFICATION
    // -----------------------------------------
    // On continue tant qu'on ne trouve pas
    // un numéro valide
    // -----------------------------------------

    while (indexEmploye == -1)
    {
        cout << "Veuillez vous identifier: ";
        cin >> numero;

        // On parcourt la liste des employés
        for (int i = 0; i < employes.size(); i++)
        {
            // Utilisation de l'opérateur ==
            if (employes[i] == numero)
            {
                indexEmploye = i;
                break;
            }
        }

        // Si aucun employé trouvé
        if (indexEmploye == -1)
        {
            cout << "ERREUR: Numero d'employe invalide" << endl;
        }
    }

    // Message de bienvenue
    cout << "Bonjour, " << employes[indexEmploye].getNom() << endl;

    int choix;

    // -----------------------------------------
    // MENU PRINCIPAL
    // -----------------------------------------

    do
    {
        cout << endl;
        cout << "********************" << endl;
        cout << " MENU PRINCIPAL " << endl;
        cout << "********************" << endl;

        cout << "1. Ajouter un article" << endl;
        cout << "2. Supprimer un article" << endl;
        cout << "3. Afficher le panier" << endl;
        cout << "0. Payer" << endl;

        cout << "Votre choix: ";
        cin >> choix;

        switch (choix)
        {
        case 1:
            cout << "AJOUT ARTICLE" << endl;
            cout << produit1 << endl;
            cout << produit2 << endl;
            cout << produit3 << endl;
            cout << produit4 << endl;
            cout << produit5 << endl;
            cout << produit6 << endl;
            cout << produit7 << endl;
            cout << produit8<< endl;
            break;

        case 2:
            cout << "RETIRER ARTICLE" << endl;
            break;

        case 3:
            cout << "AFFICHER PANIER" << endl;
            break;

        case 0:
            cout << "Paiement..." << endl;
            break;

        default:
            cout << "Choix invalide..." << endl;
        }

    } while (choix != 0);

    return 0;
}