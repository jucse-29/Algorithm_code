#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, i, j, l, m;
    cin >> n >> k;
    int ar[n + 10];
    for (i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int sum = 0;
    for (i = 0; i < k; i++)
    {
        sum += ar[i];
    } // prothom k sonkhok add kore nilam
    int ma = sum;
    for (j = k; j < n; j++)
    {
        sum = sum - ar[j - k] + ar[j]; // ek ghor samne agai jog korbo ar ek //ghor peconer value bad diye dibo
        ma = max(sum, ma);
    }
    cout << ma << endl;
}