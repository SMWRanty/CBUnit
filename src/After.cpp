#include "After.hpp"
#include "TestRunner.hpp"
#include "FileLineInfo.hpp"

namespace Cloudburst::Unit
{
	After::After(RunFunction function, const char* filename, uint32_t linenumber):
		_function(function),
		_filename(filename),
		_linenumber(linenumber)
	{}

	void After::run()
	{
		_function();
	}
		
	std::string After::filename() const
	{
		return _filename;
	}
		
	uint32_t After::linenumber() const
	{
		return _linenumber;
	}

	AfterDeclaration::AfterDeclaration(RunFunction function)
	{
		TestRunner::instance()->push(new After(function, FileLineInfo::_filename, FileLineInfo::_linenumber));
	}
}