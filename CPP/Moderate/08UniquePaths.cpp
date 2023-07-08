#include <iostream>
using namespace std;

int uniquePaths(int m, int n) {
    int Nn = m + n - 2;
    int R = m - 1;
    double res = 1;

    for (int i = 1; i <= R; i++) {
        res = res * (Nn - R + i) / i;
    }

    return (int)res;
}

int main() {
    int testCaseCount;
    cout << "Enter the number of test cases: ";
    cin >> testCaseCount;

    for (int i = 1; i <= testCaseCount; i++) {
        int m, n;
        cout << "Enter the values of m and n for test case " << i << ": ";
        cin >> m >> n;

        int paths = uniquePaths(m, n);
        cout << "Number of unique paths for test case " << i << ": " << paths << endl;
    }

    return 0;
}
