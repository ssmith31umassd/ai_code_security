#include <iostream>
#include <string>

int main() {
    char name[50];
    
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    std::cout << "Hello, " << name << "!" << std::endl;

    return 0;
}