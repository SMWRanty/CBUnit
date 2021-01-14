#include "TestOutput.hpp"
#include "TestRunner.hpp"
#include "ConsoleColour.hpp"
#include <iostream>

#include "It.hpp"
#include "Describe.hpp"

namespace Cloudburst::Unit
{
	namespace 
	{
		void printTabs(uint32_t scope)
		{
			for (uint32_t i = 0; i < scope; ++i)
			{
				std::cout << "  ";
			}
		}			
	}
	void TestOutput::printName(const std::string& name) const
	{
		printTabs(_scope);
		std::cout << white;
		std::cout << name;
		std::cout << clear;
		newLine();
	}
		
	void TestOutput::newLine() const
	{
		std::cout << "\r\n";
	}

	void TestOutput::pushScope()
	{
		++_scope;
	}

	void TestOutput::popScope()
	{
		--_scope;
	}

	void TestOutput::printNameSkip(const std::string& name) const
	{
		printTabs(_scope);
		std::cout << grey;
		std::cout << name;
		std::cout << clear;
		newLine();
	}
	

	void TestOutput::printNameFail(const std::string& name) const
	{
		printTabs(_scope);
		std::cout << red;
		std::cout << name;
		std::cout << clear;
		newLine();
	}
	
	void TestOutput::printNamePass(const std::string& name) const
	{
		printTabs(_scope);
		std::cout << green;
		std::cout << name;
		std::cout << clear;
		newLine();
	}

	void TestOutput::printError(const Error& error) const
	{
		std::cout << red;
		std::cout << "ERROR: " << error.message();
		newLine();
		std::cout << "  file: " <<error.filename();
		newLine();
		std::cout << "  line: " <<error.linenumber();
		std::cout << clear;
		newLine();
	}

	void TestOutput::printFailedTest(const It* it, const TestFailure& testFailure) const
	{
		std::cout << white;
		std::cout << "  " << it->name();
		std::cout << clear;
		std::cout << " (File: " << it->filename() << ":" << it->linenumber() << ")";
		newLine();
		std::cout << red;
		std::cout << "    " << testFailure.message();
		std::cout << clear;
		newLine();
		newLine();
	}

	void TestOutput::printFailedTestHeader(const It* it) const
	{
		const Describe* describe = it->parent();
		std::string header;
		using DescribeStack = std::stack<const Describe*>;
		DescribeStack describeStack;
		
		while (describe != nullptr)
		{
			describeStack.push(describe);
			describe = describe->parent();
		}

		std::cout << white;
		bool separator = false;
		while (!describeStack.empty())
		{
			if (separator)
			{
				std::cout << " -> ";
			}
			else
			{
				separator = true;
			}
			std::cout << describeStack.top()->name();
			describeStack.pop();	
		}
		std::cout << clear;
		newLine();
	}

	void TestOutput::printTestSuccessCount(uint32_t count)
	{
		std::cout << green;
		std::cout << count << " passing";
		std::cout << clear;
		newLine();
		
	}
	
	void TestOutput::printTestSkipCount(uint32_t count)
	{
		std::cout << grey;
		std::cout << count << " skipped";
		std::cout << clear;
		newLine();
	}
		
	void TestOutput::printTestFailureCount(uint32_t count)
	{
		std::cout << red;
		std::cout << count << " failing";
		std::cout << clear;
		newLine();
	}
}