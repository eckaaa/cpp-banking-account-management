#include "kontoverwaltung.h"
#include "aktiendepot.h"
#include "festegeldkonto.h"
#include "girokonto.h"
#include "hypothekenkonto.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <sstream>

using std::runtime_error;

vector<Konto *> KontoVerwaltung::getKonten() const
{
    return konten;
}

KontoVerwaltung::KontoVerwaltung() {}

KontoVerwaltung::~KontoVerwaltung()
{

}

void KontoVerwaltung::dateiEinlesen(){
    char c;
    cout<<"Was möchten Sie einlesen?"<<endl;
    cin>> c;

    if (c == 'k'){
        cout<<"Char eingelesen"<<endl;
        kontoEinlsen();
    }
    if (c == 'b'){
        cout<<"Char eingelesen"<<endl;
        buchungenEinelsen();
    }
// {   char wahl = '\0';

//     while(true){
//         cout<<"Was möchten Sie einlesen?"<<endl;

//         cin>> wahl;

//         cout <<" choise ";

//         switch(wahl){
//         case '1':{
//             cout<<"methode aufgerufen";
//             kontoEinlsen();
//             break;
//         }
//         case 'b':{
//             buchungenEinelsen();
//             break;
//         }
//         case '0':{
//             return;
//             break;
//         }
//         default:{
//             cout <<"Ungueltige Eingabe, probieren Sie noch mal."<<endl;
//             break;}
//         }
//     }
}

Konto *KontoVerwaltung::findeKonto(string kontoNummer)
{
    cout << "start\nsize = " << konten.size() << endl;
    for (int i = 0; i < konten.size(); i++)
    {
        cout << "step\n";
        if (kontoNummer == konten[i]->getKontoNummer() ){
            cout << "yes\n";
            return konten[i];
        }
    }
    cout << "no\n";
    return nullptr;
}

void KontoVerwaltung::zeigeGebuehren(string jahr, string kontoNummer)
{

}

void KontoVerwaltung::zeigeBuchungen(string jahr, string kontoNummer)
{

}

void KontoVerwaltung::bewerteKunden()
{

}

void KontoVerwaltung::benutzerDialog()
{
    char choice;


    while(true){
        cout<<"1: Datei einlesen"<<endl;
        cout<<"2: Konto finden"<<endl;
        cout<<"3: Gebuehren zeigen"<<endl;
        cout<<"4: Buchungen zeigen"<<endl;
        cout<<"5: Kunden bewerten"<<endl;
        cout<<"0: Programm beenden"<<endl;
        cin>>choice;
        switch (choice) {
        case '1':{

            dateiEinlesen();
        }break;

        case '2':{
            string kontoNummer;
            cin>>kontoNummer;
            findeKonto(kontoNummer);
        }
        break;
        case '3':{
            string kontoNummer, jahr;
            cin >> jahr;
            cin>> kontoNummer;
            zeigeGebuehren(kontoNummer, jahr);
        }break;
        case '4':{
            string jahr,  kontoNummer;
            cin >> jahr;
            cin>> kontoNummer;
            zeigeBuchungen(jahr, kontoNummer);
        }break;
        case '5':{
            bewerteKunden();
        }break;

        case '0':{
            return;

        }break;

        default:{
            cout <<"Ungueltige Eingabe, probieren Sie noch mal."<<endl;
        }break;
        }
    }
}

void KontoVerwaltung::kontoEinlsen()
{
    string fileName = "konten.txt";

    ifstream input(fileName);

    if(!input.is_open()){
        cout<<"cannot open file to read";
        return;
    }

    // konten.clear();

    //Kontonummer|Kundnenname|Zinssatz|Laufzeitende
    string fileLine;
    while(std::getline(input,fileLine)){
        string kundenname,kontonummer;
        string additionalParameter1; //zinsatz ||  Laufzeitende
        string additionalParameter2; //Laufzeitende
        std::stringstream ss(fileLine);
        try{
            getline(ss,kontonummer,'|');
            getline(ss,kundenname,'|');


            if(kontonummer[0] == 'H'){
                cout <<"Debug H"<<endl;
                getline(ss,additionalParameter1,'|');
                double zinssatz = stod(additionalParameter1);
                Hypothekenkonto *h = new Hypothekenkonto(kontonummer, kundenname, zinssatz);
                konten.push_back(dynamic_cast<Konto*>(h));
                cout <<"Debug H"<<endl;
            }else if(kontonummer[0] == 'F'){
                cout <<"Debug F";
                getline(ss,additionalParameter1,'|');
                getline(ss,additionalParameter2,'|');
                double zinssatz = stod(additionalParameter1);
                string laufzeitende= additionalParameter2;
                //FestegeldKonto *f = new FestegeldKonto(kontonummer, kundenname, zinssatz, laufzeitende);
                //konten.push_back(f);
                cout <<"Debug A"<<endl;
            }else if(kontonummer[0] == 'G'){
                cout <<"Debug G";
                //Girokonto *g = new Girokonto(kontonummer,kundenname);
                //konten.push_back(g);
                cout <<"Debug A"<<endl;
            }else if(kontonummer[0] == 'A'){

                Aktiendepot *a = new Aktiendepot(kontonummer,kundenname);
                konten.push_back(a);
                cout <<"Debug A"<<endl;
            }else{
                throw std::runtime_error(&"Unknown KontoTyp" [kontonummer[0]]);
            }
        }catch(const std::exception& e){
            cout<<"Couldn't parse Data";
            continue;
        }catch(const std::runtime_error& r){
            cout<<"Error Unknown Kontotype";
            continue;
        }
    }
    input.close();
    cout<<"Info Data loaded successfully!"<<endl;
    int anzahl = konten.size();
}

void KontoVerwaltung::buchungenEinelsen()
{
    int counter = 0;

    string fileName = "buchungen.txt";
    ifstream file(fileName);
    cout <<" Line 219. "<<endl;
    if (!file.is_open()){
        cout << "Die Datei konnte nicht geoeffnet werden."<<endl;
        return;
    }


    string currentLine;

    while (getline(file, currentLine)){
        cout <<" Line 229. "<<endl;
        stringstream ss(currentLine);
        string kontoNummer, buchungsDatum, kennzeichen, buchungsText, buchungsBetrag;

        try{
            cout <<" Line 234. "<<endl;
            getline(ss, kontoNummer, '|');
            getline(ss, buchungsDatum, '|');
            getline(ss, kennzeichen, '|');
            getline(ss, buchungsText, '|');
            getline(ss, buchungsBetrag, '|');

            cout <<" Line 241. "<<endl;
            Konto* k = findeKonto(kontoNummer);
             cout <<" Line 243. "<<endl;
            if (k){
                cout <<" Line 244. "<<endl;
                Buchung* b = new Buchung(kontoNummer, buchungsDatum, kennzeichen[0], buchungsText, stod(buchungsBetrag));
                alleBuchungen.push_back(b);


                k->buchungDurchfuehren(b);
                counter++;
            }else {
                cout<<kontoNummer<<" existiert nicht."<<endl;
            }

        }catch(exception &e){
            cout <<"Fehler beim Einlesen der Datei"<<e.what()<<endl;
            continue;
        }
    }
    file.close();
    cout<<"Die Datei wurde erfolgreich eingelesen!"<<endl;
    cout<<"Es wurden "<<counter<<" Buchungen angelegt" << endl;
}
