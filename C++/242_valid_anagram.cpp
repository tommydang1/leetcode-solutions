// Time: O(n)
// Space: O(n)

#include "header.hpp"

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;

        for (char ch : s) {
            map[ch]++;
        }

        for (char ch : t) {
            if (map[ch] == 0) {
                return false;
            }
            map[ch]--;
        }

        for (auto it : map) {
            if (it.second) {
                return false;
            }
        }

        return true;
    }
};