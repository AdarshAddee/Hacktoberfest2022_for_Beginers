#include <iostream>
  using namespace std;

int binarySearch(int *arr, int left, int right, int x) {
  while (left <= right) {
    int mid = left + right / 2;

    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

int main() {
  int size,temp=0;
  cout<<"enter size"<<endl;
  cin>>size;
  int *myarr=new int[size];
  int num;
  int output;

  cout << "Please enter elements " << endl;
  for (int i = 0; i < size; i++) {
    cin >> myarr[i];
  }
  cout<<"sorting the array:"<<endl;
  for(int i=0;i<size;i++)
  {
    for(int j=i+1;j<size;j++)
    {
      if(myarr[i]>myarr[j])
      {
        temp=myarr[i];
        myarr[i]=myarr[j];
        myarr[j]=temp;
      }
    }
  }
  cout<<"SORTED ARRAY"<<endl;
   for (int i = 0; i < size; i++) {
    cout<<myarr[i]<<" ";
  }
  cout<<endl;
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
