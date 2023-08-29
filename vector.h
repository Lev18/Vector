#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>
#include <stdexcept>

class  Vector {
  private:  
  int size;
  int capacity;
  int *arr;

public:
  Vector(): size(0), capacity(1), arr(nullptr) {
    arr = new int[capacity];
  }

  Vector(const Vector& src);
  Vector operator=(const Vector& oth);
  Vector(Vector&& oth);
  Vector operator=(Vector&& oth);
  ~Vector();

  void push_back(int elem);
  void pop_back();
  void print();
  int at(int placement);
  int operator[](int index);
  void insert(int placement, int elem);
  void pop_front();
  void push_front(int elem);
};

#endif
