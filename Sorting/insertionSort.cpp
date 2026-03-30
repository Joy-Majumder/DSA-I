#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n) {

  for (int i = 0; i < n; i++) {
    int CurrentValue = arr[i];
    int previous = i - 1;
    while (previous >= 0 && arr[previous] > CurrentValue) {
      arr[previous + 1] = arr[previous];
      previous--;
    }
    arr[previous + 1] =
        CurrentValue; // placing the current element in its correct position
  }
}

void PrintArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
    ;
  }
  // cout << endl;
}

int main() {
  int n = 5;
  int arr[] = {4, 2, 1, 7, 9};

  InsertionSort(arr, n);
  PrintArray(arr, n);
}
