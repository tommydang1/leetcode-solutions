// Time: O(log(n))
// Space: O(1)

#include "header.hpp"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int m;
        while (l <= r) {
            m = l + ((r-l) / 2);
            if (target > nums[m]) {
                l = m + 1;
            }
            else if (target < nums[m]) {
                r = m - 1;
            }
            else {
                return m;
            }
        }
        return -1;
    }
};