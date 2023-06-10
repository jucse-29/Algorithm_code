#include <bits/stdc++.h>
using namespace std;
int parent[1000];
int size_dsu[1000];

void make_set(int v)
{
    parent[v] = v;
    size_dsu[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])

        return v;
    return parent[v] = find_set(parent[v]);
}
void Union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        // rank
        if (size_dsu[a] < size_dsu[b])
        {
            swap(a, b); // as b is assume as small
        }
        parent[b] = a; // chotottar parents borota banai dibo
        size_dsu[b] += size_dsu[a];
    }
}
int main()
{
    int n, k, i, j, u, v;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
    {
        make_set(i);
    }

    while (k--)
    {
        cin >> u >> v;
        Union_set(u, v);
    }
    int cnt = 0;
    for (i = 1; i <= n; i++)
    {
        if (find_set(i) == i)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
