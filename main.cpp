#include "pch.h"


int main()
{
	std::cout << std::string("Day %d, part %d\n",CURRENT_DAY, CURRENT_PART);
#if (CURRENT_PART == 1)
	partOne(TEST_DATA?"":"input.txt");
#elif (CURRENT_PART == 2)
	partTwo();
#endif // (CURRENT_PART == 1)

	return 0;
}