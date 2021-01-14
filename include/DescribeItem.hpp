#pragma once

#include "Common.hpp"

namespace Cloudburst::Unit
{
	class DescribeItem
	{
	public:
		virtual ~DescribeItem();
			
		enum class Type
		{
			It,
      Skip,
			Describe
		};
			
		virtual Type type() const = 0;
		virtual std::string name() const = 0;
		virtual std::string filename() const = 0;
		virtual uint32_t linenumber() const = 0;
		virtual bool failed() const = 0;
		
		virtual void run() = 0;
	};
}