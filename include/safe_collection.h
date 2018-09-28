//
// Created by Jazmin Belmonte on 9/21/18.
//

#ifndef SAFE_COLLECTION_H
#define SAFE_COLLECTION_H

#include <stdexcept>
#include "collection.h"

template <typename Item>
class SafeCollection : public Collection<Item> {

public:

    //corresponding Collection constructors
    SafeCollection() : Collection<Item>() {}
    SafeCollection(int size) : Collection<Item>(size) {}
    SafeCollection(Collection<Item>& a) : Collection<Item>(a) {}

    //overriding the remove() function
    SafeCollection<Item>& remove() {
      if (this->sz == 0){
        throw std::runtime_error("Nothing to remove");
      } else {
        this->sz--;
        return *this;
      }
    }

    //TODO: Override the ​operator[]functions to throw an ​std::runtime_error​ when the given index is ​< 0​ or > size.
    //overriding [] operators

    Item operator[](int ndx) const {
      if (ndx < 0){
        throw std::runtime_error("Given index is less than 0");
      } else if (ndx > this->sz) {
        throw std::runtime_error("Given index is greater than size");
      } else {
        return this->elements[ndx];
      }
    }

    Item& operator[](int ndx) {
      if (ndx < 0){
        throw std::runtime_error("Given index is less than 0");
      } else if (ndx > this->sz) {
        throw std::runtime_error("Given index is greater than size");
      } else {
        return this->elements[ndx];
      }
    }

    //virtual Item operator[](int ndx) const { return elements[ndx]; }
    //virtual Item& operator[](int ndx) { return elements[ndx]; }

};

#endif //SAFE_COLLECTION_H
