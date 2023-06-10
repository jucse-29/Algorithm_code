#include <bits/stdc++.h>
using namespace std;
vector<int>G[10];
bool vis[10];
void dfs(int x)
{
    vis[x] = 1;
    for (int i = 0; i < G[x].size(); i++)
    {
        int next = G[x][i];
        if (vis[next] == 0)
        {
            dfs(next);
        }
    }
}
int main()
{
    int a[10];
    int e, node, i, j, k, u, v;
    cin >> node >> e;
    for (i = 0; i < e; i++)
    {
        cin >> u >> v;

        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0);
    for (j = 0; j < node; j++)
    {
        if (vis[j] == 1)
        {
            cout << "wow" << endl;
        }
        else
        {
            cout << "shit" << endl;
        }
    }
}
