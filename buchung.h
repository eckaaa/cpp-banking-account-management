#ifndef BUCHUNG_H
#define BUCHUNG_H

#include <iostream>

using namespace std;


class Buchung
{
private:
    string kontoNummer;
    string buchungsDatum;
    char sollHaben;
    string buchungsText;
    double betrag;

public:
    Buchung(const string &kontoNummer, const string &buchungsDatum, const char &sollHaben, const string &buchungsText, const double &betrag);
    ~Buchung();

    string getBuchungsDatum() const;
    char getSollHaben() const;
    string getBuchungsText() const;
    double getBetrag() const;
    string getKontoNummer() const;
};

#endif // BUCHUNG_H
