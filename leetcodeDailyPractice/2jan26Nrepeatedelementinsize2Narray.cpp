#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {

            // Check adjacent element
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }

            // Check element at distance 2
            if (i + 2 < nums.size() && nums[i] == nums[i + 2]) {
                return nums[i];
            }

            // Check element at distance 3
            if (i + 3 < nums.size() && nums[i] == nums[i + 3]) {
                return nums[i];
            }
        }
        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3, 3};

    int result = obj.repeatedNTimes(nums);

    cout << "Repeated element: " << result << endl;

    return 0;
}
