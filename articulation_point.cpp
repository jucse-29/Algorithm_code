#include<bits/stdc++.h>
using namespace std;
#define len 50005
int vis[len];
int arti[len];
int dis[len];
int low[len];
vector<int>G[len];
vector<pair<int,int> >bridge;
int cnt,timer;
void dfs(int x,int y)
{
    vis[x]=1;
    low[x]=dis[x]=timer++;//discover time
    for(int i=0; i<G[x].size(); i++)
    {
        if(G[x][i]==y)
        {
            continue;
        }
        else if(vis[G[x][i]])
        {
            low[x]=min(dis[G[x][i]],low[x]);
        }
        else
        {
            dfs(G[x][i],x);
            if(low[G[x][i]]>dis[x])
            {
                cnt++;
                if(G[x][i]>x)
                {
                    bridge.push_back(make_pair(x,G[x][i]));
                }
                else
                {
                    bridge.push_back(make_pair(G[x][i],x));
                }
            }
            low[x]=min(low[G[x][i]],low[x]);
        }
    }
}
int main()
{
    int t,i,j,k,node,n,u,e,v;
    char a,b,c;
    cin>>t;

    for(int ii=1; ii<=t; ii++)
    {
        cnt=0,timer=0;
        //number of node
        cin>>n;
        for(i=0; i<n; i++)
        {
            G[i].clear();
            vis[i]=0;
        }
        bridge.clear();
        for(j=0; j<n; j++)
        {
            cin>>u;

                cin>>v;
                G[u].push_back(v);
                G[v].push_back(u);

        }
        for(i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                dfs(i,-1);
            }
        }
        cout<<"Case "<<ii<<":"<<endl;
        cout<<cnt<<" Articulation Points"<<endl;
        sort(bridge.begin(), bridge.end());
       for(int i = 0; i <bridge.size(); i++)
       {
         cout << bridge[i].first << " - " << bridge[i].second << endl;
    }

    }
}

/*
1
6
0 1
1 2
2 3
2 4
4 5
*/


