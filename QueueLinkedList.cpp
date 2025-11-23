#include<iostream>
using namespace std;
//QUEUE Using LinkedList

class Node {
    Node* next;
    int data;
public:
    Node(int val):data(val),next(nullptr){}
    friend class ListQueue;
};

class ListQueue {
    Node* front;
    Node* back;
    int size;
public:
    ListQueue():front(nullptr),back(nullptr),size(0){}
    
    bool isempty() {
        return size == 0;
    }
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isempty()) {
            front = back = newNode;
        }
        back->next = newNode;
        back = newNode;

        size++;
    }
    void dequeue() {
        if (isempty()) {
            cout << "\nThe queue is empty can't delete." << endl;
            return;
        }
        Node* temp = front;
        int val = temp->data;
        front = front->next;
        if (front == nullptr) {
            back = nullptr;
        }
        delete temp;
        size--;
        cout << "\ndequeue" << val << endl;
    }
    
    int getsize() {
        cout << "\nThe current size of the queue is :";
        return size;
    }
    int getfront() {
        if (isempty()) {
            cout << "The queue is empty." << endl;
            return -1;
        }
        return front->data;
    }
};
int main() {
    ListQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout << "The front is: " << q.getfront();
    cout << q.getsize();
    q.dequeue();
    cout << endl;
    cout <<"The front is: " << q.getfront();
    cout << q.getsize();
    q.dequeue();
    cout << "The front is: " << q.getfront();
    cout << q.getsize();
    q.dequeue();
    cout << "The front is: " << q.getfront();
    cout << q.getsize();
    q.dequeue();
    cout << "The front is: " << q.getfront();
    cout << q.getsize();
    q.dequeue();

    return 0;
}