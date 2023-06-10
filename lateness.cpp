#include<bits/stdc++.h>
using namespace std;
struct event
{
    int t,d;
    event() {}
    event(int _t, int _d)
    {
        t= _t;
        d= _d;
    }
    void print()
    {
        printf("Duration = %d  Deadline = %d\n",t,d);
    }
};
bool com(event a, event b)
{
    if(a.d<b.d)
        return true;
    else
        return false;
}
int main()
{
    int t,d;
    event p[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>p[i].t>>p[i].d;
    }
    sort(p,p+n,com);

    int time=0,cnt=0,mi=0;
    for(int i=0; i<n; i++)
    {
        time+=p[i].t;
        int late=time-p[i].d;
        if(late>0)
            mi=max(mi,late);
    }
    cout<<"Maximum lateness is "<<mi<<"\n";

    return 0;
}

