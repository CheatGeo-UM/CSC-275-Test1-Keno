#include <iostream>
//#include <vector>
#include <algorithm>
#include "Player.h"

//The Player.cpp is encapsulation of all the code needed for the player portions of the Game to run.
void Player::inputPlayerNumbers() {
    int temp = 0;
    for (int i=0;i<10;i++){
        bool error = false;
        std::cout << "Enter your pick #" << i+1 <<": ";
        std::cin >> temp;
        if (std::cin.fail())
        {
            error = true;
            std::cin.clear();
            std::cin.ignore(100,'\n');
            std::cout << "Invalid data input! Try again. ";
        }
        else if (temp < 1 || temp > 80)
        {
            error = true;
            std::cout << temp << " is out of range! Try again. ";
        }
        else if (std::find(m_playerNumbers.begin(), m_playerNumbers.end(), temp) != m_playerNumbers.end()) {
            error = true;
            std::cout << temp << " was already picked! Try again. ";
        }
        if (error)
            i--;
        else
            m_playerNumbers.push_back(temp);
    }
}

std::vector<int> Player::getPlayerNumbers() {
    return m_playerNumbers;
}

void Player::printPlayerNumbers() {
    std::cout << std::endl;
    std::cout << "Player Picks: ";
    std::sort(m_playerNumbers.begin(), m_playerNumbers.end());
    for (auto i:m_playerNumbers) {
        std::cout << i << " ";
    }
}

void Player::clearPlayerNumbers() {
    m_playerNumbers.clear();
}