#include "Storage.hpp"
#include <string>
#include <vector>

Storage::Storage() {}

Storage::~Storage() {}

void Storage::add(Investigation object) {
    storage.push_back(object);
}

vector<Investigation> Storage::getAll() {
    return storage;
}

vector<Investigation> Storage::getAllOrdered() {
    return sortByNumber();
}

vector<Investigation> Storage::sortByNumber() {
    // Bubble Sort
    if (storage.size() == 0) {
        return storage;
    }

    vector<Investigation> in = storage;

    // srot by name
    for (int i = 0; i < in.size(); i++) {
        for (int j = i; j < in.size(); j++) {
            if (in[i].getNumber() > in[j].getNumber()) {
                Investigation tmp = in[i];
                in[i] = in[j];
                in[j] = tmp;
            }
        }
    }

    // sort by date if numbers are the same
    for (int i = 0; i < in.size(); i++) {
        for (int j = i; j < in.size(); j++) {
            if (in[i].getNumber() == in[j].getNumber() && in[i].getDate() < in[j].getDate()) {
                Investigation tmp = in[i];
                in[i] = in[j];
                in[j] = tmp;
            }
        }
    }

    return in;
}

vector<Investigation> Storage::sortByName() {
    // Bubble Sort
    if (storage.size() == 0) {
        return storage;
    }

    vector<Investigation> in = storage;

    // srot by name
    for (int i = 0; i < in.size(); i++) {
        for (int j = i; j < in.size(); j++) {
            if (in[i].getName() > in[j].getName()) {
                Investigation tmp = in[i];
                in[i] = in[j];
                in[j] = tmp;
            }
        }
    }

    // sort by date if names are the same
    for (int i = 0; i < in.size(); i++) {
        for (int j = i; j < in.size(); j++) {
            if (in[i].getName() == in[j].getName() && in[i].getDate() < in[j].getDate()) {
                Investigation tmp = in[i];
                in[i] = in[j];
                in[j] = tmp;
            }
        }
    }

    return in;
}

vector<Investigation> Storage::sortByBasisNumber() {
    // Bubble Sort
    if (storage.size() == 0) {
        return storage;
    }

    vector<Investigation> in = storage;

    // srot by name
    for (int i = 0; i < in.size(); i++) {
        for (int j = i; j < in.size(); j++) {
            if (in[i].getBasis().getNumber() > in[j].getBasis().getNumber()) {
                Investigation tmp = in[i];
                in[i] = in[j];
                in[j] = tmp;
            }
        }
    }

    // sort by date if numbers are the same
    for (int i = 0; i < in.size(); i++) {
        for (int j = i; j < in.size(); j++) {
            if (in[i].getBasis().getNumber() == in[j].getBasis().getNumber() && in[i].getBasis().getDate() < in[j].getBasis().getDate()) {
                Investigation tmp = in[i];
                in[i] = in[j];
                in[j] = tmp;
            }
        }
    }

    return in;
}

vector<Investigation> Storage::selectInvestigationByBasis(Basis basis) {
    vector<Investigation> result{};
    for (int i = 0; i < storage.size(); i++) {
        if (storage[i].getBasis() == basis) {
            result.push_back(storage[i]);
        }
    }

    return result;
}

vector<Investigation> Storage::selectBasisByBasis(Basis basis) {
    vector<Investigation> result{};
    for (int i = 0; i < storage.size(); i++) {
        if (storage[i].getBasis() == basis) {
            result.push_back(storage[i]);
        }
    }

    return result;
}

vector<Investigation> Storage::selectDateByBasis(Basis basis) {
    vector<Investigation> result{};
    for (int i = 0; i < storage.size(); i++) {
        if (storage[i].getBasis() == basis) {
            result.push_back(storage[i]);
        }
    }

    return result;
}

vector<Investigation> Storage::selectNameByName(string name) {
    vector<Investigation> result{};
    for (int i = 0; i < storage.size(); i++) {
        if (storage[i].getName() == name) {
            result.push_back(storage[i]);
        }
    }

    return result;
}

int Storage::size() {
    return storage.size();
}
