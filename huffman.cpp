#include <bits/stdc++.h>
#define N '\n'
#define ll long long
using namespace std;
map<pair<int,string>,int>M;
pair<int,string>node[100];
vector<int>Graph[100];
priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>PQ;
void prt(int n,string code)
{
    if(Graph[n].size()>1)
    {
        prt(Graph[n][0],code+"0");
        prt(Graph[n][1],code+"1");

    }
    else
    {
        cout<<node[n].second<<": Length = "<<code.size()<<" Codeword = "<<code<<N;
    }
}
int main()
{
    cout<<"Enter total number of charater"<<N;
    ll num;
    cin>>num;
    cout<<"Enter the character and its frequency"<<N;
    ll cnt=0;
    for(ll i=0; i<num; i++)
    {
        string s;
        int k;
        cin>>s;
        cin>>k;
        pair<int,string> A=make_pair(k,s);
        M[A]=i+1;
        node[i+1]=A;
        PQ.push(A);
        cnt++;
    }

           while(PQ.size()>1)
    {
        pair<int,string>a,b,c;
        a=PQ.top();
        PQ.pop();
        b=PQ.top();
        PQ.pop();
        c.first=a.first+b.first;
        c.second=a.second+b.second;
        PQ.push(c);
        cnt++;
        M[c]=cnt;
        node[cnt]=c;
        int x,y,z;
        x=M[a];
        y=M[b];
        z=M[c];
        Graph[z].push_back(x);
        Graph[z].push_back(y);
    }
    int p=M[PQ.top()];
    prt(p,"");
}




