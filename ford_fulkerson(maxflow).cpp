#include<bits/stdc++.h>
using namespace std;
#define MAX_NODE 1000
int nodes, edges;
int capacity[MAX_NODE][MAX_NODE];
int parent[MAX_NODE];
int color[MAX_NODE];
void init(int node)
{
    for(int i=0; i<=node; i++)
    {
        for(int j=0; j<=node; j++)
        {
            capacity[i][j]=0;
        }
    }
}
void inputGraph()
{
    int u,v,cap;
    cout<<"Enter vertex and edge number of the graph : "<<endl;
    cin>>nodes>>edges;
    init(nodes);
    for(int i=0; i<edges; i++)
    {
        cin>>u>>v>>cap;
        capacity[u][v]=cap;
    }
}
int dfs(int src, int sink)
{
    if(src == sink) return 1;
    color[src]=1;
    int res=0;
    for(int i=1; i<=nodes; i++)
    {
        if(capacity[src][i] && color[i]==0)
        {
            parent[i] = src;
            res|=dfs(i,sink);
        }
    }
    return res;
}
void initForDFS()
{
    for(int i=0; i<=nodes; i++)
    {        color[i] = 0;
        parent[i] = -1;
    }
}
void FordFullkerson(int source, int sink)
{
    int maxFlow = 0, bottleneck,x;
    initForDFS();
    while(dfs(source, sink))
    {
        bottleneck = INT_MAX;
        x = sink;
        while(x != source)
        {
            bottleneck = min(bottleneck, capacity[parent[x]][x]);
            x = parent[x];
        }
        x = sink;
        while(x != source)
        {
            capacity[parent[x]][x] -= bottleneck;
            capacity[x][parent[x]] += bottleneck;
            x = parent[x];
        }
        maxFlow += bottleneck;
        initForDFS();
    }
    cout<<"Max Flow by Ford Fullkerson = "<<maxFlow<<endl;
}
int main()
{
    int source, sink;
    inputGraph();
    cout<<"Enter source and sink point : "<<endl;
    cin>>source>>sink;
    FordFullkerson(source, sink);

    return 0;
}

