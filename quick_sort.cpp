#include<bits/stdc++.h>
using namespace std;
int a[100];
int partion(int l,int r)
{
    int index=l;
    while(l!=r)
    {
        if(index==l)//right theke compare
        {
            if(a[index]<a[r])
            {
                r--;
            }
            else
            {
                swap(a[index],a[r]);
                index=r;
            }
        }
        else if(index==r)//left theke compre
        {
            if(a[l]<a[index])
            {
                l++;
            }
            else
            {
                swap(a[index],a[l]);
                index=l;
            }

        }
    }
    // pivot index e partion hobe
    //  then l=r=index
    return l;
}
void quicksort(int l,int r)
{
    if(l>=r){
        return ;
    }
    int mid=partion(l,r);
    quicksort(l,mid-1);
    quicksort(mid+1,r);


}
int main()
{
    int k,l,m,mid,pivot,n;
    cout<<"Enter the value of n:"<<endl;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    quicksort(0,n-1);
    for(int x=0;x<n;x++){
        cout<<a[x]<<" ";
    }
    cout<<endl;

}











