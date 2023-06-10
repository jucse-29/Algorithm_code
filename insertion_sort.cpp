#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}




int main()
{
    int n;
	cin>>n;
	int ar[n+10];
	for(int i=0;i<n;i++){
        cin>>ar[i];
	}
	    cout<<"Before Sorting: ";

        for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<'\n';
        cout << "Sorted array: ";
	insertionSort(ar, n);
	printArray(ar, n);

	return 0;
}




