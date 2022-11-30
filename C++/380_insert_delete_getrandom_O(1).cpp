// Time: O(1)
// Space: O(n)

#include "header.hpp"

class RandomizedSet {
private:
    unordered_map<int, int> pos_map;
    vector<int> vals;

public:
    bool insert(int val) {
        if (pos_map.count(val)) {
            return false;
        }
        pos_map[val] = vals.size();
        vals.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!pos_map.count(val)) {
            return false;
        }
        int pos = pos_map[val];
        int last_val = vals.back();

        vals[pos] = last_val;
        pos_map[last_val] = pos;
        vals.pop_back();
        pos_map.erase(val);
        return true;
    }
    
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */