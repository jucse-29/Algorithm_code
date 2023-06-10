#include<bits/stdc++.h>
using namespace std;
int main()
{
    int left,mid,right,i,n,num;
    cout << "\n Enter the size of an array ";
    cin >> n;
    int arr[n+10];
    cout << "\n Enter the values in sorted order (asc or desc) \n";
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    left = 0;
    right = n-1;
    cout << "\n Enter a value to be searched in an array: ";
    cin >> num;

    while( left <= right)
    {


        mid = (left+right)/2;

        if(arr[mid] == num)
        {
            cout << "\nItem found at position: "<< (mid+1);

            exit(0);

        }


else if(num > arr[mid])
        {

            left=mid+1;

        }
        else if (num < arr[mid])
        {

            right=mid-1;

        }

    }

    cout << "Number does not found.";
}




