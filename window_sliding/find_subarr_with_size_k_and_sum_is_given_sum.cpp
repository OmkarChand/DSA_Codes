

//find subarray with sizee k whose sum is equal to given sum using sliding window

#include<iostream>                      
using namespace std;

bool maxSum(int arr[], int n, int k, int sum)
{
    int curr_sum = 0;
    for (int i = 0; i < k; i++)
        curr_sum += arr[i];
    
    if (curr_sum == sum)
        return true;
    
    for (int i = k; i < n; i++)
    {
        curr_sum += (arr[i] -arr[i-k]);
        if(curr_sum == sum)
            return true;
    }
    
    return false;
}

int main()
{
    int arr[] = {1,8,30,-5,20,7}, k = 3, sum=45;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxSum(arr, n, k, sum);
    return 0;
}