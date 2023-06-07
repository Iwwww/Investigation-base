#include "Basis.hpp"
#include <string>

Basis::Basis() {}

Basis::Basis(int number, Date date, string name) {
    setNumber(number);
    setDate(date);
    setName(name);
}

Basis::~Basis() {}

void Basis::setNumber(int number) {
    this->number = number;
}

void Basis::setDate(Date date) {
    this->date = date;
}

void Basis::setName(string name) {
    this->name = name;
}

int Basis::getNumber() const {
    return number;
}

Date Basis::getDate() const {
    return date;
}

string Basis::getName() const {
    return name;
}

string Basis::toString() const {
    return toString(separator);
}

string Basis::toString(string separator) const {
    string base;
    base += std::to_string(number) + separator + name;
    return base;
}

bool Basis::operator==(const Basis &basis) {
    return this->number == basis.number && this->date == basis.date &&
           this->name == name;
}

bool Basis::operator!=(const Basis &basis) {
    return !(*this == basis);
}

ostream &operator<<(ostream &os, const Basis &obj) {
    // os << toString("|");
    string sep = " | ";
    os << std::left << setw(8) << obj.getNumber() << sep
       << setw(10) << obj.getDate().toString() << sep << obj.getName();
    return os;
}

istream &operator>>(istream &os, Basis &basis) {
    int number = 0;
    Date date;
    string name;

    cout << "Input Basis\n";
    cout << "Number: ";
    os >> number;
    basis.setNumber(number);

    os >> date;
    basis.setDate(date);

    cout << "Name: ";
    os >> name;
    basis.setName(name);

    return os;
}
