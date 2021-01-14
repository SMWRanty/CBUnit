#include "AfterEach.hpp"
#include "TestRunner.hpp"
#include "FileLineInfo.hpp"

namespace Cloudburst::Unit
{
	AfterEach::AfterEach(RunFunction function, const char* filename, uint32_t linenumber):
		_function(function),
		_filename(filename),
		_linenumber(linenumber)
	{}

	void AfterEach::run()
	{
		_function();
	}
		
	std::string AfterEach::filename() const
	{
		return _filename;
	}
		
	uint32_t AfterEach::linenumber() const
	{
		return _linenumber;
	}

	AfterEachDeclaration::AfterEachDeclaration(RunFunction function)
	{
		TestRunner::instance()->push(new AfterEach(function, FileLineInfo::_filename, FileLineInfo::_linenumber));
	}
}