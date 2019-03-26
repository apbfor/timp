//
// Created by apbfor on 17.03.19.
//

#include "task2-3.h"
#include <string>

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

using namespace std;


TEST_CASE("1. b_m_substring", "несколько вхождений") {
    REQUIRE(b_m_substring("asdxxxfhgjkxxxkljhgij", "xxx") == 3);
}

TEST_CASE("2. b_m_substring", "подстрока это префикс") {
    REQUIRE(b_m_substring("polka", "pol") == 0);
}

TEST_CASE("3. b_m_substring", "подстрока это суффикс") {
    REQUIRE(b_m_substring("keyboard", "ard") == 5);
}

TEST_CASE("4. b_m_substring", "подстрока = строка") {
    REQUIRE(b_m_substring("length", "length") == 0);
}

TEST_CASE("5. b_m_substring", "подстрока длинной в один символ") {
    REQUIRE(b_m_substring("table", "l") == 3);
}

TEST_CASE("6. b_m_substring", "подстрока содержит повторяющиесы символы") {
    REQUIRE(b_m_substring("qwerry", "rr") == 3);
}

TEST_CASE("7. b_m_substring", "подстрока и строка содержат повторяющийся символ") {
    REQUIRE(b_m_substring("qwerrrrrr", "rr") == 3);
}


TEST_CASE("8. b_m_substring", "тест на вхождение") {
    REQUIRE(b_m_substring("hjkl;ytgiuy65678jtredfg", "giuy6") == 7);
}

TEST_CASE("9. b_m_substring", "поддержка русского языка"){
    REQUIRE(b_m_substring("конфета","фета") == 3);
}




// simple

TEST_CASE("1. simple_indexOf", "обычные тесты на вхождение") {
    REQUIRE(simple_indexOf("cccccabcd", "abcd") == 5);
}

TEST_CASE("2. simple_indexOf", "подстрока это префикс") {
    REQUIRE(simple_indexOf("polka", "pol") == 0);
}

TEST_CASE("3. simple_indexOf", "подстрока это суффикс") {
    REQUIRE(simple_indexOf("keyboard", "ard") == 5);
}

TEST_CASE("4. simple_indexOf", "подстрока равная строке") {
    REQUIRE(simple_indexOf("length", "length") == 0);
}

TEST_CASE("5. simple_indexOf", "подстрока это один символ") {
    REQUIRE(simple_indexOf("qwerty", "r") == 3);
}

TEST_CASE("6. simple_indexOf", "подстрока содержит повторяющийся символ") {
    REQUIRE(simple_indexOf("qwerry", "rr") == 3);
}

TEST_CASE("7. simple_indexOf", "подстрока и строка содержат повторяющийся символ") {
    REQUIRE(simple_indexOf("qwerrrrrr", "rr") == 3);
}

TEST_CASE("10. simple_indexOf", "несколько вхождений") {
    REQUIRE(simple_indexOf("...xxx......xxx....", "xxx") == 3);
}

TEST_CASE("11. simple_indexOf", "поддержка русского языка"){
    REQUIRE(simple_indexOf("школьный","льн") == 3);
}