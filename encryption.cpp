#include "encryption.h"

unsigned char sbox[256];

void initSBox() {
    for (int i = 0; i < 256; i++) {
        sbox[i] = ((i * 53) ^ 0x63) % 256;
    }
}

string encryptData(string &text, string &key) {
    string result = text;
    int keySize = key.size();

    for (int round = 0; round < ROUNDS; round++) {
        for (size_t i = 0; i < result.size(); i++) {
            result[i] ^= key[i % keySize];
            result[i] = sbox[(unsigned char)result[i]];
            result[i] ^= (round * 7 + i);
            if (i > 0) result[i] ^= result[i - 1];
        }
    }
    return result;
}

string decryptData(string &text, string &key) {
    string result = text;
    int keySize = key.size();

    for (int round = ROUNDS - 1; round >= 0; round--) {
        for (size_t i = result.size(); i-- > 0;) {
            char temp = result[i];
            if (i > 0) temp ^= result[i - 1];
            temp ^= (round * 7 + i);

            for (int j = 0; j < 256; j++) {
                if (sbox[j] == (unsigned char)temp) {
                    temp = j;
                    break;
                }
            }

            temp ^= key[i % keySize];
            result[i] = temp;
        }
    }
    return result;
}
