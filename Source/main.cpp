#include "pch.h"



int main()
{
	DayFactory dayFactory;
	std::cout << "Day "<<CURRENT_DAY<<", part "<< CURRENT_PART<<"\n";
#if (CURRENT_PART == 1)
	dayFactory.getDay(CURRENT_DAY)->partOne();
#elif (CURRENT_PART == 2)
	dayFactory.getDay(CURRENT_DAY)->partTwo();
#endif // (CURRENT_PART == 1)

	return 0;
}