#include <iostream>
#include <utility>
using namespace std;

void SelectionSort(int arr[], int n) {

  for (int i = 0; i < n - 1; i++) {
    int smallestIndex = i; // unsorted part starting
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[smallestIndex]) {
        smallestIndex = j;
      }
    }
    swap(arr[i], arr[smallestIndex]);
  }
}

void PrintArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int n = 5;
  int arr[] = {4, 1, 5, 2, 3};
  SelectionSort(arr, n);
  PrintArray(arr, n);
}
