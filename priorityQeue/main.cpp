/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief mallklasser och containerstrukturer
 */


#include <iostream>
#include "Pq.h"
#include "random"


struct delars_order{
    std::string name;
    int price;
};

//comp function
bool less_price(delars_order lhs, delars_order rhs){
    return lhs.price < rhs.price;
}

// med den här comperator funcktionen berättar vi för kön att det billigaste ska vara först
struct comparator{
   bool operator()(delars_order &lhs, delars_order &rhs){
        return lhs.price < rhs.price;
    }
};

int main() {

    std::random_device ed;
    std::mt19937 gen(ed());
    std::uniform_int_distribution<int>destribution(15, 30);

    // lampda function
    auto delarComp = [](const delars_order& d1, const delars_order& d2) { return d1.price < d2.price; };

    // using lamda function
    //p_queue<delars_order, decltype(delarComp)> seller(delarComp);
    //p_queue<delars_order,decltype(delarComp)> buyer(delarComp);

    // using funktions objekt
     p_queue<delars_order,comparator> sellerOrder;
     p_queue<delars_order,comparator> buyerOrder;


    // using the comp function
    // p_queue<delars_order, decltype(*less_price)> sellerOrder(less_price);
    // p_queue<delars_order, decltype(*less_price)> buyerOrder(less_price);
    for (int i = 0; i < 6; ++i) {

    buyerOrder.push({"Erik Pendel", destribution(gen)});
    buyerOrder.push({"Jarl Wallenburg", destribution(gen)});
    buyerOrder.push({"Joakim von Anka", destribution(gen)});
    sellerOrder.push({"Erik Pendel", destribution(gen)});
    sellerOrder.push({"Jarl Wallenburg", destribution(gen)});
    sellerOrder.push({"Jarl Wallenburg", destribution(gen)});

    }

    while(!buyerOrder.empty() && !sellerOrder.empty()){

        if(sellerOrder.top().price <= buyerOrder.pop().price){
        delars_order buyOrder = buyerOrder.pop();
        delars_order selasOrder = sellerOrder.pop();

            std::cout << buyOrder.name << "  buys from " << selasOrder.name << " for the price of " << buyOrder.price << std::endl;

        }
        buyerOrder.pop();
    }








    /*pq <int>mypq;

    mypq.push(9);
    mypq.push(34);
    mypq.push(2);
    mypq.push(91);
    mypq.push(39);

    while(!mypq.empty()){
        std::cout << mypq.top() << ", ";
        mypq.pop();
    }*/


}
