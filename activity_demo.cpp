#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
struct Event
{
    int start;
    int finish;
    Event(){}
    Event(int t,int d)
    {
        start=t;
        finish=d;
    }

    void print()
    {
        printf("start = %d, finish = %d\n",start,finish);

    }
};
Event event[1000];
bool com(Event a,Event b)
{
    if(a.finish<b.finish)
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
    //freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
       cout<<"Number of Selected Activity: "<<selected_activity.size()<<N;
    cout<<"Selected Activities are: "<<N;
    for(int i=0;i<selected_activity.size();i++)
    {
        cout<<selected_activity[i].start<<" "<<selected_activity[i].finish<<N;
    }
    return 0;
}


 {
        cin>>event[i].start>>event[i].finish;
    }

    cout<<"Before Sorting: "<<N;

    for(int i=0;i<n;i++)
    {
        event[i].print();
    }

    sort(event,event+n,com);

    cout<<"After Sorting: "<<N;

    for(int i=0;i<n;i++)
    {
        event[i].print();
    }

    vector<Event>selected_activity;

    for(int i=0;i<n;i++)
    {
        bool flag=true;
        for(int j=0;j<selected_activity.size();j++)
        {
            if(event[i].start>=selected_activity[j].finish||selected_activity[j].start>=event[i].finish)
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
            selected_activity.push_back(event[i]);
        }
    }



