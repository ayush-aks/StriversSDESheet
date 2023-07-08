#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> mergedIntervals;
    mergedIntervals.push_back(intervals[0]);
    int id = 0;

    for (int i = 1; i < intervals.size(); i++) {
        if (mergedIntervals[id][1] >= intervals[i][0]) {
            mergedIntervals[id][1] = max(mergedIntervals[id][1], intervals[i][1]);
        } else {
            mergedIntervals.push_back(intervals[i]);
            id++;
        }
    }

    return mergedIntervals;
}

int main() {
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals;
    cout << "Enter the intervals (start end):" << endl;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        intervals.push_back({start, end});
    }

    vector<vector<int>> merged = mergeIntervals(intervals);

    cout << "Merged Intervals: ";
    for (const vector<int>& interval : merged) {
        cout << interval[0] << " " << interval[1] << " ";
    }
    cout << endl;

    return 0;
}
