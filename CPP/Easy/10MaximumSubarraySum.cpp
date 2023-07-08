#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int> &arr, int n)
{
    int maxSum = INT_MIN;
    int curSum = 0;
    for(int i=0; i<n; i++){
        curSum = curSum + arr[i];
        if(curSum > maxSum){
            maxSum = curSum;
        }
        if(curSum < 0){
            curSum = 0;
        }
    }
    return max(curSum, maxSum);
}

int main()
{
    vector<int> arr = {1,2,7,-4,3,2,-10,9,1};
    int size = arr.size();

    cout<<maxSubarraySum(arr, size);
    return 0;
}
