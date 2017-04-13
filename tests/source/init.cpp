#include <Laboratory-work-5-sem2.hpp>
#include <catch.hpp>

SCENARIO("Add") {
    BinarySearchTree r;
    BinarySearchTree* root;
    int rv = r.Add(10, root);
    
    REQUIRE( rv == 10);
}
SCENARIO("print") {
    BinarySearchTree r;
    BinarySearchTree* root;
    int rv = r.print(11, root);
    
    REQUIRE( rv == 11);
}
SCENARIO("Search") {
    BinarySearchTree r;
    BinarySearchTree* root;
    int rv = r.Search(12, root);
    
    REQUIRE( rv == 12);
}
SCENARIO("Deletionh") {
    BinarySearchTree r;
    BinarySearchTree* root;
    int rv = r.Search(13, root);
    
    REQUIRE( rv == 13);
}
SCENARIO("FreeTree") {
    BinarySearchTree r;
    BinarySearchTree* root;
    int rv = r.Search(14, root);
    
    REQUIRE( rv == 14);
}

