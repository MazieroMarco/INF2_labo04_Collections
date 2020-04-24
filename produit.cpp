/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.cpp
 Auteur(s)   : Dias Morais Filipe, Maziero Marco, Sciarra Daniel
 Date        : 21.04.2020
 But         : Implémentation de la classe Produit.
 Remarque(s) : /
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "produit.h"
#include <string>
#include <iomanip>

const double Produit::PRIX_MIN = 0.05;
const unsigned Produit::NB_CENTIMES_DANS_FRANC = 100;

Produit::Produit(size_t no, const char *label, double prix) {
   if (prix < PRIX_MIN) {
      throw Prix_Non_Valide("Erreur dans Produit::Produit :\n"
                            "le prix doit etre >= " +
                            std::to_string(static_cast<unsigned> (PRIX_MIN * NB_CENTIMES_DANS_FRANC))
                            + " cts !");
   }
   this->no = no;
   this->label = label;
   this->prix = prix;
}

void Produit::setPrix(double prix) {
   if (prix < PRIX_MIN) {
      throw Prix_Non_Valide("Erreur dans Produit::setPrix :\n"
                            "le prix doit etre >= " +
                            std::to_string(static_cast<unsigned> (PRIX_MIN * NB_CENTIMES_DANS_FRANC))
                            + " cts !");
   }
   this->prix = prix;
}

std::ostream &operator<<(std::ostream &os, const Produit &p) {
   const unsigned LARGEUR = 2;
   return os << "(" << p.no << ", \"" << p.label << "\", "
           << std::setprecision(LARGEUR) << std::fixed << p.prix << ")";
}

bool operator==(const Produit &p1, const Produit &p2) {
   return (p1.no == p2.no &&
           p1.label == p2.label &&
           p1.prix == p2.prix);
}

void majorationPrixEnPourcent(Produit &p, double pourcentage) {
   if (pourcentage > 0.) {
      p.setPrix((p.prix * (1 + pourcentage / 100.)));
   }
}