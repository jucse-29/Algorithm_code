#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a1[800005];
ll tree[800005];
ll lazy1[800005];
ll lazy2[800005];
void build(ll node, ll l, ll r)
{
    if (l == r)
    {
        tree[node] = a1[l];
    }
    else
    {
        ll mid = l+(r-l) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void lazy_check(ll node, ll rng)
{
    if (lazy2[node] > 0)
    {
        tree[node] = lazy2[node] * rng;

        if (rng > 1)
        {
            lazy1[node * 2 + 1] = 0;
            lazy1[node * 2] = 0;
            lazy2[node * 2 + 1] = lazy2[node];
            lazy2[node * 2] = lazy2[node];
        }
    }
    if (lazy1[node] > 0)
    {
        tree[node] += lazy1[node] * rng;
        if (rng > 1)
        {
            lazy1[node * 2 + 1] += lazy1[node];
            lazy1[node * 2] += lazy1[node];
        }
    }
    lazy1[node] = 0;
    lazy2[node] = 0;
}

ll query(ll node, ll l, ll r, ll st, ll en)
{
    lazy_check(node, r - l + 1);
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
        ll mid = l+( r-l) / 2;
        ll x, y;
        x = query(node * 2, l, mid, st, en);
        y = query(node * 2 + 1, mid + 1, r, st, en);
        return x + y;
    }
}
void update_add(ll node, ll l, ll r, ll st, ll en, ll v)
{
    lazy_check(node, r - l + 1);
    if (l > en || r < st)
    {

        return;
    }
    else if (l >= st && r <= en)
    {
        tree[node] += (r - l + 1) * v;
        if ((r - l + 1) > 1)
        {
            lazy1[node * 2] += v;
            lazy1[node * 2 + 1] += v;
        }
        return;
    }
    else
    {
        ll mid = l+(r-l) / 2;
        update_add(node * 2, l, mid, st, en, v);
        update_add(node * 2 + 1, mid + 1, r, st, en, v);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
void update_new(ll node, ll l, ll r, ll st, ll en, ll v)
{
    lazy_check(node, r - l + 1);
    if (l > en || r < st)
    {

        return;
    }
    else if (l >= st && r <= en)
    {
        tree[node] = (r - l + 1) * v;
        if ((r - l + 1) > 1)
        {
            lazy1[node * 2]=0;
            lazy1[node * 2 + 1] =0;
            lazy2[node*2]=v;
            lazy2[node*2+1]=v;
        }
        return;
    }
    else
    {
        ll mid = l+(r-l) / 2;
        update_new(node * 2, l, mid, st, en, v);
        update_new(node * 2 + 1, mid + 1, r, st, en, v);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long n, q, i, j, k;
    cin >> n >> q;
    for (i = 1; i <= n; i++)
    {
        cin >> a1[i];
    }
    build(1, 1, n);
    while (q--)
    {
        ll ch=0;
        cin >> ch;
        if (ch == 3) // range query
        {
            ll x, y;
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << "\n";
        }
        else if (ch == 1)//update by adding
        {
            ll x, y, val;
            cin >> x >> y >> val;
            update_add(1, 1, n, x, y, val);
        }
        else if(ch==2) // update by new value
        {
            ll x,y,v;
            cin>>x>>y>>v;
            update_new(1,1,n,x,y,v);

        }
    }
}
