//
// Created by apbfor on 26.03.19.
//

#include <iostream>
#include "ddz.h"

using namespace std;

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"


TEST_CASE("Rabin-Karp","2") {
    srand(time(NULL));
    string T;
    string P;
    vector<int> vec2 = rabin_karp_matcher(T, P);
    REQUIRE (vec2.size() == 0);

    int n = rand() % 100000 + 10000;
    int m = rand() % 50000 + 1000;
    int s = rand() % (n - m);
    for (int i = 0; i < s; i++)
        T.push_back(rand() % ALPHABET_ENG + START_ASKII_ENG);
    vec2.clear();
    vec2 = rabin_karp_matcher(T, T);
    REQUIRE (vec2.size() == 1);
    vec2.clear();
    vec2 = rabin_karp_matcher(P, T);
    REQUIRE (vec2.size() == 0);

    for (int i = s; i < s + m; i++) {

        char c = rand() % ALPHABET_ENG + START_ASKII_ENG;
        T.push_back(c);
        P.push_back(c);
    }
    for (int i = s + m; i < n; i++)
        T.push_back(rand() % ALPHABET_ENG + START_ASKII_ENG);
    for (int i = s + m; i < n; i++)
        T.push_back(rand() % ALPHABET_ENG + START_ASKII_ENG);
    vector<int> vec = rabin_karp_matcher(T, P);
    REQUIRE (vec.size() != 0);
    for (int i = 0; i < vec.size(); ++i) {
        REQUIRE(P == T.substr(vec[i], m));
    }
}


//русский язык не поддерживается (по крайней мере, пока что)
//TEST_CASE("9. rabin_karp_matcher", "поддержка русского языка"){
//    REQUIRE(rabin_karp_matcher("конфета","фета") == 3);
//}
