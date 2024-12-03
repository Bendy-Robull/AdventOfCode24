#pragma once
#include "../pch.h"

void partOne(std::string fileName) {
	std::ifstream inputFile(fileName);
	std::string line;
	int safe = 0;
	while(std::getline(inputFile, line)) {
		//std::cout << line << std::endl;
		std::regex numberRegex("\\s+");
		std::vector<std::string> tokens(std::sregex_token_iterator{ begin(line),end(line),numberRegex,-1 }, std::sregex_token_iterator{});
		std::list<int> numberList;
		std::for_each(tokens.begin(), tokens.end(), [&numberList](std::string s) {numberList.push_back(std::stoi(s)); });
		bool linearIncline = std::is_sorted(numberList.begin(), numberList.end()) || std::is_sorted(numberList.begin(), numberList.end(), std::greater<>());
		while (linearIncline && numberList.size() > 1) {
			int first = numberList.front();
			numberList.pop_front();
			int second = numberList.front();
			if (std::abs(first - second) == 0 || std::abs(first - second) > 3) {
				linearIncline = false;
			}
		}
		//std::cout << "linearIncline: " << linearIncline << std::endl;
		if (linearIncline) {
			safe++;
		}
	}
	inputFile.close();
	std::cout << safe << std::endl;
}

void partTwo(std::string fileName) {
	std::ifstream inputFile(fileName);
	std::string line;
	int safe = 0;
	while (std::getline(inputFile, line)) {
		std::cout << line << std::endl;
		std::regex numberRegex("\\s+");
		std::vector<std::string> tokens(std::sregex_token_iterator{ begin(line),end(line),numberRegex,-1 }, std::sregex_token_iterator{});
		std::vector<int> numberList;
		std::for_each(tokens.begin(), tokens.end(), [&numberList](std::string s) {numberList.push_back(std::stoi(s)); });
		int errors = 0;
		while (numberList.size() > 2) {
			int first = numberList[0];
			int second = numberList[1];
			int third = numberList[2];
			if (first - second == 0 || std::abs(first - second) > 3) {
				errors++;
				if (std::abs(first - third) > 3 || std::abs(first - third) == 0) {
					errors++;
				}
			}
			std::list<int> normalList{ first, second, third };
			std::list<int> otherList{first, third, second };
			if ((!std::is_sorted(normalList.begin(), normalList.end()) && std::is_sorted(otherList.begin(), otherList.end())) || (!std::is_sorted(normalList.begin(), normalList.end(),std::greater<>()) && std::is_sorted(otherList.begin(), otherList.end(),std::greater<>()))) {
				errors++;
			}
			
			numberList.erase(numberList.begin());
			std::cout << "errors: " << errors << std::endl;
		}
		std::cout << "All Errors: " << errors << std::endl;
		if (errors <= 1) {
			safe++;
		}
	}
	inputFile.close();
	std::cout << safe << std::endl;
}