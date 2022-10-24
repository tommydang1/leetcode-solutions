// Time: O(n)
// Space: O(1)

#include "header.hpp"

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        
        while (start <= end) {
            while (!isalnum(s[start]) && start < s.size()) {
                start++;
            }
            while (!isalnum(s[end]) && end > 0) {
                end--;
            }
            if (start >= end) {
                break;
            }
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};