# C++ Banking Account Management System

A console-based banking account management system written in C++, modeling different account types through an abstract base class and polymorphic fee calculation. Developed as coursework for the Programmieren 1 module at Hochschule Darmstadt.

## Project Overview

The application manages a collection of bank accounts of different types (checking, mortgage, fixed-term deposit, stock deposit), records transactions ("Buchungen") against them, calculates account-type-specific annual fees, and awards loyalty points based on transaction history. Accounts and transactions are loaded from pipe-delimited text files.

## Technologies Used

- **C++17**
- Standard Library containers (`std::vector`) and streams (`ifstream`, `stringstream`)
- **qmake** build system (console application, no GUI framework)

## Features

- Abstract `Konto` base class with pure-virtual fee calculation, specialized by:
  - `Girokonto` (checking account)
  - `Hypothekenkonto` (mortgage account, interest-rate based)
  - `FestegeldKonto` (fixed-term deposit, interest rate + maturity date)
  - `Aktiendepot` (stock deposit)
- `Buchung` class representing a single transaction (date, debit/credit, description, amount)
- Loyalty point calculation per account (`ermittlePunkte`) based on recorded transactions
- Loading accounts and transactions from text files (`konten.txt`, `buchungen.txt`)
- Console menu (`benutzerDialog`) for looking up accounts, fees and transactions, and rating customers

## Project Structure

```
cpp-banking-account-management/
├── main.cpp                  # Application entry point
├── konto.*                   # Abstract base class for all account types
├── girokonto.*                # Checking account
├── hypothekenkonto.*           # Mortgage account
├── festegeldkonto.*            # Fixed-term deposit account
├── aktiendepot.*                # Stock deposit account
├── buchung.*                  # Single transaction record
├── kontoverwaltung.*            # Account collection, file loading, console menu
└── Kontoverwaltung14_15.pro
```

## Installation and Usage

**Requirements:** a C++17 compiler and qmake (no Qt GUI modules required).

```bash
qmake Kontoverwaltung14_15.pro
make
./Kontoverwaltung14_15
```

The program reads account and transaction data from `konten.txt` and `buchungen.txt` (pipe-separated: `Kontonummer|Kundenname|...`) in the working directory at startup. Sample data files are not included in this repository; the format expected by the parser is `AccountNumber|CustomerName|InterestRate|...` depending on account-type prefix (`H` = Hypothekenkonto, `F` = FestegeldKonto, `G` = Girokonto, `A` = Aktiendepot).

## Technical Highlights

- **Abstraction & polymorphism**: `berechneGebuehren()` is declared pure-virtual on `Konto` and implemented independently by each account subtype.
- **Encapsulation**: internal account state is protected and exposed only through accessor methods.
- **Custom text-based persistence**: accounts and transactions are parsed from a simple pipe-delimited file format using `stringstream`.

## Known Limitations

This was an early Programmieren 1 exercise: the file-loading routine currently only instantiates `Hypothekenkonto` and `Aktiendepot` objects; the branches for `Girokonto` and `FestegeldKonto` are present but commented out in the original coursework code, and some debug `cout` statements remain from development.
