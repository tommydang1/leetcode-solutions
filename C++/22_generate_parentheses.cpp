// Time: O(2^n)
// Space: O(n)? or O(2^n)

#include "header.hpp"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<pair<string, pair<int, int>>> st;
        pair<string, pair<int, int>> ele;
        st.push(make_pair("(", make_pair(1, 0)));
        
        vector<string> res;
        
        while (!st.empty()) {
            for (int i = 0, size = st.size(); i < size; i++) {
                ele = st.top();
                if (ele.second.first == n) {
                    ele.first += string(n - ele.second.second, ')');
                    res.push_back(ele.first);
                    st.pop();
                }
                else {
                    string parenthesis = ele.first;
                    pair<int, int> pair = ele.second;
                    st.pop();
                    st.push(make_pair(parenthesis + "(", make_pair(pair.first + 1, pair.second)));
                    if (pair.first > pair.second) {
                        st.push(make_pair(parenthesis + ")", make_pair(pair.first, pair.second + 1)));
                    };
                }
            }
        }
        return res;
    }
};