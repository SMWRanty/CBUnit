#include "TestOutputUser.hpp"
#include "TestRunner.hpp"

namespace Cloudburst::Unit
{
	TestOutput& TestOutputUser::testOutput()
	{
		return TestRunner::instance()->_testOutput;
	}
}