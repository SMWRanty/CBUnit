#pragma once

#include "Common.hpp"

namespace Cloudburst::Unit
{
	class FileLineInfo
	{
	public:
		FileLineInfo(const char* filename, uint32_t linenumber);

		static const char* _filename;
		static uint32_t _linenumber;
	};}