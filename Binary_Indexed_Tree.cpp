#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long n;
int BIT[1000],BIT1[1000], a[1000];
void update(int x, int delta)
{
    for (; x <= n; x += x & -x)
        BIT[x] += delta;
}
int query(int x)
{
    int sum = 0;
    for (; x > 0; x -= x & -x)
        sum += BIT[x];
    return sum;
}

int main()
{
    cin >> n;

    int i, l, r;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    int q;
    cout << "Enter the number of query:" << endl;
    cin >> q;
    while (q--)
    {
        cout << "Enter your choice:" << endl;
        char ch;
        cin >> ch;
        if (ch == '1') // query
        {
            cout << "For query enter your range:";
            cin >> l >> r;
            cout << "sum=" << query(r) - query(l - 1) << endl;
        }
        else if (ch == '2') // point update
        {
            int indx, val;
            cout << "enter your index and value:" << endl;
            cin >> indx >> val;
            update(indx, -a[indx]);
            update(indx, val);
        }
       
    }
    return 0;
}
