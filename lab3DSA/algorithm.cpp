//
// Created by hussein on 2023-05-06.
//

#include "algorithm.h"
#include<iostream>


int liniarSearch(std::vector<int> & vec ,int key) {

    for(int i = 0; i < vec.size(); i++) {
        if (key == vec.at(i)) {
            return i;
        }
    }
        return -1;
}

int binarySearch(std::vector<int> &vec, int l, int h, int key) {
    while(l <= h){
        // find the mid index
        int mid = ( l + h ) / 2;
        // if the value we are loking for is in mid then return the search value
        if(key == vec[mid]){
            return mid;

        }
        // if the value we are loking for is less then mid value then our key is in the left part of the array
        else if(key < vec[mid]){
            h = mid -1; // then we can modify the high
        }
        // if there is not in the left then it is in the right hand side
        else
            l = mid +1; // then we modify the low
            // we continue this process until we find the key

    }
    return -1;
}

// function to create a new node in heap
/*BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}*/


BstNode * createBinaryTree(std::vector<int> & vector, int start, int end){
    if(start <= end){

        int mid = (start + end) / 2;
        //int NewNode = vector.at(mid);
        //BstNode * root = GetNewNode(NewNode);
        BstNode* root = new BstNode(mid);
        root->left = createBinaryTree(vector, start, mid -1);
        root->right = createBinaryTree(vector, mid +1 , end);

        return root;
    }
    else{
        return nullptr;
    }
}

bool BinaryTreeSearch(BstNode* root , int data){
    if(root == nullptr) return false;
    if(root->data == data) return true;
    else if(data <= root->data)return BinaryTreeSearch(root->left, data);
    else return BinaryTreeSearch(root->right, data);

}




/*
// constructor function that create a ned node;
hashNode getNewNode(int data){
    hashNode NewNode = new  hashNode();
    NewNode.data = data;
    NewNode.next = nullptr;
    return NewNode;
}
*/


// create a table
std::vector<hashNode *> hashfuction(std::vector<int> &vector) {

    int size = vector.size() / 0.6;

    // create a new hashtable with the new size
    std::vector<hashNode*> hashTable(size);
    for (int i = 0; i < vector.size(); i++) {

        //allokera minne i heap och data from vector skickas till constructure och initializerar medlem variabel data i hashNode
        hashNode *firstnode = new hashNode(vector.at(i));
        int key = vector.at(i) % size;
        //std::cout << key <<" ";

        //om värdet i position 'key' i tablen är tom tilldela den första noden till den plats.
        if(hashTable.at(key)== nullptr){
            hashTable.at(key) = firstnode;
        }
        else{ // annars om det är inte tom ta den platsen i hashtabelen och lägg till en till element med hjälp av next* pointer som är medlem i hashnoden.
            hashNode* hashSecound = hashTable.at(key);
            if(hashSecound->next != nullptr){
                hashSecound = hashSecound->next;
            }
                hashTable.at(key)->next = firstnode;
        }
    }
    return hashTable;

}


bool searchHashTable(std::vector<hashNode*> hashVector, int target) {

    //since we use (mod n) to find the index in a table for out value so we also need to use (mod n) reverse to lokade the value
    int keyPos = target % hashVector.size();

    // while the target index is not empty
    while (hashVector.at(keyPos)!= NULL) {

        // is the data inside the index of intresst has data and is out data that we are looking for then return true
        if (hashVector.at(keyPos)->data == target) {
            //std::cout << hashVector.at(keyPos)->data <<  " ";
            return true;
        } else
            hashVector.at(keyPos) = hashVector.at(keyPos)->next;;
    }

    return false;
}













/*

   for (int i = 0; i < vector.size(); i++) {

        //create a newNode and get the middle index.
        hashNode *firstnode = new hashNode(vector[i]);
        int key = vector.at(i) % size;


        }
        // if the key is empty set it to first node
        if (hashTable.at(key) == nullptr) {
            hashTable.at(key) == firstnode;
        } else {
            // if the key is not empty add the secound key
            hashNode *secoundNode = hashTable.at(key);
            while (secoundNode->next != nullptr) {
                secoundNode = secoundNode->next;
            }

            //set the next value to new node
            hashTable.at(key)->next = firstnode;
 **/