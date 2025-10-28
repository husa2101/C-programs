//
// Created by hussein on 2023-05-04.
//
#include "dataGenerate.h"
#include <bits/stdc++.h>


std::vector<int> SieveOfEratosthene(int n) {

    std::vector<int> primes;
    primes.push_back(2);
    int i = 3;
//Add primes until vector reaches given size
    while (primes.size() < n) {
        bool prime = true;
        for (int j = 0; j < primes.size() && primes.at(j) * primes.at(j) <= i; j++) {

            // find all composite integers and mark them as false
            if (i % primes.at(j) == 0) {
                prime = false;
                break;
            }
        }
//take all prims that is markt as true
        if (prime)
            primes.push_back(i);
        i++;
    }
    return primes;
}
