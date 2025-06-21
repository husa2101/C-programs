//
// Created by shahr on 2024-10-11.
//
#include"is_sorted.h"

bool isSorted(std::ifstream& input){
    int data;
    int num = std::numeric_limits<int>::lowest();
    bool checkSort = true;


    while(input >> data){
        if(num <= data)
            num = data;
        else{
            checkSort = false;
            break;
        }
    }
    return checkSort;
}

void mergeSort(std::ifstream& input, std::ifstream& insert, std::ofstream& output){
    int data, data1;
    bool inputHasData = false, insertHasData = false;
    if(input >> data)
        inputHasData = true;
    if(insert >> data1)
        insertHasData = true;


    // Merge the data from the two files
    while (insertHasData && inputHasData) {
        if (data <= data1) {
            output << data << " ";
            if (input >> data)
                inputHasData = true;
            else
                inputHasData = false;
        } else {
            output << data1 << " ";
            if (insert >> data1)
                insertHasData = true;
            else
                insertHasData = false;
        }
    }

    // If there are remaining elements in insert file
    while (inputHasData) {
        output << data << " "; // the reason that we write first is that we have already
        // read ones in previus while loop and we dont need to read it egain.
        if (input >> data)
            inputHasData = true;
        else
            inputHasData = false;
    }

    // If there are remaining elements in input file
    while (insertHasData) {
        output << data1 << " ";
        if (insert >> data1)
            insertHasData = true;
        else
            insertHasData = false;
    }

}