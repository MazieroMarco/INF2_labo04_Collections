//
// Created by Daniel on 20.04.2020.
//

#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>
#include <string>
#include "exceptions.h"

// séparer déclarations et définitions
class Produit{
    friend std::ostream& operator<<(std::ostream& os, const Produit& p){
        return os << "(" << p.no << ", \"" << p.label << "\", " << p.prix << ")";
    }
public:
    Produit(size_t no, const char* label, double prix) {
        if (prix < PRIX_MIN){
            throw PrixNonValide("Erreur dans Produit::Produit :\n"  // + string(__func__) +
                                "le prix doit etre >= " + std::to_string(static_cast<int>(PRIX_MIN*100)) + " cts !"); // à voir si créer prix min en cts déjà
        }
        this->no = no;
        this->label = label;
        this->prix = prix;
    }
    void setPrix(double prix) {
        if (prix < PRIX_MIN){
            throw PrixNonValide("Erreur dans Produit::setPrix :\n"
                                "le prix doit etre >= " + std::to_string(static_cast<int>(PRIX_MIN*100)) + " cts !");
        }
        this->prix = prix;}
private:
    size_t no;
    const char* label;
    double prix;
    static const double PRIX_MIN;
};

const double Produit::PRIX_MIN = 0.05;

#endif //PRODUIT_H
