// encrypt using OpenSSL EVP
const char *encryptString(const char *inputString) {
    // Initialize the library
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    // Create context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_init(ctx);

    // Initialize the encryption operation
    EVP_CIPHER_CTX_set_padding(ctx, 1);
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, NULL, NULL);

    // Encrypt the data
    int len = strlen(inputString);
    int ciphertext_len = len + EVP_CIPHER_CTX_block_size(ctx);
    unsigned char *ciphertext = (unsigned char *)malloc(ciphertext_len);
    EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, (unsigned char *)inputString, len);

    // Finalize the encryption
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len);

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    EVP_cleanup();
    ERR_free_strings();

    return ciphertext;
}

// decrypt using OpenSSL EVP
const char *decryptString(const char *ciphertext) {
    // Initialize the library
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    // Create context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_init(ctx);

    // Initialize the decryption operation
    EVP_CIPHER_CTX_set_padding(ctx, 1);
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, NULL, NULL);

    // Decrypt the data
    int len = strlen(ciphertext);
    int plaintext_len = len + EVP_CIPHER_CTX_block_size(ctx);
    unsigned char *plaintext = (unsigned char *)malloc(plaintext_len);
    EVP_DecryptUpdate(ctx, plaintext, &plaintext_len, (unsigned char *)ciphertext, len);

    // Finalize the decryption
    EVP_DecryptFinal_ex(ctx, plaintext + plaintext_len, &plaintext_len);

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    EVP_cleanup();
    ERR_free_strings();

    return plaintext;
}

void main() {
    char *password[MAXLEN];
    printf("Enter password: ");
    scanf("%s", password);
    const char *encryptedPassword = encryptString(password);
    printf("Encrypted password: %s\n", encryptedPassword);
    const char *decryptedPassword = decryptString(encryptedPassword);
    printf("Decrypted password: %s\n", decryptedPassword);
}