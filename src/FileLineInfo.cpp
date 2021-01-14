#include "FileLineInfo.hpp"

namespace Cloudburst::Unit
{
	const char* FileLineInfo::_filename = "";
	uint32_t FileLineInfo::_linenumber = 0;

	FileLineInfo::FileLineInfo(const char* filename, uint32_t linenumber)
	{
		FileLineInfo::_filename = filename;
		FileLineInfo::_linenumber = linenumber;
	}
}