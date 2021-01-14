#include <string>
#include <random>
#include <sstream>
#include <iostream>
#include <iomanip>

int main(int argc, char** argv)
{
	if (argc >= 2)
	{
		if (std::string(argv[1]) == "--version" || std::string(argv[1]) == "-v")
		{
			std::cout << "CBUnit 2.0\r\n";
			return 1;
		}
	}
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<uint32_t> uniform_dist(0, 0xFFFFFFFF);
	srand(time(NULL));

	std::stringstream ss;
	ss << std::hex;
	ss << uniform_dist(e1);
	ss << uniform_dist(e1);
	ss << uniform_dist(e1);
	ss << uniform_dist(e1);
	std::string gpp = "g++";

	gpp += " -DCBUNIT_TEST_ID=";
	gpp += ss.str();
	for (int i = 1; i < argc; ++i)
	{
		gpp += " ";
		gpp += argv[i];
	}
	
	return system(gpp.c_str());
}