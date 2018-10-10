// Name:  Kenneth Yue
// Seneca Student ID: 127932176
// Seneca email:  kyue3@myseneca.ca
// Date of completion: Oct 08, 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include <cmath>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

    std::cout << "Command Line: ";
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << ' ';
    std::cout << std::endl;

    if (argc == 1) {
        std::cerr << "\n*** Insufficient number of arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 1;
    }
    else if (argc != 2) {
        std::cerr << "\n*** Too many arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 2;
    }
        
    // student portion
    auto letter = [](double grade) -> const char* {
        round(grade);

        return  grade >= 90 ? getLtr(Letter::ap) :
                grade >= 80 ? getLtr(Letter::a)  :
                grade >= 75 ? getLtr(Letter::bp) :
                grade >= 70 ? getLtr(Letter::b)  : 
                grade >= 65 ? getLtr(Letter::cp) :
                grade >= 60 ? getLtr(Letter::c)  :
                grade >= 55 ? getLtr(Letter::dp) :
                grade >= 50 ? getLtr(Letter::d)  :
                getLtr(Letter::f);
    };

    try {
        Grades grades(argv[1]);
        grades.displayGrades(std::cout, letter);
    } catch (const char* err) {
        std::cerr << std::endl << "*** Aborted! ***" << std::endl
        <<  "File \"" << err << "\" could not be read, or does not exist" 
        << std::endl;
        return 3;
    }
    // end of student portion

    return 0;
}