#include<bits/stdc++.h>
using namespace std;
int n;
struct suffix
{
    int idx;
    int rnk[2];
};
int cmp(struct suffix a,struct suffix b)
{

    return(a.rnk[0]==b.rnk[0])?
          (a.rnk[1]<b.rnk[1]?1:0):(a.rnk[0]<b.rnk[0]?1:0);
}
int *build(string tx,int n)
{
    struct suffix suf[n];
    int i,j,k;
    for(i=0; i<n; i++)
    {
        suf[i].idx=i;
        suf[i].rnk[0]=tx[i]-'a';
        suf[i].rnk[1]=((i+1)<n)? (tx[i+1]-'a'):-1;
    }
    sort(suf,suf+n,cmp);
    int ind[n];
    for(int k=4; k<2*n; k=k*2)
    {
        int rank=0;
        int prev_rnk=suf[0].rnk[0];
        suf[0].rnk[0]=rank;
        ind[suf[0].idx] = 0;
        for (int i = 1; i < n; i++)
        {

            if (suf[i].rnk[0] == prev_rnk &&
                    suf[i].rnk[1] == suf[i-1].rnk[1])
            {
                prev_rnk = suf[i].rnk[0];
                suf[i].rnk[0] = rank;
            }
            else
            {
                prev_rnk = suf[i].rnk[0];
                suf[i].rnk[0] = ++rank;
            }
            ind[suf[i].idx] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int nextindex = suf[i].idx + k/2;
            suf[i].rnk[1] = (nextindex < n)?
                            suf[ind[nextindex]].rnk[0]: -1;
        }

        sort(suf, suf+n, cmp);
    }
    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suf[i].idx;

    return  suffixArr;
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    string txt;
    cin>>txt;
    n=txt.size();
    int *sufarr=build(txt,n);
    cout<<"So the suffix array for this text is:"<<endl;
    print(sufarr,n);
}

