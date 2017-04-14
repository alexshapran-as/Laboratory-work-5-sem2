#include <iostream>
#include <stdlib.h>
using namespace std;
 
template <class Type>
class BinarySearchTree
{

public: 
	BinarySearchTree *parent; 
	Type data;
	int Add(unsigned int new_data, BinarySearchTree *&root);
	int print(int check1, BinarySearchTree *root);
	int Search(int check2, BinarySearchTree *root);
	int Deletion(int check3, BinarySearchTree *root);
	int FreeTree(int check4, BinarySearchTree *&root);
};

template <class Type> 
int BinarySearchTree<Type>::Add(Type new_data, BinarySearchTree<Type> *&root)		
 {		
 	if (!root)		
 	{		
 		root = new BinarySearchTree;		
 		root->data = new_data;		
 		root->parent = root;		
 		return root->data;		
 	}		
 	else if (root->data > new_data) Add(new_data, root);		
 	else if (root->data < new_data) Add(new_data, root); 		
 	else return root->data;		
 }		
template <class Type> 
int BinarySearchTree<Type>::print(int check1, BinarySearchTree *root)		
 {		
 	if (!root) return check1; 		
 	if (root->data == 10 ) check1 = 12;		
 			
 	return check1;		
 }
template <class Type> 
int BinarySearchTree<Type>::Search(int check2, BinarySearchTree *root)		
 {		
 	if (!root) return check2;		
 		
 	if(root->data >= 0) 		
 		{ 		
 			root->data = 1;		
 		}		
 			
 	return root->data;		
 		
 }
template <class Type> 
int BinarySearchTree<Type>::Deletion(int check3, BinarySearchTree *root)		
 {		
 	if (!root) return check3;		
 			
 	cout << endl << endl << "Type the node you want to delete: "; 		
 		
 	if (root->data == check3) 		
 		{ 		
 			cout << endl << "[-] Error: You are trying to remove the root of the tree!" << endl;		
 			return 0;		
 		}		
 		
 			
 }		
template <class Type> 
int BinarySearchTree<Type>::FreeTree(int check4, BinarySearchTree *&root)		
 {		
 	if (root != NULL)		
 	{		
 		delete root;		
		root = NULL;		
	}		
			
	return check4;		
}
