#include <iostream>
#include <stdio.h> 
#include <limits.h> 
#include <vector> 

int max(int a, int b) {return (a>b)? a : b;};



int calcMaxValue(int prices[],int rodLen,int maxValues[]){

    for(int currRodLen=1;currRodLen<=rodLen;currRodLen++){
        int maxVal = 0;
        for(int auxRodLen =0; auxRodLen<currRodLen;auxRodLen++){
            maxVal = max(maxVal,prices[auxRodLen]+calcMaxValue(prices,currRodLen-auxRodLen-1,maxValues));
        }
        maxValues[currRodLen]=maxVal;
    }
    
    return maxValues[rodLen];
}


int main() {
                     //size 1 , 2, 3 , 4
    int rodSizeValue[]={2,0,3,0,0,7,0,0,0,11};
    int size = 10;
    int * maxValues= new int[size];

    printf("Maximum Obtainable Value is %dn", calcMaxValue(rodSizeValue, size,maxValues)); 
    int rodSizeValue2[]={0,0,0,0,0,0,0,0,0,11};
    printf("Maximum Obtainable Value is %dn", calcMaxValue(rodSizeValue2, size,maxValues)); 
    int rodSizeValue3[]={0,0,0,0,0,0,0,0,0,31};
    printf("Maximum Obtainable Value is %dn", calcMaxValue(rodSizeValue3, size,maxValues)); 
    printf("Maximum Obtainable Value is %dn", calcMaxValue(rodSizeValue, size,maxValues)); 

    delete[] maxValues;

    getchar(); 
    return 0; 
}