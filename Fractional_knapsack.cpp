 #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
struct Item
{
    int item_number;
    int Weight;
    int Benefit;
    int Benefit_per_unit;
    Item(){}
    Item(int w,int b,int bpu)
    {
        Weight=w;
        Benefit=b;
        Benefit_per_unit=bpu;
    }

    void print()
    {
        cout<<"Item: "<<item_number<<", Weight = "<<Weight<<", Benefit = "<<Benefit<<", Benefit Per Unit = "<<Benefit_per_unit<<N;

    }
};
Item item[1000];
bool com(Item a,Item b)
{
    if(a.Benefit_per_unit>b.Benefit_per_unit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;


        for(int i=0;i<n;i++)
    {
        item[i].item_number=i+1;
        cin>>item[i].Weight>>item[i].Benefit>>item[i].Benefit_per_unit;
    }
    int W;
    cout<<"enter the value of Waight"<<endl;
    cin>>W;
    cout<<"Before Sorting: "<<N;

    for(int i=0;i<n;i++)
    {
        item[i].print();
    }

    sort(item,item+n,com);

    cout<<"After Sorting: "<<N;

    for(int i=0;i<n;i++)
    {
        item[i].print();
    }

    int w=0.0;
    int idx=0;
    int profit=0.0;
    while(w<W)
    {
        int x=min(item[idx].Weight,W-w);
        w+=x;
        cout<<x<<" Unit of "<<item[idx].item_number<<" profit = "<<item[idx].Benefit_per_unit*x<<N;
        profit+=item[idx].Benefit_per_unit*x;

        idx++;
    }

    cout<<"Total Profit: "<<profit<<N;
    return 0;
}

