#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Raum.h"
#include "Pruefung.h"
#include "Pruefer.h"
#include "Student.h"
#include "Anmeldung.h"
#include <vector>

//zum Zeitmessen
#include <time.h>
clock_t start, ende;
double time1;

using namespace std;

// evtl Array/vector[Prüfungsnr][pversionen][matrikelnummern]

vector<Raum> raeume;            //Liste mit räumen
vector<Pruefung> pruefungen;    //Liste mit prüfungen
vector<Pruefer> prueferliste;   //Liste mit Prüfern
vector<Student> studenten;
vector<Pruefung> ungueltigePruefungen;
vector<Anmeldung> ungueltigeAnmeldungen;



void einlesenPruefungen() {

    ifstream datei(
            "/Users/tombiskupski/Desktop/HfT/Semester 3/Prog3/progprojekt/InputData/Angebotene_Prüfungen_KL.csv");
    string zeile;
    bool p1existiert = false;
    bool p2existiert = false;
    Pruefer pr1 = NULL;
    Pruefer pr2 = NULL;

    string test;
    getline(datei, zeile);
    bool einlesen = true;

    int pversion;
    int pnr;
    int dauer;
    int pruefer1ID;
    int pruefer2ID;
    string stg;
    string pruefungsname;

    while (!datei.eof()) {
        for (int i = 0; i < 12; i++) {
            getline(datei, test, ';');
            switch (i) {
                case 0:
                    stg = test;
                    break;
                case 1:
                    break;
                case 2:
                    pversion = atoi(test.c_str());
                    break;
                case 3:
                    pnr = atoi(test.c_str());
                    break;
                case 4:
                    pruefungsname = test;
                    break;
                case 5:
                    pruefer1ID = atoi(test.c_str());
                    break;
                case 6:
                    break;
                case 7:
                    pruefer2ID = atoi(test.c_str());
                    break;
                case 8:
                    break;
                case 9:
                    dauer = atoi(test.c_str());
                    break;
                case 10:
                    break;
                case 11:
                    break;
                default:
                    cout << "konnte variable nicht zuordnen" << endl;
            }
        }
        getline(datei, test, '\n'); //Zum auslesen des "J" aus der Datei


        /*for(int i = 0; i < zeile.size(); i++) {
            if (zeile[i] == ';') {
            }*/

        for (int i = 0; i < prueferliste.size(); i++) {

            if (prueferliste.at(i).getPrueferID() == pruefer1ID) {
                p1existiert = true;
                //cout <<"p1 Existiert gestzt!"<<endl;
            }

            if (prueferliste.at(i).getPrueferID() == pruefer2ID) {
                p2existiert = true;
                //cout <<"p2 Existiert gestzt!"<<endl;
            }

        }

        if (!p1existiert && pruefer1ID != 0) {
            pr1 = Pruefer(pruefer1ID);
            prueferliste.push_back(pr1);
        }

        if (!p2existiert && pruefer2ID != 0) {
            pr2 = Pruefer(pruefer2ID);
            prueferliste.push_back(pr2);
        }

        if (dauer == 0){
            ungueltigePruefungen.push_back(Pruefung(pversion, pnr, dauer, pr1, pr2, stg, pruefungsname));
        }else{
            pruefungen.push_back(Pruefung(pversion, pnr, dauer, pr1, pr2, stg, pruefungsname));
        }





        pr1 = NULL;
        pr2 = NULL;
        p1existiert = false;
        p2existiert = false;

    }
    ungueltigePruefungen.pop_back();
    cout << "Prüfungen Erstellt" << endl;
    cout << "Prüfer erstellt " << endl;
    sort(prueferliste.begin(), prueferliste.end(), greater<Pruefer>());

    /*
    stringstream zeilenpuffer(zeile);
        int intPlatzhalter;
        string stringPlatzhalter;

        int pversion;
        int pnr;
        int dauer;
        int pruefer1ID;
        int pruefer2ID;
        string stg;
        string pruefungsname;

        stg;vert;pversion;pnr;pdtxt;ppruefer;Prüfer 1;zweitpruefer;Prüfer 2;pdauer;pform;psem;angeboten
                AB;;141;1030;Technik Grundlagen;6317;;;;210;KL;20201;J
                AB;;141;4030;Grundlagen Organisation 1;1224;;;;90;KL;20201;J
                AB;;161;1020;Konstruktion Grundlagen;0178;;0452;;120;KL;20201;J
                AB;;161;1030;Technik Grundlagen;6317;;;;210;KL;20201;J
                AB;;161;2030;Grundlagen Entwerfen 2;00692;;;;180;KL;20201;J

                WPM;;162;1050;Psychologische Asp.Org.I;3123;;2394;;60;KL;20201;J


        zeilenpuffer >> stg >> intPlatzhalter >> pversion >> pnr  >> pruefungsname >> pruefer1ID >> intPlatzhalter >> pruefer2ID >> intPlatzhalter >> dauer >> stringPlatzhalter >>intPlatzhalter >> stringPlatzhalter;
        cout << pversion << endl;
        //Einfügen der Prüfer in die Prüferliste und überprüfen, ob der Prüfer bereits vorhanden ist
        */

}

void einlesenRaumlisten() {
    ifstream datei("/Users/tombiskupski/Desktop/HfT/Semester 3/Prog3/progprojekt/InputData/Raumliste.csv");
    string zeile;

    while (getline(datei, zeile)) {

        for (int i = 0; i < zeile.size(); i++) {
            if (zeile[i] == ',') {
                zeile[i] = ' ';
            }
            if (zeile[i] == '"') {
                zeile[i] = ' ';
            }
        }

        stringstream zeilenpuffer(zeile);

        string a;
        string raumnr;

        int sitzplatzanzahl;

        zeilenpuffer >> a >> raumnr >> sitzplatzanzahl;

        raeume.push_back(Raum(raumnr, sitzplatzanzahl / 4));
        sort(raeume.begin(), raeume.end(), greater<Raum>());

    }

    cout << "Räume erstellt" << endl;
}


void einlesenAnmeldungen(){
    ifstream datei("/Users/tombiskupski/Desktop/HfT/Semester 3/Prog3/progprojekt/InputData/Anmeldungen_WS2019_KL.csv");
    string zeile;
    bool zugeteilt = false;

    while (getline(datei, zeile)){
        for(int i = 0; i < zeile.size(); i++) {
            if (zeile[i] == ';') {
                zeile[i] = ' ';
            }
        }

        if (zeile[0] == 'm') {
            continue;
        }

        stringstream zeilenpuffer(zeile);
        long int matrikelnr;
        string stg;
        int pversion;
        int pnr;
        string pform;
        string dtext;
        int psem;
        zeilenpuffer >> matrikelnr >> stg >> pversion >> pnr >> pform >> dtext >> psem;

        //Bisher noch doppelte Matrikelnummern dabei
        studenten.push_back(Student(matrikelnr));

        zugeteilt = false;
        for(int i = 0; i < pruefungen.size(); i++){
                if (pnr == pruefungen[i].getPnr()){
                    if (pversion == pruefungen[i].getPversion()){
                        pruefungen[i].matrikelnrListe.push_back(matrikelnr);
                        zugeteilt = true;
                        break;
                    }
                }
        }

        if (!zugeteilt){
            ungueltigeAnmeldungen.push_back(Anmeldung(matrikelnr,stg,pversion,pnr,pform,dtext,psem));
        }

    }
    cout << "Studenten erstellt" << endl;
}

int main() {

    start = clock();

    einlesenRaumlisten();
    einlesenPruefungen();
    einlesenAnmeldungen();

    cout << "Ausgabe Studenten in einer Prüfung" << endl;


    int ausgabe = 14;

    cout << "Prüfungsnr: " << pruefungen[ausgabe].getPnr()<< endl;
    cout << "Prüfungsversion: " << pruefungen[ausgabe].getPversion()<< endl;
    cout << "Anzahl studenten: " << pruefungen[ausgabe].matrikelnrListe.size()<< endl;

    for (int i = 0; i < pruefungen[ausgabe].matrikelnrListe.size(); ++i) {
        cout << pruefungen[ausgabe].matrikelnrListe[i] << endl;
    }

    cout << "Ausgabe Studenten in dieser Prüfung Fertig" << endl;


    /*
    for (int i = 0; i < prueferliste.size(); i++) {
        cout << prueferliste[i] << endl;
    }
    cout << "Anzahl prüfer: " << prueferliste.size() << endl;
    */
    /*
for(int i=0; i<raeume.size(); i++){
    cout << raeume[i] << endl;
}

*/
/*
    for (int i = 0; i < pruefungen.size(); i++) {
        cout << pruefungen[i] << endl;
    }
    cout << "Anzahl prüfungen: " << pruefungen.size() << endl;
*/
/*
 *
    for (int i = 0; i < ungueltigePruefungen.size(); i++) {
        cout << ungueltigePruefungen[i] << endl;
    }
    cout << "Anzahl prüfungen: " << ungueltigePruefungen.size() << endl;

*/
/*
    for (int i = 0; i < ungueltigeAnmeldungen.size(); i++) {
        cout << ungueltigeAnmeldungen[i] << endl;
    }

    cout << "Ungueltige Anmeldungen: " << ungueltigeAnmeldungen.size() << endl;
*/

    ende = clock();
    time1 = (double) (ende - start) / CLOCKS_PER_SEC;



    cout << "Benötigte Zeit: " << time1 << endl;

}
