#include <iostream>

int main() {
    const int SIZE = 100; // Define the size of the char array
    char input[SIZE];     // Declare the char array

    std::cout << "Enter a string: ";
    std::cin >> input;    // Read input into the char array

    std::cout << "You entered: " << input << std::endl;

    return 0;
}
