//
// Created by Tom Biskupski on 11.06.20.
//

#ifndef PROGPROJEKT_PRUEFUNG_H
#define PROGPROJEKT_PRUEFUNG_H

#include <string>
#include <vector>
#include "Pruefer.h"

using namespace std;


class Pruefung {
public:
    Pruefung(int pversion, int pnr, int dauer, Pruefer p1, Pruefer p2, string stg, string pruefungsname);
    friend ostream &operator <<(std::ostream &stream, const Pruefung &prfng);
    int getPversion() const;
    int getPnr() const;
    vector<int> matrikelnrListe;

private:

    int pversion;
    int pnr;
    int dauer;
    Pruefer pruefer1;
    Pruefer pruefer2;
    string stg;
    string pruefungsname;


};


#endif //PROGPROJEKT_PRUEFUNG_H
