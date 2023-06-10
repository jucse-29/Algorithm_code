#include <bits/stdc++.h>
#define N '\n'
using namespace std;
struct Event
{
    int s,f;
    Event()
    {

    }
    Event(int t,int d)
    {
        t=s;
        d=f;
    }
};
Event event[100];
bool com(Event a,Event b)
{
    if(a.f<b.f)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    cout<<"Enter total task\n";
    cin>>n;
    cout<<"Enter their start and finish time\n";
    for(int i=0;i<n;i++)
    {
        cin>>event[i].s>>event[i].f;
    }
    vector<Event>act;
    for(int i=0;i<n;i++)
    {
        bool flag=true;
        for(int j=0;j<act.size();j++)
        {
            if(event[i].s>=act[j].f||act[j].s>=event[i].f)
            {

                continue;
            }
            else
            {
                flag=false;
                break;
            }
        }
        if(flag==true)
        {
            act.push_back(event[i]);
        }
    }
    cout<<"Number of activity selected : "<<act.size()<<N;
    cout<<"Selected activities are :\n";
    for( int i=0;i<act.size();i++)
    {
        cout<<act[i].s<<" "<<act[i].f<<N;
    }
}
