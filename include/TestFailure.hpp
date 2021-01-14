#pragma once

#include "Common.hpp"

namespace Cloudburst::Unit
{
	class TestFailure
	{
	public:
		TestFailure(const std::string& message, const std::string& filename, uint32_t linenumber);

		const std::string& message() const;
		const std::string& filename() const;
		uint32_t linenumber() const;
	private: 
		std::string _message;
		std::string _filename;
		uint32_t _linenumber;
	};
}

#define CBUNIT_TEST_FAILURE(message) ::Cloudburst::Unit::TestFailure(message, __FILE__, __LINE__)