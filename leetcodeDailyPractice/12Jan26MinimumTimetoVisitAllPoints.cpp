#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int ans = 0;

        for (int i = 1; i < p.size(); i++) {
            ans += max(
                abs(p[i][0] - p[i - 1][0]),
                abs(p[i][1] - p[i - 1][1])
            );
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    Solution obj;
    cout << obj.minTimeToVisitAllPoints(points);

    return 0;
}
