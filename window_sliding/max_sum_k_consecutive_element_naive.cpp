#include<iostream>                      //max_sum_k_consecutive_element_naive
using namespace std;

int maxSum(int arr[], int n, int k)
{
    int max_sum = 0;
    for (int i = 0; i < n-k+1; i++)
    {
        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            sum += arr[i+j];
        }
        cout << "sum = " << sum << endl;
        max_sum = max(max_sum, sum);
    }
    cout << "max sum = " << max_sum;
    return 0;
}

int main()
{
    int arr[] = {1,8,30,-5,20,7}, k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    maxSum(arr, n, k);
    return 0;
}