#include "buchung.h"



string Buchung::getBuchungsDatum() const
{
    return buchungsDatum;
}

char Buchung::getSollHaben() const
{
    return sollHaben;
}

string Buchung::getBuchungsText() const
{
    return buchungsText;
}

double Buchung::getBetrag() const
{
    return betrag;
}

string Buchung::getKontoNummer() const
{
    return kontoNummer;
}

Buchung::Buchung(const string &kontoNummer, const string &buchungsDatum, const char &sollHaben, const string &buchungsText, const double &betrag):
    kontoNummer(kontoNummer), buchungsDatum(buchungsDatum), sollHaben(sollHaben), buchungsText(buchungsText), betrag(betrag)
{}

Buchung::~Buchung()
{}
