//
// Created by Tom Biskupski on 11.06.20.
//

#ifndef PROGPROJEKT_PRUEFER_H
#define PROGPROJEKT_PRUEFER_H


#include <istream>
#include <ostream>
#include <iostream>
using namespace std;

class Pruefer {
public:
    Pruefer(int prueferID);
    Pruefer();
    friend ostream &operator <<(ostream &stream, const Pruefer &prf);
    friend istream &operator >>(istream &stream, const Pruefer &prf);
    bool operator > (const Pruefer& str) const;
    int getPrueferID() const;
    int getPrueferFromID(int id);

private:
    int prueferID;
    int cooldown;



};


#endif //PROGPROJEKT_PRUEFER_H
