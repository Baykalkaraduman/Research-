#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::ifstream in_file;      // First we generate in file stream object
    std::string line;           // This will help us read the txt.
    int num;
    double total;

    in_file.open("/home/ekaradum/Research/03_Programming/CPP/16_I-O_Streams/05_Reading_Files/00_Reading_txt/text.txt");   // Here we initialize the stream object 
    // In some IDE's you can use "text.txt" and for some you need "../text.txt" because debugger is one directory above
    // open("This part is IDE and Operating-system spesific") in Windows "C://dir//dir1//" or in Unix, Mac, Windows just use \ to seperate 
    // in Windows "C:/dir/test.txt" is meaningless because compiler reades / as a character thats why we use //
    // Using C: or D: is not logical since the program becomes too computer spesific 
    // it is better to reference the location from the file that main is located or just get it from the user run-time

    // if(!in_file.is_open()) {} // This one works but longer
    if(!in_file) {               // Checking if the file is succsesfully opened or not
        std::cerr << "Problem opening the file" << std::endl;       // Error message 
        return 1;                                                   // return anything other than 0 because it means that program runned succssesfully
        // std::exit(1);                                            // Exit function can be used, it closes certain things and destroy the static variables etc. 
    }
    // The file is reached:
    std::cout << "The file is good to go\n" << std::endl;

    // We are accessing the file and extract the txt and assign it to the line:
    in_file >> line >> num >> total;
    std::cout << line << std::endl;     // Displaying the txt using string line on terminal.
    std::cout << num << std::endl;     // Displaying the txt using int num on terminal.
    std::cout << total << std::endl;     // Displaying the txt using double total on terminal.
    // As long as there is a blank/white space between objects compiler can easly read the txt.

    in_file.close();        // Never forget to close the file you opened

    return 0;
}