#include <stdio.h>
#include <string.h>

#define MAXLEN 100

int main() {
    FILE *file;
    char buf1[MAXLEN];
    char buf2[MAXLEN];

    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    if (fgets(buf1, MAXLEN, file) != NULL) {
        // Copy the string from buf1 to buf2
        strcpy(buf2, buf1);
        printf("String copied from buf1 to buf2: %s\n", buf2);
    } else {
        printf("Error reading from file\n");
    }

    fclose(file);

    return 0;
}