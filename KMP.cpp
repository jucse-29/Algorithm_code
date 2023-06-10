#include <bits/stdc++.h>
using namespace std;
void pi_table(string pat, int table[])
{
    int l, i = 1, j = 0;
    l = pat.size();
    table[0] = 0;
    while (i < l)
    {

        if (pat[i] == pat[j])
        {

            j++;
            table[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = table[j - 1];
            }
            else
            {
                table[i] = j;
                i++;
            }
        }
    }
}
int KMP(string txt, string pat)
{
    long long l1 = txt.size();
    long long l2 = pat.size();
    int ar[l2+5];

    pi_table(pat, ar); // pi table/Length of the previous longest create

    long long i = 0, j = 0, k, cnt = 0;
    while (i < l1)
    {
        if (txt[i] == pat[j])
        {
            i++, j++;
        }
        if (j == l2)
        {
            j = ar[j - 1];
            cnt++;
        }
        else if (i < l1 && txt[i] != pat[j])
        {
            if (j != 0)
            {
                j = ar[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return cnt;
}
int main()
{
    int t, p;
    cin >> t;
    for (p = 1; p <= t; p++)
    {
        string txt, pat;
        cin >> txt >> pat;
        int cnt;
        cnt = KMP(txt, pat);

        cout << "Case " << p << ": " << cnt << endl;
    }
}
