#include <bits/stdc++.h>

void helper(vector<vector<string>>& ans, vector<vector<bool>>& dp, string& s, int index, vector<string>& curr) {
    if (index == s.length()) {
        ans.push_back(curr);
        return;
    }
    string tmp = "";
    for (int i = index; i < s.length(); i++) {
        tmp.push_back(s[i]);
        if (dp[index][i]) {
            curr.push_back(tmp);
            helper(ans, dp, s, i + 1, curr);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string& s) {
    int n = s.length();
    vector<string> curr;
    vector<vector<string>> ans;
    vector<vector<bool>> dp(n, vector<bool>(n));

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    for (int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = (s[i] == s[i + 1]);
    }

    for (int k = 3; k <= n; k++) {
        for (int i = 0; i <= n - k; i++) {
            int j = i + k - 1;
            dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
        }
    }

    helper(ans, dp, s, 0, curr);
    return ans;
}

int main() {
    string s1 = "aaC";
    vector<vector<string>> result1 = partition(s1);
    cout << "Sample Output 1:" << endl;
    for (vector<string>& vec : result1) {
        cout << "[";
        for (int i = 0; i < vec.size(); i++) {
            cout << "\"" << vec[i] << "\"";
            if (i != vec.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    cout << endl;

    string s2 = "BaaB";
    vector<vector<string>> result2 = partition(s2);
    cout << "Sample Output 2:" << endl;
    for (vector<string>& vec : result2) {
        cout << "[";
        for (int i = 0; i < vec.size(); i++) {
            cout << "\"" << vec[i] << "\"";
            if (i != vec.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
