#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BUF_SIZE 1024
#define KEY_SIZE 32
#define IV_SIZE 16

unsigned char* encrypt(const char* plaintext, size_t plaintext_len, size_t* ciphertext_len) {
    EVP_CIPHER_CTX *ctx;
    unsigned char *ciphertext_buf;
    int ciphertext_len_tmp;
    
    // Allocate memory for the ciphertext buffer
    ciphertext_buf = (unsigned char *)malloc(plaintext_len + EVP_MAX_BLOCK_LENGTH);
    if (ciphertext_buf == NULL) {
        perror("Memory allocation error");
        return NULL;
    }

    // Initialize the cipher context
    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        perror("Error creating cipher context");
        free(ciphertext_buf);
        return NULL;
    }

    // Initialize the encryption operation
    if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, NULL, NULL)) {
        perror("Error initializing encryption operation");
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext_buf);
        return NULL;
    }

    // Perform the encryption
    if (!EVP_EncryptUpdate(ctx, ciphertext_buf, &ciphertext_len_tmp, (unsigned char *)plaintext, plaintext_len)) {
        perror("Error performing encryption");
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext_buf);
        return NULL;
    }
    *ciphertext_len = ciphertext_len_tmp;

    // Finalize the encryption
    if (!EVP_EncryptFinal_ex(ctx, ciphertext_buf + *ciphertext_len, &ciphertext_len_tmp)) {
        perror("Error finalizing encryption");
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext_buf);
        return NULL;
    }
    *ciphertext_len += ciphertext_len_tmp;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_buf;
}

int main() {
    const char *plaintext = "Hello, world!";
    size_t plaintext_len = strlen(plaintext);
    size_t ciphertext_len;
    unsigned char *ciphertext;

    // Encrypt the plaintext
    ciphertext = encrypt(plaintext, plaintext_len, &ciphertext_len);
    if (ciphertext == NULL) {
        printf("Encryption failed\n");
        return EXIT_FAILURE;
    }

    // Print the encrypted data (in hexadecimal format)
    printf("Encrypted data: ");
    for (size_t i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Free memory
    free(ciphertext);

    return EXIT_SUCCESS;
}
