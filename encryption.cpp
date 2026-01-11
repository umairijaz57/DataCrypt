#include "encryption.h"

unsigned char sbox[256];

void initSBox() {
    for (int i = 0; i < 256; i++) {
        sbox[i] = ((i * 53) ^ 0x63) % 256;
    }
}

string encryptData(const string &text, const string &key) {
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