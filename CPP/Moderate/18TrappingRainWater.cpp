#include <iostream>
using namespace std;

long getTrappedWater(long *arr, int n)
{
    long left[n] = {0};
    left[0] = arr[0];

    for (long i = 1; i < n; i++) {
        left[i] = max(left[i-1], arr[i]);
    }

    long right[n] = {0};
    right[n-1] = arr[n-1];

    for (long i = n - 2; i >= 0; i--) {
        right[i] = max(right[i+1], arr[i]);
    }

    long fill[n] = {0};
    for (long i = 0; i < n; i++) {
        fill[i] = min(left[i], right[i]) - arr[i];
    }

    long ans = 0;
    for (long i = 0; i < n; i++) {
        ans += fill[i];
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    long arr[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long result = getTrappedWater(arr, n);
    cout << "Trapped water units: " << result << endl;

    return 0;
}
