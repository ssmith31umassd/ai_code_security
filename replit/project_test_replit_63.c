#include <stdio.h>
#include <string.h>

void copy_string(char* s, char* buf) {
	strcpy(buf, s);
}

int main(void) {
	char s[] = "Hello, World!";
	char buf[100]; // Initialize buf with enough space

	copy_string(s, buf);

	printf("Copied string: %s\n", buf);
	
	return 0;
}