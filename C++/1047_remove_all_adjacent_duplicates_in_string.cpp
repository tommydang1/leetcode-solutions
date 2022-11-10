// Time: O(n)
// Space: O(1)

#include "header.hpp"

class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";

        for (int i = 0; i < s.length(); i++) {
            if (res.length() && res[res.length()-1] == s[i]) {
                res.erase(res.length()-1, 1);
            }
            else {
                res += s[i];
            }
        }

        return res;
    }
};