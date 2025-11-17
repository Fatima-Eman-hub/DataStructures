//	ARRAYS AND VECTORS

//Static Arrays

/*#include<iostream>
using namespace std;

class staticArray {
	int arr[100];
	int size;
public:
	staticArray():size(0){}

	void display() {
		if (size == 0) {
			cout << "Array is empty.\n";
			return;
		}
		cout << "Array: " << endl;
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void pushback(int val) {
		if (size == 100) {
			cout << "array overflow" << endl;
			return;
		}
		arr[size++] = val;
	}
	
	void InsertAtPos(int pos, int val) {
		if (pos<0 || pos>size) {
			cout << "invalid index" << endl;
			return;
		}
		if (size==100) {
			cout << "array overflow" << endl;
			return;
		}
		for (int i = size; i > pos; i--) {
			arr[i] = arr[i - 1];
		}
		arr[pos] = val;
		size++;
	}
	void deleteAtPos(int pos) {
		if (size == 0) {
			cout << "empty array , can't delete" << endl;
			return;
		}
		if (pos<0 || pos>size) {
			cout << "invalid index" << endl;
			return;
		}
		for (int i = 0; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
	}
	void popback() {
		if (size == 0) {
			cout << "empty array , can't delete" << endl;
			return;
		}
		size--;
	}
	int search(int val) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == val) {
				return i;
			}
			return -1;
		}
	}
	int getSize() {
		return size;
	}
};

int main() {
	staticArray s;
	int choice, value, pos;
	while (true) {
		cout << "\n----- STATIC ARRAY MENU -----\n";
		cout << "1. Insert at position\n";
		cout << "2. Delete at position\n";
		cout << "3. Search element\n";
		cout << "4. Push Back\n";
		cout << "5. Pop Back\n";
		cout << "6. Display\n";
		cout << "7. Size\n";
		cout << "0. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {

		case 1:
			cout << "Enter value: ";
			cin >> value;
			cout << "Enter position: ";
			cin >> pos;
			s.InsertAtPos(pos, value);
			break;

		case 2:
			cout << "Enter position: ";
			cin >> pos;
			s.deleteAtPos(pos);
			break;
		case 3:
			cout << "Enter value to search: ";
			cin >> value;
			pos = s.search(value);
			if (pos == -1)
				cout << "Not found.\n";
			else
				cout << "Found at index: " << pos << endl;
			break;
		case 4:
			cout << "Enter value: ";
			cin >> value;
			s.pushback(value);
			break;
		case 5:
			s.popback();
			break;
		case 6:
			s.display();
			break;
		case 7:
			cout << "Current size: " << s.getSize() << endl;
			break;
		case 0:
			return 0;
		default:
			cout << "Invalid choice.\n";
		}
	}
	return 0;
}*/

//Dynamic Array

/*#include<iostream>
using namespace std;

class DynamicArray {
	int* arr;
	int size;
	int capacity;
public:
	DynamicArray(int cap = 2) {
		if (cap <= 0) {
			cap = 2;
		}
		arr = new int[cap];
		size = 9;
		capacity = cap;
	}
	~DynamicArray() {
		delete[] arr;
		arr = nullptr; 
	}
	void insertAtPos(int pos, int val) {
		if (pos<0 || pos>size) {
			cout << "invalid index." << endl;
			return;
		}
		if (size == capacity) {
			resize();
		}
		for (int i = size; i > pos; i--) {
			arr[i] = arr[i - 1];
		}
		arr[pos] = val;
		size++;
	}
	void pushback(int val) {
		if (size == capacity) {
			resize();
		}
		arr[size++] = val;
	}
	void popback() {
		if (size == 0) {
			cout << "empty array." << endl;
		}
		size--;
	}
	void deleteAtPos(int pos) {
		if (size == 0) {
			cout << "Array is empty.\n";
			return;
		}
		if (pos < 0 || pos >= size) {
			cout << "Invalid index.\n";
			return;
		}
		for (int i = pos; i < size - 1; i++) {
			arr[i] = arr[i + 1];
			size--;
		}
	}
	void safeDelete() {
		if (arr != nullptr) {
			delete[] arr;
			arr = nullptr;
			size = 0;
			capacity = 0;
		}
	}
	int search(int val) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == val) {
				return i;
			}
			return -1;
		}
	}
	int getSize() { return size; }
	int getcapacity() { return capacity; }
	int resize() {
		cout << "Resizing from " << capacity << " to " << capacity * 2 << endl;

		int newCapacity = capacity * 2;
		int* temp = new int[newCapacity];
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		capacity = newCapacity;
	}
	void display() {
		if (size == 0) {
			cout << "Array is empty.\n";
			return;
		}
		cout << "Array: ";
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	DynamicArray A;
	int choice, value, pos;

	while (true) {
		cout << "\n----- DYNAMIC ARRAY MENU -----\n";
		cout << "1. Push Back\n";
		cout << "2. Insert at Position\n";
		cout << "3. Delete at Position\n";
		cout << "4. Search\n";
		cout << "5. Display\n";
		cout << "6. Show Size & Capacity\n";
		cout << "7. Safe Delete Array\n";
		cout << "0. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter value: ";
			cin >> value;
			A.pushback(value);
			break;

		case 2:
			cout << "Enter value: ";
			cin >> value;
			cout << "Enter position: ";
			cin >> pos;
			A.insertAtPos(pos, value);
			break;

		case 3:
			cout << "Enter position: ";
			cin >> pos;
			A.deleteAtPos(pos);
			break;

		case 4:
			cout << "Enter value to search: ";
			cin >> value;
			pos = A.search(value);
			if (pos == -1)
				cout << "Not found.\n";
			else
				cout << "Found at index: " << pos << endl;
			break;

		case 5:
			A.display();
			break;

		case 6:
			cout << "Size = " << A.getSize() << endl;
			cout << "Capacity = " << A.getcapacity() << endl;
			break;

		case 7:
			A.safeDelete();
			cout << "Array Deleted Safely!\n";
			break;

		case 0:
			return 0;

		default:
			cout << "Invalid choice.\n";
		}
	}

	return 0;
}*/


//2D ARRAYS(Row-Col-Major)
//
/*
#include<iostream>
using namespace std;

//row-major
int* twoDto1D(int arr[][3], int r, int c) {
	static int flat[9];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "index " << i * c + j << "= " << i << "," << j << endl;
			flat[i * c + j] = arr[i][j];
		}
	}
	return flat;
}
//column major
int* twoDtoOneD(int arr[][3], int r, int c) {
	static int flat[9];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "index " << i + j * r << "= " << i << "," << j << endl;
			flat[i + j * r] = arr[i][j];
		}
	}
	return flat;
}

int main() {
	int R = 3, C = 3;
	int arr[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	cout << "Original 2d array: " << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Indexes,ROW-Major: " << endl;
	int* oneDR = twoDto1D(arr, R, C);
	cout << "\nConverted 1d array,ROW-Major: " << endl;
	for (int i = 0; i < R*C; i++) {
			cout << oneDR[i] << " ";
	}
	cout << endl;
	cout << "Indexes,Col-Major: " << endl;
	int* oneDC = twoDtoOneD(arr, R, C);
	cout << "\nConverted 1d array,Col-Major: " << endl;
	for (int i = 0; i < R * C; i++) {
		cout << oneDC[i] << " ";
	}
	cout << endl;

	return 0;
}*/


//2D ARRAYS: (Special Matrices)
//1D TO 2D also
/*
#include<iostream>
using namespace std;

//Scalar 2d to 1D	(Same for diagonal matrix) 
int* scalar(int arr[][3],int r,int c) {
	static int flat[3];
	int idx = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == j) {
				cout << "index " << i * c + j << "= " << i << "," << j << endl;
				flat[idx++] = arr[i][j];
			}
		}
	}
	return flat;
}

//Upper Triangular 2D to 1D
int* uppertriangular(int arr[][4],int r,int c) {
	static int flat[10];
	int idx = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == j || i<j) {
				cout << "index " << i * c + j << "= " << i << "," << j << endl;
				flat[idx++] = arr[i][j];
			}
		}
	}
	return flat;
}
//Lower Triangular 2D to 1D
int* lowertriangular(int arr[][4], int r, int c) {
	static int flat[10];
	int idx = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == j || i > j) {
				cout << "index " << i * c + j << "= " << i << "," << j << endl;
				flat[idx++] = arr[i][j];
			}
		}
	}
	return flat;
}
//Converting a simple 1D array to 2D matrix/array
// For 1D index k → 2D indices (i,j):
//	i = k / cols
//	j = k % cols
int (*flat1Dto2D(int arr[], int size)) [3]{
	int r = 3, c = 3;
	static int arr1[3][3];
	for (int k = 0; k < r * c; k++) {
		int i = k / c;
		int	j = k % c;
		arr1[i][j] = arr[k];
	}
	return arr1;
}

int main() {
	int r = 3, c = 3;
	int array[9] = { 1,2,3,4,5,6,7,8,9 };
	int arr[3][3] = {
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};
	int uptri[4][4] = {
		{1,2,3,4},
		{0,5,6,7},
		{0,0,8,9},
		{0,0,0,10}
	};
	int lowtri[4][4] = {
		{1,0,0,0},
		{2,5,0,0},
		{3,6,8,0},
		{4,7,9,10}
	};
	cout << "\nOriginal 1d array:" << endl;
	for (int i = 0; i < 9; i++) {
		cout << array[i] << " ";
	}
	int (*TwoD)[3] = flat1Dto2D(array, 9);
	cout << "\nConverted 2D array:\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << TwoD[i][j] << " ";
		cout << endl;
	}
	cout << "Original 2d scalar array: " << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Indexes,ROW-Major: " << endl;
	int* flat = scalar(arr, r, c);
	cout << "\nConverted 1d scalar array,ROW-Major: " << endl;
	for (int i = 0; i < r; i++) {
		cout << flat[i] << " ";
	}
	cout << endl;
	cout << "Original 2d UP Triangular array: " << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << uptri[i][j] << " ";
		}
		cout << endl;
	}
	cout << "UpperTriangular: Indexes,ROW-Major: " << endl;
	int* flat2 = uppertriangular(uptri, 4, 4);
	cout << "\nConverted 1d up triangular array,ROW-Major: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << flat2[i] << " ";
	}
	cout << endl;
	
	cout << "Original 2d LOW Triangular array: " << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << lowtri[i][j] << " ";
		}
		cout << endl;
	}
	cout << "LowerTriangular: Indexes,ROW-Major: " << endl;
	int* flat3 = lowertriangular(lowtri, 4, 4);
	cout << "\nConverted 1d low triangular array,ROW-Major: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << flat3[i] << " ";
	}
	cout << endl;
	

	return 0;
}*/


//Vectors

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v1;		// empty vector
	vector<int> v2(5, 0);		// 5 elements initialized with 0
	vector<int> v3 = { 1,2,3,4 };	 // initializer list
	int n, val;
	cout << "How many numbers? ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Enter number at index " << i << " ";
		cin >> n;
		v1.push_back(val);	//insertion at end
	}
	cout << "Vector elements: ";
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;

	v1.insert(v1.begin() + 1, 100);
	v1.erase(v1.begin() + 2);
	v1.pop_back();
	cout << "Max element: " << *max_element(v1.begin(), v1.end()) << endl;
	cout << "Min element: " << *min_element(v1.begin(), v1.end()) << endl;
	sort(v1.begin(), v1.end());    // ascending
	sort(v1.rbegin(), v1.rend());  // descending
	auto it = find(v1.begin(), v1.end(), 100); // returns iterator
	if (it != v1.end()) {
		cout << "Found 100 at index: " << it - v1.begin() << endl;

	}
	else {
		cout << "100 not found" << endl;
	}
	cout << "Size: " << v1.size() << endl;
	cout << "Capacity: " << v1.capacity() << endl;

	v1.clear();
	cout << "After clear, size: " << v1.size() << endl;

	return 0;
}
*/

//LAB-3 (TEST CASES)
//Maximum Pairwise Product
/*#include<iostream>
#include<vector>
using namespace std;

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
//Naive - O(n^2)
long long maxprodNaive(const vector<int>& a) {
	long long best = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = i + 1; j < a.size(); j++) {
			long long prod = a[i] * a[j];
			if (prod > best) {
				best = prod;
			}
		}
	}
	return best;
}
//Sort-based - O(nlogn)
void bubbleSort(vector<int>& a) {
	int n = a.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				Swap(a[j], a[j + 1]);
			}
		}
	}
}
long long maxprodBubble(vector<int> a) {
	bubbleSort(a);
	int n = a.size();
	return a[n - 1] * a[n - 2];
}
//Fast O(n) — find largest & second largest
long long maxPairwiseProductFast(const vector<int>& a) {
	int max1 = 0;
	int max2 = 0;
	for (int i = 0; i < a.size(); i++) {
		if (max1 == 0 || a[i] > a[max1]) {
			max2 = max1;
			max1 = i;
		}
		else if (max2 == 0 || a[i] > a[max2]) {
			max2 = i;
		}
	}
	return a[max1] * a[max2];
}


int main() {
	vector<int> v = { 1, 10, 5, 2, 10 };

	cout << "Normal Case:\n";
	cout << "Naive: " << maxprodNaive(v) << endl;
	cout << "Sort : " << maxprodBubble(v) << endl;
	cout << "Fast : " << maxPairwiseProductFast(v) << endl;

	vector<int> best = { 5,5,5,5 };
	cout << "\nBest Case (all equal): "
		<< maxPairwiseProductFast(best) << endl;

	vector<int> worst = { 100,90,80,70 };
	cout << "\nWorst Case (descending): "
		<< maxPairwiseProductFast(worst) << endl;
}*/

//Euclidean GCD
/*#include<iostream>
#include<vector>
using namespace std;

//GCD Naive  O(min(a,b))
int GCDNaive(int a, int b) {
	int best = 1;
	int limit = (a < b ? a : b);
	for (int i = 0; i <= limit; i++) {
		best = i;
	}
	return best;
}
//GCD — Euclid O(log n)
int gcdEuclid(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcdEuclid(b, a % b);
}

int main() {
	vector<int> v = { 1, 10, 5, 2, 10 };

	cout << "\nGCD Tests:\n";
	cout << "Naive  gcd(120,140) = " << GCDNaive(120, 140) << endl;
	cout << "Euclid gcd(120,140) = " << gcdEuclid(120, 140) << endl;

	cout << "\nBest Case Euclid (a,0): "
		<< gcdEuclid(50, 0) << endl;

	cout << "Worst Case Euclid (Fib numbers): "
		<< gcdEuclid(144, 233) << endl;

	return 0;
}*/

