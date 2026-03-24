#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Employe.h"
#include "Article.h"
#include "Panier.h"

using namespace std;

// Fonction LireSaisie
string LireSaisie(const string& invite) {
    string saisie;
    cout << invite;
    cin >> saisie;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return saisie;
}

// Fonction Login
string Login(const string employes[][2], int nombreEmployes) {
    while (true) {
        string code = LireSaisie("Veuillez vous identifier: ");

        for (int i = 0; i < nombreEmployes; i++) {
            if (code == employes[i][0]) {
                cout << endl << "Bonjour, " << employes[i][1] << endl;
                return employes[i][1];
            }
        }

        cout << "ERREUR: Numero d'employe invalide." << endl;
    }
}
// declaration du menu principale
void menuPrincipal() {


}
int main() {

    srand(time(0));
    time_t tempsBrut = time(0);
    tm* date = localtime(&tempsBrut);
    int randomNom = rand() % 2;
    double sousTotal = 0.00;
    double total = 0.00;
    // creation des objet
    Panier panierObjet;
   

    // Déclaration des produits
    Article produit1("A1", "Crayon", 3.99);
    Article produit2("A2", "Cahier Canadda", 1.59);
    Article produit3("B1", "Table Pliante", 66.99);
    Article produit4("B2", "Fauteuil en Cuir", 199.99);
    Article produit5("B3", "Bureau d'etudiant", 118.99);
    Article produit6("L1", "Laptop ASUS", 600.89);
    Article produit7("L2", "Laptop Hp", 700.89);
    Article produit8("L3", "Laptop Acer", 250.99);

  // creation d'un vector de produit
    vector<Article>produits{
        produit1,produit2,produit3,produit4,produit5,produit6,produit7,produit8};

     
    
    // declaration des codes
    // Tableau utilisé pour Login
    const string employesLogin[][2] = {
        {"001", "Andrew"},
        {"002", "Nabil"},
        {"003", "Marc"},
        {"004", "Jean-Gabriel"},
        {"005", "Caroline"}
    };

    int nombreEmployes = 5;

    // -----------------------------------------
    // AUTHENTIFICATION
    // -----------------------------------------
    string nomEmploye = Login(employesLogin, nombreEmployes);

    int choix;

    // -----------------------------------------
    // MENU PRINCIPAL
    // -----------------------------------------
    do {
        cout << endl;
        cout << "********************" << endl;
        cout << "     MENU PRINCIPAL " << endl;
        cout << "********************" << endl;

        cout << "1. Ajouter un article" << endl;
        cout << "2. Supprimer un article" << endl;
        cout << "3. Afficher le panier" << endl;
        cout << "0. Payer" << endl;

        choix = stoi(LireSaisie("Votre choix: "));

        switch (choix) {
        case 1: {
            bool ajoutArticle = false;
            // afficher les produits
            cout << endl;
            cout << "********************" << endl;
            cout << "   AJOUT ARTICLE    " << endl;
            cout << "********************" << endl << endl;
            for (const Article& produitReference : produits) {
                cout << produitReference << endl;
            }

            //les repetition quand il y'a les eureur
            while (!ajoutArticle) {
                // appel de la fonction saisie code
                string saisiCode = LireSaisie("votre choix...");
                for (const Article& produitReference : produits) {
                    if (produitReference ==saisiCode) {
                        panierObjet.ajoutPanier(produitReference);
                        ajoutArticle = true;
                        break;
                    }

                }
                if (ajoutArticle == true)
                {
                    cout << "Article ajouter dans le panier" << endl;

                }
                else
                {
                    cout << "code invalide ";

                }
            }

            break;
        }
        case 2:
            bool retirerFlag = false;
            //afficher le panier
            cout << endl;
            cout << "*********************" << endl;
            cout << "   RETIRER ARTICLE   " << endl;
            cout << "*********************" << endl << endl;
            if (panierObjet.panierVide()) {
                cout << "votre Panier est vide" << endl;
            }
            else {
                cout << panierObjet << endl;
                while (!retirerFlag) {
                    string saisiCode = LireSaisie("votre choix...");
                    for (auto it = panierObjet.panierBegin(); it != panierObjet.panierEnd(); ++it) {
                        if (*it == saisiCode) {
                            panierObjet.retirerPanier(it);
                            retirerFlag = true;
                            break;
                        }
                    }
                }
                if (!retirerFlag) {
                    cout << "choix incorect, veuillez ressayer" << endl;
                }
                else {
                    cout << "Article supprimer" << endl;
                }
            }
            break;

        case 3:
            cout << endl;
            cout << "*********************" << endl;
            cout << "   AFFICHER PANIER   " << endl;
            cout<< "*********************" << endl << endl;
            if (panierObjet.panierVide())
                cout << "votre Panier est vide" << endl;
            else
            {
                cout << panierObjet;
            }
            break;

        case 0:
           
            cout << endl;
            cout << "*********************" << endl;
            cout << "**     FACTURE     **" << endl;
            cout << "*********************" << endl << endl;
            if (panierObjet.panierVide()) {
                cout << "votre Panier est vide" << endl;
                break;
            }
            else {
                for (auto it = panierObjet.panierBegin(); it != panierObjet.panierEnd(); ++it) {
                    sousTotal = it->getPrix() + sousTotal;
                    cout << *it << endl;
                }
                if (randomNom == 0) {
                    double rabais = sousTotal * 0.25;
                    cout << "rabais mystere: " << rabais << "$" << endl;
                    total = sousTotal - rabais;
                }
                cout << "---------------------------" << endl;
                cout << "sous-total :  " << sousTotal << endl;
                cout << "TPS:  " << (total * 1.05) << endl;
                cout << "TVQ" << (total * 1.09975) << endl;
                total = total * 1.05 * 1.09975;
                cout << "TOTAL: " << total << endl;
                cout << "******************************" << endl;
                cout << "vous avez ete servi par:" << nomEmploye << endl;
                cout << "Date: " << (1900 + date->tm_year) << "-"
                    << right << setw(2) << setfill('0') << (1 + date->tm_mon) << "-"
                    << setw(2) << setfill('0') << date->tm_mday << endl;
                cout << "Heure: " << date->tm_hour << ":"
                    << setw(2) << setfill('0') << date->tm_min << ":"
                    << setw(2) << setfill('0') << date->tm_sec << endl;
                cout << "***************************" << endl;

            }
            break;

        default:
            cout << "Choix invalide..." << endl;
        }

    } while (choix != 0);

    return 0;
}
