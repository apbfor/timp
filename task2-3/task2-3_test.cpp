//
// Created by apbfor on 17.03.19.
//

#include "task2-3.h"
#include <string>

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

using namespace std;

TEST_CASE("1. b_m_substring", "simple tests") {
    REQUIRE(b_m_substring("...abcd...", "abcd") == 3);
    REQUIRE(b_m_substring("cccccabcd...", "abcd") == 5);
    REQUIRE(b_m_substring("aaaaaabcd...", "abcd") == 5);
    REQUIRE(b_m_substring("bbbbbabcd...", "abcd") == 5);
    REQUIRE(b_m_substring("abeccaabadbabbad.", "abbad") == 11);
    REQUIRE(b_m_substring("aaccbccbcfaaccbccbccdasdasdaaccbcasdasda", "aaccbccbcc") == 10);
    REQUIRE(b_m_substring("cccccabcd", "abcd") == 5);
}

TEST_CASE("2. b_m_substring", "subStr is prefix") {
    REQUIRE(b_m_substring("qwerty", "qwe") == 0);
}

TEST_CASE("3. b_m_substring", "subStr is suffix") {
    REQUIRE(b_m_substring("qwerty", "rty") == 3);
}

TEST_CASE("4. b_m_substring", "subStr equal str") {
    REQUIRE(b_m_substring("qwerty", "qwerty") == 0);
}

TEST_CASE("5. b_m_substring", "subStr one char length") {
    REQUIRE(b_m_substring("qwerty", "r") == 3);
}

TEST_CASE("6. b_m_substring", "subStr contains repeated chars") {
    REQUIRE(b_m_substring("qwerry", "rr") == 3);
}

TEST_CASE("7. b_m_substring", "subStr and str contains repeated character") {
    REQUIRE(b_m_substring("qwerrrrrr", "rr") == 3);
}

TEST_CASE("8. b_m_substring", "subStr partial match (pref)") {
    REQUIRE(b_m_substring("rrtrtyrtyp.", "rtyp") == 6);
}

TEST_CASE("9. b_m_substring", "subStr partial match (suff)") {
    REQUIRE(b_m_substring("...p..yp.typrtyp", "rtyp") == 12);
}

TEST_CASE("10. b_m_substring", "multiple matches") {
    REQUIRE(b_m_substring("...xxx......xxx....", "xxx") == 3);
}

TEST_CASE("11. b_m_substring", "subStr with repeated suffix") {
    REQUIRE(b_m_substring(".ABCC....", "ABCC") == 1);
}

TEST_CASE("12. b_m_substring", "random example") {
    REQUIRE(b_m_substring("WC377dcUCzWUcir5n5uhP5jZ26mwovdJ6gOBH0dR09tapkebnWGBZzkc4WWsQ9BWnah2", "C377") == 1);
}




// simple

TEST_CASE("1. simple_substring", "simple tests") {
    REQUIRE(simple_substring("...abcd...", "abcd") == 3);
    REQUIRE(simple_substring("cccccabcd...", "abcd") == 5);
    REQUIRE(simple_substring("aaaaaabcd...", "abcd") == 5);
    REQUIRE(simple_substring("bbbbbabcd...", "abcd") == 5);
    REQUIRE(simple_substring("abeccaabadbabbad.", "abbad") == 11);
    REQUIRE(simple_substring("aaccbccbcfaaccbccbccdasdasdaaccbcasdasda", "aaccbccbcc") == 10);
    REQUIRE(simple_substring("cccccabcd", "abcd") == 5);
}

TEST_CASE("2. simple_substring", "subStr is prefix") {
    REQUIRE(simple_substring("qwerty", "qwe") == 0);
}

TEST_CASE("3. simple_substring", "subStr is suffix") {
    REQUIRE(simple_substring("qwerty", "rty") == 3);
}

TEST_CASE("4. simple_substring", "subStr equal str") {
    REQUIRE(simple_substring("qwerty", "qwerty") == 0);
}

TEST_CASE("5. simple_substring", "subStr one char length") {
    REQUIRE(simple_substring("qwerty", "r") == 3);
}

TEST_CASE("6. simple_substring", "subStr contains repeated chars") {
    REQUIRE(simple_substring("qwerry", "rr") == 3);
}

TEST_CASE("7. simple_substring", "subStr and str contains repeated character") {
    REQUIRE(simple_substring("qwerrrrrr", "rr") == 3);
}

TEST_CASE("8. simple_substring", "subStr partial match (pref)") {
    REQUIRE(simple_substring("rrtrtyrtyp.", "rtyp") == 6);
}

TEST_CASE("9. simple_substring", "subStr partial match (suff)") {
    REQUIRE(simple_substring("...p..yp.typrtyp", "rtyp") == 12);
}

TEST_CASE("10. simple_substring", "multiple matches") {
    REQUIRE(simple_substring("...xxx......xxx....", "xxx") == 3);
}