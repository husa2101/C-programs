//
// Created by shahr on 2023-05-22.
//


#include <cmath>
#include "timeCalculation.h"
#include<algorithm>

void searchTime(std::vector<int> (*primeFunc)(int), int start, int end, int increment) {
    std::vector<std::string> textFils {"sequential.txt", "BinarySearch.txt", "BTSsearch.txt", "hashSearch.txt"};
    clear(textFils);


    auto linSearch = [](std::vector<int>& vector, int key ){ liniarSearch(vector, key);  };
    auto binSearch = [](std::vector<int>& vector, int key){ binarySearch(vector,0, vector.size()-1, key);};
    auto BTSsarch = [](std::vector<int>& vector, int key){ BinaryTreeSearch(createBinaryTree(vector,0,vector.size()-1), key);};
    auto hashSearch = [](std::vector<int>& vector, int key){ searchHashTable(hashfuction(vector),key);};


    for (int i = start; i < end; i+= increment){
        auto randomData = primeFunc(i);
        //std::sort(randomData.begin(), randomData.end());
        timecalculation(linSearch, randomData, textFils.at(0));
        timecalculation(binSearch, randomData, textFils.at(1));
        timecalculation(BTSsarch, randomData, textFils.at(2));
        timecalculation(hashSearch, randomData, textFils.at(3));
        randomData.clear();

    }


}

void timecalculation(void (*searchFunc)(std::vector<int> &, int ), std::vector<int> container, std::string filename) {
double sample= 50;
double squareTime = 0;
double totalTime= 0;
double avgTime;
double stddev;
double median;

    for(int i = 0; i < sample; i++){
        auto courentTime = time(searchFunc, container, filename);
        totalTime += courentTime;
        squareTime = pow(totalTime, 2);
    }
    avgTime = totalTime / sample;
    median = pow(totalTime, 2) / sample;
    stddev = sqrt((squareTime - median) / (sample -1));

    std::string output = std::to_string(container.size()) + "\t" + std::to_string(avgTime) + "\t" + std::to_string(stddev) + "\t" + std::to_string(sample) + "\n";
    write(output, filename);
}

float time(void (*func)(std::vector<int> &, int), std::vector<int> & vector, std::string textfile) {
int random = rand();
BstNode* rootNode;
std::vector<hashNode*>hashVector;



    if(textfile == "BTSsearch.txt"){
        rootNode = createBinaryTree(vector, 0, vector.size()-1);
        auto start = std::chrono::steady_clock::now();
        BinaryTreeSearch(rootNode, random);
        auto end = std::chrono::steady_clock::now();
        auto time = std::chrono::duration<double, std::milli>(end - start).count();
    return time;
    }
    else if(textfile == "hashSearch.txt"){
        hashVector = hashfuction(vector);
        auto start = std::chrono::steady_clock::now();
        searchHashTable(hashVector, random);
        auto end = std::chrono::steady_clock::now();
        auto time = std::chrono::duration<double, std::milli>(end- start).count();
        return time;
    }
    else{
        auto start= std::chrono::steady_clock::now();
        func(vector,random );
        auto end = std::chrono::steady_clock::now();
        auto time = std::chrono::duration<double, std::milli>(end- start).count();
        return time;
    }



}
