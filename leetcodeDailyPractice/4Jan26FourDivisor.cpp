#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (int n : nums) {
            int sum = 0;
            int count = 0;

            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    int d1 = i;
                    int d2 = n / i;

                    if (d1 == d2) {
                        count++;
                        sum += d1;
                    } else {
                        count += 2;
                        sum += d1 + d2;
                    }

                    // If more than 4 divisors, no need to continue
                    if (count > 4) break;
                }
            }

            // If exactly 4 divisors, add their sum
            if (count == 4) {
                totalSum += sum;
            }
        }

        return totalSum;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = sol.sumFourDivisors(nums);
    cout << "Sum of divisors of numbers having exactly 4 divisors: "
         << result << endl;

    return 0;
}
