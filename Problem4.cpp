#include <iostream>
#include <string>

class Author {
    std::string authorName, authorEmail;
public:
    Author() {
        this->authorName = this->authorEmail = "";
    }
    void setAuthor() {
        std::cout << "Enter authors name :"; getline(std::cin, authorName);
        std::cout << "Enter authors email :"; getline(std::cin, authorEmail);
    }
    void showAuthorInfo() {
        std::cout << "Author name :" << this->getAuthorName() << std::endl;
        std::cout << "Author email :" << this->getAuthorEmail() << std::endl;
    }

    std::string getAuthorName() {
        return this->authorName;
    }
    std::string getAuthorEmail() {
        return this->authorEmail;
    }
};

class Book {
    std::string bookName, isbn;
    Author* authorList;
    int noOfAuthors;
    float price;
public:
    Book() {
        this->bookName = "";
        this->isbn = "";
        this->noOfAuthors = 0;
        this->price = 0.0f;
    }
    void setTextBook() {
        std::cout << "Enter book name :"; getline(std::cin, this->bookName);
        std::cout << "Enter ISBN No :"; getline(std::cin, this->isbn);
        std::cout << "Enter number of authors of this book :"; std::cin >> this->noOfAuthors; std::cin.ignore();
        std::cout << "Enter author details :\n";
        authorList = new Author[this->noOfAuthors];
        for (int i = 0; i < this->noOfAuthors; i++) {
            authorList[i].setAuthor();
        }
    }
    void showTextBook() {
        std::cout << "Book name :" << this->getBookName() << std::endl;
        std::cout << "ISBN No :" << this->getIsbnNo() << std::endl;
        std::cout << "Number of authors of this book :" << this->getNoOfAuthors() << std::endl;
        
        std::cout << "Authors details :\n";
        for (int i = 0; i < this->getNoOfAuthors(); i++) {
            this->authorList[i].showAuthorInfo();
        }
    }

    std::string getBookName() {
        return this->bookName;
    }
    std::string getIsbnNo() {
        return this->isbn;
    }
    int getNoOfAuthors() {
        return noOfAuthors;
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
        this->courseId = "";
        this->courseTitle = "";
        this->noOfCredits = 0;
    }

    Course& populateCourse() {
        std::cout << "Enter course ID :"; getline(std::cin, this->courseId);
        std::cout << "Enter course title :"; getline(std::cin, this->courseTitle);
        std::cout << "Enter course credits :"; std::cin >> this->noOfCredits; std::cin.ignore();
        std::cout << "Enter book details for this course :\n";
        this->textBook.setTextBook();
        return *this;
    }
    void displayCourse() {
        std::cout << "Course ID :" << this->getCourseId() << std::endl;
        std::cout << "Course Title :" << this->getCourseTitle() << std::endl;
        std::cout << "Course credit no :" << this->getCreditNo() << std::endl;
        std::cout << "Text Book details :\n";
        this->textBook.showTextBook();
    }

    std::string getCourseId() {
        return this->courseId;
    }
    std::string getCourseTitle() {
        return this->courseTitle;
    }
    int getCreditNo() {
        return this->noOfCredits;
    }
};


void operator+=(int& totalCredits, Course course) {
    totalCredits += course.getCreditNo();
}

// Global functions
void allocateMemory(Course*& courseArr, int noOfCourses) {
    courseArr = new Course[noOfCourses];
}

int main()
{
    Course* courseArr;
    int n, i;

    std::cout << "How many courses? \nEnter here :"; std::cin >> n; std::cin.ignore();
    allocateMemory(courseArr, n);
    for (i = 0; i < n; i++) {
        courseArr[i].populateCourse().displayCourse();
    }

    int totalCredits = 0;
    for (i = 0; i < n; i++) {
        totalCredits += courseArr[i];
    }

    std::cout << "Total no of credits of these courses is :" << totalCredits << std::endl;

    return 0;
}
