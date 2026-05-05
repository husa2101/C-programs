//
// Created by shahr on 2026-04-23.
//

#include "gussAnNumber.h"

int gussAnNumber::random() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    return dis(gen);
}

gussAnNumber::gussAnNumber() {
    secretNumber = random();
}
int gussAnNumber::getSecretNumber() {
    return secretNumber;
}

void gussAnNumber::reset() {
    secretNumber = random();
}
