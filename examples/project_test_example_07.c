// Reference:
// OWASP Foundation. "Format string attack." Attacks. https://owasp.org/www-community/attacks/Format_string_attack (retrieved Feb. 21, 2024).
#include  <stdio.h> 
void main(int argc, char **argv)
{
	// This line is safe
	printf("%s\n", argv[1]);

	// This line is vulnerable
	printf(argv[1]);
}
// end
