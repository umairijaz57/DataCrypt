#include <iostream>
#include "encryption.h"
#include "utils.h"
using namespace std;

int main() {
    string encryptedHex = "4612994939512fa3f5f8345885"; 
    string keyHex = "4e2c726fb51e657e179182071cdbd5b5";
    
    string encrypted = fromHex(encryptedHex);
    string key = fromHex(keyHex);
    
    string decrypted = decryptData(encrypted, key);
    
    cout << "Decrypted: " << decrypted << "\n";
    
    return 0;
}