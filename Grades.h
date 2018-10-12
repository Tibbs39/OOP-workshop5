// Name:  Kenneth Yue
// Seneca Student ID: 127932176
// Seneca email:  kyue3@myseneca.ca
// Date of completion: Oct 08, 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#include <iostream>
#include <iomanip>

#ifndef SICT_GRADES_H
#define SICT_GRADES_H

namespace sict {

    class Grades {
        char* file;
        unsigned int* stuNum;
        double* stuGrade;
        size_t cnt;

        // keep move and copy private
        // copy constructor 
        Grades(Grades&);
        // copy operator
        Grades& operator=(Grades&);
        // move constructor
        Grades(Grades&&);
        // move operator
        Grades& operator=(Grades&&);

        public:
            // constructor
            Grades(const char*);
            // destructor
            ~Grades();

        template <typename T>
        void displayGrades(std::ostream& os, T func) const {
            for (int i = 0; i < cnt; ++i) {
                std::cout << std::setw(10) << stuNum[i] 
                    << std::setw(6) << std::fixed << std::setprecision(2) 
                    << stuGrade[i] << std::setw(4) << func(stuGrade[i])
                    << std::endl;
            }
        }
    };
} // namespace sict

#endif //SICT_GRADES_H