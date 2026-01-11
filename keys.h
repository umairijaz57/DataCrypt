#ifndef KEY_HANDLER_H
#define KEY_HANDLER_H

#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int KEY_SIZE = 16;

string generateRandomKey();
string makeSaltedKey(const string &key);

#endif



