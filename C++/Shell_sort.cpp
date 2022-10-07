#include <iostream>
using namespace std;

void shellSort(int array[], int n) {
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}
int main() {  
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n; 
    int a[n];
    cout<<"Enter the elements of an Array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    } 
    cout<<"Before sorting array elements are - \n";  
        for (int i = 0; i < n; i++){  
        cout<<a[i]<<" ";   
        }
    shellSort(a, n);  
    cout<<"\nAfter sorting array elements are - \n";    
        for (int i = 0; i < n; i++){
        cout<<a[i]<<" ";   
        }
    return 0;  
}  
