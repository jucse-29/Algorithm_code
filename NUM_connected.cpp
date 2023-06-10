#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
int c;
void dfs(int n)
{
    visited[n] = true;
    for (auto i : adj[n])
    {
        if (visited[i] == false)
        {
            dfs(i);
        }
    }
}

int main()
{
    c = 0;
    int ver, edg;
    cin >> ver >> edg;
    adj = vector<vector<int>>(ver);
    visited = vector<bool>(ver, false);
    for (int i = 0; i < edg; i++)
    {
        int m, n;
        cin >> m >> n;
        m--,n--;
        adj[m].push_back(n);
        adj[n].push_back(m);
    }
    for (int i = 0; i < ver; i++)
    {
        if (visited[i] == false)
        {
            c++;
            dfs(i);
        }
    }
    cout<< c << endl;
}