/*
Code : Linear Search
Author : Prathamesh Patil
*/

# include <iostream>

using namespace std;

int main()
{
        // gettting the size for the array
        int n;
        cout << "Enter the size of array : ";
        cin >> n;

        // declaration of the array
        int arr[n];

        // taking the input for array elements
        for(int i = 0; i < n; i++)
        {
                cin >> arr[i];
        }

        // linear search logic

        int search_element, flag = 1;

        // input the element to search in the array
        cout << "Enter the element to search in the array : ";
        cin >> search_element;

        for(int i = 0; i < n; i++)
        {
                if(arr[i] == search_element)
                {
                        cout << "Element " << search_element << " found at the position : " << i << endl;
                        flag = 0;               // set the flag bit to 0
                        break;
                }
        }

        // if flag bit reamins 1 then we haven't found the element in the array 
        if(flag == 1)
        {
                cout << "Entered element is not present in the array...!!" << endl;        
        }
}
