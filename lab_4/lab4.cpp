#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
class List {
	struct Node {
		T data;
		Node* prev;
		Node* next;
		Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
	};
	Node* head;
	Node* tail;
	unsigned count;
	void initList(const List& other) {
		head = tail = nullptr;
		count = other.count;
		Clear();
		if (other.head == nullptr) {
			return;
		}
		Node* temp = other.head;
		Node* predPointer, * pointer;
		predPointer = new Node(temp->data);
		head = predPointer;
		temp = temp->next;
		if (temp == nullptr) {
			tail = head;
			return;
		}
		while (temp != nullptr) {
			pointer = new Node(temp->data);
			predPointer->next = pointer;
			pointer->prev = predPointer;
			predPointer = pointer;
			temp = temp->next;
		}
		tail = pointer;
	}
public:
	class Iterator {
	private:
		Node* current;
	public:
		Iterator(Node* node) : current(node) {}
		Iterator begin() const {
			return Iterator(head);
		}
		Iterator end() const {
			return Iterator(nullptr);
		}
		const Iterator begin() {
			return Iterator(head);
		}
		const Iterator end() {
			return Iterator(nullptr);
		}
	};
	const T& operator[](int index) const {
		Node node = getAt(index);
		return node->data;
	}
	T& operator[](int index) {
		Node* node = getAt(index);
		return node->data;
	}
	void Clear() {
		Node* current = head;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
		head = tail = nullptr;
		count = 0;
	}
	~List() {
		Clear();
	}
	List() : head(nullptr), tail(nullptr), count(0) {}
	List(const List& other) {
		initList(other);
	}
	List(List&& other) {
		if (this == &other) {
			return *this;
		}
		head = std::move(other.head);
		tail = std::move(other.tail);
		count = std::move(other.count);
		other.head = other.tail = nullptr;
		other.count = 0;
	}
	List(std::initializer_list<T> ilist) : head(nullptr), tail(nullptr), count(0) {
		List<T> temp;
		for (const T& number : ilist) {
			temp.PushBack(number);
		}
		std::swap(head, temp.head);
		std::swap(tail, temp.tail);
		std::swap(count, temp.count);

		if (&temp != this) {
			temp.head = nullptr;
			temp.tail = nullptr;
			temp.count = 0;
		}

	}
	Node* getAt(int index) {
		Node* ptr = head;
		int i = 0;
		if (index >= count) {
			return tail;
		}
		for (int i = 0; i < index; i++) {
			ptr = ptr->next;
		}
		return ptr;
	}
	bool PushBack(const T& element) {
		Node* newNode = new Node(element);
		if (tail == nullptr) {
			tail = head = newNode;
		}
		else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		count++;
		return true;
	}
	bool PushFront(const T& element) {
		Node* newNode = new Node(element);
		if (tail == nullptr) {
			tail = head = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		count++;
		return true;
	}
	bool PopBack(T& element) {
		if (head == nullptr) {
			return false;
		}
		element = tail->data;
		if (count == 1) {
			delete tail;
			head = tail = nullptr;
			count--;
			return true;
		}
		Node* pred = tail->prev;
		pred->next = nullptr;
		delete tail;
		tail = pred;
		count--;
		return true;
	}
	bool PopFront(T& element) {
		if (head == nullptr) {
			return false;
		}
		element = head->data;
		if (count == 1) {
			delete head;
			head = tail = nullptr;
			count--;
			return true;
		}
		Node* pred = head->next;
		pred->prev = nullptr;
		delete head;
		head = pred;
		count--;
		return true;
	}
	bool PeekFront(T& element) const {
		if (count == 0) {
			return false;
		}
		element = head->data;
		return true;
	}
	bool PeekBack(T& element) const {
		if (count == 0) {
			return false;
		}
		element = tail->data;
		return true;
	}
	void InsertAt(const T& value, int index) {
		Node* right = getAt(index);
		Node* pointer = new Node(value);
		if (right == head) {
			pointer->next = head;
			head->prev = pointer;
			head = pointer;
			count++;
			return;
		}
		if (right == tail) {
			tail->next = pointer;
			pointer->prev = tail;
			tail = pointer;
			count++;
			return;
		}
		Node* left = right->prev;
		pointer->prev = left;
		pointer->next = right;
		left->next = pointer;
		right->prev = pointer;
		count++;
	}
	int RemoveAt(int index) {
		Node* pointer = getAt(index);
		int deleteValue = pointer->data;
		count--;
		if (pointer == head) {
			Node* newHead = pointer->next;
			if (newHead != nullptr) {
				newHead->prev = nullptr;
			}
			delete head;
			head = newHead;
			return deleteValue;
		}
		if (pointer == tail) {
			Node* newTail = pointer->prev;
			if (newTail != nullptr) {
				newTail->next = nullptr;
			}
			delete tail;
			tail = newTail;
			return deleteValue;
		}
		Node* left = pointer->prev;
		Node* right = pointer->next;
		left->next = right;
		right->prev = left;
		delete pointer;
		return deleteValue;
	}
	unsigned GetSize() {
		return count;
	}
	List& operator=(const List& other) {
		if (this == &other) {
			return *this;
		}
		initList(other);
		return *this;
	}
	List& operator=(List&& other) {
		if (this == &other) {
			return *this;
		}
		head = std::move(other.head);
		tail = std::move(other.tail);
		count = std::move(other.count);
		other.head = nullptr;
		other.tail = nullptr;
		other.count = 0;
		return *this;
	}
	List& operator=(std::initializer_list<int> ilist) {
		List<T> temp;
		for (const T& number : ilist) {
			temp.PushBack(number);
		}
		swap(head, temp.head);
		swap(tail, temp.tail);
		swap(count, temp.count);

		if (&temp != this) {
			temp.head = nullptr;
			temp.tail = nullptr;
			temp.count = 0;
		}

		return *this;
	}
};

int main() {
	std::initializer_list<int> list = { 2, 10, 42 };
	List<int> myList = list;
	List<int> list2 = { 0, 1, -1 };
	List<int> List{};
	cout << "mylist: " << endl << myList[0] << endl << myList[1] << endl << myList[2] << endl;
	List.PushBack(52);
	List.PushFront(11);
	List.PushBack(27);
	cout << "List:" << endl << List[0] << endl << List[1] << endl << List[2] << endl;
	int num = 1;
	int& element = num;
	cout << "List size: " << List.GetSize() << endl;
	cout << List.PopFront(element) << " " << element << endl;
	cout << List.PopBack(element) << " " << element << endl;
	cout << List.PeekFront(element) << " " << element << endl;
	cout << List.PeekFront(element) << " " << element << endl;
	cout << "List size: " << List.GetSize() << endl;
	return 0;
}