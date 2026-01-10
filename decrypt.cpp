#include "encryption.h"
#include "utils.h"        
#include <iostream>
using namespace std;


int main() {
    initSBox();            
    string encrypted = fromHex("57d4c78e565383398cba");
    string key = fromHex("5936561cb29d5ef67b518b927c220e9a");
    string decrypted = decryptData(encrypted, key);
    cout << "Decrypted Data: " << decrypted << endl;
    return 0;
}