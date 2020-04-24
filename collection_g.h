/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collection_g.h
 Auteur(s)   : Dias Morais Filipe, Maziero Marco, Sciarra Daniel
 Date        : 21.04.2020
 But         : Contient les définitions de la  de la class générique Collection.
 Remarque(s) : 
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef COLLECTION_G_H
#define COLLECTION_G_H

#include <algorithm>
#include <iostream>
#include "exceptions.h"

template <typename T, template <typename, typename = std::allocator<T>> class Conteneur> class Collection;

template <typename T, template <typename, typename = std::allocator<T>> class Conteneur>
std::ostream& operator<<(std::ostream& os, const Collection<T, Conteneur>& rhs);

template <typename T, template <typename, typename = std::allocator<T>> class Conteneur>
class Collection {
    friend std::ostream& operator<< <>(std::ostream& os, const Collection& rhs);
public:
    void ajouter(const T& objet);
    size_t taille() const;
    T& get(size_t id);
    bool contient(const T& objet) const;
    void vider();

    template <typename Operation>
    void parcourir(Operation operation);
private:
    Conteneur<T> data;
};

#include "collection_g_impl.h"
#endif // COLLECTION_G_H
