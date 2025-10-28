//
// Created by hussein on 2023-04-16.
//

#include "sortsAlgorithm.h"



// quickSort partition Medium
int partitionMedium(std::vector<int> &v, int low, int high){

    int mid = (low + high)/2;

        if(v.at(mid) < v.at(low)){
            std::swap(v.at(low) , v.at(mid));
        }if(v.at(high) < v.at(mid)){
            std::swap(v.at(mid), v.at(high));
        }if(v.at(high) < v.at(low)){
            std::swap(v.at(low) , v.at(high));
        }

    return v.at(high);
}




// Quicksort partition
int Partition(std::vector<int> &vector, int low, int high, bool median){


    int pivot;
    if (median)
        pivot = partitionMedium(vector,low, high); // median-of-three pivot
    else
        pivot = vector.at(high); // right side pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (vector.at(j) < pivot)
        {
            i++; // increment index of smaller element
            std::swap(vector.at(i), vector.at(j));
        }
    }
    i++;
    std::swap(vector.at(i), vector.at(high));
    return i;


}

void Quicksort(std::vector<int> &v, int start, int end, bool medium ){

    if(start<end){
        int p = Partition(v,start,end, medium);
        // sorting the left part
        Quicksort(v,start,p-1, medium);
        // sorting the right part
        Quicksort(v,p+1,end, medium);
    }

}

// selection
std::vector<int> selectionSort(std::vector<int> &vec) {

    for(int i = 0; i < vec.size() - 1; i++){
        int min = i;
        for(int j = i +1; j < vec.size(); j++){
            if (vec[j] < vec[min]) {

                min = j;
            }

        }
        std::swap(vec.at(i), vec.at(min));

    }
    return vec;
}


//insertionSort
std::vector<int> insertionSort(std::vector<int>&array){
    //so we begin from second index because we did not have another ithem to compare to. and we assume that the first ithem is in a right position.
    for(int i = 1; i < array.size(); i ++){
        // we need the another loop to look at all the previous items and if they are greater we need to shift.
        for(int j = 0; j < array.size(); j++ ){
            if(array[i] < array[j]) {  // if pos[0] is greater then pos[1]
                std::swap(array.at(i), array.at(j));

            }
        }
    }
    return array;

}



