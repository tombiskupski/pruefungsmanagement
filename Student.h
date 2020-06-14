//
// Created by Tom Biskupski on 11.06.20.
//

#ifndef PROGPROJEKT_STUDENT_H
#define PROGPROJEKT_STUDENT_H

#include <vector>
using namespace std;

class Student {
public:
    Student(int marikelnr);

private:
    int marikelnr;
    int cooldown;
    bool bereit;
    //vector<int> angPruefung;
};


#endif //PROGPROJEKT_STUDENT_H
