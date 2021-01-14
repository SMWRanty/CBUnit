#include "TestMonitor.hpp"
#include "It.hpp"
namespace Cloudburst::Unit
{
  class It;

	void TestMonitor::testFailure(It& it, const TestFailure& testFailure)
	{
		_failures.push_back({&it, testFailure});
		++_failureTotal;
	}
		
	void TestMonitor::testSuccess(It& it)
	{
    (void)it;
		++_successTotal;
	}
		
	void TestMonitor::testSkipped(Skip& skip)
	{
    (void)skip;
		++_skipTotal;
	}

	void TestMonitor::printTestFailures(TestOutput& output)
	{
			const Describe* currentParent = nullptr;

			for (auto failedTest: _failures)
			{
				if (currentParent != failedTest.it->parent())
				{
					currentParent = failedTest.it->parent();
					output.printFailedTestHeader(failedTest.it);
				}
				output.printFailedTest(failedTest.it, failedTest.failure);				
			}
	}
	void TestMonitor::printTestSuccessCount(TestOutput& output)
	{
		 output.printTestSuccessCount(_successTotal);
	}

	void TestMonitor::printTestFailureCount(TestOutput& output)
	{
		output.printTestFailureCount(_failureTotal);
	}
	void TestMonitor::printTestSkipCount(TestOutput& output)
	{
		output.printTestSkipCount(_skipTotal);
	}
}