#pragma once

#define it CBUNIT_IT
#define describe CBUNIT_DESCRIBE
#define skip CBUNIT_SKIP
#define before CBUNIT_BEFORE
#define beforeEach CBUNIT_BEFORE_EACH
#define after CBUNIT_AFTER
#define afterEach CBUNIT_AFTER_EACH
#define failTest(message) throw CBUNIT_TEST_FAILURE(message)