/*
chiragchandnani10
https://github.com/chiragchandnani10
*/

#include<bits/stdc++.h>
using namespace std;
void merging(int input[],int start,int end){
    int mid = (start+end)/2;
    int i=start, j=mid+1, k=start;
    int ans[end+1];
    while(i<=mid&&j<=end){
        if(input[i]<input[j]){
            ans[k]=input[i];
            i++;
            k++;
        }
        else{
            ans[k]=input[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        ans[k]=input[i];
        i++;
        k++;
    }
    while(j<=end){
        ans[k]=input[j];
        j++;
        k++;
    }
    for(int s=start;s<=end;s++){
        input[s]=ans[s];
    }
}

void merge_sort(int input[],int start,int end){
    if(start>=end){
        return;
    }
    int mid = ((start+end)/2);
    merge_sort(input,start,mid);
    merge_sort(input,mid+1,end);
    merging(input,start,end);
    
    
}



void mergeSort(int input[], int size){
    // Write your code here
  
    merge_sort(input,0,size-1);
    
    
        
}

