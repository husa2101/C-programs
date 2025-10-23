/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief The STL generic algorithms
 */



#include <iostream>
#include "person.h"
#include "vector"
#include "algorithm"
#include "numeric"



int main() {

    Person arr[] = { {"frida", 190.9},{"John", 185.5}, {"Alice", 190.7}, {"Bob", 176.9} , {"Bob", 176.9}};
    std::vector<Person> vec(arr, arr + std::size(arr));
    std::for_each(vec.begin(), vec.end(), Print());


    // Används find_if för att hitta det första elementet som är större än prescribed värde
    double prescribed = 180.8;
    auto it = std::find_if(vec.begin(), vec.end(), MyPridicate(prescribed));
    if(it != vec.end()){
        std::cout << "the first value that is greater then Prescibed value is ";
        Print()(*it);
    }


    // Använd adjacent_find för att hitta det första paret av lika intilliggande element
    FindSameName p;
   auto name= std::adjacent_find(vec.begin(), vec.end(), p);
    if(name!= vec.end()){
        std::cout<< "name that has the equal object in a sequence" ;
        Print()(*name);
    }

    // Använd adjacent_find för att hitta det första paret av lika intilliggande element fast används här lampda instället för class
    /*auto adjacentIt = std::adjacent_find(vec.begin(), vec.end(), [](const Person& a, const Person& b) {
        return a.getName() == b.getName();
    });
    Print()(*adjacentIt);*/

    /*används för att jämföra två sekvenser eller delar av sekvenser för likhet, i den här fallet jämför arr, arr+ std::size(arr)
     * med den element som börjar med vec.begin() och jämförelsen görs baserad på användar definerade predikat */
     FindEqual f;
    auto equal = std::equal(arr, arr +std::size(arr), vec.begin(), f);
    std::cout << "the array and vector has the equal element " << equal;




   /* för att söka efter en sekvens av personer i vector<Person> som börjar från första personen i arr[] och slutar på den andra personen
   std::begin(arr) + 1 Resultatet av sökningen sparas i subsequenceIt.*/
    auto subsequenceIt = std::search(vec.begin(), vec.end(), std::begin(arr), std::begin(arr) + 1);

    // Sedan kontrolleras om en sekvens av personer hittades och i så fall skrivs den ut:
    if (subsequenceIt != vec.end()) {
        std::cout << "\nSubsequence found:\n";
        // är pekare som pekar på första elementet och subsequenceIt + std::size(arr) - 3 är pekare som pekar på sista elementet
        std::for_each(subsequenceIt, subsequenceIt + std::size(arr) - 3, Print());
    }

    // accumulate operation on a vector<Person>vec
    MyBinOp b;
    double sum = std::accumulate(vec.begin(), vec.end(), 0.0,b );
    double mean = sum / vec.size();
    std::cout << "the average value of the vector is: " << mean << std::endl;


    //  using transform function in order to transfor only the value from old vec to new vec2
    MyUnOp M;
    std::vector<double>vec2;
    std::transform(vec.begin(), vec.end(), std::back_inserter(vec2),M );
    std::cout << "the transform vec2 content is : ";
    for (auto it:vec2) {
    std::cout << it << " ";
    }
    std::cout << "\n\n";

    // replace the value of vec2 by subtracting each value with the average value from step 6 with the help of functor Myfunc()
    std::transform(vec2.begin(), vec2.end(),vec2.begin(),  Myfunc(mean));
    std::cout << " replace the value of vec2  ";
    for (auto it:vec2) {
        std::cout << it << " ";
    }
    std::cout << "\n\n";

    // fort vec2
    std::sort(vec2.begin(), vec2.end());
    for (auto it: vec2) {
        std::cout << it;
    }

}
