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

    return 0;
}