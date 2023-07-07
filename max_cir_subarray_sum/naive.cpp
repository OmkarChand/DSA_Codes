#include<iostream>
#include<algorithm>
using namespace std;

int maxSumCirSubArray(int arr[], int len)
{
    int res=arr[0];
    for(int i = 0; i < len; i++)
    {
        int curr_sum = arr[i];
        int curr_max = arr[i];

        for(int j = 1; j < len; j++)
        {
            curr_sum += arr[(i+j)%len];
            curr_max = max(curr_max, curr_sum);   
        }
        res = max(res, curr_max);
    }
    return res;
}

int main()
{
    int arr[]= {8,-4,3,-5,4};
    int len=sizeof(arr)/sizeof(arr[0]);
    cout << "max sum subarray = " << maxSumCirSubArray(arr, len) << endl;
    return 0;
}