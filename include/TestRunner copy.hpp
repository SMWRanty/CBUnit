#pragma once
#include "Describe.hpp"
#include "It.hpp"
#include "BeforeEach.hpp"
#include "AfterEach.hpp"
#include "Before.hpp"
#include "After.hpp"
#include "Common.hpp"
#include "Error.hpp"
#include "TestOutput.hpp"
#include "TestMonitor.hpp"
#include "TestFailure.hpp"

namespace Cloudburst::Unit
{
	class TestRunner
	{
		friend class TestOutputUser;
		friend class TestOutput;

		friend class Describe;
		friend class It;
	public:
		~TestRunner();

		int run();
		static TestRunner* instance();

		void push(Describe* describe);
		void push(It* it);
		void push(BeforeEach* beforeEach);
		void push(AfterEach* afterEach);
		void push(Before* before);
		void push(After* after);

		const Error& error() const;

		bool testCanRun(Describe* describe) const;

		void excludeFile(const std::string& filename);
		void runFile(const std::string& filename);
	private:
		

		static TestRunner* _instance;
		using Describes = std::list<Describe*>;
		Describes _topLevelDescribes;

		using DescribeStack = std::stack<Describe*>;
		DescribeStack _describeStack;

		Error _error;
		TestOutput _testOutput;
		TestMonitor _testMonitor;

		using StringList = std::list<std::string>;
		StringList _excludedFiles;
		StringList _runnableFiles;
		
	};
}