#include <iostream>

using namespace std;

void Merge(int lo, int mid, int hi,int a[]){
    int i,j,k,b[hi+1];
    i = lo;
    j = mid+1;
    k=lo;
    while(i<=mid && j<=hi){
        if (a[i]<a[j]){
            b[k] = a[i];
            i++;
            k++;
        }
        else if (a[j]<a[i]){
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while(i<=mid){
        b[k] = a[i];
        i++;
        k++;
    }

    while(j<=hi){
        b[k] = a[j];
        j++;
        k++;
    }

    for(int x=lo;x<=hi;x++){
        a[x] = b[x];
    }
}

void MS(int a[],int lo,int hi){
    if (lo<hi){
        int mid = (lo + hi)/2;
        MS(a,lo,mid);
        MS(a,mid+1,hi);
        Merge(lo,mid,hi,a);
    }
}

int main(){
    int n;
    cout<<"Enter the length of array: ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    MS(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}