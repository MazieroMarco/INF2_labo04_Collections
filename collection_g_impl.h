/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collection_g_impl.h
 Auteur(s)   : Dias Morais Filipe, Maziero Marco, Sciarra Daniel
 Date        : 21.04.2020
 But         : Fichier d'implémentation de la classe générique Collection.
 Remarque(s) : La fonction parcourir permet d'executer une fonction passée en paramètre
               sur tous les éléments de la collection en y appliquant un coefficient.
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef COLLECTION_G_IMPL_H
#define COLLECTION_G_IMPL_H

#include <iterator>
#include "exceptions.h"

template <typename T, template <typename, typename = std::allocator<T>> class Conteneur>
std::ostream& operator<<(std::ostream& os, const Collection<T, Conteneur>& rhs) {
    os << "[";
    for (auto it = rhs.data.begin(); it != rhs.data.end(); ++it) {
        if (it != rhs.data.begin()) {os << ", ";}
        os << *it;
    }
    os << "]";
    return os;
}

template <typename T, template <typename, typename = std::allocator<T>> class Conteneur>
void Collection<T, Conteneur>::ajouter(const T& objet) {
    data.push_back(objet);
}

template <typename T, template <typename, typename = std::allocator<T>> class Conteneur>
size_t Collection<T, Conteneur>::taille() const {
    return data.size();
}

template <typename T, template <typename, typename = std::allocator<T>> class Conteneur>
T& Collection<T, Conteneur>::get(size_t id) {
    if (id < 0 || id >= data.size()) {
        throw IndiceNonValide("Erreur dans Collection::get :\n"
                              "n doit etre strictement plus petit que collection.size()");
    }
    return *(std::next(data.begin(), (int)id));
}

template <typename T, template <typename, typename = std::allocator<T>> class Conteneur>
bool Collection<T, Conteneur>::contient(const T& objet) const {
    return std::find(data.begin(), data.end(), objet) != data.end();
}

template <typename T, template <typename, typename = std::allocator<T>> class Conteneur>
void Collection<T, Conteneur>::vider() {
    data.clear();
}

template <typename T, template <typename, typename = std::allocator<T>> class Conteneur>
template<typename UnaryOperation>
void Collection<T, Conteneur>::parcourir(UnaryOperation operation, double coefficient) {
    for (T& i : this->data) {
        operation(i, coefficient);
    }
}

#endif //PROJET_COLLECTION_G_IMPL_H
