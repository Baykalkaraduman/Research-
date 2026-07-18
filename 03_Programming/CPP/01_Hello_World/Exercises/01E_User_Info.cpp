#include <iostream>

int main () {

    int age {};
    std::cout << "Hello, Please Enter Your Age: ";
    std::cin >> age;
    int height {};
    std::cout << "Please Enter Your Height in cm: ";
    std::cin >> height;
    int weight {};
    std::cout << "Please Enter Your Mass in kg: ";
    std::cin >> weight;
    double num1 {};
    double num2 {};
    std::cout << "Now Enter Two Number: ";
    std::cin >> num1 >> num2;
    std::cout << "Dear User, you are at age " << age << " with " << height << " cm of height and " << weight << " kg of mass " << std::endl;
    std::cout << "The numbers you have choosed were " << num1 << " and " << num2 << std::endl;
    return 0;
}