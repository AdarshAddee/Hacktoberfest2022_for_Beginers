#include <vector>
#include <iostream>
using namespace std;

bool isPossible(int arr[], int books, int student, int mid)
{
  int studentCount = 1;
  int pageSum = 0;
  // cout << "checking for mid "<< mid <<endl;

  for (int i = 0; i < books; i++)
  {
    if (pageSum + arr[i] <= mid)
    {
      pageSum += arr[i];
    }
    else
    {
      studentCount++;
      if (studentCount > student || arr[i] > mid)
      {
        return false;
      }
      pageSum = arr[i];
    }
    if (studentCount > student)
    {
      return false;
    }
  }
  return true;
}

int allocateBooks(int arr[], int books, int student)
{
  int s = 0;
  int sum = 0;

  for (int i = 0; i < books; i++)
  {
    sum += arr[i];
  }
  int e = sum;
  int ans = -1;
  int mid = s + (e - s) / 2;

  while (s <= e)
  {
    if (isPossible(arr, books, student, mid))
    {
      
      ans = mid;
      e = mid - 1;
    }
    else
    {
      s = mid + 1;
    }
    mid = s + (e - s) / 2;
  }
  return ans;
}

int main()
{
  int arr[4] = {10, 20, 30, 40};
  int student = 2;
  int  books = 4;
  cout << allocateBooks(arr, books, student);
}
