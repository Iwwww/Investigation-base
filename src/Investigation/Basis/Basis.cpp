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

int Basis::getNumber() {
    return number;
}

Date Basis::getDate() {
    return date;
}

string Basis::getName() {
    return name;
}

string Basis::toString() {
    return toString(separator);
}

string Basis::toString(string separator) {
    string date;
    date +=
        std::to_string(number) + separator + string(date) + separator + name;
    return date;
}

bool Basis::operator==(const Basis &basis) {
    return this->number == basis.number && this->date == basis.date &&
           this->name == name;
}

bool Basis::operator!=(const Basis &basis) {
    return !(*this == basis);
}

ostream &Basis::operator<<(ostream &os) {
    toString();
    // os << std::to_string(getNumber()) << string(" ") << getDate().toString()
    // << string(" ") << getName();
    return os;
}

istream &operator>>(istream &os, Basis& basis) {
    int number = 0;
    Date date;
    string name;

    cout << "Input Basis";
    cout << "Number: ";
    os >> number;
    basis.setNumber(number);

    cout << "Date: ";
    os >> date;
    basis.setDate(date);

    cout << "Name: ";
    os >> name;
    basis.setName(name);

    return os;
}
