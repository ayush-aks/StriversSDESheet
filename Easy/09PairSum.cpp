#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> pairs;
    int j = 0;
    for(int i = 1; i < arr.size(); i++)
    {
       int sum = arr[j] + arr[i];
       if(sum == s)
       {
           vector<int> temp;
           temp.push_back(arr[j]);
           temp.push_back(arr[i]);
           pairs.push_back(temp);
       }
       if((sum > s) || ((i == arr.size() - 1) && (j<arr.size())))
       {
           j++;
           i = j;
       }
   }
   return pairs;
}

void printV(vector<vector<int>> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // vector<int> arr = {1,2,3,4,5};
    vector<int> arr = {2,-3,3,-3,-2};
    int s = 0;

    vector<vector<int>> ans = pairSum(arr, s);

    cout << endl;
    printV(ans);

    return 0;
}
