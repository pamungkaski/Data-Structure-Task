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
void rankSort(int pTab[],int pRank[]){
    int ind=0;
    int max = 0;
    for (int i = 1; i<10; i++){
        if(pTab[i]>pTab[max]) max = i;
    };
    pRank[ind]=max;
    for (ind = 1; ind<10; ind++ ) {
        max =0;
        for (int i = 1; i < 10; i++) {
            if ((pTab[i] > pTab[max]) and ( pTab[i]<pTab[(pRank[ind-1])])){
                max = i;
            };
        };
        pRank[ind] = max;
    };

}
class IntArray{
public:
    int length = 9;
    int tabInt[10]={17,11,18,121,114,112,117,123,15,129};;
    int tabRank[10];
    void sort1(){
        quickSort(tabInt,length);
    };
    void sort2(){
        rankSort(tabInt,tabRank);
    };

};
int main() {
    IntArray Table1;
    IntArray Table2;
    IntArray Table3;
    Table1.sort1();
    Table2.sort2();
    std::cout << "Quick Sort"<< std::endl;
    for ( int j = 0; j < 10; j++ ) {
        std::cout << Table1.tabInt[j]<< std::endl;
    };

    std::cout << "Sort by Rank"<< std::endl;
    for ( int j = 0; j < 10; j++ ) {
        std::cout << Table2.tabInt[Table2.tabRank[j]]<< std::endl;
    };
    return 0;
}