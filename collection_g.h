/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collection_g.h
 Auteur(s)   : Dias Morais Filipe, Maziero Marco, Sciarra Daniel
 Date        : 21.04.2020
 But         : Mettre à disposition une classe Collection permettant le stockage d'objets
               de type quelconque dans un conteneur de type quelconque. Cette classe
               met à disposition les fonctionnalités suivantes :
               - Ajout d'un objet dans le conteneur de la collection.
               - Récupérer le nombre d'objets contenus dans le conteneur.
               - Récupérer un objet du conteneur par son index.
               - Rechercher si le conteneur contient un objet spécifique.
               - Vider totalement le conteneur.
               - Parcourir le conteneur et appliquer sur chaque élément de celui-ci,
                 une fonction générique passée en paramètre qui va modifier ces éléments
                 en leur appliquant un coefficient réel.

 Remarque(s) : /
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef COLLECTION_G_H
#define COLLECTION_G_H

#include <iostream>

template <typename T, template <typename, typename = std::allocator<T>> class Conteneur> 
class Collection;

template <typename T, template <typename, typename = std::allocator<T>> class Conteneur>
std::ostream& operator<<(std::ostream& os, const Collection<T, Conteneur>& rhs);

template <typename T, template <typename, typename = std::allocator<T>> class Conteneur>
class Collection {
   friend std::ostream& operator<< <>(std::ostream& os, const Collection& rhs);
public:
   void ajouter(const T& objet);
   size_t taille() const noexcept;
   T& get(size_t id);
   bool contient(const T& objet) const;
   void vider() noexcept;

   template <typename UnaryOperation>
   void parcourir(UnaryOperation operation, double coefficient);
private:
   Conteneur<T> data;
};

#include "collectionImpl_g.h"
#endif // COLLECTION_G_H