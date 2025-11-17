//STACK(LIFO: LAST IN FIRST OUT)
//Stack is used everywhere recursion or backtracking occurs.

//With Static Arrays:
/*
#include<iostream>
using namespace std;

class Stack {
	int top;
	int capacity = 10;
	int array[10];
	int sz = 0;
public:
	Stack() : top(-1) {}

	bool isEmpty() const {
		if (top == -1) {
			return true;
		}
		return false;
	}

	bool isFull() const {
		if (top == capacity - 1) {
			return true;
		}
		return false;
	}

	void push(int val) {
		if (isFull()) {
			cout << "stack is full" << endl;
			return;
		}
		else {
			top++;
			array[top] = val;
			cout << "Pushed: " << val << endl;
			sz++;
		}
	}

	void pop() {
		if (isEmpty()) {
			cout << "stack is empty" << endl;
			return;
		}
		int val = array[top];
		top--;
		cout << "Popped: " << val << endl;
		sz--;
	}

	int peek() const {
		if (isEmpty()) {
			cout << "stack is empty" << endl;
			return -1;
		}
		return array[top];
	}

	void size() {
		cout << "size is: " << sz << endl;
	}
};


int main() {
	Stack s;
	s.isEmpty();
	s.size();
	s.push(10);
	s.size();
	s.push(20);
	s.push(30);
	s.push(40);
	cout << "peek called:" << s.peek() << endl;
	s.size();
	s.pop();
	cout << "peek called:" << s.peek() << endl;

	return 0;
}
*/


//With Dynamic Arrays:

//In array implementation: stack memory is continuous, allocated once.
/*#include<iostream>
using namespace std;

class Stack {
	int* arr; 
	int top;
	int capacity;
	int sz = 0;
public:
	Stack(int size) {
		capacity = size;
		arr = new int[capacity];
		top = -1;
	}

	bool isEmpty() const {
		return top == -1;
	}

	bool isFull() const {
		return top == capacity - 1;
	}

	void push(int val) {
		if (isFull()) {
			cout << "stack is full" << endl;
			return;
		}
		else {
			arr[++top] = val;
			cout << "Pushed: " << val << endl;
			sz++;
		}
	}

	void pop() {
		if (isEmpty()) {
			cout << "stack is empty" << endl;
			return;
		}
		int val = arr[top--];
		cout << "Popped: " << val << endl;
		sz--;
	}

	int peek() const {
		if (isEmpty()) {
			cout << "stack is empty" << endl;
		}
		return arr[top];
	}
	void size() {
		cout << "size of stack is : " << sz << endl;
	}
	void display() {
		if (isEmpty()) {
			cout << "stack is empty" << endl;
		}
		cout << "Stack (top -> bottom): ";
		for (int i = top; i >= 0; i--) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	~Stack() {
		delete[] arr;
	}
};


int main() {
	Stack s(10);
	s.isEmpty();
	s.push(10);
	cout << "TOP:" << s.peek() << endl;
	s.size();
	s.push(20);
	s.push(30);
	
	s.push(40);
	s.display();
	s.size();
	cout << "TOP:" << s.peek() << endl;
	s.pop();
	cout << "TOP:" << s.peek() << endl;
	s.size();
	s.display();

	return 0;
}*/

//With LinkedList 

//In linked list: each push() creates a new node dynamically using new.
//Each pop() deletes it — this is how dynamic memory works in runtime.
/*
#include<iostream>
using namespace std;

class Node {
	Node* next;
	int data;
public:
	Node(int val) :data(val), next(nullptr) {}
	friend class StackSingleLL;
};

class StackSingleLL {
	Node* top;
public:
	StackSingleLL() {
		top = nullptr;
	}
	void push(int value) {
		Node* newNode = new Node(value);
		newNode->next = top;
		top = newNode;
		cout << "Pushed: " << value << endl;
	}
	void pop() {
		if (isEmpty()) {
			cout << "Stack is empty, can't pop!" << endl;
		}
		Node* temp = top;
		cout << "Popped: " << temp->data << endl;
		top = top->next;
		delete temp;
	}
	int peek() {
		if (isEmpty()) {
			cout << "Stack is empty!" << endl;
		}
		return top->data;
	}
	bool isEmpty() {
		return top == nullptr;
	}
	void display() {
		if (isEmpty()) {
			cout << "Stack is empty!" << endl;
		}
		cout << "Stack (top -> bottom): " << endl;
		for (Node* temp = top; temp != nullptr; temp = temp->next) {
			cout << temp->data << " -> ";
		}
		cout << "null" << endl;
	}
	~StackSingleLL() {
		while (!isEmpty()) {
			pop();
		}
	}
};

int main() {
	StackSingleLL s;

	s.push(5);
	s.push(15);
	s.push(25);
	s.display();

	cout << "Top element: " << s.peek() << endl;

	s.pop();
	s.display();

	s.pop();
	s.pop();
	s.pop(); // underflow

	return 0;
}*/

//Stack used in Recursion

/*#include<iostream>
using namespace std;

int fact(int n) {
	cout << "Entering factorial(" << n << ")\n";
	if (n == 1) {
		cout << "Base case reached,returning1\n";
		return 1;
	}
	int ans = fact(n - 1);
	cout << "Returning" << n << " * " << ans << " from factorial(" << n << ")\n";
	return n * ans;
}

int fibo(int n) {
	cout << "Entering fibonacci " << n << endl;
	if (n == 0 || n == 1) {
		cout << "Entering base case of fibo " << n << " returning " << n << endl;
		return n;
	}
	int a = fibo(n - 1);
	int b = fibo(n - 2);
	cout << "fibo (" << n << ") returning " << a + b << endl;
	return a + b;
}

void TowerOfHanoi(int n, char source, char dest, char aux) {
	if (n == 1) {
		cout << "Move disk 1 from " << source << " to " << dest << endl;
		return;
	}
	TowerOfHanoi(n - 1, source, aux, dest);
	cout << "Move disk " << n << " from " << source << " to " << dest << endl;
	TowerOfHanoi(n - 1, aux, dest, source);
}

int main() {
	int n = 5;
	int result = fact(n);
	cout << "\nFinal result:" << result << endl;
	int result2 = fibo(n);
	cout << "\nFinal result:" << result2 << endl;
	int n1 = 3;
	TowerOfHanoi(n1, 'A', 'B', 'C');


	return 0;
}*/

//Undo/Redo simulation

/*#include<iostream>
#include<stack>
#include<string>
using namespace std;

//action push to undo stack
//UNDO: action popped from undo , pushed to redo , perform reverse of the action
//REDO: action popped from redo , pushed to undo , perform the action again

class undoredoStack {
	string doc;
	stack<string> undo;
	stack<string> redo;
public:
	undoredoStack():doc("") {}

	void typetext(const string &action) {
		undo.push(doc);
		doc = action;

		while (!redo.empty()) {
			redo.pop();
		}
		cout << "[Action] Document changed.\n";
	}
	void undostack() {
		if (undo.empty()) {
			cout << "[Undo] Nothing to undo.\n";
			return;
		}
		redo.push(doc);
		doc = undo.top();
		undo.pop();
		cout << "[Undo] Previous state restored.\n";
	}
	void redostack() {
		if (redo.empty()) {
			cout << "[Redo] Nothing to redo.\n";
			return;
		}
		undo.push(doc);
		doc = redo.top();
		redo.pop();
		cout << "[Redo] Redone.\n";
	}
	void show()const {
		cout << "Document: " << (doc.empty() ? "[empty]" : doc) << "\n";
	}
};

int main() {
	undoredoStack s;
	s.typetext("HELLO GURLL");
	s.show();

	s.typetext("hiii");
	s.show();

	s.undostack();
	s.show();

	s.redostack();
	s.show();

	return 0;
}*/

//Infix → Postfix using Stack

//Postfix Evaluation

//Balanced Parentheses Checker

//Browser back/forward using stack