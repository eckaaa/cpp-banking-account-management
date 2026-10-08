#ifndef KONTOVERWALTUNG_H
#define KONTOVERWALTUNG_H

#include "konto.h"

#include "buchung.h"

class KontoVerwaltung
{
private:
        vector<Konto*> konten;
        vector <Buchung*> alleBuchungen;

public:
    KontoVerwaltung();
    ~KontoVerwaltung();
    void dateiEinlesen();
    Konto* findeKonto(string kontoNummer);
    void zeigeGebuehren(string jahr, string kontoNummer);
    void zeigeBuchungen(string jahr, string kontoNummer);
    void bewerteKunden();

    void benutzerDialog();

    void kontoEinlsen();
    void buchungenEinelsen();


    vector<Konto *> getKonten() const;
};

#endif // KONTOVERWALTUNG_H
