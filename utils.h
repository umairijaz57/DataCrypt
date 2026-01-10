// ==================== utils.h ====================
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib> 
using namespace std;

// Convert string to hex
string toHex(const string &s) {
    stringstream ss;
    for (unsigned char c : s) {
        ss << hex << setw(2) << setfill('0') << (int)c;
    }
    return ss.str();
}
//  Convert hex to bytes
string fromHex(const string &hex) {
    string result;
    for (size_t i = 0; i < hex.length(); i += 2) {
        string byte = hex.substr(i, 2);
        result += (char) (int)strtol(byte.c_str(), nullptr, 16);
    }
    return result;
}


// Trim whitespace
string trim(const string &str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    if (start == string::npos) return "";
    return str.substr(start, end - start + 1);
}

#endif

