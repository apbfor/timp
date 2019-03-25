//
// Created by apbfor on 17.03.19.
//

#include "task2-3.h"
#include <string>

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

using namespace std;

TEST_CASE("1. b_m_substring", "несколько вхождений") {
    REQUIRE(b_m_substring("...xxx......xxx....", "xxx") == 3);
}

TEST_CASE("2. b_m_substring", "подстрока это префикс") {
    REQUIRE(b_m_substring("qwerty", "qwe") == 0);
}

TEST_CASE("3. b_m_substring", "подстрока это суффикс") {
    REQUIRE(b_m_substring("qwerty", "rty") == 3);
}

TEST_CASE("4. b_m_substring", "подстрока = строка") {
    REQUIRE(b_m_substring("qwerty", "qwerty") == 0);
}

TEST_CASE("5. b_m_substring", "подстрока длинной в один символ") {
    REQUIRE(b_m_substring("qwerty", "r") == 3);
}

TEST_CASE("6. b_m_substring", "подстрока содержит повторяющиесы символы") {
    REQUIRE(b_m_substring("qwerry", "rr") == 3);
}

TEST_CASE("7. b_m_substring", "подстрока и строка содержат повторяющийся символ") {
    REQUIRE(b_m_substring("qwerrrrrr", "rr") == 3);
}

TEST_CASE("8. b_m_substring", "Случайный набор") {
    REQUIRE(b_m_substring("WC377dcUCzWUcir5n5uhP5jZ26mwovdJGBZzkc4WWsQ9BWnah2", "C377") == 1);
}

TEST_CASE("9. b_m_substring", "тесты на вхождение") {
    REQUIRE(b_m_substring("...abcd...", "abcd") == 3);
    REQUIRE(b_m_substring("abeccaabadbabbad.", "abbad") == 11);
    REQUIRE(b_m_substring("aaccbccbcfaaccbccbccdasdasdaaccbcasa", "aaccbccbcc") == 10);
    REQUIRE(b_m_substring("cccccabcd", "abcd") == 5);
}

TEST_CASE("10. b_m_substring", "поддержка русского языка"){
    REQUIRE(b_m_substring("конфета","фета") == 3);
}




// simple

TEST_CASE("1. simple_indexOf", "обычные тесты на вхождение") {
    REQUIRE(simple_indexOf("...abcd...", "abcd") == 3);
    REQUIRE(simple_indexOf("abeccaabadbabbad.", "abbad") == 11);
    REQUIRE(simple_indexOf("aaccbccbcfaaccbccbccdasdasdaaccbcasdasda", "aaccbccbcc") == 10);
    REQUIRE(simple_indexOf("cccccabcd", "abcd") == 5);
}

TEST_CASE("2. simple_indexOf", "подстрока это префикс") {
    REQUIRE(simple_indexOf("qwerty", "qwe") == 0);
}

TEST_CASE("3. simple_indexOf", "подстрока это суффикс") {
    REQUIRE(simple_indexOf("qwerty", "rty") == 3);
}

TEST_CASE("4. simple_indexOf", "подстрока равная строке") {
    REQUIRE(simple_indexOf("qwerty", "qwerty") == 0);
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