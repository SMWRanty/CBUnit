#pragma once

#include "DescribeItem.hpp"
#include "TestOutputUser.hpp"

namespace Cloudburst::Unit
{
	class Describe;
	class It: public DescribeItem, private TestOutputUser
	{
	public:
		It(const char* name, RunFunction function, const char* filename, uint32_t linenumber);

		void run() override;
		
		Type type() const override;
		std::string name() const override;
		std::string filename() const override;
		uint32_t linenumber() const override;
		bool failed() const override;
		Describe* parent() const;
		void setParent(Describe* parent);
	protected:
		const char* _name;
		RunFunction _function;
		const char* _filename;
		uint32_t _linenumber;
		bool _failed;
		Describe* _parent;
	};

	class ItDeclaration
	{
	public:
		ItDeclaration(const char* name, RunFunction function);
	};
}

#define CBUNIT_IT   ::Cloudburst::Unit::FileLineInfo CBUNIT_UNIQUE_FILE_LINE_INFO_NAME(__COUNTER__)(__FILE__, __LINE__); ::Cloudburst::Unit::ItDeclaration CBUNIT_UNIQUE_IT_NAME(__COUNTER__)