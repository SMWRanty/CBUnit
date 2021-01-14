#pragma once
#include <list>
#include <functional>
#include <string>
#include <stack>
#include <cstdint>

namespace Cloudburst::Unit
{
	class TestRunner;
	using RunFunction = std::function<void()>;
}

#define CBUNIT_CONCAT2(x, y) x ## y
#define CBUNIT_CONCAT(x, y) CBUNIT_CONCAT2(x, y)

#define CBUNIT_STR2(x) #x
#define CBUNIT_STR(x) CBUNIT_STR2(x)

#define CBUNIT_GENERATE_UNIQUE_SUFFIX(localID) CBUNIT_CONCAT(CBUNIT_CONCAT(CBUNIT_TEST_ID, _), localID)
#define CBUNIT_UNIQUE_NAME(name, localID) CBUNIT_CONCAT(name, CBUNIT_GENERATE_UNIQUE_SUFFIX(localID))

#define CBUNIT_UNIQUE_DESCRIBE_NAME(localID) CBUNIT_UNIQUE_NAME(__cbunit_describe, localID)
#define CBUNIT_UNIQUE_IT_NAME(localID) CBUNIT_UNIQUE_NAME(__cbunit_it, localID)
#define CBUNIT_UNIQUE_BEFORE_EACH_NAME(localID) CBUNIT_UNIQUE_NAME(__cbunit_before_each, localID)
#define CBUNIT_UNIQUE_BEFORE_NAME(localID) CBUNIT_UNIQUE_NAME(__cbunit_before, localID)
#define CBUNIT_UNIQUE_AFTER_EACH_NAME(localID) CBUNIT_UNIQUE_NAME(__cbunit_after_each, localID)
#define CBUNIT_UNIQUE_AFTER_NAME(localID) CBUNIT_UNIQUE_NAME(__cbunit_after, localID)
#define CBUNIT_UNIQUE_FILE_LINE_INFO_NAME(localID) CBUNIT_UNIQUE_NAME(__cbunit_flinfo, localID)