#pragma once
#include<string>
#include<iostream>
#include<vector>
#include "Article.h"

class Panier
{
private:
	std::vector<Article> items{};

public:
	// declaration de la fonction ajouter dans panier
	void ajoutPanier(const Article& article);

	// declaration de la fonction surcharge pour affichage des produit
	friend std::ostream& operator<<(std::ostream& os,const Panier& p);

	// declaration de la fonction pour comparer la quantite d'article dans le panier
	bool panierVide()const;

};

