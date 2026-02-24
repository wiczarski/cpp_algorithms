#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        int start_index = 0;

        for (int i = 0; i < nums.size(); i++) {
            int cur_num = nums[i];
            start_index = i - k;

            auto found = seen.find(cur_num);
            if (found != seen.end()) {
                if (found->second >= start_index && found->second <= i) {
                    return true;
                }
            }
            seen[cur_num] = i;
        }
        return false;
    }
};