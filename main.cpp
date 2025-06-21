/**
* @brief the objectiv of this progam is to learn about the
* iteration and selection sats
*/



#include <iostream>
#include <limits>



int main()
{
    double num, totalInt, medelValue;
    double i = std::numeric_limits<double>::lowest();
    double j = 0;
    int var;

    /*by using cin inside while statement will automatically stop when it reaches
    the end of the file or encounters an error.*/
    std::cout << " enter a value" << "\n";
    while (std::cin >> num)
    {

        var++;
        double maxValue = std::max(i, num);
        double minValue = std::min(j, num);
        totalInt += num;
        // std::cout << maxValue << "\t";
        i = maxValue;
        j = minValue;
    }
    medelValue = totalInt / var;
    std::cout << i << "\n"
              << j << "\n"
              << medelValue << "\n";

    return 0;
}