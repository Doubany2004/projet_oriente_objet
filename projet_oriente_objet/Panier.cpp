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

