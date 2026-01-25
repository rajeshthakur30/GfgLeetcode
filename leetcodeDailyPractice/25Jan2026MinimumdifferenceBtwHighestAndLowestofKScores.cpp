#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int>& nums, int k) {
    if (k <= 1) return 0;

    sort(nums.begin(), nums.end());
    int n = (int)nums.size();
    int ans = INT_MAX;

    for (int i = 0; i + k - 1 < n; i++) {
        ans = min(ans, nums[i + k - 1] - nums[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << minimumDifference(nums, k) << "\n";
    return 0;
}
