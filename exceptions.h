/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : exceptions.h
 Auteur(s)   : Dias Morais Filipe, Maziero Marco, Sciarra Daniel
 Date        : 21.04.2020
 But         : Implémentation des classes d'exceptions pour les classes Collection et
               Produit. La classe Indice_Non_Valide et Prix_Non_Valide définissent le
               type d'objets lancés comme exceptions pour indiquer respectivement, un
               indice ou un prix non valide, pour les arguments utilisés par les
               différentes fonctionnalités des classes Collection et Produit.

 Remarque(s) : Bien que les 2 versions des constructeurs ne soient pas forcément
               utilisés ici, nous avons préféré les implémenter pour être cohérent
               avec le standard C++11 et pour une question d'évolutivité du code.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class Indice_Non_Valide: public std::logic_error {
public:
    explicit Indice_Non_Valide(const std::string& what_arg) : logic_error(what_arg) {}
    explicit Indice_Non_Valide(const char* what_arg) : logic_error(what_arg) {}
};

class Prix_Non_Valide : public std::logic_error {
public:
    explicit Prix_Non_Valide(const std::string& what_arg) : logic_error(what_arg) {}
    explicit Prix_Non_Valide(const char* what_arg) : logic_error(what_arg) {}
};

#endif // EXCEPTIONS_H