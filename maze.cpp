#include <iostream>
#include <fstream>

using namespace std;

int n,m,li,ci,lf,cf,v[11][11],t=0;
struct solutie{int l,c,d;};
solutie s[101];

ifstream f("soarece1.in");
ofstream g("soarece1.out");

void initializare(int k)
{
    s[k-1].d=0;
}

int succesor(int k)
{
    s[k-1].d++;
    if(s[k-1].d<=4)
        return 1;
    else
        return 0;
}

int valid(int k)
{
    int lc,cc,dl[]={-1,0,1,0},dc[]={0,1,0,-1},i;
    lc=s[k-1].l+dl[s[k-1].d-1];
    cc=s[k-1].c+dc[s[k-1].d-1];
    if(lc>n || lc<1 || cc>m || cc<1)
        return 0;
    if(v[lc][cc]==1)
        return 0;
    for(i=1;i<k;i++)
    {
        if(s[i].l==lc && s[i].c==cc)
            return 0;
    }
    s[k].l=lc;
    s[k].c=cc;
    return 1;
}

int solutie(int k)
{
    if(s[k].l==lf && s[k].c==cf)
        return 1;
    else
        return 0;
}

void tiparire(int k)
{
    int i,j,l,ok;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            ok=0;
            for(l=1;l<=k;l++)
            {
                if(i==s[l].l && j==s[l].c)
                    ok=l;
            }
            if(ok!=0)
                g<<ok<<" ";
            else
                g<<0<<" ";
        }
        g<<'\n';
    }
}

void back(int k)
{
    int ok1,ok2;
    initializare(k);
    while(k>0)
    {
        do
        {
            ok1=succesor(k);
            ok2=valid(k);
        }while(ok1 && !ok2);

        if(ok1)
        {
            if(solutie(k))
            {
                tiparire(k);
                k=0;
                t=1;
            }
            else
            {
                k++;
                initializare(k);
            }
        }
        else
            k--;
        }

}

int main()
{
    int i,j;
    char a;
    f>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            f>>a;
            if(a=='_')
                v[i][j]=0;
            else
            if(a=='#')
                v[i][j]=1;
            else
            if(a=='S')
            {
                li=i;
                ci=j;
            }
            else
            {
                lf=i;
                cf=j;
            }
        }
    s[1].l=li;
    s[1].c=ci;
    back(2);
    if(t==0)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                g<<0<<" ";
            g<<'\n';
        }
    }
    return 0;
}
