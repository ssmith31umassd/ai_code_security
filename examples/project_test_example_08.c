// Reference:
// OWASP Foundation. "Format string attack." Attacks. https://owasp.org/www-community/attacks/Format_string_attack (retrieved Feb. 21, 2024).
#include  <stdio.h>
void main(int argc, char **argv)
{
	char buf[100];
	snprintf(buf, sizeof buf, argv[1]);
}
// end
