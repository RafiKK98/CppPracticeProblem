#include <iostream>
#include <string>
using namespace std;

class Address
{
    int houseNo, roadNo, zipCode;
    string street, thana, district;
public:
    friend istream& operator>>(istream& in, Address& e);
    friend ostream& operator<<(ostream& out, Address& a);

    Address() {
        houseNo = roadNo = zipCode = 0000;
        street = thana = district = "TBA";
    }

    void setAddress() {
        cout << "Enter house no :"; cin >> houseNo;
        cout << "Enter road no :"; cin >> roadNo;
        cout << "Enter street name :"; cin >> street;
        cout << "Enter thana name :"; cin >> thana;
        cout << "Enter district name :"; cin >> district;
        cout << "Enter Zip code :"; cin >> zipCode;
    }

    int getHouseNo() {
        return houseNo;
    }
    int getRoadNo() {
        return roadNo;
    }
    int getZipCode() {
        return zipCode;
    }
};

class Employee
{
    int employeeID;
    string name, department;
    Address empAddress;

public:
    friend istream& operator>>(istream&, Employee&);
    friend ostream& operator<<(ostream& out, Employee& e);

    Employee() {
        employeeID = 0000;
        name = department = "TBA";   
    }

    Employee(int ID, string Name, string Dept) {
        employeeID = ID;
        name = Name;
        department = Dept;
        cin >> empAddress;
    }

    void setEmployeeID() {
        cout << "Enter employee ID :";  cin >> employeeID;
    }
    void setEmployeeName() {
        cout << "Enter employee name :";
        getline(cin, name);
        cin.ignore();
    }
    void setEmployeeDepartment() {
        cout << "Enter employee department :";
        getline(cin, department);
        cin.ignore();
    }

    bool operator==(int zip) {
        if (empAddress.getZipCode() == zip)
            return true;
        else
            return false;
    }
    
};
istream& operator>>(istream& in, Address& a) {
    cout << "Enter house no :"; in >> a.houseNo;
    cout << "Enter road no :"; in >> a.roadNo; in.ignore();
    cout << "Enter street name :"; getline(in, a.street); //in.ignore();
    cout << "Enter thana name :"; getline(in, a.thana); //in.ignore();
    cout << "Enter district name :"; getline(in, a.district); //in.ignore();
    cout << "Enter Zip code :"; in >> a.zipCode; in.ignore();

    return in;
}

ostream& operator<<(ostream& out, Address& a) {
    out << "House no :" << a.houseNo << endl;
    out << "Road no :" << a.roadNo << endl; 
    out << "Street name :" << a.street << endl;
    out << "Thana name :" << a.thana << endl;
    out << "District name :" << a.district << endl;
    out << "Zip Code :" << a.zipCode << endl;

    return out;
}
istream& operator>>(istream& in, Employee& e) {
    cout << "Enter employee ID :"; in >> e.employeeID; in.ignore();
    cout << "Enter employee name :"; getline(in, e.name);
    cout << "Enter employee department :"; getline(in, e.department);
    in >> e.empAddress;
    return in;
}
ostream& operator<<(ostream& out, Employee& e) {
    out << "Employee ID :" << e.employeeID << endl;
    out << "Employee name :" << e.name << endl;
    out << "Employee department :" << e.department << endl;
    out << e.empAddress << endl;

    return out;
}

int main()
{
    Employee e1, e2(4161, "S K Dey", "CSE");
    //parameterized constructor also ask for address details

    cout << "\nGive input for employee 1: " << endl;
    cin >> e1;
    //Should ask employeeID, name, department.
    //Then ask address related information.

    cout << "\nComplete information of the employees are : " << endl;
    cout << e1 << e2 << endl;

    cout << "\nThe employee e1 ";
    if (e1 == 1229) cout << "lives in Bashundhara R / A." << endl;
    else cout << "does NOT lives in Bashundhara R / A." << endl;
    //comparing zipCode field

    return 0;
}
