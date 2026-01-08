#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // dp array
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int prod = nums1[i - 1] * nums2[j - 1];

                dp[i][j] = max({
                    prod,                       // start new subsequence
                    dp[i - 1][j - 1] + prod,    // extend previous subsequence
                    dp[i - 1][j],               // skip nums1 element
                    dp[i][j - 1]                // skip nums2 element
                });
            }
        }
        return dp[n][m];
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};

    cout << sol.maxDotProduct(nums1, nums2) << endl;

    return 0;
}
