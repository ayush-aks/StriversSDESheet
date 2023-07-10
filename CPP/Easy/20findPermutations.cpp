#include <bits/stdc++.h>
using namespace std;

void solve(vector<string>& res, string& s, int i) {
    if (i == s.size() - 1) {
        res.push_back(s);
        return;
    }
    for (int j = i; j < s.size(); j++) {
        swap(s[i], s[j]);
        solve(res, s, i + 1);
        swap(s[i], s[j]);
    }
}

vector<string> findPermutations(string& s) {
    vector<string> res;
    solve(res, s, 0);
    return res;
}

int main() {
    string input = "cba";
    vector<string> permutations = findPermutations(input);

    cout << "Permutations of " << input << ":" << endl;
    for (const string& permutation : permutations) {
        cout << permutation << endl;
    }

    return 0;
}
