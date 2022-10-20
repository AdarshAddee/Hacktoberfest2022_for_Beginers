#include <iostream>

using namespace std;

int binarySearch(int arr[], int siz, int key)
{
    int start = 0;
    int ending = siz - 1;
    //int mid = (start + ending)/2;
    int mid = start +(ending - start)/2;

    while(start <= ending)
    {
        if (arr[mid] == key)
            return mid;
        if (key > arr[mid])
            start = mid + 1;
        else
            ending = mid - 1;

        //mid = (start + ending)/2;
        mid = start + (ending - start)/2;
    }
    return -1;
}

int main()
{
    int even[6] = {1,3,4,5,6,8};
    int odd[5] = {4,5,6,7,8};

    int evenIndex = binarySearch(even, 6, 6);
    cout << "Index of 6 is: " << evenIndex <<endl;

    int OddIndex = binarySearch(odd, 5, 4);
    cout << "Index of 4 in odd is: " <<OddIndex << endl;


}
