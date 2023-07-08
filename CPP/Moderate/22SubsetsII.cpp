/*
Sample Input 1:
2
3
1 1 3
4
1 3 3 3
Sample Output 1:
1
1 1
1 3
3
1 1 3

1
1 3
1 3 3
1 3 3 3
3
3 3
3 3 3
*/

#include <bits/stdc++.h>

void generateSubsets(vector<int> &arr, int i, vector<int> &ds, vector<vector<int>> &ans) {
    if (i == arr.size()) {
        return;
    }

    ds.push_back(arr[i]);
    ans.push_back(ds);
    generateSubsets(arr, i + 1, ds, ans);
    while (i < arr.size() - 1 && arr[i] == arr[i + 1])
        i++;
    ds.pop_back();
    generateSubsets(arr, i + 1, ds, ans);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    generateSubsets(arr, 0, ds, ans);

    return ans;
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Size of the array

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; // Elements of the array
        }

        vector<vector<int>> subsets = uniqueSubsets(n, arr);
        for (auto subset : subsets) {
            cout << subset.size() << endl; // Size of the subset
            for (auto num : subset) {
                cout << num << " "; // Elements of the subset
            }
            cout << endl;
        }
    }

    return 0;
}
