#pragma once

class Day
{
	virtual void readFile(std::string fileName) = 0;
public:
	virtual void partOne() = 0;
	virtual void partTwo() = 0;
};

class DayFactory
{
public:
	DayFactory();
private:
		Day* days[25];
public:
		Day* getDay(int day);
};