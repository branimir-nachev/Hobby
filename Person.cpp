//
// Created by Branimir Nachev on 17.02.21.
//

#include "Person.hpp"

Person::Person() {}

Person::Person(const string &firstName, const string &lastName) : firstName(firstName), lastName(lastName) {
    fullName = firstName + " " + lastName;
}

const string &Person::getFirstName() const {
    return firstName;
}

const string &Person::getLastName() const {
    return lastName;
}

const string &Person::getFullName() const {
    return fullName;
}

void Person::setFirstName(const string &firstName) {
    Person::firstName = firstName;
}

void Person::setLastName(const string &lastName) {
    Person::lastName = lastName;
}

Person::~Person() {

}


