#include <iostream>
using namespace std;
class LinkedList {
private:
	struct Node {
		int data{};
		Node *next;
	} * head;

public:
	LinkedList() : head(nullptr) {}
	~LinkedList() {
		while (head) {
			Node *temp = head;
			head = head->next;
			delete temp;
		}
	}

	void push(int data) {
		Node *new_node = new Node();
		new_node->data = data;
		new_node->next = head;
		head = new_node;
	}

	void append(int data) {
		Node *new_node = new Node();
		new_node->data = data;
		new_node->next = nullptr;
		if (head == nullptr)
			head = new_node;
		else {
			Node *last = head;
			while (last->next != nullptr)
				last = last->next;
			last->next = new_node;
		}
	}

	void insertAt(int position, int data) {
		if (position != 0 && head == nullptr) {
			cout << "Invalid position";
			return;
		}
		Node *new_node = new Node();
		new_node->data = data;
		if (position == 0) {
			new_node->next = head;
			head = new_node;
		} else {
			Node *temp = head;
			while (position > 2) {
				position--;
				temp = temp->next;
			}
			new_node->next = temp->next;
			temp->next = new_node;
		}
	}

	void deleteValue(int data) {
		Node *node = head;
		if (node && node->data == data) {
			head = node->next;
			delete node;
			return;
		}
		Node *prev = nullptr;
		while (node && node->data != data) {
			prev = node;
			node = node->next;
		}
		if (node == nullptr) {
			cout << "Khong tim thay gia tri can xoa" << endl;
			return;
		}
		prev->next = node->next;
		delete node;
	}

	void print() {
		Node *node = head;
		while (node) {
			cout << node->data << ' ';
			node = node->next;
		}
		cout << endl;
	}
	void reverse() {
		Node *current = head;
		Node *prev = nullptr, *next = nullptr;

		while (current) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	};

	int size() {
		int count = 0;
		Node *current = head;
		while (current) {
			count++;
			current = current->next;
		}
		return count;
	}
};

int main() {
	LinkedList dataList;
	dataList.push(5);
	dataList.append(4);
	// dataList.insertAt(3, 7);
	dataList.append(8);
	cout << "Linked list:" << endl;
	dataList.print();
	dataList.reverse();
	cout << "Linked list after reverse:" << endl;
	dataList.print();
	return 0;
}
