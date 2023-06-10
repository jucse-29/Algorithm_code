#include<bits/stdc++.h>
using namespace std;
int ar[1000];
partion(int l,int r)
{
    int index=l;
    while(l!=r)
    {
        if(index==l)
        {
            if(ar[index]<ar[r])
            {
                r--;
            }
            else{
                swap(ar[index],ar[r]);
                index=r;
            }
        }
        else if(index==r){
            if(ar[index]>ar[l]){
               l++;
            }
            else{
                swap(ar[index],ar[l]);
                index=l;
            }
        }
    }
    return l;
}
void quicksort(int l,int r)
{
    if(l==r)return;
    int mid=partion(l,r);
    partion(l,mid-1);
    partion(mid+1,r);
}
int main()
{
    int i,j,k,n;
    cin>>n;

    for(i=0; i<n; i++)
    {
        cin>>ar[i];
    }
    quicksort(0,n-1);

    for(j=0;j<n;j++){
        cout<<ar[j]<<" ";
    }

}
