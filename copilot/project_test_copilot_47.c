#include <stdio.h>
#include <string.h>

void copySubstring(char* source, char* destination) {
    char* commaPosition = strchr(source, ',');
    if (commaPosition != NULL) {
        strcpy(destination, commaPosition);
    }
}

int main() {
    char sourceString[100];
    char destinationString[100];

    printf("Enter a string: ");
    fgets(sourceString, sizeof(sourceString), stdin);

    copySubstring(sourceString, destinationString);

    printf("Substring after the first comma: %s\n", destinationString);

    return 0;
}