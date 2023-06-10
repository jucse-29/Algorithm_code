#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);

ll dp[1000][1000];

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	cout<<"Enter Number of Elements: ";
	cin>>n;

	ll w[n+10],p[n+10];
	cout<<"Enter The Weight and Profits"<<N;
	for(ll i=1;i<=n;i++)
	{
    	cin>>w[i]>>p[i];
	}

	cout<<"Enter The Size of the knapsack: ";



ll sz;
	cin>>sz;

	for(ll i=0;i<=n;i++)
	{
    	dp[i][0]=0;
	}
	for(ll i=0;i<=sz;i++)
	{
    	dp[0][i]=0;
	}


	for(ll i=1;i<=n;i++)
	{
    	for(ll j=1;j<=sz;j++)
    	{
        	if((j-w[i])>=0) dp[i][j]=max(dp[i-1][j],(p[i]+dp[i-1][j-w[i]]));
        	else dp[i][j]=dp[i-1][j];
    	}
	}
	cout<<dp[n][sz]<<N;


}



