#include "dataGenerate.h"
#include "algorithm.h"
#include"timeCalculation.h"
//#include"matplotlibcpp.h"




int main() {

    srand(time(NULL));

    auto primes = [](int N){std::vector<int> data = SieveOfEratosthene(N); return data; };
        int start = 100;
        int end = 10000;
        int increment = 100;

    searchTime(primes,start, end, increment);


/*
int key = 97;
   std::vector<hashNode*> hashtable = hashfuction(primtal);
   //std::cout<< hashtable.at(3)->data << "   "<<hashtable.at(3)->next->data;

    if(searchHashTable(hashtable,key)){
        std::cout << " the key exist" << " ";
    }else{
        std::cout << "the key does not exist" << " ";
    }

int n = 100;
   BstNode* root; // pointer to the node

    std::vector<int> primeInt = SieveOfEratosthene(n);
    for(auto it : primeInt){
        std::cout<< it <<" ";
    }
std::cout<< " \n";
    int start = 0;
    int end = primeInt.size()-1;
    root = createBinaryTree(primeInt, start, end);


while(true){
    int number;
    std::cout << "enter a number to be search for"<< std::endl;
    std::cin>> number;
    if(BinaryTreeSearch(root, number) == true) std:: cout << "found" << "\n";
    else std::cout << "Not found" << "\n";
    }

int n = 100;
    std::vector<int> primeInt = SieveOfEratosthene(n);
    for(auto it: primeInt){
        std::cout<< it << " ";
    }
    std::cout<< "\n";



    int m = 13;
    int number = liniarSearch( primeInt,m);
    if (number== -1)std::cout<<"the number is not found";
    else std::cout << "the index of: " << m << "  is  "<< number;
    std::cout<< "\n";



    int key = 7;
    int h = primeInt.size()-1; // last index of a vector
    int l = 0;  // first index of a vector
    std::cout << h << ", " <<l << "\n";
    std::cout<< binarySearch(primeInt,l, h , key);
*/
    return 0;
}
