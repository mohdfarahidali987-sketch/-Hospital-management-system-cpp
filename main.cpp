#include <iostream>

#include "Hospital.h"

using namespace std;

int main() {

    Hospital hospital;

    // LOAD SAVED DATA

    hospital.loadPatients();
    hospital.loadDoctors();
    hospital.loadAppointments();

    int choice;

    while (true) {

        cout << " HOSPITAL MANAGEMENT SYSTEM  "<<endl;

        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Delete Patient\n";

        cout << "5. Add Doctor\n";
        cout << "6. View Doctors\n";
        cout << "7. Search Doctor\n";
        cout << "8. Delete Doctor\n";

        cout << "9. Book Appointment\n";
        cout << "10. View Appointments\n";

        cout << "11. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        // ---------------- ADD PATIENT ----------------

        if (choice == 1) {

            int id, age;
            string name, disease;

            cout << "Enter Patient ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Age: ";
            cin >> age;

            cin.ignore();

            cout << "Enter Disease: ";
            getline(cin, disease);

            Patient p(id, name, age, disease);

            hospital.addPatient(p);
        }

        // ---------------- VIEW PATIENTS ----------------

        else if (choice == 2) {

            hospital.viewPatients();
        }

        // ---------------- SEARCH PATIENT ----------------

        else if (choice == 3) {

            int id;

            cout << "Enter Patient ID: ";
            cin >> id;

            hospital.searchPatient(id);
        }

        // ---------------- DELETE PATIENT ----------------

        else if (choice == 4) {

            int id;

            cout << "Enter Patient ID: ";
            cin >> id;

            hospital.deletePatient(id);
        }

        // ---------------- ADD DOCTOR ----------------

        else if (choice == 5) {

            int id, age;
            string name, specialization;

            cout << "Enter Doctor ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Age: ";
            cin >> age;

            cin.ignore();

            cout << "Enter Specialization: ";
            getline(cin, specialization);

            Doctor d(id, name, age, specialization);

            hospital.addDoctor(d);
        }

        // ---------------- VIEW DOCTORS ----------------

        else if (choice == 6) {

            hospital.viewDoctors();
        }

        // ---------------- SEARCH DOCTOR ----------------

        else if (choice == 7) {

            int id;

            cout << "Enter Doctor ID: ";
            cin >> id;

            hospital.searchDoctor(id);
        }

        // ---------------- DELETE DOCTOR ----------------

        else if (choice == 8) {

            int id;

            cout << "Enter Doctor ID: ";
            cin >> id;

            hospital.deleteDoctor(id);
        }

        // ---------------- BOOK APPOINTMENT ----------------

        else if (choice == 9) {

            string patientName, doctorName, date;

            cin.ignore();

            cout << "Enter Patient Name: ";
            getline(cin, patientName);

            cout << "Enter Doctor Name: ";
            getline(cin, doctorName);

            cout << "Enter Appointment Date: ";
            getline(cin, date);

            Appointment a(
                patientName,
                doctorName,
                date
            );

            hospital.bookAppointment(a);
        }

        // ---------------- VIEW APPOINTMENTS ----------------

        else if (choice == 10) {

            hospital.viewAppointments();
        }

        else if (choice == 11) {

            cout << "\nThank You!\n";
            break;
        }

        else {
            cout << "\nInvalid Choice!\n";
        }
    }

    return 0;
}