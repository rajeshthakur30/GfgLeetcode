#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPaint(vector<int> &boards, int k, int maxTime) {
    int painters = 1, currTime = 0;

    for (int len : boards) {
        if (len > maxTime) return false;

        if (currTime + len <= maxTime)
            currTime += len;
        else {
            painters++;
            currTime = len;
            if (painters > k) return false;
        }
    }
    return true;
}

int minTime(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = 0;

    for (int x : boards) high += x;

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(boards, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> boards(n);
    for (int i = 0; i < n; i++)
        cin >> boards[i];

    cout << minTime(boards, k);

    return 0;
}
