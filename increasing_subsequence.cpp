

#include<bits/stdc++.h>
using namespace std;
char s1[20],s2[20], b[20][20];
int a[20][20],m,n;
void print(int x,int y)
{
    if(x==0||y==0)
    {
        return;
    }
    if(b[x][y]=='c')
    {
        print(x-1,y-1);
        printf("%c",s1[x-1]);
    }
    else if(b[x][y]=='u')
    {
        print(x-1,y);
    }
    else
    {
        print(x,y-1);
    }
}
void LCS()
{
    n=strlen(s1);
    m=strlen(s2);
    for( int i=0; i<=n; i++)
    {
        a[i][0]=0;//col borabor sob 0
    }
    for(int i=0; i<=m; i++)
    {
        a[0][i]=0;//row borabor sob 0
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                a[i][j]=a[i-1][j-1]+1;
                b[i][j]='c';
            }
            else if(a[i-1][j]>=a[i][j-1])
            {
                a[i][j]=a[i-1][j];
                b[i][j]='u';
            }
            else
            {
                a[i][j]=a[i][j-1];
                b[i][j]='l';
            }
        }
    }
}
int main()
{
    cout<<"Enter The first String:"<<endl;
    scanf("%s",s1);
    cout<<"Enter the string:"<<endl;
    scanf("%s",s2);
    LCS();
    cout<<"The LIS is:";
    print(m,n);

}
