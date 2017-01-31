#include <iostream>
#include "task1.cpp"
int main() {
    char input;
    std::cout << "Tugas Inteface" << std::endl;
    std::cout << "1. Tugas 1"<< std::endl;
    std::cout << "Choose: " ;
    std::cin >> input;
    switch(input){
        case '1': tugas1();
    };
    return 0;
}