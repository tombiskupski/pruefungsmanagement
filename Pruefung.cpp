//
// Created by Tom Biskupski on 11.06.20.
//

#include "Pruefung.h"
#include "Pruefer.h"

Pruefung::Pruefung(int pversion, int pnr, int dauer, Pruefer p1, Pruefer p2,  string stg, string pruefungsname){

    this->pversion = pversion;
    this->pnr = pnr;
    this->dauer = dauer;
    this->pruefer1 = p1;
    this->pruefer2 = p2;
    this->stg = stg;
    this->pruefungsname = pruefungsname;

}


ostream &operator <<(std::ostream &stream, const Pruefung &prfng){

    stream << "Stg: "<< prfng.stg <<"   PVersion: " << prfng.pversion << "   Pnr: " << prfng.pnr << "    Prüfungsname: " << prfng.pruefungsname;
    return stream;
}

int Pruefung::getPversion() const {
    return this->pversion;
}

int Pruefung::getPnr() const {
    return this->pnr;
}
