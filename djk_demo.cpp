#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const int inf=1e9;
vector<pair<int,int> >v[N];
int n;
void djkastra(int source){
vector<bool>vis(N,false);
vector<int>dist(N,inf);
multiset<pair<int,int>>st;
st.insert({0,source});
dist[source]=0;
while(!st.empty()){
pair x=*st.begin();
st.erase(st.begin());
int u=x.second;
if(vis[u]){
continue;
}
vis[u]=true;
for(pair y:v[u]){
int uu=y.first;
int wwt=y.second;
if(wwt+dist[u]<dist[uu]){
dist[uu]=wwt+dist[u];
st.insert({dist[uu],uu});
}
}
}
for(int i=0;i<n;i++){
cout<<i<<" : "<<dist[i]<<endl;
}
}
int main()
{
freopen("in.txt","r",stdin);
int a,b,c,e;cin>>n>>e;
for(int i=0;i<e;i++){
cin>>a>>b>>c;
v[a].push_back({b,c});
v[b].push_back({a,c});
}
cin>>a;
djkastra(a);
}
