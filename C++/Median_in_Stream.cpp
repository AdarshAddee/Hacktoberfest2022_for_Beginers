Question: Given that integers are read from a data stream. Your task is to find the median of the elements read so far.
I solve this question using max and min heap


#include<bits/stdc++.h>
#include<queue>
vector<int> findMedian(vector<int> &arr, int n){
	priority_queue<int, vector<int>, greater<int>>min;
    priority_queue<int>max;
    vector<int> ans;
    for(int i = 0; i<n; i++){
        if(i%2==0){
            min.push(arr[i]);
            max.push(min.top());
            min.pop();
            ans.push_back(max.top());
        }
        else{
            max.push(arr[i]);
            min.push(max.top());
            max.pop();
            int num = (max.top() + min.top())/2;
            ans.push_back(num);
        }
    }
    return ans;
	
}
