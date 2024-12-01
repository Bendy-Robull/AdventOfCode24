#include "../pch.h"

void partOne(std::string fileName) {
	std::list<int> firstList;
	std::list<int> secondList;

	std::ifstream inputFile(fileName);
	std::string line;
	while (std::getline(inputFile, line)) {
		std::stringstream ss(line);
		int number;
		int numberTwo;
		ss >> number >> numberTwo;
		firstList.push_back(number);
		secondList.push_back(numberTwo);
	}
	inputFile.close();
	firstList.sort();
	secondList.sort();
	std::cout<< firstList.size() << std::endl;
	int sum = 0;
	while(!firstList.empty()) {
		std::cout << firstList.front() << " : " << secondList.front() << std::endl;
		int first = firstList.front();
		int second = secondList.front();
		sum += std::abs(first-second);
		firstList.pop_front();
		secondList.pop_front();
	}
	std::cout << sum << std::endl;
}

void partTwo(std::string fileName) {

}