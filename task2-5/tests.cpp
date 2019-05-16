//
// Created by apbfor on 05.05.19.
//

#include "task2-5.h"
#include <string>

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

using namespace std;


TEST_CASE("1. Check adj list") {
    Graph b({4,7,8,9,11,15}, { {4,7}, {7,9}, {11,15} });
    vector<int> requires = {4,7,9,8,11,15};
    REQUIRE(b.onlyfortests == requires);
}
