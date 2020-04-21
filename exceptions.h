/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : exceptions.h
 Auteur(s)   : Dias Morais Filipe, Maziero Marco, Sciarra Daniel
 Date        : 21.04.2020
 But         : Fichier de l'implémentation des excpetions pour les classes Produit et
               Collection.
 Remarque(s) : 
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class IndiceNonValide: public std::logic_error {
public:
    explicit IndiceNonValide(const std::string& s) : logic_error(s) {}
    explicit IndiceNonValide(const char* s) : logic_error(s) {}
};

class PrixNonValide : public std::logic_error {
public:
    explicit PrixNonValide(const std::string& s) : logic_error(s) {}
    explicit PrixNonValide(const char* s) : logic_error(s) {}
};

#endif //EXCEPTIONS_H
