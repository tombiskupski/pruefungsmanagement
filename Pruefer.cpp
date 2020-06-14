//
// Created by Tom Biskupski on 11.06.20.
//

#include "Pruefer.h"

Pruefer::Pruefer(int prueferID){
    this->prueferID = prueferID;
}

Pruefer::Pruefer(){
    this->prueferID = 0;
}

ostream &operator <<(ostream &stream, const Pruefer &prf){

    stream <<"PrüferID: " << prf.prueferID;
    return stream;
}

istream &operator >>(istream &stream, const Pruefer &prf){

    stream >> prf.prueferID;
    return stream;

}

int Pruefer::getPrueferID() const {
    return this->prueferID;
}


bool Pruefer::operator > (const Pruefer& str) const
{
    return (this->prueferID > str.prueferID);
}

