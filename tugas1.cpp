#include <iostream>
void swap(int &px, int &py){
    int temp = px;
    px = py;
    py =temp;
};
void quickSort(int ptab[], int &pPan){
    int pivot = pPan;
    int wall = 0;
    int element = 0;
    while (wall != pivot){
        if (element == 9){
            swap(ptab[wall],ptab[pivot]);
            element = wall;
        }
        else {
            if (ptab[element]>=ptab[pivot]){
                swap(ptab[wall],ptab[element]);
                quickSort(ptab,wall);
                wall++;element++;
            }
            else element++;
        };
    }
};
class IntArray{
public:
    int length = 9;
    int tabInt[10]={17,11,18,121,114,112,117,123,15,129};
    void sort(){
        quickSort(tabInt,length);
    };

};
int main() {
    IntArray Table1;
    Table1.sort();
    for ( int j = 0; j < 10; j++ ) {
        std::cout << Table1.tabInt[j]<< std::endl;
    }
    return 0;
}