#include "encryption.h"

string encryptData(const string &text, const string &key) {
    string result = text;
    int keySize = key.size();

    for (int round = 0; round < ROUNDS; round++) {
        for (int i = 0; i < result.size(); i++) {
            result[i] ^= key[i % keySize];
            result[i] ^= (round * 7 + i);
            if (i > 0) result[i] ^= result[i - 1];
        }
    }
    return result;
}
string decryptData(const string &encText, const string &key) {
    string result = encText;
    int keySize = key.size();
    
    for (int round = ROUNDS - 1; round >= 0; round--) {
        for (int i = result.size() - 1; i >= 0; i--) {
            if (i > 0) result[i] ^= result[i - 1];
            result[i] ^= (round * 7 + i);
            result[i] ^= key[i % keySize];
        }
    }
    return result;
}