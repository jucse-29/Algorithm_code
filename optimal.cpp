#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'

int main()
{
    //freopen("input optimal caching.txt","r",stdin);
    int m;
    cin>>m;
    string frame;
    cin>>frame;


    int n;
    cin>>n;
    string request;
    cin>>request;

    int hit=0;
    int miss=0;

    for(int i=0;i<n;i++)
    {
        bool flag=false;
        for(int j=0;j<m;j++)
        {
            if(frame[j]==request[i])
            {
                flag=true;
                break;
            }

        }
        if(flag)
        {
            hit++;
            cout<<"Hit"<<" ";
        }
        if(flag==false)
        {
            miss++;
            cout<<"Miss"<<" ";

            int idx=0;



           int mx_dist=0;
            for(int j=0;j<m;j++)
            {
                int dist=n+2;
                for(int k=i+1;k<n;k++)
                {
                    if(request[k]==frame[j])
                    {
                        dist=k;
                        break;
                    }
                }
                if(dist>mx_dist)
                {
                    idx=j;
                    mx_dist=dist;
                }
            }

            frame[idx]=request[i];

        }
        cout<<"  Frame: "<<frame<<N;
    }
    cout<<"Number of Hit: "<<hit<<" Number of Miss: "<<miss<<N;
    return 0;
}

