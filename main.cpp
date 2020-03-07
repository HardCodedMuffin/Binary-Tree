#include <iostream>
#include "binary_tree.h"


using namespace std;

int main()
{
	int choice, inputInt;
	string inputStr;
	
	binary_tree tree;

	tree.time();

	while (true) {
		choice = tree.get_menu_ops();
		if (choice == 6) break;
		
		switch (choice)
		{
		case 1:
			tree.get_add_menu_ops();
			break;
		case 2:
			cout << "Select a node to view details: " << endl << ">> ";
			cin >> inputInt;
			cout << "Details of the node " << inputInt <<"...\n" << endl;
			cout << "Index of Node	  :	" << inputInt << endl;
			cout << "Value of Node	  :	" << tree.peek_node(inputInt) << endl;
			cout << "Is it a leaf Node?:	" << tree.is_leaf(inputInt) << endl;
			tree.find_node(inputInt);
			break;
		case 3:
			cout << "Select a node to replace: " << endl << ">> ";
			cin >> choice;
			cout << "Now set a new node: " << endl << ">> ";
			cin >> inputInt;
			tree.replace_node(choice, inputInt);
			cout << "\nOut	-> " << choice << endl;
			cout << "In	-> " << inputInt << endl;
			break;
		case 4: 
			cout << "Select a node to remove: " << endl << ">> ";
			cin >> inputInt;
			tree.delete_node(inputInt);
			cout << "\nOut	-> " << choice << endl;
			break;
		case 5:
			tree.preorder_traversal(1);
		default:
			break;
		}
	
	}

	cout << "Quiting...";
}