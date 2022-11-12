// Time: O(log(n))
// Space: O(n)

#include "header.hpp"

class MedianFinder {
private:
    priority_queue<int> leftQ;
    priority_queue<int, vector<int>, greater<int>> rightQ;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (leftQ.empty() || num < leftQ.top()) {
            leftQ.push(num);
        }
        else {
            rightQ.push(num);
        }

        // Rebalance
        if (leftQ.size() >= rightQ.size() + 2) {
            int temp = leftQ.top();
            rightQ.push(temp);
            leftQ.pop();
        }
        if (rightQ.size() >= leftQ.size() + 2) {
            int temp = rightQ.top();
            leftQ.push(temp);
            rightQ.pop();
        }
    }
    
    double findMedian() {
        if (leftQ.size() > rightQ.size()) {
            return leftQ.top();
        }
        else if (rightQ.size() > leftQ.size()) {
            return rightQ.top();
        }
        else {
            cout << leftQ.top() << " " << rightQ.top() << endl;
            return (double)(leftQ.top() + rightQ.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */