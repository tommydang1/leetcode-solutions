// Time: O(n)
// Space: O(n)

#include "header.hpp"

class StockSpanner {
private:
    stack<vector<int>> st;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        vector<int> stock {price, 1};
        while (!st.empty() && st.top()[0] <= price) {
            stock[1] += st.top()[1];
            st.pop();
        }
        st.push(stock);
        return stock[1];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */