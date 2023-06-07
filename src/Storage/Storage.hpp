// TODO:
// tset sortByNumber
// test sortByName
// test sortByBasisNumber

#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <algorithm>
#include <vector>
#include "../Investigation/Investigation.hpp"

using std::vector;
using std::max_element;
using std::min_element;

class Storage {
public:
    Storage();
    Storage(Storage &&) = default;
    Storage(const Storage &) = default;
    Storage &operator=(Storage &&) = default;
    Storage &operator=(const Storage &) = default;
    ~Storage();

    void add(Investigation);

    vector<Investigation> getAll();
    vector<Investigation> getAllOrdered();

    vector<Investigation> sortByNumber();
    vector<Investigation> sortByName();
    vector<Investigation> sortByBasisNumber();

    // return all with found basis
    vector<Investigation> selectInvestigationByBasis(Basis);
    vector<Investigation> selectBasisByBasis(Basis);
    vector<Investigation> selectDateByBasis(Basis);
    vector<Investigation> selectNameByName(string name);

    int size();

private:
    vector<Investigation> storage;
};

#endif  // !STORAGE_HPP
