#ifndef _COLLECTION_H_
#define _COLLECTION_H_

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>


template<typename Item>
class Collection {
public:
  Collection(): capacity(INITIAL_CAPACITY), sz(0), 
    elements(std::make_unique<Item[]>(capacity)) {}

  Collection(int size): capacity(size), sz(size), 
    elements(std::make_unique<Item[]>(capacity)){}

  Collection(Collection<Item>& a): capacity(a.capacity), sz(a.sz),
    elements(std::make_unique<Item[]>(capacity)) {
    for (int i = 0; i < a.sz; i++) elements[i] = a.elements[i];
  }

  virtual int size() { return sz; }

  virtual Item get(int ndx) const { return elements[ndx]; }

  virtual void add(Item e) {
    if (sz == capacity) {
      expand();
    }

    (*this)[sz++] = e;
  }

  virtual Collection<Item>& remove() {
    sz--;
    return *this;
  }

  virtual Item* begin() { return elements.get(); }

  virtual Item* end() { return elements.get() + sz; }

  //overloaded = operator
  virtual Collection<Item>& operator=(Collection<Item>& a) {
    //creating new array with same capacity
    auto newElements = std::make_unique<Item[]>(a.capacity);
    //for each item within the array size copy array elements into new array elements
    for (int i = 0; i < a.sz; i++) newElements[i] = a.elements[i];
    //finally move elements
    elements = move(newElements);
    //copy capacity
    capacity = a.capacity;
    //copy size
    sz = a.sz;


    return *this;
  }

  //overloaded [] operators
  virtual Item operator[](int ndx) const { return elements[ndx]; }
  virtual Item& operator[](int ndx) { return elements[ndx]; }

  //overloaded << operator
  virtual Collection<Item>& operator<<(Item e) {
    add(e);
    return *this;
  }

  // TODO: overload + operator
  Collection<Item>& operator+(Item n){
    add(n);
    return *this;
  }

  // TODO: overload -- operator
  Collection<Item>& operator--(){
    return remove();
  }

  // TODO: overload - operator
  Collection<Item>& operator-(int n){
    for (int i = 1; i <= n; i++) {
      remove();
    }
    return *this;
  }

  // TODO: overload << operator
  friend std::ostream& operator<<(std::ostream& out, const Collection<Item>& c) {
    for (int i = 0; i < c.sz; i++) {
      out << c[i]<< std::endl;
    }
    return out;
  }


  virtual ~Collection(){}

protected:
  int capacity;
  int sz;
  std::unique_ptr<Item[]> elements;
  static const int INITIAL_CAPACITY = 8;

  void expand() {
    auto newElements = std::make_unique<Item[]>(capacity * 2);
    for (int i = 0; i < capacity; i++) newElements[i] = elements[i];
    elements = std::move(newElements);

    capacity *= 2;
  }

};//end of class Collection

#endif