#include "TestFailure.hpp"

namespace Cloudburst::Unit
{

	TestFailure::TestFailure(const std::string& message, const std::string& filename, uint32_t linenumber):
		_message(message),
		_filename(filename),
		_linenumber(linenumber)
	{}

	const std::string& TestFailure::message() const
	{
		return _message;
	}

	const std::string& TestFailure::filename() const
	{
		return _filename;
	}

	uint32_t TestFailure::linenumber() const
	{
		return _linenumber;
	}
}