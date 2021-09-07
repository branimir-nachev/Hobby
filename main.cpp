#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <thread>
#include <chrono>
#include "FamilyMember.hpp"

using namespace std;
using namespace std::chrono_literals;

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

    auto start = chrono::high_resolution_clock::now();

    Person Petko{ "Petko","Nachev" };
    Person Maria{ "Maria","Nacheva" };
    Person Jana{ "Snegana","Hristova" };
    Person Ico{ "Hristo","Todorov" };
    Person Branimir{ "Branimir","Nachev" };
    Person Vania{ "Vania","Hristova" };
    Person Vicky{ "Victoria","Nacheva" };
    Person Margarita{"Margarita","Nacheva"};
    Person Stefan{"Stefan","Nikolov"};
    Person Volen{"Volen","Nikolov"};

    FamilyMember fPetko{ Petko };
    FamilyMember fMaria{ Maria };
    FamilyMember fJana{ Jana };
    FamilyMember fIco{ Ico };
    FamilyMember fBranimir{ Branimir,&fMaria,&fPetko };
    FamilyMember fVania{ Vania,&fJana,&fIco };
    FamilyMember fVicky{ Vicky,&fVania,&fBranimir };
    FamilyMember fMargarita {Margarita,&fMaria,&fPetko};
    FamilyMember fStefan{ Stefan,&fMaria,&fPetko };
    FamilyMember fVolen (Volen,&fMargarita,&fStefan);

    cout << "---------------------------------------------------" << endl;

    cout << "Parents of " << fVicky.getMember().getFullName() <<
         " are : \n\tMother => " <<
         fVicky.getMother()->getMember().getFullName() <<
         "\n and \n\tFather => " <<
         fVicky.getFather()->getMember().getFullName() <<
         endl << "GrandMa and Pa : " <<
         "\n\t GrandMother => " <<
         fVicky.getFather()->getMother()->getMember().getFullName() <<
         "\nand \n\t GrandFather => " <<
         fVicky.getFather()->getFather()->getMember().getFullName() <<
         "\n and" <<
         "\n\t GrandMother => " <<
         fVicky.getFather()->getMother()->getMember().getFullName() <<
         "\nand \n\t GrandFather => " <<
         fVicky.getFather()->getFather()->getMember().getFullName() << endl;

    cout << "---------------------------------------------------" << endl;

    cout << fBranimir.getMember().getFullName() << " has a child with name : \n\t" <<
         fBranimir.getChildrens().back()->getMember().getFullName() << endl;

    cout << "Parents of " << fBranimir.getMember().getFullName() <<
         " are : \n\tMother => " <<
         fBranimir.getMother()->getMember().getFullName() <<
         "\n and \n\tFather => " <<
         fBranimir.getFather()->getMember().getFullName() << endl;

    cout << "---------------------------------------------------" << endl;

    cout << fVania.getMember().getFullName() << " has a child with name : \n\t" <<
         fBranimir.getChildrens().back()->getMember().getFullName() << endl;

    cout << "Parents of " << fVania.getMember().getFullName() <<
         " are : \n\tMother => " <<
         fVania.getMother()->getMember().getFullName() <<
         "\n and \n\tFather => " <<
         fVania.getFather()->getMember().getFullName() << endl;

    std::cout << "\nThe cildren of " << fMaria.getMember().getFullName() << " are : " << std::endl;

    for (auto child : fMaria.getChildrens())
    {
        std::cout << "\tChild : " << std::endl;
        std::cout << child->getMember().getFullName() << std::endl;
        std::cout << "\tHis child : \n" << child->getChildrens().back()->getMember().getFullName() << std::endl;
        std::cout << "\tAnd her Grand Parents : " << std::endl;
        std::cout << child->getChildrens().back()->getMother()->getMother()->getMember().getFullName() << std::endl;
        std::cout << child->getChildrens().back()->getMother()->getFather()->getMember().getFullName() << std::endl;
        std::cout << child->getChildrens().back()->getFather()->getMother()->getMember().getFullName() << std::endl;
        std::cout << child->getChildrens().back()->getFather()->getFather()->getMember().getFullName() << std::endl;
    }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double,std::milli> duration = end - start;
    cout << "\n\nTime for the iterations : " << duration.count() << " ms" << endl;

    return 0;
}
