#include <bits/stdc++.h>
using namespace std;

int longestSubarrayMajorityGreaterThanK(vector<int>& arr, int K) {
    int n = arr.size();
    
    unordered_map<int, int> mp;
    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {

        // Convert values
        if (arr[i] > K)
            prefixSum += 1;
        else
            prefixSum -= 1;

        // Case 1: whole subarray from 0 to i
        if (prefixSum > 0)
            maxLen = i + 1;

        // Store first occurrence
        if (mp.find(prefixSum) == mp.end())
            mp[prefixSum] = i;

        // Case 2: check if (prefixSum - 1) exists
        if (mp.find(prefixSum - 1) != mp.end()) {
            int len = i - mp[prefixSum - 1];
            maxLen = max(maxLen, len);
        }
    }

    return maxLen;
}

int main() {
    int n, K;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value of K: ";
    cin >> K;

    int result = longestSubarrayMajorityGreaterThanK(arr, K);
    cout << "Longest Subarray Length: " << result << endl;

    return 0;
}