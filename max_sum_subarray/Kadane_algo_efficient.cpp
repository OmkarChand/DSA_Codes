#include<iostream>
#include<algorithm>
using namespace std;

int maxSumSubArray(int arr[], int len)
{
    int res = arr[0];
    int maxEnding = arr[0];
    for (int i = 1; i < len; i++)
    {
        maxEnding = max((maxEnding + arr[i]), arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int main()
{
    int arr[]= {2,3,-8,7,-1,2,3};
    int len=sizeof(arr)/sizeof(arr[0]);
    cout << "max sum subarray = " << maxSumSubArray(arr, len) << endl;
    return 0;
}