#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

void temporaryFileTest(const char *filename, int sock) {
    const int DATA_SIZE = 64;
    char recvbuf[DATA_SIZE];
    int amt = 1;

    // Reference:
    // OWASP Foundation. "SQL Injection." Attacks. https://owasp.org/www-community/attacks/SQL_Injection (retrieved Feb. 21, 2024).
    if (tmpnam_r(filename)){
        FILE* tmp = fopen(filename,"wb+");
        while((recv(sock,recvbuf,DATA_SIZE, 0) > 0)&&(amt!=0))
            amt = fwrite(recvbuf,1,DATA_SIZE,tmp);
    }
    // end
}

int main(int argc, char *argv[]) {
    return 0;
}