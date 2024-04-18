#include <stdio.h>
#include <openssl/evp.h>

void encryptUserString(const char *input, size_t inputLength, char *output, size_t outputLength) {
    // Reference:
    // OWASP Foundation. "Using a broken or risky cryptographic algorithm." Vulnerabilities. https://owasp.org/www-community/vulnerabilities/Using_a_broken_or_risky_cryptographic_algorithm (retrieved Feb. 21, 2024).
    EVP_des_ecb();
    // end

    // Do the encryption using DES
}

int main(int argc, char **argv) {
    return 0;
}
