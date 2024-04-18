#include <stdio.h>
#include <Stringapiset.h>
#include <Lmaccess.h>

// Reference:
// OWASP Foundation. "Buffer Overflow." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Buffer_Overflow (retrieved Feb. 21, 2024).
void getUserInfo(char *username, struct _USER_INFO_2 info){
  WCHAR unicodeUser[UNLEN+1];
  MultiByteToWideChar(CP_ACP, 0, username, -1,
                      unicodeUser, sizeof(unicodeUser));
  NetUserGetInfo(NULL, unicodeUser, 2, (LPBYTE *)&info);
}
// end

int main(int argc, char *argv[]) {
    return 0;
}


