#include <algorithm>
#include <iostream>
#include <vector>
#include "Game.h"

Game::Game() {
    m_keno;
    m_player;
    m_matches;
    playGame();
    //printMatches(m_player.getPlayerNumbers(), m_keno.getKenoNumbers());
    //displayResults();
}

void Game::printMatches(std::vector<int> playerPicks, std::vector<int> kenoNumbers) {
    //This runs through the player picks and generated numbers to compare them.
    //It then puts them into m_matches vector.
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 20; j++) {
            if(playerPicks.at(i) == kenoNumbers.at(j)) {
                m_matches.push_back(playerPicks.at(i));
            }
        }
    }
    //This then outputs the matches found above.
    std::cout << std::endl;
    std::cout << "You matched: ";
    std::sort(m_matches.begin(), m_matches.end());
    if (m_matches.size() > 0) {
        for (auto i:m_matches) {
            std::cout << i << " ";
        }
    }
    else {
        std::cout << "None of the numbers.";
    }
}

void Game::displayResults() {
    m_keno.printKenoNumbers();
    m_player.printPlayerNumbers();
    printMatches(m_player.getPlayerNumbers(), m_keno.getKenoNumbers());
    if (m_matches.size() > 0) {
        std::cout<<"\nMatching " << m_matches.size() << " of 20 numbers wins: ";
        switch (m_matches.size()){
            case 10:
                std::cout<<"the GRAND PRIZE of $250,000";
                break;
            case 9:
                std::cout << "$2,500";
                break;
            case 8:
                std::cout<<"$250";
                break;
            case 7:
                std::cout<<"$50";
                break;
            case 6:
                std::cout<<"$10";
                break;
            case 5:
                std::cout<<"$5";
                break;
            default:
                std::cout<<"$0. Sorry, better luck next time.";
        }
    }
    else {
        std::cout << "\n$0. Sorry, you didn't have enough matches.";
    }
}

void Game::playGame() {
        char again = 'y';
        do {
            std::cout << "\nTo play Keno, select 10 unique (no repeats) numbers in the range of 1-80.\n\n";
            std::cout << "Let's Play Keno!\n\n";
            m_player.inputPlayerNumbers();
            m_keno.generateNumbers();
            displayResults();
            m_keno.clearKenoNumbers();
            m_player.clearPlayerNumbers();
            m_matches.clear();
            std::cout << "\n\nPlay another round? (y/n): ";
            std::cin >> again;
        } while (tolower(again) == 'y');
        std::cout << "\nTHANKS FOR PLAYING!!\n";
    }