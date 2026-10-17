#include <algorithm>
#include <iostream>
#include <vector>
#include "Game.h"

Game::Game() { //This is abstraction for the class Game and the code below that and in other parts of the program.
    m_keno; //These three (m_keno, m_player and m_matches don't seen to be necessary here,
    m_player; // but leaving them in doesn't seem to adversely affect the program either.
    m_matches; // I have tested it with and without them, but ultimately decided to leave them in.

    playGame(); // This is what allows the entire program to run, using the .cpps and headers of all the
                // other parts (KenoNumbers and Player).
                // I am pretty sure this is both encapsulation and abstraction.

    //Neither of the two commented code below helped and actually caused errors at the end of the program running.
    //printMatches(m_player.getPlayerNumbers(), m_keno.getKenoNumbers());
    //displayResults();
    //I decided to comment them out, rather than erase them, in case there was a use for them I missed or needed later.
}
// Abstraction
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
    else { //I added this message in when no numbers where matched. It looked very empty and felt like there was less feedback to the user.
        std::cout << "None of the numbers.";
    }
}
// Abstraction
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
// Abstraction and Encapsulation
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