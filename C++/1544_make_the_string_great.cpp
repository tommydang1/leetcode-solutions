// Time: O(n)
// Space: O(1)

include "header.hpp"

class Solution {
public:
    string makeGood(string s) {
        if (!s.length()) {
            return s;
        }
        string res = "";

        for (int i = 0; i < s.length(); i++) {
            if (res.length() &&
            ((isupper(s[i]) && (tolower(s[i]) == res[res.length()-1])) ||
            (islower(s[i]) && (toupper(s[i]) == res[res.length()-1])))) {
                res.erase(res.length()-1, 1);
            }
            else {
                res += s[i];
            }
        }
        return res;
    }
};