#include <iostream>
  using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    // Found in this index : exit (return)
    if (arr[mid] == x) {
      return mid;
    } 
    // searching index is higher than current check
    else if (arr[mid] < x) {
      left = mid + 1;
    } 
    // searching index is lesser than current check
    else {
      right = mid - 1;
    }
  }
  // left index > right mean not found in arr[]
  return -1;
}

int main() {
  int myarr[10];
  int num;
  int output;

  cout << "Please enter 10 elements ASCENDING order" << endl;
  for (int i = 0; i < 10; i++) {
    cin >> myarr[i];
  }
  cout << "Please enter an element to search" << endl;
  cin >> num;

  output = binarySearch(myarr, 0, 9, num);

  if (output == -1) {
    cout << "No Match Found" << endl;
  } else {
    cout << "Match found at position: " << output << endl;
  }

  return 0;
}
