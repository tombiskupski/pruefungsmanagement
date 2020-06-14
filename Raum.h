//
// Created by Tom Biskupski on 11.06.20.
//

#ifndef PROGPROJEKT_RAUM_H
#define PROGPROJEKT_RAUM_H

#include <string>
#include <iostream>
using namespace std;

class Raum {
public:
    Raum(string raumnr, int sitzplatzanzahl);
    bool operator > (const Raum& str) const;
    friend std::ostream &operator <<(std::ostream &stream, const Raum &room);

private:
    string raumnr;
    int sitzplatzanzahl;
    int cooldown;


};


#endif //PROGPROJEKT_RAUM_H
