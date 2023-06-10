#include<bits/stdc++.h>
using namespace std;
vector<int>v;
void partion( int ar[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int mid=(l+r)/2;
    partion(ar,l,mid);
    partion(ar,mid+1,r);
    int i=l,j=mid+1;
    v.clear();
    while(i<=mid||j<=r)
    {
        if(i<=mid&&j<=r)
        {
            if(ar[i]<ar[j])
            {
                v.push_back(ar[i]);
                i++;
            }
            else
            {
                v.push_back(ar[j]);
                j++;
            }
        }
        else if(i<=mid)
        {
            v.push_back(ar[i]);
            i++;
        }
        else
        {

            v.push_back(ar[j]);
            j++;
        }
    }
    for(i=0;i<v.size();i++){
        ar[i+l]=v[i];
    }
    v.clear();
}

int main()
{
    int i,j,k,l,n;
    cin>>n;
    int ar[n+10];
    for(i=0; i<n; i++)
    {
        cin>>ar[i];
    }
    partion(ar,0,n-1);
    for(i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}


