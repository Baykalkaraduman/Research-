#include <iostream>

int main () {
    int year {};
    double GPA {};
    std::cout << "Please enter your year and GPA: ";
    std::cin >> year >> GPA;
    std::cout << "Currently you are on your " << year << "st/nd/rd/th year and your GPA is: " << GPA << std::endl;
    int new_year {};
    double new_GPA {};
    std::cout << "Please enter your up-to-date year and GPA: ";
    std::cin >> new_year >> new_GPA;
    year = new_year;
    GPA = new_GPA;
    std::cout << "Currently you are on your " << year << "st/nd/rd/th year and your GPA is: " << GPA << std::endl;
    return 0;
} // I know the code is inefficent it just shows how to change variables