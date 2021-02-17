//
// Created by Branimir Nachev on 17.02.21.
//

#ifndef WORK_PERSON_HPP
#define WORK_PERSON_HPP

#include <iostream>

using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    string fullName;
public:
    Person(const string &firstName, const string &lastName);

    Person();

    const string &getFirstName() const;

    const string &getLastName() const;

    const string &getFullName() const;

    void setFirstName(const string &firstName);

    void setLastName(const string &lastName);

    virtual ~Person();
};

#endif //WORK_PERSON_HPP
