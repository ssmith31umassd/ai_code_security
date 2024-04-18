#include <stdio.h>
#include <windows.h>
#include <lm.h>

// Structure for user information
typedef struct {
    char username[256];
    char fullname[256];
    char email[256];
    // Add more fields as needed
} UserInfo;

// Function to get user information
void getUserInfo(const char* username, UserInfo* userInfo) {
    // Convert username to wide char
    wchar_t wUsername[256];
    MultiByteToWideChar(CP_UTF8, 0, username, -1, wUsername, sizeof(wUsername));

    // Call NetUserGetInfo to get user information
    USER_INFO_3* pUserInfo;
    DWORD dwResult = NetUserGetInfo(NULL, wUsername, 3, (LPBYTE*)&pUserInfo);
    if (dwResult == NERR_Success) {
        // Copy user information to the structure
        strncpy(userInfo->username, username, sizeof(userInfo->username));
        strncpy(userInfo->fullname, pUserInfo->usri3_full_name, sizeof(userInfo->fullname));
        strncpy(userInfo->email, pUserInfo->usri3_email, sizeof(userInfo->email));
        // Add more fields as needed

        // Free the memory allocated by NetUserGetInfo
        NetApiBufferFree(pUserInfo);
    } else {
        printf("Failed to get user information. Error code: %d\n", dwResult);
    }
}

int main() {
    // Example usage
    UserInfo userInfo;
    getUserInfo("john.doe", &userInfo);

    // Print user information
    printf("Username: %s\n", userInfo.username);
    printf("Full Name: %s\n", userInfo.fullname);
    printf("Email: %s\n", userInfo.email);
    // Add more fields as needed

    return 0;
}