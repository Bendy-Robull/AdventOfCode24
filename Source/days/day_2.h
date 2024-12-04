#pragma once
#include "../pch.h"
class Day2 : public Day
{
public:
	Day2() = default;
	~Day2() = default;
private:
	void readFile(std::string fileName) override {}
public:
	void partOne() override {
		std::ifstream inputFile("Resources/real_inputs/day2_1.txt");
		std::string line;
		int safe = 0;
		while (std::getline(inputFile, line)) {
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
	} // 8 6 4 5 1 = +2 -4 -2 -3   a != 0,|a| <= 3, ha a < b novekvo akkor minden elemre a - b =< 0, ha a > b csokkeno akkor a - b => 0

	void partTwo() override {
		std::ifstream inputFile("Resources/real_inputs/day2_1.txt");
		std::string line;
		int safe = 0;
		while (std::getline(inputFile, line)) {
			std::cout << line << "  |  ";
			std::regex numberRegex("\\s+");
			std::vector<std::string> tokens(std::sregex_token_iterator{ begin(line),end(line),numberRegex,-1 }, std::sregex_token_iterator{});
			std::list<int> numberList;
			std::for_each(tokens.begin(), tokens.end(), [&numberList](std::string s) {numberList.push_back(std::stoi(s)); });
			std::list<int> numdifs;
			while (numberList.size() > 1) {
				int first = numberList.front();
				numberList.pop_front();
				int second = numberList.front();
				numdifs.push_back(second - first);
			}
			std::for_each(numdifs.begin(), numdifs.end(), [](int i) {std::cout << i << " "; });
			bool incline = std::accumulate(numdifs.begin(),numdifs.end(),0) > 0;
			bool isRepaired = false;
			bool isSafe = true;
			auto it = numdifs.begin();
			while (it != numdifs.end()) {
				if (incline) {
					if (std::abs(*it) <= 3 && *it >0 ) {
						++it;
					}
					else
					{
						if (!isRepaired) {
							if (it == numdifs.begin()) {
								numdifs.erase(it++);
							}
							else if (!(next(it) == numdifs.end()))
							{
								*std::next(it) += *it;
								numdifs.erase(it++);
							}
							else
							{
								++it;
							}
							isRepaired = true;
						}
						else
						{
							isSafe = false;
							break;
						}
					}
				}
				else
				{
					if (std::abs(*it) <= 3 && *it <0) {
						++it;
					}
					else
					{
						if (!isRepaired) {
							if (it == numdifs.begin()) {
								numdifs.erase(it++);
							}
							else if (!(next(it) == numdifs.end()))
							{
								*std::next(it) += *it;
								numdifs.erase(it++);
							}
							else
							{
								++it;
							}
							isRepaired = true;
						}
						else
						{
							isSafe = false;
							break;
						}
					}
				}
			}
			std::cout << "safe: " << isSafe << std::endl;
			if(isSafe)
			{
				safe++;
			}
		}
		inputFile.close();
		std::cout << safe << std::endl;
	}
};