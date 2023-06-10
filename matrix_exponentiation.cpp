#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 10001;
void Mat_Multiply(ll a[2][2], ll b[2][2])
{
    ll matrix[2][2];
    for (ll i = 0; i < 2; i++)
    {
        for (ll j = 0; j < 2; j++)
        {
            matrix[i][j] = 0;
            for (ll k = 0; k < 2; k++)
            {
                matrix[i][j] += ((a[i][k] % MOD * b[k][j] % MOD) % MOD);
            }
        }
    }
    for (ll i = 0; i < 2; i++)
    {
        for (ll j = 0; j < 2; j++)
            a[i][j] = matrix[i][j] % MOD;
    }
}
ll Power(ll F[2][2], ll n)
{
    ll M[2][2] = {{1, 1}, {1, 0}};
    if (n == 1)
        return F[0][0] % MOD + F[0][1] % MOD;
    Power(F, n / 2);
    Mat_Multiply(F, F);
    if (n % 2)
        Mat_Multiply(F, M);

    return F[0][0] % MOD + F[0][1] % MOD;
}
ll fibo(ll n)
{
    ll F[2][2] = {{1, 1}, {1, 0}};//base
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    return Power(F, n - 2);
}
int main()
{
    ll n;
    cin >> n;
    ll ans = fibo(n);

    cout << ans << endl;
}
