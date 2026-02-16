#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of meetings: ";
    cin >> n;

    vector<int> start(n), end(n);
    cout << "Enter start times:\n";
    for(int i=0;i<n;i++) cin >> start[i];

    cout << "Enter end times:\n";
    for(int i=0;i<n;i++) cin >> end[i];

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int rooms = 0, maxRooms = 0;
    int i = 0, j = 0;

    while(i < n && j < n) {
        if(start[i] < end[j]) {
            rooms++;
            maxRooms = max(maxRooms, rooms);
            i++;
        } else {
            rooms--;
            j++;
        }
    }

    cout << "Minimum Meeting Rooms Required: " << maxRooms;
    return 0;
}
