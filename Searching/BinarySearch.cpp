#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
  int start = 0;
  int end = size - 1;
  int mid = (start + end) / 2;

  while (start <= end) {
    if (arr[mid] == key) {
      return mid;
    }
    // here we have to see that if want to go right side of an array then we
    // should use this formula : right > starting index = mid index + 1; left >
    // ending index = mid index - 1; here bellow shown this :
    //
    if (key > arr[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    mid = (start + end) / 2;
  }

  return -1; // here -1 means that it isnt found(Not found);
}

int main() {
  int even[6] = {2, 4, 6, 8, 12, 18};
  int odd[5] = {3, 8, 11, 14, 16};
  int index = binarySearch(even, 6, 12); // we can see that array is Even named
                                         // and 6 is its size and 12 is the key
  cout << "Index of 12 is : " << index << endl;
}
