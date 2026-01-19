#ifndef CRYPTO_ENGINE_H
#define CRYPTO_ENGINE_H

#include <string>
using namespace std;

const int ROUNDS = 57;
extern unsigned char sbox[256];

string encryptData(const string &text, const string &key);
string decryptData(const string &encText, const string &key);

#endif
