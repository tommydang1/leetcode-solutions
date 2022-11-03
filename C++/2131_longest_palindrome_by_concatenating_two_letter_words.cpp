// Time: O(n)
// Space: O(n)

#include "header.hpp"

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res = 0;

        unordered_map<string, int> hash;

        for (string s : words) {
            string s_rev = s;
            reverse(s_rev.begin(), s_rev.end());
            if (hash.count(s_rev) && hash[s_rev] > 0) {
                hash[s_rev]--;
                res += 4;
            }
            else if (hash.count(s)) {
                hash[s]++;
            }
            else {
                hash[s] = 1;
            }
        }

        for (auto it : hash) {
            string s_rev = it.first;
            reverse(s_rev.begin(), s_rev.end());
            if (it.first == s_rev && it.second > 0) {
                res += 2;
                break;
            } 
        }

        return res;
    }
};