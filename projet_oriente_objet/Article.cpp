#include "Article.h"
#include<iostream>
#include<string>
#include <iomanip>

using namespace std;

// fonction de conducteur

Article::Article(std::string code, std::string nom, double prix) {
	this->code = code;
	this->nom = nom;
	this->prix = prix;
}

// fonction affichage
std::ostream& operator<<(std::ostream& os, const Article& articleAutre) {
	os << left << setw(25) << (articleAutre.code + ": " + articleAutre.nom)
		<< right << setw(8) << articleAutre.prix<<"$";
	return os;
}
// fonction de comparaison
bool Article::operator==(const string& saisiCode) const{
	return code == saisiCode;
}