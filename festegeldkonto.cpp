#include "festegeldkonto.h"

FestegeldKonto::FestegeldKonto(const string &kontoNummer, const string &kunde, const double &zinssatz, const string &laufzeitEnde):
     Konto(kontoNummer, kunde), zinssatz(zinssatz), laufzeitEnde(laufzeitEnde)
{

}

double FestegeldKonto::getZinssatz() const
{
    return zinssatz;
}

string FestegeldKonto::getLaufzeitEnde() const
{
    return laufzeitEnde;
}



double FestegeldKonto::berechneGebuehren(string jahr) const
{

}
