#include <iostream>
#include "encryption.h"
#include "keys.h"
#include "filehandler.h"
using namespace std;

int main() {
    cout << "\n========================================\n";
    cout << "  Student Data Encryption System\n";
    cout << "========================================\n\n";
    
    srand(time(0));
    initSBox();

    string outputDir = "student_data";
    if (!createOutputDirectory(outputDir)) {
        cerr << "Error: Directory create nahi hui!\n";
        return 1;
    }

    vector<Student> students = readStudentsFile("students.txt");
    if (students.empty()) {
        cout << "Error: students.txt mein koi data nahi!\n";
        return 1;
    }

    int count = 0;
    for (const auto &student : students) {
        string key = generateRandomKey();
        string finalKey = makeSaltedKey(key);

        string encRoll = encryptData(student.roll, finalKey);
        string encName = encryptData(student.name, finalKey);
        string encProgram = encryptData(student.program, finalKey);
        string encEmail = encryptData(student.email, finalKey);

        if (saveEncryptedStudent(student, encRoll, encName, encProgram, encEmail, outputDir)) {
            appendKeyToFile(student.roll, finalKey);
            cout << "[" << ++count << "] " << student.roll << " - " << student.name << endl;
        } else {
            cerr << "Error: " << student.roll << " save nahi hua!\n";
        }
    }

    cout << "\n========================================\n";
    cout << "  Encryption Complete!\n";
    cout << "  Total: " << count << " students\n";
    cout << "  Output: " << outputDir << "/\n";
    cout << "  Keys: keys.txt\n";
    cout << "========================================\n\n";

    string rrr = decryptData("4617ae97fe6542b4e85a", "94a49095d50128c82091ff5e729002db");
    cout << "Decrypted Sample Name: " << rrr << endl;

    return 0;
}
