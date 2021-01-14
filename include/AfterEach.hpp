#pragma once

#include "DescribeItem.hpp"
#include "TestOutputUser.hpp"

namespace Cloudburst::Unit
{
	class AfterEach
	{
	public:
		AfterEach(RunFunction function, const char* filename, uint32_t linenumber);

		void run();
		
		std::string filename() const;
		uint32_t linenumber() const;
	protected:
		RunFunction _function;
		const char* _filename;
		uint32_t _linenumber;
	};

	class AfterEachDeclaration
	{
	public:
		AfterEachDeclaration(RunFunction function);
	};
}

#define CBUNIT_AFTER_EACH  ::Cloudburst::Unit::FileLineInfo CBUNIT_UNIQUE_FILE_LINE_INFO_NAME(__COUNTER__)(__FILE__, __LINE__); ::Cloudburst::Unit::AfterEachDeclaration CBUNIT_UNIQUE_AFTER_EACH_NAME(__COUNTER__)