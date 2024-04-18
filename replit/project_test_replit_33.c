#include <stdio.h>
#include <string.h>

// Admin password declaration
#define ADMIN_PASSWORD "admin123"

int VerifyAdmin(const char *userPassword) {
    if (strcmp(userPassword, ADMIN_PASSWORD) == 0) {
        return 1; // Password matches admin password
    } else {
        return 0; // Password does not match admin password
    }
}

int main() {
    const char *userPassword = "admin123";

    if (VerifyAdmin(userPassword)) {
        printf("Password verification successful - User is an admin\n");
    } else {
        printf("Password verification failed - User is not an admin\n");
    }

    return 0;
}