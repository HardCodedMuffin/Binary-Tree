#include <iostream>
#include "binary_tree.h"


using namespace std;

int main()
{
	char select;
	int choice, parent,input;
	
	binary_tree tree;
	
		cout << "ALGORITHMS AND DATA STRUCTURES II ASSIGNMENT 1" << endl << endl;
		
		cout << "	1 -> Add     Node" << endl;
		cout << "	2 -> Find    Node" << endl;
		cout << "	3 -> Check   Node" << endl;
		cout << "	4 -> Replace Node" << endl;
		cout << "	5 -> Remove  Node" << endl;
		cout << endl << "Choose an operation: \n>> ";
		cin >> choice;
		tree.preorder(1);

}