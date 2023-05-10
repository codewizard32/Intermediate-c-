#include <iostream>
using namespace std;


int min(int x, int y) {
    return (x <= y) ? x : y;
}


int fib_search(int arr[], int n, int x) {
    
    int fib2 = 0; 
    int fib1 = 1; 
    int fib = fib2 + fib1; 

    
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    
    int offset = -1;
    while (fib > 1) {
       
        int i = min(offset+fib2, n-1);

       
        if (arr[i] < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        
        else if (arr[i] > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        
        else {
            return i;
        }
    }

   
    if (fib1 && arr[offset+1] == x) {
        return offset+1;
    }
    return -1;
}


int main() {
    int n, x;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to be searched: ";
    cin >> x;

    
    int index = fib_search(arr, n, x);
    if (index == -1) {
        cout << "Element not found in the array.\n";
    }
    else {
        cout << "Element found at index " << index << " in the array.\n";
    }

    return 0;
}
