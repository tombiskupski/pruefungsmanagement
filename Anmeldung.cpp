//
// Created by Tom Biskupski on 11.06.20.
//

#include "Anmeldung.h"

Anmeldung::Anmeldung (int matrikelnr, string studiengang, int pversion, int pnr, string pform, string dtxt, int psem){
    this->matrikelnr = matrikelnr;
    this->studiengang = studiengang;
    this->pversion = pversion;
    this->pnr = pnr;
    this->pform = pform;
    this->dtxt = dtxt;
    this->psem = psem;

}


std::ostream &operator <<(std::ostream &stream, const Anmeldung &anm){

    stream << "Matrikelnr: " << anm.matrikelnr << "    Pversion: "<< anm.pversion << "    Pnr: " << anm.pnr <<endl;
    return stream;
}
