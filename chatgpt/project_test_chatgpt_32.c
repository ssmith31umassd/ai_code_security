#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include <shadow.h>

// Function to check if the plaintext password matches the encrypted password
int checkPassword(const char *username, const char *plaintext_password) {
    struct spwd *shadow_entry;
    char *encrypted_password;

    // Get the shadow entry for the user
    shadow_entry = getspnam(username);
    if (shadow_entry == NULL) {
        perror("Error getting shadow entry");
        return -1; // Error getting shadow entry
    }

    // Get the encrypted password from the shadow entry
    encrypted_password = shadow_entry->sp_pwdp;

    // Encrypt the plaintext password and compare with the encrypted password
    if (strcmp(crypt(plaintext_password, encrypted_password), encrypted_password) == 0) {
        return 0; // Passwords match
    } else {
        return 1; // Passwords do not match
    }
}

int main() {
    const char *username = "example_user"; // Provide the username here
    const char *plaintext_password = "example_password"; // Provide the plaintext password here

    // Check if the plaintext password matches the encrypted password for the user
    int result = checkPassword(username, plaintext_password);
    if (result == 0) {
        printf("Password matched!\n");
    } else if (result == 1) {
        printf("Password did not match.\n");
    } else {
        printf("Error checking password.\n");
    }

    return 0;
}
