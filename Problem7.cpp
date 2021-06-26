#include <iostream>
#include <string>

class ComplexNo {
    int real, img;
public:
    friend std::ostream& operator<<(std::ostream& out, ComplexNo& cnNo);
    friend std::istream& operator>>(std::istream& in, ComplexNo& complexNo);

    ComplexNo() {
        this->real = 0;
        this->img = 0;
    }
    ComplexNo(int real, int img) {
        this->real = real;
        this->img = img;
    }

    void setComplexNo() {
        std::cout << "Enter real no :"; std::cin >> this->real; std::cin.ignore();
        std::cout << "Enter img no :"; std::cin >> this->img; std::cin.ignore();
    }

    int getRealVal() {
        return this->real;
    }
    int getimgVal() {
        return this->img;
    }

    ComplexNo operator+(ComplexNo complexNo) {
        ComplexNo sum;
        sum.real = this->real + complexNo.real;
        sum.img = this->img + complexNo.img;
        return sum;
    }
    ComplexNo operator-(ComplexNo complexNo) {
        ComplexNo sum;
        sum.real = this->real - complexNo.real;
        sum.img = this->img - complexNo.img;
        return sum;
    }
    ComplexNo operator*(ComplexNo complexNo) {
        ComplexNo sum;
        sum.real = this->real * complexNo.real - this->img * complexNo.img;
        sum.img = this->real * complexNo.img + this->img * complexNo.real;
        return sum;
    }
};

class ComplexRow {
    int noOfCNperRow;
    ComplexNo* CnPtr;
public:
    friend std::istream& operator>>(std::istream& in, ComplexRow& cnRows);
    friend std::ostream& operator<<(std::ostream& out, ComplexRow& cnRow);

    void setComplexRow() {
        std::cout << "Enter number of complex numbers :"; std::cin >> this->noOfCNperRow; std::cin.ignore();
        this->CnPtr = new ComplexNo[this->noOfCNperRow];
        for (int i = 0; i < this->getNoOfCNperRow(); i++) {
            std::cout << "Enter complex no at index [" << i << "] (first real value then imaginary value):";
            std::cin >> CnPtr[i];
        }
    }



    ComplexRow& mergeWith(ComplexRow& complexRow) {
        ComplexRow mergedRow;
        int length = this->getNoOfCNperRow() < complexRow.getNoOfCNperRow() ? this->getNoOfCNperRow() : complexRow.getNoOfCNperRow();
        mergedRow.CnPtr = new ComplexNo[length];

        for (int i = 0; i < length; i++) {
            mergedRow.CnPtr[i] = this->CnPtr[i] + complexRow.CnPtr[i];
        }
        return mergedRow;
    }

    int getNoOfCNperRow() {
        return this->noOfCNperRow;
    }

    ComplexNo* getCnPtr() {
        return this->CnPtr;
    }
    void showCNRowInfo() {
        for (int i = 0; i < this->noOfCNperRow; i++) {
            std::cout << this->CnPtr[i] << " ";
        }
    }
};

std::istream& operator>>(std::istream& in, ComplexNo& complexNo) {
    in >> complexNo.real >> complexNo.img; in.ignore();
    return in;
}

std::istream& operator>>(std::istream& in, ComplexRow& cnRow) {
    cnRow.setComplexRow();

    return in;
}

std::ostream& operator<<(std::ostream& out, ComplexNo& cnNo) {
    if ( cnNo.getimgVal() >= 0 )
        out << cnNo.getRealVal() << "+" << cnNo.getimgVal() << "i";
    else
        out << cnNo.getRealVal() << cnNo.getimgVal() << "i";

    return out;
}

std::ostream& operator<<(std::ostream& out, ComplexRow& cnRow) {
    cnRow.showCNRowInfo();
    return out;
}


void showComplexRows(ComplexRow* cnRows, int row) {
    for (int r = 0; r < row; r++) {
        std::cout << "Row-" << r + 1 << " :";
        std::cout << cnRows[r] << std::endl;
    }
}

int main()
{
    int row, rowIndex1, rowIndex2, i;
    ComplexRow* cnRows;

    std::cout << "How many rows of complex no's? Enter here :"; std::cin >> row; std::cin.ignore();
    cnRows = new ComplexRow[row];
    for (i = 0; i < row; i++) {
        std::cin >> cnRows[i];
    }
    // ask no of complexNo in i-th row & populate them with ComplexNo objects;

    std::cout << "The matrix/2D shape of complex numbers is :" << std::endl;
    showComplexRows(cnRows, row); // global function

    ComplexRow mergedRow;
    std::cout << "Enter indices of two rows (<row) to merge :"; std::cin >> rowIndex1 >> rowIndex2;
    mergedRow = cnRows[rowIndex1].mergeWith(cnRows[rowIndex2]);
    std::cout << "The MERGED rows of complex numbers is :" << mergedRow << std::endl;

    int lower, upper;
    // get values of lower & upper from user
    std::cout << "Enter upper and lower values :";
    std::cin >> lower >> upper; std::cin.ignore();
    // Now display all the Complex numbers from mergedRow,
    // whose real<= lower & img>=upper
    for (i = 0; i < mergedRow.getNoOfCNperRow(); i++) {
        if (mergedRow.getCnPtr()[i].getRealVal() <= lower && mergedRow.getCnPtr()[i].getimgVal() >= upper )
            std::cout << mergedRow.getCnPtr()[i] << std::endl;
    }

    return 0;
}