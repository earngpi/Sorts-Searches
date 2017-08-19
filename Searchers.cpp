//
//  Searchers.cpp
//  Sort-Search
//
//  Created by Earng's on 8/19/2560 BE.
//  Copyright © 2560 Earng's. All rights reserved.
//

#include "Searchers.hpp"
#include <iostream>
#include <vector>
using namespace std;



//BinarySearch------------------------------------------------------------------------------------------

int binarySearch(vector<int> &vt, int value){
    return binarySearch(vt, value, 0, (int)vt.size()-1);
}

int binarySearch(vector<int> &vt, int value, int from, int to){
    while(from<=to){ //still elements to compare (after focusing area of search)
        int mid = (from+to)/2;
        if(vt[mid]==value){ //found
            return mid;
        }else if(vt[mid]>value){ //focus searching to left part
            to = mid;
        }else{ //focus searching to right part
            from = mid+1;
        }
    }
    return -1; //not found
}



//LinearSearch------------------------------------------------------------------------------------------

int LinearSearch(vector<int> &vt, int value){
    if(vt.size()!=0){
        for(int i=0; i<=vt.size()-1; i++){ //check elements one by one
            if(vt[i]==value){
                return i; //found
            }
        }
    }
    return -1; //not found
}
