#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices)
{
    int profit;
    int ans=0;
    int mini=prices[0];

    for(int i=1;i<prices.size();i++){
        profit=prices[i]-mini;
        ans=max(ans,profit);
        mini=min(mini,prices[i]);
    }
    return ans;
}
void printV(vector<int> v, int n)
{
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
}
int main()
{
    vector<int> arr = {1,2,3,4};
    int n = arr.size();
    printV(arr, n);
    cout<<endl<<endl;

    cout<<maximumProfit(arr);



    return 0;
}
