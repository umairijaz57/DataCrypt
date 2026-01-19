#include "filehandler.h"
#include <fstream>
#include <sstream>
#include <direct.h>
#include <iostream>
#include "utils.h"
#include <cerrno>
using namespace std;

bool createOutputDirectory(const string &dirName) {
    return _mkdir(dirName.c_str()) == 0 || errno == EEXIST;
}

vector<Student> readStudentsFile(const string &filename) {
    vector<Student> students;
    ifstream in(filename);
    if (!in.is_open()) {
        cerr << "Error: " << filename << " file nahi mili!\n";
        return students;
    }

    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Student s;
        getline(ss, s.roll, ',');
        getline(ss, s.name, ',');
        getline(ss, s.program, ',');
        getline(ss, s.email, ',');
        if (!s.roll.empty()) students.push_back(s);
    }
    in.close();
    return students;
}

bool saveEncryptedStudent(const Student &s,
                          const string &encRoll,
                          const string &encName,
                          const string &encProgram,
                          const string &encEmail,
                          const string &outputDir) {
    string filename = outputDir + "/student_" + s.roll + ".txt";
    ofstream out(filename);
    if (!out.is_open()) return false;

    out << "Roll: " << toHex(encRoll) << "\n";
    out << "Name: " << toHex(encName) << "\n";
    out << "Program: " << toHex(encProgram) << "\n";
    out << "Email: " << toHex(encEmail) << "\n";

    out.close();
    return true;
}

bool appendKeyToFile(const string &roll, const string &key) {
    ofstream out("keys.txt", ios::app);
    if (!out.is_open()) return false;
    out << roll << " " << toHex(key) << "\n";
    out.close();
    return true;
}
bool appendKeyToFileSalted(const string &roll, const string &key) {
    ofstream out("keysSalted.txt", ios::app);
    if (!out.is_open()) return false;
    out << roll << " " << toHex(key) << "\n";
    out.close();
    return true;
}


