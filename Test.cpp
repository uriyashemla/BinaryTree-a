#include "BinaryTree.hpp"
#include "doctest.h"

using namespace ariel;
using namespace std;

BinaryTree<int> tree_of_ints;
BinaryTree<string> tree_of_strings;
BinaryTree<int> complex_tree;
BinaryTree<int[]> array_tree;

TEST_CASE("Binary tree (int) building")
{
    CHECK_THROWS(tree_of_ints.add_left(5, 3));    //there is no root
    CHECK_THROWS(tree_of_ints.add_right(5, 3));   //there is no root
    CHECK_NOTHROW(tree_of_ints.add_root(5));      //creating root 5
    CHECK_NOTHROW(tree_of_ints.add_left(5, 4));   //4 is the left child of 5
    CHECK_NOTHROW(tree_of_ints.add_left(5, 7));   //Now 7 is the left child of 5
    CHECK_NOTHROW(tree_of_ints.add_right(5, 2));  //2 is the right child of 5
    CHECK_NOTHROW(tree_of_ints.add_right(5, 9));  //Now 9 is the right child of 5
    CHECK_THROWS(tree_of_ints.add_left(4, 8));    //4 isnt exist enymore
    CHECK_THROWS(tree_of_ints.add_right(2, 8));   //2 isnt exist enymore
    CHECK_NOTHROW(tree_of_ints.add_root(1));      //changing the root to 1
    CHECK_THROWS(tree_of_ints.add_left(5, 8));    //5 isnt exist enymore
    CHECK_THROWS(tree_of_ints.add_right(5, 8));   //5 isnt exist enymore
    CHECK_NOTHROW(tree_of_ints.add_left(9, 6));   //6 is the left child of 9
    CHECK_NOTHROW(tree_of_ints.add_right(9, 10)); //10 is the right child of 9
    CHECK_NOTHROW(tree_of_ints.add_left(1, 11));  //Now 11 is the new left child of of the root 1
    CHECK_NOTHROW(tree_of_ints.add_right(1, 12)); //Now 12 is the new right child of of the root 1
    CHECK_NOTHROW(tree_of_ints.add_left(11, 4));  //4 is the left child of 11
    CHECK_NOTHROW(tree_of_ints.add_right(11, 2)); //2 is the right child of 11
    CHECK_THROWS(tree_of_ints.add_left(7, 8));    //7 isnt exist enymore
    CHECK_THROWS(tree_of_ints.add_right(7, 8));   //7 isnt exist enymore
    CHECK_THROWS(tree_of_ints.add_left(9, 8));    //9 isnt exist enymore
    CHECK_THROWS(tree_of_ints.add_right(9, 8));   //9 isnt exist enymore

    /*
                         1
                   
                    11      12
                  
                  4   2    6   10

    */
}

TEST_CASE("Iterator with int tree")
{
    string check;
    //checks that the in-order works as it should
    for (auto it1 = tree_of_ints.begin_inorder(); it1 != tree_of_ints.end_inorder(); ++it1)
    {
        check += to_string(it1.in_cur->data) + " ";
    }
    CHECK(check == "4 11 2 1 6 12 10 ");
    check = "";

    //checks that the pre-order works as it should
    for (auto it = tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder(); ++it)
    {
        check += to_string(it.pre_cur->data) + " ";
    }
    CHECK(check == "1 11 4 2 12 6 10 ");
    check = "";

    //checks that the post-order works as it should
    for (auto it1 = tree_of_ints.begin_postorder(); it1 != tree_of_ints.end_postorder(); ++it1)
    {
        check += to_string(it1.pos_cur->data) + " ";
    }
    CHECK(check == "4 2 11 6 10 12 1 ");
}

TEST_CASE("Binary tree (string) building")
{
    CHECK_THROWS(tree_of_strings.add_left("p", "q"));   //there is no root
    CHECK_THROWS(tree_of_strings.add_right("p", "q"));  //there is no root
    CHECK_NOTHROW(tree_of_strings.add_root("p"));       //creating root "p"
    CHECK_NOTHROW(tree_of_strings.add_left("p", "o"));  //"o" is the left child of "p"
    CHECK_NOTHROW(tree_of_strings.add_left("p", "s"));  //Now "s" is the left child of "p"
    CHECK_NOTHROW(tree_of_strings.add_right("p", "t")); //"t" is the right child of "p"
    CHECK_NOTHROW(tree_of_strings.add_right("p", "r")); //Now "r" is the right child of "p"
    CHECK_THROWS(tree_of_strings.add_left("o", "w"));   //"o" isnt exist enymore
    CHECK_THROWS(tree_of_strings.add_right("t", "w"));  //"t" isnt exist enymore
    CHECK_NOTHROW(tree_of_strings.add_root("a"));       //changing the root to "a"
    CHECK_THROWS(tree_of_strings.add_left("p", "r"));   //"p" isnt exist enymore
    CHECK_THROWS(tree_of_strings.add_right("p", "l"));  //"p" isnt exist enymore
    CHECK_NOTHROW(tree_of_strings.add_left("r", "f"));  //"f" is the left child of "r"
    CHECK_NOTHROW(tree_of_strings.add_right("r", "g")); //"g" is the right child of "r"
    CHECK_NOTHROW(tree_of_strings.add_left("a", "b"));  //Now "b" is the new left child of of the root "a"
    CHECK_NOTHROW(tree_of_strings.add_right("a", "c")); //Now "c" is the new right child of of the root "a"
    CHECK_NOTHROW(tree_of_strings.add_left("b", "d"));  //"d" is the left child of "b"
    CHECK_NOTHROW(tree_of_strings.add_right("b", "e")); //"e" is the right child of "b"
    CHECK_THROWS(tree_of_strings.add_left("s", "q"));   //"s" isnt exist enymore
    CHECK_THROWS(tree_of_strings.add_right("s", "q"));  //"s" isnt exist enymore
    CHECK_THROWS(tree_of_strings.add_left("r", "i"));   //"r" isnt exist enymore
    CHECK_THROWS(tree_of_strings.add_right("r", "k"));  //"r" isnt exist enymore

    /*
                         a
                   
                    b      c
                  
                  d   e    f   g

    */
}

TEST_CASE("Iterator with string tree")
{
    string check;
    //checks that the in-order works as it should
    for (auto it1 = tree_of_strings.begin_inorder(); it1 != tree_of_strings.end_inorder(); ++it1)
    {
        check += it1.in_cur->data + " ";
    }
    CHECK(check == "d b e a f c g ");
    check = "";
    //checks that the pre-order works as it should
    for (auto it = tree_of_strings.begin_preorder(); it != tree_of_strings.end_preorder(); ++it)
    {
        check += it.pre_cur->data + " ";
    }
    CHECK(check == "a b d e c f g ");
    check = "";
    //checks that the post-order works as it should
    for (auto it1 = tree_of_strings.begin_postorder(); it1 != tree_of_strings.end_postorder(); ++it1)
    {
        check += it1.pos_cur->data + " ";
    }
    CHECK(check == "d e b f g c a ");
}

TEST_CASE("Build complex tree")
{
    CHECK_NOTHROW(complex_tree.add_root(1));
    CHECK_NOTHROW(complex_tree.add_left(1, 2));
    CHECK_NOTHROW(complex_tree.add_right(1, 3));
    CHECK_NOTHROW(complex_tree.add_left(2, 4));
    CHECK_NOTHROW(complex_tree.add_right(2, 5));
    CHECK_NOTHROW(complex_tree.add_left(3, 6));
    CHECK_NOTHROW(complex_tree.add_right(3, 7));
    CHECK_NOTHROW(complex_tree.add_left(4, 8));
    CHECK_NOTHROW(complex_tree.add_left(5, 10));
    CHECK_NOTHROW(complex_tree.add_right(5, 11));
    CHECK_NOTHROW(complex_tree.add_left(10, 12));
    CHECK_NOTHROW(complex_tree.add_right(8, 9));
    CHECK_NOTHROW(complex_tree.add_left(6, 13));
    CHECK_NOTHROW(complex_tree.add_right(6, 14));
    CHECK_NOTHROW(complex_tree.add_left(7, 15));
    CHECK_NOTHROW(complex_tree.add_right(7, 16));
    CHECK_NOTHROW(complex_tree.add_left(16, 17));
    CHECK_NOTHROW(complex_tree.add_right(17, 18));

    /*
                1

        2               3

    4      5         6       7

  8      10 11    13  14   15  16

   9   12                     17

                                 18
*/
}

TEST_CASE("Iterator with int tree")
{
    string check;
    //checks that the in-order works as it should
    for (auto it1 = complex_tree.begin_inorder(); it1 != complex_tree.end_inorder(); ++it1)
    {
        check += to_string(it1.in_cur->data) + " ";
    }
    CHECK(check == "8 9 4 2 12 10 5 11 1 13 6 14 3 15 7 17 18 16 ");
    check = "";

    //checks that the pre-order works as it should
    for (auto it = complex_tree.begin_preorder(); it != complex_tree.end_preorder(); ++it)
    {
        check += to_string(it.pre_cur->data) + " ";
    }
    CHECK(check == "1 2 4 8 9 5 10 12 11 3 6 13 14 7 15 16 17 18 ");
    check = "";

    //checks that the post-order works as it should
    for (auto it1 = complex_tree.begin_postorder(); it1 != complex_tree.end_postorder(); ++it1)
    {
        check += to_string(it1.pos_cur->data) + " ";
    }
    CHECK(check == "9 8 4 12 10 11 5 2 13 14 6 15 18 17 16 7 3 1 ");
}


/*
TEST_CASE("Build array tree")
{
    int r[] = {1, 2};
    int lc[] = {4, 5};
    int rc[] = {5, 6};
    CHECK_NOTHROW(array_tree.add_root(r));
    CHECK_NOTHROW(array_tree.add_right(r, rc));
    CHECK_NOTHROW(array_tree.add_left(r, lc));
    
}
*/

TEST_CASE("Build big tree")
{
    BinaryTree<int> big_left_tree;
    big_left_tree.add_root(1);
    for (int i = 2; i < 10000; i++)
    {
        CHECK_NOTHROW(big_left_tree.add_left(i - 1, i));
    }
    BinaryTree<int> big_right_tree;
    big_right_tree.add_root(1);
    for (int i = 2; i < 10000; i++)
    {
        CHECK_NOTHROW(big_right_tree.add_left(i - 1, i));
    }
}
