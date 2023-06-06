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
        90471739,
        "Massachusetts Institute of Technology (MIT)",
        Date(2023, 8, 2),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(38533011, Date(2023, 2, 2), "Policy")));

    storage.add(Investigation(
        93294455,
        "McGill University",
        Date(2023, 6, 16),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(89188912, Date(2023, 5, 24), "Policy")));

    storage.add(Investigation(
        72101764,
        "KGU",
        Date(2023, 9, 2),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(64576011, Date(2023, 8, 10), "Security")));

    storage.add(Investigation(
        22323772,
        "University of Chicago",
        Date(2023, 6, 23),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(92097260, Date(2023, 9, 18), "Control")));

    storage.add(Investigation(
        93294455,
        "KF BMSTU",
        Date(2023, 6, 27),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(96766401, Date(2023, 11, 25), "Privacy")));

    storage.add(Investigation(
        53318612,
        "KGU",
        Date(2023, 8, 18),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(23177011, Date(2023, 12, 20), "Control")));

    storage.add(Investigation(
        15150285,
        "KGU",
        Date(2023, 10, 19),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(61075414, Date(2023, 11, 13), "Security")));

    storage.add(Investigation(
        83461541,
        "University of Pennsylvania",
        Date(2023, 10, 21),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(45836708, Date(2023, 11, 24), "Privacy")));

    storage.add(Investigation(
        93294455,
        "Stanford University",
        Date(2023, 6, 11),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(24986944, Date(2023, 6, 2), "Control")));

    storage.add(Investigation(
        81091156,
        "Cambridge University",
        Date(2023, 8, 1),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(77268071, Date(2023, 8, 25), "Privacy")));

    storage.add(Investigation(
        39177051,
        "University of California, Los Angeles (UCLA)",
        Date(2023, 8, 28),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(75083165, Date(2023, 11, 15), "Policy")));

    storage.add(Investigation(
        42084163,
        "Massachusetts Institute of Technology (MIT)",
        Date(2023, 5, 5),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(84970609, Date(2023, 6, 7), "Policy")));

    storage.add(Investigation(
        93085608,
        "University of California, Berkeley",
        Date(2023, 3, 27),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(72356570, Date(2023, 5, 15), "Security")));

    storage.add(Investigation(
        48803867,
        "Stanford University",
        Date(2023, 2, 24),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(38393191, Date(2023, 2, 19), "Policy")));

    storage.add(Investigation(
        78575237,
        "Harvard University",
        Date(2023, 3, 9),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(89461135, Date(2023, 7, 10), "Security")));

    storage.add(Investigation(
        47017009,
        "Oxford University",
        Date(2023, 2, 12),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(80223081, Date(2023, 8, 6), "Policy")));

    storage.add(Investigation(
        18332384,
        "University of Pennsylvania",
        Date(2023, 10, 22),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(57512718, Date(2023, 1, 22), "Privacy")));

    storage.add(Investigation(
        37905361,
        "University of Toronto",
        Date(2023, 4, 17),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(98495321, Date(2023, 10, 22), "Privacy")));

    storage.add(Investigation(
        96303533,
        "Princeton University",
        Date(2023, 8, 26),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(80646842, Date(2023, 4, 9), "Policy")));

    storage.add(Investigation(
        26503748,
        "Imperial College London",
        Date(2023, 9, 25),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(68146960, Date(2023, 10, 6), "Control")));

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
