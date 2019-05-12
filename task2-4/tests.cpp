//
// Created by apbfor on 22.03.19.
//

#include "task2-4.h"
#include <string>

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

using namespace std;


TEST_CASE("Main case") {
    ifstream fin("/home/user/Desktop/sort/output.txt");
    int a,b;
    fin >> a;
    b = a;
    while (fin>>a) {
        REQUIRE(b<=a);
        b = a;
    }
    fin.close();
}