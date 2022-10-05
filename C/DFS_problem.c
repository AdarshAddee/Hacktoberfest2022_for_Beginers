// Author: Simran-Sahni
/*
DFS Application question
Find the node from which all can be visited
*/
#include <stdio.h>
#define N 500
int adj[N][N];
int n, m;
int vis[N];

int swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void reset(int vis[])
{
    for (int i = 0; i < n; i++)
        vis[i] = 0;
}

void dfs(int root, int state)
{
    if (vis[root] && state == n)
        return;

    vis[root] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[root][i] == 1 && vis[i] != 1)
        {
            dfs(i, state);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    // reset(vis,n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &u, &v);
        adj[--u][--v] = 1;
    }

    int ans[n];
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        reset(vis);
        dfs(i, 0);
        int y = 0;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == 1)
                y++;
        }

        if (y == n)
            ans[l++] = i + 1;
    }

    if (l == 0)
    {
        printf("BAD LUCK");
        return 0;
    }
    int minI;
    // sort the ans array
    for (int i = 0; i < l; i++)
    {
        minI = i;
        for (int j = i + 1; j < l; j++)
        {
            if (ans[minI] > ans[j])
                minI = j;
        }
        if (minI != i)
        {
            swap(&ans[i], &ans[minI]);
        }
    }
    for (int i = 0; i < l; ++i)
    {
        printf("%d ", ans[i]);
    }

    return 0;
}
