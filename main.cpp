#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "FamilyMember.hpp"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Дебъг-а винаги се rebuild-ва !" << std::endl;
    vector<int> myVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    sort(myVector.begin(), myVector.end());
    map<int, char> myMap;
    for (int i = 0; i < myVector.size(); i++) {
        myMap.emplace(make_pair(myVector.at(i), static_cast<char>(myVector.at(i) + 65)));
        cout << "За ключ " << i << " записът е " << myMap[i] << endl;
    }

    cout << endl;

    Person Petko{"Петко", "Начев"};
    Person Maria{"Мария", "Начева"};
    Person Jana{"Снежана", "Христова"};
    Person Ico{"Христо", "Тодоров"};
    Person Branimir{"Бранимир", "Начев"};
    Person Vania{"Ваня", "Христова"};
    Person Vicky{"Виктория", "Начева"};

    FamilyMember fPetko{Petko};
    FamilyMember fMaria{Maria};
    FamilyMember fJana{Jana};
    FamilyMember fIco{Ico};
    FamilyMember fBranimir{Branimir, &fMaria, &fPetko};
    FamilyMember fVania{Vania, &fJana, &fIco};
    FamilyMember fVicky{Vicky, &fVania, &fBranimir};

    cout << "---------------------------------------------------" << endl;

    cout << "Родители на " << fVicky.getMember().getFullName() <<
         " са : \n\tМайка => " <<
         fVicky.getMother()->getMember().getFullName() <<
         "\n и \n\tБаща => " <<
         fVicky.getFather()->getMember().getFullName() <<
         endl << "баба и дядо са : " <<
         "\n\t Баба => " <<
         fVicky.getFather()->getMother()->getMember().getFullName() <<
         "\nи \n\t Дядо => " <<
         fVicky.getFather()->getFather()->getMember().getFullName() <<
         "\n и" <<
         "\n\t Баба => " <<
         fVicky.getFather()->getMother()->getMember().getFullName() <<
         "\nи \n\t Дядо => " <<
         fVicky.getFather()->getFather()->getMember().getFullName() << endl;

    cout << "---------------------------------------------------" << endl;

    cout << fBranimir.getMember().getFullName() << " има дете на име : \n\t" <<
         fBranimir.getChildrens().back()->getMember().getFullName() << endl;

    cout << "Родители на " << fBranimir.getMember().getFullName() <<
         " са : \n\tМайка => " <<
         fBranimir.getMother()->getMember().getFullName() <<
         "\n и \n\tБаща => " <<
         fBranimir.getFather()->getMember().getFullName() << endl;

    cout << "---------------------------------------------------" << endl;

    cout << fVania.getMember().getFullName() << " има дете на име : \n\t" <<
         fBranimir.getChildrens().back()->getMember().getFullName() << endl;

    cout << "Родители на " << fVania.getMember().getFullName() <<
         " са : \n\tМайка => " <<
         fVania.getMother()->getMember().getFullName() <<
         "\n и \n\tБаща => " <<
         fVania.getFather()->getMember().getFullName() << endl;

    return 0;
}
