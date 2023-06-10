#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll tree[800005];
ll a1[800005];
void build(ll node, ll l, ll r)
{
    if (l == r)
    {
        tree[node] = a1[l];
    }
    else
    {
        ll mid = l + (r - l) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
ll query(ll node, ll l, ll r, ll st, ll en)
{
    if (l > en || r < st)
    {
        return 0;
    }
    else if (l >= st && r <= en)
    {
        return tree[node];
    }
    else
    {
        ll mid = l + (r - l) / 2;
        ll x, y;
        x = query(node * 2, l, mid, st, en);
        y = query(node * 2 + 1, mid + 1, r, st, en);
        return x + y;
    }
}
int main()
{
    ll i, j, k, q;
    cin >> n >> q;
    for (i = 1; i <= n; i++)
    {
        cin >> a1[i];
    }
    build(1, 1, n);
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        cout << query(1, 1, n, x, y) << endl;
    }
}