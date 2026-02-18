#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& a, int low, int mid, int high) {
    int count = 0;
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
        if (a[left] <= a[right]) {
            temp.push_back(a[left]);
            left++;
        } else {
            temp.push_back(a[right]);
            count += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(a[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(a[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }

    return count;
}

int mergeSort(vector<int>& a, int low, int high) {
    int count = 0;
    if (low >= high) return count;

    int mid = low + (high - low) / 2;
    count += mergeSort(a, low, mid);
    count += mergeSort(a, mid + 1, high);
    count += merge(a, low, mid, high);

    return count;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = mergeSort(a, 0, n - 1);
    cout << "Inversion Count = " << result;

    return 0;
}
