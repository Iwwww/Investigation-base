#ifndef BASIS_HPP
#define BASIS_HPP

#include <iostream>
#include <string>
#include "../../Date/Date.hpp"

using std::istream;
using std::ostream;
using std::string;

class Basis {
public:
    Basis();
    Basis(int number, Date date, string name);
    Basis(Basis &&) = default;
    Basis(const Basis &) = default;
    Basis &operator=(Basis &&) = default;
    Basis &operator=(const Basis &) = default;
    ~Basis();

    void setNumber(int);
    void setDate(Date);
    void setName(string);

    int getNumber();
    Date getDate();
    string getName();
    string toString();
    string toString(string separator);

    bool operator==(const Basis &basis);
    bool operator!=(const Basis &basis);
    ostream &operator<<(ostream &os);
    friend istream &operator>>(istream &os, Basis&);

private:
    int number = 0;  // order number
    Date date{};     // order signing date
    string name{};   // order name

    string separator = " ";
};

#endif  // !BASIS_HPP
