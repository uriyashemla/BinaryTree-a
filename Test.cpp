#include "BinaryTree.hpp"
#include "doctest.h"

using namespace ariel;
using namespace std;

BinaryTree<int> tree_of_ints;

TEST_CASE("Binary tree build")
{

    CHECK_THROWS(tree_of_ints.add_left(5, 3));  //there is no root
    CHECK_THROWS(tree_of_ints.add_right(5, 3)); //there is no root

    CHECK_NOTHROW(tree_of_ints.add_root(5)); //creating root 5

    CHECK_NOTHROW(tree_of_ints.add_left(5, 4)); //4 is the left child of 5
    CHECK_NOTHROW(tree_of_ints.add_left(5, 7)); //Now 7 is the left child of 5

    CHECK_NOTHROW(tree_of_ints.add_right(5, 2)); //2 is the right child of 5
    CHECK_NOTHROW(tree_of_ints.add_right(5, 9)); //Now 9 is the right child of 5

    CHECK_THROWS(tree_of_ints.add_left(4, 8));  //4 isnt exist enymore
    CHECK_THROWS(tree_of_ints.add_right(2, 8)); //2 isnt exist enymore

    CHECK_NOTHROW(tree_of_ints.add_root(1));    //changing the root to 1
    CHECK_THROWS(tree_of_ints.add_left(5, 8));  //5 isnt exist enymore
    CHECK_THROWS(tree_of_ints.add_right(5, 8)); //5 isnt exist enymore

    CHECK_NOTHROW(tree_of_ints.add_left(9, 6));   //6 is the left child of 9
    CHECK_NOTHROW(tree_of_ints.add_right(9, 10)); //10 is the right child of 9
    CHECK_NOTHROW(tree_of_ints.add_left(1, 11));  //Now 11 is the new left child of of the root 1
    CHECK_NOTHROW(tree_of_ints.add_right(1, 12));  //Now 12 is the new right child of of the root 1

    CHECK_NOTHROW(tree_of_ints.add_left(11, 4));  //4 is the left child of 11
    CHECK_NOTHROW(tree_of_ints.add_right(11, 2)); //2 is the right child of 9

    CHECK_THROWS(tree_of_ints.add_left(7, 8));  //7 isnt exist enymore
    CHECK_THROWS(tree_of_ints.add_right(7, 8)); //7 isnt exist enymore
    CHECK_THROWS(tree_of_ints.add_left(9, 8));  //9 isnt exist enymore
    CHECK_THROWS(tree_of_ints.add_right(9, 8)); //9 isnt exist enymore
}

TEST_CASE("preorder")
{
    auto it = tree_of_ints.begin_preorder();
}

TEST_CASE("postorder")
{
}

TEST_CASE("inorder")
{
}