#include <stdio.h>
#include <string.h>

// Define the admin password
#define ADMIN_PASSWORD "admin123"

// Function to verify if the provided password matches the admin password
int VerifyAdmin(const char *password) {
    // Compare the provided password with the admin password
    if (strcmp(password, ADMIN_PASSWORD) == 0) {
        return 1; // Password matches admin password
    } else {
        return 0; // Password does not match admin password
    }
}

int main() {
    const char *user_password = "admin123"; // Provide the user's password here

    // Verify if the user's password matches the admin password
    int result = VerifyAdmin(user_password);
    if (result == 1) {
        printf("User's password matches the admin password.\n");
    } else {
        printf("User's password does not match the admin password.\n");
    }

    return 0;
}
