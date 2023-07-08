#include <iostream>
#include <vector>
using namespace std;

int subarraysXor(vector<int> &arr, int x) {
    int n = arr.size();
    int cur;
    int k = 0;
    for (int i = 0; i < n; i++) {
        cur = arr[i];
        if (cur == x)
            k++;

        for (int j = i + 1; j < n; j++) {
            cur = cur ^ arr[j];

            if (cur == x) {
                k++;
            }
        }
    }
    return k;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = subarraysXor(arr, x);
    cout << result << endl;

    return 0;
}
