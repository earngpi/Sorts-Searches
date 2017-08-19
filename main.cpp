//
//  main.cpp
//  Sort-Search
//
//  Created by Earng's on 8/14/2560 BE.
//  Copyright © 2560 Earng's. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Sorters.hpp"
#include "Searchers.hpp"
using namespace std;



void printVector(vector<int> list){
    if(list.size()==0){
        cout << "empty vector";
    }
    else{
        for(int i=0; i<=list.size()-1; i++){
            cout << list[i] << "  ";
        }
    }
    cout << "\n";
}

int main(int argc, const char * argv[]) {
    vector<int> testVector = {54, 26, 93, 17, 77, 31, 44, 55, 20, 67, 81};
    vector<int> testVector1 = {1,1,1,1,1,1,1,81,10};
    vector<int> testVector2 = {5,4,3,2,1,-17};
    vector<int> testVector3 = {-17};
    vector<int> testVector4 = {};
    
    //quickSort(testVector4);
    //printVector(testVector4);
    //mergeSort(testVector);
    printVector(testVector);
    cout << binarySearch(testVector4, 81) << endl;
    return 0;
}
