#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second



int main()
{
   int n;
   cin>>n;

   vector<int> a(n);
   for(int i=0;i<n;i++)
   {
      cin>>a[i];
   }

   priority_queue<int, vector<int>, greater<int>> Min_Heap;
   for(int i=0;i<n;i++)
   {
      Min_Heap.push(a[i]);
   }

   int ans = 0;

   while (Min_Heap.size() > 1)
   {
      int e1 = Min_Heap.top();
      Min_Heap.pop();
      int e2 = Min_Heap.top();
      Min_Heap.pop();

      ans += e1+e2;
      Min_Heap.push(e1 + e2);
   }
   cout<<ans<<endl;
   
   
   


   return 0;
}