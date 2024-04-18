#include <stdio.h>

int main() {
    char name[100]; // Assuming the name will not exceed 100 characters

    // Prompting the user for their name
    printf("Please enter your name: ");
    
    // Reading input from stdin into a char array using gets
    gets(name);

    // Displaying the name entered by the user
    printf("Hello, %s\n", name);

    return 0;
}
