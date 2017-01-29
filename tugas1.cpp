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
    int min = 0;
    for (int i = 1; i<10; i++){
        if(pTab[i]<pTab[min]) min = i;
    };
    int max = min;
    for (int i = 0; i<10; i++){
        if(pTab[i]>pTab[max]) max = i;
    };
    pRank[ind]=max;
    for (ind = 1; ind<10; ind++ ) {
        max = min;
        for (int i = 0; i < 10; i++) {
            if ((pTab[i] > pTab[max]) and ( pTab[i]<pTab[(pRank[ind-1])])){
                max = i;
            };
        };
        pRank[ind] = max;
    };

};
void linSort(int pTab[],int pLin[],int &aWal){
    int ind=0;
    int dummy;
    int prev;
    int min = 0;
    for (int i = 1; i<10; i++){
        if(pTab[i]<pTab[min]) min = i;
    };
    int max = min;
    for (int i = 1; i<10; i++){
        if(pTab[i]>pTab[max]) max = i;
    };
    aWal = max;
    dummy = aWal;
    prev = pTab[max];
    for (ind = 1; ind<10; ind++ ) {
        max = min;
        for (int i = 0; i < 10; i++) {
            if ((pTab[i] > pTab[max]) and ( pTab[i]<prev)){
                max = i;
            };
        };
        pLin[dummy] = max;
        prev = pTab[max];
        dummy = max;
    };

}
class IntArray{
    public:
        int length = 9;
        int tabInt[10]={17,11,18,121,114,112,117,123,15,129};;
        int tabRank[10];
        int tabLin[10];
        int first;
        void sort1(){
            quickSort(tabInt,length);
        };
        void sort2(){
            rankSort(tabInt,tabRank);
        };
        void sort3(){
            linSort(tabInt,tabLin,first);
        };
};
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