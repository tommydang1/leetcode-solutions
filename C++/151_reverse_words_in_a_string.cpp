// Time: O(n)
// Space: O(n)

#include "header.hpp"

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int i = s.length()-1;
        while (i >= 0) {
            string word = "";
            for (; i >= 0; i--) {
                if (s[i] == ' ') {
                    break;
                }
                word += s[i];
            }
            reverse(word.begin(), word.end());
            if (word.length()) {
                res += word + ' ';
            }
            i--;
        }
        res.resize(res.length()-1);
        return res;
    }
};