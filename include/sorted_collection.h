//
// Created by Jazmin Belmonte on 9/21/18.
//
#include "safe_collection.h"
#include <string>

#ifndef SORTED_COLLECTION_H
#define SORTED_COLLECTION_H

template <typename Item>
class SortedCollection : public SafeCollection<Item> {

public:

    //TODO: corresponding SafeCollection constructors
    SortedCollection() : SafeCollection<Item>() {}
    SortedCollection(int size) : SafeCollection<Item>(size) {}
    SortedCollection(Collection<Item>& a) : SafeCollection<Item>(a) {}

    //TODO: override add function to add in a sorted manner
    void add(Item e) {
      if (this->sz < this->capacity) {
        auto newElements = std::make_unique<Item[]>(this->capacity);
        int i = 0;
        while (e > this->elements[i]){
          newElements[i] = this->elements[i];
          i++;
        }
        newElements[i] = e;
        while (i < this->sz){
          newElements[i+1] = this->elements[i];
          i++;
        }
        this->sz++;
      }
      if (this->sz == this->capacity) {
        auto newElements = std::make_unique<Item[]>(this->capacity * 2);
        int i = 0;
        while (e > this->elements[i]){
          newElements[i] = this->elements[i];
          i++;
        }
        newElements[i] = e;
        while (i < this->sz){
          newElements[i+1] = this->elements[i];
          i++;
        }
        this->sz++;
        this->capacity *= 2;
      }
    }
};



#endif //SORTED_COLLECTION_H



/*
void add(Item e) {
  auto newElements = std::make_unique<Item[]>(this->sz +1);
  while (needAdd) {
    for (int i; i <= this->sz; i++) {
      if (e > this->elements[i-1]) {
        newElements[i-1] = this->elements[i-1];
      } else if ( e < this->elements[i]){
        newElements[i-1] = e;
        needAdd = false;
      }
    }
  }
  for (int i; i <= this->sz; i++){
    newElements[i-1] = this->elements[i-1];
  }
}*/




/*
int s = this->sz;
auto newElements= std::make_unique<Item[]>(s+1);
for (; s && this->elements < newElements[s-1]; --s){
newElements[s] = this->elements[s-1];
}*/





/*auto newElements = std::make_unique<Item[]>(this->capacity);
for (int i = 0; i < this->sz; i++) newElements[i] = this->elements[i];
newElements[this->sz++] = e;
for (int i = (this->sz-1); i > 0; i--){
for (int j = 1; j <= 1; j++){
if (newElements[j-1] > newElements[j]){
e = newElements[j-1];
newElements[j-1] = newElements[j];
newElements[j] = e;
}
}
}*/
