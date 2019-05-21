//
// Created by apbfor on 05.05.19.
//

#include "task2-5.h"
#include <string>

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

using namespace std;


TEST_CASE("1. Graph DFS") {
    Graph b({4,7,8,9,11,15}, { {4,7}, {7,9}, {11,15} });
    vector<int> vec1 = {4,7,9,8,11,15};
    b.connectedComponents();
    REQUIRE(b.onlyfortests == vec1);
}

TEST_CASE("2. Check connected list"){
    Graph b({4, 7, 8, 9, 11, 15, 56, 6, 3, 2, 1}, {{4,  7},
                                                   {7,  9},
                                                   {15, 11},
                                                   {1,   2},
                                                   {2,   3},
                                                   {3,  7}});
    vector<int> v1 = {1,2,3,7,4,9};
    vector<int> v2 = {11,15};
    b.connectedComponents();
    REQUIRE(b.getConnected().at(0)==v1);
    REQUIRE(b.getConnected().at(1)==v2);
}

TEST_CASE("3. Another graph DFS") {
    Graph g({1, 2, 3, 4, 5, 9, 12, 16}, {{1, 3},
                                         {2, 1},
                                         {9, 12},
                                         {9, 16}});
    g.connectedComponents();
    vector<int>vector1 = {1,3,2,4,5,9,12,16};
    REQUIRE(g.onlyfortests == vector1);
}

TEST_CASE("4. Check connected list for another graph"){
    Graph g({1, 2, 3, 4, 5, 9, 12, 16}, {{1, 3},
                                         {2, 1},
                                         {9, 12},
                                         {9, 16}});
    vector<int> v1 = {1,3,2};
    vector<int> v2 = {9,12,16};
    g.connectedComponents();
    REQUIRE(g.getConnected().at(0)==v1);
    REQUIRE(g.getConnected().at(1)==v2);
}