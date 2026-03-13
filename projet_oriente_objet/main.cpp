#include <iostream>
#include <vector>
#include "Employe.h"

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