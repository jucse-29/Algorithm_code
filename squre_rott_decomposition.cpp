// Note:Time complexity=Osqrt(n)
// application:Range sum and point update

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a1[800005];
ll sum[800005];
ll block[80005];
ll BS;
void build(ll n)
{
    ll idx = -1;
    BS = sqrt(n);
    // create a decomposed array
    for (int i = 0; i < n; i++)
    {
        sum[i] = a1[i];
        if (i % BS == 0)
        {
            idx++;
        }
        block[idx] += sum[i];
    }
}
void point_update(ll idx, ll v)
{
    ll block_num = idx / BS;
    block[block_num] += v - sum[idx];
    sum[idx] = v;
}
ll query(ll l, ll r)
{
    ll Sum = 0;
    // traversing first block in range
    while (l < r && l % BS != 0 && l != 0)
    {
        Sum += sum[l];
    }
    // travesing completely overlaped block
    while (l + BS - 1 <= r)
    {
        Sum += block[l / BS];
        l += BS;
    }
    // traversing last block
    while (l <= r)
    {
        Sum += sum[l];
        l++;
    }
    return Sum;
}
int main()
{
    ll n, i, j, k, q;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    build(n);
    cin >> q;
    while (q--)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            ll l, r;
            cin >> l >> r;

            cout << query(l - 1, r - 1) << endl;
        }
        else
        {
            ll idx, v;
            cin >> idx >> v;
            point_update(idx, v);
        }
    }
}