//
//  Searchers.hpp
//  Sort-Search
//
//  Created by Earng's on 8/19/2560 BE.
//  Copyright © 2560 Earng's. All rights reserved.
//

#ifndef Searchers_hpp
#define Searchers_hpp

#include <stdio.h>
#include <vector>
using namespace std;

int binarySearch(vector<int> &vt, int value);
int binarySearch(vector<int> &vt, int value, int from, int to);

int LinearSearch(vector<int> &vt, int value);


#endif /* Searchers_hpp */
