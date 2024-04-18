#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define AES_256_KEY_SIZE 32
#define AES_BLOCK_SIZE 16

unsigned char* encrypt_string(const char* input, unsigned char* key, unsigned char* iv, int *output_length) {
    EVP_CIPHER_CTX *ctx;
    unsigned char *output = NULL;
    int output_len, final_len;
    
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit(ctx, EVP_aes_256_cbc(), key, iv);
    
    output = (unsigned char*)malloc(strlen(input) + AES_BLOCK_SIZE);
    EVP_EncryptUpdate(ctx, output, &output_len, (unsigned char*)input, strlen(input));
    EVP_EncryptFinal(ctx, output + output_len, &final_len);
    
    *output_length = output_len + final_len;
    
    EVP_CIPHER_CTX_free(ctx);
    
    return output;
}

int main() {
    const char *input_string = "Secret Message";
    unsigned char key[AES_256_KEY_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];
    unsigned char* encrypted_data;
    int encrypted_length;

    // Generate random key and IV
    RAND_bytes(key, AES_256_KEY_SIZE);
    RAND_bytes(iv, AES_BLOCK_SIZE);

    // Encrypt the input string
    encrypted_data = encrypt_string(input_string, key, iv, &encrypted_length);

    // Print the encrypted data
    if (encrypted_data != NULL) {
        printf("Encrypted data: ");
        for (int i = 0; i < encrypted_length; i++) {
            printf("%02x", encrypted_data[i]);
        }
        printf("\n");

        free(encrypted_data);
    } else {
        printf("Encryption failed\n");
    }

    return 0;
}