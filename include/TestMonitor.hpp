#pragma once

#include "TestFailure.hpp"
#include "TestOutput.hpp"

namespace Cloudburst::Unit
{
  class It;
  class Skip;

	class TestMonitor
	{
	public:
		void testFailure(It& it, const TestFailure& testFailure);
		void testSuccess(It& it);
		void testSkipped(Skip& it);

		void printTestFailures(TestOutput& output);
		void printTestSuccessCount(TestOutput& output);
		void printTestFailureCount(TestOutput& output);
		void printTestSkipCount(TestOutput& output);
	private:

		struct FailedIt
		{
			It* it;
			TestFailure failure;
		};
		using FailedItList = std::list<FailedIt>;
		FailedItList _failures;

		unsigned long _failureTotal = 0;
		unsigned long _successTotal = 0;
		unsigned long _skipTotal = 0;
	};
}