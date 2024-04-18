#include  <stdio.h>
void main(int argc, char **argv)
{
	char buf[100];
    const char *itemToCopy = argv[1];
    strcpy(buf, itemToCopy);
    printf("%s\n", buf);
}