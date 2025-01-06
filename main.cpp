#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string *fullName;

public:
    Person(const string &name) {
        fullName = new string(name);
    }

    Person(const Person &p) {
        fullName = new string(*p.fullName);
    }

    ~Person() {
        delete fullName;
    }

    void displayName() const {
        cout << *fullName << endl;
    }
};

class Apartment {
private:
    Person **residents; 
    int residentsCount;

public:
    Apartment(int count) : residentsCount(count) {
        residents = new Person*[residentsCount];
        for (int i = 0; i < residentsCount; ++i) {
            string name;
            cout << "enter name for resident " << i + 1 << ": ";
            cin >> name;
            residents[i] = new Person(name);
        }
    }

    Apartment(const Apartment &a) : residentsCount(a.residentsCount) {
        residents = new Person*[residentsCount];
        for (int i = 0; i < residentsCount; ++i) {
            residents[i] = new Person(*a.residents[i]);
        }
    }

    ~Apartment() {
        for (int i = 0; i < residentsCount; ++i) {
            delete residents[i];
        }
        delete[] residents;
    }

    void displayResidents() const {
        for (int i = 0; i < residentsCount; ++i) {
            cout << "resident " << i + 1 << ": ";
            residents[i]->displayName();
        }
    }
};

class Building {
private:
    Apartment **flats; 
    int apartmentsCount;

public:
    Building(int count) : apartmentsCount(count) {
        flats = new Apartment*[apartmentsCount];
        for (int i = 0; i < apartmentsCount; ++i) {
            int numResidents;
            cout << "enter number of residents for apartment " << i + 1 << ": ";
            cin >> numResidents;
            flats[i] = new Apartment(numResidents);
        }
    }

    Building(const Building &b) : apartmentsCount(b.apartmentsCount) {
        flats = new Apartment*[apartmentsCount];
        for (int i = 0; i < apartmentsCount; ++i) {
            flats[i] = new Apartment(*b.flats[i]);
        }
    }

    ~Building() {
        for (int i = 0; i < apartmentsCount; ++i) {
            delete flats[i];
        }
        delete[] flats;
    }

    void displayBuilding() const {
        for (int i = 0; i < apartmentsCount; ++i) {
            cout << "apartment " << i + 1 << " residents:" << endl;
            flats[i]->displayResidents();
        }
    }
};

int main() {
    int apartments;
    cout << "how many apartments in the building? ";
    cin >> apartments;

    Building b(apartments);

    cout << "\ndisplaying all residents in the building:" << endl;
    b.displayBuilding(); 

    return 0;
}
