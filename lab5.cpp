#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
 
int tabs = 0;
int number = 0;
unsigned int k = 0;
unsigned int n = 0;

template <class Type>
class BinarySearchTree
{
private:
	Type data;
	BinarySearchTree *left; 
	BinarySearchTree *right; 
	BinarySearchTree *parent; 
	
public:
void Add(Type new_data, BinarySearchTree *&root)
{
	if (!root)
	{
		root = new BinarySearchTree;
		root->data = new_data;
		root->parent = root;
		root->left = 0;
		root->right = 0;
		return;
	}
	else if (root->data > new_data) Add(new_data, root->left);
	else if (root->data < new_data) Add(new_data, root->right); 
	else return;
}

void Search(BinarySearchTree *root)
{
	if (!root) return;
	
	if (k == 0) 
	{ 
		cout << endl << "Type the number you want to find: "; 
		cin >> number;
	}
	k++; 

	if(root->data == number) 
		{ 
			cout << endl << "[+] The number " << number << " was found!:)";
			n++;
		}
	
	Search(root->left);
	Search(root->right);

}

void print_line(BinarySearchTree *root)
{
	if (!root) return; 
	
	print_line(root->right);
 
	cout << root->data << " ";

	print_line(root->left);

	return;
}

void print(BinarySearchTree *root)
{
	if (!root) return; 
	
	tabs++; 
	print(root->right);
 
	for (unsigned int i = 0; i < tabs; ++i) cout << "- "; 
	cout << root->data << endl;

	print(root->left);
 	tabs--;

	return;
}

void Deletion(BinarySearchTree *root)
{
	if (!root) return;
	
	cout << endl << endl << "Type the node you want to delete: "; 
	cin >> number;

	if (number == root->data) 
		{ 
			cout << endl << "[-] Error: You are trying to remove the root of the tree!" << endl;
			return;
		}

	removeNode(root, number, parent);
	
}

BinarySearchTree* findMaxNode(BinarySearchTree *root) 
{
    if (root == NULL) exit(4);
    if (root->right) return findMaxNode(root->right);
    return root;
}

void removeNode(BinarySearchTree *root, int number, BinarySearchTree *parent) {
    if (root == NULL) {
        return;
    }
 
    if (root->data > number) removeNode(root->left, number, root);
    else if (root->data < number) removeNode(root->right, number, root);
    else 
    {
        if (root->left && root->right) 
        {
        	BinarySearchTree* localMax = findMaxNode(root->left);
        	root->data = localMax->data;
            removeNode(root->left, localMax->data, root);
            return;
        } 
        else if (root->left) 
        {
            BinarySearchTree* localMax = findMaxNode(root->left);
            root->data = localMax->data;
            removeNode(root->left, localMax->data, root);
        } 
        else if (root->right) 
        {
            if (root->left == parent) parent->left = root->right;
            else parent->right = root->right;
            delete root;
            root = NULL;
        } 
        else 
        {
            if (parent->left == root) parent->left = NULL;
            else parent->right = NULL;
            delete root;
            root = NULL;
        }
    }
}
 
void FreeTree(BinarySearchTree *&root)
{
	if (root != NULL)
	{
		FreeTree(root->left);
		FreeTree(root->right);
		delete root;
		root = NULL;
	}
	
	return;
}
 
};

int main(void)
{
	BinarySearchTree<unsigned int> *root = 0;
	BinarySearchTree<unsigned int> *ptr;

	unsigned int* node;
	unsigned int size = 0;
	auto temp = 0;

	cout << "Print the number of nodes: ";
	cin >> temp;
	try
	{
		if(temp < 0) throw 1;
	}
	catch(int test)
	{
		cout << endl << "[-] Exception " << test << ": The number of nodes can't be negative!!!" << endl;
		return 0;
	}
	size = temp;

	node = new unsigned int [size];

	for (unsigned int i = 0; i < size; ++i)
	{
		cout << "Add node " << i+1 << ": ";
		cin >> temp;
		try
		{
			if( temp < 0 ) throw 2;
		}
		catch( int test )
		{
			cout << endl << "[-] Exception " << test << ": The node of tree can't be negative!!!" << endl;
			return 0;
		}
		node[i] = temp;
		cout << endl;
	}


	for (unsigned int i = 0; i < size; ++i)
	{
		ptr->Add(node[i], root);
	}

	cout << endl << size << " ";
	ptr->print_line(root);
	cout << endl << endl << "Binary Search Tree:" << endl;
 
	ptr->print(root);
	ptr->Search(root);
	if( n == 0 ) cout << endl << "[-] The number " << number << " was not found!:(";

	ptr->Deletion(root);
	cout << endl << "The result of deletion: " << endl;
	ptr->print(root);

	ptr->FreeTree(root);
 	delete [] node;
	cout << endl << endl << "Press any button to exit the program " << endl;
	_getch();
	return 0;
}

