#ifndef CRYPTO_ENGINE_H
#define CRYPTO_ENGINE_H

#include <string>
using namespace std;

const int ROUNDS = 5;
extern unsigned char sbox[256];

void initSBox();
string encryptData(const string &text, const string &key);

#endif
