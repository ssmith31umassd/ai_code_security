#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int getHostnameFromIP(const char* ipAddress, char* hostnameBuffer, size_t bufferSize) {
    struct sockaddr_in sa;
    struct hostent* host;

    // Convert the IP address string to a network address structure
    if (inet_pton(AF_INET, ipAddress, &(sa.sin_addr)) <= 0) {
        return -1; // Invalid IP address
    }

    // Perform the hostname lookup
    host = gethostbyaddr(&(sa.sin_addr), sizeof(struct in_addr), AF_INET);
    if (host == NULL) {
        return -1; // Failed to lookup hostname
    }

    // Copy the hostname to the buffer
    strncpy(hostnameBuffer, host->h_name, bufferSize - 1);
    hostnameBuffer[bufferSize - 1] = '\0'; // Ensure null-termination

    return 0; // Success
}

int main() {
    const char* ipAddress = "192.168.0.1";
    char hostname[256];

    if (getHostnameFromIP(ipAddress, hostname, sizeof(hostname)) == 0) {
        printf("Hostname: %s\n", hostname);
    } else {
        printf("Failed to lookup hostname.\n");
    }

    return 0;
}