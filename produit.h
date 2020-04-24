/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.h
 Auteur(s)   : Dias Morais Filipe, Maziero Marco, Sciarra Daniel
 Date        : 21.04.2020
 But         : Mettre à disposition une classe Produit, permettant de créer des objets
               se caractérisant par un no, un libellé et un prix. Cette classe met à
               disposition :
               - Un constructeur de produit.
               - Une méthode permettant de modifier le prix d'un produit
               - Une surcharge de l'opérateur de flux pour afficher les caractéristiques
               d'un produit et une surcharge de l'opérateur d'égalité afin de comparer
               deux produits.
               Une fonction amie permettant de majorer le prix d'un produit selon un
               certain pourcentage passé en paramètre est également fournie par cette classe.

 Remarque(s) : La classe ne propose pas de constructeur par défaut.
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>
#include "exceptions.h"

class Produit {
   friend void majorationPrixEnPourcent(Produit& p, double pourcentage);
   friend std::ostream& operator<<(std::ostream& os, const Produit& p);
   friend bool operator==(const Produit& p1, const Produit& p2);
public:
   Produit(size_t no, const char* label, double prix);
   void setPrix(double prix);
private:
   size_t no;
   const char* label;
   double prix; // Prix en francs
   static const double PRIX_MIN; // Prix en francs, minimum autorisé pour un Produit
   static const unsigned NB_CENTIMES_DANS_FRANC;
};

void majorationPrixEnPourcent(Produit& p, double pourcentage);

#endif // PRODUIT_H