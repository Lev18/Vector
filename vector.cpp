#include "vector.h"

void Vector::push_back (int elem) {
    if (size == capacity) {
        int *tmp = new int [2 *capacity];
        for (int i = 0; i < capacity; ++i) {
            tmp[i] = arr[i];
        }
        capacity *= 2;
        delete [] arr;
        arr = tmp;
        tmp = nullptr;
    }
    arr[size] = elem;
    ++size;
}

void Vector::pop_back() {
    if (0 == size) {
        --size;
        return;
    }
    int lastIndex = size - 1;
    arr[lastIndex] = 0;
     --size; 
}

void Vector::print () {
     for (int i = 0; i < size; ++i) {
      std :: cout << arr[i] << std::endl;
    }
}

int Vector::at (int placement) {
    if (size < placement) {
        throw std::out_of_range("index is out of range");
    }

        return arr[placement];
}

void Vector::insert(int placement, int elem) {
    int* tmp = new int[capacity + 1];
    bool pl = false;
    for (int i = 0; i < capacity; ++i) {
        if (i == placement) {
            tmp[i] = elem;
            pl = true;
        }
        if (pl) {
            tmp[i + 1] = arr[i];
        } else {
            tmp[i] = arr[i];
        }
    }
   ++capacity;
   ++size;
    delete [] arr;
    arr = tmp;
}

void Vector::pop_front() {
  int* tmp = new int [capacity - 1];
  int* ptr = arr + 1;
  int* ptr1 = tmp;
  for(auto i = 0; i < size -1; ++i) {
    *tmp++ = *ptr++;
  }
  delete [] arr;
  arr = ptr1;
  --size;
}

void Vector::push_front(int elem) {
    insert(0, elem);
}
