#include <iostream>
#include <vector>
#include <string>
// ENUM CREATES A MAPPING OF NUMBERS TO IDENTIFIES
// one AND spedas MAP TO A THE NUMBER 0
//two AND hearts MAO TO THE NUMBER 1
// there AND diamonds MAO TO THE NUMBER 2
// AND SO ON

enum Rank{ONE, TWO, THERE, FOUR, FIVE, SEX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TOWELVE};
enum Suit{HEARTS, SPEDAR, DIAMONDS,CLUBS};

struct Card{
    Rank rank;
    Suit suit;
    int num_suit = 4;
    int num_rank = 13;
};

struct Deck{
    std::vector<Card> cards;
    int max_size_of_deck = 52;


};

void print_cards(const Card& card);
void print_deck(const Deck& deck);
void initialize(Deck& deck); // passing by reference sompis the memory location of the actual parameter
//into the formal parameter

int main() {

    Deck my_card;
    initialize(my_card);
    print_deck(my_card);

    return 0;
}
void initialize(Deck& deck){
    for(int count = 0; count < deck.max_size_of_deck; count++){
        Card card;
        for(int suit = 0; suit < card.num_suit; suit++ ){
            for(int rank = 0; rank< card.num_rank; rank++){
                card.suit = Suit(suit);   // Suit is a datatype that perform a type conversion from int to those
                card.rank = Rank(rank);
                deck.cards.push_back(card);
            }
        }
    }
}

void print_deck(const Deck& deck ){
    for(Card c: deck.cards){
        print_cards(c);
    }
}

void print_cards( const Card& card){
    std::cout<< "rank:" << card.rank << " suit:" << card.suit << "\n";
}
