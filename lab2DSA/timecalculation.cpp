//
// Created by hussein on 2023-04-18.
//

#include "timecalculation.h"
#include "sortsAlgorithm.h"
#include"print_to_file.h"


void sortTime(int start,int end, int incremant, std::vector<int>(*generate_data_funk)(int size)){

    //vector that hold all outputfile
    std::vector<std::string>filename {"selectionSort.data","insertionSort.data","sort.data","quickSortPart.data","quickSortMedium.data"};


    //create a lambda function in order to send it as argument ti another function
    auto selectSort = [](std::vector<int>& vector) { selectionSort(vector); };
    auto insertSort = [](std::vector<int>& vector) { insertionSort(vector); };
    auto sort = [](std::vector<int>& vector) {std::sort(vector.begin(), vector.end());};
    auto quickSortMedium = [](std::vector<int>& vector) { Quicksort(vector, 0, vector.size() -1, true);};
    auto quickPartition = [](std::vector<int>& vector) { Quicksort(vector, 0, vector.size() -1, false);};



     //clear file before writing in it
    std::ofstream clean;
    std::ofstream cl1;
    std::ofstream cl2;
    std::ofstream cl3;
    std::ofstream cl4;
    clean.open("insertionSort.data", std::ofstream::out | std::ofstream::trunc);
    cl1.open("selectionSort.data", std::ofstream::out | std::ofstream::trunc);
    cl2.open("sort.data", std::ofstream::out | std::ofstream::trunc);
    cl3.open("quickSortPart.data", std::ofstream::out | std::ofstream::trunc);
    cl4.open("quickSortMedium.data", std::ofstream::out | std::ofstream::trunc);
    clean.close();
    cl1.close();
    cl2.close();
    cl3.close();
    cl4.close();


    // for loop that input diffrent size into the generate_data_function to generate data
    for(int i = start; i < end; i+=incremant){

     auto randomData = generate_data_funk(i);


     // send function + randomData + file to write in
     timeCalculate(selectSort,randomData, filename[0]);
     timeCalculate(insertSort, randomData, filename[1]);
     timeCalculate(sort, randomData, filename[2]);
     timeCalculate(quickPartition, randomData, filename[3]);
     timeCalculate(quickSortMedium, randomData, filename[4]);

     }
}

void timeCalculate(void(*sort_funk)(std::vector<int>&), std::vector<int> container, std::string filename){
int sample = 5;
double totalTime = 0;
double sqareTime = 0;
double median;
double Stdev;
double avgTime;

    for (int i = 0; i < sample; i++) {

       auto timeCurrent = time(sort_funk, container);
       totalTime += timeCurrent;
       sqareTime += pow(timeCurrent, 2);

    }

    
    median = pow(totalTime, 2)/ sample;
    Stdev = sqrt((sqareTime - median)/ (sample -1));
    avgTime = totalTime / sample;


    // concatonate all information
    std::string output = std::to_string(container.size())+ "\t" +std::to_string(avgTime)+"\t" +std::to_string(Stdev)+ "\t" + std::to_string(sample) + "\t";

    // write it into ther outputfile
    write(filename, output);
}

double time(void(*sort)(std::vector<int> &), std::vector<int> vector) {

    auto start_time = std::chrono::steady_clock::now();

    sort(vector);

    auto end_time = std::chrono::steady_clock::now();
    auto   time =  std::chrono::duration<double,std::milli>(end_time-start_time).count();

    return time;
}




