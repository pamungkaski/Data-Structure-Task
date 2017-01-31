//
// Created by Ki Ageng Satria Pamungkas on 1/31/17.
//

#ifndef KULIAHSTD_TASK1_H
#define KULIAHSTD_TASK1_H

#endif //KULIAHSTD_TASK1_H

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