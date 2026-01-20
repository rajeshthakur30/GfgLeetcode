#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        res.reserve(nums.size());

        for (auto &n : nums) {
            if (n & 1) { // odd
                int z = ((n + 1) & ~n) >> 1;
                res.push_back(n & ~z);
            } else {
                res.push_back(-1); // even
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;                 // size of array
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution s;
    vector<int> ans = s.minBitwiseArray(nums);

    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << (i + 1 == (int)ans.size() ? '\n' : ' ');
    }
    return 0;
}
