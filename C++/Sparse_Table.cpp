#include<bits/stdc++.h>

#define ll long long int
#define pi 3.1415926535897932385
#define mod 1000000007
#define db double
#define pp(x) pair<x,x>
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define tc ll tc; cin>>tc; for(ll number = 1 ; number <= tc ; number ++ )
#define vv(x) vector<x >
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof  pop_front
#define endl "\n"
#define umap unordered_map
#define mp make_pair 
#define pq priority_queue
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define bp ll kkk; cin >>kkk;
#define dbgArr(a,n) cout<<"Array "<<#a<<endl; for(ll i=0 ; i<n ; i++) cout<<a[i]<<" "; cout<<endl;
#define forn(i,n) for(ll i=0 ; i<n ; i++)
#define forn1(i,n) for(ll i=1 ; i<=n ; i++)
#define arr(a,n) for(ll i=0;i<n;i++){ cin>>a[i]; }
#define arr1(a,n) for(ll i=1;i<=n;i++){ cin>>a[i]; }
#define file freopen("inp.in","r",stdin); freopen("outp.out","w",stdout)
#define print cout<<"Case #"<<number<<": "
#define all(x) x.begin(), x.end()
#define trav(x, a) for(auto &x: a)
ll power(ll x, ll b) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= mod;} b >>= 1; x *= x; x %= mod;} return p % mod;}

using namespace std;

struct sparse_table
{
    vv(vv(int)) mat ;
    vv(int) p2 ;
    int n,m ;
    
    void init(int _n , int _m)
    {
        n=_n ; m=_m ;
        mat.resize(n); p2.resize(n);
        forn(i,n) mat[i].resize(m);
        forn1(i,n) p2[i]=p2[i/2]+1 ;
    }

    void build(int a[])
    {
        forn(i,n) mat[i][0]=a[i] ;
        forn(j,m)
        {
            for(ll i=0 ; i+(1<<j) <= n ; i++)
            {
                mat[i][j]=min(mat[i][j-1],mat[i+(1<<(j-1))][j-1]); // can use + for range sum query
            }
        }
    }

    int query(int l , int r)
    {
        int pw=p2[r-l];
        return min(mat[l][pw],mat[r-(1<<pw)+1][pw]);
    }

};

int main()
{
    FIO
    return 0 ;
}
