#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  i, num, index=-1,n;

    cin>>n;
    int ar[n+10];
    for(i=0; i<n; i++)
        cin>>ar[i];
    cout<<"\nEnter a Number to Search: ";
    cin>>num;
    for(i=0; i<n; i++)
    {
        if(ar[i]==num)
        {
            index = i;
            break;
        }
    }

 if(index==-1){
        cout<<"NO"<<"\n";
    }
    else{
            cout<<"YES"<<"\n";
    cout<<"\nFound at Index No."<<index;
    cout<<endl;
    }
    return 0;
}




