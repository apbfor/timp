#include "iostream"
#include "cstdio"

#include "example.h"

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

TEST_CASE("example", "example")
{
	REQUIRE(sum(5, 10) == 15);
}

TEST_CASE("example1","example1")
{
    REQUIRE(sum(5,12)==10);
}