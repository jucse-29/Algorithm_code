#include <bits/stdc++.h>
using namespace std;
int n, i, j, k;
int a1[1000], table[1000][10];

long long query(int L, int R)
{
    long long answer = 0;
    for (int j = k; j >= 0; j--)
    {
        if (L + (1 << j) - 1 <= R)
        {
            answer = answer + table[L][j];

            L += 1 << j;
        }
    }
    return answer;
}

void sparse_table()
{
    cin >> n;
    k = log2(n) + 1;
    for (i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (i = 0; i < n; i++)
    {
        table[i][0] = a1[i];
    }
    for (j = 1; j <= k; j++)
        for (i = 0; i <= n - (1 << j); i++)
            table[i][j] = table[i][j - 1] +
            table[i + (1 << (j - 1))][j - 1];

    cout << query(0, 2) << endl;
}
int main()
{
    sparse_table();
}
