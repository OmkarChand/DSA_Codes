#include<iostream>
#include<algorithm>
using namespace std;

int maxLenEvenOddSubarray(int arr[], int n)
{
    int res = 1;
    int curr_max = 1;
    for (int i = 1; i < n; i++)
    {
        if((arr[i] % 2 ==0 && arr[i-1] % 2 != 0) || (arr[i] % 2 !=0 && arr[i-1] % 2 == 0))
        {
            curr_max++;
            res = max(res, curr_max);
        }
        else    
            curr_max = 1;
    }
    return res;
}

int main()
{
    int arr[]= {10,12,14,7,8};
    int len=sizeof(arr)/sizeof(arr[0]);
    cout << "max length even-odd subarray = " << maxLenEvenOddSubarray(arr, len) << endl;
    return 0;
}