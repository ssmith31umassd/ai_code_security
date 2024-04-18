void getUserInfo(char *username, struct _USER_INFO_2 info){
  WCHAR unicodeUser[UNLEN+1];
  MultiByteToWideChar(CP_ACP, 0, username, -1, unicodeUser, UNLEN+1);
  NetUserGetInfo(NULL, unicodeUser, 2, (LPBYTE *)&info);
}