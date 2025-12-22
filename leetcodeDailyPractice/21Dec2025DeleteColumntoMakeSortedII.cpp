#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int minDeletionSize(char strs[][10], int n) {
    int m = strlen(strs[0]);   // length of each string
    int cnt = 0;

    // sorted[i] = true means strs[i] < strs[i+1] already fixed
    bool sorted[100] = {false};   // n-1 size is enough

    // Traverse each column
    for (int j = 0; j < m; j++) {
        bool deleteCol = false;

        // Check if this column breaks order
        for (int i = 0; i < n - 1; i++) {
            if (!sorted[i] && strs[i][j] > strs[i + 1][j]) {
                deleteCol = true;
                break;
            }
        }

        if (deleteCol) {
            cnt++;     // delete this column
            continue;
        }

        // Update sorted pairs
        for (int i = 0; i < n - 1; i++) {
            if (!sorted[i] && strs[i][j] < strs[i + 1][j]) {
                sorted[i] = true;
            }
        }
    }
    return cnt;
}

int main() {
    char strs[3][10] = {"ca", "bb", "ac"};
    int n = 3;

    int result = minDeletionSize(strs, n);
    printf("Output: %d\n", result);

    return 0;
}
