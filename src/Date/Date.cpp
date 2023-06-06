#include "Date.hpp"

Date::Date() {}

Date::Date(int year, int month, int day) {
    setYear(year);
    setMonth(month);
    setDay(day);
}

Date::~Date() {}

void Date::setDate(int year, int month, int day) {
    setYear(year);
    setMonth(month);
    setDay(day);
}

void Date::setYear(int year) {
    if (year >= YEAR_RANGE_BEGIN and year <= YEAR_RANGE_END) {
        this->year = year;
    } else {
        throw invalid_argument("Invalid date");
    }
}

void Date::setMonth(int month) {
    if (month >= MONTH_RANGE_BEGIN and month <= MONTH_RANGE_END) {
        this->month = month;
    } else {
        throw invalid_argument("Invalid date");
    }
}

void Date::setDay(int day) {
    if (day >= DAY_RANGE_BEGIN and day <= DAY_RANGE_END) {
        this->day = day;
    } else {
        throw invalid_argument("Invalid date");
    }
}

int Date::getYear() {
    return year;
}

int Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}

string Date::toString() {
    return toString(separator);
}

string Date::toString(string separator) {
    string date;
    string y = std::to_string(year);
    string m = std::to_string(month);
    string d = std::to_string(day);

    if (m.size() < 2) m = "0" + m;
    if (d.size() < 2) d = "0" + d;

    date += y + separator + m + separator + d;
    return date;
}

bool Date::operator==(const Date &date) {
    if (this->year == date.year) {
        if (this->month == date.month) {
            if (this->day == date.day) {
                return true;
            }
        }
    }

    return false;
}

bool Date::operator!=(const Date &date) {
    return !(*this == date);
}

bool Date::operator>(const Date &date) {
    if (this->year > date.year) {
        if (this->month > date.month) {
            if (this->day > date.day) {
                return true;
            }
        }
    }

    return false;
}

bool Date::operator<(const Date &date) {
    if (this->year < date.year) {
        if (this->month < date.month) {
            if (this->day < date.day) {
                return true;
            }
        }
    }

    return false;
}

ostream &Date::operator<<(ostream &os) {
    os << toString();
    return os;
}

istream &operator>>(istream &os, Date &date) {
    int year = Date::YEAR_RANGE_BEGIN;
    int month = Date::MONTH_RANGE_BEGIN;
    int day = Date::DAY_RANGE_BEGIN;

    cout << "Input Date\n";
    cout << "Year: ";
    os >> year;
    date.setYear(year);

    cout << "Month: ";
    os >> month;
    date.setMonth(month);

    cout << "Day: ";
    os >> day;
    date.setDay(day);

    return os;
}
