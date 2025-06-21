#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <fstream>
#include <map>

void transform(std::string &hello)
{

    std::transform(hello.begin(), hello.end(), hello.begin(),
                   [](const char c)
                   { return std::tolower(c); });
}

std::string filter(std::string &text)
{
    std::string::size_type a = text.find(':');
    if (a != std::string::npos)
    {
        text.erase(a, 1); // Remove ':' if found (1 character at position 'a')
    }

    std::string::size_type b = text.find('(');
    if (b != std::string::npos)
    {
        text.erase(b, 1);
    }
    std::string::size_type c = text.find(')');
    if (c != std::string::npos)
    {
        text.erase(c, 1);
    }
    std::string target = "=================================================================";
    std::string::size_type d = text.find(target);
    if (d != std::string::npos)
    {
        text.erase(d);
    }
    std::string::size_type e = text.find('.');
    if (e != std::string::npos)
    {
        text.erase(e, 1);
    }
    std::string::size_type f = text.find('-');
    if (f != std::string::npos)
    {
        text.erase(f, 1);
    }
    std::string::size_type g = text.find('"');
    if (g != std::string::npos)
    {
        text.erase(g, 1); // Remove '(' if found (1 character at position 'b')
    }

    std::string::size_type h = text.find('*');
    if (h != std::string::npos)
    {
        text.erase(h, 1);
    }

    if (!text.empty() && text.back() == ',')
    {
        text.erase(text.size() - 1, 1);
    }

    std::string::size_type i = text.find('?');
    if (i != std::string::npos)
    {
        text.erase(i, 1);
    }
    std::string t = ",\"";

    if (text.size() >= t.size() && text.compare(text.size() - t.size(), t.size(), t) == 0)
    {
        text.erase(text.size() - t.size(), 1);
    }

    std::string s = "..";
    if (text.size() == s.size() && text.at(0) == s.at(0) && text.at(1) == s.at(1))
    {
        text.clear();
    }

    if (!text.empty() && text.back() == '!')
    {
        text.erase(text.size() - 1, 1); // Remove '(' if found (1 character at position 'b')
    }

    if (!text.empty() && text.back() == '"')
    {
        text.erase(text.size() - 1);
    }

    std::string kk = ",'";
    if (text.size() >= kk.size() && text.compare(text.size() - kk.size(), kk.size(), kk) == 0)
    {
        text.erase(text.size() - kk.size(), 1);
    }

    return text;
}

struct Compare
{
    int operator()(std::pair<std::string, int> first, std::pair<std::string, int> secound)
    {
        return secound.second < first.second;
    }
};

int main()
{
    std::vector<std::string> vec;
    std::ifstream input;
    std::string str;
    std::multimap<std::string, int> multi_map;
    input.open("hitchhikersguide.txt");

    if (input.fail())
    {
        std::cerr << " unable to open the file";
        return 0;
    }

    while (input >> str)
    {
        transform(str);
        std::string sub_str = filter(str);
        vec.push_back(sub_str);
    }
    std::sort(vec.begin(), vec.end());
    std::vector<std::string> copy_vec;

    for (auto it : vec)
    {
        copy_vec.push_back(it);
    }
    auto new_end = std::unique(copy_vec.begin(), copy_vec.end());
    copy_vec.erase(new_end, copy_vec.end());

    for (auto it : copy_vec)
    {
        int num = std::count(vec.begin(), vec.end(), it);
        multi_map.insert(std::pair{it, num});
    }
    std::vector<std::pair<std::string, int>> pair_vec(multi_map.begin(), multi_map.end());
    std::sort(pair_vec.begin(), pair_vec.end(), Compare());

    for (auto it : pair_vec)
    {
        std::cout << "the number of this charecter" << "  {" << it.first << "}  " << "in the text file is:   " << it.second << "\n";
    }

    return 0;
}

/*
struct comp{
    int operator()(int a, int b){

    return a < b;
    }
};

void print(int a){
    std::cout << a << std::setw(3);
}

int main(){
    std::vector<int>v{22, 44, 6, 8, 0, 8,21, 77, 3, 4, 45, 2, 7, 2, 2, 12, 21, 33, 3, 3, 3, 3};
    std::vector<int>::iterator it;
    it = std::max_element(v.begin(), v.end(), comp());
    std::cout << "the max value in this vector is: " << std::setw(3) << *it << "\n";

    std::vector<int>::iterator first;
    std::vector<int>::iterator last;
    first = v.begin();
    last = v.end();
    std::cout << "the number of elements is: " << std::distance(first, last) <<"\n";

   auto last_element = std::unique(v.begin(), v.end());
   v.erase(last_element, v.end());
   std::for_each(v.begin(), v.end(), print);
    std::cout << "\n\n";

   std::sort(v.begin(), v.end());
   std::for_each(v.begin(), v.end(), print);

   auto last_value = std::unique(v.begin(), v.end());
   v.erase(last_value, v.end());
    std::cout << "\n\n";
   std::for_each(v.begin(), v.end(), print);





    return 0;
}

*/

/*
struct Person{
    std::string name;
    int age;
};

bool compare(Person& p, Person& c){
    return p.age < c.age;
}
void print(Person& p);

int main(){

std::vector<Person> pers{{"Adam", 40}, {"rayan", 4},
                         {"rahele", 34},{"reihaneh", 8}};
std::sort(pers.begin(), pers.end(), compare);
std::for_each(pers.begin(), pers.end(), print);
std::cout << "--------------------------------------------------------------------"<< std::endl;
std::vector<Person>::iterator it;

    for (it = pers.begin(); it != pers.end(); ++it) {
        std::cout << it->age << std::setw(3) << it->name << "\n";
    }

    std::cout << "-------------------------------------------------------" << std::endl;

    for (Person& element: pers) {
        std::cout << element.age << std::setw(3) << element.name << "\n";
    }

    return 0;
}

void print(Person& p){
    std::cout << p.age << " and " << p.name <<"\n";
}
*/

/*
this is a part of the lab 3


#include "is_sorted.h"

int main()
{
    std::ifstream input;
    std::ifstream insert;
    std::ofstream output;

 input.open("a.txt");
 insert.open("b.txt");
 output.open("output.txt");

    if(!input.is_open())
         std::cerr << "unable to open the file (Input)" << "\n";
    else if(!insert.is_open())
        std::cerr << "unable to open the file (Insert)" << "\n";
    else if(!output.is_open())
        std::cerr << "unable to open the file (output)" << "\n";
    mergeSort(input, insert, output);


   bool checkSorted = isSorted(input);
    if (checkSorted)
        std::cout << "the integer list is sorted";
    else
        std::cout << "the integer list is not sorted";


    input.close();
    insert.close();
    output.close();

    return 0;
}
*/

/*
int main()
{
    while (true){
        string str, name;
        bool isPolindrome = true;
        cout << " enter a string please" << "\n";
        cin >> str;
        if(cin.fail()){
            cout << "invalid value " << "\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }else if(str == "exit")
            break;

        cin.clear();


        for (int i = str.size() -1; i >= 0 ; --i) {
            name += str[i];
        }
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] != name[i]){
                isPolindrome = false;
                break;
            }
        }

        if (isPolindrome)
            cout << "it is polindrome";
        else
            cout << "it is not polindrome";
    }
        return 0;
}*/
