#include <bits/stdc++.h>
using namespace std;
int ar[] = {3, 34, 4, 12, 5, 2};
int cnt = 0;
int sum = 12;
int subsetsum(int n1, int sum1)
{
    while (n1)
    {
        if (n1 == 0 && sum1 == 0)
        {
            return cnt;
        }
        if (sum1 == 0 && n1 != 0)
        {
          return  cnt++;
            
        }
        else
        {

            return subsetsum(n1 - 1, sum1) || (subsetsum(n1 - 1, sum1 - ar[n1 - 1]))&&cnt;
        }
    }
}

int main()
{
    int i, j, k, l, n = 6;
  
        cout << subsetsum(n, sum) << endl;
    
}
