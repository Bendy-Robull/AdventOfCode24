#include "../pch.h"
void readFile(std::list<int>& listOne, std::list<int>& listTwo, std::string fileName) {
	std::ifstream inputFile(fileName);
	std::string line;
	while (std::getline(inputFile, line)) {
		std::stringstream ss(line);
		int number;
		int numberTwo;
		ss >> number >> numberTwo;
		listOne.push_back(number);
		listTwo.push_back(numberTwo);
	}
	inputFile.close();
}
void partOne(std::string fileName) {
	std::list<int> firstList;
	std::list<int> secondList;
	readFile(firstList, secondList, fileName);
	firstList.sort();
	secondList.sort();
	std::cout << firstList.size() << std::endl;
	int sum = 0;
	while (!firstList.empty()) {
		//std::cout << firstList.front() << " : " << secondList.front() << std::endl;
		int first = firstList.front();
		int second = secondList.front();
		sum += std::abs(first - second);
		firstList.pop_front();
		secondList.pop_front();
	}
	std::cout << sum << std::endl;
}

void partTwo(std::string fileName) {
	std::list<int> firstList;
	std::list<int> secondList;
	readFile(firstList, secondList, fileName);
	int sum = 0;
	for (auto i : firstList) {
		int occurence = 0;
		for (auto j : secondList) {
			if (i == j)
			{
				occurence++;
			}
		}
		//std::cout << i << " : " << occurence << std::endl;
		sum += occurence * i;
	}
	std::cout << sum << std::endl;
}