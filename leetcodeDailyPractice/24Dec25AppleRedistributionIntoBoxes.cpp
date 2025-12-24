#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& cap) {
        // Sum of all apples
        int sum = accumulate(apple.begin(), apple.end(), 0);

        // Frequency array for box capacities (0–50)
        uint8_t fq[51] = {0};

        int high = 0, low = 51;

        // Count frequency of each capacity
        for (auto &c : cap) {
            fq[c]++;
            high = max(high, c);
            low = min(low, c);
        }

        int res = 0;

        // Greedily use largest capacity boxes first
        for (int i = high; i >= low && sum > 0; i--) {
            while (fq[i]-- > 0 && sum > 0) {
                sum -= i;
                res++;
            }
        }

        return res;
    }
};

int main() {
    Solution obj;

    vector<int> apple = {1, 3, 2};
    vector<int> cap = {4, 3, 1, 5};

    cout << "Minimum boxes needed: "
         << obj.minimumBoxes(apple, cap) << endl;

    return 0;
}
