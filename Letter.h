// Name:  Kenneth Yue
// Seneca Student ID: 127932176
// Seneca email:  kyue3@myseneca.ca
// Date of completion: Oct 08, 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#ifndef SICT_LETTER_H
#define SICT_LETTER_H

namespace sict {

    enum class Letter {
        ap,
        a,
        bp,
        b,
        cp,
        c,
        dp,
        d,
        f
    }; // letter grades, p signifies +, i.e ap = A+

    // converts Letter to string
    template<typename L>
    const char* convertLtr(const L& letter) {
        switch (letter) {
            case L::ap : return "A+  ";
            case L::a  : return "A   ";
            case L::bp : return "B+  ";
            case L::b  : return "B   ";
            case L::cp : return "C+  ";
            case L::c  : return "C   ";
            case L::dp : return "D+  ";
            case L::d  : return "D   ";
            case L::f  : return "F   ";
            default    : return "Invalid";
        }
    }

} //namespace sict
#endif // SICT_LETTER_H