#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Patient {
    string name;
    int priority;

    bool operator<(const Patient& other) const {
        return priority < other.priority;
    }
};

int main() {
    priority_queue<Patient> patientQueue;

    int numPatients;
    cout << "Enter the number of patients: ";
    cin >> numPatients;

    // Enqueue patients
    for (int i = 0; i < numPatients; i++) {
        Patient p;
        cout << "Patient " << i + 1 << ":\n";
        cout << "Enter the patient name: ";
        cin.ignore();
        getline(cin, p.name);
        cout << "Enter the patient priority (1 for Serious, 2 for Non-Serious, 3 for General Checkup): ";
        cin >> p.priority;

        patientQueue.push(p);
    }

    // Serve patients
    cout << "\nServing patients:\n";
    while (!patientQueue.empty()) {
        Patient currentPatient = patientQueue.top();
        patientQueue.pop();

        cout << "Serving patient: " << currentPatient.name << " (Priority: " << currentPatient.priority << ")" << endl;
    }

    return 0;
}
