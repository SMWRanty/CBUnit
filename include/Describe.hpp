#pragma once

#include "DescribeItem.hpp"
#include "TestOutputUser.hpp"

namespace Cloudburst::Unit
{
	class It;
	class BeforeEach;
	class AfterEach;
	class Before;
	class After;

	class Describe: public DescribeItem, private TestOutputUser
	{
		friend class It;
	public:
		Describe(const char* name, RunFunction function, const char* filename, uint32_t linenumber, bool skip);
		~Describe() override;

		void run() override;
		
		Type type() const override;
		std::string name() const override;
		std::string filename() const override;
		uint32_t linenumber() const override;
		bool failed() const override;
		Describe* parent() const;
		void setParent(Describe* parent);

		void push(Describe* describe);
		void push(It* it);
		void push(BeforeEach* beforeEach);
		void push(AfterEach* afterEach);
		void push(Before* before);
		void push(After* after);
	protected:
		bool isSkipped() const;
		const char* _name;
		RunFunction _function;
		const char* _filename;
		uint32_t _linenumber;

		using Items = std::list<DescribeItem*>;
		Items _items;

		BeforeEach* _beforeEach;
		AfterEach* _afterEach;
		Before* _before;
		After* _after;
		bool _failed;
		Describe* _parent;
		bool _skip;
	};

	class DescribeDeclaration
	{
	public:
		DescribeDeclaration(const char* name, RunFunction function);
		DescribeDeclaration(bool skip, const char* name, RunFunction function);
	};
}

#define CBUNIT_DESCRIBE   ::Cloudburst::Unit::FileLineInfo CBUNIT_UNIQUE_FILE_LINE_INFO_NAME(__COUNTER__)(__FILE__, __LINE__); ::Cloudburst::Unit::DescribeDeclaration CBUNIT_UNIQUE_DESCRIBE_NAME(__COUNTER__)