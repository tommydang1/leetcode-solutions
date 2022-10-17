// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> differences;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            if (differences.count(nums[i])) {
                res.push_back(differences[nums[i]]-1);
                res.push_back(i);
                break;
            }
            
            differences[target-nums[i]] = i + 1;
        }

        return res;
    }
};