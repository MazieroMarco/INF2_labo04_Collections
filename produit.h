/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.h
 Auteur(s)   : Dias Morais Filipe, Maziero Marco, Sciarra Daniel
 Date        : 21.04.2020
 But         : Fichier en-tête de la classe Produit.
 Remarque(s) : La classe ne propose pas de constructeur par défaut.
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>
#include "exceptions.h"

class Produit {
    friend Produit majorationPourcentagePrix(Produit& p, double pourcentage);
    friend std::ostream& operator<<(std::ostream& os, const Produit& p);
    friend bool operator==(const Produit& p1, const Produit& p2);
public:
    Produit(size_t no, const char* label, double prix);
    void setPrix(double prix);
private:
    size_t no;
    const char* label;
    double prix; // Prix en francs
    static const double PRIX_MIN; // Prix en francs, minimum autorisé pour un objet Produit
};

Produit majorationPourcentagePrix(Produit& p, double pourcentage);

#endif //PRODUIT_H