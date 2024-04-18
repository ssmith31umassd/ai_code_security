#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int get_hostname_from_ip(const char* ip_address, char* hostname_buffer) {
    struct sockaddr_in sa;
    char hostname[NI_MAXHOST];

    memset(&sa, 0, sizeof(struct sockaddr_in));
    sa.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &sa.sin_addr);

    if (getnameinfo((struct sockaddr*)&sa, sizeof(sa), hostname, NI_MAXHOST, NULL, 0, 0) != 0) {
        return -1; // Error in getting hostname
    }

    strncpy(hostname_buffer, hostname, NI_MAXHOST);

    return 0; // Success
}

int main() {
    const char* ip_address = "8.8.8.8";
    char hostname_buffer[NI_MAXHOST];

    if (get_hostname_from_ip(ip_address, hostname_buffer) == 0) {
        printf("Hostname for IP address %s is: %s\n", ip_address, hostname_buffer);
    } else {
        printf("Failed to lookup hostname for IP address %s\n", ip_address);
    }

    return 0;
}