#include "TestRunner.hpp"
#include "Error.hpp"
extern int testMain(Cloudburst::Unit::TestRunner& testRunner);

namespace
{
	void printHelp() 
	{

	}

	void excludeFiles(int argc, char** argv, int& i)
	{
		while(i != argc)
		{
			std::string argument = argv[i];
			if (argument.substr(0,1) == "-")
			{
				return;
			}
			else
			{
				Cloudburst::Unit::TestRunner::instance()->excludeFile(argument);
				++i;
			}
		}
	}

	void runFiles(int argc, char** argv, int& i)
	{
while(i != argc)
		{
			std::string argument = argv[i];
			if (argument.substr(0,1) == "-")
			{
				return;
			}
			else
			{
				Cloudburst::Unit::TestRunner::instance()->runFile(argument);
				++i;
			}
		}
	}
}
int main(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string argument = argv[i];
	 if ((argument == "--help") || (argument == "-h"))
		{
			printHelp();
			return 0;
		}
		else if ((argument == "--exclude") || (argument == "-x"))
		{
			++i;
			excludeFiles(argc, argv, i);
			//iterate over the arguments adding the excluded files to the test runner;
		}
		else if ((argument == "--run") || (argument == "-r"))
		{
			++i;
			runFiles(argc, argv, i);
			//iterate over the arguments adding the run files to the test runner
		}
	}
	return testMain( *Cloudburst::Unit::TestRunner::instance());
}