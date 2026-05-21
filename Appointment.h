#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>

using namespace std;

class Appointment {

private:
    string patientName;
    string doctorName;
    string date;

public:

    Appointment() {}

    Appointment(string p, string d, string dt) {
        patientName = p;
        doctorName = d;
        date = dt;
    }

    string getPatientName() {
        return patientName;
    }

    string getDoctorName() {
        return doctorName;
    }

    string getDate() {
        return date;
    }

    void display() {

        cout << "\nPatient: " << patientName << endl;
        cout << "Doctor: " << doctorName << endl;
        cout << "Date: " << date << endl;
    }
};

#endif