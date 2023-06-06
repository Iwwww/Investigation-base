// TODO:
// setter/getter for Type type

#ifndef INVESTIGATION_HPP
#define INVESTIGATION_HPP

#include <exception>
#include <iomanip>
#include <string>
#include "../Date/Date.hpp"
#include "Basis/Basis.hpp"

using std::cin;
using std::cout;
using std::setw;
using std::out_of_range;
using std::string;

class Investigation {
public:
    enum Type {
        FinancialControl,  // Финансовый контроль
        StateProcurementControl,  // Контроль государственных закупок
        StateServicesControl,  // Контроль государственных услуг
    };

    Investigation();
    Investigation(
        int number,
        string name,
        Date date,
        string description,
        Type type,
    Basis basis
    );
    Investigation(Investigation &&) = default;
    Investigation(const Investigation &) = default;
    Investigation &operator=(Investigation &&) = default;
    Investigation &operator=(const Investigation &) = default;
    ~Investigation();

    void setNumber(int);
    void setName(string);
    void setDate(Date);
    void setDescription(string);
    void setType(Type);
    void setType(int);
    void setBasis(Basis);

    int getNumber() const;
    string getName() const;
    Date getDate() const;
    string getDescription() const;
    Type getType() const;
    Basis getBasis() const;

    friend ostream &operator<<(ostream &os, const Investigation& obj);
    istream &operator>>(istream &os);

private:
    int number = 0;
    string name{};  // name of the institution being inspected
    Date date{};           // Date of the inspection
    string description{};  // subject of the investigation
    Type type{};
    Basis basis{};

    string separator = " ";
};

#endif  // !INVESTIGATION_HPP
