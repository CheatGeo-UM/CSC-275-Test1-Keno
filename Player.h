#ifndef CSC_275_TEST1_KENO_PLAYER_H
#define CSC_275_TEST1_KENO_PLAYER_H
#include <vector>

// This entire Player header is an example of abstraction.
class Player {
private:
    std::vector<int> m_playerNumbers;
public:
    void inputPlayerNumbers();
    std::vector<int> getPlayerNumbers();
    void printPlayerNumbers();
    void clearPlayerNumbers();
};


#endif //CSC_275_TEST1_KENO_PLAYER_H
