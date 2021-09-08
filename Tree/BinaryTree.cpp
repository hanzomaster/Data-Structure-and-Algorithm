#include <iostream>
using namespace std;

struct Trunk {
	Trunk *prev{nullptr};
	string str{""};

	Trunk(Trunk *prev, string str) : prev(prev), str(str) {}
	~Trunk() { delete prev; }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p) {
	if (!p) return;
	showTrunks(p->prev);
	cout << p->str;
}

class BinaryTree {
	struct Node {
		int   data{0};
		Node *left{nullptr};
		Node *right{nullptr};
		Node(int data) : data(data) {}
		~Node() {
			delete left;
			delete right;
		}
	} * root{nullptr};

	void destroyTree(Node *leaf) {
		if (leaf) {
			destroyTree(leaf->left);
			destroyTree(leaf->right);
			delete leaf;
		}
	}

	void insert(Node *leaf, int data) {
		if (data < leaf->data)
			if (leaf->left)
				insert(leaf->left, data);
			else
				leaf->left = new Node(data);
		else {
			if (leaf->right)
				insert(leaf->right, data);
			else
				leaf->right = new Node(data);
		}
	}

	void inOrderPrint(Node *leaf) {
		if (leaf) {
			inOrderPrint(leaf->left);
			cout << leaf->data << ',';
			inOrderPrint(leaf->right);
		}
	}

	void postOrderPrint(Node *leaf) {
		if (leaf) {
			inOrderPrint(leaf->left);
			inOrderPrint(leaf->right);
			cout << leaf->data << ',';
		}
	}

	void display(Node *root, Trunk *prev, bool isLeft) {
		if (root == nullptr) {
			return;
		}

		string prev_str = "    ";
		Trunk *trunk = new Trunk(prev, prev_str);

		display(root->right, trunk, true);

		if (!prev) {
			trunk->str = "———";
		} else if (isLeft) {
			trunk->str = ".———";
			prev_str = "   |";
		} else {
			trunk->str = "`———";
			prev->str = prev_str;
		}

		showTrunks(trunk);
		cout << root->data << endl;

		if (prev) {
			prev->str = prev_str;
		}
		trunk->str = "   |";

		display(root->left, trunk, false);
	}

public:
	~BinaryTree() { destroyTree(root); }

	void insert(int data) {
		if (root)
			insert(root, data);
		else
			root = new Node(data);
	}

	void postOrderPrint() {
		postOrderPrint(root);
		cout << endl;
	}
	void inOrderPrint() {
		inOrderPrint(root);
		cout << endl;
	}

	void display(bool isLeft) {
		display(root, nullptr, isLeft);
	}
};
int main() {
	BinaryTree tree;
	tree.insert(10);
	tree.insert(14);
	tree.insert(6);
	tree.insert(5);
	tree.insert(8);
	tree.insert(11);
	tree.insert(18);

	// tree.postOrderPrint();
	// tree.inOrderPrint();

	tree.display(false);
	return 0;
}
