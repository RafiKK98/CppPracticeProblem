#include <iostream>
#include <string>

class Date {
    int day, year;
    std::string month;
public:
    Date() {
        day = 00;
        month = "TBA";
        year = 0000;
    }

    int getDay() {
        return day;
    }
    std::string getMonth() {
        return month;
    }
    int getYear() {
        return year;
    }
    void setDate() {
        std::cout << "Enter day :";
        std::cin >> day;
        std::cin.ignore();
        std::cout << "Enter month :";
        getline(std::cin, month);
        std::cout << "Enter year :";
        std::cin >> year;
        std::cin.ignore();
    }
};

class Employee {
    int employeeID;
    std::string name, department;
    Date dateOfJoining;
public:
    friend std::istream& operator>>(std::istream& in, Employee& employee);
    friend std::ostream& operator<<(std::ostream& out, Employee& employee);

    Employee() {
        employeeID = 0000;
        name = "TBA";
        department = "TBA";
    }
    Employee(int empID, std::string Name, std::string Dept) {
        employeeID = empID;
        name = Name;
        department = Dept;
        dateOfJoining.setDate();
    }

    void setID(int empID) {
        employeeID = empID;
    }
    void setName(std::string Name) {
        name = Name;
    }
    void setDepartment(std::string dept) {
        department = dept;
    }
    int getID() {
        return employeeID;
    }
    std::string getName() {
        return name;
    }
    std::string getDepartment() {
        return department;
    }

    bool operator==(int year) {
        if (dateOfJoining.getYear() == year)
            return true;
        else
            return false;
    }
    bool operator==(std::string month) {
        if (dateOfJoining.getMonth() == month)
            return true;
        else
            return false;
    }
};

/* Overloaded Operators */
std::ostream& operator<<(std::ostream& out, Date& date) {
    out << date.getMonth() << "-" << date.getDay() << "-" << date.getYear() << std::endl;
    return out;
}
std::istream& operator>>(std::istream& in, Employee& employee) {
    std::cout << "Enter employee ID :"; in >> employee.employeeID; in.ignore();
    std::cout << "Enter employee name :"; getline(in, employee.name);
    std::cout << "Enter employee department :"; getline(in, employee.department);
    std::cout << "Enter employee joining date :" << std::endl;
    employee.dateOfJoining.setDate();
    return in;
}

std::ostream& operator<<(std::ostream& out, Employee& employee) {
    out << "Employee ID :" << employee.getID() << std::endl;
    out << "Employee name :" << employee.getName() << std::endl;
    out << "Employee department :" << employee.getDepartment() << std::endl;
    out << "Employee Joining date :" << employee.dateOfJoining << std::endl;

    return out;
}

int main()
{
    Employee e1, e2(4161, "S K Dey", "CSE");

    std::cout << "Give input for employee 1: " << std::endl;
    std::cin >> e1;
    // Should ask employeeID, name, department.
    // Then ask for date of joining related information.

    std::cout << "Complete information of the employees are: " << std::endl;
    std::cout << e1 << e2 << std::endl;

    std::cout << "Mr./Ms. " << e1.getName();

    if (e1 == 2017 && e1 == "October")
        std::cout << " joined the company in October 2017." << std::endl;
    else
        std::cout << " did not join the company in October 2017." << std::endl;

    return 0;
}
