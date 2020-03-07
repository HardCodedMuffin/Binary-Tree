#include "binary_tree.h"
#include <iostream>


binary_tree::binary_tree()
{
	tree = (int*)calloc(MAX_BOUND, sizeof(int));
}

int binary_tree::root(int data)
{
	if (tree[1] != NULL)
		std::cout << "Tree already had root";
	else
		tree[1] = data;
	return 0;
}

int binary_tree::set_left(int index, int data)
{
	if (tree[index] == NULL)
		std::cout << "Can't set child at " << (index * 2) << ", no parent found " << std::endl;
	else
		tree[(index * 2)] = data;
	return 0;
}

int binary_tree::set_right(int index, int data)
{
	if (tree[index] == NULL)
		std::cout << "Can't set child at " << (index * 2) + 1 << ", no parent found " << std::endl;
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

void binary_tree::preorder(int index)
{
	if (index >= 0 && tree[index] != NULL)
	{
		std::cout << tree[index] << " ";
		preorder(get_left_child(index));
		preorder(get_right_child(index));
	}
}

int binary_tree::is_leaf(int index)
{
	// to check of the indices of the left and right children are valid or not
	if (!get_left_child(index) && !get_right_child(index))
		return 1;
	// to check if both the children of the node are null or not
	if (tree[get_left_child(index)] == NULL && tree[get_right_child(index)] == NULL)
		return 1;
	return 0; // node is not a leaf
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

int binary_tree::peek_node(int index)
{	
	return tree[index];
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


int binary_tree::find_parent(int index) {
	if (index == 0)
		std::cout << "The root node cannot have a parent";
	else if (index % 2 == 0)
		return (index / 2);
	else
		return (index - 1) / 2;
}

void binary_tree::find_node(int index) {
	if (is_leaf(index))
		std::cout << tree[index] <<" is valid and parent of " << tree[index] << " is " << find_parent(index) << " but no child found!" << std::endl;
	else 
		std::cout << tree[index] <<" is valid and left child is -> " << get_left_child(index) << " right child -> " << get_right_child(index) << std::endl;
}
