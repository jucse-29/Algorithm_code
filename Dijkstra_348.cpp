#include<bits/stdc++.h>
using namespace std;

const int inf= 1e9;
const int N= 1e5;
int main()
{
    int i,j,k,n,m;
    cin>>n>>m;
    vector<int>dis(n+1,inf);
    vector<vector<pair<int,int>>>graph(n+1);
    int u,v,w;
    for(i=0; i<n; i++)
    {
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    //as undirected
    int source;
    cin>>source;
    dis[source]=0;

    set<pair<int,int>>st;
    st.insert({0,source});//{w,vertex}
    while(!st.empty())
    {
        auto x =*st.begin();// most small element of set
        st.erase(x);
        for(auto it:graph[x.second])
        {
            if(dis[it.first]>dis[x.second]+it.second)
            {
                st.erase({dis[it.first],it.first});
                dis[it.first]=dis[x.second]+it.second;
                st.insert({dis[it.first],it.first});
            }
        }
    }
    for(i=1;i<=n;i++){
        if(dis[i]<inf){
            cout<<dis[i]<<" ";
        }
        else{
            cout<<"-1"<<" ";
        }
    }

}

