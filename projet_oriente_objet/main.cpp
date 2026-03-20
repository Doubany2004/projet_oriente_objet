#include <iostream>
#include <vector>
#include <limits>
#include "Employe.h"

using namespace std;

// ---------------------------------------------------------
// Fonction LireSaisie
// Permet de lire une saisie utilisateur proprement
// en gérant les erreurs de type (cin.fail())
// ---------------------------------------------------------
string LireSaisie(const string& invite)
{
    string saisie;
    cout << invite;
    cin >> saisie;

    // Gestion des erreurs de saisie: si l'utilisateur entre un type incorrect
    if (cin.fail())
    {
        cin.clear(); // Réinitialise l'état de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Vide le buffer
    }

    return saisie;
}

// ---------------------------------------------------------
// Fonction Login
// Vérifie si le code entré correspond à un employé existant
// Retourne le nom de l'employé si trouvé
// ---------------------------------------------------------
string Login(const string employes[][2], int nombreEmployes)
{
    while (true)
    {
        string code = LireSaisie("Veuillez vous identifier: ");

        // On parcourt la liste des employés
        for (int i = 0; i < nombreEmployes; i++)
        {
            if (code == employes[i][0])
            {
                cout << endl << "Bonjour, " << employes[i][1] << endl;
                return employes[i][1];
            }
        }

        // Si aucun employé trouvé
        cout << "ERREUR: Numero d'employe invalide." << endl;
    }
}

int main()
{
    // -----------------------------------------
    // Création de la liste des employés (vector)
    // -----------------------------------------
    vector<Employe> employes =
    {
        Employe("001", "Andrew"),
        Employe("002", "Nabil"),
        Employe("003", "Marc"),
        Employe("004", "Jean-Gabriel"),
        Employe("005", "Caroline")
    };

    // Tableau utilisé pour la fonction Login du prof
    const string employesLogin[][2] =
    {
        {"001", "Andrew"},
        {"002", "Nabil"},
        {"003", "Marc"},
        {"004", "Jean-Gabriel"},
        {"005", "Caroline"}
    };

    int nombreEmployes = 5;

    // -----------------------------------------
    // AUTHENTIFICATION (avec la fonction du prof)
    // -----------------------------------------
    string nomEmploye = Login(employesLogin, nombreEmployes);

    int choix;

    // -----------------------------------------
    // MENU PRINCIPAL
    // -----------------------------------------
    do
    {
        cout << endl;
        cout << "********************" << endl;
        cout << "     MENU PRINCIPAL " << endl;
        cout << "********************" << endl;

        cout << "1. Ajouter un article" << endl;
        cout << "2. Supprimer un article" << endl;
        cout << "3. Afficher le panier" << endl;
        cout << "0. Payer" << endl;

        // Utilisation de LireSaisie pour éviter les erreurs de saisie
        choix = stoi(LireSaisie("Votre choix: "));

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