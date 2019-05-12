//
// Created by apbfor on 03.03.19.
//

#include "iostream"
#include "cstdio"

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

#include "task2-2.h"

TEST_CASE("1. Search elem + remove elem + add elem"){
    Tree tree;
    SECTION("search in empty tree"){
        REQUIRE(tree.search(3)== -1);
    }
    SECTION("added and deleted"){
        tree.add(5);
        tree.removeElem(5);
        REQUIRE(tree.search(5)== -1);

        tree.add(5);
        REQUIRE(tree.search(5)== 5);
    }
}

TEST_CASE("2. Max and min elem"){
    Tree tr;
    tr.add(20);
    tr.add(8);
    tr.add(79);
    tr.add(18);
    tr.add(2);
    tr.add(42);

    REQUIRE(tr.maxElement() == 79);

    REQUIRE(tr.minElement()==2);

}


TEST_CASE("3. Remove from empty tree"){
    Tree tr;
    tr.removeElem(8);
    tr.add(5);
    REQUIRE(tr.search(5)== 5);
}

TEST_CASE("4. Min and Max in empty tree"){
    Tree tr;
    SECTION("just created"){
        REQUIRE(tr.minElement()==-1);
        REQUIRE(tr.maxElement()==-1);
    }
    SECTION("added and deleted elements"){
        tr.add(5);
        tr.add(7);
        tr.removeElem(5);
        tr.removeElem(7);
        REQUIRE(tr.minElement()==-1);
        REQUIRE(tr.maxElement()==-1);
    }
}

TEST_CASE("3. Check correct tree"){
    Tree tr;
    srand(time(NULL));
    for(int i=0; i<5000; i++){
        tr.add(rand()%50000);
        REQUIRE(tr.checkCorrect()==true);
    }

}

TEST_CASE("4. Tree size"){
    Tree tr;
    REQUIRE(tr.getSize()==0);
    tr.add(5);
    tr.add(8);
    tr.add(12);
    tr.add(7);
    tr.add(156);
    REQUIRE(tr.getSize()==5);
    tr.removeElem(7);
    REQUIRE(tr.getSize()==4);
}