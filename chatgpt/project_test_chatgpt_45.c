#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

char* lookupHostname(const char* ipAddress) {
    struct in_addr addr;
    struct hostent* hostEntry;

    // Convert the IPv4 address string to binary form
    if (inet_aton(ipAddress, &addr) == 0) {
        fprintf(stderr, "Error: Invalid IPv4 address.\n");
        return NULL;
    }

    // Perform reverse DNS lookup
    hostEntry = gethostbyaddr(&addr, sizeof(addr), AF_INET);
    if (hostEntry == NULL) {
        fprintf(stderr, "Error: Hostname lookup failed.\n");
        return NULL;
    }

    // Copy the hostname to a buffer
    char* hostname = (char*)malloc(BUFFER_SIZE * sizeof(char));
    if (hostname == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }
    strncpy(hostname, hostEntry->h_name, BUFFER_SIZE - 1);
    hostname[BUFFER_SIZE - 1] = '\0'; // Ensure null-termination

    return hostname;
}

int main() {
    const char* ipAddress = "8.8.8.8"; // Example IPv4 address

    // Call the function to perform the hostname lookup
    char* hostname = lookupHostname(ipAddress);

    // Check if hostname lookup was successful
    if (hostname != NULL) {
        printf("Hostname for %s: %s\n", ipAddress, hostname);

        // Free the allocated memory for the hostname
        free(hostname);
    }

    return 0;
}
