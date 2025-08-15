//
// Created by shahr on 2025-08-06.
//


#include "linked_list.h"

#include <iostream>
#include <vector>

// node constructor
linked_list::node::node(double value): value(value), next(nullptr), prev(nullptr) {}

// linked_list constructor
linked_list::linked_list():head(nullptr), tail(nullptr) {
}

linked_list::~linked_list() {
    node* curent = head;
    while (curent != nullptr) {
        node* temp = curent;
        curent = curent->next;
        delete temp;
    }
}

void linked_list::insert(double value, size_t position) {
    node* new_node = new node(value);

    if (position <= 0 || !head) { // insert at beginning
        new_node->next = head;
        if (head)
            head->prev = new_node;
        else
            tail = new_node; // list was empty
        head = new_node;
        return;
    }

    node* current = head;
    int index = 0;

    while (current && index < position) {
        current = current->next;
        index++;
    }

    if (!current) { // insert at end
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    } else { // insert in the middle
        node* prev_node = current->prev;
        new_node->next = current;
        new_node->prev = prev_node;

        if (prev_node)
            prev_node->next = new_node;

        current->prev = new_node;

        if (position == 0)
            head = new_node;
    }
}

void linked_list::print() const {
    node* current = this->head;
    while(current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
}


void linked_list::push_back(double value) {
    node* new_node = new node(value);
    if(head == nullptr && tail == nullptr){
        tail = new_node;
        head = new_node;
    }else{
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
}

void linked_list::push_front(double value) {
    node* new_node = new node(value);
    if (head == nullptr && tail == nullptr) {
        head = new_node;
        tail = new_node;
    }else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

double linked_list::pop_front() {
    double value = head->value;
    if (head == nullptr){
        std::cerr << "there is nothing to pop" << std::endl;
        return -1;
    }else if(head == tail){
        head = head->next;
        delete head;
    }else{
        node* old_head = head;
        head = head->next;
        head->prev = nullptr;
        delete old_head;
    };
    return value;

}

double linked_list::pop_back() {
    double value = tail->value;
    if (head == nullptr && tail == nullptr){
        std::cerr << "there is nothing to pop" << std::endl;
    }else if(head == tail){
        delete tail;
        return -1;
    }else{
        node* new_tail = tail->prev;
        tail->prev = nullptr;
        new_tail->next = nullptr;
        delete tail;
        tail = new_tail;
    }
    return value;
}

linked_list::linked_list(const linked_list &src): head(nullptr), tail(nullptr) {
   node* current = src.head;
   while(current != nullptr){
       this->push_back(current->value);
       current = current->next;
   }
}

linked_list &linked_list::operator=(const linked_list &rhs) {

    if(this->head == rhs.tail){
        return* this;
    }

    while(this->head != nullptr){
        node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;

    node* current = rhs.head;
    while(current != nullptr){
        this->push_back(current->value);
        current = current->next;
    }
    return *this;
}

linked_list &linked_list::operator+=(const linked_list& rhs) {
    node* current = rhs.head;

    while(current != nullptr){
        this->push_back(current->value);
        current = current->next;
    }
    return *this;
}

double linked_list::front() const {
    node* current = head;
    if(current->value){
        return head->value;
    }else
        std::cout << " the list is empty" << std::endl;
}

double linked_list::back() const {
    node* current = tail;
    if(current->value){
        return tail->value;
    }else
        std::cout << "the list is empty" << std::endl;

    return 0;
}

double linked_list::at(size_t pos) const {
    if (tail == head)
        std::cout << " there is only one element in the list " <<std::endl;
    if(pos > this->size())
        std::cout<< "out of reach "<<std::endl;
    if (!head)
        std::cout << "the list is empty "<< std::endl;
    node *current = head;
    size_t size = 0;

    while( current && size < pos ){
        current = current->next;
        size++;
    }
    return current->value;
}

size_t linked_list::size() const {
    node* current = head;
    size_t size = 0;
    while (current != nullptr){
        current = current->next;
        size++;
    }
    return size;
}

void linked_list::print_reverse() const {
    node* current = tail;
    if(tail==head)
        std::cout << current->value << std::setw(4);
    if(!head)
        std::cout << "the List is empty" <<std::endl;

    while(current != nullptr){
        std::cout << current->value << std::setw(4);
        current = current->prev;

    }
}

void linked_list::remove(size_t pos) {
    node* current = head;
    node* current1 = tail;
    size_t size = 0;


    if(pos >= this->size()){
        std::cerr << "out of reach" <<std::endl;
    }else if(!head && !tail){
        std::cerr << " the list is empty" << std::endl;
    }
    else if(pos == this->size() -1 ) {
        node *preNode = current1->prev;
        preNode->next = nullptr;
        current1->prev = nullptr;
        tail = preNode;
        delete current1;


    }
    else if (size == pos) {
        node* postNode = current->next;
        current->next = nullptr;
        current->prev = nullptr;
        postNode->prev = nullptr;
        head = postNode;
        delete current;

    }
    else{
            while(current && size < pos){
                current = current->next;
                size++;
            }
            node* preNode = current->prev;
            node* postNode = current->next;
            preNode->next = postNode;
            postNode->prev = preNode;

            current->next = nullptr;
            current->prev = nullptr;

            delete current;

    }
}


bool linked_list::is_empty() const {
    node* current = head;
    if(current != nullptr){
        return true;
    }else{
        return false;
    }
}

linked_list linked_list::marge(linked_list& l1, linked_list& l2) const {

    linked_list margeList;
    node* current1 = l1.head;
    node* current2 = l2.head;
    if(!current1 && !current2){
        std::cerr << "the Marge process is not possible one och both list is empty" << std::endl;
    }else{
        while(current1 != nullptr && current2 != nullptr){

            if(current1){
                margeList.push_back(current1->value);
            }if(current2){
                margeList.push_back(current2->value);
            }

            current1 = current1->next;
            current2 = current2->next;
        }

        while(current1 != nullptr){
            margeList.push_back(current1->value);
            current1 = current1->next;
        }
        while (current2 != nullptr){
            margeList.push_back(current2->value);
            current2 = current2->next;

        }

    }

    return  margeList;
}