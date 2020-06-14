//
// Created by Tom Biskupski on 11.06.20.
//

#include "Raum.h"

Raum::Raum(string raumnr, int sitzplatzanzahl){
    this->raumnr = raumnr;
    this->sitzplatzanzahl = sitzplatzanzahl;
    this->cooldown = 0; //Cooldown von 60 minuten nach einer Klausur
}

bool Raum::operator > (const Raum& str) const
{
    return (this->sitzplatzanzahl > str.sitzplatzanzahl);
}


ostream &operator <<(std::ostream &stream, const Raum &room){

    stream <<"Raumnr: " << room.raumnr << "   Sitzplätze: " << room.sitzplatzanzahl;
    return stream;
}
