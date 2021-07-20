//
// Created by d1r3ct0r on 20/07/2021.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "includes/IntBST.h"

TEST_CASE("Check length after 3 simple inserts","[Tree Length]"){
    IntBST tree;
    tree.insert(0);
    tree.insert(1);
    tree.insert(2);
    REQUIRE(tree.length() == 3);
}

TEST_CASE("Enter 3 and check if we can find it", "[Tree search]"){
    IntBST tree;
    tree.insert(0);
    tree.insert(3);
    tree.insert(5);
    REQUIRE(tree.search(4)==false);
    REQUIRE(tree.search(3) ==true);

}