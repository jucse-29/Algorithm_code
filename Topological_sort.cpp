#include<bits/stdc++.h>
const int N=1e5;
using namespace std;
vector<int>v[N];
map<int,bool>vis;
struct node{
    int v;
    int in;
};
void dfs(int s,stack<int>&stk){
    vis[s]=true;
    for(int i:v[s]){
   	 if(not vis[i])
   	 dfs(i,stk);
    }
    stk.push(s);
}
int main()
{
    int n;
    cout<<"Enter vertex: ";cin>>n;
    node nde[n];
    for(int i=0;i<n;i++){
   	 nde[i].v=i;
   	 nde[i].in=0;
    }
	int e;
    cout<<"Enter edges: ";cin>>e;
    for(int i=0;i<e;i++){
   	 int a,b;cin>>a>>b;
   	 v[a].push_back(b);
   	 nde[b].in++;
    }
    sort(nde,nde+n,[&](node aa,node bb){
   	 return aa.in<bb.in;
    });
    stack<int>stk;
    for(node aa: nde){
   	 if(!vis[aa.v]){
   		 dfs(aa.v,stk);
   	 }
    }
    vector<int>vv;
    cout<<"topological sorting is: ";
    while(stk.size()!=0){
   	 cout<<stk.top()<<" ";
   	 stk.pop();
    }
}




