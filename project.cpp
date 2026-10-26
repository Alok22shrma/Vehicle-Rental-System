
#include <iostream>
#include <string>
using namespace std;
class Vehicle {
protected:
    int vehicleID;
    string model;
    int days;

public:
    Vehicle(int id, string m, int d) {
        vehicleID = id;
        model = m;
        days = d;
    }

    virtual double calculateRent() = 0;
    
    virtual void display() {
        cout << "\nVehicle ID: " << vehicleID;
        cout << "\nModel: " << model;
        cout << "\nRental Duration: " << days << " days";
    }

    virtual ~Vehicle() {}
};
class Car : public Vehicle {
public:
    Car(int id, string m, int d)
        : Vehicle(id, m, d) {}

    double calculateRent() override {
        return days * 1500;
    }

    void display() override {
        cout << "\n--- CAR DETAILS ---";
        Vehicle::display();
        cout << "\nDaily Rate: Rs. 1500";
        cout << "\nTotal Rent: Rs. "
             << calculateRent() << endl;
    }
};
class Bike : public Vehicle {
public:
    Bike(int id, string m, int d)
        : Vehicle(id, m, d) {}

    double calculateRent() override {
        return days * 500;
    }
    void display() override {
        cout << "\n--- BIKE DETAILS ---";
        Vehicle::display();
        cout << "\nDaily Rate: Rs. 500";
        cout << "\nTotal Rent: Rs. "
             << calculateRent() << endl;
    }
};
int main() {
    int choice, id, days;
    string model;
    cout << "===== VEHICLE RENTAL SYSTEM =====\n";
    cout << "1. Rent a Car\n";
    cout << "2. Rent a Bike\n";
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice != 1 && choice != 2) {
        cout << "Invalid vehicle choice!\n";
        return 0;
    }
    cout << "Enter Vehicle ID: ";
    if (!(cin >> id) || id <= 0) {
        cout << "Invalid Vehicle ID!\n";
        return 0;
    }
    cout << "Enter Model (one word): ";
    cin >> model;
    cout << "Enter rental days: ";
    if (!(cin >> days) || days <= 0) {
        cout << "Invalid duration! Days must be positive.\n";
        return 0;
    }
    Vehicle* v;
    if (choice == 1) {
        v = new Car(id, model, days);
    } else {
        v = new Bike(id, model, days);
    }
    v->display();

    delete v;
    return 0;
}
