#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();        // number of rows
        int m = strs[0].size();     // number of columns

        // dp[j] = longest valid column sequence ending at column j
        vector<int> dp(m, 1);
        int longest = 1;

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < j; i++) {

                bool valid = true;

                // check all rows
                for (int r = 0; r < n; r++) {
                    if (strs[r][i] > strs[r][j]) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            longest = max(longest, dp[j]);
        }

        // minimum columns to delete
        return m - longest;
    }
};

int main() {
    Solution sol;

    vector<string> strs = {"babca", "bbazb"};

    int result = sol.minDeletionSize(strs);
    cout << "Output: " << result << endl;

    return 0;
}
