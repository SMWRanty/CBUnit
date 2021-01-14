#include "Error.hpp"

namespace Cloudburst::Unit
{
	Error::Error() {}
	
	Error::Error(const std::string& message, const std::string& filename, uint32_t linenumber):
		_message(message),
		_filename(filename),
		_linenumber(linenumber)
	{}

	const std::string& Error::message() const
	{
		return _message;
	}
	
	const std::string& Error::filename() const
	{
		return _filename;
	}
	
	uint32_t Error::linenumber() const
	{
		return _linenumber;
	}

	bool Error::isValid() const
	{
		return _message != "";
	}
}