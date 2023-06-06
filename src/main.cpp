#include <any>
#include <vector>
#include "Investigation/Basis/Basis.hpp"
#include "Investigation/Investigation.hpp"
#include "Menu/Menu.hpp"
#include "Storage/Storage.hpp"

using std::any;
using std::any_cast;
using std::cout;
using std::endl;
using std::vector;
using Type = Investigation::Type;

void printAddedOrder(vector<std::any> params) {
    auto* storage = any_cast<Storage*>(params[0]);

    for (int i = 0; i < storage->size(); i++) {
        cout << storage->getAll()[i] << endl;
    }
}

void printSortedOrder(vector<std::any> params) {
    auto* storage = any_cast<Storage*>(params[0]);

    vector<Investigation> vec = storage->getAllOrdered();
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

void sortByNumber(vector<std::any> params) {
    auto* storage = any_cast<Storage*>(params[0]);

    vector<Investigation> vec = storage->sortByNumber();
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

void sortByName(vector<std::any> params) {
    auto* storage = any_cast<Storage*>(params[0]);

    vector<Investigation> vec = storage->sortByName();
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

void sortByBasisNumber(vector<std::any> params) {
    auto* storage = any_cast<Storage*>(params[0]);

    vector<Investigation> vec = storage->sortByBasisNumber();
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

void selectBasisByBasis(vector<std::any> params) {
    auto* storage = any_cast<Storage*>(params[0]);

    Basis basis;
    cin >> basis;

    // vector<Basis> vec = storage->selectBasisByBasis(basis);
    // for (int i = 0; i < vec.size(); i++) {
    //     cout << vec[i].toString() << endl;
    // }
}

int main() {
    using namespace YMM;
    // init data
    Storage storage;
    storage.add(Investigation(
        93670579,
        "University College London (UCL)",
        Date(2023, 7, 25),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(
            64966214,
            Date(2023, 10, 4),
            "Check University College London (UCL)")));

    storage.add(Investigation(
        43450165,
        "BMSTU",
        Date(2023, 2, 1),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(81435834, Date(2023, 4, 17), "Check BMSTU")));

    storage.add(Investigation(
        38239336,
        "Cambridge University",
        Date(2023, 6, 5),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(88412335, Date(2023, 7, 4), "Check Cambridge University")));

    storage.add(Investigation(
        30565240,
        "California Institute of Technology (Caltech)",
        Date(2023, 9, 18),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(
            89199115,
            Date(2023, 2, 22),
            "Check California Institute of Technology (Caltech)")));

    storage.add(Investigation(
        91299740,
        "BMSTU",
        Date(2023, 11, 6),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(24872565, Date(2023, 1, 22), "Check BMSTU")));

    storage.add(Investigation(
        35208763,
        "California Institute of Technology (Caltech)",
        Date(2023, 1, 11),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(
            97466769,
            Date(2023, 4, 21),
            "Check California Institute of Technology (Caltech)")));

    storage.add(Investigation(
        26746415,
        "University College London (UCL)",
        Date(2023, 12, 26),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(
            53181948,
            Date(2023, 8, 18),
            "Check University College London (UCL)")));

    storage.add(Investigation(
        19039307,
        "University of Chicago",
        Date(2023, 8, 13),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(51848283, Date(2023, 6, 9), "Check University of Chicago")));

    storage.add(Investigation(
        87609109,
        "BMSTU",
        Date(2023, 3, 27),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(84089119, Date(2023, 2, 22), "Check BMSTU")));

    storage.add(Investigation(
        89913126,
        "KF BMSTU",
        Date(2023, 12, 11),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(99932116, Date(2023, 8, 28), "Check KF BMSTU")));

    storage.add(Investigation(
        65485607,
        "University of California, Los Angeles (UCLA)",
        Date(2023, 5, 23),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(
            78946923,
            Date(2023, 9, 23),
            "Check University of California, Los Angeles (UCLA)")));

    storage.add(Investigation(
        79429946,
        "University of Toronto",
        Date(2023, 8, 6),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(42518498, Date(2023, 4, 24), "Check University of Toronto")));

    storage.add(Investigation(
        33359894,
        "KGU",
        Date(2023, 9, 5),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(81521495, Date(2023, 4, 14), "Check KGU")));

    storage.add(Investigation(
        50409440,
        "Harvard University",
        Date(2023, 7, 11),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(81931996, Date(2023, 1, 2), "Check Harvard University")));

    storage.add(Investigation(
        34719344,
        "KF BMSTU",
        Date(2023, 11, 16),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(10080090, Date(2023, 7, 3), "Check KF BMSTU")));

    storage.add(Investigation(
        60187258,
        "University of Chicago",
        Date(2023, 4, 16),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(62642177, Date(2023, 12, 21), "Check University of Chicago")));

    storage.add(Investigation(
        96517676,
        "University of Tokyo",
        Date(2023, 6, 4),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(44061684, Date(2023, 5, 11), "Check University of Tokyo")));

    storage.add(Investigation(
        67197693,
        "University of Toronto",
        Date(2023, 10, 20),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(51030876, Date(2023, 6, 5), "Check University of Toronto")));

    storage.add(Investigation(
        50564668,
        "Oxford University",
        Date(2023, 5, 6),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(23571457, Date(2023, 2, 5), "Check Oxford University")));

    storage.add(Investigation(
        11041444,
        "Imperial College London",
        Date(2023, 7, 14),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(82730713, Date(2023, 6, 5), "Check Imperial College London")));

    vector<std::any> params{&storage};

    Menu menu = Menu(
        "Labaratory Work 6",
        vector<Menu>{
            Menu(
                "Print",
                vector<Menu>{
                    Menu("Print in added order", printAddedOrder),
                    Menu(
                        "Print in sorted order (key - investigation number)",
                        printSortedOrder)}),
            Menu(
                "Sort",
                vector<Menu>{
                    Menu("Sort in investigation number order", sortByNumber),
                    Menu(
                        "Sort in investigation name alphabet order",
                        sortByName),
                    Menu("Sort in basis number order", sortByBasisNumber),
                }),
            Menu(
                "Search",
                vector<Menu>{
                    Menu("Basis (key - Basis)", selectBasisByBasis),
                    // Menu("Year and Month (key - Basis)", func2),
                    // Menu(
                    //     "Investigation name (key - investigation name)",
                        // func2)
                        }),
        },
        params);

    menu.run();

    return 0;
}
