//
// Created by apbfor on 03.03.19.
//

#include "iostream"
#include "cstdio"

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

#include "task2-2.h"

Tree* tree = NULL;

TEST_CASE("add elem+search"){
    tree = InsertNode(tree, 5);
    tree = InsertNode(tree, 52);


    SECTION("elem is in tree") {
        Tree* searching = NULL;
        searching = SearchItem(tree, 5);
        REQUIRE(searching->val == 5);
    }

    SECTION("elem is not in tree"){
        Tree* searching = NULL;
        searching = SearchItem(tree, 12);
        REQUIRE(searching == NULL);
    }
}

TEST_CASE("max,min elem"){
    tree = InsertNode(tree, 5);
    tree = InsertNode(tree, 52);
    tree = InsertNode(tree, 123);
    tree = InsertNode(tree, 2);

    SECTION("max elem"){
        REQUIRE(MaxElement(tree)->val==123);
    }

    SECTION("min elem"){
        REQUIRE(MinElement(tree)->val == 2);
    }
}

TEST_CASE("delete elem"){
    tree = InsertNode(tree, 5);
    tree = InsertNode(tree, 52);
    tree = DeleteNode(tree, 52);
    tree = DeleteNode(tree, 5);

    SECTION("elem was not in tree") {
        Tree *searching = NULL;
        searching = SearchItem(tree, 12);

        REQUIRE(searching == NULL);
    }

    SECTION("elem was in tree"){
        Tree *searching = NULL;
        searching = SearchItem(tree, 12);

        REQUIRE(searching == NULL);
    }
}
