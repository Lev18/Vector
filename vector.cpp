#include "vector.h"

Vector::Vector(const Vector& src) {
    capacity = src.capacity;
    size = src.size;
    int* tmp = new int[capacity];
    for (int in = 0; in < capacity; ++in) {
      tmp[in] = src.arr[in]; 
    }
    delete[] arr;
    arr = tmp;
}

Vector::Vector(Vector&& oth) {
    arr = oth.arr;
    size = oth.size;
    capacity = oth.capacity;

    oth.arr = nullptr;
    oth.size = 0;
    oth.capacity = 0;
}

Vector Vector::operator=(Vector&& oth) {
    if (this != &oth) {
        delete[] arr;
        size = oth.size;
        capacity = oth.capacity;
        arr = oth.arr;

        oth.arr = nullptr;
        oth.size = 0;
        oth.capacity = 0;
    }
    return *this;
}

Vector Vector::operator=(const Vector& src) {
    if (this != &src) {
        delete[] arr;

        size = src.size;
        capacity = src.capacity;
        arr = new int[capacity]; // allocate new memory for the new array

        // copying elements from source object's array
        for(int in = 0; in < capacity; ++in) {
            arr[in] = src.arr[in];
        }
    }
    return *this;
}

void Vector::push_back (int elem) {
    if (size == capacity) {
        int *tmp = new int [2 *capacity];
        for (int i = 0; i < capacity; ++i) {
            tmp[i] = arr[i];
        }
        capacity *= 2;
        delete[] arr;
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

void Vector::print() {
     for (int i = 0; i < size; ++i) {
      std :: cout << arr[i] << std::endl;
    }
}

int Vector::at(int placement) {
    if (size <= placement) {
        throw std::out_of_range("index is out of range");
    }
    return arr[placement];
}

int Vector::operator[](int index) {
     if (size <= index) {
        throw std::out_of_range("index is out of range");
    }
    return arr[index]; 
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
    delete[] arr;
    arr = tmp;
}

void Vector::pop_front() {
  int* tmp = new int [capacity - 1];
  int* ptr = arr + 1;
  int* ptr1 = tmp;
  for(auto i = 0; i < size -1; ++i) {
    *tmp++ = *ptr++;
  }
  delete[] arr;
  arr = ptr1;
  --size;
}

void Vector::push_front(int elem) {
    insert(0, elem);
}
