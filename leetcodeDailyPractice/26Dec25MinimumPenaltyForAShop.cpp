#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;

        // Initial penalty: count all 'Y'
        for (char c : customers) {
            if (c == 'Y')
                penalty++;
        }

        int minPenalty = penalty;
        int bestHour = 0;

        // Check penalty hour by hour
        for (int i = 0; i < customers.length(); i++) {
            if (customers[i] == 'Y') {
                penalty--;   // customer comes, shop open → no penalty
            } else {
                penalty++;   // no customer, shop open → penalty
            }

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }

        return bestHour;
    }
};

int main() {
    string customers;
    cin >> customers;

    Solution obj;
    cout << obj.bestClosingTime(customers);

    return 0;
}
