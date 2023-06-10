
#include <bits/stdc++.h>
using namespace std;
int vis[300005];
int tree[300005];
int level[300005];
int fat[300005];
int parent[30005][30];
vector<int> adj[30005];
int n, cnt;
void dfs(int node, int par, int idx)
{
    vis[node] = 1;
    level[node] = idx;
    fat[node] = par;
    for (auto x : adj[node])
    {
        if (vis[x] != 1)
        {
            dfs(x, node, idx+1);
        }
    }
    return;
}
void LCA()// store all parents using sparse table
{
    memset(parent, -1, sizeof(parent));
    for (int i = 0; i < n; i++)
    {
        parent[i][0] = fat[i];
    }
    for (int i = 1; (1 << i) < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = parent[j][i - 1];
            if (x >= 0)
            {
                parent[j][i] = parent[x][i - 1];
            }
        }
    }
}
int ans(int x, int y)
{
    cout << x << " has level " << level[x] << " and " << y << " has level " << level[y] << endl;
    if (level[x] < level[y])
    {
        swap(x, y);
    }
    int dif = level[x] - level[y];
    for (int i = 17; i >= 0; i--)
    {
        if (dif && (1 << i))
        {
            x = parent[x][i];
        }
    }
    if (x == y)
        return y;
    if (fat[x] == fat[y] && fat[x] != -1)
    {
        return fat[x];
    }
    int p = x, q = y;
    int val = log2(level[p]);
    for (int i = val; i >= 0; i--)
    {
        if (parent[p][i] != -1 && parent[p][i] != parent[q][i])
            p = parent[p][i];
        q = parent[q][i];
    }
    return fat[p];
}
int main()
{
    int n, m, i, j, k;
    cout<<"Enter the value of 'n':"<<endl;
    cin >> n;
    memset(vis, 0, sizeof(vis));
    for (i = 0; i <= n; i++)
    {
        adj[i].clear();
    }
    for (i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0, -1, 0);
    LCA();
    cout << "Enter the value of query:" << endl;
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int lca = ans(a, b);
        cout << "LCA of (" << a << ", " << b << ") = " << lca << endl;
    }
}
