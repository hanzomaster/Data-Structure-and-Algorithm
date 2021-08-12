#include <iostream>
using namespace std;
class DoubleLinkedList {
	struct Node {
		int data;
		Node *prev{nullptr};
		Node *next{nullptr};
	};
	Node *head, *tail;

public:
	DoubleLinkedList() : head(nullptr), tail(nullptr){};
	~DoubleLinkedList() {
		while (head) {
			Node *temp = head;
			head = head->next;
			delete temp;
		}
	}

	void push(int value) {
		Node *new_node = new Node();
		new_node->data = value;

		if (isEmpty()) {
			head = new_node;
			tail = new_node;
		} else {
			new_node->next = head;
			head->prev = new_node;
			head = new_node;
		}
	}

	void append(int value) {
		Node *new_node = new Node();
		new_node->data = value;

		if (isEmpty()) {
			head = new_node;
			tail = new_node;
		} else {
			tail->next = new_node;
			new_node->prev = tail;
			tail = new_node;
		}
	}

	void insertAfterValue(int value, int data) {
		Node *new_node = new Node();
		new_node->data = data;

		Node *current = head;
		while (current != nullptr && current->data != value) {
			current = current->next;
		}
		if (current == nullptr)
			cout << "Vi tri khong hop le" << endl;
		else if (current->next == nullptr) {
			current->next = new_node;
			new_node->prev = current;
			tail = new_node;
		} else {
			Node *next_node = current->next;
			current->next = new_node;
			new_node->prev = current;
			new_node->next = next_node;
			next_node->prev = new_node;
		}
	}

	void print() {
		Node *temp = head;
		while (temp) {
			cout << temp->data << ' ';
			temp = temp->next;
		}
		cout << endl;
	}

	bool isEmpty() {
		return head == nullptr;
	}

	bool find(int value) {
		if (isEmpty())
			return false;

		Node *current = head;
		while (current != nullptr && current->data != value)
			current = current->next;

		if (current == nullptr)
			return false;
		return true;
	}
};

int main() {
	DoubleLinkedList list;
	list.push(5);
	list.push(4);
	list.append(6);
	list.insertAfterValue(5, 7);
	list.print();
	cout << list.find(5) << endl;
	return 0;
}
