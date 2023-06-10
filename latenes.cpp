#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Event
{
    int duration;
    int deadline;
    Event() {}
    Event(int _dur, int _dead)
    {

        duration = _dur;
        deadline =_dead;

    }
    void print()
    {
        printf("Duration = %d, Deadline=%d\n",duration,deadline);
    }

};
///a<b?
Event E[100];
bool com(Event a, Event b)
{
    if(a.deadline<b.deadline)
        return true;
    return false;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int N;
    scanf("%d",&N);
    for(int i=0; i<N; i++)
    {
        scanf("%d%d",&E[i].duration,&E[i].deadline);
    }
    for(int i=0; i<N; i++)
    {
        E[i].print();
    }

    sort(E,E+N,com);
    cout<<"After Sorting\n\n";
    for(int i=0; i<N; i++)
    {
        E[i].print();
    }
    int max_lateness=0;
    int time=0;
    int n;
    for(int i=0; i<n; i++)
    {
        time+=E[i].duration;

        int lateness=max(0,(time - E[i].deadline));

        max_lateness=max(lateness,max_lateness);
    }

    cout<<"Maximum Lateness is : "<<max_lateness<<N;
    return 0;
}







