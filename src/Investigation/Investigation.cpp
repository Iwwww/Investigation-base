#include "Investigation.hpp"

Investigation::Investigation() {}

Investigation::Investigation(
    int number,
    string name,
    Date date,
    string description,
    Type type,
    Basis basis) {
    setNumber(number);
    setName(name);
    setDate(date);
    setDescription(description);
    setType(type);
    setBasis(basis);
}

Investigation::~Investigation() {}

void Investigation::setNumber(int number) {
    this->number = number;
}

void Investigation::setName(string name) {
    this->name = name;
}

void Investigation::setDate(Date date) {
    this->date = date;
}

void Investigation::setDescription(string description) {
    this->description = description;
}

void Investigation::setType(Type type) {
    this->type = type;
}

void Investigation::setType(int _type) {
    switch (type) {
        case 1: type = FinancialControl; break;
        case 2: type = StateProcurementControl; break;
        case 3: type = StateServicesControl; break;
        default:
            type = FinancialControl;
            throw std::out_of_range("Invalid type");
            break;
    }
}

void Investigation::setBasis(Basis basis) {
    this->basis = basis;
}

int Investigation::getNumber() const {
    return number;
}

string Investigation::getName() const {
    return name;
}

Date Investigation::getDate() const {
    return date;
}

string Investigation::getDescription() const {
    return description;
}

Investigation::Type Investigation::getType() const {
    return type;
}

Basis Investigation::getBasis() const {
    return basis;
}

ostream &operator<<(ostream &os, const Investigation &obj) {
    string sep = " | ";
    string type{};

    switch (obj.type) {
        case 0: type = "FinancialControl"; break;
        case 1: type = "StateProcurementControl"; break;
        case 2: type = "StateServicesControl"; break;
        default:
            type = "none";
            throw std::out_of_range("Invalid type");
            break;
    }

    os << std::to_string(obj.getNumber()) << sep << std::left << setw(47)
       << obj.getName() << sep << setw(10) << obj.getDate().toString() << sep
       << setw(25) << type << sep << setw(8) << obj.getBasis();
    return os;
}

istream &Investigation::operator>>(istream &os) {
    int number = 0;
    string name;
    Date date;
    string description;
    Type type{};
    Basis basis;

    cout << "Input Investigation\n";
    cout << "Number: ";
    os >> number;
    this->setNumber(number);

    cout << "Name: ";
    os >> name;
    this->setName(name);

    // cout << "Date: ";
    os >> date;
    this->setDate(date);

    cout << "Description: ";
    os >> description;
    this->setName(description);

    cout << "Types:\n"
         << "1 - FinancialControl\n"
         << "2 - StateProcurementControl\n"
         << "3 - StateServicesControl\n";

    cout << "Input Type: ";
    int choice = 0;
    while (choice < 1 || choice > 3) {
        cin >> choice;
    }

    // cout << "Basis: ";
    os >> basis;
    this->setBasis(basis);

    return os;
}
