#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of towers: ";
    cin >> n;

    vector<int> h(n);
    cout << "Enter tower heights:\n";
    for (int i = 0; i < n; i++)
        cin >> h[i];

    // Sort heights to find median
    sort(h.begin(), h.end());
    int median = h[n / 2];

    int moves = 0;
    for (int i = 0; i < n; i++)
        moves += abs(h[i] - median);

    cout << "Minimum moves required = " << moves;
    return 0;
}
