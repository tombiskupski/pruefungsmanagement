//
// Created by Tom Biskupski on 11.06.20.
//

#include "Student.h"

Student::Student(int marikelnr) {
    this->marikelnr = marikelnr;
    cooldown = 0 ;
    bereit = true;
}