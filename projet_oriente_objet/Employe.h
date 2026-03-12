#pragma once
#include <string>

using namespace std;

// Classe qui représente un employé du magasin
class Employe
{
private:
    // Attributs privés (encapsulation)
    string numero;
    string nom;

public:

    // Constructeur paramétré
    // Sert à créer un employé avec un numéro et un nom
    Employe(string numero, string nom);

    // Accesseur (getter) pour obtenir le numéro
    // const signifie que la fonction ne modifie pas l'objet
    string getNumero() const;

    // Accesseur (getter) pour obtenir le nom
    string getNom() const;

    // Surcharge de l'opérateur ==
    // Permet de comparer un objet Employe avec un code string
    bool operator==(string code) const;
};