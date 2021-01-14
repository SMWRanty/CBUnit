#pragma once

#include "DescribeItem.hpp"
#include "TestOutputUser.hpp"

namespace Cloudburst::Unit
{
	class After
	{
	public:
		After(RunFunction function, const char* filename, uint32_t linenumber);

		void run();
		
		std::string filename() const;
		uint32_t linenumber() const;
	protected:
		RunFunction _function;
		const char* _filename;
		uint32_t _linenumber;
	};

	class AfterDeclaration
	{
	public:
		AfterDeclaration(RunFunction function);
	};
}

#define CBUNIT_AFTER ::Cloudburst::Unit::FileLineInfo CBUNIT_UNIQUE_FILE_LINE_INFO_NAME(__COUNTER__)(__FILE__, __LINE__); ::Cloudburst::Unit::AfterDeclaration CBUNIT_UNIQUE_AFTER_NAME(__COUNTER__)