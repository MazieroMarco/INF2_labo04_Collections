/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.h
 Auteur(s)   : Dias Morais Filipe, Maziero Marco, Sciarra Daniel
 Date        : 21.04.2020
 But         : Fichier en-tête de la classe Produit.
 Remarque(s) : 
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>
#include <string>
#include "exceptions.h"

class Produit{
    friend std::ostream& operator<<(std::ostream& os, const Produit& p);
    friend bool operator==(const Produit& p1, const Produit& p2);
public:
    Produit(size_t no, const char* label, double prix);
    void setPrix(double prix);
    void majorationPourcentagePrix(const double &pourcentage);
private:
    size_t no;
    const char* label;
    double prix;
    static const double PRIX_MIN;
};

#endif //PRODUIT_H
