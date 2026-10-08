#ifndef KONTO_H
#define KONTO_H
#include "buchung.h"
#include <iostream>
#include <vector>

using namespace std;



class Konto
{
protected:
    string kontoNummer;
    string kunde;
    double kontoStand;
    vector <Buchung*> buchungen;


public:
    Konto(const string &kontoNummer, const string &kunde);
    virtual ~Konto();
    virtual double berechneGebuehren(string jahr) const = 0;
    void buchungDurchfuehren(Buchung* buchung) ;
    long ermittlePunkte();


    string getKontoNummer() const;
    string getKunde() const;
    double getKontoStand() const;
    vector<Buchung *> getBuchungen() const;
};

#endif // KONTO_H
