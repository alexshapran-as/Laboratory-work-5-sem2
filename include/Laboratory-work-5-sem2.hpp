#include <iostream>
#include <stdlib.h>
using namespace std;
 
template <class Type>
class BinarySearchTree
{

public: 
	BinarySearchTree *parent; 
	unsigned int data;
	int Add(unsigned int new_data, BinarySearchTree *&root);
	int print(int check1, BinarySearchTree *root);
	int Search(int check2, BinarySearchTree *root);
	int Deletion(int check3, BinarySearchTree *root);
	int FreeTree(int check4, BinarySearchTree *&root);
};
