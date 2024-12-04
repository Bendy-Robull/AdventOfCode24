#include "../pch.h"

class Day1 : public Day
{
public:
	Day1() = default;
	~Day1() = default;	
private:
	std::list<int> firstList;
	std::list<int> secondList;

	void readFile(std::string fileName) override {
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
	}
public:
	void partOne() override {
		readFile("Resources/real_inputs/day1_1.txt");
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

	void partTwo() override {
		readFile("Resources/real_inputs/day1_1.txt");
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
};


