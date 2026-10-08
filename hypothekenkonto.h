#ifndef HYPOTHEKENKONTO_H
#define HYPOTHEKENKONTO_H

#include "konto.h"


class Hypothekenkonto : public Konto
{
private:
    double zinssatz;
public:
    Hypothekenkonto( const string &kontoNummer, const string &kunde, const double &zinssatz );
    double berechneGebuehren(string jahr) const override;

    double getZinssatz() const;
};

#endif // HYPOTHEKENKONTO_H
