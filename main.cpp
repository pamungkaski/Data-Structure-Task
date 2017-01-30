#include <iostream>
#include "tugas1.cpp"
int main() {
    IntArray Table1;
    IntArray Table2;
    IntArray Table3;
    Table1.sort1();
    Table2.sort2();
    Table3.sort3();
    std::cout << "Quick Sort"<< std::endl;
    for ( int j = 0; j < 10; j++ ) {
        std::cout << Table1.tabInt[j]<< std::endl;
    };

    std::cout << "Sort by Rank"<< std::endl;
    for ( int j = 0; j < 10; j++ ) {
        std::cout << Table2.tabInt[Table2.tabRank[j]]<< std::endl;
    };

    std::cout << "Sort by Linked"<< std::endl;
    std::cout << Table3.tabInt[Table3.first] <<std::endl;
    int index = Table3.first;
    for ( int j = 1; j < 10; j++ ) {
        index = Table3.tabLin[index];
        std::cout << Table3.tabInt[index]<< std::endl;
    };
    return 0;
}