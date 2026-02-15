#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of packets: ";
    cin >> n;

    int a[n];
    cout << "Enter chocolates in packets:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter number of students: ";
    cin >> m;

    if (m > n) {
        cout << "Distribution not possible";
        return 0;
    }

    sort(a, a + n);

    int diff = a[m-1] - a[0];
    for (int i = 1; i <= n - m; i++) {
        int curr = a[i+m-1] - a[i];
        if (curr < diff)
            diff = curr;
    }

    cout << "Minimum difference: " << diff;
    return 0;
}
