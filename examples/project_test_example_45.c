#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int validate_addr_form(const char *user_supplied_addr) {
    return 0;
}

// Reference:
// MITRE. "CWE-787: Out-of-bounds Write." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/787.html (retrieved Feb. 22, 2024).
void host_lookup(char *user_supplied_addr){
   struct hostent *hp;
   in_addr_t *addr;
   char hostname[64];
   in_addr_t inet_addr(const char *cp);

   /*routine that ensures user_supplied_addr is in the right format for conversion */

   validate_addr_form(user_supplied_addr);
   addr = inet_addr(user_supplied_addr);
   hp = gethostbyaddr( addr, sizeof(struct in_addr), AF_INET);
   strcpy(hostname, hp->h_name);
}
// end

int main(int argc, char **argv) {
    return 0;
}
