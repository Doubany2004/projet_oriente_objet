#include "Panier.h"
#include<string>
#include<iostream>
#include<vector>

using namespace std;
// declaration de la fonction ajout panier
void Panier::ajoutPanier(const Article& article) {
	items.push_back(article);
	
}
 // fonction d'affichage du panier
std::ostream& operator<<(std::ostream& os, const Panier& p) {
	
	 for(const auto& article: p.items)
	{
		 os<< article << endl;
	}
	 return os;
}
// fonction si le panier est vide
bool Panier::panierVide()const {
	return items.empty();
}

std::vector<Article>::iterator Panier::panierBegin() {
	return items.begin();
}

std::vector<Article>::iterator Panier::panierEnd() {
	return items.end();
}
// declaration de la fonction pour retirerPanier

void Panier::retirerPanier(std::vector<Article>::iterator article) {
	items.erase(article);
}