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
      //make a temp copy of the dynamic array
      Item *temp = new Item[this->sz];
      //copy current array into temp


    }

};

#endif //SORTED_COLLECTION_H


/*// theSize is a private member of a class that holds the array
  int j = theSize - 1;
  // dynamic allocation
  int *temp = new int[theSize];
  for (int k = 0; k < theSize; k++) {
  temp[k] = x[k];
  }
  delete [] x;
  // using j >=0 because I need to check as low as the x[0] value
  for(; j >=0 && element < temp[j]; --j) {
  // So in the first run starting at x[3]
  //    this would be the value at x[3] is now at x[4]
  temp[j] = temp[j+1];
  }

  temp[j] = element;
  x = temp;
  delete [] temp;
  theSize++;
  */










//      if (this->sz == this->capacity) {
//        this->expand();
//      }
//
//      (*this)[this->sz++] = e;