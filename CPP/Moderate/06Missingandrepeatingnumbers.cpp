#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

pair<int, int> missingAndRepeating(vector<int>& arr, int n) {
    unordered_set<int> vis;
    int missing = 0;
    int repeated = 0;
    for (int& num : arr) {
        if (vis.count(num)) {
            repeated = num;
        } else {
            vis.insert(num);
        }
    }
    for (int num = 1; num <= n; num++) {
        if (vis.count(num) == 0) {
            missing = num;
            break;
        }
    }
    return {missing, repeated};
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        pair<int, int> result = missingAndRepeating(arr, n);
        cout << "Missing element: " << result.first << endl;
        cout << "Repeating element: " << result.second << endl;
    }

    return 0;
}
