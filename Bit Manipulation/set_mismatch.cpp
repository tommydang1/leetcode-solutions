// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> res;

        int missing = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (s.count(nums[i])) {
                res.push_back(nums[i]);
                missing ^= i+1;
            }
            else {
                s.insert(nums[i]);
                missing ^= nums[i] ^ (i+1);
            }
        }
        res.push_back(missing);

        return res;
    }
};