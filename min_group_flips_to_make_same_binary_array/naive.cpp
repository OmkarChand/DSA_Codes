#include<iostream>    // not written properly
using namespace std;

int min_flips(int arr[], int n)
{
    int zero_count = 0, one_count = 0;
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] != arr[i+1])
            if(arr[i] == 0)
                zero_count++;
            else if (arr[i] == 1)
                one_count++;
    }
    

    cout << "one = " << one_count << " " << "zero = " << zero_count << endl;
    int element;
    if (zero_count < one_count)
        element = 0;
    else
        element = 1;
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
            cout << "index = " << i << endl;
        
        
    }
    return 0;
    
}

int main()
{
    int arr[] = {1,0,0,0,1,0,0,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    min_flips(arr, n);
    return 0;
}