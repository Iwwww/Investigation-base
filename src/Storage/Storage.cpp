#include "Storage.hpp"
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
    // Counting Sort
    if (storage.size() == 0) {
        return storage;
    }

    vector<Investigation> in = storage;

    int min = in[0].getNumber();
    int max = in[0].getNumber();
    for (int i = 0; i < in.size(); i++) {
        if (in[i].getNumber() < min) min = in[i].getNumber();
        if (in[i].getNumber() > max) max = in[i].getNumber();
    }

    vector<int> count = vector<int>(max - min + 1);

    for (int i = 0; i < in.size(); i++) {
        count[in[i].getNumber() - min]++;
    }

    int index = 0;
    for (int i = 0; i < count.size(); i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++) {
                in[index++].setNumber(i + 1);
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
    Investigation last = in[0];
    int last_index = 0;
    for (int i = 0; i < in.size(); i++) {
        if (last.getName() != in[i].getName()) {
            for (int j = last_index; j - 1 < i; j++) {
                if (in[i].getDate() > in[j].getDate()) {
                    Investigation tmp = in[i];
                    in[i] = in[j];
                    in[j] = tmp;
                }
            }
            last = in[i];
            last_index = 0;
        }
    }

    return in;
}

vector<Investigation> Storage::sortByBasisNumber() {
    // Counting Sort
    if (storage.size() == 0) {
        return storage;
    }

    vector<Investigation> in = storage;

    int min = in[0].getBasis().getNumber();
    int max = in[0].getBasis().getNumber();
    for (int i = 0; i < in.size(); i++) {
        if (in[i].getBasis().getNumber() < min)
            min = in[i].getBasis().getNumber();
        if (in[i].getBasis().getNumber() > max)
            max = in[i].getBasis().getNumber();
    }

    vector<int> count = vector<int>(max - min + 1);

    for (int i = 0; i < in.size(); i++) {
        count[in[i].getBasis().getNumber() - min]++;
    }

    int index = 0;
    for (int i = 0; i < count.size(); i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++) {
                Basis tmp = in[index].getBasis();
                tmp.setNumber(i + 1);
                in[index++].setBasis(tmp);
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

vector<Basis> Storage::selectBasisByBasis(Basis basis) {
    vector<Basis> result{};
    for (int i = 0; i < storage.size(); i++) {
        if (storage[i].getBasis() == basis) {
            result.push_back(storage[i].getBasis());
        }
    }

    return result;
}

vector<Date> Storage::selectDateByBasis(Basis basis) {
    vector<Date> result{};
    for (int i = 0; i < storage.size(); i++) {
        if (storage[i].getBasis() == basis) {
            result.push_back(storage[i].getBasis().getDate());
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
