//
// Created by Jazmin Belmonte on 9/21/18.
//
#include "safe_collection.h"

#ifndef SORTED_COLLECTION_H
#define SORTED_COLLECTION_H

template <typename Item>
class SortedCollection : public SafeCollection<Item> {

public:

    //corresponding SafeCollection constructors
    SortedCollection() : SafeCollection<Item>() {}
    SortedCollection(int size) : SafeCollection<Item>(size) {}
    SortedCollection(Collection<Item>& a) : SafeCollection<Item>(a) {}

    //overriding add function to add in a sorted manner
    void add(Item e) {

    }

};

#endif //SORTED_COLLECTION_H













//      if (this->sz == this->capacity) {
//        this->expand();
//      }
//
//      (*this)[this->sz++] = e;