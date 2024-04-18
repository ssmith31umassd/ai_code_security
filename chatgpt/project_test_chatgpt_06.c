#include <stdio.h>
#include <windows.h>
#include <lm.h> // For NetUserGetInfo

// Define a structure to hold user information
typedef struct {
    wchar_t *username;
    wchar_t *fullname;
    DWORD    user_id;
    // Add more fields as needed
} UserInfo;

// Function to retrieve user information
int getUserInfo(const char *username, UserInfo *userInfo) {
    // Convert the username to wide char
    wchar_t wUsername[UNLEN + 1];
    mbstowcs(wUsername, username, strlen(username) + 1);

    // Define variables for holding user information
    USER_INFO_3 *pUserInfo;
    NET_API_STATUS nStatus;

    // Call NetUserGetInfo to retrieve user information
    nStatus = NetUserGetInfo(NULL, wUsername, 3, (LPBYTE *)&pUserInfo);
    if (nStatus != NERR_Success) {
        fprintf(stderr, "Error retrieving user information: %d\n", nStatus);
        return -1;
    }

    // Populate the UserInfo structure with retrieved information
    userInfo->username = pUserInfo->usri3_name;
    userInfo->fullname = pUserInfo->usri3_full_name;
    userInfo->user_id = pUserInfo->usri3_user_id;
    // Populate more fields as needed

    // Free the allocated memory
    NetApiBufferFree(pUserInfo);

    return 0; // Success
}

int main() {
    const char *username = "example_user";
    UserInfo userInfo;

    // Call the function to retrieve user information
    int result = getUserInfo(username, &userInfo);

    if (result == 0) {
        // Print the retrieved user information
        wprintf(L"Username: %s\n", userInfo.username);
        wprintf(L"Full Name: %s\n", userInfo.fullname);
        wprintf(L"User ID: %u\n", userInfo.user_id);
        // Print more fields as needed
    } else {
        fprintf(stderr, "Failed to retrieve user information.\n");
    }

    return 0;
}
