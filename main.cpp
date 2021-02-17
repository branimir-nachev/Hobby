#include <iostream>
#include <vector>
#include <map>
#include "FamilyMember.hpp"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Дебъг-а винаги се rebuild-ва !" <<std::endl;
    vector<int> myVector = {1,2,3,4,5,6,7,8,9,0};
    sort(myVector.begin(),myVector.end());
    map<int,char> myMap;
    for (int i=0; i <  myVector.size(); i++)
    {
        myMap.emplace(make_pair(myVector.at(i),static_cast<char>(myVector.at(i)+65)));
        cout << "За ключ " << i << " записът е " << myMap[i] << endl;
    }

    cout << endl;

    Person Branimir {"Бранимир","Начев"};
    Person Vania {"Ваня","Христова"};
    Person Vicky {"Виктория","Начева"};

    FamilyMember fBranimir {Branimir};
    FamilyMember fVania {Vania};
    FamilyMember fVicky {Vicky,&fVania,&fBranimir};

    cout << "Родители на " << fVicky.getMember().getFullName() << " са : \n\tМайка => " <<
            fVicky.getMother()->getMember().getFullName() << "\n и \n\tБаща => " <<
            fVicky.getFather()->getMember().getFullName() << endl;

    cout << fBranimir.getMember().getFullName() << " има дете на име : \n\t" <<
            fBranimir.getChildrens().back()->getMember().getFullName() << endl;

    cout << fVania.getMember().getFullName() << " има дете на име : \n\t" <<
         fBranimir.getChildrens().back()->getMember().getFullName() << endl;

    return 0;
}
