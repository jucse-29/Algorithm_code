
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, m, i, j, k, t, s, q;

    cin >> t;
    for (s = 1; s <= t; s++)
    {
        cout << "Enter the value of 'n':" << endl;
        cin >> n;
        ll ar[n + 10];
        ll p = log2(n) + 1;
        ll Sp[p + 2][n + 2];
        for (i = 0; i < n; i++) // 1 len er jonno store
        {
            cin >> ar[i];
            Sp[0][i] = ar[i];
        }
        // store the element

        for (i = 1; i < 18; i++)
        {
            for (j = 0; j + (1 << i) - 1 < n; j++)
            {
                Sp[i][j] = min(Sp[i - 1][j], Sp[i - 1][j + (1 << (i - 1))]);
            }
        }
        // Query
        
        cout << "Enter the value of query:" << endl;
        cin >> q;
        while (q--)
        {
            ll a, b;
            cin >> a >> b;
            a--, b--;
            ll len = b - a + 1;
            ll x = log2(len);
            ll mi = min(Sp[x][a], Sp[x][b - (1 << x) + 1]);

            cout << mi << endl;
        }
    }
}
