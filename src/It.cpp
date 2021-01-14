#include "It.hpp"
#include "FileLineInfo.hpp"
#include "TestRunner.hpp"
#include "TestFailure.hpp"
#include <iostream>

namespace Cloudburst::Unit
{
	It::It(const char* name, RunFunction function, const char* filename,	uint32_t linenumber):
		_name(name),
		_function(function),
		_filename(filename),
		_linenumber(linenumber),
		_failed(false),
		_parent(nullptr)
	{}

	void It::run()
	{
		try
		{
			_function();
		}
		catch (const TestFailure& failure)
		{
			_failed = true;
			testOutput().printNameFail(_name);
			TestRunner::instance()->_testMonitor.testFailure(*this, failure);
		}
		if (!_failed)
		{
			testOutput().printNamePass(_name);
		  TestRunner::instance()->_testMonitor.testSuccess(*this);		
		}
	}
	
	It::Type It::type() const
	{
		return Type::It;
	}
	
	std::string It::name() const
	{
		return _name;
	}

	std::string It::filename() const
	{
		return _filename;
	}

	uint32_t It::linenumber() const
	{
		return _linenumber;
	}

	bool It::failed() const
	{
		return _failed;
	}

	void It::setParent(Describe* parent)
	{
		 _parent = parent;
	}

	Describe* It::parent() const
	{
		return _parent;
	}
	
	ItDeclaration::ItDeclaration(const char* name, RunFunction function)
	{
		TestRunner::instance()->push(new It(name, function, FileLineInfo::_filename, FileLineInfo::_linenumber));
	}
}