#include <iostream>
#include <vector>
#include "Employe.h"

using namespace std;

int main()
{

    // -------------------------------------------------
    // Création de la liste des employés autorisés
    // On utilise un vector qui contient des objets
    // de type Employe.
    // -------------------------------------------------

    vector<Employe> employes =
    {
        Employe("001", "Andrew"),
        Employe("002", "Nabil"),
        Employe("003", "Marc"),
        Employe("004", "Jean-Gabriel"),
        Employe("005", "Caroline")
    };


    // Variable qui va stocker le numéro entré
    string numero;

    // Pointeur vers l'employé connecté
    // nullptr signifie qu'aucun employé n'est connecté
    Employe* employeConnecte = nullptr;


    // -------------------------------------------------
    // AUTHENTIFICATION
    // -------------------------------------------------
    // On répète tant que l'utilisateur n'entre pas
    // un numéro valide.
    // -------------------------------------------------

    while (employeConnecte == nullptr)
    {

        cout << "Veuillez vous identifier: ";
        cin >> numero;


        // Recherche dans la liste des employés
        for (int i = 0; i < employes.size(); i++)
        {

            // On utilise l'opérateur == que nous avons créé
            if (employes[i] == numero)
            {
                // Si l'employé est trouvé,
                // on sauvegarde son adresse
                employeConnecte = &employes[i];

                break;
            }
        }

        // Si aucun employé n'est trouvé
        if (employeConnecte == nullptr)
        {
            cout << "ERREUR: Numero d'employe invalide" << endl;
        }
    }


    // Message de bienvenue
    cout << "Bonjour, " << employeConnecte->getNom() << endl;


    int choix;

    // -------------------------------------------------
    // MENU PRINCIPAL
    // -------------------------------------------------
    // Cette boucle affiche le menu jusqu'à ce que
    // l'utilisateur choisisse l'option 0 (payer).
    // -------------------------------------------------

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


        // Gestion du choix avec switch
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