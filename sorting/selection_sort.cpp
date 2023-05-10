
#include <iostream>
using namespace std;


void sentinelSearch(int arr[], int n, int key)
{

	
	int last = arr[n - 1];

	
	arr[n - 1] = key;
	int i = 0;

	while (arr[i] != key)
		i++;

	
	arr[n - 1] = last;

	if ((i < n - 1) || (arr[n - 1] == key))
		cout << key << " is present at index " << i;
	else
		cout << "Element Not found";
}


int main()
{
	int arr[50];
    int a;
    cout<<"Enter number of elements:";
    cin>>a;
    for(int i=0; i<a; i++)
    {
        cin>>arr[i];
    } 
	int n = sizeof(arr) / sizeof(arr[0]);
	int key;
    cout<<"Enter element to be searched:";
    cin>>key;

	sentinelSearch(arr, n, key);

	return 0;
}
