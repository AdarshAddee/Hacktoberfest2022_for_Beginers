#include<iostream>
#include<vector>

using namespace std;

void SubSeq(int i,int sz,vector <int> v, int Arr[],int key=4)
{
    int sum=0;
    for(auto it : v)
        sum+=it;
    if(sum==key)
    {
        for(auto i : v)
            cout<<i<<" ";
        cout<<":\n";
        return;
    }
    else if(i>=sz)
    {
        return;
    }
    v.push_back(Arr[i]);
    SubSeq(i+1,sz,v,Arr,key);
    v.pop_back();
    SubSeq(i+1,sz,v,Arr,key);
    return;
}
int main()
{
    int n;
    cout<<"Enter the size of the array\t";
    cin>>n;
    int Arr[n];
    cout<<"Enter the elements of the Array\t";
    for(int i=0;i<n;i++)
        cin>>Arr[i];
    cout<<"Enter the Sum for the subsequence to be printed\t";
    cin>>n;
    vector<int> v;
    SubSeq(0,sizeof(Arr)/sizeof(Arr[0]),v,Arr,n);
    return 0;
}
