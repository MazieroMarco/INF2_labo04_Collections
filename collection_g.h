/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collection_g.h
 Auteur(s)   : Dias Morais Filipe, Maziero Marco, Sciarra Daniel
 Date        : 21.04.2020
 But         : Définition de la classe Collection permettant le stockage d'objets
               de type quelconque dans un conteneur de type quelconque.

 Remarque(s) : La classe Collection contient des fonctions membres permmetant:
                    - L'ajout d'un objet dans le conteneur de la collection.
                    - Récupérer le nombre d'objets contenus dans le conteneur.
                    - Récupérer un objet du conteneur par son index.
                    - Chercher si le conteneur contient un objet spécifique.
                    - Vider totalement le conteneur.
                    - Parcourir le conteneur pour y executer une fonction passée
                      en paramètre qui va modifier les objets du conteneur en
                      leur appliquant un coefficient réel.
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef COLLECTION_G_H
#define COLLECTION_G_H

#include <iostream>

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

    template <typename UnaryOperation>
    void parcourir(UnaryOperation operation, double coefficient);
private:
    Conteneur<T> data;
};

#include "collectionImpl_g.h"
#endif // COLLECTION_G_H
