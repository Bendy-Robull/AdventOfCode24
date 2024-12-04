#pragma once
#include "../pch.h"

class Day3 : public Day {
public:
	Day3() = default;
	~Day3() = default;
private:
	void readFile(std::string fileName) override {}
public:
	void partOne() override {
		std::ifstream inputFile("Resources/real_inputs/day3_1.txt");
		std::string line;
		int mulSum = 0;
		std::regex exp("mul\\(\\d{1,3},\\d{1,3}\\)");
		while (getline(inputFile, line)) {
			std::vector<std::string> tokens(std::sregex_token_iterator{ begin(line),end(line),exp,0 }, std::sregex_token_iterator{});
			std::cout << tokens.size() << std::endl;
			for (std::string& mul : tokens) {
				std::cout<<mul<<std::endl;
				std::regex numreg("\\d{1,3}");
				std::vector<std::string> numtokens(std::sregex_token_iterator{ begin(mul),end(mul),numreg,0}, std::sregex_token_iterator{});
				std::list<int> numbers;
				std::for_each(numtokens.begin(), numtokens.end(), [&numbers](std::string num) {numbers.push_back(std::stoi(num)); });
				mulSum += numbers.front() * numbers.back();
			}
		}
		inputFile.close();
		std::cout << mulSum << std::endl;
	};
	void partTwo() override {};
};