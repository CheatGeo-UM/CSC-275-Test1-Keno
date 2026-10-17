#include <iostream>
#include <random>
#include <algorithm>
#include "KenoNumbers.h"

void KenoNumbers::generateNumbers() {
    std::random_device rd;
    std::mt19937 gen(rd());
    gen.seed(0);
    std::uniform_int_distribution<int> distrib(1, 80);
    int num;
    for (int i = 1; i <= 20; ) {
        num = distrib(gen);
        if (std::find(m_kenoNumbers.begin(), m_kenoNumbers.end(), num) == m_kenoNumbers.end()) {
            m_kenoNumbers.push_back(num);
            i++;
        }
    }
}

std::vector<int> KenoNumbers::getKenoNumbers() {
    return m_kenoNumbers;
}

void KenoNumbers::printKenoNumbers() {
    std::cout <<"\n----------------------------------Results----------------------------------\n";
    std::cout << "Keno Numbers: ";
    std::sort(m_kenoNumbers.begin(), m_kenoNumbers.end());
    for (auto i:getKenoNumbers()) {
        std::cout << i << " ";
    }
}

void KenoNumbers::clearKenoNumbers() {
    m_kenoNumbers.clear();
}