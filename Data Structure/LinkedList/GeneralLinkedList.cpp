#include <iostream>
#include <initializer_list>
using namespace std;

template<typename T>
class LinkedList {
	struct Node {
		T value;
		Node *next;

		Node(T value, Node *next = nullptr) : value{value}, next{next} {}

		~Node() {
			delete next;
		}

		void append(Node *next) {
			if (next != nullptr) next->next = this->next;
			this->next = next;
		}
	};

public:
	Node *head = nullptr, *tail = nullptr;

	LinkedList() {}

	LinkedList(initializer_list<T> elements) {
		for (T element : elements) add(element);
	}

	~LinkedList() {
		while (head) {
			Node *temp = head;
			head = head->next;
			delete temp;
		}
	}

	void add(T value) {
		Node *node = new Node(value);
		if (head == nullptr)
			head = tail = node;
		else {
			tail->append(node);
			tail = node;
		}
	}

	void insertAssumeSorted(T value) {
		if (head == nullptr)
			add(value);
		else {
			Node *currentNode = head;
			while (true) {
				if (currentNode->next == nullptr || currentNode->next->value >= value) {
					currentNode->append(new Node(value));
					break;
				}
				currentNode = currentNode->next;
			}
		}
	}

	void print() {
		Node *currentNode = head;
		while (currentNode) {
			cout << currentNode->value << ' ';
			currentNode = currentNode->next;
		}
		cout << endl;
	}
};


int main() {
	LinkedList<int> l{5, 10, 15, 20};
	cout << "List before insertion:" << endl;
	l.print();
	l.insertAssumeSorted(12);
	cout << "List after insertion:" << endl;
	l.print();
}
