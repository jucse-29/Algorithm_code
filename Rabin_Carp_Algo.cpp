
#include<bits/stdc++.h>
using namespace std;
const long long q=INT_MAX;
#define d 256
vector<int>vc;
int cnt=0;
void Hash(string txt,string pat)
{
    int pl=pat.size();
    int tl=txt.size();
    int i,j;
    int p=0;
    int t=0;
    int h=1;
    for(i=0; i<pl-1; i++)
    {
        h=(h*d)%q;
    }
    for(i=0; i<pl; i++)
    {
        p=(d*p+pat[i])%q;
        t=(d*t+txt[i])%q;
    }
    for(i=0; i<=tl-pl; i++)
    {
        if(p==t)
        {
            for(j=0; j<pl; j++)
            {
                if(txt[i+j]!=pat[j])
                {
                    break;
                }
            }
            if(j==pl)
            {
                vc.push_back(i);
            }
        }
        if(i<tl-pl)
        {
            t=(d*(t-txt[i]*h)+txt[i+pl])%q;
            if(t<0)
            {
                t=t+q;
            }
        }

    }

}
int main()
{
    string pat,txt;
    cout<<"Enter the text:"<<endl;
    cin>>txt;
    cout<<"Enter the pattern:"<<endl;
    cin>>pat;
    Hash(txt,pat);
    cout<<"Number of occurance:"<<vc.size()<<endl;
    cout<<"Indexs are:";
    for(int i=0;i<vc.size();i++){
        cout<<vc[i]<<" ";
    }
    cout<<endl;
    return 0;

}
