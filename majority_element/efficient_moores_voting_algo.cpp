#include<iostream>
using namespace std;

int majority_element(int arr[], int n)
{
    int res = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if(arr[res] == arr[i])
            count++;
        else
            count--;
        
        if(count == 0)
        {
            count = 1;
            res = i;
        }
    }

    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
    }
    if(count <= n/2)
        res = -1;
    
    
    return res;
}

int main()
{
    int arr[] = {6,8,4,8,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "majority element :" << majority_element(arr, n) << endl;
    return 0;
}