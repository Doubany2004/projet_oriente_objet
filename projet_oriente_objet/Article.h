#pragma once
#include<string>
#include<iostream>
class Article
{
private:
	std::string code;
	std::string nom;
	double prix;

	
public:
	// declaration du constructeur
	Article(std::string code, std::string nom, double prix);
	
	// declaration de la fonction de surcharge pour l'affichage 
	friend std::ostream& operator<<(std::ostream& os, const Article& articleAutre);

	// declaration de la fonction de surcharge pour la comparaison
	 bool operator==(const std::string& saisiCode) const;

	 double getPrix()const;
};

