//
// Created by Branimir Nachev on 17.02.21.
//

#include "FamilyMember.hpp"

FamilyMember::FamilyMember(const Person &member) : member(member) {}

FamilyMember::FamilyMember(const Person &member, FamilyMember *mother, FamilyMember *father) : member(member),
                                                                                               mother(mother),
                                                                                               father(father) {}

FamilyMember *FamilyMember::getMother() const {
    return mother;
}

void FamilyMember::setMother(FamilyMember *mother) {
    FamilyMember::mother = mother;
}

FamilyMember *FamilyMember::getFather() const {
    return father;
}

void FamilyMember::setFather(FamilyMember *father) {
    FamilyMember::father = father;
}

const vector<FamilyMember *> &FamilyMember::getChildrens() const {
    return childrens;
}

void FamilyMember::setChildrens(const vector<FamilyMember *> &childrens) {
    FamilyMember::childrens = childrens;
}

FamilyMember::~FamilyMember() {

}
