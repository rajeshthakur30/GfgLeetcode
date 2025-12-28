#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;
        int r = rows - 1;
        int c = 0;

        // Start from bottom-left
        while (r >= 0 && c < cols) {
            if (grid[r][c] < 0) {
                count += (cols - c); // all elements to the right are negative
                r--;                 // move up
            } else {
                c++;                 // move right
            }
        }
        return count;
    }
};

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << "Count of negative numbers: ";
    cout << obj.countNegatives(grid) << endl;

    return 0;
}
