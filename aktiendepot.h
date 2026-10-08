#ifndef AKTIENDEPOT_H
#define AKTIENDEPOT_H

#include "konto.h"

class Aktiendepot : public Konto
{
public:
    Aktiendepot(const string &kontoNummer, const string &kunde);
    double berechneGebuehren(string jahr) const override;

};

#endif // AKTIENDEPOT_H
