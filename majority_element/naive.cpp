#include<iostream>
using namespace std;

int majority_element(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i+1; j < n; j++)
        {
            if(arr[i] == arr[j])
                count++;
        }
        if (count > n/2)
            return i;
    }
    
    return -1;
}

int main()
{
    int arr[] = {2,3,4,5,5,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "majority element :" << majority_element(arr, n) << endl;
    return 0;
}