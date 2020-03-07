#ifndef binary_tree

const int MAX_BOUND = 15;

class binary_tree
{
private:
	int* tree;
public:
	
	binary_tree();
	
	int root(int data);
	int set_left(int index, int data);
	int set_right(int index, int data);
	int get_left_child(int index);
	int get_right_child(int index);
	
	void preorder(int index);
	
	int find_parent(int index);
	void find_node(int index);
	int is_leaf(int index);
	int get_max(int a, int b);
	int get_height(int index);
	int peek_node(int index);
	void delete_node(int data);
	void replace_node(int data, int newdata);

};

#endif // !binary_tree

