#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hIndex(vector<int>& citations) {
    int n = citations.size();
    sort(citations.begin(), citations.end());

    int s = 0, e = n - 1, ans = 0;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        int h = n - mid;

        if (citations[mid] >= h) {
            ans = h;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter number of papers: ";
    cin >> n;

    vector<int> citations(n);
    cout << "Enter citations: ";
    for (int i = 0; i < n; i++) {
        cin >> citations[i];
    }

    cout << "H-Index = " << hIndex(citations);

    return 0;
}