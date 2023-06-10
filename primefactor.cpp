
#include <bits/stdc++.h>
#define ll long long
#define MIN 1e7
#define YY cout << "YES" << '\n'
#define NN cout << "NO" << '\n'
#define Yy cout << "Yes" << '\n'
#define Nn cout << "No" << '\n'
#define yy cout << "yes" << '\n'
#define nn cout << "no" << '\n'
#define V vector<ll> v, v1, v2, v3;
#define Vs vector<char> vs1, vs2;
#define P pair<ll, ll> pa;
#define M map<ll, ll> mp, mp1;
#define MS map<string, ll> ms;
#define VP vector<pair<ll, ll>> vp;
#define N '\n'
long long n;
// s1.find(s2) != std::string::npos   "(vulo na amay please samia!!!)"
ll t;
const ll MAX = 10000005;
using namespace std;
void Sieve(ll n)
{

    V;
    for (ll i = 1; i <= n; i++)
    {
        v1[i] = 1;
    }
    ll i, j, k;

    for (int p = 2; p * p <= n; p++)
    {

        if (v[p] == 1)
        {

            for (int i = p * 2; i <= n; i += p)
                v[i] = 0;
        }
    }
}
void solve()
{

    ll a, b, c = 0, d, e, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, x1, x2, y1, y2, z1, z2, x, y, z, w;
    ll f = 0, cnt0 = 0, cnt = 0, cnt2 = 0, cnt3 = 0, sum1 = 0, sum2 = 0, mx = 0, mi = 1e9, ans = 1;
    string s1, s2, s3 = "";
    cin >> n;
    Sieve(n);
    V;
    // n er value er modde koto gula prime ache
    // factor of prime
    for (i = 0; i < v.size() && v[i] <= n; i++)
    {
        x = n;
        cnt = 0;
        while (x / v[i])
        {
            cnt = cnt + x / v[i];
            x = x / v[i];
        }
        printf("%d^%d\n", v[i], cnt);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        solve();
    }
}
