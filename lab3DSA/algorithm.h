//
// Created by shahr on 2023-05-06.
//

#ifndef LAB3STRUCT_ALGORITHM_H
#define LAB3STRUCT_ALGORITHM_H
#include<vector>

// liniar search function that take vector and a number to search for
int liniarSearch(std::vector<int> & vec, int number);


// take a vector and start and end element of the vectror in order to find the median
// and a key to search for
int binarySearch(std::vector<int>& vec, int l,int h,int key);




// to create a tree we forst need to declare a pointer to BstNode that will always store the address of root node
struct BstNode{
    int data;
    BstNode *left;
    BstNode *right;
    BstNode(int data)  :data(data), left(nullptr), right(nullptr){};
};
// generate a node
BstNode* GetNewNode(int data);

// create a binary tree and the return the root of the tree
BstNode * createBinaryTree(std::vector<int> & vector, int start, int end);

//take a root as a argument and data to search for
bool BinaryTreeSearch(BstNode* root , int data);


struct hashNode{
    hashNode(int data) :data(data), next(nullptr){};
    int data;
    hashNode *next;
};


//create hash table
std::vector<hashNode *>hashfuction (std::vector<int>& value);

// take a hash table as a argument and a key to search for
bool searchHashTable(std::vector<hashNode*> hashVector, int key);


#endif //LAB3STRUCT_ALGORITHM_H
