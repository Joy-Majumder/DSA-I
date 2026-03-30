#include <iostream>
#include <utility>
using namespace std;

void BubbleSort(int arr[], int n) {
  // Bublle Sort time complexity is : 0(n^2)
  bool isSwapped = false;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        isSwapped = true;
      }
    }
    if (!isSwapped) { // array is already sorted
      break;
    }
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
  BubbleSort(arr, n);
  PrintArray(arr, n);
}
