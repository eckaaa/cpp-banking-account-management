TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        aktiendepot.cpp \
        buchung.cpp \
        festegeldkonto.cpp \
        girokonto.cpp \
        hypothekenkonto.cpp \
        konto.cpp \
        kontoverwaltung.cpp \
        main.cpp

HEADERS += \
    aktiendepot.h \
    buchung.h \
    festegeldkonto.h \
    girokonto.h \
    hypothekenkonto.h \
    konto.h \
    kontoverwaltung.h
