#include "keys.h"

const string SALT = "HAYAT@101";

string generateRandomKey() {
    string key(KEY_SIZE, 0);
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
    return key;
}

string makeSaltedKey(const string &key) {
    string salted = key;
    for (int i = 0; i < key.size(); i++) {
        salted[i] ^= SALT[i % SALT.size()];
    }
    return salted;
}
