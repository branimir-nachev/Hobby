//
// Created by Branimir Nachev on 17.02.21.
//

#ifndef WORK_FAMILYMEMBER_HPP
#define WORK_FAMILYMEMBER_HPP
#include <iostream>
#include <vector>
#include "Person.hpp"

using namespace std;

class FamilyMember {
protected:
    Person member;
    FamilyMember *mother;
    FamilyMember *father;
    vector<FamilyMember*> childrens;

public:
    FamilyMember(const Person &member);

    FamilyMember(const Person &member, FamilyMember *mother, FamilyMember *father);

    FamilyMember *getMother() const;

    void setMother(FamilyMember *mother);

    FamilyMember *getFather() const;

    void setFather(FamilyMember *father);

    void addChild(FamilyMember *child);

    const vector<FamilyMember *> &getChildrens() const;

    virtual ~FamilyMember();
};


#endif //WORK_FAMILYMEMBER_HPP
