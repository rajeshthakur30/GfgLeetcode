#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;
    vector<int> a(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter size of second array: ";
    cin >> m;
    vector<int> b(m);

    cout << "Enter elements: ";
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> unionArr;

    // Add first array
    for (int x : a)
        unionArr.push_back(x);

    // Add second array
    for (int x : b)
        unionArr.push_back(x);

    cout << "Union with duplicates:\n";
    for (int x : unionArr)
        cout << x << " ";

    return 0;
}