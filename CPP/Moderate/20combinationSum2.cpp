#include<bits/stdc++.h>
using namespace std;

void combinationSumHelper(int ind, vector<vector<int>> &ans, vector<int> &v, vector<int> &arr, int n, int target){
    if(target == 0){
        ans.push_back(v);
        return;
    }

    for(int i = ind; i < n; i++){
        if(i > ind && arr[i] == arr[i-1]) continue;
        if(arr[i] > target) break;
        v.push_back(arr[i]);
        combinationSumHelper(i+1, ans, v, arr, n, target - arr[i]);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
    sort(arr.begin(), arr.end());
    int ind = 0;
    vector<vector<int>> ans;
    vector<int> v;
    combinationSumHelper(ind, ans, v, arr, n, target);
    return ans;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<vector<int>> result = combinationSum2(arr, n, target);

    for(auto combination : result){
        for(auto num : combination){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
