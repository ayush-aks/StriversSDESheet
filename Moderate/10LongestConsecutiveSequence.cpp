#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n)
{
    unordered_set<int> st(nums.begin(), nums.end());
    int longest = 0;

    for (int i = 0; i < n; i++) {
        if (st.find(nums[i] - 1) == st.end()) {
            int length = 1;

            for (int j = 1; st.find(nums[i] + j) != st.end(); j++, length++)
                ;

            longest = max(length, longest);
        }
    }

    return longest;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int longestLength = lengthOfLongestConsecutiveSequence(nums, n);

    cout << "Length of the longest consecutive sequence: " << longestLength << endl;

    return 0;
}
