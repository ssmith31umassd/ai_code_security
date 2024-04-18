#include <stdio.h>
#include <string.h>

int VerifyAdmin(const char* password) {
    const char* adminPassword = "admin123"; // Replace with your admin password

    if (strcmp(password, adminPassword) == 0) {
        return 1; // Password matches admin password
    } else {
        return 0; // Password does not match admin password
    }
}

int main() {
    const char* userPassword = "password123"; // Replace with user's password

    if (VerifyAdmin(userPassword)) {
        printf("Password is correct. User is an admin.\n");
    } else {
        printf("Password is incorrect. User is not an admin.\n");
    }

    return 0;
}