#include<bits/stdc++.h>
using namespace std;
struct FN
{
    int value,waight;
    FN() {}
    FN(int V,int W)
    {
        value=V;
        waight=W;

    }
};
FN ar[100];
bool com(FN a,FN b)
{
    double r1 =(double)a.value/a.waight;
    double r2 =(double)b.value/b.waight;
    return r1>r2;

}


int main()
{
    int i,j,k;
    int n,N;
    cin>>N;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>ar[i].value>>ar[i].waight;
    }
    sort(ar,ar+n,com);

    int cuw=0;
    double tk = 0.0;
    for(i=0; i<n; i++)
    {
        if(cuw+ar[i].waight<=N) {
        cuw+=ar[i].waight;
        tk+=ar[i].value;
        }
        else{
          int rim = N-ar[i].waight;
          tk+=  ar[i].value*((double)rim/ar[i].waight);
          break;
        }
    }
    cout<<tk<<"\n";
}
