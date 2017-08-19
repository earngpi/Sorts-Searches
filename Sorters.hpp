//
//  Sorters.hpp
//  Sort-Search
//
//  Created by Earng's on 8/14/2560 BE.
//  Copyright © 2560 Earng's. All rights reserved.
//

#ifndef Sorters_hpp
#define Sorters_hpp

#include <stdio.h>
#include <vector>
using namespace std;

void quickSort(vector<int> &vt);
void quickSort(vector<int> &vt, int from, int to);

void mergeSort(vector<int> &vt);
void mergeSort(vector<int> &vt, int from, int to);
void merge(vector<int> &vt, int from, int mid, int to);

#endif /* Sorters_hpp */
