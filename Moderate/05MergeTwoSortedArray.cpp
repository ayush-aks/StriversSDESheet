#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    // To remove the extra element from arr1.
    for (int i = 0; i < n; i++) {
        arr1.pop_back();
    }

    // Push elements of arr2 into arr1.
    for (int i = 0; i < n; i++) {
        arr1.push_back(arr2[i]);
    }

    // Sort arr1.
    sort(arr1.begin(), arr1.end());

    return arr1;
}

int main() {
    int m, n;
    cout << "Enter the sizes of the arrays (m and n): ";
    cin >> m >> n;

    vector<int> arr1(m + n);
    vector<int> arr2(n);

    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    vector<int> result = ninjaAndSortedArrays(arr1, arr2, m, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
