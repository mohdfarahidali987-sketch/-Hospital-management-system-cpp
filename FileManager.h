#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>
#include <iostream>

using namespace std;

class FileManager {

public:

    static void savePatient(string data) {

        ofstream file("patients.txt", ios::app);

        file << data << endl;

        file.close();
    }

    static void saveDoctor(string data) {

        ofstream file("doctors.txt", ios::app);

        file << data << endl;

        file.close();
    }

    static void saveAppointment(string data) {

        ofstream file("appointments.txt", ios::app);

        file << data << endl;

        file.close();
    }
};

#endif