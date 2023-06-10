#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e5;
vector<int>v[N];
void bfs(int s,int n){
	vector<bool>vis(n,false);
	queue<int>q;
	vis[s]=true;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		vis[u]=true;
		cout<<u<<" ";
		q.pop();
		for(int i:v[u]){
			if(not vis[i]){
				q.push(i);
			}
		}
	}
	cout<<endl;
}




int main()
{
    cout<<"Enter the value of n,e"<<endl;
	int a,b,n,e;cin>>n>>e;
	for(int i=0;i<e;i++){
		cin>>a>>b;
		v[a].pb(b);
	}
	int s;cin>>s;
	bfs(s,n);
}



