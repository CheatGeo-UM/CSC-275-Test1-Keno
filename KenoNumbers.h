#ifndef CSC_275_TEST1_KENO_KENONUMBERS_H
#define CSC_275_TEST1_KENO_KENONUMBERS_H
#include <vector>

// This entire KenoNumbers header is an example of abstraction.
class KenoNumbers {
private:
    std::vector<int> m_kenoNumbers;
public:
    void generateNumbers();
    std::vector<int> getKenoNumbers();
    void printKenoNumbers();
    void clearKenoNumbers();
};


#endif //CSC_275_TEST1_KENO_KENONUMBERS_H
