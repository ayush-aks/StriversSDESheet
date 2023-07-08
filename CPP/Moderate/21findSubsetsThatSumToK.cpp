#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> arr, int n, int k, int index, vector<vector<int>>& ans, vector<int>& ds) {
    if (index >= n) {
        if (k == 0) {
            ans.push_back(ds);
        }
        return;
    }

    // Take
    ds.push_back(arr[index]);
    solve(arr, n, k - arr[index], index + 1, ans, ds);
    ds.pop_back();

    // Not Take
    solve(arr, n, k, index + 1, ans, ds);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k) {
    vector<vector<int>> ans;
    vector<int> ds;
    int index = 0;
    solve(arr, n, k, index, ans, ds);
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the target sum: ";
    cin >> k;

    vector<vector<int>> subsets = findSubsetsThatSumToK(arr, n, k);

    cout << "Subsets that sum to " << k << ": " << endl;
    for (const vector<int>& subset : subsets) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
