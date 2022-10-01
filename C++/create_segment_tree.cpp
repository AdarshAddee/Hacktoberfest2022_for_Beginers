/*
segment tree
You have given an array A of n elements. Your task is to process q queries of the following types.
1 i x : Update the value at position i to x.
2 i j : Print the sum of values in the range [i, j].
*/

#include<bits/stdc++.h>
using namespace std;                                                                                                                                          
typedef long long int ll;                             //g++ ll.cpp -o ll.exe
typedef long double ld;  
typedef pair<ll,ll> iii;                              //all elements to 0
const ll mod =1e9+7;



struct node
{
  ll x;

};


vector<node> g;
vector<ll> ar;

node merge(node a,node b)
{
  node temp;
  temp.x=a.x+b.x;
  return temp;
}

void build(ll index,ll l,ll r)
{

  if(l==r)
  {
    node tt;
    tt.x=ar[l];
    g[index]=tt;
    return;
  }

  ll mid;
  mid=(l+r)/2;
  build(2*index,l,mid);
  build(2*index+1,mid+1,r);
  g[index]=merge(g[2*index],g[2*index+1]);
}

void update(ll index,ll l,ll r,ll pos,ll value)
{

  if((pos<l)|| (pos>r))
  return; 


  if(l==r)
  {
    //cout<<index<<endl;
    node tt;
    tt.x=value;
    g[index]=tt;
    ar[l]=value;
    return;
  }

  ll mid;
  mid=(l+r)/2;
  update(2*index,l,mid,pos,value);
  update(2*index+1,mid+1,r,pos,value);
  g[index]=merge(g[2*index],g[2*index+1]);


}


 node query(ll index,ll l,ll r,ll lq,ll rq)
 {
  node ans;
  ans.x=0;

  if(lq> r || rq<l)
    return ans;

  if(lq<=l && rq>=r)
    return(g[index]);

  ll mid=(l+r)/2;
  ans=merge(query(2*index,l,mid,lq,rq),query(2*index+1,mid+1,r,lq,rq));

  return(ans);



 }


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

  ll n,q;
  cin>>n>>q;

  g.resize(4*n+6);
  ar.resize(n+1);

  for(ll i=1;i<=n;i++)
    cin>>ar[i];

  build(1,1,n);

  while(q--)
  {
    ll t;
    cin>>t;
    if(t==1)
    {
      ll i,x;
      cin>>i>>x;
      update(1,1,n,i,x);
    }
    if(t==2)
    {
      ll lq,rq;
      cin>>lq>>rq;
      node temp;
      temp=query(1,1,n,lq,rq);
      cout<<temp.x<<endl;

    }
  }







    return 0;
}
