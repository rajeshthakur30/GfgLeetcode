#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter required XOR value: ";
    cin >> k;

    unordered_map<int, int> freq;
    int prefixXor = 0;
    int count = 0;

    freq[0] = 1;  // Important for subarrays starting from index 0

    for(int i = 0; i < n; i++) {
        prefixXor ^= arr[i];

        int required = prefixXor ^ k;

        if(freq.find(required) != freq.end()) {
            count += freq[required];
        }

        freq[prefixXor]++;
    }

    cout << "Number of subarrays with XOR " << k << " is: " << count << endl;

    return 0;
}