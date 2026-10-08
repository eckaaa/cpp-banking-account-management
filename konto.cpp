#include "konto.h"

Konto::Konto(const string &kontoNummer, const string &kunde):
    kontoNummer(kontoNummer), kunde(kunde)
{

}

Konto::~Konto()
{

}

void Konto::buchungDurchfuehren(Buchung *buchung)
{
    buchungen.push_back(buchung);
    if(buchung->getSollHaben() == 'H'){
        kontoStand += buchung->getBetrag();
    }
    else {
        kontoStand -= buchung->getBetrag();
    }
}


long Konto::ermittlePunkte()
{

}

string Konto::getKontoNummer() const
{
    return kontoNummer;
}

string Konto::getKunde() const
{
    return kunde;
}

double Konto::getKontoStand() const
{
    return kontoStand;
}

vector<Buchung *> Konto::getBuchungen() const
{
    return buchungen;
}

