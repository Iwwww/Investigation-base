#include <stdio.h>
#include <string.h>
#include <any>
#include <string>
#include <vector>
#include "Input/Input.hpp"
#include "Investigation/Basis/Basis.hpp"
#include "Investigation/Investigation.hpp"
#include "Menu/Menu.hpp"
#include "Storage/Storage.hpp"

using std::any;
using std::any_cast;
using std::cout;
using std::endl;
using std::getline;
using std::vector;
using Type = Investigation::Type;

string getString() {
    string input;
    getline(cin, input);
    return input;
}

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
    try {
        cin >> basis;
    } catch (const std::invalid_argument&) {
        cout << "Invalid argument\n";
        return;
    }

    vector<Investigation> vec = storage->selectBasisByBasis(basis);
    cout << "\n";
    cout << "Search results:\n";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].getName() << " " << vec[i].getBasis().toString() << endl;
    }
}

void selectDateByBasis(vector<std::any> params) {
    auto* storage = any_cast<Storage*>(params[0]);

    Basis basis;
    try {
        cin >> basis;
    } catch (const std::invalid_argument&) {
        cout << "Invalid argument\n";
        return;
    }

    vector<Investigation> vec = storage->selectDateByBasis(basis);
    cout << "\n";
    cout << "Search results:\n";
    for (int i = 0; i < vec.size(); i++) {
        Date date = vec[i].getBasis().getDate();
        cout << std::left << setw(47) << vec[i].getName() << " "
             << date.getYear() << "-" << date.getMonth() << endl;
    }
}

void selectNameByName(vector<std::any> params) {
    auto* storage = any_cast<Storage*>(params[0]);

    cout << "Investigation place: ";
    string name;
    cin >> name;

    vector<Investigation> vec = storage->selectNameByName(name);
    cout << "\n";
    cout << "Search results:\n";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

int main() {
    using namespace YMM;
    // init data
    Storage storage;
    storage.add(Investigation(
        35219244,
        "StanfordUniversity",
        Date(2023, 7, 9),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(55033570, Date(2023, 6, 1), "Security")));

    storage.add(Investigation(
        20553574,
        "McGillUniversity",
        Date(2023, 6, 8),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(45435922, Date(2023, 5, 5), "Control")));

    storage.add(Investigation(
        46915500,
        "KGU",
        Date(2023, 10, 8),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(55033570, Date(2023, 7, 1), "Security")));

    storage.add(Investigation(
        88465734,
        "McGillUniversity",
        Date(2023, 8, 10),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(18175691, Date(2023, 11, 7), "Privacy")));

    storage.add(Investigation(
        37436516,
        "MassachusettsInstituteOfTechnology",
        Date(2023, 12, 16),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(50425947, Date(2023, 8, 24), "Control")));

    storage.add(Investigation(
        86716173,
        "PrincetonUniversity",
        Date(2023, 4, 14),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(33360461, Date(2023, 12, 16), "Policy")));

    storage.add(Investigation(
        60055320,
        "UniversityOfToronto",
        Date(2023, 6, 24),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(98384299, Date(2023, 6, 17), "Privacy")));

    storage.add(Investigation(
        43399174,
        "CaliforniaInstituteOfTechnology",
        Date(2023, 2, 9),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(57020234, Date(2023, 6, 4), "Control")));

    storage.add(Investigation(
        92714882,
        "UniversityOfPennsylvania",
        Date(2023, 3, 4),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(71585481, Date(2023, 2, 28), "Security")));

    storage.add(Investigation(
        16847719,
        "StanfordUniversity",
        Date(2023, 2, 5),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(21316053, Date(2023, 1, 21), "Privacy")));

    storage.add(Investigation(
        43961763,
        "UniversityOfPennsylvania",
        Date(2023, 9, 3),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(65019618, Date(2023, 12, 13), "Privacy")));

    storage.add(Investigation(
        31218189,
        "BMSTU",
        Date(2023, 6, 9),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(41241436, Date(2023, 5, 22), "Security")));

    storage.add(Investigation(
        21387939,
        "UniversityOfTokyo",
        Date(2023, 1, 18),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(54736769, Date(2023, 9, 2), "Control")));

    storage.add(Investigation(
        31218189,
        "BMSTU",
        Date(2023, 11, 19),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(79482768, Date(2023, 7, 1), "Security")));

    storage.add(Investigation(
        18836347,
        "UniversityOfPennsylvania",
        Date(2023, 11, 21),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(28210158, Date(2023, 8, 23), "Policy")));

    storage.add(Investigation(
        73912258,
        "KFBMSTU",
        Date(2023, 11, 13),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(10462014, Date(2023, 8, 3), "Control")));

    storage.add(Investigation(
        31218189,
        "UniversityOfTokyo",
        Date(2023, 5, 19),
        "This is description",
        Investigation::Type::FinancialControl,
        Basis(35703293, Date(2023, 10, 12), "Control")));

    storage.add(Investigation(
        81785491,
        "KFBMSTU",
        Date(2023, 6, 22),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(85415490, Date(2023, 11, 9), "Security")));

    storage.add(Investigation(
        99150134,
        "ImperialCollegeLondon",
        Date(2023, 7, 17),
        "This is description",
        Investigation::Type::StateProcurementControl,
        Basis(86372529, Date(2023, 6, 17), "Control")));

    storage.add(Investigation(
        75585227,
        "ImperialCollegeLondon",
        Date(2023, 2, 6),
        "This is description",
        Investigation::Type::StateServicesControl,
        Basis(41427911, Date(2023, 7, 23), "Policy")));

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
                "Search Investigation by",
                vector<Menu>{
                    Menu("Basis (key - Basis)", selectBasisByBasis),
                    Menu("Date (key - Basis)", selectDateByBasis),
                    Menu("Place (key - name)", selectNameByName),
                }),
        },
        params);

    menu.run();

    return 0;
}
