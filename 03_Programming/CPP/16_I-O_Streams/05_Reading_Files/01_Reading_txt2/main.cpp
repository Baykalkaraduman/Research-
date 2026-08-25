#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main() {

    std::ifstream in_file;
    std::string line;
    int num;
    double total;

    in_file.open("/home/ekaradum/Research/03_Programming/CPP/16_I-O_Streams/05_Reading_Files/01_Reading_txt2/test.txt");

    if(!in_file) {
        std::cerr << "Problem opening the file" << std::endl;
        return 1;
    }

    while(!in_file.eof()) {     // eof() is a function that checks whether we reached the end-of-the-file.

    // We can acctually integrate ln:20 and ln:26 like this:
    // while(in_file >> line >> num >> total)

        // while we are not at the end of the file:
        in_file >> line >> num >> total;    // Reading three items then display them at the below lines. When it finishes. It loops all over again.
        std::cout << std::setw(10) << std::left << line // setw makes the output more beatiful to eyes.
                << std::setw(10) << num
                << std::setw(10) << total
                << std::endl;
    }
    in_file.close();
    return 0;
}