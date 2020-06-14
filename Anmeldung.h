//
// Created by Tom Biskupski on 11.06.20.
//

#ifndef PROGPROJEKT_ANMELDUNG_H
#define PROGPROJEKT_ANMELDUNG_H

#include <string>
using namespace std;

class Anmeldung {
public:
    Anmeldung (int matrikelnr, string studiengang, int pversion, int pnr, string pform, string dtxt, int psem);
    friend std::ostream &operator <<(std::ostream &stream, const Anmeldung &fract);

  //  mtknr;stg;pversion;pnr;pform;dtxt;psem
  //  163468;AB;141;1020;KL;Klausur;20192

private:

    int matrikelnr;
    string studiengang;
    int pversion;
    int pnr;
    string pform;
    string dtxt;
    int psem;

};

#endif //PROGPROJEKT_ANMELDUNG_H
