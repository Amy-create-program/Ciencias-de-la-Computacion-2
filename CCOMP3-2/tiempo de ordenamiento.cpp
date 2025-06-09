#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

struct Less {
	bool operator()(int a, int b) const {
		return a < b;
	}
};

struct Greater {
	inline bool operator()(int a, int b) const {
		return a > b;
	}
};

bool compareAsc(int a, int b) {
	return a < b;
}


template <typename Compare>
void merge(vector<int>& arr, int left, int mid, int right, Compare comp) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	vector<int> L(n1), R(n2);
	for(int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for(int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];
	
	int i = 0, j = 0, k = left;
	
	while (i < n1 && j < n2) {
		if (comp(L[i], R[j])) {
			arr[k++] = L[i++];
		} else {
			arr[k++] = R[j++];
		}
	}
	
	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];
}
	
template <typename Compare>
	void mergeSort(vector<int>& arr, int left, int right, Compare comp) {
		if (left >= right) return;
		
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid, comp);
		mergeSort(arr, mid + 1, right, comp);
		merge(arr, left, mid, right, comp);
	}
		
	void printVector(const vector<int>& arr) {
		for (int num : arr)
			cout << num << " ";
		cout << endl;
	}
		
	
int main() {
	srand(time(0));
			
	
	vector<int> original(1000);
		for (int& x : original)
			x = rand() % 10000;
			
	
	vector<int> arr1 = original;
	mergeSort(arr1, 0, arr1.size() - 1, Less());
	cout << "\nOrdenado ascendente (function object - Less):\n";
	printVector(arr1);
			
	vector<int> arr2 = original;
	mergeSort(arr2, 0, arr2.size() - 1, compareAsc);
	cout << "\nOrdenado ascendente (puntero a funci�n):\n";
	printVector(arr2);
			
			
	vector<int> arr3 = original;
	mergeSort(arr3, 0, arr3.size() - 1, Greater());
	cout << "\nOrdenado descendente (function object - Greater):\n";
	printVector(arr3);
			
			return 0;
		}
		
