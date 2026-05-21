#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "Patient.h"
#include "Doctor.h"
#include "Appointment.h"
#include "FileManager.h"

using namespace std;

class Hospital {

private:

    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

public:

    // ---------------- LOAD PATIENTS ----------------

    void loadPatients() {

        ifstream file("patients.txt");

        if (!file)
            return;

        string line;

        while (getline(file, line)) {

            stringstream ss(line);

            string idStr, name, ageStr, disease;

            getline(ss, idStr, ',');
            getline(ss, name, ',');
            getline(ss, ageStr, ',');
            getline(ss, disease, ',');

            int id = stoi(idStr);
            int age = stoi(ageStr);

            Patient p(id, name, age, disease);

            patients.push_back(p);
        }

        file.close();
    }

    // ---------------- LOAD DOCTORS ----------------

    void loadDoctors() {

        ifstream file("doctors.txt");

        if (!file)
            return;

        string line;

        while (getline(file, line)) {

            stringstream ss(line);

            string idStr, name, ageStr, specialization;

            getline(ss, idStr, ',');
            getline(ss, name, ',');
            getline(ss, ageStr, ',');
            getline(ss, specialization, ',');

            int id = stoi(idStr);
            int age = stoi(ageStr);

            Doctor d(id, name, age, specialization);

            doctors.push_back(d);
        }

        file.close();
    }

    // ---------------- LOAD APPOINTMENTS ----------------

    void loadAppointments() {

        ifstream file("appointments.txt");

        if (!file)
            return;

        string line;

        while (getline(file, line)) {

            stringstream ss(line);

            string patient, doctor, date;

            getline(ss, patient, ',');
            getline(ss, doctor, ',');
            getline(ss, date, ',');

            Appointment a(patient, doctor, date);

            appointments.push_back(a);
        }

        file.close();
    }

    // ---------------- ADD PATIENT ----------------

    void addPatient(Patient patient) {

        patients.push_back(patient);

        FileManager::savePatient(
            to_string(patient.getId()) + "," +
            patient.getName() + "," +
            to_string(patient.getAge()) + "," +
            patient.getDisease()
        );

        cout << "\nPatient Added Successfully!\n";
    }

    // ---------------- VIEW PATIENTS ----------------

    void viewPatients() {

        if (patients.empty()) {

            cout << "\nNo Patients Found!\n";
            return;
        }

        for (auto &p : patients) {
            p.display();
        }
    }

    // ---------------- SEARCH PATIENT ----------------

    void searchPatient(int id) {

        bool found = false;

        for (auto &p : patients) {

            if (p.getId() == id) {

                p.display();
                found = true;
            }
        }

        if (!found) {
            cout << "\nPatient Not Found!\n";
        }
    }

    // ---------------- DELETE PATIENT ----------------

    void deletePatient(int id) {

        auto it = remove_if(
            patients.begin(),
            patients.end(),

            [id](Patient &p) {
                return p.getId() == id;
            }
        );

        if (it != patients.end()) {

            patients.erase(it, patients.end());

            rewritePatientsFile();

            cout << "\nPatient Deleted Successfully!\n";
        }

        else {
            cout << "\nPatient Not Found!\n";
        }
    }

    // ---------------- ADD DOCTOR ----------------

    void addDoctor(Doctor doctor) {

        doctors.push_back(doctor);

        FileManager::saveDoctor(
            to_string(doctor.getId()) + "," +
            doctor.getName() + "," +
            to_string(doctor.getAge()) + "," +
            doctor.getSpecialization()
        );

        cout << "\nDoctor Added Successfully!\n";
    }

    // ---------------- VIEW DOCTORS ----------------

    void viewDoctors() {

        if (doctors.empty()) {

            cout << "\nNo Doctors Found!\n";
            return;
        }

        for (auto &d : doctors) {
            d.display();
        }
    }

    // ---------------- SEARCH DOCTOR ----------------

    void searchDoctor(int id) {

        bool found = false;

        for (auto &d : doctors) {

            if (d.getId() == id) {

                d.display();
                found = true;
            }
        }

        if (!found) {
            cout << "\nDoctor Not Found!\n";
        }
    }

    // ---------------- DELETE DOCTOR ----------------

    void deleteDoctor(int id) {

        auto it = remove_if(
            doctors.begin(),
            doctors.end(),

            [id](Doctor &d) {
                return d.getId() == id;
            }
        );

        if (it != doctors.end()) {

            doctors.erase(it, doctors.end());

            rewriteDoctorsFile();

            cout << "\nDoctor Deleted Successfully!\n";
        }

        else {
            cout << "\nDoctor Not Found!\n";
        }
    }

    // ---------------- BOOK APPOINTMENT ----------------

    void bookAppointment(Appointment appointment) {

        appointments.push_back(appointment);

        FileManager::saveAppointment(
            appointment.getPatientName() + "," +
            appointment.getDoctorName() + "," +
            appointment.getDate()
        );

        cout << "\nAppointment Booked Successfully!\n";
    }

    // ---------------- VIEW APPOINTMENTS ----------------

    void viewAppointments() {

        if (appointments.empty()) {

            cout << "\nNo Appointments Found!\n";
            return;
        }

        for (auto &a : appointments) {
            a.display();
        }
    }

    // ---------------- REWRITE PATIENT FILE ----------------

    void rewritePatientsFile() {

        ofstream file("patients.txt");

        for (auto &p : patients) {

            file
                << p.getId() << ","
                << p.getName() << ","
                << p.getAge() << ","
                << p.getDisease()
                << endl;
        }

        file.close();
    }

    // ---------------- REWRITE DOCTOR FILE ----------------

    void rewriteDoctorsFile() {

        ofstream file("doctors.txt");

        for (auto &d : doctors) {

            file
                << d.getId() << ","
                << d.getName() << ","
                << d.getAge() << ","
                << d.getSpecialization()
                << endl;
        }

        file.close();
    }
};

#endif