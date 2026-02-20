#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), cmp);

    // Handle case like 0 0 0
    if(arr[0] == "0") {
        cout << "0";
        return 0;
    }

    for(auto s : arr) {
        cout << s;
    }

    return 0;
}