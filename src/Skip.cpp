#include "Skip.hpp"
#include "FileLineInfo.hpp"
#include "TestRunner.hpp"
#include "TestFailure.hpp"
#include <iostream>

namespace Cloudburst::Unit
{
	Skip::Skip(const char* name, RunFunction function, const char* filename,	uint32_t linenumber):
		_name(name),
		_function(function),
		_filename(filename),
		_linenumber(linenumber),
		_failed(false),
		_parent(nullptr)
	{}

	void Skip::run()
	{
	  testOutput().printNameSkip(_name);
		TestRunner::instance()->_testMonitor.testSkipped(*this);
	}
	
	Skip::Type Skip::type() const
	{
		return Type::Skip;
	}
	
	std::string Skip::name() const
	{
		return _name;
	}

	std::string Skip::filename() const
	{
		return _filename;
	}

	uint32_t Skip::linenumber() const
	{
		return _linenumber;
	}

	bool Skip::failed() const
	{
		return _failed;
	}

	void Skip::setParent(Describe* parent)
	{
		 _parent = parent;
	}

	Describe* Skip::parent() const
	{
		return _parent;
	}
	
	SkipDeclaration::SkipDeclaration(const char* name, RunFunction function)
	{
		TestRunner::instance()->push(new Skip(name, function, FileLineInfo::_filename, FileLineInfo::_linenumber));
	}
}