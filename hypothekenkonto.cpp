#include "hypothekenkonto.h"


double Hypothekenkonto::getZinssatz() const
{
    return zinssatz;
}

Hypothekenkonto::Hypothekenkonto( const string &kontoNummer, const string &kunde, const double &zinssatz):
    Konto(kontoNummer, kunde), zinssatz(zinssatz)
{

}

double Hypothekenkonto::berechneGebuehren(string jahr) const
{

}
