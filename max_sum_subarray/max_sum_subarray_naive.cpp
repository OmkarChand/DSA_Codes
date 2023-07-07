#include<iostream>
#include<algorithm>
using namespace std;

int maxSumSubArray(int arr[], int len)
{
    int sum=arr[0];
    for(int i = 0; i < len; i++)
    {
        int curr = 0;
        for (int j = i; j < len; j++)
        {
            curr += arr[j];
            sum = max(sum, curr);   
        }
    }
    return sum;
}

int main()
{
    int arr[]= {2,3,-8,7,-1,2,3};
    int len=sizeof(arr)/sizeof(arr[0]);
    cout << "max sum subarray = " << maxSumSubArray(arr, len) << endl;
    return 0;
}