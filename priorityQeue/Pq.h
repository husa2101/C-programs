/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief mallklasser och containerstrukturer
 */


#ifndef PQ_PQ_H
#define PQ_PQ_H
#include <iostream>
#include <functional>

#include <queue>
#include <functional>

/* using template meaning declear and define in the same file. template has advantages such as, reusability and flexibility */
template <typename T, typename COMP = std::less<T>>
class p_queue {
public:
    //p_queue() = default;
    //p_queue(){}

    // constructor that initialize a comparator functor
    p_queue(COMP comp=COMP()) : comp(comp) {}
    // detta är en type omvandling construerare den omvandlar from typen COMP till typen p_queue

    /*template <typename IT>
    p_queue(IT first, IT last, COMP comp = COMP()) : data(first, last), comp(comp) {
    }*/

    // push the element into the queue and sort them using comparator
    void push(T element) {
        data.push_back(element);
        std::sort(data.begin(), data.end(), comp);
    }

    // retrive the top element
    T top() const {
        return data.front();
    }

    // remove the top element
    T pop() {
        T top_element = data.front();
        data.erase(data.begin());
        return top_element;
    }

    // chack if the container is empty
    bool empty() const {
        return data.empty();
    }

    // what is the size of the container
    size_t size() const {
        return data.size();
    }

private:
    std::vector<T> data;
    COMP comp;
};



#endif //PQ_PQ_H
