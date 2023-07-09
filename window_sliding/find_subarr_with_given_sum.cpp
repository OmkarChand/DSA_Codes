

//given a array of non-negative integers, find a subarray whose sum is equal to given sum using sliding window

#include<iostream>                      
using namespace std;

bool findSubArray(int arr[], int n, int sum)
{
    int curr_sum = arr[0], s = 0;
    for (int e = 1; e < n; e++)
    {
        //clean the previous window
        while (curr_sum > sum && s < e-1)
        {
            curr_sum -= arr[s];
            s++;
        }
        if (curr_sum == sum)
            return true;
        if(e < n)
            curr_sum += arr[e];        
    }
    return (curr_sum == sum);
}

int main()
{
    int arr[] = {1,4,20,3,10,5},  sum=33;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findSubArray(arr, n, sum);
    return 0;
}