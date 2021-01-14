#include "TestRunner.hpp"
#include "Error.hpp"
#include <iostream>
#include <algorithm>

namespace Cloudburst::Unit
{
	int TestRunner::run()
	{
		if (_error.isValid())
		{
			_testOutput.printError(_error);
			return -1;
		}
		try
		{
			for (auto describe : _topLevelDescribes)
			{
				describe->run();
			}

			_testMonitor.printTestSuccessCount(_testOutput);
			_testMonitor.printTestSkipCount(_testOutput);
			_testMonitor.printTestFailureCount(_testOutput);
			_testOutput.newLine();
			_testMonitor.printTestFailures(_testOutput);
			
		}
		catch(const Error& error)
		{
			_error = error;
			_testOutput.printError(error);
			return -1;
		}
		return 0;
	}

	TestRunner::~TestRunner()
	{
		for (auto describe : _topLevelDescribes)
		{
			delete describe;
		}
	}
		
	TestRunner* TestRunner::instance()
	{
		if (_instance == nullptr)
		{
				_instance = new TestRunner();
		}
		return _instance;
	}

	void TestRunner::push(Describe* describe)
	{
		if (_describeStack.empty())
		{
			_topLevelDescribes.push_back(describe);
		}
		else
		{
			_describeStack.top()->push(describe);
		}		
	}

	void TestRunner::push(It* it)
	{
		if (_describeStack.empty())
		{
			_error = Error("It declaration declared at root scope", it->filename(), it->linenumber());
		}
		else
		{
			_describeStack.top()->push(it);
		}		
	}

	void TestRunner::push(BeforeEach* beforeEach)
	{
		if (_describeStack.empty())
		{
			_error = Error("Before each declaration declared at root scope", beforeEach->filename(), beforeEach->linenumber());
		}
		else
		{
			_describeStack.top()->push(beforeEach);
		}		
	}

	void TestRunner::push(AfterEach* afterEach)
	{
		if (_describeStack.empty())
		{
			_error = Error("After each declaration declared at root scope", afterEach->filename(), afterEach->linenumber());
		}
		else
		{
			_describeStack.top()->push(afterEach);
		}		
	}

	void TestRunner::push(Before* before)
	{
		if (_describeStack.empty())
		{
			_error = Error("Before declaration declared at root scope", before->filename(), before->linenumber());
		}
		else
		{
			_describeStack.top()->push(before);
		}		
	}

	void TestRunner::push(After* after)
	{
		if (_describeStack.empty())
		{
			_error = Error("After declaration declared at root scope", after->filename(), after->linenumber());
		}
		else
		{
			_describeStack.top()->push(after);
		}		
	}

	TestRunner* TestRunner::_instance = nullptr;

	const Error& TestRunner::error() const
	{
		return _error;
	}

	bool TestRunner::testCanRun(Describe* describe) const
	{
		if (std::find(_excludedFiles.begin(), _excludedFiles.end(), describe->name()) != _excludedFiles.end())
		{
			return false;
		}
		else if (_runnableFiles.empty())
		{
			//The runnable files list is empty, so none have been provided, i.e run all
			return true;
		}
		else 
		{
			return std::find(_runnableFiles.begin(), _runnableFiles.end(), describe->name()) != _runnableFiles.end();
		}
	}
	
	void TestRunner::excludeFile(const std::string& filename)
	{
		_excludedFiles.push_back(filename);
	}
		
	void TestRunner::runFile(const std::string& filename)
	{
		_runnableFiles.push_back(filename);
	}
}