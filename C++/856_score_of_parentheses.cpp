// Time: O(n)
// Space: O(n)

#include "header.hpp"

class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0;
        stack<char> st;
        
        for (char ch : s) {
            if (ch == '(') {
                st.push(res);
                res = 0;
            }
            else {
                res = st.top() + max(2*res, 1);
                st.pop();
            }
        }
        return res;
    }
};