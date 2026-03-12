#include "Employe.h"

// Constructeur
// this sert à différencier l'attribut de la classe et le paramètre
Employe::Employe(string numero, string nom)
{
    this->numero = numero;
    this->nom = nom;
}

// Getter pour le numéro
string Employe::getNumero() const
{
    return numero;
}

// Getter pour le nom
string Employe::getNom() const
{
    return nom;
}

// Surcharge de l'opérateur ==
// Permet de comparer directement un employé avec un code
bool Employe::operator==(string code) const
{
    return numero == code;
}