#include "BeforeEach.hpp"
#include "TestRunner.hpp"
#include "FileLineInfo.hpp"

namespace Cloudburst::Unit
{
	BeforeEach::BeforeEach(RunFunction function, const char* filename, uint32_t linenumber):
		_function(function),
		_filename(filename),
		_linenumber(linenumber)
	{}

	void BeforeEach::run()
	{
		_function();
	}
		
	std::string BeforeEach::filename() const
	{
		return _filename;
	}
		
	uint32_t BeforeEach::linenumber() const
	{
		return _linenumber;
	}

	BeforeEachDeclaration::BeforeEachDeclaration(RunFunction function)
	{
		TestRunner::instance()->push(new BeforeEach(function, FileLineInfo::_filename, FileLineInfo::_linenumber));
	}
}