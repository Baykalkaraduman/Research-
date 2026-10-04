#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main() {


    std::vector<std::string> cards {"spades", "hearts", "dimonds", "clubs"};

    for(size_t i{0}; i < cards.size(); ++i) {
        char abb = static_cast<char>(std::toupper(static_cast<unsigned char>(cards[i][0])));
        std::cout << abb << " = " << cards[0] << std::endl;
    }

    return 0;
}