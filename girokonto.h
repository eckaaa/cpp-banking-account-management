#ifndef GIROKONTO_H
#define GIROKONTO_H

#include "konto.h"


class Girokonto : public Konto
{
public:
    Girokonto(const string &kontoNummer, const string &kunde);
    double berechneGebuehren(string jahr) const override;
};

#endif // GIROKONTO_H
