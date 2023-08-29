#include "vector.h"

int main() {
  Vector obj1;
    obj1.push_back(15);
    obj1.push_back(16);
    obj1.push_back(17);
    obj1.push_back(18);
    obj1.pop_back();
    std::cout << obj1.at(2) << std::endl;
    obj1.insert(0, 7);
    obj1.push_front(7);
    obj1.pop_front();
    obj1.print();
  
    std::cout << obj1[3] << std::endl;
}
