#include <iostream>
#include <string>

class Author {
    int ID;
    std::string name, email;
public:
    friend std::ostream& operator<<(std::ostream& out, Author& author);

    Author() {
        ID = 000;
        name = email = "TBA";
    }

    void setAuthorInfo() {
        std::cout << "Enter Author ID :";
        std::cin >> ID; std::cin.ignore();
        std::cout << "Enter Author name :";
        getline(std::cin, name);
        std::cout << "Enter Author email :";
        getline(std::cin, email);
    }

    int getID() {
        return this->ID;
    }
    std::string getName() {
        return this->name;
    }
    std::string getEmail() {
        return this->email;
    }
};

class Book {
    std::string title, ISBN_No;
    float price;
    int noOfAuthor;
    Author *ptr;
public:
    friend std::istream& operator>>(std::istream& in, Book& book);
    friend std::ostream& operator<<(std::ostream& in, Book& book);

    Book() {
        title = "N/A";
        ISBN_No = "000 - 0 - 0000 - 0000 - 0";
        price = 0.0f;
        noOfAuthor = 0;
    }
    Book(std::string title, std::string ISBN_No, float price) {
        this->title = title;
        this->ISBN_No = ISBN_No;
        this->price = price;

        std::cout << "Enter no of authors for " << this->title << " :";
        std::cin >> noOfAuthor;
        ptr = new Author[noOfAuthor];
        for (int i = 0; i < noOfAuthor; i++) {
            ptr[i].setAuthorInfo();
        }
    }

    std::string getTitle() {
        return this->title;
    }
    std::string getISBN_No() {
        return this->ISBN_No;
    }
    float getPrice() {
        return this->price;
    }
    int getNoOfAuthors() {
        return this->noOfAuthor;
    }

    bool operator<=(int price) {
        if (this->getPrice() <= price)
            return true;
        else
            return false;
    }
    bool operator==(std::string authorName) {
        for (int i = 0; i < this->getNoOfAuthors(); i++) {
            if (this->ptr[i].getName() == authorName)
                return true;
            else
                return false;
        }
    }
};

std::ostream& operator<<(std::ostream& out, Author& author) {
    out << "Author ID :" << author.getID() << std::endl;
    out << "Author Name :" << author.getName() << std::endl;
    out << "Author Email :" << author.getEmail() << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Book& book) {
    std::cout << "Enter book title :"; getline(in, book.title);
    std::cout << "Enter book ISBN_No :"; getline(in, book.ISBN_No);
    std::cout << "Enter book price :"; in >> book.price; in.ignore();

    std::cout << "Enter no of authors for " << book.title << " :";
    in >> book.noOfAuthor;
    book.ptr = new Author[book.noOfAuthor];
    for (int i = 0; i < book.noOfAuthor; i++) {
        book.ptr[i].setAuthorInfo();
    }
    
    return in;
}
std::ostream& operator<<(std::ostream& out, Book& book) {
    out << "Book Title :" << book.getTitle() << std::endl;
    out << "Book ISBN_No :" << book.getISBN_No() << std::endl;
    out << "Book price :" << book.getPrice() << std::endl;
    out << "No of authors for the book " << book.getNoOfAuthors() << std::endl;
    out << "Author Info list :" << std::endl;

    for (int i = 0; i < book.getNoOfAuthors(); i++) {
        out << book.ptr[i] << std::endl;
    }

    return out;
}

int main()
{
    Book b1, b2("Data Structures", "978 - 0 - 7334 - 2609 - 4", 550);
    //parameterized constructor also ask for no of authors and their details
    std::cout << "Give input for book 1: " << std::endl;
    std::cin >> b1;
    //Should ask title, ISBN_No, price.
    //Then ask #ofAuthors & author info (id, name and email) for all authors.
    std::cout << "Complete information of the books are : " << std::endl;
    std::cout << b1 << b2 << std::endl;
    std::cout << "For The book titled : " << b1.getTitle() << std::endl;
    if (b1 <= 1000 || b1 == "Ataul Karim")
        std::cout << "Ataul Karim is an author, or the price is <= 1000" << std::endl;
    else
        std::cout << "Ataul Karim is NOT an author & price is > 1000" << std::endl;

    return 0;
}
