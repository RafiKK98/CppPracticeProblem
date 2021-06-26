#include <iostream>
#include <string>
#include <map>


class Book {
    std::string bookName;
    std::string* authorNames;
    int noOfAuthors;
    float price;
public:
    Book() {
        this->bookName = "";
        this->noOfAuthors = 0;
        this->price = 0.0f;
        this->authorNames = nullptr;
    }
    void setTextBook() {
        std::cout << "Enter book name :"; getline(std::cin, this->bookName);
        std::cout << "Enter no of authors for this book :"; std::cin >> this->noOfAuthors; std::cin.ignore();
        this->authorNames = new std::string[this->noOfAuthors];
        for (int i = 0; i < this->noOfAuthors; i++) {
            std::cout << "Enter author name " << i + 1 << " :"; getline(std::cin, authorNames[i]);
        }
        std::cout << "Enter book price :"; std::cin >> this->price; std::cin.ignore();
    }

    void showTextBook() {
        std::cout << "Book name :" << this->getBookName() << std::endl;
        std::cout << "No of authors :" << this->getNoOfAuthors() << std::endl;
        this->getAuthorNames();
        std::cout << "Book price :" << this->getPrice() << std::endl;
    }

    std::string getBookName() {
        return this->bookName;
    }
    int getNoOfAuthors() {
        return this->noOfAuthors;
    }
    void getAuthorNames() {
        std::cout << "Author Names as following :\n";
        for (int i = 0; i < this->noOfAuthors; i++) {
            std::cout << authorNames[i] << "\n";
        }
    }
    float getPrice() {
        return this->price;
    }
};

class Course {
    std::string courseId, courseTitle;
    int noOfCredits;
    Book textBook;
public:
    Course() {
        this->courseId = "N/A";
        this->courseTitle = "N/A";
        this->noOfCredits = 0;
        this->textBook = Book();
    }
    Course& setCourseInfo() {
        std::cout << "Enter course ID :"; getline(std::cin, this->courseId);
        std::cout << "Enter course title :"; getline(std::cin, this->courseTitle);
        std::cout << "Enter no of credits for this course :"; std::cin >> this->noOfCredits; std::cin.ignore();
        std::cout << "Enter text book details :\n";
        this->textBook.setTextBook();

        return *this;
    }
    void showCourseInfo() {
        std::cout << "Course ID :" << this->getCourseID() << std::endl;
        std::cout << "Course Title :" << this->getCourseTitle() << std::endl;
        std::cout << "Course credit no :" << this->getNoOfCredits() << std::endl;
        this->textBook.showTextBook();
    }

    std::string getCourseID() {
        return this->courseId;
    }
    std::string getCourseTitle() {
        return this->courseTitle;
    }
    int getNoOfCredits() {
        return this->noOfCredits;
    }
    void getTextBook() {
        std::cout << this->textBook.getBookName() << std::endl;
        std::cout << this->textBook.getNoOfAuthors() << std::endl;
        this->textBook.getAuthorNames();
        std::cout << this->textBook.getPrice() << std::endl;
    }
};

// global functions
float getBillAmount(Course* enrolledCourses, int n, int ratePerCredit, float scholarshipPercent) {
    int totalCredit = 0;
    float totalBill = 0.0;
    scholarshipPercent /= 100;
    for (int i = 0; i < n; i++) {
        totalCredit += enrolledCourses[i].getNoOfCredits();
    }
    totalBill = totalCredit * ratePerCredit;
    totalBill *= scholarshipPercent;

    return totalBill;
}

int main()
{
    Course* enrolledCourses;
    int n, i, ratePerCredit;
    float scholarshipPercent;

    std::cout << "How many courses to enroll? \Enter here :"; std::cin >> n; std::cin.ignore();
    std::cout << "Rate per credit for this student :"; std::cin >> ratePerCredit; std::cin.ignore();
    std::cout << "Scholarship(%) for this student :"; std::cin >> scholarshipPercent; std::cin.ignore();

    enrolledCourses = new Course[n];
    for (int i = 0; i < n; i++) {
        enrolledCourses[i].setCourseInfo().showCourseInfo();
    }

    std::cout << "Total amount to be paid is :" << getBillAmount(enrolledCourses, n, ratePerCredit, scholarshipPercent) << std::endl;
    return 0;
}
