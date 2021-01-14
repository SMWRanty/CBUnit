#include "Before.hpp"
#include "TestRunner.hpp"
#include "FileLineInfo.hpp"

namespace Cloudburst::Unit
{
	Before::Before(RunFunction function, const char* filename, uint32_t linenumber):
		_function(function),
		_filename(filename),
		_linenumber(linenumber)
	{}

	void Before::run()
	{
		_function();
	}
		
	std::string Before::filename() const
	{
		return _filename;
	}
		
	uint32_t Before::linenumber() const
	{
		return _linenumber;
	}

	BeforeDeclaration::BeforeDeclaration(RunFunction function)
	{
		TestRunner::instance()->push(new Before(function, FileLineInfo::_filename, FileLineInfo::_linenumber));
	}
}