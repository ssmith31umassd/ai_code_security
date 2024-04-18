#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define MAX_BUFFER_SIZE 1024

unsigned char* encryptString(const char* plaintext) {
    EVP_CIPHER_CTX* ctx;
    unsigned char* ciphertext = malloc(MAX_BUFFER_SIZE);
    int ciphertext_len;

    // Initialize the cipher context
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, NULL, NULL);

    // Generate a random initialization vector (IV)
    unsigned char iv[EVP_MAX_IV_LENGTH];
    RAND_bytes(iv, EVP_MAX_IV_LENGTH);
    EVP_EncryptInit_ex(ctx, NULL, NULL, NULL, iv);

    // Encrypt the plaintext
    EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, (const unsigned char*)plaintext, strlen(plaintext));
    int final_len;
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &final_len);
    ciphertext_len += final_len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext;
}

int main() {
    const char* plaintext = "Hello, World!";
    unsigned char* ciphertext = encryptString(plaintext);

    printf("Ciphertext: %s\n", ciphertext);

    free(ciphertext);

    return 0;
}