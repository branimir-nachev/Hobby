//
// Created by Branimir Nachev on 17.02.21.
//

#include "FamilyMember.hpp"

FamilyMember::FamilyMember(const Person &member) : member(member) {
    mother = nullptr;
    father = nullptr;
}

FamilyMember::FamilyMember(const Person &member, FamilyMember *mother, FamilyMember *father) : member(member),
                                                                                               mother(mother),
                                                                                               father(father) {
    if (mother)
        mother->addChild(this);
    if (father)
        father->addChild(this);
}

FamilyMember *FamilyMember::getMother() const {
    return mother;
}

void FamilyMember::setMother(FamilyMember *mother) {
    if (mother){
        FamilyMember::mother = mother;
        FamilyMember::mother->addChild(this);
    }
}

FamilyMember *FamilyMember::getFather() const {
    return father;
}

void FamilyMember::setFather(FamilyMember *father) {
    if (father){
        FamilyMember::father = father;
        FamilyMember::father->addChild(this);
    }
}

const Person &FamilyMember::getMember() const {
    return member;
}

void FamilyMember::addChild(FamilyMember *child) {
    childrens.push_back(child);
}

const vector<FamilyMember *> &FamilyMember::getChildrens() const {
    return childrens;
}

FamilyMember::~FamilyMember() {

}
