// Time: O(n)
// Space: O(n)

#include "header.hpp"

class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> set;
        int res = 1;

        for (char ch : s) {
            if (set.count(ch)) {
                res++;
                set.clear();
            }
            set.insert(ch);
        }

        return res;
    }
};