#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long n = 1000000;
ll a1[n + 10];
ll tree[n + 10];

// Find sum from [0,r] then subtract sum
// from [0,l-1] in order to find sum from
// [l,r]
int query(ll idx)
{
    ll sum = 0;
    while (idx > 0)
    {
        sum += tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}
void Update_and_build(ll idx, ll val, ll n) // tree construct o(nlog(n))
{
    while (idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
void Range_update(ll l, ll incre, ll n)
{
    while (l <= n)
    {
        tree[l] += incre;
        l += (l & -l);
    }
}

int main()
{
    long long i, j, k, m, n;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a1[i];
        Update_and_build(i, a1[i], n);
    }
    ll q, op, l, r;
    cout << "Enter the nummber of query:" << endl;
    cin >> q;
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {

            cin >> l >> r;
            ll ans = query(r) - query(l - 1); // 1base index
            cout << "Range sum: " << ans << endl;
        }
        else if (op == 2)
        {
            ll idx, val;
            cin >> idx >> val;                  // point update
            Update_and_build(idx, -a1[idx], n); // puropuri value bad dilam
            a1[idx] = val;
            Update_and_build(idx, val, n);
        }
        else
        {
            // range update  main previous value sathe new value add kore update
            ll l, r, incre;
            cin >> l >> r >> incre;
            Range_update(l, incre, n);
            Range_update(r + 1, -incre, n);
            Range_update(l, incre * (l - 1), n);
            Range_update(r + 1, -incre * r, n);
            
        }
    }
    return 0;
}
