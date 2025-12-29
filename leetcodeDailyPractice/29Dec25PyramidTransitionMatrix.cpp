#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<char>> mp;

    bool dfs(string curr, string next, int idx) {
        // If only one character left, pyramid is possible
        if (curr.size() == 1) return true;

        // One level completed → move to next level
        if (idx == curr.size() - 1) {
            return dfs(next, "", 0);
        }

        string key = curr.substr(idx, 2);

        // If no rule exists for this pair
        if (mp.find(key) == mp.end()) return false;

        // Try all possible characters
        for (char ch : mp[key]) {
            if (dfs(curr, next + ch, idx + 1))
                return true;
        }

        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // Build mapping
        for (string &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }

        return dfs(bottom, "", 0);
    }
};

int main() {
    Solution obj;

    string bottom = "BCD";
    vector<string> allowed = {"BCC", "CDE", "CEA", "FFF"};

    if (obj.pyramidTransition(bottom, allowed))
        cout << "True";
    else
        cout << "False";

    return 0;
}
