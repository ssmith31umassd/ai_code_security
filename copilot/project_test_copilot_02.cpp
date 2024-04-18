#include <iostream>

int main() {
    const int MAX_SIZE = 100;
    char input[MAX_SIZE];

    std::cout << "Enter a string: ";
    std::cin >> input;

    std::cout << "You entered: " << input << std::endl;

    return 0;
}