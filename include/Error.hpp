#pragma once

#include "Common.hpp"

namespace Cloudburst::Unit
{
	class Error
	{
	public:
	Error();
		Error(const std::string& message, const std::string& filename, uint32_t linenumber);
	
		const std::string& message() const;
		const std::string& filename() const;
		uint32_t linenumber() const;
		bool isValid() const;
	private:
		std::string _message;
		std::string _filename;
		uint32_t _linenumber;
	};
}