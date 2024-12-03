#include "pch.h"

DayFactory::DayFactory()
{
	days[1] = new Day1();
	days[2] = new Day2();
}

Day* DayFactory::getDay(int day)
{
	return days[day];
}