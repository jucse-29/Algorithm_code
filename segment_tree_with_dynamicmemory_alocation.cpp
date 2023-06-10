

#include<bits/stdc++.h>
using namespace std;
int arr[]={4, 9, 2, 4, 2, 9, 3, 7, 8, 0, 5, 3, 9};
struct node
{
    int st,ed;
    int mn;
    bool lazy;
    int lv;
    node *l,*r;
    node(){}
    node(int _x, int _y){
        st=_x,ed=_y;l=r=NULL;
        lazy=false; lv=0; mn = 10000000; }
};
void build(node *ob )
{
    if(ob->st==ob->ed)
    {
        int ind = ob->st;
        ob->mn = arr[ind];
        return ;
    }
    int mid = (ob->st + ob->ed)/2;
    if(ob->l==NULL)ob->l = new node(ob->st, mid);
    if(ob->r==NULL)ob->r = new node (mid+1, ob->ed);
    build(ob->l);
    build(ob->r);
    ob->mn = min( ob->l->mn, ob->r->mn);
}
long long query(node *ob , int x , int y)
{
    if(ob->lazy)
    {
        ob->mn=ob->lv;
        if(ob->st!=ob->ed)
        {
            ob->l->lazy=true;
            ob->l->lv=ob->lv;
            ob->r->lazy=true;
            ob->r->lv=ob->lv;

        }
        ob->lazy=false;
    }
    if(ob->st==x && ob->ed==y)  return ob->mn;
    int mid = (ob->st + ob->ed)/2;

    if(y<=mid)  return query(ob->l,x,y);
    else if(x>mid) return query(ob->r,x,y);
    int a = query(ob->l, x, mid);
    int b = query(ob->r, mid+1, y);
    return min(a,b);
}
void update(node *ob , int x , int y,int val)
{
    if(ob->lazy)
    {
        ob->mn=ob->lv;
        if(ob->st!=ob->ed)
        {
            ob->l->lazy=true;
            ob->l->lv=ob->lv;
            ob->r->lazy=true;
            ob->r->lv=ob->lv;

        }
        ob->lazy=false;
    }
    if(x>ob->ed&&y<ob->st) return;
    if(x==ob->st&&y==ob->ed)
    {
        ob->mn=val;
        if(ob->st!=ob->ed)
        {
            ob->l->lazy=true;
            ob->l->lv=val;
            ob->r->lazy=true;
            ob->r->lv=val;
        }
        return;
    }
    int mid=(ob->st+ob->ed)/2;
    if(y<=mid) update(ob->l,x,y,val);
    else if(x>mid) update(ob->r,x,y,val);
    else
    {
        update(ob->l,x,mid,val);
        update(ob->r,mid+1,y,val);
    }
    ob->mn=min(ob->l->mn,ob->r->mn);
}
int main()
{
    int n = 13,l,r,val,q;
    node *root =new node(0,n-1);
    cout<<root->st<<endl;
    cout<<root->ed<<endl;

    build(root);
   
    cout<<"Number of Query : ";
    cin>>q;
    while(q--)
    {
        cout<<"For query t=1,and range update t=2"<<endl;
        cout<<"Input t = ";
        int t; cin>>t;
        if(t==1)
        {
            cin>>l>>r;
            int ans=query(root,l-1,r-1);
            cout<<"The minimum value of "<<l<<" to "<<r<<" = ";
            cout<<ans<<endl;
        }
        else if(t==2)
        {
            cin>>l>>r>>val;
            update(root,l-1,r-1,val);
            cout<<"After update new array is : "<<endl;
            for(int i=0;i<n;i++) cout<<query(root,i,i)<<" "; cout<<endl;
        }
    }

    return 0;
}


/*
    4 9 2 4 2 9 3 7 8 0 5 3 9
*/

