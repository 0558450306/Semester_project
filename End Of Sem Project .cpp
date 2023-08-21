#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Patient {
private:
 string name;
    int age;
 string medicalHistory;

public:
    Patient(string _name, int _age,string _medicalHistory)
        : name(_name), age(_age), medicalHistory(_medicalHistory) {}

    void displayInfo() const {
   cout << "Name: " << name << "\n";
   cout << "Age: " << age << "\n";
   cout << "Medical History: " << medicalHistory << "\n";
    }
};

int main() {
   vector<Patient> patients;

    while (true) {
        cout << "1. Add Patient\n2. Display Patient Information\n3. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string name;
            int age;
            string medicalHistory;
            
            cout << "Enter patient name: ";
            cin.ignore();
            getline(cin, name);
            
            cout << "Enter patient age: ";
            string ageStr;
            getline(cin, ageStr);
            age = stoi(ageStr); // Convert string to integer
            
            cout << "Enter medical history: ";
            getline(cin, medicalHistory);
            
            patients.push_back(Patient(name, age, medicalHistory));
            cout << "Patient information added successfully.\n";
        } else if (choice == 2) {
            for (const Patient &patient : patients) {
                patient.displayInfo();
                cout << "--------------------\n";
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}