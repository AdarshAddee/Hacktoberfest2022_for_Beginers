#include<bits/stdc++.h>
using namespace std;

int part(int *a,int s,int e)
{
    int pivot = a[s];
    int c = 0;
    for(int i=s+1;i<=e;i++)
    {
        if(a[i]<pivot)
        {
            c++;
        }
    }
    int pi = s+c;
    swap(a[pi],a[s]);
    int i=s,j=e;
    while (i<pi && j>pi)
    {
        while (a[i]<=pivot)
        {
            i++;
        }
        while (a[j]>pivot)
        {
            j--;
        }
        if(i<pi && j>pi)
        {
            swap(a[i++],a[j--]);
        }

        
    }
    return pi;
    

}
void QS(int *a, int s, int e)
{
    if(s>=e)
    return;
    else
    {
        int p = part(a,s,e);
        QS(a,s,p-1);
        QS(a,p+1,e);
    }
}
int main()
{
    int a[5] = {2,4,1,6,9};
    int n = 5;
    QS(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}