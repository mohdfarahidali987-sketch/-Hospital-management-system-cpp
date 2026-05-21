#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"

class Patient : public Person {

private:
    string disease;

public:

    Patient() {}

    Patient(int id, string name, int age, string disease)
        : Person(id, name, age) {

        this->disease = disease;
    }

    string getDisease() {
        return disease;
    }

    void display() override {

        cout << "\nPatient ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Disease: " << disease << endl;
    }
};

#endif