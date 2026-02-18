#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    int start[n], end[n];

    cout << "Enter start and end of intervals:\n";
    for(int i = 0; i < n; i++) {
        cin >> start[i] >> end[i];
    }

    sort(start, start + n);
    sort(end, end + n);

    int i = 0, j = 0;
    int overlap = 0, maxOverlap = 0;

    while(i < n && j < n) {
        if(start[i] <= end[j]) {
            overlap++;
            maxOverlap = max(maxOverlap, overlap);
            i++;
        } else {
            overlap--;
            j++;
        }
    }

    cout << "Maximum overlapping intervals: " << maxOverlap;
    return 0;
}
