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

Produit::Produit(size_t no, const char *label, double prix)
{
   if (prix < PRIX_MIN)
   {
      throw PrixNonValide("Erreur dans Produit::Produit :\n" // + string(__func__) +
                          "le prix doit etre >= " +
                          std::to_string(static_cast<int>(PRIX_MIN * 100)) + " cts !"); // à voir si créer prix min en cts déjà
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

std::ostream &operator<<(std::ostream &os, const Produit &p)
{
   return os << "(" << p.no << ", \"" << p.label << "\", " << p.prix << ")";
}

void Produit::majorationPourcentagePrix(const double &pourcentage)
{
   if (pourcentage > 0.0)
   {
      prix += prix / 100.0 * pourcentage;
   }
};