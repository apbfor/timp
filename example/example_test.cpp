#include "iostream"
#include "cstdio"

#include "example.h"

// внимание! define CATCH_CONFIG_MAIN должен быть выше include  "../catch.hpp"
// иначе будет ошибка вида
// .../tests.cpp:23: undefined reference to Catch::StringRef::StringRef(char const*)
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

TEST_CASE("example", "example")
{
	REQUIRE(sum(5, 10) == 15);
}