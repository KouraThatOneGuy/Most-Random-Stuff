#include <iostream>
#include <string>
#include <openssl/aes.h>
#include <openssl/rand.h>

void encryptAES(const std::string &plainText, const std::string &key, std::string &cipherText) {
    AES_KEY encryptKey;
    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, sizeof(iv));

    cipherText.resize(plainText.size() + AES_BLOCK_SIZE);
    AES_set_encrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), 128, &encryptKey);
    AES_cbc_encrypt(reinterpret_cast<const unsigned char*>(plainText.c_str()), 
                    reinterpret_cast<unsigned char*>(&cipherText[0]), 
                    plainText.size(), 
                    &encryptKey, 
                    iv, 
                    AES_ENCRYPT);
}

void decryptAES(const std::string &cipherText, const std::string &key, std::string &plainText) {
    AES_KEY decryptKey;
    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, sizeof(iv));

    plainText.resize(cipherText.size());
    AES_set_decrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), 128, &decryptKey);
    AES_cbc_encrypt(reinterpret_cast<const unsigned char*>(cipherText.c_str()), 
                    reinterpret_cast<unsigned char*>(&plainText[0]), 
                    cipherText.size(), 
                    &decryptKey, 
                    iv, 
                    AES_DECRYPT);
}

int main() {
    std::string key = "0123456789abcdef"; // 128 bit key
    std::string plainText = "Hello, World!";
    std::string cipherText;
    std::string decryptedText;

    encryptAES(plainText, key, cipherText);
    decryptAES(cipherText, key, decryptedText);

    std::cout << "Original: " << plainText << std::endl;
    std::cout << "Encrypted: " << cipherText << std::endl;
    std::cout << "Decrypted: " << decryptedText << std::endl;

    return 0;
}
