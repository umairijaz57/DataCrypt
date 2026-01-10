#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>
#include <vector>
using namespace std;

struct Student {
    string roll;
    string name;
    string program;
    string email;
};

bool createOutputDirectory(const string &dirName);
vector<Student> readStudentsFile(const string &filename);
bool saveEncryptedStudent(const Student &student,
                          const string &encRoll,
                          const string &encName,
                          const string &encProgram,
                          const string &encEmail,
                          const string &outputDir);
bool appendKeyToFile(const string &roll, const string &key);

#endif
