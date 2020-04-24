/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.cpp
 Auteur(s)   : Dias Morais Filipe, Maziero Marco, Sciarra Daniel
 Date        : 21.04.2020
 But         : Fichier implémentation de la classe Produit.
 Remarque(s) : 
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "produit.h"
#include <iomanip>

const double Produit::PRIX_MIN = 0.05;

Produit::Produit(size_t no, const char *label, double prix)
{
   if (prix < PRIX_MIN)
   {
      throw PrixNonValide("Erreur dans Produit::Produit :\n"
                          "le prix doit etre >= " +
                          std::to_string(static_cast<int>(PRIX_MIN * 100)) + " cts !");
   }
   this->no = no;
   this->label = label;
   this->prix = prix;
}

void Produit::setPrix(double prix)
{
   if (prix < PRIX_MIN)
   {
      throw PrixNonValide("Erreur dans Produit::setPrix :\n"
                          "le prix doit etre >= " +
                          std::to_string(static_cast<int>(PRIX_MIN * 100)) + " cts !");
   }
   this->prix = prix;
}

double Produit::getPrix() const { return prix; }

std::ostream &operator<<(std::ostream &os, const Produit &p)
{
   return os << "(" << p.no << ", \"" << p.label << "\", " << std::setprecision(2) << std::fixed << p.prix << ")";
}

bool operator==(const Produit& p1, const Produit& p2) {
    return (p1.no == p2.no &&
            p1.label == p2.label &&
            p1.prix == p2.prix);
}

void Produit::majorationPourcentagePrix(double pourcentage, Produit& p)
{
   if (pourcentage > 0.0)
   {
       p.setPrix(p.getPrix() * (1 + pourcentage / 100));
   }
}