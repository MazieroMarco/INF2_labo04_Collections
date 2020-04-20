//
// Created by Marco on 20.04.2020.
//

#ifndef COLLECTION_G_H
#define COLLECTION_G_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "exceptions.h"

template <typename T, template <typename...> class Conteneur> class Collection;

template <typename T, template <typename...> class Conteneur>
std::ostream& operator<<(std::ostream& os, const Collection<T, Conteneur>& rhs) {
    os << "[";
    for (size_t i = 0; i < rhs.data.size(); ++i) {
        if (i) {os << ", ";}
        os << rhs.data.at(i);
    }
    os << "]";
    return os;
}

template <typename T, template <typename...> class Conteneur>
class Collection {
    friend std::ostream& operator<< <>(std::ostream& os, const Collection& rhs);
public:
    void ajouter(const T& objet);
    size_t taille() const;
    T& get(size_t id) const;
    bool contient(const T& objet) const;
    void vider();
private:
    Conteneur<T> data;
};

template <typename T, template <typename...> class Conteneur>
void Collection<T, Conteneur>::ajouter(const T& objet) {
    data.push_back(objet);
}

template <typename T, template <typename...> class Conteneur>
size_t Collection<T, Conteneur>::taille() const {
    return data.size();
}

template <typename T, template <typename...> class Conteneur>
T& Collection<T, Conteneur>::get(size_t id) const {
    if (id < 0 || id >= data.size()) {throw IndiceNonValide("IndiceNonValide");}
    return data.at(id);
}

template <typename T, template <typename...> class Conteneur>
bool Collection<T, Conteneur>::contient(const T& objet) const {
    return std::find(data.begin(), data.end(), objet) != data.end;
}

template <typename T, template <typename...> class Conteneur>
void Collection<T, Conteneur>::vider() {
    data.clear();
}

#endif // COLLECTION_G_H
