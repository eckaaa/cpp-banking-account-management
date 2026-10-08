#ifndef FESTEGELDKONTO_H
#define FESTEGELDKONTO_H
#include "konto.h"
#include <string>
using namespace std;

class FestegeldKonto : public Konto
{
private:
    double zinssatz;
    string laufzeitEnde;


public:
    FestegeldKonto(const string &kontoNummer, const string &kunde, const double &zinssatz, const string &laufzeitEnde);
    double berechneGebuehren(string jahr) const override;

    double getZinssatz() const;
    string getLaufzeitEnde() const;
};

#endif // FESTEGELDKONTO_H
