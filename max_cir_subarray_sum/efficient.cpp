#include<iostream>
#include<algorithm>
using namespace std;

int normal_max_sum(int arr[], int len)
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
int cir_subarray_max_sum(int arr[], int n)
{
    int max_normal = normal_max_sum(arr, n);
    cout << "max_normal = " << max_normal << endl;

    if(max_normal < 0)
        return max_normal;
    
    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
        arr[i] = - arr[i];
    }
    int min_normal = normal_max_sum(arr, n);
    cout << "total sum = " << total_sum << endl;
    cout << "min sum = " << min_normal << endl;
    int max_circular = total_sum + min_normal;
    cout << "max_circular = " << max_circular << endl;
    //return max(max_normal, max_circular);  
    cout << "result = " << (max_normal, max_circular) << endl;
    return 0;
}

int main()
{
    int arr[]= {2,3,-8,7,-1,2,3};
    int len=sizeof(arr)/sizeof(arr[0]);
    //cout << "cir_max_sum = " << cir_subarray_max_sum(arr, len) << endl;
    cir_subarray_max_sum(arr, len);
    return 0;
}