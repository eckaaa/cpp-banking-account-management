#include "girokonto.h"

Girokonto::Girokonto(const string &kontoNummer, const string &kunde):
    Konto(kontoNummer, kunde) {}

double Girokonto::berechneGebuehren(string jahr) const{
}
