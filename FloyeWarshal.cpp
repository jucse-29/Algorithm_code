#include<bits/stdc++.h>
using namespace std;
const int N=501;
const int inf=1e5;

int main()
{
     int n,m,i,j,k,a,b,w;
 int dis[N][N];
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if(i==j)dis[i][j]=0;
            else dis[i][j]=inf;
        }
    }

    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>a>>b>>w;
        dis[a][b]=w;// x to y=w
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(dis[i][j]==inf){
                cout<<"I"<<" ";
            }
            else {
                cout<<dis[i][j]<<" ";
            }

        }
        cout<<endl;
    }

}
