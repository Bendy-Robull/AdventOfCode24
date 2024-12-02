#include "pch.h"


int main()
{
	std::cout << std::string("Day %d, part %d\n", CURRENT_DAY, CURRENT_PART);
#if (CURRENT_PART == 1)
	partOne(TEST_DATA ? "test_inputs/day" + std::to_string(CURRENT_DAY) + "_1.txt" : "real_inputs/day" + std::to_string(CURRENT_DAY) + "_1.txt");
#elif (CURRENT_PART == 2)
	partTwo(TEST_DATA ? "test_inputs/day" + std::to_string(CURRENT_DAY) + "_1.txt" : "real_inputs/day" + std::to_string(CURRENT_DAY) + "_1.txt");
#endif // (CURRENT_PART == 1)

	return 0;
}