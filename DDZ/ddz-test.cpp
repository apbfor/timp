//
// Created by apbfor on 26.03.19.
//

#include <iostream>
#include "ddz.h"

using namespace std;

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

using namespace std;


TEST_CASE("1. rabin_karp_matcher", "несколько вхождений") {
    REQUIRE(rabin_karp_matcher("asdxxxfhgjkxxxkljhgij", "xxx") == 3);
}

TEST_CASE("2. rabin_karp_matcher", "подстрока это префикс") {
    REQUIRE(rabin_karp_matcher("polka", "pol") == 0);
}

TEST_CASE("3. rabin_karp_matcher", "подстрока это суффикс") {
    REQUIRE(rabin_karp_matcher("keyboard", "ard") == 5);
}

TEST_CASE("4. rabin_karp_matcher", "подстрока = строка") {
    REQUIRE(rabin_karp_matcher("length", "length") == 0);
}

TEST_CASE("5. rabin_karp_matcher", "подстрока длинной в один символ") {
    REQUIRE(rabin_karp_matcher("table", "l") == 3);
}

TEST_CASE("6. rabin_karp_matcher", "подстрока содержит повторяющиесы символы") {
    REQUIRE(rabin_karp_matcher("qwerry", "rr") == 3);
}

TEST_CASE("7. rabin_karp_matcher", "подстрока и строка содержат повторяющийся символ") {
    REQUIRE(rabin_karp_matcher("qwerrrrrr", "rr") == 3);
}


TEST_CASE("8. rabin_karp_matcher", "тест на вхождение") {
    REQUIRE(rabin_karp_matcher("hjkl;ytgiuy65678jtredfg", "giuy6") == 7);
}


//русский язык не поддерживается (по крайней мере, пока что)
//TEST_CASE("9. rabin_karp_matcher", "поддержка русского языка"){
//    REQUIRE(rabin_karp_matcher("конфета","фета") == 3);
//}
