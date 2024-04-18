#include <stdio.h>
#include <string.h>

#define MAXLEN 100

int main() {
    FILE *file;
    char buf1[MAXLEN];
    char buf2[MAXLEN];

    // Open the file for reading
    file = fopen("filename.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Read up to MAXLEN bytes from the file into buf1
    fgets(buf1, MAXLEN, file);

    // Copy the string from buf1 into buf2
    strcpy(buf2, buf1);

    // Close the file
    fclose(file);

    // Print the contents of buf2
    printf("buf2: %s\n", buf2);

    return 0;
}