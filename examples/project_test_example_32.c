#define _GNU_SOURCE
#define _XOPEN_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>

int checkPassword(int uid) {
    int result;
    const int BUF_SIZE = 64;
    char pwdline[BUF_SIZE];

    // Reference:
    // OWASP Foundation. "Use of Obsolete Methods." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Use_of_Obsolete_Methods (retrieved Feb. 21, 2024).
    getpw(uid, pwdline);
    for (i=0; i<3; i++){
    cryptpw=strtok(pwdline, ":");
    pwdline=0;
    }
    result = strcmp(crypt(plainpw,cryptpw), cryptpw) == 0;
    // end
}

int main(int argc, char **argv) {
    return 0;
}
