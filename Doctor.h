#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"

class Doctor : public Person {

private:
    string specialization;

public:

    Doctor() {}

    Doctor(int id, string name, int age, string specialization)
        : Person(id, name, age) {

        this->specialization = specialization;
    }

    string getSpecialization() {
        return specialization;
    }

    void display() override {

        cout << "\nDoctor ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Specialization: " << specialization << endl;
    }
};

#endif