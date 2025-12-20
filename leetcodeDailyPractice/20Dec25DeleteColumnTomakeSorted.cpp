#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();        // number of strings
        int m = strs[0].size();     // length of each string
        int cnt = 0;

        // Traverse each column
        for (int j = 0; j < m; j++) {
            // Check if column is sorted
            for (int i = 0; i < n - 1; i++) {
                if (strs[i][j] > strs[i + 1][j]) {
                    cnt++;      // delete this column
                    break;
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    vector<string> strs = {"cba", "daf", "ghi"};
    cout << sol.minDeletionSize(strs);

    return 0;
}
