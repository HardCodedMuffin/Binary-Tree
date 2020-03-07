#include "binary_tree.h"
#include <iostream>

binary_tree::binary_tree()
{
	tree = (int*)calloc(MAX_BOUND, sizeof(int));
}

int binary_tree::root(int data)
{
	if (tree[1] != NULL)
		std::cout << "Tree already had root!" << std::endl;
	else
		tree[1] = data;
	return 0;
}

int binary_tree::set_left(int index, int data)
{
	if (tree[index] == NULL)
		std::cout << "Can't set child at " << (index * 2) << ", no parent found! " << std::endl;
	else
		tree[(index * 2)] = data;
	return 0;
}

int binary_tree::set_right(int index, int data)
{
	if (tree[index] == NULL)
		std::cout << "Can't set child at " << (index * 2) + 1 << ", no parent found! " << std::endl;
	else 
		tree[(index * 2) + 1] = data;
	return 0;
}

int binary_tree::get_left_child(int index)
{
	if (tree[index] != NULL && (2 * index) <= MAX_BOUND)
		return (2 * index);
	return -1;
}

int binary_tree::get_right_child(int index)
{
	if (tree[index] != NULL && ((2 * index) + 1) <= MAX_BOUND)
		return (2 * index) + 1;
	return -1;
}

int binary_tree::get_max(int a, int b)
{
	return (a > b) ? a : b;
}

int binary_tree::get_height(int index)
{
	if (tree[index] == MAX_BOUND || index <= 0 || is_leaf(index))
		return 0;
	return(get_max(get_height(get_left_child(index)), get_height(get_right_child(index))) + 1);
}

int binary_tree::get_menu_ops()
{
	std::string inputStr = " ";

	while (true) {
		std::cout << "\nALGORITHMS AND DATA STRUCTURES II ASSIGNMENT 1 \n" << std::endl;
		std::cout << "	1 -> Add Node " << std::endl;
		std::cout << "	2 -> Details " << std::endl;
		std::cout << "	3 -> Replace Node " << std::endl;
		std::cout << "	4 -> Remove Node " << std::endl;
		std::cout << "	5 -> Traverse  " << std::endl;
		std::cout << "	6 -> Quit" << std::endl;
		std::cout << "\nSelect an operation to continue: " << std::endl;
		std::cout << ">> ";
		std::cin >> inputStr;

		if (inputStr == "1") return 1;
		else if (inputStr == "2") return 2;
		else if (inputStr == "3") return 3;
		else if (inputStr == "4") return 4;
		else if (inputStr == "5") return 5;
		else if (inputStr == "6") return 6;
		else
			std::cout << "Invalid input!\n" << std::endl;
	}
}

int binary_tree::get_add_menu_ops()
{
	std::string inputStr = " ";
	std::cout << "	1 -> Add root node " << std::endl;
	std::cout << "	2 -> Add left node " << std::endl;
	std::cout << "	3 -> Add right node " << std::endl << ">> ";
	std::cin >> inputStr;

	if (inputStr == "1") {
		std::cout << "Select a root: " << std::endl << ">> ";
		std::cin >> parent;
		root(parent);
		return 1;
	}
	else if (inputStr == "2") {
		std::cout << "Select parent first: " << std::endl << ">> ";
		std::cin >> parent;
		std::cout << "Now set the left child: " << std::endl << ">> ";
		std::cin >> data;
		set_left(parent, data);
		return 2;
	}
	else if (inputStr == "3") {
		std::cout << "Select parent first: " << std::endl << ">> ";
		std::cin >> parent;
		std::cout << "Now set the right child: " << std::endl << ">> ";
		std::cin >> data;
		set_right(parent, data);
		return 3;
	}
	else {
		std::cout << "Invalid option!" << std::endl;
		return 4;
	}
}

int binary_tree::is_leaf(int index)
{
	// to check of the indices of the left and right children are valid or not
	if (!get_left_child(index) && !get_right_child(index)) {
		return 1;
	}
	// to check if both the children of the node are null or not
	if (tree[get_left_child(index)] == NULL && tree[get_right_child(index)] == NULL) {
		return 1;
	}
	return 0; // node is not a leaf
}

int binary_tree::find_parent(int index) {
	if (index == 0)
		std::cout << "The root node cannot have a parent";
	else if (index % 2 == 0)
		return (index / 2);
	else
		return (index - 1) / 2;
}

int binary_tree::peek_node(int index)
{	
	return tree[index];
}

void binary_tree::find_node(int index) {
	if (is_leaf(index))
		std::cout <<"Parent		  :	" << find_parent(index) << std::endl << "Left Child	  :	Not Found" << std::endl << "Right Child	  :	Not Found" << std::endl << std::endl;
	else 
		std::cout << "Parent		  :	" << find_parent(index) << std::endl << "Left Child	  :	" << get_left_child(index) << std::endl << "Right Child	  :	"<< get_right_child(index) << std::endl << std::endl;
}

void binary_tree::delete_node(int data)
{
	for (int i = 0; i < MAX_BOUND; i++)
	{
		if (tree[i] == data)
		{
			for (int j = i; j < (MAX_BOUND - 1); j++)
			{
				tree[j] = tree[j + 1];
			}
			break;
		}
	}
}

void binary_tree::replace_node(int data, int newdata)
{
	for (int i = 0; i < MAX_BOUND; i++)
	{
		if (tree[i] == data)
		{
			tree[i] = newdata;
			break;
		}
	}
}

void binary_tree::preorder_traversal(int index)
{
	if (index >= 0 && tree[index] != NULL)
	{
		std::cout << tree[index] << " ";
		preorder_traversal(get_left_child(index));
		preorder_traversal(get_right_child(index));
	}
}