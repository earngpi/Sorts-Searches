//
//  Sorters.cpp
//  Sort-Search
//
//  Created by Earng's on 8/14/2560 BE.
//  Copyright © 2560 Earng's. All rights reserved.
//

#include "Sorters.hpp"
#include <iostream>
#include <vector>
using namespace std;



//QuickSort---------------------------------------------------------------------------------------------

void quickSort(vector<int> &vt){
    quickSort(vt, 0, (int)vt.size()-1);
}


void quickSort(vector<int> &vt, int from, int to){
    //base case and error input
    if(from == to || vt.size()==0){
        return;
    }
    
    //init
    int pivot = to; //last element as pivot
    int left = from;
    int right = pivot-1;
    
    //general case starts from next line to the end of function
    //sorting left and right sides
    while(left<right){
        while(left<to && vt[left]<=vt[pivot]){ //be careful of 1st condition
            left++;
        }
        while(right>from && vt[right]>=vt[pivot]){ //be careful of 1st condition
            right--;
        }
        if(left<right){
            int tmp = vt[left];
            vt[left] = vt[right];
            vt[right] = tmp;
        }
    }
    if(vt[left]>vt[pivot]){ //final switch if value at left is higher than the one at pivot
        int tmp = vt[left];
        vt[left] = vt[pivot];
        vt[pivot] = tmp;
    }
    
    //recursion
    if(left==right){ //when value at pivot is the highest or lowest
        quickSort(vt, from, right);
        quickSort(vt, left+1, to);
    }else{
        quickSort(vt, from, right);
        quickSort(vt, left, to);
    }
    
    return;
}



//MergeSort---------------------------------------------------------------------------------------------

void mergeSort(vector<int> &vt){
    mergeSort(vt, 0, (int) vt.size()-1);
}


void mergeSort(vector<int> &vt, int from, int to){
    //base case
    if(from>=to){
        return;
    }
    //general case
    int mid = (from+to)/2;
    mergeSort(vt, from, mid);
    mergeSort(vt, mid+1, to);
    merge(vt, from, mid, to);
    return;
}


void merge(vector<int> &vt, int from, int mid, int to){
    vector<int> tmp = vt;
    
    //init
    int left = from;
    int right = mid+1;
    int i = from; //remembers vector index
    
    while(left<=mid && right<=to){ //sorting elements to the right positions
        if(tmp[left]>tmp[right]){
            vt[i++] = tmp[right++];
        }else{
            vt[i++] = tmp[left++];
        }
    }
    
    while(left<=mid){ //when left part has not been exhausted
        vt[i++] = tmp[left++];
    }
    while(right<=to){ //when right part has not been exhausted
        vt[i++] = tmp[right++];
    }
}



//HeapSort----------------------------------------------------------------------------------------------

void heapSort(vector<int> &vt){
    for(int i=((int)vt.size()-1)/2; i>=0; i--){ //init: turning input array to max heap
        heapify(vt, i, (int)vt.size());
    }
    
    int lastIndex = (int)vt.size()-1; //virtual last index for max heap
    while(lastIndex>=0){ //extract the biggest(first) element until all have been extracted/sorted
        int tmp = vt[0];
        vt[0] = vt[lastIndex];
        vt[lastIndex--] = tmp;
        //lastIndex--;
        heapify(vt, 0, lastIndex+1);
    }
}

/*helper method that turns input array or subarray into max heap
 *(vt[root] considered first element while vt[size-1] considered last element in array) 
 */
void heapify(vector<int> &vt, int root, int size){ 
    int left = (root*2)+1;
    int right = (root*2)+2;
    int largest = root;
    

    if(left<=size-1 && vt[largest]<vt[left]){ //when value at left is larger than that at largest
        largest = left;
    }
    if(right<=size-1 && vt[largest]<vt[right]){ //when value at right is larger than the one at (current)largest
        largest = right;
    }
    
    if(largest!=root){ //if root is not largest, switch them and heapify the affected subtree
        int tmp = vt[root];
        vt[root] = vt[largest];
        vt[largest] = tmp;
        heapify(vt, largest, size);
    }
}
