#pragma once

#include "Common.hpp"
#include "Error.hpp"
#include "TestFailure.hpp"

namespace Cloudburst::Unit
{
	class It;
	class Describe;
	class TestOutput
	{
		friend class Describe;
	public:
		void printName(const std::string& name) const;
		void printNameSkip(const std::string& name) const;
		void printNameFail(const std::string& name) const;
		void printNamePass(const std::string& name) const;
		void printError(const Error& error) const;
		void printFailedTest(const It* it, const TestFailure& testFailure) const;
		void printFailedTestHeader(const It* it) const;
		void printTestSuccessCount(uint32_t count);
		void printTestSkipCount(uint32_t count);
		void printTestFailureCount(uint32_t count);
		void newLine() const;
	private:
		void pushScope();
		void popScope();	
		uint32_t _scope;
	};
}