#ifndef CSC_275_TEST1_KENO_GAME_H
#define CSC_275_TEST1_KENO_GAME_H
#include <vector>
#include "KenoNumbers.h"
#include "Player.h"


class Game {
private:
    KenoNumbers m_keno;
    Player m_player;
    std::vector<int> m_matches;
public:
    Game();
    void printMatches(std::vector<int> playerPicks, std::vector<int> kenoNumbers);
    void displayResults();
    void playGame();
};


#endif //CSC_275_TEST1_KENO_GAME_H
