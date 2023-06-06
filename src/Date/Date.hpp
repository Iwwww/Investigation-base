// TODO:
// setter/getter for sepparator

#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <stdexcept>
#include <string>

using std::cout;
using std::invalid_argument;
using std::istream;
using std::ostream;
using std::string;

class Date {
public:
    // The date range includes the value of the variables (>=, <=)
    static const int YEAR_RANGE_BEGIN = 1900;
    static const int YEAR_RANGE_END = 2050;
    static const int MONTH_RANGE_BEGIN = 1;
    static const int MONTH_RANGE_END = 12;
    static const int DAY_RANGE_BEGIN = 1;
    static const int DAY_RANGE_END = 31;

    Date();
    Date(int year, int month, int day);
    Date(Date &&) = default;
    Date(const Date &) = default;
    Date &operator=(Date &&) = default;
    Date &operator=(const Date &) = default;
    ~Date();

    void setDate(int year, int month, int day);
    void setYear(int);
    void setMonth(int);
    void setDay(int);

    int getYear();
    int getMonth();
    int getDay();
    // return std::string "YYYY-MM-DD"
    string toString();
    string toString(string separator);

    bool operator==(const Date &date);
    bool operator!=(const Date &date);
    bool operator>(const Date &date);
    bool operator<(const Date &date);
    ostream &operator<<(ostream &os);
    friend istream &operator>>(istream &os, Date&);

private:
    int year = YEAR_RANGE_BEGIN;
    int month = MONTH_RANGE_BEGIN;
    int day = DAY_RANGE_BEGIN;

    string separator = "-";
};

#endif  // !DATE_HPP
