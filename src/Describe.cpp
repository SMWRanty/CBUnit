#include "Describe.hpp"
#include "TestRunner.hpp"
#include "FileLineInfo.hpp"
#include "BeforeEach.hpp"
#include "AfterEach.hpp"
#include "Before.hpp"
#include "After.hpp"
#include <iostream>
namespace Cloudburst::Unit
{
	Describe::Describe(const char* name, RunFunction function,const char* filename,	uint32_t linenumber, bool skip):
		_name(name),
		_function(function),
		_filename(filename),
		_linenumber(linenumber),
		_beforeEach(nullptr),
		_afterEach(nullptr),
		_before(nullptr),
    _after(nullptr),
		_failed(false),
		_parent(nullptr),
		_skip(skip)
	{}

	Describe::~Describe()
	{
		for (auto item : _items)
		{
			delete item;
		}
		delete _beforeEach;
		delete _afterEach;
		delete _after;
		delete _before;
	}

	void Describe::run()
	{
		if (TestRunner::instance()->testCanRun(this))
		{
			TestRunner::instance()->_describeStack.push(this);
			if (_skip)
			{
				testOutput().printNameSkip(_name);
			}
			else
			{
				testOutput().printName(_name);
			}
			_function();
			testOutput().pushScope();
			bool isNotSkipped = !isSkipped();
			if (_before && isNotSkipped)
			{
				_before->run();
			}
			for (auto item : _items)
			{
				if (_beforeEach && isNotSkipped)
				{
					_beforeEach->run();
				}
				item->run();
				if (item->failed())
				{
					_failed = true;
				}
				if (_afterEach && isNotSkipped)
				{
					_afterEach->run();
				}
			}
			if (_after && isNotSkipped)
			{
				_after->run();
			}
			testOutput().popScope();
			if (TestRunner::instance()->_describeStack.size() == 1)
			{
				testOutput().newLine();
			}
			TestRunner::instance()->_describeStack.pop();
		}
	}
			
	Describe::Type Describe::type() const
	{
		return Type::Describe;
	}

	std::string Describe::name() const
	{
		return _name;
	}

	std::string Describe::filename() const
	{
		return _filename;
	}

	uint32_t Describe::linenumber() const
	{
		return _linenumber;
	}

	bool Describe::failed() const
	{
		return _failed;
	}

	void Describe::setParent(Describe* parent)
	{
		_parent = parent;
	}
	Describe* Describe::parent() const
	{
		return _parent;
	}
	
	void Describe::push(Describe* describe)
	{
		describe->setParent(this);
		_items.push_back(describe);
	}

	void Describe::push(It* it)
	{
		it->setParent(this);
		_items.push_back(it);
	}

	void Describe::push(BeforeEach* beforeEach)
	{
		if (_beforeEach != nullptr)
		{
			throw Error("More than one before each declared", beforeEach->filename(), beforeEach->linenumber());
		}
		_beforeEach = beforeEach;
	}

	void Describe::push(AfterEach* afterEach)
	{
		if (_afterEach != nullptr)
		{
			throw Error("More than one after each declared", afterEach->filename(), afterEach->linenumber());
		}
		_afterEach = afterEach;
	}

	void Describe::push(Before* before)
	{
		if (_before != nullptr)
		{
			throw Error("More than one before declared", before->filename(), before->linenumber());
		}
		_before = before;
	}

	void Describe::push(After* after)
	{
		if (_after != nullptr)
		{
			throw Error("More than one after declared", after->filename(), after->linenumber());
		}
		_after = after;
	}

	bool Describe::isSkipped() const
	{
		if (_skip)
		{
			return true;
		}
		else if (_parent == nullptr)
		{
			return false;
		}
		else 
		{
			return _parent->isSkipped();
		}
	}
	DescribeDeclaration::DescribeDeclaration(const char* name, RunFunction function)
	{
		TestRunner::instance()->push(new Describe(name, function, FileLineInfo::_filename, FileLineInfo::_linenumber, false));
	}

	DescribeDeclaration::DescribeDeclaration(bool skip, const char* name, RunFunction function)
	{
		TestRunner::instance()->push(new Describe(name, function, FileLineInfo::_filename, FileLineInfo::_linenumber, skip));
	}
}