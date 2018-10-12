// Name:  Kenneth Yue
// Seneca Student ID: 127932176
// Seneca email:  kyue3@myseneca.ca
// Date of completion: Oct 08, 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#include <iostream>
#include <fstream>
#include <cstring>
#include "Grades.h"

using namespace sict;

Grades::Grades(const char* fileName) {
    // define cnt
    cnt = 0;
    
    if (fileName) { // check for nullptr
        std::ifstream fin(fileName); // open file
        if (fin.fail()) // check if file exists
            throw fileName;
        
        // create char array and copy file name
        file = new char[strlen(fileName)+1];
        strcpy(file,fileName);

        // count number of lines
        char line[40];
        while (!fin.eof()) {
            fin.getline(line, 40);
            if (strlen(line) > 1) // to account for blank lines
                ++cnt;
        }

        // go back to beginning of file
        fin.clear();
        fin.seekg(0,fin.beg);

        // create new arrays
        stuNum = new unsigned int [cnt];
        stuGrade = new double [cnt];

        // copy contents of file into array.
        for (size_t i = 0; i < cnt; ++i)
            // to account for blank lines
            if (fin.peek() != '\n' || fin.peek() != '\r') {
                fin >> stuNum[i] >> stuGrade[i];
            } else {
                fin.ignore();
            }
        
        fin.close();
    }
}

Grades::~Grades() {
    delete [] file;
    delete [] stuNum;
    delete [] stuGrade;
}