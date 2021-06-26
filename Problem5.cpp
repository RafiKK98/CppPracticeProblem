#include <iostream>
#include <string>

class HardDisk {
	int rpm, capacityInGB;
public:
	void setHDD() {
		std::cout << "Enter HDD RPM :"; std::cin >> this->rpm; std::cin.ignore();
		std::cout << "Enter Capacity in Gigabytes :"; std::cin >> this->capacityInGB; std::cin.ignore();
	}

	void showHDDInfo() {
		std::cout << "RPM :" << this->getHddRpm() << std::endl;
		std::cout << "Capacity (in GBs) :" << this->getHddCapacity() << std::endl;
	}

	int getHddRpm() {
		return this->rpm;
	}
	int getHddCapacity() {
		return this->capacityInGB;
	}
};

class Computer {
	std::string brand;
	float speedInGhz;
	int noOfHDD;
	HardDisk* hddArr;
	float price;
public:
	
	void setComputer() {
		std::cout << "Enter brand name :"; getline(std::cin, this->brand);
		std::cout << "Enter CPU Speed in GHz :"; std::cin >> this->speedInGhz; std::cin.ignore();
		std::cout << "Enter number of HardDisks :"; std::cin >> this->noOfHDD; std::cin.ignore();
		std::cout << "Enter price of the computer :"; std::cin >> this->price; std::cin.ignore();

		hddArr = new HardDisk[this->noOfHDD];

		for (int i = 0; i < this->noOfHDD; i++) {
			this->hddArr[i].setHDD();
		}
	}

	void showComputer() {
		std::cout << "Brand :" << this->getBrand() << std::endl;
		std::cout << "CPU Speed :" << this->getCPUSpeed() << std::endl;
		std::cout << "No of HDDs :" << this->getNoOfHDD() << std::endl;
		for (int i = 0; i < this->getNoOfHDD(); i++) {
			this->hddArr[i].showHDDInfo();
		}
		std::cout << "Price :" << this->getPrice() << std::endl;
	}

	std::string getBrand() {
		return this->brand;
	}
	float getCPUSpeed() {
		return this->speedInGhz;
	}
	int getNoOfHDD() {
		return this->noOfHDD;
	}
	float getPrice() {
		return this->price;
	}

	int getPcStorage() {
		int s = 0;
		for (int i = 0; i < this->noOfHDD; i++) {
			s += this->hddArr[i].getHddCapacity();
		}
		return s;
	}
};

class ComputerLab {
	std::string roomNo;
	int noOfComputer;
	Computer* compArr;
public:
	friend void operator+=(int& storage, ComputerLab Lab);

	ComputerLab& setLabInfo() {
		std::cout << "Enter lab room no :"; getline(std::cin, this->roomNo);
		std::cout << "Enter number of computers in lab :"; std::cin >> this->noOfComputer; std::cin.ignore();
		compArr = new Computer[this->noOfComputer];

		for (int i = 0; i < this->noOfComputer; i++) {
			this->compArr[i].setComputer();
		}
		return *this;
	}
	ComputerLab& showLabInfo() {
		std::cout << "Lab room no :" << this->getRoomNo() << std::endl;
		std::cout << "No of comuters in this room :" << this->getNoOfComputer() << std::endl;
		std::cout << "Computer specifications :" << std::endl;
		
		for (int i = 0; i < this->noOfComputer; i++) {
			this->compArr[i].showComputer();
		}
		return *this;
	}

	std::string getRoomNo() {
		return this->roomNo;
	}
	int getNoOfComputer() {
		return this->noOfComputer;
	}

	int getLabPcStorage() {
		int s = 0;
		for (int i = 0; i < this->noOfComputer; i++) {
			s += this->compArr[i].getPcStorage();
		}
		return s;
	}

	bool operator>=(int noOfComputer) {
		return this->getNoOfComputer() >= noOfComputer;
	}
};

void operator+=(int& storage, ComputerLab Lab) {
	int storageCapacity = Lab.getLabPcStorage();
	storage += storageCapacity;
}

int main()
{
	ComputerLab* labs;
	int n, i;
	std::cout << "How many computer labs? \nEnter here :"; std::cin >> n; std::cin.ignore();
	labs = new ComputerLab[n]; int totalStorageOfAllLabsInGB = 0;

	for (int i = 0; i < n; i++) {
		labs[i].setLabInfo().showLabInfo();

		totalStorageOfAllLabsInGB += labs[i];
		std::cout << "Total storage of all labs combined is :" << totalStorageOfAllLabsInGB << " GB" << std::endl;

		if (labs[i] >= 30)
			std::cout << i+1 << "-th Lab is a big computer Lab." << std::endl;
		else
			std::cout << i+1 << "-th Lab is a small computer Lab." << std::endl;
	}

	return 0;
}
