//LINKED LIST START 
//non-contagious,dynamic, [data+pointer(address of next node)],lastnode(points to null)


//SINGLY LINKEDLIST with full functionality 
/*#include<iostream>
using namespace std;

class Node {
 int data;
 Node* next;
public:
 Node(int val):data(val),next(nullptr){}
 friend class SinglyLL;
};
class SinglyLL {
 Node* head;
 Node* tail;
public:
 SinglyLL() {
  head = nullptr;
  tail = nullptr;
 }

 void pushFront(int value) {
  Node* newNode = new Node(value);
  if (head == nullptr) {
   head = tail = newNode;
  }
  else {
   newNode->next = head;
   head = newNode;

  }
 }
 void pushback(int value) {
  Node* newNode = new Node(value);
  if (head == nullptr) {
   head = tail = newNode;
  }
  else {
   tail->next = newNode;
   newNode->next = nullptr;
   tail = newNode;
  }
 }
 void popFront() {
  Node* temp = head;
  if (head == nullptr) {
   cout << "List is empty." << endl;
   return;
  }
  else {
   head = temp->next;
   temp->next = nullptr;
   delete temp;
  }
 }
 void popBack() {
  Node* temp = head;
  if (head == nullptr) {
   cout << "List is empty." << endl;
   return;
  }
  while (temp->next != tail) {
   temp = temp->next;
  }
  delete tail;
  tail = temp;
  temp->next = nullptr;
 }
 void pushMiddle(int pos,int value) {
  if (head == nullptr) {
   cout << "List is empty." << endl;
   pushFront(value);
  }
  if (pos < 0) {
   cout << "Invalid position." << endl;
  }
  Node* newNode = new Node(value);
  Node* temp = head;
  for (int i = 0; i < pos - 1; i++) {
   temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
 }
 void popMiddlebyValue(int value) {
  if (head == nullptr) {
   cout << "List is empty." << endl;
   return;
  }
  if (head->data == value) {
   popFront();
  }
  Node* temp = head;
  while (temp->next != nullptr && temp->next->data != value) {
   temp = temp->next;
  }
  if (temp->next == nullptr) {
   cout << "Value not found in the list." << endl;
   return;
  }
  Node* deleteNode = temp->next;
  temp->next = temp->next->next;
  delete deleteNode;
 }
 void popMiddlebyPosition(int pos) {
  if (head == nullptr) {
   cout << "List is empty." << endl;
   return;
  }
  if (pos == 0) {
   popFront();
   return;
  }
  Node* temp = head;
  int currentPos = 0;
  while (temp != nullptr && currentPos < pos - 1) {
   temp = temp->next;
   currentPos++;
  }
  if (temp == nullptr || temp->next == nullptr) {
   cout << "Position out of range." << endl;
   return;
  }
  Node* deleteNode = temp->next;
  temp->next = temp->next->next;
  delete deleteNode;
 }

 void deleteAllOccurrences(int value) {
  if (head == nullptr) {
   cout << "List is empty." << endl;
   return;
  }
  while (head != nullptr && head->data == value) {
   Node* temp = head;
   head = head->next;
   delete temp;
  }
  if (head == nullptr) {
   cout << "All occurrences of " << value << " deleted (list
became empty)." << endl;
   return;
  }
  Node* temp = head;
  while (temp->next != nullptr) {
   if (temp->next->data == value) {
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
   }
   else {
    temp = temp->next;
   }
  }
 }
 int search(int key) {
  Node* temp = head;
  int idx = 0;
  while (temp != nullptr) {
   if (temp->data == key) {
    return idx;
   }
   temp = temp->next;
   idx++;
  }
  return idx;
 }

 void display()
 {
  Node* temp = head;
  while (temp != nullptr) {
   cout << temp->data << " ->";
   temp = temp->next;
  }
  cout << "NULL" << endl;
 }
void maxFind() const {
 if (head == nullptr) {
  cout << "List is empty.\n";
  return;
 }
 int maxVal = head->data;
 for (Node* temp = head; temp != nullptr; temp = temp->next)
  if (temp->data > maxVal)
   maxVal = temp->data;
 cout << "Maximum Value: " << maxVal << endl;
}

void minFind() const {
 if (head == nullptr) {
  cout << "List is empty.\n";
  return;
 }
 int minVal = head->data;
 for (Node* temp = head; temp != nullptr; temp = temp->next)
  if (temp->data < minVal)
   minVal = temp->data;
 cout << "Minimum Value: " << minVal << endl;
}

void reverse() {
 Node* prev = nullptr;
 Node* curr = head;
 Node* next = nullptr;
 while (curr != nullptr) {
  next = curr->next;
  curr->next = prev;
  prev = curr;
  curr = next;
 }
 head = prev;
}

void sort() {
 if (head == nullptr || head->next == nullptr)
  return;

 for (Node* i = head; i != nullptr; i = i->next)
  for (Node* j = i->next; j != nullptr; j = j->next)
   if (i->data > j->data)
    swap(i->data, j->data);
}
 ~SinglyLL() {
  while (head != nullptr)
   popFront();
 }
};

int main() {
 SinglyLL L;
 cout << "\nCALLING PUSH FRONT:" << endl;
 L.pushFront(90);
 L.pushFront(11);
 L.pushFront(12);
 L.pushFront(13);
 L.pushFront(14);
 L.pushFront(15);
 L.pushFront(16);
 L.display();
 cout << "\nCALLING PUSH BACK:" << endl;
 L.pushback(90);
 L.pushback(8);
 L.pushback(7);
 L.pushback(6);
 L.display();
 cout << "\nCALLING POP FRONT:" << endl;
 L.popFront();
 L.display();
 cout << "\nCALLING POP BACK:" << endl;
 L.popBack();
 L.display();
 cout << "\nCALLING PUSH AT MIDDLE:" << endl;
 L.pushMiddle(4, 90);
 L.display();
 cout << "\nCALLING POP AT MIDDLE BY VALUE:" << endl;
 L.popMiddlebyValue(90);
 L.display();
 cout << "\nCALLING POP AT MIDDLE BY POSITION:" << endl;
 L.popMiddlebyPosition(4);
 L.display();
 cout << "\nDELETING ALL OCCURENCE OF A VALUE:" << endl;
 L.deleteAllOccurrences(90);
 L.display();
 int n;
 cout << "Enter what you want ti search in list:";
 cin >> n;
 cout << "\nFound at " << n << " index: " << L.search(n);

 return 0;
}*/

//Doubly:

/*#include<iostream> 
using namespace std;

class Node {
    int data;
    Node* next;
    Node* prev;
public:
    Node(int val) :data(val), next(nullptr), prev(nullptr) {}
    friend class DoublyLL;
};
class DoublyLL {
    Node* head;
    Node* tail;
public:
    DoublyLL() {
        head = tail = nullptr;
    }
    void pushFront(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = nullptr;
            tail = newNode;
        }
    }
    void pushMiddle(int pos, int val) {
        if (pos == 0 || head == nullptr) {
            pushFront(val);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        if (temp->next == nullptr) { //temp=tail 
            pushBack(val);
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    void popFront() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void popBack() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }
    void popMiddlebyposition(int pos) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
        }
        if (pos == 0) {
            popFront();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "position out of range." << endl;
            return;
        }
        if (temp == tail) {
            popBack();
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    void popMiddlebyvalue(int val) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
        }
        Node* temp = head;
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "value not found." << endl;
            return;
        }
        if (temp == head) {
            popFront();
            return;
        }
        if (temp == tail) {
            popBack();
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    void deleteallOccurencesOfValue(int val) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) {
                Node* todelete = temp;
                temp = temp->next;
                if (todelete == head) {
                    popFront();
                }
                else if (todelete == tail) {
                    popBack();
                }
                else {
                    todelete->prev->next = todelete->next;
                    todelete->next->prev = todelete->prev;
                    delete todelete;
                }
            }
            else {
                temp = temp->next;
            }
        }
    }
    void reverse() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        Node* cur = head;
        Node* temp = nullptr;
        while (cur != nullptr) { //swap next and prev for each node 
            temp = cur->prev;
            cur->prev = cur->next;
            cur->next = temp;
            cur = cur->prev;
        }
        if (temp != nullptr) { //swap head and tail 
            head = temp->prev;
        }
    }
    void sort() {
        if (head == nullptr) {
            return;
        }
        for (Node* i = head; i != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }
    void maxFind() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        int maxVal = head->data;
        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            maxVal = max(maxVal, temp->data);
        }
        cout << "Maximum Value: " << maxVal << endl;
    }
    void minFind() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        int minVal = head->data;
        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            minVal = min(minVal, temp->data);
        }
        cout << "Minimum Value: " << minVal << endl;
    }
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "NULL <- ";
        while (temp != nullptr) {
            cout << temp->data << " <--> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    int search(int key) {
        Node* temp = head;
        int idx = 0;
        while (temp != nullptr) {
            if (temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return idx;
    }
};
int main() {
    DoublyLL L;
    cout << "\nCALLING PUSH FRONT:" << endl;
    L.pushFront(10);
    L.pushFront(20);
    L.pushFront(30);
    L.pushFront(10);
    L.pushFront(40);
    L.pushFront(10);
    L.display();
    cout << "\nCALLING PUSH BACK:" << endl;
    L.pushBack(70);
    L.pushBack(10);
    L.pushBack(7);
    L.pushBack(6);
    L.display();
    cout << "\nCALLING POP FRONT:" << endl;
    L.popFront();
    L.display();
    cout << "\nCALLING POP BACK:" << endl;
    L.popBack();
    L.display();
    cout << "\nCALLING PUSH AT MIDDLE:" << endl;
    int n1;
    cout << "Enter where you want to add in list:";
    cin >> n1;
    L.pushMiddle(n1, 90);
    cout << "added value at index" << n1 << endl;
    L.display();

    cout << "\nCALLING POP AT MIDDLE BY VALUE:" << endl;
    int n2;
    cout << "Enter what you want to delete in list:";
    cin >> n2;
    L.popMiddlebyvalue(n2);
    L.display();
    cout << "\nCALLING POP AT MIDDLE BY POSITION:" << endl;
    int n3;
    cout << "Enter where you want to delete in list:";
    cin >> n3;
    L.popMiddlebyposition(n3);
    L.display();
    cout << "\nDELETING ALL OCCURENCE OF A VALUE:" << endl;
    int n4;
    cout << "Enter what you want to delete in list completely:";
    cin >> n4;
    L.deleteallOccurencesOfValue(n4);
    L.display();
    int n;
    cout << "Enter what you want to search in list:";
    cin >> n;
    cout << "\nFound at " << n << " index: " << L.search(n);

    L.sort();
    cout << "\nSorted List:\n";
    L.display();

    L.reverse();
    cout << "\nReversed List:\n";
    L.display();

    L.maxFind();
    L.minFind();

    return 0;
}*/

//Circular:

/*#include <iostream> 
using namespace std;

class Node {
    int data;         // stores value of the node 
    Node* next;       // stores address of the next node 
public:
    Node(int val) : data(val), next(nullptr) {}
    friend class SinglyCircularLL;   // allows LL class to access private 
    members
};

class SinglyCircularLL {
    Node* head;       // points to first node 
    Node* tail;       // points to last node (whose next = head) 
public:
    // Constructor: initialize empty list 
    SinglyCircularLL() {
        head = tail = nullptr;
    }

    // Check if list is empty 
    bool isEmpty() const {
        return head == nullptr;
    }


    // Insert node at beginning 
    void pushFront(int val) {
        Node* newNode = new Node(val);

        // Case 1: list is empty 
        if (isEmpty()) {
            head = tail = newNode;
            tail->next = head;  // circular link 
        }
        // Case 2: list already has nodes 
        else {
            newNode->next = head; // newNode points to old head 
            head = newNode;       // update head 
            tail->next = head;    // tail must point to new head now 
        }
    }

    // Insert node at end 
    void pushBack(int val) {
        Node* newNode = new Node(val);

        // Case 1: empty list 
        if (isEmpty()) {
            head = tail = newNode;
            tail->next = head;   // circular link 
        }
        // Case 2: already has elements 
        else {
            tail->next = newNode;  // old tail points to new node 
            tail = newNode;        // new node becomes tail 
            tail->next = head;     // maintain circular link 
        }
    }

    // Insert node in the middle at a given position 
    void pushMiddle(int pos, int val) {
        if (isEmpty() || pos == 0) {  // if empty or inserting at start 
            pushFront(val);
            return;
        }

        Node* temp = head;
        // Move to (pos-1)th node 
        for (int i = 0; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        // If reached tail, just add at end 
        if (temp == tail) {
            pushBack(val);
            return;
        }

        // Create new node and insert 
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }


    // Delete node from front 
    void popFront() {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        // Case 1: single node 
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        // Case 2: multiple nodes 
        Node* temp = head;
        head = head->next;     // move head to next node 
        tail->next = head;     // maintain circular link 
        delete temp;           // delete old head 
    }

    // Delete node from back 
    void popBack() {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        // Case 1: single node 
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        // Case 2: multiple nodes — find 2nd last node 
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;          // delete last node 
        tail = temp;          // update tail 
        tail->next = head;    // maintain circular link 
    }

    // Delete node at specific position (0-based) 
    void popMiddleByPosition(int pos) {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        // Case 1: delete at start 
        if (pos == 0) {
            popFront();
            return;
        }

        Node* temp = head;

        // Move to (pos-1)th node 
        for (int i = 0; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        // If reached end of list or invalid position 
        if (temp->next == head) {
            cout << "Position out of range.\n";
            return;
        }

        // Delete target node 
        Node* target = temp->next;
        if (target == tail)
            popBack();
        else {
            temp->next = target->next;
            delete target;
        }
    }

    // Delete node by value (first occurrence) 
    void popMiddleByValue(int val) {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        // If value is at head 
        if (head->data == val) {
            popFront();
            return;
        }

        Node* temp = head;
        do {
            if (temp->next->data == val) {
                Node* target = temp->next;
                if (target == tail)
                    tail = temp;  // update tail if deleting last 
                temp->next = target->next;
                delete target;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Value not found.\n";
    }

    // Delete ALL occurrences of a given value 
    void deleteAllOccurrences(int val) {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        // Repeatedly delete from head if head matches value 
        while (head && head->data == val) {
            popFront();
            if (isEmpty()) return;
        }

        Node* temp = head;
        do {
            if (temp->next->data == val) {
                Node* delNode = temp->next;
                if (delNode == tail)
                    tail = temp;
                temp->next = delNode->next;
                delete delNode;
                if (temp->next == head) break; // stop if back at start 
            }
            else {
                temp = temp->next;
            }
        } while (temp != head);
    }

    // Display all nodes (stops when we reach head again) 
    void display() {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "HEAD -> ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(HEAD again)" << endl;
    }

    // Reverse the circular list 
    void reverse() {
        if (isEmpty() || head == tail) return;

        Node* prev = tail;
        Node* curr = head;
        Node* next = nullptr;

        // Reverse links for every node 
        do {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);

        // Update head and tail 
        tail = head;
        head = prev;
    }

    // Sort list using bubble sort 
    void sort() {
        if (isEmpty() || head == tail)
            return;

        Node* i = head;
        do {
            Node* j = i->next;
            while (j != head) {
                if (i->data > j->data)
                    swap(i->data, j->data);
                j = j->next;
            }
            i = i->next;
        } while (i != head);
    }

    // Find maximum value 
    void maxFind() const {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        int maxVal = head->data;
        Node* temp = head->next;
        do {
            if (temp->data > maxVal)
                maxVal = temp->data;
            temp = temp->next;
        } while (temp != head);
        cout << "Maximum Value: " << maxVal << endl;
    }

    // Find minimum value 
    void minFind() const {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        int minVal = head->data;
        Node* temp = head->next;
        do {
            if (temp->data < minVal)
                minVal = temp->data;
            temp = temp->next;
        } while (temp != head);
        cout << "Minimum Value: " << minVal << endl;
    }

    // Search for a key and return its position 
    int search(int key) const {
        if (isEmpty()) return -1;

        Node* temp = head;
        int index = 0;
        do {
            if (temp->data == key)
                return index;
            temp = temp->next;
            index++;
        } while (temp != head);

        return -1;  // not found 
    }
};
int main() {
    SinglyCircularLL L;

    cout << "Inserting at FRONT:\n";
    L.pushFront(10);
    L.pushFront(20);
    L.pushFront(30);
    L.display();

    cout << "\nInserting at BACK:\n";
    L.pushBack(40);
    L.pushBack(50);
    L.display();

    cout << "\nInserting at MIDDLE (pos=2, val=25):\n";
    L.pushMiddle(2, 25);
    L.display();

    cout << "\nDeleting FRONT:\n";
    L.popFront();
    L.display();

    cout << "\nDeleting BACK:\n";
    L.popBack();
    L.display();

    cout << "\nDeleting by VALUE (25):\n";
    L.popMiddleByValue(25);
    L.display();

    cout << "\nSorting:\n";
    L.sort();
    L.display();

    cout << "\nReversing:\n";
    L.reverse();
    L.display();

    cout << "\nFinding Max and Min:\n";
    L.maxFind();
    L.minFind();

    int n;
    cout << "\nEnter value to search: ";
    cin >> n;
    int pos = L.search(n);
    if (pos != -1)
        cout << "Found at position: " << pos << endl;
    else
        cout << "Not found.\n";

    return 0;
}*/
